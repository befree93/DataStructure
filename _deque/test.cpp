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
			cout << "front에 추가할 값: ";
			cin >> val;
			dq.push_front(val);
		}
		else if (num == 2)
		{
			cout << "back에 추가할 값: ";
			cin >> val;
			dq.push_back(val);
		}
		else if (num == 3)
		{
			cout << "front에서 원소 제거\n";
			if (!dq.empty())dq.pop_front();
			else cout << "비어있음\n";
		}
		else if (num == 4)
		{
			cout << "back에서 원소 제거\n";
			if (!dq.empty())dq.pop_back();
			else cout << "비어있음\n";
		}
		else if (num == 5)
		{
			cout << "front 원소: " << dq.front() << "\n";
		}

		else if (num == 6)
		{
			cout << "back 원소: " << dq.back() << "\n";
		}

		else if (num == 7)
		{
			cout << "원소의 개수: " << dq.size() << "\n";
		}
		else if (num == 8)
		{
			cout << "모든 원소 출력\n";
			dq.show();
		}
		else if (num == -1)break;
	}
	return 0;
}