#include<iostream>
#include<string>
using namespace std;
class student{
	string name;
public:
	//构造
	student(string name){
		this->name = name;
	}
	~student(){
		cout << "学生类析构了" << endl;
	}
};

class school{
private:
    string schoolName;
	string schollType;
	string address;
public:
	student *stu;//指针
	school(string schoolName, string schoolType, string address){
		this->schoolName = schoolName;
		this->schollType = schollType;
		this->address = address;
		cout << "普通构造函数" << endl;
	}
	//拷贝构造,初始化列表参数
	school(const school& a) :schollType(a.schollType), address(a.address), schoolName(a.schoolName){
		cout << "深拷贝构造函数" << endl;
		cout << this->schoolName << "拷贝建立了" << endl;
	}
	//移动拷贝
	school(school&& t) :schollType(t.schollType), address(t.address), schoolName(t.schoolName){
		stu = t.stu;
		t.stu = NULL;
		cout << "移动构造函数" << endl;
	}
	//学校类的析构函数
	~school(){
		cout << "学校类析构了" << endl;
		delete stu;
	}
	//开学函数
	void open(){
		cout << this->schoolName << "开学了" << endl;
	}
	//默认构造
	school(){
		cout << "默认构造函数" << endl;
	}
};
class university :public school
{
public:
	university():school("河北","但是","大"){}
	void open(){
		school::open();
	}
};
//int main(){
//	university a;
//	a.open();
//}
//创建对象必须调用构造函数。在构造函数中初始化
//子类构造对象时，先调用父类的构造函数，有参就是有参，无参就是无参，父类初始化好了再调用子类的构造函数
//析构的时候先析构子类的再析构父类的
//隐藏：当子类有个函数和父类相同时，父类的会被隐藏