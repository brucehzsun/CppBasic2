//
// Created by bruce on 2019-11-13.
//
#include <iostream>
#include <fstream>

using namespace std;

int segmentTableSize = 0;

void parseOggPage(ifstream &fin) {
    //0-3
    char *oggs = new char[4];
    fin.read(oggs, 4);
    cout << "\nnew page:" << oggs << endl;
    if (oggs != "Oggs") {
        cout << "error" << endl;
    }

    char *version = new char[1];
    fin.read(version, 1);
//    cout << "version:" << (int) (*version) << endl;

    char *header_type = new char[1];
    fin.read(header_type, 1);
//    cout << "header_type:" << (int) (*header_type) << endl;

    char *granule_position = new char[8];
    fin.read(granule_position, 8);
//    cout << "granule_position:" << granule_position << endl;

    char *bitstream_serial_number = new char[4];
    fin.read(bitstream_serial_number, 4);
//    cout << "serial_number:" << (int) (*bitstream_serial_number) << endl;

    char *page_sequence_number = new char[4];
    fin.read(page_sequence_number, 4);
    cout << "page_sequence_number:" << (int) (*page_sequence_number) << endl;

    char *CRC_checksum = new char[4];
    fin.read(CRC_checksum, 4);
//    cout << "CRC_checksum:" << (int) (*CRC_checksum) << endl;

    char *number_page_segments = new char[1];
    fin.read(number_page_segments, 1);
    int page_segments = (int) (*number_page_segments);
    cout << "page_segments:" << page_segments << endl;

    //27＋255＋255*255=65307）。
    // page_size = header_size(27+number_page_segments) +segment_table中每个segment的大小;
    cout << "segment_table_len:";
    int segment_tables[page_segments];
    for (int i = 0; i < page_segments; i++) {
        char *segment_table = new char[1];
        fin.read(segment_table, 1);
        int segment_table_value = (int) (*segment_table);

        cout << segment_table_value << ",";//19
        segment_tables[i] = segment_table_value;
    }
    cout << " " << endl;

    cout << "segment_table_value:";
    for (int i = 0; i < page_segments; i++) {
        int segment_table_value = segment_tables[i];
        if (segment_table_value < 0) {
            segment_table_value = 255 + 1 + segment_table_value;
        }
        if (segment_table_value > 0) {
            char *data = new char[segment_table_value];
            fin.read(data, segment_table_value);
            cout << "len = " << segment_table_value << ",data = " << data[0] << data[1] << data[2]
                 << data[3];//19
        }
    }
    cout << " " << endl;


//    int dateLen = page_segments * segmentTableSize;
//    cout << "dataLen = " << dateLen << ",currentTableSize = " << currentTableSize << endl;//19
//    char *data = new char[dateLen];
//    fin.read(data, dateLen);
//    cout << "dataLen = " << dateLen << ",data:" << data << endl;//19
}

int main() {

    string file_name = "/Users/bruce/CLionProjects/CppBasic2/data/0347248_6D25F77B_12CA.opus";
    ifstream fin(file_name, ios::in | ios::binary);
    if (!fin.is_open()) {
        cout << "file is not open" << endl;
        return 0;
    }

    while (!fin.eof()) {
        parseOggPage(fin);
    }

    return 0;
}
