#include<iostream>
#include<vector>
using namespace std;

template<class T>class stack1{
	vector<T>vec;
public:
	//入栈
	void push(T&& a){
		vec.push_back(a);
	}
	//出栈
	void pop(){
		return vec.pop_back();
	}
	//判空
	bool empty(){
		return vec.empty();
	}
	//栈顶
	T& top(){
		return vec.back();
	}
	//大小
	size_t size(){
		return vec.size();
	}
};
//void main(){
//	stack1<int>s1;//定义int类型的对象
//	s1.push(9);
//	s1.push(8);
//	s1.push(1);
//	cout << s1.top() << endl;
//	s1.push(10);
//	s1.pop();
//
//	cout << s1.size() << endl;
//}