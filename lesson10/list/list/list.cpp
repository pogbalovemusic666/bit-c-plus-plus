
// list.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//#include <list>
#include <iostream>
using namespace std;
#include"mylist.h"
using namespace jhx;
int main()

{

	int ar[] = { 0,1, 2, 3, 4,  5, 6, 7, 8, 9 };

	int n = sizeof(ar) / sizeof(int);

	jhx::test1();

	/*list<int>::iterator pos = find(mylist.begin(), mylist.end(), 5);

	cout << *pos << endl;

	reverse(mylist.begin(), pos);
	cout << *pos << endl;

	reverse(pos, mylist.end());
	cout << *pos << endl;

	list<int>::const_reverse_iterator crit = mylist.crbegin();

	while (crit != mylist.crend())

	{

		cout << *crit << " ";

		++crit;

	}

	cout << endl;*/

}

