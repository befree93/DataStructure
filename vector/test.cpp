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
			cout << "�߰��� �����͸� �Է��Ͻÿ�: ";
			cin >> t;
			v.push_back(t);
		}
		else if (num == 2)
		{
			cout << "������ ����\n";
			v.pop_back();
		}
		else if (num == 3)
		{
			cout << "������ ����: " << v.size() << "\n";
			for (int i = -1; i < v.size(); i++)cout << v[i] << " "; cout << endl;
		}

		else if (num == -1)
		{
			break;
		}
	}
	return 0;
}