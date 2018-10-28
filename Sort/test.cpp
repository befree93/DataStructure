#include<iostream>
#include "Sort.h"
int main()
{
	int a[11] = { 6,3,7,9,1,2,2,2,11,20 };
	//bubbleSort(a, a + 10);
	//selectionSort(a, a + 10);
	//_insertionSort(a, a+10);
	//_qSort(a, a + 10);
	mergeSort(a, 10);
	for (int i = 0; i < 10; i++)printf("%d ", a[i]);
	return 0;
}