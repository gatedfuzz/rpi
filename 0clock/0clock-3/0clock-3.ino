///////////////////////////////////////////////////////////
// DS3231

#include "RTClib.h"
#include <Timezone.h> // https://github.com/JChristensen/Timezone

TimeChangeRule myBST = {"BST", Last, Sun, Mar, 1, 60};
TimeChangeRule mySTD = {"GMT", Last, Sun, Nov, 2, 0};
Timezone myTZ(myBST, mySTD);
TimeChangeRule *tcr;        //pointer to the time change rule, use to get TZ abbrev

RTC_DS3231 rtc;
DateTime get_time() {
  DateTime dt = rtc.now();
  auto tim = dt.unixtime();
  tim = myTZ.toLocal(tim, &tcr);
  DateTime dt_local{tim};
  return dt_local;
}


// DS3231 end
///////////////////////////////////////////////////////////
// MAX7219

#include <SPI.h>

// What pin on the Arduino connects to the LOAD/CS pin on the MAX7219/MAX7221
#ifdef ESP32 // includes WROOM
#define LOAD_PIN 5
#else
#define LOAD_PIN 10
#endif

/**
   Transfers data to a MAX7219/MAX7221 register.
   @param address The register to load data into
   @param value   Value to store in the register
*/
void transfer_7219(uint8_t address, uint8_t value) {
  digitalWrite(LOAD_PIN, LOW); // CS
  SPI.transfer(address);
  SPI.transfer(value);
  digitalWrite(LOAD_PIN, HIGH);
}

void init_7219() {
  pinMode(LOAD_PIN, OUTPUT);
  SPI.setBitOrder(MSBFIRST);
  SPI.begin();
  transfer_7219(0x0F, 0x00);
  transfer_7219(0x09, 0xFF); // Enable mode B
  transfer_7219(0x0A, 0x0F); // set intensity (page 9)
  transfer_7219(0x0B, 0x07); // use all pins
  transfer_7219(0x0C, 0x01); // Turn on chip
}

/*
  struct Max7219 {
  Max7219() { init_7219(); }
  }
*/

// MAX7219 end
///////////////////////////////////////////////////////////
// COMMON COMPONENTS

typedef unsigned long ulong;
//typedef unsigned long micros_t;
typedef ulong ms_t;

template<int N, typename T>
struct Buffer {
  int capacity = N;
  int size = 0;
  T data[N];
  void push(T value) {
    if (size < capacity) data[size++] = value;
  };
  void zap() {
    for (int i = 0; i < capacity; ++i) data[i] = 0;
    size = 0;
  }
};



struct Periodic {
  ms_t _started;
  ms_t _period;
  Periodic(ms_t period) : _period(period) {
    _started = millis() - period; // subtract the period so that we get an immediate reset
  }
  bool expired() {
    ms_t ms = millis();
    if (ms - _started < _period) return false;
    _started = ms;
    return true;
  }

};

struct Delay {
  bool _active = false;
  ms_t _started;
  ms_t _len;
  void begin(ms_t len_ms) {
    _len = len_ms;
    _active = true;
    _started = millis();
  }
  bool expired() {
    if (!_active) return false;
    ms_t ms = millis();
    if (ms - _started < _len) return false;
    _active = false;
    return true;
  }
};

typedef void (*funcptr)();
struct Button { // gets called on falling
  using bstate = enum states {start, ignore1, seek_high, ignore2};
  
