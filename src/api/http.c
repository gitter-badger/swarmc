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
#include <curl/curl.h>

struct MemoryStruct {
  char *memory;
  size_t size;
};

// alloc memory for curl
static size_t
WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
  size_t realsize = size * nmemb;
  struct MemoryStruct *mem = (struct MemoryStruct *)userp;

  mem->memory = realloc(mem->memory, mem->size + realsize + 1);
  if(mem->memory == NULL) {
    /* out of memory! */
    printf("not enough memory (realloc returned NULL)\n");
    return 0;
  }

  memcpy(&(mem->memory[mem->size]), contents, realsize);
  mem->size += realsize;
  mem->memory[mem->size] = 0;
  return realsize;
}

static int http_get(lua_State *L) {
  CURL *curl;
  CURLcode res;

  // memory management
  struct MemoryStruct chunk;
  chunk.memory = malloc(1);  /* will be grown as needed by the realloc above */
  chunk.size = 0;    /* no data at this point */

  // we init curl fist
  curl_global_init(CURL_GLOBAL_ALL);

  // send all data to this function
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);

  // we pass our 'chunk' struct to the callback function
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);

  /* get a curl handle */
  curl = curl_easy_init();
  if(curl) {
    // set the curl url
    curl_easy_setopt(curl, CURLOPT_URL, lua_tostring(L, 1));

    //curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "name=daniel&project=curl");

    // perform the request
    res = curl_easy_perform(curl);

    // check for errors
    /* check for errors */
    if(res != CURLE_OK) {
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
    }

    // return the data.
    lua_pushstring(L, chunk.memory);

    free(chunk.memory);

    /* always cleanup */
    curl_easy_cleanup(curl);
  } else {
    fprintf(stderr, "failed to init curl");
    return 0;
  }

  // globally cleanup curl.
  curl_global_cleanup();

  return 1;
}

/**
 * we do a http.post
 *
 * @lua_param {string} url - url to post
 * @lua_param {table} data - post data
 **/
static int http_post(lua_State *L) {
  CURL *curl;
  CURLcode res;

  // memory management
  struct MemoryStruct chunk;
  chunk.memory = malloc(1);  /* will be grown as needed by the realloc above */
  chunk.size = 0;    /* no data at this point */

  // we init curl fist
  curl_global_init(CURL_GLOBAL_ALL);

  // send all data to this function
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);

  // we pass our 'chunk' struct to the callback function
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);

  /* get a curl handle */
  curl = curl_easy_init();
  if(curl) {
    // set the curl url
    curl_easy_setopt(curl, CURLOPT_URL, lua_tostring(L, 1));

    //curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "name=daniel&project=curl");

    // perform the request
    res = curl_easy_perform(curl);

    // check for errors
    /* check for errors */
    if(res != CURLE_OK) {
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
    }

    // return the data.
    lua_pushstring(L, chunk.memory);

    free(chunk.memory);

    /* always cleanup */
    curl_easy_cleanup(curl);
  } else {
    fprintf(stderr, "failed to init curl");
    return 0;
  }

  // globally cleanup curl.
  curl_global_cleanup();

  return 1;
}

void api_http_open(lua_State *L) {
  const struct luaL_reg http_lib[] = {
    {"get", http_get},
    {"post", http_post},
    {NULL, NULL}};

  luaL_openlib(L, "http", http_lib, 0);
}
