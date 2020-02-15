#include<iostream>
#include<vector>
using namespace std;

template<class T>class stack1{
	vector<T>vec;
public:
	//��ջ
	void push(T&& a){
		vec.push_back(a);
	}
	//��ջ
	void pop(){
		return vec.pop_back();
	}
	//�п�
	bool empty(){
		return vec.empty();
	}
	//ջ��
	T& top(){
		return vec.back();
	}
	//��С
	size_t size(){
		return vec.size();
	}
};
//void main(){
//	stack1<int>s1;//����int���͵Ķ���
//	s1.push(9);
//	s1.push(8);
//	s1.push(1);
//	cout << s1.top() << endl;
//	s1.push(10);
//	s1.pop();
//
//	cout << s1.size() << endl;
//}