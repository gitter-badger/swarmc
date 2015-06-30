#include <base.h>

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
