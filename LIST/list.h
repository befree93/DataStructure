#ifndef __LIST_H__
#define __LIST_H__

template<typename T>
void _swap(T *a, T *b) { T tmp = *a; *a = *b; *b = tmp; }

template<typename T>class List;
template<typename T>
class Node
{
	friend class List<T>;
private:
	T val;
	Node<T> *left;
	Node<T> *right;
public:
	Node<T>() : val(0), left(nullptr), right(nullptr) {}
	Node<T>(T v) : val(v), left(nullptr), right(nullptr) {}
};
template<typename T>
class List
{
private:
	int sz;
	Node<T> *head;
	Node<T> *tail;

public:
	Node<T>* begin();
	Node<T>* end();
	List();
	~List();
	void push(T v);
	void pop(T v);
	int size();
	bool empty();
	bool find(T v);
	void qSort(Node<T> *first, Node<T> *last);
	void showAll()// for the test
	{
		Node<T> *pos = head->right;
		while (pos != nullptr&&pos != tail)
		{
			printf("%d ", pos->val);
			pos = pos->right;
		}
		printf("\n");
	}
};

template<typename T>
Node<T>* List<T>::begin()
{
	return head->right;
}
template<typename T>
Node<T>* List<T>::end()
{
	return tail->left;
}
template<typename T>
List<T>::List()
{
	sz = 0;
	head = new Node<T>();
	tail = new Node<T>();
}
template<typename T>
List<T>::~List()
{
	Node<T> *cur = head, *delNode;
	while (cur != nullptr)
	{
		delNode = cur;
		cur = cur->right;
		delete delNode;
	}
}

template<typename T>
int List<T>::size()
{
	return sz;
}
template<typename T>
bool List<T>::empty()
{
	return !sz;
}

template<typename T>
void List<T>::push(T v)
{
	Node<T> *newNode = new Node<T>(v);
	if (nullptr == head->right)
	{
		head->right = newNode;
		newNode->left = head;
		newNode->right = tail;
		tail->left = newNode;
	}
	else
	{
		newNode->left = tail->left;
		tail->left->right = newNode;
		newNode->right = tail;
		tail->left = newNode;
	}
	sz++;
}

template<typename T>
bool List<T>::find(T v)
{
	Node<T> *cur = head->right;
	while (cur != nullptr)
	{
		if (cur->val == v)return 1;
		cur = cur->right;
	}
	return 0;
}
template<typename T>
void List<T>::pop(T v)
{
	bool remove = false;
	Node<T> *cur = head->right;
	while (cur != nullptr)
	{
		if (cur->val == v)
		{
			cur->left->right = cur->right;
			cur->right->left = cur->left;
			delete cur;
			remove = true;
			break;
		}
		cur = cur->right;
	}
	if (remove)sz--;
	else printf("does not exist!");
}

template<typename T>
void List<T>::qSort(Node<T> *start, Node<T> *end)
{
	if (start->left == end)return;
	Node<T> *l = start->right;
	Node<T> *r = end;
	while (1)
	{
		while (l->left != r && l->val <= start->val)l = l->right;
		while (r->right != l && r->val > start->val)r = r->left;
		if (l->left == r)break;
		_swap(&(l->val), &(r->val));
	}
	_swap(&(start->val), &(r->val));
	qSort(start, r->left);
	qSort(r->right, end);
}
#endif
