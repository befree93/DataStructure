#ifndef ___VECTOR_H__
#define ___VECTOR_H__

template<typename T>
class _vector
{
private:
	int sz;
	int capacity;
	T *v;
public:
	_vector();
	_vector(int _n);
	~_vector();
	int size();
	bool empty();
	void resize(int _n);
	void clear();
	void push_back(T val);
	void pop_back();
	void reverse();
	T& operator[](const unsigned int &i)const;
	void operator =(const _vector<T> &tmp);
	
};

template<typename T>
_vector<T>::_vector()
{
	sz= 0;
	capacity = 1<<10;
	v = new T[capacity];
}
template<typename T>
_vector<T>::_vector(int _n)
{
	sz = 0;
	capacity = _n;
	v = new T[_n];
}
template<typename T>
_vector<T>::~_vector()
{
	capacity = 0;
	delete[] v;
}
template<typename T>
int _vector<T>::size()
{
	return sz;
}
template<typename T>
bool _vector<T>::empty()
{
	return !sz;
}
template<typename T>
void _vector<T>::resize(int _n)
{
	T *tmp = new T[_n];
	capacity = _n;
	for (int i = 0; i < sz; i++)tmp[i] = v[i];
	delete[] v;
	v = tmp;
}
template<typename T>
void _vector<T>::clear()
{
	delete[] v;
	capacity = 1;
	sz = 0;
	v = new T[1];
}
template<typename T>
void _vector<T> :: push_back(T val)
{
	if (sz == capacity)
	{
		resize(sz * 2);
	}
	v[sz++] = val;
}
template<typename T>
void _vector<T>::pop_back()
{
	if (!sz)return;
	sz--;
}
template<typename T>
void _vector<T>::reverse()
{
	T tmp;
	for (int i = 0; i < sz; i++)
	{
		tmp = v[i];
		v[i] = v[sz - 1 - i];
		v[sz - 1 - i] = tmp;
	}
}
template<typename T>
T& _vector<T>:: operator[](const unsigned int &i)const
{
	//if (i >= 0 && i < sz)
		return v[i];
}
template<typename T>
void _vector<T>:: operator =(const _vector<T> &t)
{
	capacity = t.capacity;
	sz = t.sz;
	delete[] v;
	v = new T[capacity];
	for (int i = 0; i < sz; i++)v[i] = t[i];
}


#endif