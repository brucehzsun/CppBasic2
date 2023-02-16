//
// Created by bruce on 2019-11-09.
//
#include <iostream>

using namespace std;

int divide(int x, int y) {
    if (y == 0) {
        //抛出异常，基本数据类型；如果此处不throw异常，程序会core dump。上层无法catch
        throw y;
    }
    if (y == 10) {
        throw std::exception();
    }
    return x / y;
}

int main() {

    try {
        int ret = divide(4, 0);
//        int ret2 = divide(4, 10);
        cout << "ret = " << ret << endl;
    } catch (int e) {
        //接受异常，基本数据类型；
        cout << "出现异常 e = " << e << endl;
    } catch (std::string &e) {
        //接受异常，基本数据类型；
        cout << "出现异常string e = " << e << endl;
    } catch (exception &e) {
        //接受异常，基本数据类型；
        cout << "出现异常exception e = " << e.what() << endl;
    } catch (...) {
        //异常如果不被throw，程序是无法catch异常的，会导致coredump
        cout << "未知异常 " << endl;
    }
}
