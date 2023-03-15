#include <iostream>
#include <stdexcept>

using namespace std;

const int MAX_SIZE = 100; // 最大容量

template<typename T>
class SeqList {
private:
    T data[MAX_SIZE]; // 数据存储
    int size; // 当前元素个数

public:
    SeqList() {
        size = 0;
    }

    // 获取元素个数
    int getSize() const {
        return size;
    }

    // 判断是否为空
    bool isEmpty() const {
        return size == 0;
    }

    // 判断是否已满
    bool isFull() const {
        return size == MAX_SIZE;
    }

    // 在指定位置插入元素
    void insert(int index, const T& item) {
        if (index < 0 || index > size) {
            throw out_of_range("Index out of range.");
        }

        if (isFull()) {
            throw out_of_range("List is full.");
        }

        // 将元素后移
        for (int i = size; i > index; i--) {
            data[i] = data[i - 1];
        }

        // 插入新元素
        data[index] = item;
        size++;
    }

    // 删除指定位置的元素
    void remove(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range.");
        }

        // 将元素前移
        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }

        size--;
    }

    // 获取指定位置的元素
    T& get(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range.");
        }

        return data[index];
    }
};

int main() {
    SeqList<int> list;

    // 测试插入
    list.insert(0, 1);
    list.insert(1, 2);
    list.insert(2, 3);

    // 测试获取
    cout << "list[0]: " << list.get(0) << endl;
    cout << "list[1]: " << list.get(1) << endl;
    cout << "list[2]: " << list.get(2) << endl;

    // 测试删除
    list.remove(1);
    cout << "After removing the element at index 1:" << endl;
    cout << "list[0]: " << list.get(0) << endl;
    cout << "list[1]: " << list.get(1) << endl;

    return 0;
}