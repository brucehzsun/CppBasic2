//
// Created by bruce sun on 2023/2/11.
//
#include "iostream"
#include "queue"

using namespace std;

void default_max_queue() {
    //默认是最大值优先级队列
    priority_queue<int> q1;
    //最小值优先级队列
    priority_queue<int, vector<int>, greater<>> q2;

    q1.push(33);
    q1.push(11);
    q1.push(22);
    q1.push(55);

    while (!q1.empty()) {
        cout << q1.top() << " ";
        q1.pop();
    }
    cout << endl;
}

void default_min_queue() {
    //最小值优先级队列
    priority_queue<int, vector<int>, greater<>> q2;

    q2.push(33);
    q2.push(11);
    q2.push(22);
    q2.push(55);

    while (!q2.empty()) {
        cout << q2.top() << " ";
        q2.pop();
    }
    cout << endl;
}

int main() {
    default_max_queue();
    default_min_queue();
}