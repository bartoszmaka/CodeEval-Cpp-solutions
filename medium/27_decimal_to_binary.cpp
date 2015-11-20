#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void tobinary(int number);

int main(int argc,char*argv[]){
    fstream file(argv[1],ios::in);

    while(!file.eof()){
        string buffer;
        file>>buffer;
        if (buffer != ""){
            tobinary(atoi(buffer.c_str()));
        }
    }
    file.close();

    return 0;
}

void tobinary(int number){
    if(!number){
        cout<<0<<endl;
        return;
    }

    int n = 0;
    for(long long int i = 1 ; i <= number ; i*=2){
        n++;
    }

    bool bits[n];
    for (int i = 0 ; i < n ; i++){
        if(number%2 == 0){
            number = number/2;
            bits[i] = 0;
        }else{
            number = (number-1)/2;
            bits[i] = 1;
        }
    }
    for(bool *i = bits+(n-1) ; i >= bits ; i--){
        cout<<*i;
    }
    cout<<endl;
}
