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

#ifndef SWARM_BASE
#define SWARM_BASE

#include <stdio.h>
#ifndef __cplusplus
#include <stdbool.h>
#endif
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

#include <lua5.1/lua.h>
#include <lua5.1/lauxlib.h>
#include <lua5.1/lualib.h>

#include <getopt.h>

// swarm interl headers
#include <swarm/colors.h>

// api headers
#include <api/swarm.h>
#include <api/fs.h>
#include <api/term.h>
#include <api/colors.h>

#ifndef LUA_VERSION_NUM
#error "This computer does not have the proper Lua headers. Please install them."
#endif

#if LUA_VERSION_NUM != 501
#error "This computer has an improper version of the Lua headers. Please install the Lua 5.1 headers."
#endif

static inline void bail(lua_State *L, char *msg){
	fprintf(stderr, "\e[1;31m\nFATAL ERROR:\e[0m\n  %s: %s\n\n",
		msg, lua_tostring(L, -1));
	exit(1);
}

typedef void (*swarm_api_t)(lua_State *L);

int run_lua(char*, int);

#define ELOADFILE 0x1ff
#define ENOPARAM 0x2ff
#define EPCALL 0x3ff
#define EFNOTE 0x4ff

#endif /* end of include guard: SWARM_BASE */
