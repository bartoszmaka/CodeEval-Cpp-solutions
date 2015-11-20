#include <iostream>
#include <fstream>

using namespace std;

int go(char sign);

int main(int argc,char*argv[]){
    fstream file(argv[1],ios::in);
    string buffer;
    bool shots[27];

    while(!file.eof()){
        getline(file,buffer);
        if(buffer != ""){
            //fill array
            for(bool *i = shots ; i < shots+26 ; i++){
                *i=true;
            }

            //filter the letters
            for(int i = 0 ; i < buffer.size() ; i++){
                shots[go(buffer[i])]=false;
            }

            // Output unused letters
            bool out = 0;
            for (int i = 0 ; i < 26 ; i++){
                if(shots[i]==true){
                    char output = i+97;
                    cout<<output;
                    out = 1;
                }
            }
            if(out == 0){
                cout<<"NULL";
            }
            cout<<endl;
        }
    }
    return 0;
}
int go (char sign)
{
    if((sign >= 65) && (sign <= 90)){
        return sign-65;
    }
    else if((sign >= 97) && (sign <= 122)){
        return sign-97;
    }
    else{
        return 'C';
    }
}
