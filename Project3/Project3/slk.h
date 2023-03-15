#ifndef SLK_H
#define SLK_H
template<class T>
struct Node
{
	T data;
	struct Node <T>* next;
};

template<class T>
class LinkList
{
public:
	LinkList() 
	{
		front = new Node <T>;
		front->next = NULL;
	}
	LinkList1(T a[], int n);
	LinkList2(T a[], int n);
	~LinkList();
	void PrintList();
	int GetLength();
	Node<T>* Get(int i);
	int Locate(T x);
	void Insert(int i, T x);
	T Delete(int i);
private:
	Node<T>* front;

};

#endif

