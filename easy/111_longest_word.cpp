#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main(int argc,char *argv[]){
    fstream file (argv[1],ios::in);

    while(!file.eof()){
        string buffer;
        string word;
        getline (file,buffer);
        buffer.insert(buffer.end(),' ');            //Now every word ends with ' '
        int n = count(buffer.begin(),buffer.end(),' ');
        for (int i = 0 ; i < n ; i++){
            size_t pos = buffer.find(' ');
            if(pos>word.length()){
                word = buffer.substr(0,pos);
            }
            buffer.erase(0,pos+1);}
            cout<<word<<endl;
        }
        file.close();
        return 0;
}
