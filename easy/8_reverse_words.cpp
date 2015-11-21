#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;


int main(int argc,char *argv[]){
    fstream file;
    string buffer;
    file.open(argv[1],ios::in);

    while(!file.eof()){
        getline(file,buffer);
        int n = count(buffer.begin(),buffer.end(),' ')+1;
        string words [n];

        for(int i = 0 ; i < n ; i++){
            size_t pos = buffer.find(' ');
            words[i] = buffer.substr(0,pos);
            buffer.erase(0,pos+1);
        }

        for(int i = n-1 ; i >= 0 ; i--){
            cout<<words[i]<<" ";
        }
        cout<<endl;
    }
    file.close();
    return 0;
}
