#include<iostream>
#include"seqlist.h"
using namespace std;

template<class T, int N> SeqList<T, N>::SeqList(T a[], int n) 
{ 
	if (n > N)throw"���鳤�ȳ���˳�����󳤶�"; 
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
	if (length >= N)throw"�����쳣"; 
	if (i < 1 || i > length + 1)throw"λ���쳣";
	for (int j = length; j >= i; j--) 
	{ 
		data[j] = data[j - 1];
	}
	data[i - 1] = x; 
	length++; 
}

template<class T, int N> T SeqList<T, N>::Delete(int i)
{ 
	if (0 == length)throw"�����쳣";
	if (i < 1 || i > length)throw"λ���쳣"; 
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
	if (i < 1 || i > length)throw"����λ�÷Ƿ�";
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

	// ����PrintList()
	cout << "˳���Ԫ�أ� ";
	list.PrintList();
	system("pause");

	// ����Insert()
	cout << "�ڵ�����λ�ò���6" << endl;
	list.Insert(3, 6);
	cout << "�г�������Ԫ��: ";
	list.PrintList();
	system("pause");

	// ����Delete()
	cout << "ɾ�����ĸ�Ԫ��" << endl;
	int del=list.Delete(4);
	cout << "�г�ɾ�����Ԫ��: ";
	list.PrintList();
	cout << "ɾ����Ԫ��Ϊ��" <<del<< endl;
	system("pause");

	// ����Get()
	cout << "�ڶ���Ԫ��Ϊ: " << list.Get(2) << endl;
	system("pause");

	// ����Locate()
	int pos = list.Locate(4);
	if (pos != 0) {
		cout << "4��λ��Ϊ: " << pos << endl;
	}
	else {
		cout << "����û�����Ԫ��" << endl;
	}

	return 0;
}
