#include <iostream>
#include <vector>
#include <string>
using namespace std;
class xiaozhang
{
	string name;
public:
	xiaozhang(string sname)
	{
		this->name = sname;
	}
	~xiaozhang()
	{
		cout << "��Ϣ��" << endl;
	}
};
class school
{
public:
	string schoolName;
	string schoolType;
	string address;
	xiaozhang* master;

	school(string schoolName, string schoolType, string address)//���캯����������ʼ��
	{
		cout << "ִ���˹��캯��" << endl;
		this->schoolName = schoolName;
		this->schoolType = schoolType;
		this->address = address;
	}
	~school()
	{
		cout << "ִ����������" << endl;
		delete master;
	}
	//yidong
	school(school&& other) :schoolName(other.schoolName), schoolType(other.schoolType), address(other.address){
		cout << "�ƶ�����" << endl;
		master = other.master;
		other.master = NULL;
	}
};
void run()
{
	school s1("����ʯ�ʹ�ѧ", "��ѧ", "����");
	school s2("��һũҵ��ѧ", "��ѧ", "����");
	swap(s1, s2);
}
school getschool(){
	school s2("����ʯ�ʹ�ѧ", "����", "haha");
	return s2;
}

int main()
{
	school s1(getschool());
	cout << "��һ��" << endl;
}