#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
    fstream file;
    file.open(argv[1],ios::in);
    string buffer;
    while (file.eof() == false) {
        file>>buffer;
        int number = atoi(buffer.c_str());
        if (number%2 == 0) {
            cout<<1<<endl;
        }
        else {
            cout<<0<<endl;
        }
    }
    return 0;
}
