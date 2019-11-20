//
// Created by bruce on 2019-11-20.
//
#include <iostream>
#include <string>

using namespace std;

void test1() {
    string s1 = "aaaaaa";
    string s2("bbbbb");
    string s3 = s2; //通过拷贝构造函数 初始化s3；
    string s4(10, 'c');

    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    cout << "s4 = " << s4 << endl;
}

//string 的迭代
void test2() {
    //1.使用for循环迭代；
    string s = "abcdefg";
    for (int i = 0; i < s.size(); i++) {
        cout << s.at(i) << " ";//也可以使用s[i];
    }
    cout << endl;

    //2.使用迭代器
    for (string::iterator it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

//char * to string and string to char*
void test3() {
    string s = "abcdefg";
    printf("s=%s\n", s.c_str());

    char buf[128] = {0};
    s.copy(buf, 3, 0);
    printf("buf:%s\n", buf);
}

//字符串的拼接
void test4() {
    string s1 = "aaaa";
    string s2 = "bbbb";
    s1 += s2;
    cout << "s1 = " << s1 << endl;
    s1.append(s2);
    cout << "s1 = " << s1 << endl;
}

//find
void test5() {
    string s = "hello world";
    int index = s.find("world", 0);
    cout << "index = " << index << endl;
}

int main() {
//    test1();
//    test2();
//    test3();
//    test4();
    test5();
}
