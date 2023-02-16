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

template<typename T1, typename T2>
void mysort(T1 *arr, T2 size) {
    T1 tmp;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
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
    {
        int arr[] = {11, 22, 33, 44, 23, 21};
        int size = sizeof(arr) / sizeof(int);
        mysort<int, int>(arr, size);
        for (int i = 0; i < size; i++) {
            std::cout << arr[i]  << " ";
        }
    }
}