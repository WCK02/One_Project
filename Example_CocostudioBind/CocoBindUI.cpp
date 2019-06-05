//CocosBindUIControl* CocosBindUIControl::_instance = nullptr;
#include "CocoBindUI.h"

CocosBindUI* CocosBindUIControl::_cur = nullptr;
CocosBindUIControl _instance;
CocosBindUIControl* CocosBindUIControl::getInstance()
{
	//if (!_instance)
	{
		//_instance = new(std::nothrow) CocosBindUIControl;
	}
	return &_instance;
}

void CocosBindUIControl::pushRef(const string& name, Ref* obj)
{
	_cur->insert(name, obj);
}

Ref* CocosBindUIControl::bind(const string& name)
{
	return _cur->find(name);
}

void CocosBindUIControl::setCur(CocosBindUI* cur)
{
	_cur = cur;
}

void CocosBindUIControl::luaCallFunc()
{
	_cur->_callfunc(_cur->_handle);
}

CocosBindUI* CocosBindUI::create()
{
	auto ptr = new(std::nothrow) CocosBindUI;
	ptr->autorelease();
	return ptr;
}

CocosBindUI::CocosBindUI()
{
	CocosBindUIControl::getInstance()->setCur(this);
}

CocosBindUI::~CocosBindUI()
{
	CocosBindUIControl::getInstance()->setCur(nullptr);
}

Ref* CocosBindUI::find(const string& name)
{
	auto iter = m_map.find(name);
	if (iter != m_map.end())
		return iter->second;
	return nullptr;
}
void CocosBindUI::insert(const string& name, Ref* obj)
{

}
void CocosBindUI::setCallFunc(Ref* obj, const std::function<void(Ref*)>& func)
{
	_handle = obj;
	_callfunc = func;
}