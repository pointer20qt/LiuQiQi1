#include<iostream>
using namespace std;
//计数类
template<class T>class REF{
private:
	int count1=0;//记录对应的指针个数
	T* obj = nullptr;//指向对象
public:
	REF(T* p):obj(p){
	 //向里传一个指针，count1的个数增加
		++count1;
	}
	inline void increase(){
		count1++;
	}
	inline void reduce(){
		count1--;
		if (count1 == 0){
			delete obj;//删除计数对象
			delete this;//删除shared对应的对象
		}
	}
	//获得对应对象
	T* get(){
		return obj;
	}
	int getcount(){
		return count1;
	}
};
template<class T>class sharked_str{
private:
	REF<T>* ref = nullptr;//内部有一个指针指向counts类，存储计数
public:
	//无参构造
	sharked_str() = default;
	//传递指针构造
	sharked_str(T* news){
		ref = new REF<T>(news);//传一个指针，构造出REF类的新对象news
	}
		//拷贝构造
	sharked_str(const sharked_str& other){
		ref = other.ref; //根据对象other,拷贝出一样的ref
		if (ref){
			ref->increase();//新构建的对象有意义，计数加一，防止空指针调用函数产生异常
		}
	}
		//移动构造
	sharked_str(sharked_str&& other){
		swap(ref, other.ref);//
	}
		//拷贝赋值,拷贝另一个对象的指针到现在对象
	sharked_str& operator = (const sharked_str& other){
		if (ref){
			ref->reduce();//另一个对象的计数引用的个数减1
		}
		ref = other.ref;//对应的指针连新的计数指针
		if (ref){
			ref->increase();//个数加一
		}
		return *this;
	}
		//移动赋值,另一个对象的指针移到现在对象上
	sharked_str& operator = (sharked_str&& other){
		if (ref){
			ref->reduce();//原来的指针减一
		}
		ref = other.ref;
		other.ref = nullptr;//另一个的指针要为空
		return *this;
	}
	//交换函数
	void swap(sharked_str&& other){
		swap(ref, other.ref);
	}
		//析构函数
	~sharked_str(){
		if (ref){
			ref->reduce();
		}
	}
		//reset()销毁 
	//替换对象reset(T*),ref的东西 给新的target
	void reset(T* target){
		if (ref){
			ref->reduce();
		}
		ref = new REF<T>(target);
	}
	//reset(),销毁对象
	void reset(){
		if (ref){
			ref->reduce();
		}
		ref = nullptr;
	}
		//operator*
	T& operator*(){
		if (ref){
			return *ref->get();//返回对象
		}
		else{
			return *(T*)nullptr;
		}
	} 
		//operator->
	T* operator->(){
		if (ref){
			return ref->get();//返回对象
		}
		else{
			return  (T*)nullptr;
		} 
	}
		//get()获得裸指针
	T* get(){
		if (ref){
			return ref->get();//返回对象
		}
		else{
			return  (T*)nullptr;
		}
	}
		//usecount//获得引用计数
		int usecount(){
				if (ref){
					return ref->getcount();//返回对象
				}
				else{
					return 0;
				} 
			}
		//unique//判断引用计数是否唯一
		bool unique(){
			if (ref){
				return ref->getcount()==1; 
			}
			else{
				return false;
			}
		}
		//operator bool//是否关联对象
		operator bool(){
			return ref != nullptr; 
		}

};
void main(){
	sharked_str<int> ptr1(new int);
	cout << "当前引用计数" << ptr1.usecount() << endl;
	sharked_str<int>ptr2(ptr1);
	sharked_str<int>ptr3;
	ptr3 = ptr2;
	cout << "当前引用计数" << ptr1.usecount() << endl;
	cout << "当前引用计数" << ptr2.usecount() << endl;
	cout << "当前引用计数" << ptr3.usecount() << endl;

	ptr2.reset();
}