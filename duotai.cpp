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
	
public:
	string schoolName;
	string schollType;
	string address;
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
	virtual void open(){
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
	university() :school("大学", "但是", "大"){}
	virtual void open(){
		cout << "哈尔滨" << this->schoolName << "开学了" << endl;
	}
};
//父类指针调用的是子类对象
void printfschool(school* s){
	s->open();
}
//int main(){
//	university a;
//	a.open();
//}
//把父类设为虚函数，则父类与子类相同的那个函数在子类中就可以重写
//多态：如果父类为虚函数，可以用父类指针调用子类函数，父类对象子类指针不行，父类指针子类指针不行
//虚析构：解决父类指针指向子类对象，父类指针删除子类对象的问题，为了避免内存泄漏