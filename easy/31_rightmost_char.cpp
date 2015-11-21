#include <iostream>
#include <fstream>

using namespace std;

int seeklastdigit(string & sentence);


int main(int argc,char *argv[]){
    fstream file(argv[1],ios::in);
    string buffer;

    while(!file.eof()){
        getline(file,buffer);
        cout<<seeklastdigit(buffer)<<endl;

    }
    file.close();
    return 0;
}

int seeklastdigit(string& sentence){
    for(int i = sentence.length()-3 ; i >= 0 ; i--){
        if (sentence[i] == sentence[sentence.length()-1]){
            return i;
        }
    }
    return -1;
}
