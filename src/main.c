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

#include <swarm/colors.h>

void swarm_usage(struct _IO_FILE * descriptor) {
  fprintf(descriptor,
    RED "swarmc "
    RESET "is an extensible, lightweight, computercraft emulator. (non-graphical)\n"
    CYAN "usage: \n"
    GREEN TAB "--main-file or -m: "
    RESET "main file to execute\n"
    GREEN TAB "--working-directory or -D: "
    RESET "working directory for loadfile() calls.\n"
    GREEN TAB "--vanilla-compat or -V: "
    RESET "compatibility with vanilla lua.\n"
    GREEN TAB "--strict or -S: "
    RESET "disable compatibility with vanilla lua.\n"
  );
}

int main(int argc, char const *argv[]) {
  if (argc == 1) {
    fprintf(stderr, RED "swarmc "
      RESET "requires 2 or more arguments.\n"
    );

    swarm_usage(stderr);
  }

  return 0;
}
