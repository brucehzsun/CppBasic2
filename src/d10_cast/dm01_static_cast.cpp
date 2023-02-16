//
// Created by bruce on 2019-11-09.
//

#include <iostream>

using namespace std;

int main() {
    double pai = 3.1415926;
    int num = (int) pai;
    cout << "num = " << num << endl;

    //编译器进行类型检查,是否可以隐式类型转换，增强程序的健壮性
    int num2 = static_cast<int>(pai);
    cout << "pai = " << pai << endl;
    cout << "num2 = " << num2 << endl;

    char *p = "hello world";
    int *num3 = reinterpret_cast<int *>(p);
    int *num4 = (int *)p;

    cout << "p = " << p << endl;//%s
    cout << "num3 = " << num3 << endl;//%d
    cout << "num4 = " << num4 << endl;//%d

}
