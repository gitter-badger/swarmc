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

// i have no fucking clue what I am doing

#include <swarm/base.h>


// build the colors object.
void api_colors_open(lua_State *L) {
  lua_newtable(L);

  lua_pushnumber(L, colors_white);
  lua_setfield(L, -2, "white");

  lua_pushnumber(L, colors_orange);
  lua_setfield(L, -2, "orange");

  lua_pushnumber(L, colors_magenta);
  lua_setfield(L, -2, "magenta");

  lua_pushnumber(L, colors_lightBlue);
  lua_setfield(L, -2, "lightBlue");

  lua_pushnumber(L, colors_yellow);
  lua_setfield(L, -2, "yellow");

  lua_pushnumber(L, colors_lime);
  lua_setfield(L, -2, "lime");

  lua_pushnumber(L, colors_pink);
  lua_setfield(L, -2, "pink");

  lua_pushnumber(L, colors_lightGray);
  lua_setfield(L, -2, "lightGray");

  lua_pushnumber(L, colors_cyan);
  lua_setfield(L, -2, "cyan");

  lua_pushnumber(L, colors_purple);
  lua_setfield(L, -2, "purple");

  lua_pushnumber(L, colors_blue);
  lua_setfield(L, -2, "blue");

  lua_pushnumber(L, colors_brown);
  lua_setfield(L, -2, "brown");

  lua_pushnumber(L, colors_green);
  lua_setfield(L, -2, "green");

  lua_pushnumber(L, colors_red);
  lua_setfield(L, -2, "red");

  lua_pushnumber(L, colors_black);
  lua_setfield(L, -2, "black");

  lua_setglobal(L, "colors");
}
