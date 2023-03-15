#include <iostream>
#include <stdexcept>

using namespace std;

const int MAX_SIZE = 100; // �������

template<typename T>
class SeqList {
private:
    T data[MAX_SIZE]; // ���ݴ洢
    int size; // ��ǰԪ�ظ���

public:
    SeqList() {
        size = 0;
    }

    // ��ȡԪ�ظ���
    int getSize() const {
        return size;
    }

    // �ж��Ƿ�Ϊ��
    bool isEmpty() const {
        return size == 0;
    }

    // �ж��Ƿ�����
    bool isFull() const {
        return size == MAX_SIZE;
    }

    // ��ָ��λ�ò���Ԫ��
    void insert(int index, const T& item) {
        if (index < 0 || index > size) {
            throw out_of_range("Index out of range.");
        }

        if (isFull()) {
            throw out_of_range("List is full.");
        }

        // ��Ԫ�غ���
        for (int i = size; i > index; i--) {
            data[i] = data[i - 1];
        }

        // ������Ԫ��
        data[index] = item;
        size++;
    }

    // ɾ��ָ��λ�õ�Ԫ��
    void remove(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range.");
        }

        // ��Ԫ��ǰ��
        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }

        size--;
    }

    // ��ȡָ��λ�õ�Ԫ��
    T& get(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range.");
        }

        return data[index];
    }
};

int main() {
    SeqList<int> list;

    // ���Բ���
    list.insert(0, 1);
    list.insert(1, 2);
    list.insert(2, 3);

    // ���Ի�ȡ
    cout << "list[0]: " << list.get(0) << endl;
    cout << "list[1]: " << list.get(1) << endl;
    cout << "list[2]: " << list.get(2) << endl;

    // ����ɾ��
    list.remove(1);
    cout << "After removing the element at index 1:" << endl;
    cout << "list[0]: " << list.get(0) << endl;
    cout << "list[1]: " << list.get(1) << endl;

    return 0;
}