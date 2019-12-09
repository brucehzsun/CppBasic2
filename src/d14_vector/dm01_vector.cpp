//
// Created by bruce on 2019-12-01.
//
#include <iostream>
#include <vector>

using namespace std;

void test1() {
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(6);
    v1.push_back(7);

    cout << "头部元素：" << v1.front() << endl;
    cout << "尾部元素：" << v1.back() << endl;
    v1.pop_back();
    cout << "尾部元素：" << v1.back() << endl;

    //修改头部元素
    v1.front() = 111;
    v1.back() = 222;
    cout << "头部元素：" << v1.front() << endl;
    cout << "尾部元素：" << v1.back() << endl;
    cout << "迭代器遍历：" << endl;
    for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "插入100：" << endl;
    v1.insert(v1.begin() + 2, 100);
    for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    cout << "删除100：" << endl;
    auto it = v1.erase(v1.begin() + 2);
    cout << "删除100："<< *it << endl;
    for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

}

int main() {
    test1();
}
