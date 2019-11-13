//
// Created by bruce on 2019-11-12.
//
#include <iostream>
#include <string>

using namespace std;

const string TMJL = "天猫精灵";
const string NHTM = "你好天猫";

string &filterRec(string &rec) {
    size_t index = rec.find(TMJL);
    if (index >= rec.size()) {
        index = rec.find(NHTM);
    }
    if (index < rec.size()) {
        rec = rec.substr(index, rec.size() - 1);
    }
    return rec;
}

int main() {

    string rec = "这个 就 比较好 天猫精灵 我要 晚会 灯光";

    string result = filterRec(rec);
    cout << "result = " << result << endl;


    return 0;
}
