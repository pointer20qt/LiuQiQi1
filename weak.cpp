#include<iostream>
using namespace std;
//������
template<class T>class REF{
private:
	int count1 = 0;//��¼share��Ӧ��ָ�����
	int count2 = 0;//��¼weakָ��ĸ���
	T* obj = nullptr;//ָ�����
public:
	REF(T* p) :obj(p){
		//���ﴫһ��ָ�룬count1�ĸ�������
		++count1;
	}
	inline void increase(){
		count1++;
	}
	inline void increase_w(){
		count2++;
	}
	inline void reduce(){
		count1--;
		if (count1 == 0){
			delete obj;//ɾ������
			obj = nullptr;//��ָ�������Ϊ��
			if (count2 == 0){//�������ü���Ϊ0��ɾ�����ü���
				delete this;
			}
		}
	}
	inline void reduce_w(){
		count2--;
		if (count2 == 0&&count1 ==0){
			delete this;//ȫ��ɾ��
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



template<class T>class weak_str{
private:
	REF<T>* ref = nullptr;//�ڲ���һ��ָ��ָ��counts�࣬�洢����
public:
	//�޲ι���
	weak_str() = default;
	//����share����
	weak_str(sharked_str<T>& other):ref(other.ref){
		if (ref){
			ref->increase_w();//����һ��weakָ��
		}
	}
	//��������
	weak_str(const weak_str<T>& other){
		ref = other.ref; //���ݶ���other,������һ����ref
		if (ref){
			ref->increase_w();//weak��1
		}
	}
	//�ƶ�����
	weak_str(weak_str<T>&& other){
		swap(ref, other.ref);
	}
	//������ֵ,������һ�������ָ�뵽���ڶ���
	weak_str<T>& operator = (const weak_str<T>& other){
		if (ref){
			ref->increase_w();
		}
		ref = other.ref;
		if (ref){
			ref->increase_w();
		}
		return *this;
	}
	//�ƶ���ֵ,��һ�������ָ���Ƶ����ڶ�����
	weak_str<T>& operator = (weak_str<T>&& other){
		if (ref){
			ref->increase_w();
		}
		ref = other.ref;
		other.ref = nullptr;
		return *this;
	}
	//��������
	void swap(weak_str<T>& other){
		swap(ref, other.ref);
	}
	//��������
	~weak_str(){
		if (ref){
			ref->reduce();
		}
	}
	//reset(),���ٶ���
	void reset(){
		if (ref){
			ref->reduce_w();
		}
		ref = nullptr;
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
	//expired() �ж��Ƿ��Ѿ�ɾ��
	bool expired(){
		if (ref){
			return ref->getcount()>0;//���ض���
		}
		else{
			return false;
		}
	}
	//lock()���һ��shareָ��
	weak_str<T> lock(){
		weak_str<T>tem(ref);
		return tem;
	}
};

template<class T>class weak_str;
template<class T>class sharked_str{
	friend class weak_str<T>;
private:
	REF<T>* ref = nullptr;//�ڲ���һ��ָ��ָ��counts�࣬�洢����
public:
	//�޲ι���
	sharked_str() = default;
	//����ָ�빹��
	sharked_str(T* news){
		ref = new REF<T>(news);//��һ��ָ�룬�����REF����¶���news
	}
	sharked_str(REF<T>* newref){
		ref = newref;
		if (ref){
			ref->increase();
		}
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
			return ref->getcount() == 1;
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