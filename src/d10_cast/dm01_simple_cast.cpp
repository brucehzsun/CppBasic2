//
// Created by bruce on 2019-11-09.
//

#include <iostream>

using namespace std;

int main() {
    double pai = 3.1415926;
    int num = (int) pai;
    cout << "num = " << num << endl;

    int num2 = static_cast<int>(pai);
    cout << "num2 = " << num2 << endl;

    char *p = "hello world";
    int *num3 = reinterpret_cast<int *>(p);

    cout << "p = " << p << endl;//%s
    cout << "num3 = " << num3 << endl;//%d

}
