//
// Created by bruce on 2019-11-13.
//
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int segmentTableSize = 0;


class OggsPage {
public:
    OggsPage() {}

public:
    string head;
    int page_sequence_number;
    int page_segments;
    string page_data;
};

class OggPasrser {
public:
    void feed(char *data, int len) {

        if (len < 27) {
            cout << "data too small，wait..." << endl;
            return;
        }

        int position = 0;
        if (cur_page == nullptr) {
            char header[4];
            for (char &i : header) {
                i = data[position++];
            }
            cur_page = new OggsPage();
            cur_page->page_data += header;
            if (cur_page->page_data.rfind("OggS", 0) != 0) {
                cout << "开头不是OggS." << endl;
                return;
            }

            cout << "cur_page = " << cur_page->page_data << endl;

            cur_page->page_data += data[position++];//version
            cur_page->page_data += data[position++];//header_type
            for (int i = 0; i < 8; i++) {//granule_position
                cur_page->page_data += data[position++];
            }
            for (int i = 0; i < 4; i++) {//serial_number
                cur_page->page_data = data[position++];
            }

            char page_sequence_number[4];
            for (char &i : page_sequence_number) {
                i = data[position++];
            }
            cur_page->page_sequence_number = (int) (*page_sequence_number);
            cout << "page_sequence_number:" << cur_page->page_sequence_number << endl;
            cur_page->page_data += page_sequence_number;
            for (int i = 0; i < 4; i++) {//CRC_checksum
                cur_page->page_data = data[position++];
            }

            char *number_page_segments = new char[1];
            number_page_segments[0] = data[position++];
            cur_page->page_segments = (int) (*number_page_segments);
            cout << "page_segments:" << cur_page->page_segments << endl;
            cur_page->page_data += number_page_segments;
        }

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

private:
    queue<OggsPage> *oggs_queue = new queue<OggsPage>();
    OggsPage *cur_page = nullptr;
};


int main() {

    string file_name = "/Users/bruce/CLionProjects/CppBasic2/data/0347248_6D25F77B_12CA.opus";
    ifstream fin(file_name, ios::in | ios::binary);
    queue<char> audio_queue;

    int buf_size = 32;
    char buf[buf_size];
    if (!fin.is_open()) {
        cout << "file is not open" << endl;
        return 0;
    }


    OggPasrser oggPasrser;
    while (!fin.eof()) {
        fin.read(buf, buf_size);
        for (int i = 0; i < buf_size; i++) {
            audio_queue.push(buf[i]);
        }
        oggPasrser.feed(buf, buf_size);
        break;
    }
//    }

//    string s;
//    s.append("aaaaa");
//    s.append("bbbb");
//    s.append("bbbbfffffffffffffffffffffff");
//    cout << s << endl;
//    cout << s.capacity() << endl;

    return 0;
}
