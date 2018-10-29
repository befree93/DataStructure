#include<iostream>
#include "_deque.h"
#include<string>
using namespace std;

int main()
{
	int num, val;
	_deque<int> dq;
	while (1)
	{
		cin >> num;
		if (num == 1)
		{
			cout << "front�� �߰��� ��: ";
			cin >> val;
			dq.push_front(val);
		}
		else if (num == 2)
		{
			cout << "back�� �߰��� ��: ";
			cin >> val;
			dq.push_back(val);
		}
		else if (num == 3)
		{
			cout << "front���� ���� ����\n";
			if (!dq.empty())dq.pop_front();
			else cout << "�������\n";
		}
		else if (num == 4)
		{
			cout << "back���� ���� ����\n";
			if (!dq.empty())dq.pop_back();
			else cout << "�������\n";
		}
		else if (num == 5)
		{
			cout << "front ����: " << dq.front() << "\n";
		}

		else if (num == 6)
		{
			cout << "back ����: " << dq.back() << "\n";
		}

		else if (num == 7)
		{
			cout << "������ ����: " << dq.size() << "\n";
		}
		else if (num == 8)
		{
			cout << "��� ���� ���\n";
			dq.show();
		}
		else if (num == -1)break;
	}
	return 0;
}