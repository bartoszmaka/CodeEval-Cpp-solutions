#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;


int main(int argc,char*argv[]){
    fstream file(argv[1],ios::in);
    string buffer;
    unsigned short int matrix[256][256];

    for(unsigned short int i = 0 ; i < 256 ; i++){
        for (unsigned short int j = 0 ; j < 256 ; j++){
            matrix[i][j] = 0;
        }
    }

    while(!file.eof()){
        getline(file,buffer);
        size_t pos = buffer.find(' ');

        if(buffer[0] == 'S'){       //Set
            if(buffer[pos-1] == 'w'){       //Row
                buffer.erase(0,pos+1);
                size_t pos = buffer.find(' ');
                unsigned short int argi = atoi(buffer.substr(0,pos).c_str());
                unsigned short int argx = atoi(buffer.substr(pos+1,buffer.length()-1).c_str());

                for(unsigned short int i = 0 ; i < 256 ; i++){
                    matrix[argi][i] = argx;
                }
            }else if (buffer[pos-1] == 'l'){//Col
                buffer.erase(0,pos+1);
                size_t pos = buffer.find(' ');
                unsigned short int argi = atoi(buffer.substr(0,pos).c_str());
                unsigned short int argx = atoi(buffer.substr(pos+1,buffer.length()-1).c_str());

                for(unsigned short int i = 0 ; i < 256 ; i++){
                    matrix[i][argi] = argx;
                }
            }
        }
        else if(buffer[0] == 'Q'){  //Query
            unsigned short int sum = 0;
            unsigned short int argi = atoi(buffer.substr(pos+1,buffer.length()-1).c_str());
            if(buffer[pos-1] == 'w'){       //Row
                for (unsigned short int i = 0 ; i < 256 ; i++){
                    sum += matrix[argi][i];
                }
                cout<<sum<<endl;
            }else if (buffer[pos-1] == 'l'){//Col
                for(int i = 0 ; i < 256 ; i++){
                    sum += matrix[i][argi];
                }
                cout<<sum<<endl;
            }
        }
    }

    file.close();
    return 0;
}
