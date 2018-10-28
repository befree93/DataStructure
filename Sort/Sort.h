#ifndef __Sort_H__
#define __Sort_H__
template<typename T>
void swap(T *t1, T *t2) { T tmp = *t1; *t1 = *t2; *t2 = tmp; }

template<typename T>
void bubbleSort(T s, T e)
{
	for (T i = e - 1; i >= s; i--)
		for (T j = s; j < i; j++)
			if (*j > *(j + 1))swap(j, (j + 1));
}

template<typename T>
void selectionSort(T s, T e)
{
	T min;
	for (T i = s; i < e - 1; i++)
	{
		min = i;
		for (T j = i + 1; j < e; j++)
			if (*j < *min)min = j;
		swap(min, i);
	}
}

template<typename T>
void _insertionSort(T s, T e)
{
	T tmp = s;
	for (T i = s + 1; i < e; i++)if (*tmp < *i)tmp = i;
	swap(tmp, s);
	for (T i = s + 1; i < e; i++)
	{
		for (T j = i; *j < *s; --j, --s)swap(s, j);
		s = i;
	}
}
template<typename T>
void _qSort(T s, T e)
{
	if (s == e)return;

	swap(s, (e - s) / 2 + s);
	T pv = s;
	T l = s + 1;
	T r = e - 1;
	while (l <= r)
	{
		while (l <= r && *pv >= *l)l++;
		while (l <= r && *pv < *r)r--;
		if (l < r)swap(l, r);
	}
	swap(pv, r);
	_qSort(s, r);
	_qSort(r + 1, e);
}

template<typename T>
void mergeSort(T z[], int size)
{
	if (size <= 1)return;
	int mid = size >> 1;
	mergeSort(z, mid);
	mergeSort(z + mid, size - mid);
	T *buf = new T[size];
	int l = 0, r = mid, k = 0;
	while (l < mid&&r < size)buf[k++] = z[l] < z[r] ? z[l++] : z[r++];
	while (l < mid)buf[k++] = z[l++];
	while (r < size)buf[k++] = z[r++];
	for (int i = 0; i < size; i++)z[i] = buf[i];
	delete[] buf;
}
#endif