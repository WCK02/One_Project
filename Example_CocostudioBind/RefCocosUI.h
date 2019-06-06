#ifndef RefCocosUI_h
#define RefCocosUI_h

#include <cocos2d.h>
USING_NS_CC;
using namespace std;

class RefCocosUI;

class CC_DLL BindCocosUI
{
public:
	static BindCocosUI* getInstance();
	static BindCocosUI* _instance;
	Ref* bindRef(const string&);
	void setRef(RefCocosUI*);
	void push(const string&, Ref*);
	static RefCocosUI* now;
};


class CC_DLL RefCocosUI : public Ref
{
public:
	static RefCocosUI* create();
	RefCocosUI();
	~RefCocosUI();

	bool insertRef(const string&,Ref*);
	Ref* findRef(const string&);
private:
	CCDictionary* _dic;
};



#endif // RefCocosUI_h
