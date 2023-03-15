#include<iostream>
#include"linklist.h"

using namespace std;

template<class T>
LinkList<T>::LinkList(T a[], int n)
{
	front = new Node<T>;
	front ->next = NULL;
	for (int i = n - 1; i >= 0; i--)
	{
		Node <T>* s = new Node <T>;
		s->data = a[i];
		s->next = front->next;
		front->next = s;
	}
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
	Node<T>* p = front->next;
	while (p != NULL)
	{
		cout<<p->data;
		p = p->next;
	}
	cout << endl;
}

template<class T>
int LinkList<T>::GetLength()
{
	Node<T>* p = front->next;
	int i=0;
	while (p != NULL)
	{
		i++ ;
		p = p->next;
	}
	return i;
}

template<class T>
Node<T>* LinkList<T>::Get(int i)//按位查找
{
	Node<T>* p = front->next;
	int j = 1;
	while (p && j != i)
	{
		p = p->next;
		j++;
	}
	return p;
}

template<class T>
int LinkList<T>::Locate(T x)
{
	Node<T>* p = front->next;
	int j = 1;
	while (p)
	{
		if (p->data == x)
		{
			return j;
		}
		p = p->next;
		j++;
	}
	return -1;
}

template<class T>
void LinkList<T>::Insert(int i, T x)
{
	Node<T>* p = front;
	if (i != 1)
	{
		p = Get(i - 1);
	}
	if (p)
	{
		Node<T>* s = new Node<T>;
		s->data = x;
		s->next = p->next;
		p->next = s;
	}
	else throw"插入位置错误";
}

template<class T>
T LinkList<T>::Delete(int i)
{
	Node<T>* p = front->next;
	if (i != 1)
	{
		p = Get(i - 1);
	}
	Node<T>* q =p->next;
	p->next = q->next;
	T x = q->data;
	delete q;
	return x;
}

int main() {
	int arr[] = { 1, 3, 5, 7, 9 };
	LinkList<int> list(arr, 5); 
	cout << "原始链表内容：";
	list.PrintList();
	system("pause");

	cout << "链表长度：" << list.GetLength() << endl;
	system("pause");

	int pos = list.Locate(7);
	if (pos != -1) {
		cout << "7 的位置在 " << pos << endl;
	}
	else {
		cout << "7 不在链表中" << endl;
	}

	system("pause");
	list.Insert(3, 4);
	cout << "在位置 3 插入 4 后的链表：";
	list.PrintList();

	system("pause");
	int deleted = list.Delete(2);
	cout << "删除位置 2 的元素 " << deleted << " 后的链表：";
	list.PrintList();
	system("pause");
	return 0;
}



