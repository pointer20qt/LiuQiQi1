#include<iostream>
#include<string>
using namespace std;
class student{
	string name;
public:
	//����
	student(string name){
		this->name = name;
	}
	~student(){
		cout << "ѧ����������" << endl;
	}
};

class school{
private:
	
public:
	string schoolName;
	string schollType;
	string address;
	student *stu;//ָ��
	school(string schoolName, string schoolType, string address){
		this->schoolName = schoolName;
		this->schollType = schollType;
		this->address = address;
		cout << "��ͨ���캯��" << endl;
	}
	//��������,��ʼ���б����
	school(const school& a) :schollType(a.schollType), address(a.address), schoolName(a.schoolName){
		cout << "������캯��" << endl;
		cout << this->schoolName << "����������" << endl;
	}
	//�ƶ�����
	school(school&& t) :schollType(t.schollType), address(t.address), schoolName(t.schoolName){
		stu = t.stu;
		t.stu = NULL;
		cout << "�ƶ����캯��" << endl;
	}
	//ѧУ�����������
	~school(){
		cout << "ѧУ��������" << endl;
		delete stu;
	}
	//��ѧ����
	virtual void open(){
		cout << this->schoolName << "��ѧ��" << endl;
	}
	//Ĭ�Ϲ���
	school(){
		cout << "Ĭ�Ϲ��캯��" << endl;
	}
};
class university :public school
{
public:
	university() :school("��ѧ", "����", "��"){}
	virtual void open(){
		cout << "������" << this->schoolName << "��ѧ��" << endl;
	}
};
//����ָ����õ����������
void printfschool(school* s){
	s->open();
}
//int main(){
//	university a;
//	a.open();
//}
//�Ѹ�����Ϊ�麯����������������ͬ���Ǹ������������оͿ�����д
//��̬���������Ϊ�麯���������ø���ָ��������ຯ���������������ָ�벻�У�����ָ������ָ�벻��
//���������������ָ��ָ��������󣬸���ָ��ɾ�������������⣬Ϊ�˱����ڴ�й©