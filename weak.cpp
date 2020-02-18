#include<iostream>
using namespace std;
//计数类
template<class T>class REF{
private:
	int count1 = 0;//记录share对应的指针个数
	int count2 = 0;//记录weak指针的个数
	T* obj = nullptr;//指向对象
public:
	REF(T* p) :obj(p){
		//向里传一个指针，count1的个数增加
		++count1;
	}
	inline void increase(){
		count1++;
	}
	inline void increase_w(){
		count2++;
	}
	inline void reduce(){
		count1--;
		if (count1 == 0){
			delete obj;//删除对象
			obj = nullptr;//把指针对象置为空
			if (count2 == 0){//并且引用计数为0，删除引用计数
				delete this;
			}
		}
	}
	inline void reduce_w(){
		count2--;
		if (count2 == 0&&count1 ==0){
			delete this;//全部删除
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



template<class T>class weak_str{
private:
	REF<T>* ref = nullptr;//内部有一个指针指向counts类，存储计数
public:
	//无参构造
	weak_str() = default;
	//传递share构造
	weak_str(sharked_str<T>& other):ref(other.ref){
		if (ref){
			ref->increase_w();//增加一个weak指针
		}
	}
	//拷贝构造
	weak_str(const weak_str<T>& other){
		ref = other.ref; //根据对象other,拷贝出一样的ref
		if (ref){
			ref->increase_w();//weak加1
		}
	}
	//移动构造
	weak_str(weak_str<T>&& other){
		swap(ref, other.ref);
	}
	//拷贝赋值,拷贝另一个对象的指针到现在对象
	weak_str<T>& operator = (const weak_str<T>& other){
		if (ref){
			ref->increase_w();
		}
		ref = other.ref;
		if (ref){
			ref->increase_w();
		}
		return *this;
	}
	//移动赋值,另一个对象的指针移到现在对象上
	weak_str<T>& operator = (weak_str<T>&& other){
		if (ref){
			ref->increase_w();
		}
		ref = other.ref;
		other.ref = nullptr;
		return *this;
	}
	//交换函数
	void swap(weak_str<T>& other){
		swap(ref, other.ref);
	}
	//析构函数
	~weak_str(){
		if (ref){
			ref->reduce();
		}
	}
	//reset(),销毁对象
	void reset(){
		if (ref){
			ref->reduce_w();
		}
		ref = nullptr;
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
	//expired() 判断是否已经删除
	bool expired(){
		if (ref){
			return ref->getcount()>0;//返回对象
		}
		else{
			return false;
		}
	}
	//lock()获得一个share指针
	weak_str<T> lock(){
		weak_str<T>tem(ref);
		return tem;
	}
};

template<class T>class weak_str;
template<class T>class sharked_str{
	friend class weak_str<T>;
private:
	REF<T>* ref = nullptr;//内部有一个指针指向counts类，存储计数
public:
	//无参构造
	sharked_str() = default;
	//传递指针构造
	sharked_str(T* news){
		ref = new REF<T>(news);//传一个指针，构造出REF类的新对象news
	}
	sharked_str(REF<T>* newref){
		ref = newref;
		if (ref){
			ref->increase();
		}
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
			return ref->getcount() == 1;
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