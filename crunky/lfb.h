#pragma once
/*
 * Copyright (C) 2018 bzt (bztsrc@github)
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */

#ifdef __cplusplus
extern "C" {
#endif

void lfb_init();
void lfb_init_as_stdout();
//void lfb_showpicture();
void lfb_print(int x, int y, char *s);
void lfb_proprint(int x, int y, char *s);
int fbputchar(int c);
void fbprint(char* str);
int fbputs(char* str);
void fbnewline();
unsigned int lfb_pitch();
unsigned char* lfb_buffer();
unsigned int lfb_width();
unsigned int lfb_height();
unsigned int isrgb();
int lfb_num_chars_in_col();
int lfb_num_chars_in_row();

#ifdef __cplusplus
}
#endif
