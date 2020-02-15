#include<iostream>
using namespace std;
//模板参数包
//template<class...args>void Lprintf(args...d){
//	//arg...d 是一个变量，可以接受多个参数 
//}
//递归拆包
template<class T, class...args1> void Lprintf(T f,args1...d){
	cout << f << endl;
	Lprintf(d...);
}
void Lprintf(){
	cout << "递归终结" << endl;
}
void main(){
	Lprintf<int>(3,3.14,"nisd",0.1);
}