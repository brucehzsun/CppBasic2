//
// Created by bruce on 2019-12-15.
//
#include <iostream>
#include <string>
#include <map>

using namespace std;

void test1() {
    map<int, string> map1;
    pair<map<int, string>::iterator, bool> ret;
    ret = map1.insert(pair<int, string>(1, "value1"));
    if (ret.second) {
        cout << "插入成功:" << ret.first->first << "\t" << ret.first->second << endl;
    } else {
        cout << "插入失败:" << ret.first->first << "\t" << ret.first->second << endl;
    }

    ret = map1.insert(pair<int, string>(1, "value11"));
    if (ret.second) {
        cout << "插入成功:" << ret.first->first << "\t" << ret.first->second << endl;
    } else {
        cout << "插入失败:" << ret.first->first << "\t" << ret.first->second << endl;
    }
    map1.insert(map<int, string>::value_type(2, "value2"));
    map1.insert(make_pair(3, "value3"));
    map1[4] = "value4";
    map1[4] = "value44";

    for (auto it = map1.begin(); it != map1.end(); it++) {
        cout << it->first << "\t" << it->second << endl;
    }

    cout << "查找" << endl;
    map<int, string>::iterator map_ret = map1.find(3);
    if (map_ret != map1.end()) {
        cout << "查找成功：" << map_ret->first << "=>" << map_ret->second << endl;
    }

    map_ret = map1.find(300);
    if (map_ret == map1.end()) {
        cout << "查找失败：" << map_ret->first << "\t" << map_ret->second << endl;
    }

    while (!map1.empty()) {
        auto it = map1.begin();
        cout << it->first << "\t" << it->second << endl;
        map1.erase(it);
    }
}

int main() {
    test1();
}
