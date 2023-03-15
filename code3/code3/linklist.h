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
	}//�޲ι��캯��
	LinkList(T a[], int n);//�вι��캯������ʼ���б�(ͷ�巨)
	~LinkList();//��������
	void PrintList();//�������Ա�
	int GetLength();//��ȡ���Ա�ĳ���
	Node<T>* Get(int i);//��ȡ���Ա��ϵ�i��Ԫ�ؽڵ�ĵ�ַ
	int Locate(T x);//�������Ա���ֵΪx��Ԫ�أ��ҵ��󷵻����ַ
	void Insert(int i, T x);//�����Ա�ĵ�i��λ���ϲ���ֵΪx��Ԫ��
	T Delete(int i);//ɾ�����Ա��i��Ԫ�أ�������Ԫ�ط���
private:
	Node <T>* front;//ͷָ��
};

#endif 

