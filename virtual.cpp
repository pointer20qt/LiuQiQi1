#include<iostream>
#include<string>
using namespace std;
class father
{
public:
	father() {};//默认构造
	//父类虚构函数写为虚析构 
	virtual ~father(){ 
		cout << "析构爸爸" << endl; 
	}
	//父类虚函数
	virtual void DoSomething() {
		cout << "我是爸爸" << endl; 
	}
};
class son : public father//继承于父类
{
public:
	son() {};
	//子类析构函数
	~son() {
		cout << "析构儿子" << endl;
	}
	//子类函数
	void DoSomething(){ 
		cout << "我是儿子" << endl; 
	}
};
void main()
{
	father *p = new son;//创建一个父类的指针
	p->DoSomething();//重写子类函数
	delete p;
}
//覆盖：父类的指针可以指向子类的对象，父类的引用可以指向子类的对象