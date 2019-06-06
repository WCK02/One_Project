#include <cocos2d.h>
using namespace cocos2d;
#include "tolua_bind_RefCocosUI.h"
#include <stdlib.h>
#include "2d\RefCocosUI.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"

using namespace std;
int luaopen_refcocostudioui_luabinding(lua_State* L)
{
	int argc = lua_gettop(L) - 1;
	if (argc == 1)
	{
		string name = tolua_tostring(L, -1, 0);
		Node* obj = dynamic_cast<Node*>(BindCocosUI::getInstance()->bindRef(name.c_str()));
		if (obj)
		{
			//tolua_pushusertype(L, (void*)obj, "cc.Node");//这个是强行指定其为注册的cc.Node类型
			//tolua_register_gc(L, lua_gettop(L));
			object_to_luaval<cocos2d::Node>(L, "cc.Node", (cocos2d::Node*)obj);//这个运用了type_trait的技巧进行lua注册里的类型推断
		}
		return 1;
	}
	luaL_error(L, "lua_ref_CocostudioBindUI:bind:UI");
	return 0;
}