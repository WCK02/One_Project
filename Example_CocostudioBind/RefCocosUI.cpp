#include "RefCocosUI.h"

RefCocosUI::RefCocosUI()
{
	BindCocosUI::getInstance()->setRef(this);
	_dic = CCDictionary::create();
	_dic->retain();
}
RefCocosUI::~RefCocosUI()
{
	BindCocosUI::getInstance()->setRef(nullptr);
	_dic->release();
}

RefCocosUI* RefCocosUI::create()
{
	RefCocosUI* ptr = new(std::nothrow) RefCocosUI;
	ptr->autorelease();
	return ptr;
}

bool RefCocosUI::insertRef(const string& name, Ref* obj)
{
	_dic->setObject(obj, name);
	return true;
}

Ref* RefCocosUI::findRef(const string& name)
{
	return _dic->objectForKey(name);
}

BindCocosUI* BindCocosUI::_instance = nullptr;
RefCocosUI* BindCocosUI::now = nullptr;
BindCocosUI* BindCocosUI::getInstance()
{
	if (_instance)
	{
		_instance = new(std::nothrow) BindCocosUI;
	}
	return _instance;
}

void BindCocosUI::setRef(RefCocosUI* _now)
{
	now = _now;
}
void BindCocosUI::push(const string& name, Ref* obj)
{
	now->insertRef(name,obj);
}

Ref* BindCocosUI::bindRef(const string& name)
{
	return now->findRef(name);
}