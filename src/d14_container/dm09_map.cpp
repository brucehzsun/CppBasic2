//
// Created by bruce sun on 2023/2/13.
//
#include "iostream"
#include "map"
#include "string"

using namespace std;

void basic_map() {
    map<int, string> map1;

    //方法1
    map1.insert(pair<int, string>(1, "aaaa"));
    map1.insert(pair<int, string>(2, "bbbb"));

    //方法2
    map1.insert(make_pair(3, "ccccc"));
    map1.insert(make_pair(4, "ddddd"));

    //方法3
    map1.insert(map<int, string>::value_type(5, "fffff"));
    map1.insert(map<int, string>::value_type(6, "gggggg"));

    //方法4
    map1[7] = "hhhhh";
    map1[8] = "iiiiii";

    //迭代
    for (auto &it: map1) {
        cout << it.first << "=>" << it.second << endl;
    }

    //删除
    while (!map1.empty()) {
        auto it = map1.begin();
        cout << "delete " << it->first << " => " << it->second << endl;
        map1.erase(it);
    }
}

void map_different() {
    map<int, string> map1;
    pair<map<int, string>::iterator, bool> ret1 = map1.insert(make_pair(1, "aaaa"));
    cout << "ret = " << ret1.second << ",it=" << ret1.first->first << " => " << ret1.first->second << endl;

    auto ret2 = map1.insert(make_pair(1, "bbbb"));//不会覆盖aaaa
    cout << "ret = " << ret2.second << ",it=" << ret2.first->first << " => " << ret2.first->second << endl;
    if (!ret2.second) {
        cout << "插入失败" << endl;
    }
    map1[2] = "cccc";
    map1[2] = "dddd";//会覆盖cccc

    for (auto &it: map1) {
        cout << it.first << " => " << it.second << endl;
    }
}

void map_find() {
    map<int, string> map1;

    //方法1
    map1.insert(pair<int, string>(1, "aaaa"));
    map1.insert(pair<int, string>(2, "bbbb"));

    //方法2
    map1.insert(make_pair(3, "ccccc"));
    map1.insert(make_pair(4, "ddddd"));

    //方法3
    map1.insert(map<int, string>::value_type(5, "fffff"));
    map1.insert(map<int, string>::value_type(6, "gggggg"));

    //方法4
    map1[7] = "hhhhh";
    map1[8] = "iiiiii";

    //迭代
    for (auto &it: map1) {
        cout << it.first << "=>" << it.second << endl;
    }

    //查准
    auto it = map1.find(100);
    if (it == map1.end()) {
        cout << "key = 100 不存在." << it->first << " => " << it->second << endl;
    }

    auto it2 = map1.find(2);
    cout << it2->first << " => " << it2->second << endl;
}

int main() {
    basic_map();
    map_different();
    map_find();
    return 0;
}