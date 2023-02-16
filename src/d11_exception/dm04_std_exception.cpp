//
// Created by bruce on 2019-11-12.
//
#include <iostream>
#include <string>
#include <exception>

using namespace std;

class MyException : public exception {
public:
    MyException(char *what) {
        this->_what = what;
    }

    const char *what() {
        return this->_what;
    }

private:
    char *_what;
};

int main() {
    int age = 50;
    try {
        if (age >= 80) {
            throw out_of_range("年龄太大");
        } else {
            throw MyException("未知异常xxx");
        }
    } catch (out_of_range &e) {
        cout << "out_of_range = " << e.what() << endl;
    } catch (MyException &e) {
        cout << "MyException = " << e.what() << endl;
    } catch (...) {
        cout << "未知异常" << endl;
    }


    return 0;
}
