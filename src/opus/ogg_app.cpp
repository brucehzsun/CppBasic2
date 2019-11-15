//
// Created by bruce on 2019-11-15.
//


#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int segmentTableSize = 0;


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
