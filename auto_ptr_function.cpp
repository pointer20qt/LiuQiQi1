#include<iostream>
#include<memory>

using namespace std;

class tool{
public:
	int value=0;
	tool(){
		cout << "tool������" << endl;
	}
	~tool(){
		cout << "tool������" << endl;
	}
};

//ģ�廯�����Խ�����������
template<class T>
class Auto_Ptr{
	T* obj = nullptr;
public:
	//�޲ι���
	Auto_Ptr(){}
	//���췽��������һ��ָ��
	Auto_Ptr(T* ptr) :obj(ptr){
	}
    //�����������ͷ�ָ��
	~Auto_Ptr(){
		delete obj;
	}
	//����׼�ĸ��ƹ��죨ת���ڲ�ָ�����Ȩ��
	Auto_Ptr(Auto_Ptr<T>& ptr){
		obj = ptr.obj;
		ptr.obj = nullptr;
	}
	//����׼�ĸ��Ƹ�ֵ��ת���ڲ�ָ�����Ȩ��
	Auto_Ptr& operator=(Auto_Ptr<T>& ptr){
		delete obj;
		obj = ptr.obj;
		ptr.obj = nullptr;
		return *this;
	}
	//reset()  �ͷ�֮ǰ�ģ������ָ��
	void reset(T* newPtr=nullptr){
		delete obj;
		obj = newPtr;
	}
	//release()   �ͷſ���Ȩ������ָ��
	T* release(){
		auto temp = obj;
		obj = nullptr;
		return temp;
	}
	//operator*()   ģ��ָ����ʷ���
	T& operator*(){
		return *obj;
	}
	//operator->()   ģ��ָ���ͷʽ���ʷ���
	T* operator->(){
		return obj;
	}
	//get()   ���ָ��֮���ָ��
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