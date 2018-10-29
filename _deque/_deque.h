
#ifndef ___DEQUE_H__
#define ___DEQUE_H__

template<typename T> class _deque;
template<typename T>
class _node
{
	friend class _deque<T>;
private:
	T data;
	_node *l;
	_node *r;
public:
	_node() :l(nullptr), r(nullptr) {}
	_node(T val) :data(val), l(nullptr), r(nullptr) {}
};

template<typename T>
class _deque
{
private:
	int sz;
	_node<T> *head;
	_node<T> *tail;
public:
	_deque();
	~_deque();
	int size();
	bool empty();
	void push_front(T val);
	void push_back(T val);
	void pop_front();
	void pop_back();
	void show();
	T front();
	T back();
};

template<typename T>
_deque<T>::_deque()
{
	sz = 0;
	head = new _node<T>();
	tail = new _node<T>();
}
template<typename T>
_deque<T>::~_deque()
{
	_node<T> *cur = head;
	while (cur != nullptr)
	{
		_node<T> *tmp = cur;
		cur = cur->r;
		delete tmp;
	}
}
template<typename T>
int _deque<T>::size()
{
	return sz;
}
template<typename T>
bool _deque<T>::empty()
{
	return !sz;
}

template<typename T>
void _deque<T>::push_front(T val)
{
	_node<T> *newNode = new _node<T>(val);
	sz++;
	if (nullptr == head->r)
	{
		head->r = newNode;
		newNode->l = head;

		newNode->r = tail;
		tail->l = newNode;
		return;
	}
	newNode->r = head->r;
	head->r->l = newNode;

	newNode->l = head;
	head->r = newNode;
}

template<typename T>
void _deque<T>::push_back(T val)
{
	_node<T> *newNode = new _node<T>(val);
	sz++;
	if (nullptr == head->r)
	{
		head->r = newNode;
		newNode->l = head;

		newNode->r = tail;
		tail->l = newNode;
		return;
	}
	tail->l->r = newNode;
	newNode->l = tail->l;

	newNode->r = tail;
	tail->l = newNode;
}

template<typename T>
void _deque<T>::pop_front()
{
	if (!sz)return;

	_node<T> *delNode = head->r;
	delNode->r->l = head;
	head->r = delNode->r;
	delete delNode;
	sz--;
}
template<typename T>
void _deque<T>::pop_back()
{
	if (!sz)return;
	_node<T> *delNode = tail->l;
	delNode->l->r = tail;
	tail->l = delNode->l;
	delete delNode;
	sz--;
}

template<typename T>
T _deque<T>::front()
{
	return head->r->data;
}
template<typename T>
T _deque<T>::back()
{
	return tail->l->data;
}
template<typename T>
void _deque<T>::show()
{
	_node<T> *cur = head->r;
	while (nullptr != cur && cur != tail)
	{
		std::cout << cur->data << " ";
		cur = cur->r;
	}
	std::cout << "\n";
}













#endif