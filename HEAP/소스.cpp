#include<iostream>
#include "HEAP.h"
bool ff(const int &a, const int &b) { return a < b; }
int main()
{
	HEAP<int> pq;
	pq.initPriority(ff);
		for(int i=1;i<11;i++)pq.push(i);
		while (!pq.empty())
		{
			printf("%d %d\n", pq.size(), pq.top());
			pq.pop();
		}
	return 0;
}