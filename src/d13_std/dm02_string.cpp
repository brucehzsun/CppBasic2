//
// Created by bruce on 2019-11-20.
//
#include <iostream>
#include <string>
#include "algorithm"

using namespace std;

void create_string() {
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
void iterator_string() {
    //1.使用for循环迭代；
    string s = "abcdefg";
    for (int i = 0; i < s.size(); i++) {
        cout << s.at(i) << " ";//也可以使用s[i];
    }
    cout << endl;

    //2.使用迭代器
//    for (string::iterator it = s.begin(); it != s.end(); it++) {
    for (auto it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    //3.迭代器简化方法
    for (char &it: s) {
        cout << it << " ";
    }
    cout << endl;
}

//char * to string and string to char*
void convert_char_string() {
    string s = "abcdefg";
    printf("s=%s\n", s.c_str());

    //string copy to buffer;
    char buf[128] = {0};
    s.copy(buf, 3, 0);
    printf("buf:%s\n", buf);
}

//字符串的拼接
void string_join() {
    string s1 = "aaaa";
    string s2 = "bbbb";
    string s3 = s1 + s2;
    cout << "s3 = " << s3 << endl;
    s1.append(s2);
    cout << "s1 = " << s1 << endl;
}

//find
void string_find() {
    string s = "hello world";
    int index = s.find("world", 0);
    cout << "index = " << index << endl;
}

void string_replace() {
    string s = "hello world";
    string replace = "world";
    s.replace(s.find(replace), replace.length(), "WORLD");
    cout << s << endl;
}

void sub_string() {
    string s = "hello1 hello2 hello3";
    auto it = find(s.begin(), s.end(), 'l');
    if (it != s.end()) {
        s.erase(it);
    }

    cout << s << endl;
    s.erase(s.begin(), s.begin() + 5);
    cout << s << endl;

    s.insert(0, "new");
    cout << s << endl;
    s.insert(10, "new");
    cout << s << endl;
    //尾插法
    s.insert(s.length(), "new");
    cout << s << endl;
}

void string_normal() {
    string s = "AAAA bbbb";
//    std::transform(s.begin(), s.end(), s.begin(), std::tolower)
}

int main() {
    create_string();
    iterator_string();
    convert_char_string();
    string_join();
    string_find();
    string_replace();
    sub_string();
    string_normal();
}
