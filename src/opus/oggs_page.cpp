//
// Created by bruce on 2019-11-15.
//
#include "oggs_page.h"

OggsPage::OggsPage() {
    capacity = 0;
}

bool OggsPage::append(char data) {
    if (limit_ <= 3) {
        head_ += data;
    }
    page_data += data;
    limit_++;

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

long OggsPage::getSequenceNumber() {
    return this->page_sequence_number;
}

string OggsPage::header() {
    return this->head_;
}