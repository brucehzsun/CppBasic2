//
// Created by bruce sun on 2023/2/11.
//
#include "iostream"
#include "set"

using namespace std;

int main() {
    multiset<int> set1;
    set1.insert(100);
    set1.insert(200);
    set1.insert(300);
    set1.insert(200);
    set1.insert(300);

    for (int i: set1) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}