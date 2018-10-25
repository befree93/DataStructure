//#pragma once
//#include<iostream>
#ifndef __HEAP_H__
#define __HEAP_H__


template<typename T>
class HEAP
{
	typedef bool priorityCmp(const T &t1, const T &t2);
private:
	int capacity;
	int sz;
	priorityCmp *pc;
	T* heap;
	void swap(T *t1, T *t2) { T tmp = *t1; *t1 = *t2; *t2 = tmp; }

public:
	HEAP();
	HEAP(int _n);
	~HEAP();
	void resize(int _n);
	bool empty();
	int size();
	void initPriority(priorityCmp f);
	bool cmp(const T& t1, const T& t2);
	void push(T val);
	void pop();
	T top();
};
template<typename T>
HEAP<T>::HEAP()
{
	capacity = 1 << 10;
	sz = 0;
	heap = new T[1 << 10];
	pc = nullptr;
}
template<typename T>
HEAP<T>::HEAP(int _n)
{
	pc = nullptr;
	capacity = _n;
	sz = 0;
	heap = new T[_n];
}
template<typename T>
HEAP<T>::~HEAP()
{
	delete[] heap;
}
template<typename T>
void HEAP<T>::resize(int _n)
{
	capacity = _n;
	T *tmp = new T[_n];
	for (int i = 0; i < capacity; i++)tmp[i] = heap[i];
	delete[] heap;
	heap = tmp;
}
template<typename T>
int HEAP<T>::size()
{
	return sz;
}
template<typename T>
bool HEAP<T>::empty()
{
	return !sz;
}

template<typename T>
void HEAP<T>::initPriority(priorityCmp f)
{
	pc = f;
}
template<typename T>
bool HEAP<T>::cmp(const T& t1, const T& t2)
{
	if (pc == nullptr)
	return t1 > t2;

	return pc(t1, t2);
}
template<typename T>
T HEAP<T>::top()
{
	if (sz)return heap[1];
}

template<typename T>
void HEAP<T>::push(T val)
{
	if (sz + 1 == capacity)
		resize(capacity * 2);

	heap[++sz] = val;
	for (int i = sz; i >> 1; i >>= 1)
	{
		if (cmp(heap[i], heap[i >> 1]))swap(&heap[i], &heap[i >> 1]);
		else break;
	}
}
template<typename T>
void HEAP<T>::pop()
{
	if (!sz)return;
	heap[1] = heap[sz--];
	for (int cur = 1; cur <= sz;)
	{
		int l = cur << 1, r = cur << 1 | 1, next = l;
		if (next > sz)return;
		if (r <= sz && cmp(heap[r], heap[next]))next = r;
		if (!cmp(heap[next], heap[cur]))return;
		swap(&heap[cur], &heap[next]);
		cur = next;
	}
}
#endif