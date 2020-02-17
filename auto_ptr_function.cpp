#include<iostream>
#include<memory>

using namespace std;

class tool{
public:
	int value=0;
	tool(){
		cout << "tool构造了" << endl;
	}
	~tool(){
		cout << "tool析构了" << endl;
	}
};

//模板化，可以接受任意类型
template<class T>
class Auto_Ptr{
	T* obj = nullptr;
public:
	//无参构造
	Auto_Ptr(){}
	//构造方法，复制一个指针
	Auto_Ptr(T* ptr) :obj(ptr){
	}
    //析构方法，释放指针
	~Auto_Ptr(){
		delete obj;
	}
	//不标准的复制构造（转移内部指针控制权）
	Auto_Ptr(Auto_Ptr<T>& ptr){
		obj = ptr.obj;
		ptr.obj = nullptr;
	}
	//不标准的复制赋值（转移内部指针控制权）
	Auto_Ptr& operator=(Auto_Ptr<T>& ptr){
		delete obj;
		obj = ptr.obj;
		ptr.obj = nullptr;
		return *this;
	}
	//reset()  释放之前的，获得新指针
	void reset(T* newPtr=nullptr){
		delete obj;
		obj = newPtr;
	}
	//release()   释放控制权，返回指针
	T* release(){
		auto temp = obj;
		obj = nullptr;
		return temp;
	}
	//operator*()   模拟指针访问方法
	T& operator*(){
		return *obj;
	}
	//operator->()   模拟指针箭头式访问方法
	T* operator->(){
		return obj;
	}
	//get()   获得指针之乡的指针
	T& get(){
		return obj;
	}
};

int main()
{
	Auto_Ptr<tool> ptr1{ new tool };
	Auto_Ptr<tool> ptr2(ptr1);
	Auto_Ptr<tool> ptr3;
	ptr3 = ptr2;
	(*ptr3).value;
	ptr3->value;
	ptr3.release();
}