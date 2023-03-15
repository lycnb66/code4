#include<iostream>
#include"seqlist.h"
using namespace std;

template<class T, int N> SeqList<T, N>::SeqList(T a[], int n) 
{ 
	if (n > N)throw"数组长度超过顺序表最大长度"; 
    for (int i = 0; i < n; i++) 
    { 
	data[i] = a[i];
	length = n; 
    } 
}

template<class T, int N> void SeqList<T, N>::PrintList() 
{ 
	for (int i = 0; i < length; i++) 
	{
		cout << data[i] << " "; 
	} 
	cout << endl;
}

template<class T, int N> void SeqList<T, N>::Insert(int i, T x) 
{ 
	if (length >= N)throw"上溢异常"; 
	if (i < 1 || i > length + 1)throw"位置异常";
	for (int j = length; j >= i; j--) 
	{ 
		data[j] = data[j - 1];
	}
	data[i - 1] = x; 
	length++; 
}

template<class T, int N> T SeqList<T, N>::Delete(int i)
{ 
	if (0 == length)throw"下溢异常";
	if (i < 1 || i > length)throw"位置异常"; 
	T x = data[i - 1]; 
	int j = i;
	for (; j < length; j++) 
	{ 
		data[j - 1] = data[j];
	} 
	length--; 
	return x; 
}

template<class T, int N> T SeqList<T, N>::Get(int i) 
{ 
	if (i < 1 || i > length)throw"查找位置非法";
	return data[i - 1]; 
}

template<class T, int N> int SeqList<T, N>::Locate(T x) 
{ 
	for (int i = 0; i < length; i++)
	{ 
		if (data[i] == x)return i + 1; 
	}
	return 0; 
}

int main() {
	int arr[5] = { 1, 2, 3, 4, 5 }; SeqList<int, 10> list(arr, 5);

	// 测试PrintList()
	cout << "顺序表元素： ";
	list.PrintList();
	system("pause");

	// 测试Insert()
	cout << "在第三个位置插入6" << endl;
	list.Insert(3, 6);
	cout << "列出插入后的元素: ";
	list.PrintList();
	system("pause");

	// 测试Delete()
	cout << "删除第四个元素" << endl;
	int del=list.Delete(4);
	cout << "列出删除后的元素: ";
	list.PrintList();
	cout << "删除的元素为：" <<del<< endl;
	system("pause");

	// 测试Get()
	cout << "第二个元素为: " << list.Get(2) << endl;
	system("pause");

	// 测试Locate()
	int pos = list.Locate(4);
	if (pos != 0) {
		cout << "4的位置为: " << pos << endl;
	}
	else {
		cout << "表中没有这个元素" << endl;
	}

	return 0;
}
