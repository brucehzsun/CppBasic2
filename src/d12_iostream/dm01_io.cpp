//
// Created by bruce on 2019-11-12.
//
#include <iostream>
#include <fstream>

using namespace std;

int main() {

    string fname = "data/hello.txt";

    //写文件
    ofstream fout(fname, ios::app);
    fout << "hello 1" << endl;
    fout << "hello 2" << endl;
    fout << "hello 3" << endl;
    fout << "hello 4" << endl;
    fout.close();

    //读文件
    ifstream fin(fname);
    char buf;
    while (fin.get(buf)) {
        cout << buf;
    }

    cout << "finish" << endl;
    fin.close();
}