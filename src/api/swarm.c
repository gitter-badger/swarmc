#include <api/swarm.h>

int api_fn_getSwarmVersion(lua_State *L) {
  lua_pushstring(L, "swarm version 1");
  return 1;
}

int api_fn_swarmAdder(lua_State *L) {
  double a = lua_tonumber(L, 1);
  double b = lua_tonumber(L, 2);

  lua_pushnumber(L, a + b);
  return 1;
}

void api_swarm_open(lua_State *L) {
  static const struct luaL_reg swarm_lib[] = {
		{"getSwarmVersion", api_fn_getSwarmVersion},
    {"add", api_fn_swarmAdder},
		{NULL, NULL}};

  luaL_openlib(L, "swarm", swarm_lib, 0);
}
