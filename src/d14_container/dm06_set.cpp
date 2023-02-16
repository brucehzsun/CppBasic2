//
// Created by bruce sun on 2023/2/11.
//
#include "iostream"
#include "set"

using namespace std;

void default_order_set() {
    //自动排序，默认从小到大；
    set<int> s1;
    for (int i = 0; i < 10; i++) {
        s1.insert(i);
    }
    s1.insert(100);
    s1.insert(100);
    s1.insert(100);

    for (int it: s1) {
        cout << it << " ";
    }
    cout << endl;

    while (!s1.empty()) {
        auto it = s1.begin();
        cout << *it << " ";
        s1.erase(it);
    }
    cout << endl;
    cout << "set size = " << s1.size() << endl;
}

void max_order_set() {
    //自动排序，默认从小到大,现在是从大到小
    set<int, greater<>> s1;
    for (int i = 0; i < 10; i++) {
        s1.insert(i);
    }
    s1.insert(100);
    s1.insert(100);
    s1.insert(100);

    for (int it: s1) {
        cout << it << " ";
    }
    cout << endl;

    while (!s1.empty()) {
        auto it = s1.begin();
        cout << *it << " ";
        s1.erase(it);
    }
    cout << endl;
    cout << "set size = " << s1.size() << endl;
}

int main() {
    //set 使用红黑树进行设计，平衡二叉树
    default_order_set();
    max_order_set();
}