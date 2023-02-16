//
// Created by bruce sun on 2023/2/11.
//
#include "iostream"
#include "list"

using namespace std;


int main() {
    list<int> l;
    for (int i = 0; i < 10; i++) {
        l.push_back(i);
    }

    auto delete_it = l.begin();
    delete_it++;
    delete_it++;
    delete_it++;

    l.erase(delete_it);

    for (auto it = l.begin(); it != l.end(); it++) {
        cout << *it << " ";
    }

    return 0;
}