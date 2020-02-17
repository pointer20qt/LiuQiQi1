#include<iostream>
using namespace std;
//������
template<class T>class REF{
private:
	int count1=0;//��¼��Ӧ��ָ�����
	T* obj = nullptr;//ָ�����
public:
	REF(T* p):obj(p){
	 //���ﴫһ��ָ�룬count1�ĸ�������
		++count1;
	}
	inline void increase(){
		count1++;
	}
	inline void reduce(){
		count1--;
		if (count1 == 0){
			delete obj;//ɾ����������
			delete this;//ɾ��shared��Ӧ�Ķ���
		}
	}
	//��ö�Ӧ����
	T* get(){
		return obj;
	}
	int getcount(){
		return count1;
	}
};
template<class T>class sharked_str{
private:
	REF<T>* ref = nullptr;//�ڲ���һ��ָ��ָ��counts�࣬�洢����
public:
	//�޲ι���
	sharked_str() = default;
	//����ָ�빹��
	sharked_str(T* news){
		ref = new REF<T>(news);//��һ��ָ�룬�����REF����¶���news
	}
		//��������
	sharked_str(const sharked_str& other){
		ref = other.ref; //���ݶ���other,������һ����ref
		if (ref){
			ref->increase();//�¹����Ķ��������壬������һ����ֹ��ָ����ú��������쳣
		}
	}
		//�ƶ�����
	sharked_str(sharked_str&& other){
		swap(ref, other.ref);//
	}
		//������ֵ,������һ�������ָ�뵽���ڶ���
	sharked_str& operator = (const sharked_str& other){
		if (ref){
			ref->reduce();//��һ������ļ������õĸ�����1
		}
		ref = other.ref;//��Ӧ��ָ�����µļ���ָ��
		if (ref){
			ref->increase();//������һ
		}
		return *this;
	}
		//�ƶ���ֵ,��һ�������ָ���Ƶ����ڶ�����
	sharked_str& operator = (sharked_str&& other){
		if (ref){
			ref->reduce();//ԭ����ָ���һ
		}
		ref = other.ref;
		other.ref = nullptr;//��һ����ָ��ҪΪ��
		return *this;
	}
	//��������
	void swap(sharked_str&& other){
		swap(ref, other.ref);
	}
		//��������
	~sharked_str(){
		if (ref){
			ref->reduce();
		}
	}
		//reset()���� 
	//�滻����reset(T*),ref�Ķ��� ���µ�target
	void reset(T* target){
		if (ref){
			ref->reduce();
		}
		ref = new REF<T>(target);
	}
	//reset(),���ٶ���
	void reset(){
		if (ref){
			ref->reduce();
		}
		ref = nullptr;
	}
		//operator*
	T& operator*(){
		if (ref){
			return *ref->get();//���ض���
		}
		else{
			return *(T*)nullptr;
		}
	} 
		//operator->
	T* operator->(){
		if (ref){
			return ref->get();//���ض���
		}
		else{
			return  (T*)nullptr;
		} 
	}
		//get()�����ָ��
	T* get(){
		if (ref){
			return ref->get();//���ض���
		}
		else{
			return  (T*)nullptr;
		}
	}
		//usecount//������ü���
		int usecount(){
				if (ref){
					return ref->getcount();//���ض���
				}
				else{
					return 0;
				} 
			}
		//unique//�ж����ü����Ƿ�Ψһ
		bool unique(){
			if (ref){
				return ref->getcount()==1; 
			}
			else{
				return false;
			}
		}
		//operator bool//�Ƿ��������
		operator bool(){
			return ref != nullptr; 
		}

};
void main(){
	sharked_str<int> ptr1(new int);
	cout << "��ǰ���ü���" << ptr1.usecount() << endl;
	sharked_str<int>ptr2(ptr1);
	sharked_str<int>ptr3;
	ptr3 = ptr2;
	cout << "��ǰ���ü���" << ptr1.usecount() << endl;
	cout << "��ǰ���ü���" << ptr2.usecount() << endl;
	cout << "��ǰ���ü���" << ptr3.usecount() << endl;

	ptr2.reset();
}