// lesson6.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
template<class T>
T Add(const T& left, const T& right)
{
	return left + right;
}
int main()
{
	int a1 = 10, a2 = 20;
	double d1 = 10.1, d2 = 20.0;
	//cout << Add(a1, a2) << endl;
	cout << Add(d1, d2) << endl;
	
}