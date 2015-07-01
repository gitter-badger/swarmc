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
#include <openssl/sha.h>

static int sha256_main(lua_State *L) {
  unsigned char digest[SHA256_DIGEST_LENGTH];
  const char *string = lua_tostring(L, 1);

  // sha56 hash the string using openssl
  SHA256((unsigned char*)&string, strlen(string), (unsigned char*)&digest);

  char mdString[SHA256_DIGEST_LENGTH*2+1];

  for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
    sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
  }

  // return the result
  lua_pushstring(L, mdString);

  return 1;
}

void load_sha256_hash(lua_State *L) {
  lua_pushcfunction(L, sha256_main);
  lua_setglobal(L, "sha256");
}
