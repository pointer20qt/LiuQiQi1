#include<iostream>
using namespace std;
class A
{
private:
	int num;
public:
	friend void fun(A &a);
};
void fun(A &a)
{
	cout << "���" << endl;
}
void main()
{
	A a;
	fun(a);
}