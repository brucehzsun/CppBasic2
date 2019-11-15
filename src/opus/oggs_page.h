//
// Created by bruce on 2019-11-15.
//

#ifndef CPPBASIC2_OGGSPAGE_H
#define CPPBASIC2_OGGSPAGE_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class OggsPage {
public:
    OggsPage();

    bool append(char data);

    string &getDataBuf();

    int &capacity();

    int &limit();

    int &getNumberPageSegments();

private:
    string data_buf_;//字符缓存
    int capacity_;//总大小
    int limit_;//当前数据的大小
    int number_page_segments;
    int page_segments;
    bool valid;
    bool isParseHead;
    stringstream str_stream;
};

#endif //CPPBASIC2_OGGSPAGE_H
