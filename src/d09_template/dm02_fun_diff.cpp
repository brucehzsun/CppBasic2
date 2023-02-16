//
// Created by bruce sun on 2022/12/29.
//
#include "iostream"

int max(int &a, int &b) {
    std::cout << "普通函数" << std::endl;
    return a > b ? a : b;
}


template<typename T>
T max(T &a, T &b) {
    std::cout << "模版函数" << std::endl;
    return a > b ? a : b;
}

void mySwitch(int &a, char &c) {
    std::cout << "我是普通函数" << std::endl;
}

int main() {
    int a = 10, b = 20;
    float c = 3.0, d = 4.0;
    //模版函数，严格按照类型匹配，不会进行类型自动转换
    std::cout << max(a, b) << std::endl;//优先选择普通函数
    std::cout << max<int>(a, b) << std::endl;
    std::cout << max<>(a, b) << std::endl;
    std::cout << max(c, d) << std::endl;//如果函数模版产生更好的匹配，使用函数模版
}