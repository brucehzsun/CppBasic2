//
// Created by bruce on 2019-11-12.
//
#include <iostream>
#include <fstream>

using namespace std;

int main() {

    sh
    ofstream fout(file_name);
    fout << "hello 1" << endl;
    fout << "hello 2" << endl;
    fout << "hello 3" << endl;
    fout << "hello 4" << endl;
    fout.close();

    ifstream fin(file_name);

    char ch;
    while (fin.get(ch)) {
        cout << ch;
    }

    cout << "finish" << endl;
    fin.close();
}