//
// Created by bruce on 2019-11-09.
//
#include <iostream>

using namespace std;

void print(const char *p) {
    //p可以修改才行，如果原始数据类型不能修改，会出现崩溃，慎用；
    char *p1 = const_cast<char *>(p);
    p1[0] = 'A';
    cout << p << endl;
    cout << p1 << endl;
}

int main() {
    const char* buf = "abcdefg";
    print(buf);
}
