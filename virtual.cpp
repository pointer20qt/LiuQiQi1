#include<iostream>
#include<string>
using namespace std;
class father
{
public:
	father() {};//Ĭ�Ϲ���
	//�����鹹����дΪ������ 
	virtual ~father(){ 
		cout << "�����ְ�" << endl; 
	}
	//�����麯��
	virtual void DoSomething() {
		cout << "���ǰְ�" << endl; 
	}
};
class son : public father//�̳��ڸ���
{
public:
	son() {};
	//������������
	~son() {
		cout << "��������" << endl;
	}
	//���ຯ��
	void DoSomething(){ 
		cout << "���Ƕ���" << endl; 
	}
};
void main()
{
	father *p = new son;//����һ�������ָ��
	p->DoSomething();//��д���ຯ��
	delete p;
}
//���ǣ������ָ�����ָ������Ķ��󣬸�������ÿ���ָ������Ķ���