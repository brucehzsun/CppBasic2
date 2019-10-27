//
// Created by bruce on 2019-10-27.
//
#include <iostream>

template<typename T>
class A {
public:
    A(T a) {
        this->a = a;
    }

public:
    void printA() {
        std::cout << "a:" << a << std::endl;
    }

private:
    T a;
};

int main() {
    A<int> a(100);
    a.printA();

    A<int> b('c');
    b.printA();
}
