#include<iostream>
using namespace std;
//ģ�������
//template<class...args>void Lprintf(args...d){
//	//arg...d ��һ�����������Խ��ܶ������ 
//}
//�ݹ���
template<class T, class...args1> void Lprintf(T f,args1...d){
	cout << f << endl;
	Lprintf(d...);
}
void Lprintf(){
	cout << "�ݹ��ս�" << endl;
}
void main(){
	Lprintf<int>(3,3.14,"nisd",0.1);
}