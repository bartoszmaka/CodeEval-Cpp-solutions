#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int pow(int x, int y);


int main(int argc,char*argv[]){
    fstream file(argv[1],ios::in);
    string buffer;

    while(!file.eof()){
        getline(file,buffer);
        if(buffer != ""){
            int value = 0;
            for (int i = 0 ; i < buffer.length() ; i++){
                value += pow(buffer[i]-'0',buffer.length());
            }

            if(value == atoi(buffer.c_str())){
                cout<<"True"<<endl;
            }
            else{
                cout<<"False"<<endl;
            }
        }
    }
    file.close();
    return 0;
}

int pow(int x, int y){
    if(y == 1){
        return x;
    }
    else{
        return x*(pow(x,y-1));
    }
}
