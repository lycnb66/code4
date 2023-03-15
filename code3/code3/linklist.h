#ifndef LINKLIST_H
#define LINKLIST_H

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
	}//无参构造函数
	LinkList(T a[], int n);//有参构造函数，初始化列表(头插法)
	~LinkList();//析构函数
	void PrintList();//遍历线性表
	int GetLength();//获取线性表的长度
	Node<T>* Get(int i);//获取线性表上第i个元素节点的地址
	int Locate(T x);//查找线性表中值为x的元素，找到后返回其地址
	void Insert(int i, T x);//在线性表的第i个位置上插入值为x的元素
	T Delete(int i);//删除线性表第i个元素，并将该元素返回
private:
	Node <T>* front;//头指针
};

#endif 

