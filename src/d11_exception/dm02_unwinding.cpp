//
// Created by bruce on 2019-11-10.
//
#include <iostream>

using namespace std;

class Test {
public:
    Test(int a, int b) {
        this->a = a;
        this->b = b;
        cout << "构造函数" << endl;
    }

    ~Test() {
        cout << "~析构函数" << endl;
    }

    void print() {
        cout << "a = " << a << ", b = " << b << endl;
    }

private:
    int a, b;
};

void playObj() {
    Test *t1 = new Test(1, 2);
    t1->print();

    delete t1;
    throw 1;
}

int main() {

    try {
        playObj();
    } catch (int e) {
        cout << "int exception = " << e << endl;
    } catch (...) {
        cout << "unknown exception" << endl;
    }

}

