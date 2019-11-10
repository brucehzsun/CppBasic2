//
// Created by bruce on 2019-11-10.
//
#include <iostream>

using namespace std;

class CopyException {
public:
    CopyException() {
    }


    CopyException(int code, string msg) {
        this->code = code;
        this->msg = msg;
        cout << "构造函数" << endl;
    }


    ~CopyException() {
        cout << "析构函数" << endl;
    }

    int getCode() {
        return this->code;
    }

    string getMsg() {
        return this->msg;
    }

    CopyException(const CopyException &c) {
        this->code = c.code;
        this->msg = c.msg;
        cout << "copy构造函数" << endl;
    }

private:
    int code;
    string msg;
};


void copy_switch(char *in, char *out) {

    if (in == nullptr) {
        throw CopyException(1, "in is null");
    }

    if (out == nullptr) {
//        throw new CopyException(2, "out is null");//抛出指针类型；
        throw CopyException(2, "out is null");//抛出引用类型
    }
}

int main() {

    try {
        char in[] = "abcdefg";
        char *out = nullptr;
        copy_switch(in, out);
    } catch (CopyException &e) {
        //e:就是copy构造函数。&e就少了一个copy的动作
        cout << "code &= " << e.getCode() << ",msg = " << e.getMsg() << endl;
    } catch (CopyException *e) {
        cout << "code *= " << e->getCode() << ",msg = " << e->getMsg() << endl;
    } catch (...) {
        cout << "unknown exception" << endl;
    }


}
