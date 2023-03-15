#ifndef SEQLIST_H
#define SEQLIST_H
template <class T, int N>
class SeqList
{
public:
	SeqList() { int lenth = 0; }//无参构造函数
	SeqList(T a[], int n);//有参构造函数
	int GetLength() { return length; }//获取顺序表的长度
	void PrintList(); // 遍历各个数据结构
	void Insert(int i, T x);//在第i个元素的位置插入x
	T Delete(int i);//删除第i个元素
	T Get(int i);//获取顺序表上第i个元素的值
	int Locate(T x);//查找顺序表中值为x的元素，找到后返回其位置
private:
	T data[N];//存储元素的数组
	int length;//顺序表的长度
};
#endif

