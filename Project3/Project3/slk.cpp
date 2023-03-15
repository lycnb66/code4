#include<iostream>
#include"slk.h"

using namespace std;

template<class T>
int LinkList<T>::LinkList1(T a[], int n)
{
	front = new Node <T>;
	front->next = NULL;
	for (int i = n - 1; i >= 0; i--)
	{
		Node<T>* s = new Node <T>;
		s->data = a[i];
		s->next = front->next;
		front->next = s;
	}

}

template<class T>
int LinkList<T>::LinkList2(T a[], int n)
{
	front = new Node <T>;
	Node <T>* r = front;
	for (int i = 0; i < n; i++)
	{
		Node <T>* s = new Node<T>;
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
}
template<class T>
LinkList<T>::~LinkList()
{
	Node<T>* p = front;
	while (p)
	{
		front = p;
		p = p->next;
		delete front;
	}
}

template<class T>
void LinkList<T>::PrintList()
{
};