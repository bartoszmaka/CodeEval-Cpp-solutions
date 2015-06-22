#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
int value(char digit);
int main(int argc,char *argv[])
{
    fstream file(argv[1],ios::in);
    string buffer;
    while(!file.eof())
    {
        getline (file,buffer);
//        cout<<buffer<<" =";
        int output=0;
        for(int i=0;i<buffer.length();i++)
        {
//            cout<<" ( "<<buffer[i]<<" * 16^"<<buffer.length()-(i+1)<<" ) ";
            output+=value(buffer[i])*pow(16,buffer.length()-(i+1));
        }
        cout<<output<<endl;
    }


    file.close();
    return 0;
}
int value(char digit)
{
    switch(digit)
    {
    case '1' :
        return 1;
    case '2' :
        return 2;
    case '3' :
        return 3;
    case '4' :
        return 4;
    case '5' :
        return 5;
    case '6' :
        return 6;
    case '7' :
        return 7;
    case '8' :
        return 8;
    case '9' :
        return 9;
    case 'a' :
        return 10;
    case 'b' :
        return 11;
    case 'c' :
        return 12;
    case 'd' :
        return 13;
    case 'e' :
        return 14;
    case 'f' :
        return 15;
    default :
        return 0;

    }
}
