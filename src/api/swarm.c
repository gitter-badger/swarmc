#include <api/swarm.h>

int api_fn_getSwarmVersion(lua_State *L) {
  lua_pushstring(L, "swarm version 1");
  return 1;
}

void api_swarm_open(lua_State *L) {
  static const struct luaL_reg swarm_lib[] = {
		{"getSwarmVersion", api_fn_getSwarmVersion},
		{NULL, NULL}};

  luaL_openlib(L, "swarm", swarm_lib, 0);
}
