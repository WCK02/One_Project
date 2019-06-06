
#include "D:\LuaTest\frameworks\cocos2d-x\cocos\editor-support\cocostudio\ActionTimeline\CocoBindUI.h"//
#include "tolua_bind_RefCocosUI.h"

int luaopen_refcocostudioui_luabinding(lua_State* L)
{
	int argc = lua_gettop(L);
	if (argc == 2)
	{
		Ref* ref = static_cast<Ref*>(tolua_tousertype(L, 1, 0));
		if (!ref)
		{
			CCLOG("userdata is nullptr");
			return 0;
		}
		if (!toluafix_isfunction(L, 2, "LUA_FUNCTION", 0, 0))
		{
			CCLOG("This is not lua function");
			return 0;
		}
		LUA_FUNCTION handle = toluafix_ref_function(L, 2, 0);
		auto func = [=](Ref* obj) {
			LuaStack* stack = LuaEngine::getInstance()->getLuaStack();

			stack->pushObject(obj, "cc.Ref");

			stack->executeFunctionByHandler(handle, 1);
			stack->clean();
		};
		ScriptHandlerMgr::getInstance()->addCustomHandler((void*)ref,handle);

		auto bindUI = CocosBindUI::create();
		bindUI->setCallFunc(ref, func);
	}
	return 0;
}

int luaopen_bindsingle(lua_State* L)
{
	return 0;
}