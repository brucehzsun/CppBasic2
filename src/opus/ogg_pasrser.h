//
// Created by bruce on 2019-11-15.
//

#ifndef CPPBASIC2_OGGPASRSER_H
#define CPPBASIC2_OGGPASRSER_H

#include <iostream>
#include <string>
#include <queue>
#include "oggs_page.h"

using namespace std;


class OggPasrser {
public:
    bool feed(char *data, int len);

    bool end();

private:
    queue<OggsPage *> *oggs_queue = new queue<OggsPage *>();
    queue<char> *audio_queue = new queue<char>();
    OggsPage *cur_page = nullptr;
};


#endif //CPPBASIC2_OGGPASRSER_H
