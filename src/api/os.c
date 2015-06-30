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

// forward declarations
static int os_version(lua_State *L);
static int os_getComputerID(lua_State *L);

/**
 * Get the SWARM_EMULATED_VERSION
 **/
static int os_version(lua_State *L) {
  lua_pushstring(L,SWARM_EMULATED_VERSION);
  return 1;
}

/**
 * Get the emulated computer ID.
 **/
static int os_getComputerID(lua_State *L) {
  lua_pushnumber(L, 1);
  return 1;
}

// open the fs api
void api_os_open(lua_State *L) {
  const struct luaL_reg os_lib[] = {
    {"version", os_version},
    {"getComputerID", os_getComputerID},
    {NULL, NULL}};

  luaL_openlib(L, "os", os_lib, 0);
}
