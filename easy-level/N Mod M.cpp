#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    fstream file(argv[1],ios::in);
    string buffer;
    while(!file.eof())
    {
        getline(file,buffer);
        if (buffer!=""){
            unsigned short int pos=buffer.find(',');
            unsigned short int number = atoi(buffer.substr(0,pos).c_str());
            buffer.erase(0,pos+1);
            unsigned short int m = atoi(buffer.c_str());

            while (number>=m)
            {
                number-=m;
            }
            cout<<number<<endl;
        }
    }
    return 0;
}
