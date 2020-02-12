#include "test.h"
#include <iostream>
#include<limits.h>
#include<climits>
#include<vector>

using namespace::std;
#pragma comment(lib,"lllllib.lib")

int main(){
	vector<int>arr{ 1, 2, 3, 4, 5, 6 };
	try{
		for (int i = 0; i < 6; i++){
			cout << arr.at(i) << endl;
		}
		throw 5;
		cout << "打印完了" << endl;
	}
	catch (int test){
		cout << "小宇老师" << test << endl;
	}
	catch (out_of_range &d){
		cout <<d.what()<< "数组越界" << endl;
	}
	catch (...){
		cout << "程序出现异常" << endl;
	}
	cout << "程序最后一句" << endl;

}



