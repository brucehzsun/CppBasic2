//
// Created by bruce on 2019-11-12.
//
#include <iostream>
#include <fstream>

using namespace std;

class Teacher {
public:

    Teacher() {

    }

    Teacher(int age, char *name) {
        this->age = age;
        strcpy(this->name, name);
    }

    void print() {
        cout << "age = " << this->age << ", name = " << this->name << endl;
    }

private:
    int age;
    char name[32];
};

int main() {

    Teacher t1(20, "tom");
    Teacher t2(25, "jerry");

    string file_name = "test.dat";
    ofstream fout(file_name, ios::out | ios::binary);
    fout.write((const char *) &t1, sizeof(t1));
    fout.write((const char *) &t2, sizeof(t2));
    fout.close();


    ifstream fin(file_name, ios::in | ios::binary);
    Teacher tmp;
    fin.read((char *) &tmp, sizeof(t1));
    tmp.print();
    fin.read((char *) &tmp, sizeof(t2));
    tmp.print();


}
