#include <iostream>
#include <fstream>

using namespace std;

int main(int argc,char *argv[]){
    fstream file;
    file.open(argv[1],ios::in);
    string buffer;
    while(!file.eof()){
        int sum = 0;
        getline(file,buffer);
        for(int i = 0 ; i < buffer.length() ; i++){
            sum += buffer[i]-'0';
        }
        cout<<sum<<endl;
    }
    file.close();
    return 0;
}
