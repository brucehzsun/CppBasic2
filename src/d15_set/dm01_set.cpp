//
// Created by bruce on 2019-12-07.
//
#include <iostream>
#include <set>

using namespace std;

void test1() {
    //使用红黑树
//    set<int> s1;//默认从小到大
//    set<int,less<int>> s1;
    set<int, greater<int>> s1;//从大到小
    for (int i = 0; i < 10; i++) {
        int tmp = rand();
        s1.insert(tmp);
    }
    s1.insert(100);
    s1.insert(100);
    s1.insert(100);
    s1.insert(100);

    for (set<int>::iterator it = s1.begin(); it != s1.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;


    while (!s1.empty()) {
        set<int>::iterator it = s1.begin();
        cout << "delete = " << *it << endl;
        s1.erase(it);
    }
}

int main() {
    test1();

}
