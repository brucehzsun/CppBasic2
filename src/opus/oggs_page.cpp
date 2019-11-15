//
// Created by bruce on 2019-11-15.
//
#include "oggs_page.h"

OggsPage::OggsPage() {
    this->capacity_ = 0;
}

bool OggsPage::append(char data) {
    if (limit_ <= 3) {
        head_ += data;
    }
    data_buf_ += data;
    limit_++;

    if (data_buf_.size() > 27 * 2) {
        if (!isParseHead) {
            isParseHead = true;
            if (data_buf_.rfind("OggS", 0) == 0) {
                cout << "开头是OggS，合法格式" << endl;
                this->valid = true;
            } else {
                this->valid = false;
                cout << "开头是OggS，非法格式" << endl;
            }

            string numb_str = data_buf_.substr(4 + 6 + 8 + 4, 4);
//        page_sequence_number = stoi(numb_str, 0, 2);
            cout << "numb_str:" << numb_str << endl;
            cout << "page_sequence_number:" << page_sequence_number << endl;
        }
    }

//    cur_page->page_data += page_sequence_number;
//    for (int i = 0; i < 4; i++) {//CRC_checksum
//        cur_page->page_data += audio_queue->front();
//        audio_queue->pop();
//    }
//
//    char *number_page_segments = new char[1];
//    number_page_segments[0] = audio_queue->front();
//    audio_queue->pop();
//
//    cur_page->page_segments = (int) (*number_page_segments);
//    cout << "page_segments:" << cur_page->page_segments << endl;
//    cur_page->page_data += number_page_segments;
    return true;

}

string &OggsPage::getDataBuf() {
    return this->data_buf_;
}

int &OggsPage::capacity() {
    return this->capacity_;
}

int &OggsPage::limit() {
    return this->limit_;
}

int &OggsPage::getSequenceNumber() {
    return this->page_sequence_number;
}

string &OggsPage::header() {
    return this->head_;
}