  funcptr _func ;
  int _pin;
  //bool _prev = HIGH;
  bstate _state = start;
  //Periodic _debouncer = Periodic(25);
  ms_t _ms;
  Button(int pin, funcptr func) {
    _pin = pin;
    pinMode(pin, INPUT_PULLUP);
    _func = func;
  }
  void update() {
    const int DT = 35; //debounce time
    //bool cur = digitalRead(_pin);
    switch (_state) {
      case start:
        if (digitalRead(_pin) == HIGH) return; // ignore the pin whilst unpressed
        _ms = millis();
        _func();
        _state = ignore1;
        break;
      case ignore1: // don't do anything for 25ms
        if (millis() - _ms > DT) _state = seek_high;
        break;
      case seek_high: // wait for pin to go high
        if (digitalRead(_pin) == LOW) return;
        _ms = millis();
        _state = ignore2;
        break;
      case ignore2: // don't process button for 25ms
        if (millis() - _ms < DT) return;
        if(digitalRead(_pin) == HIGH) _state = start;
        break;
    }
    /*
      if (!_debouncer.expired()) return;
      bool cur = digitalRead(_pin);
      if (cur == LOW && _prev == HIGH) _func();
      _prev = cur;
    */
  }

};

// COMMON COMPONENTS end
///////////////////////////////////////////////////////////
void do_set(char *buf) {
  buf[15] = 0;
  buf[24] = 0;
  //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  rtc.adjust(DateTime(buf + 4, buf + 16));
  Serial.println(buf + 4);
  Serial.println(buf + 16);

}
Buffer<30, char> input;
void serialise() {
  if (!Serial.available()) return;
  char c = Serial.read();
  input.push(c);
  if (c != '\r') return;
  if (strncmp("SET", input.data, 3) != 0) return;
  do_set(input.data);
  input.zap();
}


void sw0_falling() {
  mins30(true);
}
void sw1_falling() {}
void sw2_falling() {}

Button sw0(3, sw0_falling);
Button sw1(A2, sw1_falling);
Button sw2{A4, sw2_falling};

#define BZR 8
//#define SW A2
void setup() {
  init_7219();
  rtc.begin();
  Serial.begin(9600);
  update_regular_display();

  //pinMode(SW, INPUT_PULLUP);
  pinMode(BZR, OUTPUT);

}

void show_dec(int pos, int val, bool dp = false) {
  int v = val % 10;
  if (dp) v |= 1 << 7; // add in the decimal point
  transfer_7219(pos, v);
  //int v1 = val/10;
  transfer_7219(pos + 1, val / 10);
}

void update_regular_display() {
  DateTime dt = get_time();
  show_dec(1, dt.minute());
  show_dec(3, dt.hour(), true);
  transfer_7219(5, 0b1111); // blank
  transfer_7219(6, 0b1111); // blank
  show_dec(7, dt.day());
}

void update_counter_display(int remaining_secs) {
  show_dec(1, remaining_secs % 60);
  show_dec(3, remaining_secs / 60, true);
  for (int i = 5; i < 9; i++) {
    transfer_7219(i, 0b1111); // blank
  }
}

void loop() {
  serialise();

  sw0.update();
  sw1.update();
  sw2.update();


  static Periodic regular(250);
  if (regular.expired()) {
    int timer = mins30(false);
    if (timer == 0) {
      update_regular_display();
    } else {
      update_counter_display(timer);
    }
  }
}

void sound(bool on) {
  // tones seem to sound so much better than a straight-forward bussing
#if 0
  digitalWrite(BZR, on);
#else
  if (on) {
    tone(BZR, 2525);// quindar
    //tone(BZR, 1000);
  } else {
    noTone(BZR);
    digitalWrite(BZR, LOW);
  }
#endif
}

int mins30(bool toggle) {
  enum states {idle, start, timing, expired};
  static Delay dly;
  //static active = false;
  static int state = idle;
  static ms_t start_time;

  if (state == idle) {
    sound(LOW);
    if (toggle) state = start;
    return 0;
  }
  if (toggle) state = idle;

  ms_t segment = (millis() - start_time) % 5000; // break up the timing into 5 second chunks
  switch (state) {
    case start:
      start_time = millis();
      state = timing; //fallthrough
    case timing:
      //sound(segment < 250); // decided to turn sound off for now 2020-07-20
      if (millis() - start_time > 1800000) state = expired; // i.e. 30 mins
      return 1800 - (millis() - start_time) / 1000; // i.e. seconds
    case expired:
      sound(segment < 250 || ( 500 < segment && segment < 750)); // double-beeping
      return 0;
  }
}