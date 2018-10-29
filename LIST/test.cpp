#include<iostream>
#include"list.h"
using namespace std;


int main()
{
	int num;
	List<int> list;
	while (1)
	{
		scanf("%d", &num);
		
		if (num == 2)
		{
			int val;
			printf("추가할 데이터 : ");
			scanf("%d", &val);
			list.push(val);
		}
		else if (num == 3)
		{
			int val;
			printf("삭제할 데이터 : ");
			scanf("%d", &val);
			list.pop(val);
		}
		else if (num == 4)
		{
			list.showAll();
		}
		else if (num == 5)printf("%d\n", list.size());
		else if (num == 6)list.qSort(list.begin(), list.end());
	}
	return 0;
}