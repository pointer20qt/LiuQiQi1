#include <iostream>
using namespace std;
#include<time.h>

int true1 = 0;
int false1 = 0;
//
int fun1()
{
	int temp = rand() % 5 + 15;
	return temp;
}

bool fun(int n)
{
	int temp = rand() % 100;
	if (temp >= n)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool fun(double n)
{
	double temp = rand() / (double)(RAND_MAX);
	if (temp < n)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	srand(time(0));

	for (int i = 0; i < 100; i++)
	{
		if (fun(0.8))
		{
			true1++;
		}
		else
		{
			false1++;
		}
	}
	cout << "成功的：" << true1 << endl;
	cout << "失败的：" << false1 << endl;
	cout << fun1() << endl;;
	return 0;
	system("pause");
}