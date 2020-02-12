#include <iostream>
#include <vector>
#include <string>
using namespace std;
class xiaozhang
{
	string name;
public:
	xiaozhang(string sname)
	{
		this->name = sname;
	}
	~xiaozhang()
	{
		cout <<"休息了" << endl;
	}
};
class school
{
public:
	string schoolName;
	string schoolType;
	string address;
	xiaozhang* master;
	//默认构造函数
	//school() = default;
	school(const school& p) :schoolName(p.schoolName), schoolType(p.schoolType), address(p.address)
	{
		cout << this->schoolName<<"建立了" << endl;
		master = new xiaozhang(*(p.master));
	}
	school(string schoolName,string schoolType,string address)//构造函数，用来初始化
	{
		cout << "执行了构造函数" << endl;
		this->schoolName = schoolName;
		this->schoolType = schoolType;
		this->address = address;
		master = new xiaozhang("杨老师");
	}
	~school()
	{
		cout << "执行析构函数" << endl;
		delete master;
	}
	
	
};
void run()
{
	school s1("东北石油大学","大学","大庆");
	school s2("八一农业大学","大学","大庆");
	swap(s1, s2);
}


int main()
{
	school s1("东北","石油","大学");
	cout << "下一句代码" << endl;
}