//
// Created by bruce sun on 2023/1/31.
//
#include "iostream"
#include "queue"

using namespace std;

class Teacher {
public:
    int age;
};

void test1() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << "队列头元素=" << q.front() << endl;
    cout << "队列size=" << q.size() << endl;

    while (!q.empty()) {
        int front = q.front();
        q.pop();
        cout << front << " ";
    }
    cout << endl;
}

void test2() {
    Teacher t1, t2, t3;
    t1.age = 31;
    t2.age = 32;
    t3.age = 33;

    queue<Teacher *> q;
    q.push(&t1);
    q.push(&t2);
    q.push(&t3);

    while (!q.empty()) {
        Teacher *p = q.front();
        q.pop();
        cout << p->age << " ";
    }
}

int main() {
    //队尾进，队头出
    test1();
    test2();
}