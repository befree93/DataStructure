#include<iostream>
#include<algorithm>
#include"_string.h"
using namespace std;

int main()
{
	int num;
	_string a,b,c;
	_string arr[10] = { "banana","apple","ape","append","da","db","daab","daabc","ace","cc" };
	char buf[12] = "ABCD";
	a = "abc";
	b = "def";
	c = a + b;
	cout << c << " " << c.size() << "\n";
	c += "zzz";
	cout << c <<" "<<c.size()<< "\n";
	sort(arr, arr + 10);
	for (int i = 0; i < 10; i++)cout << arr[i] << "\n";
	return 0;
}