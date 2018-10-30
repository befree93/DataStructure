#include<iostream>
#include<string>
#include"_vector.h"
using namespace std;

int main()
{
	int num;
	string t;
	//_vector<int> v;
	_vector<string > v;
	while (1)
	{
		cin >> num;
		if (num == 1)
		{
			cout << "추가할 데이터를 입력하시오: ";
			cin >> t;
			v.push_back(t);
		}
		else if (num == 2)
		{
			cout << "데이터 삭제\n";
			v.pop_back();
		}
		else if (num == 3)
		{
			cout << "원소의 개수: " << v.size() << "\n";
			for (int i = -1; i < v.size(); i++)cout << v[i] << " "; cout << endl;
		}

		else if (num == -1)
		{
			break;
		}
	}
	return 0;
}