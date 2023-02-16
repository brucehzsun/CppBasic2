//
// Created by bruce sun on 2023/1/3.
//
#include "iostream"

using namespace std;

template<typename T>
class Complex {
public:
    Complex(T a, T b) {
        this->a = a;
        this->b = b;
    }

    void printCom();

    Complex operator+(Complex &c2);

    template<typename T1>
    friend ostream &operator<<(ostream &out, Complex<T1> &c2);
//    friend ostream &operator<<(ostream &out, Complex &c2) {
//        out << "c.a:" << c2.a << ",c.b:" << c2.b;
//        return out;
//    }

private:
    int a;
    int b;
};

template<typename T>
void Complex<T>::printCom() {
    cout << "a:" << this->a << ",b:" << this->b << endl;
}

template<typename T>
Complex<T> Complex<T>::operator+(Complex<T> &c2) {
    Complex<T> tmp(this->a + c2.a, this->b + c2.b);
    return tmp;
}

// << >> 运算符重载只能用友元函数，其他运算符重载都要写成成员函数。
template<typename T>
ostream &operator<<(ostream &out, Complex<T> &c2) {
    out << "c.a:" << c2.a << ",c.b:" << c2.b;
    return out;
}


int main() {
    Complex<int> c1(1, 2);
    c1.printCom();
    Complex<int> c2(3, 4);
    Complex<int> c3 = c1 + c2;
    cout << "c3=" << c3 << endl;
}
