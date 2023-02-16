//
// Created by bruce on 2019-11-18.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

class Teacher {
public:
    Teacher(){}
    Teacher(int age) {
        this->age = age;
    }

    Teacher(const Teacher &t1) {
        this->age = t1.age;
        memcpy(this->name, t1.name, 64);
        cout << "拷贝构造函数执行,age=" << this->age << endl;
    }

    int age;
    char name[64];
};

void test3() {
    Teacher *t1 = new Teacher(11);
    Teacher *t2 = new Teacher(22);
    Teacher *t3 = new Teacher(33);

    vector<Teacher *> v1;
    //添加的是指针，不会触发拷贝构造函数
    v1.push_back(t1);
    v1.push_back(t2);
    v1.push_back(t3);

    for (auto it = v1.begin(); it != v1.end(); it++) {
        cout << "age = " << (*it)->age << " " << endl;
    }

    delete t1;
    delete t2;
    delete t3;
}

void test2() {
    Teacher t1(22), t2(23), t3(35);
    vector<Teacher> v1(3);
    //拷贝到容器中
    v1.push_back(t1);
    v1.push_back(t2);
    v1.push_back(t3);

    for (auto it = v1.begin(); it != v1.end(); it++) {
        cout << "age = " << it->age << " ";
    }
}

void test1() {
    //容器
    vector<int> v1;
    //拷贝到容器中,会触发拷贝构造函数
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(3);
    v1.push_back(4);

    //迭代器
//    for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
    for (auto it = v1.begin(); it != v1.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    //算法
    int num = count(v1.begin(), v1.end(), 3);
    cout << "等于3的个数 = " << num << endl;
}

int main() {
//    test1();
    test2();
//    test3();
}
