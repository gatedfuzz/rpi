import ctypes
#import struct
import zlib
import os.path
import getopt
import sys

import serial # python3 pip install --user pyserial

opts, args = getopt.getopt(sys.argv[1:],'h', ['help'])
#print(opts)
#print(args)
#exit(0)

fname = "~/Downloads/"
fname = args[0]
#fname += "pg2243.txt"
#fname += "cowbell-1.wav"
#fname = os.path.expanduser(fname)
print("fname = ", fname)
#exit(0)

txt = b"hello world"

fp = open(fname, "rb")
txt = fp.read()
#print(txt)
fp.close()
#exit(0);
crc_out = zlib.crc32(txt)
#print("checksum = ", zlib.crc32(txt))
#exit(0)


len1 = len(txt)
print("tx len: ", len1)
#len2 = struct.pack()
len2 = ctypes.c_uint32(len1)


with serial.Serial('/dev/ttyACM0', 115200, timeout=1) as ser:
    ser.write(b'T')
    ser.write(len2)
    ser.write(txt)
    print("Finished transmitting")
    ser.write(b'R')
    rx = ser.read(4)
    rx1 = 0
    for i in range(4):
        rx1 <<= 8
        rx1 += rx[3-i]
    print("rx len: ", rx1)
    #rx1 =  rx[0]>>8 + rx[1]
    print(rx1)
    #rxlen1.reverse()
    #rxlen2 = struct.unpack('>l', rxlen1)[0]
    #print(rxlen2)
    rx2 = ser.read(rx1)
    print(rx2)
    crc_in = zlib.crc32(rx2)
    if(crc_in == crc_out):
        print("Checksums match")
    else:
        print("ERR: Checksums differ")

