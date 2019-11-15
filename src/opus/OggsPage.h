//
// Created by bruce on 2019-11-15.
//

#ifndef CPPBASIC2_OGGSPAGE_H
#define CPPBASIC2_OGGSPAGE_H


class OggsPage {
public:
    OggsPage() {
        capacity = 0;
    }

public:
    string head;
    int page_sequence_number;
    int page_segments;

    bool append(char data) {
        page_data += data;
        capacity++;
    }

    string &get_page_data() {
        return this->page_data;
    }

private:
    string page_data;
    int capacity;
};

#endif //CPPBASIC2_OGGSPAGE_H
