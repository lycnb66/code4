#ifndef SEQLIST_H
#define SEQLIST_H
template <class T, int N>
class SeqList
{
public:
	SeqList() { int lenth = 0; }//�޲ι��캯��
	SeqList(T a[], int n);//�вι��캯��
	int GetLength() { return length; }//��ȡ˳���ĳ���
	void PrintList(); // �����������ݽṹ
	void Insert(int i, T x);//�ڵ�i��Ԫ�ص�λ�ò���x
	T Delete(int i);//ɾ����i��Ԫ��
	T Get(int i);//��ȡ˳����ϵ�i��Ԫ�ص�ֵ
	int Locate(T x);//����˳�����ֵΪx��Ԫ�أ��ҵ��󷵻���λ��
private:
	T data[N];//�洢Ԫ�ص�����
	int length;//˳���ĳ���
};
#endif

