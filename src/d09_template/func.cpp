//
// Created by bruce on 2019-10-27.
//
#include <iostream>


template<typename T>
void mySwitch(T &a, T &b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}

int main() {
    {
        int x = 100;
        int y = 200;
        mySwitch<int>(x, y);
        printf("x:%d,y:%d\n", x, y);
    }
    {
        char a = 'a';
        char b = 'b';
        mySwitch<char>(a, b);
        printf("a:%c,b:%c\n", a, b);
    }
}