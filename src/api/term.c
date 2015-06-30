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

#include <swarm/base.h>

// declare types
static int term_write(lua_State *lua);
static int term_setTextColor(lua_State *lua);

// default text colors
const char *term_color = RESET;
double term_color_int  = 0;


// methods exposed to lua
static int term_write(lua_State *lua){
  const char *string = lua_tostring(lua, 1);

  printf(term_color);
  printf(string);
  printf(RESET); // color reset

  return 1;
}

/**
 * Set the text color
 **/
static int term_setTextColor(lua_State *lua) {
  int color = luaL_checknumber(lua, 1);

  // check the colors.
  switch(color) {
    case 0:
      term_color = RESET;
    break;

    case colors_white:
      term_color = WHITE;
    break;

    case colors_red:
      term_color = RED;
    break;

    case colors_yellow:
      term_color = YELLOW;
    break;

    case colors_blue:
      term_color = BLUE;
    break;

    case colors_cyan:
      term_color = CYAN;
    break;

    case colors_purple:
      term_color = PURPLE;
    break;

    case colors_green:
      term_color = GREEN;
    break;
  }

  term_color_int = color;

  return 1;
}

/**
 * Get the text color
 **/
static int term_getTextColor(lua_State *L) {
  lua_pushnumber(L, term_color_int);
  return 1;
}

int print(lua_State *L) {
  const char *string = lua_tostring(L, 1);

  printf(term_color);
  printf(string);
  printf("\n"); // print prints a newline
  printf(RESET); // color reset

  return 1;
}

// open the term api
void api_term_open(lua_State *L) {
  const struct luaL_reg term_lib[] = {
    {"write", term_write},
    {"setTextColor", term_setTextColor},
    {"setTextColour", term_setTextColor},
    {"getTextColor", term_getTextColor},
    {"getTextColour", term_getTextColor},
    {NULL, NULL}};

  lua_pushcfunction(L, print);
  lua_setglobal(L, "print");

  luaL_openlib(L, "term", term_lib, 0);
}
