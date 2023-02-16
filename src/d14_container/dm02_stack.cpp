//
// Created by bruce sun on 2023/1/31.
//
#include "stack"
#include "iostream"

using namespace std;

class Teacher {
public:
    int age;
};

void test1() {
    stack<int> s;
    for (int i = 0; i < 10; i++) {
        s.push(i + 1);
    }
    //出栈
    while (!s.empty()) {
        int tmp = s.top();
        s.pop();
        cout << tmp << ",size=" << s.size() << endl;
    }
}

void test2() {
    Teacher t1, t2, t3;
    t1.age = 31;
    t2.age = 32;
    t3.age = 33;

    stack<Teacher *> s;
    s.push(&t1);
    s.push(&t2);
    s.push(&t3);

    while (!s.empty()) {
        Teacher *p = s.top();
        s.pop();
        cout << "pT=" << p->age << endl;
    }

}

int main() {
    test1();
    test2();
}