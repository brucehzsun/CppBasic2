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
    }

    while (!audio_queue->empty()) {
        ret = cur_page->append(audio_queue->front());
        if (ret) {
            audio_queue->pop();
        } else {
            this->oggs_queue->push(cur_page);
            cur_page = new OggsPage();
        }
    }

    return true;
}

bool OggPasrser::end() {
    cout << "end; queue size = " << this->oggs_queue->size() << endl;
}