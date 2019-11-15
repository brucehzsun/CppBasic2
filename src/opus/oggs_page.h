//
// Created by bruce on 2019-11-15.
//

#ifndef CPPBASIC2_OGGSPAGE_H
#define CPPBASIC2_OGGSPAGE_H


class OggsPage {
public:
    OggsPage();

    bool append(char data);

    string &getDataBuf();

    int capacity();

    int limit();

    float getSequenceNumber();

    string header();

private:
    string data_buf_;//字符缓存
    int capacity_;//总大小
    int limit_;//当前数据的大小
    string head_;
    int page_sequence_number;
    int page_segments;
};

#endif //CPPBASIC2_OGGSPAGE_H
