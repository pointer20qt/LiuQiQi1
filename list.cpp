#include<iostream>
#include<vector>
#include<Initializer_List>
#include<assert.h>
using namespace std;
class abc{
private:
	int* a;
public:
	
	abc(initializer_list<int>vec){
		a = new int[vec.size()];
		for (int i =0; i != vec.size();i++){
			 a[i] = *(vec.begin() + i);
		}
	}
	//����int&�����г�Ա���޸�
	int& operator[](const int i){
		assert(i >= 2 && i <= 6);
		return a[i];
	}
};
int main()
{
	abc c({1,2,3,4,5,6,7});//�������󣬴����������ʼ����
	cout << c[4] << endl;
	c[4] = 0;
	cout << c[4] << endl;
}