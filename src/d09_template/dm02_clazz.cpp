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

/**
 * 子类派生模板父类必须制定类型；
 */
class B : public A<int> {
public:
    B(int a, int b) : A<int>(a) {
        this->b = b;
    }

public:
    void printB() {
        std::cout << "b:" << this->b << std::endl;
    }

private:
    int b;
};

int main() {
    A<int> a(100);
    a.printA();

    A<int> a2('c');
    a2.printA();


    B b(100, 200);
    b.printA();
    b.printB();
}
