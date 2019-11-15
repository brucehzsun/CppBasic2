//
// Created by bruce on 2019-11-15.
//
#include "oggs_page.h"

OggsPage::OggsPage() {
    this->capacity_ = 0;
    this->isParseHead = false;
    this->limit_ = 0;
}

bool OggsPage::append(char data) {
    if (capacity_ > 0 && limit_ >= capacity_) {
        cout << "append full; capacity_ = " << this->capacity_ << ", limit = " << limit_ << endl;
        return false;
    }

    str_stream << data;
    data_buf_ += data;
    limit_++;

    if (data_buf_.size() < 27) {
        return true;
    }

    if (!isParseHead) {
        isParseHead = true;
        char *capture_pattern = new char[4];
        str_stream.read(capture_pattern, 4);
        cout << "capture_pattern = " << capture_pattern << ">>>>>>>>>>>>>>>" << endl;

        //version &
        char version[1];
        str_stream.read(version, 1);
//        cout << "version = " << (int) (*version) << endl;

        //header_type
        char header_type[1];
        str_stream.read(header_type, 1);
        cout << "header_type = " << (int) (*header_type) << endl;

        char granule_position[8];
        str_stream.read(granule_position, 8);


        char bitstream_serial_number[4];
        str_stream.read(bitstream_serial_number, 4);
//        cout << "serial_number = " << (int) (*bitstream_serial_number) << endl;

        char page_sequence[4];
        str_stream.read(page_sequence, 4);
        cout << "page_sequence = " << (int) (*page_sequence) << endl;

        //CRC_checksum
        char CRC_checksum[4];
        str_stream.read(CRC_checksum, 4);

        //number_page_segments
        char number_page_segments[1];
        str_stream.read(number_page_segments, 1);
        this->number_page_segments = (int) (*number_page_segments);
        cout << "number_page_segments = " << this->number_page_segments << endl;
    }

    if (this->capacity_ == 0 && limit_ - 27 > number_page_segments) {
        //segment_table;
        this->capacity_ = 27;
        for (int i = 0; i < this->number_page_segments; i++) {
            char segment_size_str[1];
            str_stream.read(segment_size_str, 1);
            int segment_size = (int) (*segment_size_str);
            if (segment_size < 0) {
                segment_size = 255 + 1 + segment_size;
            }

            this->capacity_++;
            this->capacity_ += segment_size;
            cout << "segment_size = " << segment_size << endl;
        }
    }
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

int &OggsPage::getNumberPageSegments() {
    return this->number_page_segments;
}
