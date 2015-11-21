#include <iostream>
#include <sstream>
#include <cstdlib>
#include <fstream>

using namespace std;

void is_happy(int number);


int main(int argc, char *argv[]){

    fstream file;
    file.open(argv[1],ios::in);
    string line;

    while (file.eof() == false){
        file>>line;
        is_happy(atoi(line.c_str()));
        cout<<endl;
    }

    file.close();
    return 0;
}

void is_happy(int number){
    stringstream ss;        //
    ss<<number;             //  int to string
    string text = ss.str();   //
    number = 0;
    for(int i = 0 ; i < text.length() ; i++){
        int x = (text[i]-'0')*(text[i]-'0');
        number += x;
    }
    if(number == 1){
        cout<<1;
    }
    else if(number == 4){
        // Happy numbers are not equal to 4 in any stage
        cout<<0;
    }
    else{
        is_happy(number);
    }
}
