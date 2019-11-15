//
// Created by bruce on 2019-11-15.
//

#include "ogg_pasrser.h"

bool OggPasrser::feed(char *raw_ata, int len) {
    cout << "feed len = " << len << endl;
    if (len < 27) {
        cout << "data too small，wait..." << endl;
        return false;
    }

    for (int i = 0; i < len; i++) {
        this->audio_queue->push(raw_ata[i]);
    }

    bool ret;
    if (cur_page == nullptr) {
        cur_page = new OggsPage();
        while (!audio_queue->empty()) {
            ret = cur_page->append(audio_queue->front());
            if (ret) {
                audio_queue->pop();
            } else {
                cout << "OggsPage 满了;limit = " << cur_page->limit() << endl;
                return false;
            }
        }
    }

    return true;
}