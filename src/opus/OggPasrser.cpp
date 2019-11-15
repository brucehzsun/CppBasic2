//
// Created by bruce on 2019-11-15.
//

#include "OggPasrser.h"

bool OggPasrser::feed(char *raw_ata, int len) {
    if (len < 27) {
        cout << "data too small，wait..." << endl;
        return false;
    }

    for (int i = 0; i < len; i++) {
        this->audio_queue->push(raw_ata[i]);
    }

    if (cur_page == nullptr) {
        cur_page = new OggsPage();
        char header[4];
        for (char &i : header) {
            i = audio_queue->front();
            audio_queue->pop();
            cur_page->append(i);;
        }


        if (cur_page->get_page_data().rfind("OggS", 0) != 0) {
            cout << "开头不是OggS." << endl;
            return true;
        }

        cout << "cur_page = " << cur_page->get_page_data() << endl;

        //version & header_type
        for (int i = 0; i < 2; i++) {
            cur_page->page_data += audio_queue->front();
            audio_queue->pop();
        }

        for (int i = 0; i < 8; i++) {//granule_position
            cur_page->page_data += audio_queue->front();
            audio_queue->pop();
        }
        for (int i = 0; i < 4; i++) {//serial_number
            cur_page->page_data += audio_queue->front();
            audio_queue->pop();
        }

        char page_sequence_number[4];
        for (char &i : page_sequence_number) {
            i += audio_queue->front();
            audio_queue->pop();
        }
        cur_page->page_sequence_number = (int) (*page_sequence_number);
        cout << "page_sequence_number:" << cur_page->page_sequence_number << endl;
        cur_page->page_data += page_sequence_number;
        for (int i = 0; i < 4; i++) {//CRC_checksum
            cur_page->page_data += audio_queue->front();
            audio_queue->pop();
        }

        char *number_page_segments = new char[1];
        number_page_segments[0] = audio_queue->front();
        audio_queue->pop();

        cur_page->page_segments = (int) (*number_page_segments);
        cout << "page_segments:" << cur_page->page_segments << endl;
        cur_page->page_data += number_page_segments;
    }


    if (audio_queue->front() < cur_page->page_segments) {
        cout << "wait..." << endl;
        return true;
    }
    for (int i = 0; i < cur_page->page_segments; i++) {
        char segment_value = audio_queue->front();
        audio_queue->pop();

        cur_page->page_data += segment_value;
        cur_page->segment_size_queue->push((int) segment_value);
    }

    cout << "当前page大小 = " << cur_page->page_data << endl;


//        int limit = len - position;
//        if (limit < page_segments) {
//            cout << "数据不够用了 limit:" << limit << ", page_segments = " << page_segments << endl;
//            return;
//        }
//
//        int segment_tables[page_segments];
//        //27＋255＋255*255=65307）。
//        // page_size = header_size(27+number_page_segments) +segment_table中每个segment的大小;
//        cout << "segment_table_len:";
//        for (int i = 0; i < page_segments; i++) {
//            char *segment_table = new char[1];
//            segment_table[0] = data[position++];
//            int segment_table_value = (int) (*segment_table);
//            cout << segment_table_value << ",";//19
//            segment_tables[i] = segment_table_value;
//            cur_page += segment_table_value;
//        }
//        cout << " " << endl;
//
//
//        limit = len - position;
//        if (limit < page_segments) {
//            cout << "数据不够用了 limit:" << limit << ", page_segments = " << page_segments << endl;
//            return;
//        }
//        cout << "limit:" << limit << ", page_segments = " << page_segments << endl;
//
//        cout << "segment_table_value:";
//        for (int i = 0; i < page_segments; i++) {
//            int segment_table_value = segment_tables[i];
//            if (segment_table_value < 0) {
//                segment_table_value = 255 + 1 + segment_table_value;
//            }
//            if (limit < segment_table_value) {
//                cout << "数据不够用了 limit:" << limit << ", page_segments = " << page_segments << endl;
//                return;
//            }
//
//            if (segment_table_value > 0) {
//                char *data = new char[segment_table_value];
//                for (int i = 0; i < segment_table_value; i++) {
//                    data[i] = data[position++];
//                }
//                cout << "len = " << segment_table_value << ",data = " << data[0] << data[1] << data[2]
//                     << data[3];//19
//                cur_page += data;
//            }
//        }
//        cout << " " << endl;
}