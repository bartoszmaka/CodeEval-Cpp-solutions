#include <iostream>
#include <fstream>

using namespace std;

int main(int argc,char*argv[]){
    fstream file;
    string word;
    string mask;
    file.open(argv[1],ios::in);

    while(!file.eof()){
        file>>word;
        file>>mask;
        for(int i = 0 ; i < word.length() ; i++){
            if (mask[i] == '1'){
                cout<<(char)toupper(word[i]);
            }
            else{
                cout<<word[i];
            }
        }
        cout<<endl;
    }
    file.close();
    return 0;
}
