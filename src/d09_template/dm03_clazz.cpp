//
// Created by bruce on 2019-10-27.
//
#include <iostream>

template<typename T>
class Teacher {
public:
    Teacher(T a) {
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
class MathTeacher : public Teacher<int> {
public:
    MathTeacher(int a, int b) : Teacher<int>(a) {
        this->b = b;
    }

public:
    void printB() {
        std::cout << "b:" << this->b << std::endl;
    }

private:
    int b;
};

template<typename T>
class YuwenTeacher : public Teacher<T> {
public:
    YuwenTeacher(T c, T a) : Teacher<T>(a) {
        this->c = c;
    }

    void printC(){
        std::cout << "c:" << this->c << std::endl;
    }
private:
    T c;
};

int main() {
    std::cout << "size of char = " << sizeof(char) << std::endl;
    std::cout << "size of short = " << sizeof(short) << std::endl;
    std::cout << "size of uint8_t = " << sizeof(uint8_t) << std::endl;
    std::cout << "size of char* = " << sizeof(char *) << std::endl;

    Teacher<int> a(100);
    a.printA();

    Teacher<int> a2('c');
    a2.printA();


    MathTeacher b(100, 200);
    b.printA();
    b.printB();
}
