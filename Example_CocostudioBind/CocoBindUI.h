#ifndef CocosBindUI_h
#define CocosBindUI_h
#include <cocos2d.h>
using namespace cocos2d;
using namespace std;

class CocosBindUI;

class CC_DLL CocosBindUIControl
{
public:
	static CocosBindUIControl* getInstance();
	void pushRef(const string& name,Ref* obj);
	Ref* bind(const string&);
	~CocosBindUIControl() { CCLOG("Des COCOS"); };
	void setCur(CocosBindUI*);
	void luaCallFunc();
private:
	static CocosBindUI* _cur;
};
// = nullptr;

class CC_DLL CocosBindUI : public Ref
{
	friend class CocosBindUIControl;

public:
	static CocosBindUI* create();

	Ref* find(const string&);
	void insert(const string& name,Ref*);
	
	void setCallFunc(Ref*,const std::function<void(Ref*)>&);

private:
	CocosBindUI();
	~CocosBindUI();

	map<const string, Ref*> m_map;
	Ref* _handle;
	std::function<void(Ref*)> _callfunc;
};






#endif