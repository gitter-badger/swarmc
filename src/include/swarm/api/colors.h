/*
The MIT License (MIT)

Copyright (c) 2015 Jared Allard and Matheus Alcantara

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#ifndef COLORS_API_FS
#define COLORS_API_FS

#include <base.h>

// number definitions
#define colors_white      1
#define colors_orange     2
#define colors_magenta    4
#define colors_lightBlue  8
#define colors_yellow     16
#define colors_lime       32
#define colors_pink       64
#define colors_gray       128
#define colors_lightGray  256
#define colors_cyan       512
#define colors_purple     1024
#define colors_blue       2048
#define colors_brown      4096
#define colors_green      8192
#define colors_red        16384
#define colors_black      32768

void api_colors_open(lua_State *L);

#endif /* end of include guard: COLORS_API_FS */
