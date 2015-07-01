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

#include <base.h>
#include <colors.h>

static int file_exists(char* file_name) {
  return access(file_name, F_OK) != -1;
}

int run_lua(char* main_file, int debug) {
  if (!main_file) {
    errno = ENOPARAM;
    return -1;
  } else if(!file_exists(main_file)) {
    errno = EFNOTE;
    return -1;
  } else {
    if (debug)
      fprintf(stdout, RED "debug: " CYAN "creating lua state.\n" RESET);
    lua_State* L = luaL_newstate();

    if (debug)
      fprintf(stdout, RED "debug: " CYAN "opening lua libraries.\n" RESET);

    luaL_openlibs(L);
    api_fs_open(L);
    api_swarm_open(L);
    api_term_open(L);
    api_colors_open(L);
    api_os_open(L);
    api_http_open(L);

    /* crypto */
    api_aes_open(L);

    if (debug)
      fprintf(stdout, RED "debug: " CYAN "trying to load lua script %s.\n" RESET, main_file);

    if (luaL_loadfile(L, main_file)) {
      errno = ELOADFILE;
      return -1;
    }

    if (debug)
      fprintf(stdout, RED "debug: " CYAN "trying to execute lua script %s.\n" RESET, main_file);

    if (lua_pcall(L, 0, 0, 0)) {
      errno = EPCALL;
      return -1;
    }
    if (debug)
      fprintf(stdout, RED "debug: " CYAN "closing lua state.\n" RESET);

    lua_close(L);
    return 0;
  }
}
