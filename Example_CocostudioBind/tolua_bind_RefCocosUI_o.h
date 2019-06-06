#pragma once
extern "C"{
#include "lua.h"
#include "tolua++.h"
}
#include "tolua_fix.h"
#include "CCLuaEngine.h"

int luaopen_refcocostudioui_luabinding(lua_State* L);
int luaopen_bindsingle(lua_State* L);