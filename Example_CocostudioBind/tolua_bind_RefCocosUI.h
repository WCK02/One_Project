#pragma once
#include <cocos2d.h>
using namespace cocos2d;

extern "C"{
#include "lua.h"
#include "tolua++.h"
}
#include "..\cocos2d-x\cocos\scripting\lua-bindings\manual\tolua_fix.h"
#include "..\cocos2d-x\cocos\scripting\lua-bindings\manual\CCLuaEngine.h"

int luaopen_refcocostudioui_luabinding(lua_State* L);