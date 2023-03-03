//
// Created by bruce on 2019-12-07.
// 函数对象 operator(); 也叫仿函数
//
#include <iostream>
#include <vector>
#include "set"
#include "algorithm"

using namespace std;

//函数对象
template<typename T>
class ShowElement {
public:
    //函数调用操作符
    void operator()(T &t) {
        a++;
        cout << "operator() = " << t << endl;
    }

    void printA() {
        cout << "print count=" << a;
    }

private:
    int a = 0;
};

template<typename T>
void funcShowElement(T &t) {
    cout << "func = " << t << endl;
}

void test() {
    int a = 10;
    ShowElement<int> showElement;
    showElement(a);

    funcShowElement(a);

    {
        vector<int> v1;
        for (int i = 0; i < 10; i++) {
            v1.push_back(i + 1);
        }

        ShowElement<int> show;
        show = for_each(v1.begin(), v1.end(), show);
        show.printA();
    }
    cout << endl;
}

class IsDev {
public:
    IsDev(int dev) {
        this->dev = dev;
    }

    bool operator()(int value) {
        return (value % dev) == 0;
    }

private:
    int dev;
};

/**
 * 一元谓词
 */
void test_find_if() {
    vector<int> v1;
    for (int i = 10; i < 40; i++) {
        v1.push_back(i);
    }

    auto it = find_if(v1.begin(), v1.end(), IsDev(4));
    if (it != v1.end()) {
        cout << "找到了：" << *it << endl;
    } else {
        cout << "没有能被4整除的" << endl;
    }

}

template<typename T>
class SumAdd {
public:
    T operator()(T t1, T t2) {
        return t1 + t2;
    }
};

/**
 * 二元函数对象
 */
void test_two_params() {
    cout << "二元函数对象" << endl;
    vector<int> v1, v2, v3;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);

    v2.push_back(2);
    v2.push_back(4);
    v2.push_back(6);

    v3.resize(10);

    auto it_r = std::transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), SumAdd<int>());
    cout << *it_r << endl;

    for (int &it: v3) {
        cout << it << endl;
    }
}

void FunShowElement(int &t) {
    cout << t << " ";
}

bool MyCompare(const int &a, const int &b) {
    return a < b;
}

//二元谓词，比较大小
void test4() {
    cout << "二元谓词" << endl;
    vector<int> v(10);
    for (int i = 0; i < 10; i++) {
        v[i] = std::rand() % 100;
    }

//    for (int &i: v) {
//        cout << i << endl;
//    }
    //实现遍历
    std::for_each(v.begin(), v.end(), FunShowElement);
    cout << "" << endl;
    std::sort(v.begin(), v.end(), MyCompare);
    std::for_each(v.begin(), v.end(), FunShowElement);
    cout << "" << endl;
}

class CompareNoCase {
public:
    bool operator()(const string &str1, const string &str2) {
        string s1;
        s1.resize(str1.size());
        std::transform(str1.begin(), str1.end(), s1.begin(), [](unsigned char ch) {
            return std::tolower(ch);
        });

        string s2;
        s2.resize(str2.size());
        std::transform(str2.begin(), str2.end(), s2.begin(), [](unsigned char ch) {
            return std::tolower(ch);
        });

        return s1 < s2;
    }
};

//二元谓词在set集合中的应用
void test_set() {
    cout << "二元谓词在set集合中的应用:" << endl;
    set<string, CompareNoCase> set1;
    set1.insert("aaaa");
    set1.insert("bbb");
    set1.insert("ccc");

    auto it = set1.find("AAAA");
    if (it != set1.end()) {
        cout << "查找到：" << *it << endl;
    } else {
        cout << "未查找到" << endl;
    }

    //不区分大小写查找

}


int main() {
    test();
    test_find_if();
    test_two_params();
    test4();
    test_set();
}
