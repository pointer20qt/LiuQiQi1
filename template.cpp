#include<iostream>
using namespace std;
//模板函数
template<class T>void swap1(T& a, T& b){
	//成员有指针（引用），直接赋值会造成浅拷贝
	T tem = a;
	//b里的指针放到a里
	a = b;
	//tem里的指针放到b里，tem和b的指针共用一块地址，有问题
	b = tem;
}
class A{
public:
	int value = 0;
	char* p;
	A(int v){
		cout << "构造函数" << endl;
		value = v;
		p = new char[100];//给p申请一块空间存放数据
	}
	//拷贝构造
	A(const A& c):A(c.value){
		cout << "拷贝构造A" << endl;
	}
	//重载=，给tem和b各一块地方存指针
	A& operator=(const A& other){
		delete p;
		p = new char[100];
		value = other.value;
		return *this;
	}
	~A(){
		cout << "析构函数" << endl;
		delete p;
	}
};
void main(){
	//int x1 = 5, x2 = 4;
	//double y1 = 4.90, y2 = 5.01;
	////隐式交换
	////swap1(x1, x2);
	////cout << x1 << "和" << x2 << endl;
	////显式交换
	//swap1<double>(y1,y2);
	//cout << y1 << "和" << x1 << endl;
	////指定模板
	//cout << y1 << "和" << x1 << endl;
	A a(5), b(6);
	
	swap1(a, b);//交换对象
	cout << a.value << "和" << b.value  << endl;
}