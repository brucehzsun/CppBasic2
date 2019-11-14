//
// Created by bruce on 2019-11-13.
//
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

int segmentTableSize = 0;

string cur_page;


void parseOggPage(char *data, int len) {

    if (len < 27) {
        cout << "data too small，wait..." << endl;
        return;
    }

    int page_segments = 0;
    if (cur_page.empty()) {
        int position = 0;
        for (int i = 0; i < 4; i++) {
            cur_page += data[position++];
        }

        if (cur_page.rfind("OggS", 0) != 0) {
            cout << "开头不是OggS." << endl;
            return;
        }
        cout << "cur_page = " << cur_page << endl;

        //version
        cur_page += data[position++];
        cout << "version:" << cur_page << endl;

        char *header_type = new char[1];
        header_type[0] = data[position++];
        cout << "header_type:" << (short) (*header_type) << endl;
        cur_page += header_type;

        char *granule_position = new char[8];
        for (int i = 0; i < 8; i++) {
            granule_position[0] = data[position++];
        }
        cur_page += granule_position;

        char *bitstream_serial_number = new char[4];
        for (int i = 0; i < 4; i++) {
            bitstream_serial_number[0] = data[position++];
        }
        cout << "serial_number:" << (int) (*bitstream_serial_number) << endl;
        cur_page += bitstream_serial_number;

        char *page_sequence_number = new char[4];
        for (int i = 0; i < 4; i++) {
            page_sequence_number[0] = data[position++];
        }
        cout << "page_sequence_number:" << (int) (*page_sequence_number) << endl;
        cur_page += page_sequence_number;

        char *CRC_checksum = new char[4];
        for (int i = 0; i < 4; i++) {
            CRC_checksum[0] = data[position++];
        }
        cout << "CRC_checksum:" << (int) (*CRC_checksum) << endl;
        cur_page += CRC_checksum;

        char *number_page_segments = new char[1];
        number_page_segments[0] = data[position++];
        page_segments = (int) (*number_page_segments);
        cout << "page_segments:" << page_segments << endl;
        cur_page += number_page_segments;
    }



//    int segment_tables[page_segments];
//    if (!audio_stream.eof()) {
//        //27＋255＋255*255=65307）。
//        // page_size = header_size(27+number_page_segments) +segment_table中每个segment的大小;
//        cout << "segment_table_len:";
//        for (int i = 0; i < page_segments; i++) {
//            char *segment_table = new char[1];
//            audio_stream.read(segment_table, 1);
//            int segment_table_value = (int) (*segment_table);
//
//            cout << segment_table_value << ",";//19
//            segment_tables[i] = segment_table_value;
//        }
//        cout << " " << endl;
//    }
//
//    if (!audio_stream.eof()) {
//        cout << "segment_table_value:";
//        for (int i = 0; i < page_segments; i++) {
//            int segment_table_value = segment_tables[i];
//            if (segment_table_value < 0) {
//                segment_table_value = 255 + 1 + segment_table_value;
//            }
//            if (segment_table_value > 0) {
//                char *data = new char[segment_table_value];
//                audio_stream.read(data, segment_table_value);
//                cout << "len = " << segment_table_value << ",data = " << data[0] << data[1] << data[2]
//                     << data[3];//19
//            }
//        }
//        cout << " " << endl;
//    }

}

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


    while (!fin.eof()) {
        fin.read(buf, buf_size);
        for (int i = 0; i < buf_size; i++) {
            audio_queue.push(buf[i]);
        }
        parseOggPage(buf, buf_size);
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
