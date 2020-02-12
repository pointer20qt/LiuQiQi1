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
		cout << "休息了" << endl;
	}
};
class school
{
public:
	string schoolName;
	string schoolType;
	string address;
	xiaozhang* master;

	school(string schoolName, string schoolType, string address)//构造函数，用来初始化
	{
		cout << "执行了构造函数" << endl;
		this->schoolName = schoolName;
		this->schoolType = schoolType;
		this->address = address;
	}
	~school()
	{
		cout << "执行析构函数" << endl;
		delete master;
	}
	//yidong
	school(school&& other) :schoolName(other.schoolName), schoolType(other.schoolType), address(other.address){
		cout << "移动构造" << endl;
		master = other.master;
		other.master = NULL;
	}
};
void run()
{
	school s1("东北石油大学", "大学", "大庆");
	school s2("八一农业大学", "大学", "大庆");
	swap(s1, s2);
}
school getschool(){
	school s2("东北石油大学", "大庆", "haha");
	return s2;
}

int main()
{
	school s1(getschool());
	cout << "下一句" << endl;
}