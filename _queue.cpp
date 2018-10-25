#include<iostream>

template<typename T>
class _queue
{
private:

	int capacity;
	int fr,re;
	T *q;
public:
	_queue();
	_queue(int _n);
	~_queue();
	int size();
	bool empty();
	void resize(int _n);
	void push(T val);
	void pop();
	T front();
};
template<typename T>
_queue<T>::_queue()
{
	capacity = 1<<7;
	fr=re= 0;
	q = new T[1<<7];
}
template<typename T>
_queue<T>::_queue(int _n)
{
	capacity = _n;
	fr=re = 0;
	q = new T[_n];
}
template<typename T>
_queue<T>::~_queue()
{
	delete[] q;
}
template<typename T>
int _queue<T>::size()
{
	return re - fr;
}
template<typename T>
bool _queue<T>::empty()
{
	return !(re - fr > 0);
}
template<typename T>
void _queue<T>::resize(int _n)
{
	capacity = _n;
	T *tmp = new T[_n];
	for (int i =0; i+fr <re; i++)tmp[i] = q[i+fr];
	fr = 0; re -= fr;
	delete[] q;
	q = tmp;
}
template<typename T>
void _queue<T>::push(T val)
{
	if (re==capacity)
	{
		resize(capacity * 2);
	}
	q[re++] = val;
}
template<typename T>
void _queue<T>::pop()
{
	if (fr < re)fr++;
}
template<typename T>
T _queue<T>::front()
{
	if (fr < re)return q[fr];
}
