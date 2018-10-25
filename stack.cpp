#include<iostream>

template<typename T>
class _stack
{
private:
	int capacity;
	int sz;
	T *st;
public:
	_stack();
	_stack(int _n);
	~_stack();
	int size();
	bool empty();
	void resize(int _n);
	void push(T val);
	T top();
	void pop();
};

template<typename T>
_stack<T>::_stack()
{
	capacity = 1 << 10;
	sz = 0;
	st = new T[capacity];
}
template<typename T>
_stack<T>::_stack(int _n)
{
	capacity = _n;
	sz = 0;
	st = new T[_n];
}
template<typename T>
_stack<T>::~_stack()
{
	delete[] st;
}
template<typename T>
int _stack<T>::size()
{
	return sz;
}
template<typename T>
bool _stack<T>::empty()
{
	return !sz;
}
template<typename T>
void _stack<T>::resize(int _n)
{
	capacity = _n;
	T *tmp = new T[_n];
	for (int i = 0; i < sz; i++)tmp[i] = st[i];
	delete[]st;
	st = tmp;
}
template<typename T>
void _stack<T>::push(T val)
{
	if (sz == capacity)
	{
		resize(capacity * 10);
	}
	st[sz++] = val;
}
template<typename T>
void _stack<T>::pop()
{
	if (sz)sz--;
}
template<typename T>
T _stack<T>::top()
{
	if (sz)
		return st[sz - 1];
}
