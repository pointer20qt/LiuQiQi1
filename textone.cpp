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
		cout <<"��Ϣ��" << endl;
	}
};
class school
{
public:
	string schoolName;
	string schoolType;
	string address;
	xiaozhang* master;
	//Ĭ�Ϲ��캯��
	//school() = default;
	school(const school& p) :schoolName(p.schoolName), schoolType(p.schoolType), address(p.address)
	{
		cout << this->schoolName<<"������" << endl;
		master = new xiaozhang(*(p.master));
	}
	school(string schoolName,string schoolType,string address)//���캯����������ʼ��
	{
		cout << "ִ���˹��캯��" << endl;
		this->schoolName = schoolName;
		this->schoolType = schoolType;
		this->address = address;
		master = new xiaozhang("����ʦ");
	}
	~school()
	{
		cout << "ִ����������" << endl;
		delete master;
	}
	
	
};
void run()
{
	school s1("����ʯ�ʹ�ѧ","��ѧ","����");
	school s2("��һũҵ��ѧ","��ѧ","����");
	swap(s1, s2);
}


int main()
{
	school s1("����","ʯ��","��ѧ");
	cout << "��һ�����" << endl;
}