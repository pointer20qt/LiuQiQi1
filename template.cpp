#include<iostream>
using namespace std;
//ģ�庯��
template<class T>void swap1(T& a, T& b){
	//��Ա��ָ�루���ã���ֱ�Ӹ�ֵ�����ǳ����
	T tem = a;
	//b���ָ��ŵ�a��
	a = b;
	//tem���ָ��ŵ�b�tem��b��ָ�빲��һ���ַ��������
	b = tem;
}
class A{
public:
	int value = 0;
	char* p;
	A(int v){
		cout << "���캯��" << endl;
		value = v;
		p = new char[100];//��p����һ��ռ�������
	}
	//��������
	A(const A& c):A(c.value){
		cout << "��������A" << endl;
	}
	//����=����tem��b��һ��ط���ָ��
	A& operator=(const A& other){
		delete p;
		p = new char[100];
		value = other.value;
		return *this;
	}
	~A(){
		cout << "��������" << endl;
		delete p;
	}
};
void main(){
	//int x1 = 5, x2 = 4;
	//double y1 = 4.90, y2 = 5.01;
	////��ʽ����
	////swap1(x1, x2);
	////cout << x1 << "��" << x2 << endl;
	////��ʽ����
	//swap1<double>(y1,y2);
	//cout << y1 << "��" << x1 << endl;
	////ָ��ģ��
	//cout << y1 << "��" << x1 << endl;
	A a(5), b(6);
	
	swap1(a, b);//��������
	cout << a.value << "��" << b.value  << endl;
}