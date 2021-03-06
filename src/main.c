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

#include <colors.h>

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
    GREEN TAB "--extensions or -E: "
    RESET "enable " RED "swarmc" RESET "-specific extensions.\n"
    GREEN TAB "--help or -h: "
    RESET "print help for swarmc\n"
    GREEN TAB "--debug or -a: "
    RESET "enable debug information.\n"
  );
}

int extensions, strict, debug;

static struct option opts[] = {
  {"vanilla-compat", no_argument, &strict, 0},
  {"strict", no_argument, &strict, 1},
  {"debug", no_argument, &debug, 1},
  {"extensions", no_argument, &extensions, 1},
  {"main-file", required_argument, 0, 'm'},
  {"working-directory", required_argument, 0, 'D'},
  {"help", no_argument, 0, 'h'},
  {0, 0, 0, 0}
};

int main(int argc, char *const argv[]) {
  if (argc == 1) {
    fprintf(stderr, RED "swarmc "
      RESET "requires 2 or more arguments.\n"
    );

    swarm_usage(stderr);
    exit(0);
  }

  int c = 0;
  int opt_indx = 0;
  char* main_file, working_dir;

  while ((c = getopt_long(argc, argv, "m:D:V:S:E:h", opts, &opt_indx)) != -1) {
    switch(c) {
      case 'h':
        swarm_usage(stdout);
      exit(0);

      case 'D':
        // in case there is no argument, getopt_long already printed an error.
        if (optarg)
          working_dir = *optarg;
      break;

      case 'm':
        if (optarg)
          main_file = optarg;
        else
          fprintf(stderr, RED "--main-file or -m " RESET "requires an argument.");
      break;

    }
  }

  if(run_lua(main_file, debug) == -1) {
    fprintf(stderr, RED "swarmc "
      RESET "failed to execute.\n"
    );
    switch(errno) {
      case ENOPARAM:
        fprintf(stderr, RED "error: " RESET " main file is not defined.\n");
      break;

      case ELOADFILE:
        fprintf(stderr, RED "error: " RESET "loadfile failed.\n");
      break;

      case EPCALL:
        fprintf(stderr, RED "error: " RESET "pcall failed.\n");
      break;

      case EFNOTE:
        fprintf(stderr, RED "error: " RESET "file %s not found.\n", main_file);
      break;
    }
    exit(0);
  }
  return 0;
}
