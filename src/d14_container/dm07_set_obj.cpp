//
// Created by bruce sun on 2023/2/11.
//
#include "iostream"
#include "set"

using namespace std;

class Student {
public:
    Student(char *name, int age) {
        strcpy(this->name, name);
        this->age = age;
    }

public:
    int age;
    char name[64];
};

struct StuFunction {
    bool operator()(const Student &left, const Student &right) {
        if (left.age < right.age) {
            return true;
        } else {
            return false;
        }
    }
};

void obj_set() {
    //仿函数
    set<Student, StuFunction> set1;
    Student s1("aaa", 10);
    Student s2("bbb", 20);
    Student s3("ccc", 30);
    Student s4("ccc", 30);//完蛋了，set是唯一的，加不进去；

    pair<set<Student, StuFunction>::iterator, bool> ret = set1.insert(s1);
    cout << "ret=" << ret.first->age << ",ret2=" << ret.second << endl;
    set1.insert(s2);
    set1.insert(s3);
    ret = set1.insert(s4);
    cout << "ret=" << ret.first->age << ",ret2=" << ret.second << endl;
    if (!ret.second) {
        cout << "插入失败" << endl;
    }

    for (auto it = set1.begin(); it != set1.end(); it++) {
        cout << it->age << " ";
    }
    cout << endl;
}

void set_find() {
    set<int> s1;
    for (int i = 0; i < 10; i++) {
        s1.insert(i * 2);
    }

    for (auto it = s1.begin(); it != s1.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    auto it = s1.find(6);
    cout << "find=" << *it << endl;
    int count = s1.count(6);
    cout << "count=" << count << endl;

    it = s1.lower_bound(6);
    cout << *it << endl;

    it = s1.upper_bound(6);
    cout << *it << endl;

    auto range = s1.equal_range(6);
    cout << "range start = " << *range.first << endl;
    cout << "range end = " << *range.second << endl;
}

int main() {
    //set 使用红黑树进行设计，平衡二叉树
    obj_set();
    set_find();
}