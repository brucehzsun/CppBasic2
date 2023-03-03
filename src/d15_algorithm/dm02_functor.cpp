//
// Created by bruce on 2019-12-07.
//
#include <iostream>
#include <set>

using namespace std;

class Student {
public:
    Student(string name, int age) {
        this->name = name;
        this->age = age;
    }

    string name;
    int age;
};

struct StuFunctor {
    bool operator()(const Student &left, const Student &right) {
        return left.age < right.age;
    }
};

void test() {
    Student s1("s1", 24);
    Student s2("s2", 14);
    Student s3("s3", 34);
    Student s4("s4", 74);
    Student s5("s5", 54);
    Student s6("s6", 54);

    set<Student, StuFunctor> set_;
    pair<set<Student, StuFunctor>::iterator, bool> ret = set_.insert(s1);
    ret = set_.insert(s2);
    ret = set_.insert(s3);
    ret = set_.insert(s4);
    ret = set_.insert(s5);
    cout << "ret = " << ret.second << " " << ret.first->name << endl;
    //插入失败，已经存在s5了。返回的是s5；
    ret = set_.insert(s6);
    cout << "ret = " << ret.second << " " << ret.first->name << endl;

    for (set<Student, StuFunctor>::iterator it = set_.begin(); it != set_.end(); it++) {
        cout << it->age << " " << it->name << endl;
    }
}

int main() {
    test();
}
