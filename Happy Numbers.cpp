#include <iostream>
#include <sstream>
#include <cstdlib>
#include <fstream>

using namespace std;

void is_happy(int number);

int main(int argc, char *argv[])
{

    fstream file;
    file.open(argv[1],ios::in);
    string line;
    while (file.eof()==false)
    {
        file>>line;
        //cout<<line<<" "<<atoi(line.c_str());
        is_happy(atoi(line.c_str()));
        cout<<endl;

    }
    file.close();

    return 0;
}
void is_happy(int number)
{
    stringstream ss;        //
    ss<<number;             //  int to string
    string text=ss.str();   //
    number=0;
    for (int i=0; i<text.length(); i++)                         //
    {
                                                                //  squares every digit
        /*cout<<"x = "<<(text[i]-'0')<<"*"<<(text[i]-'0')<<" = "<<(text[i]-'0')*(text[i]-'0')<<endl;*/
        int x=(text[i]-'0')*(text[i]-'0');                      //  of number
        number+=x;                                              //
    }                                                           //
    /*cout<<number<<endl;*/


    if (number==1)
    {
        cout<<1;
    }                       //
    else if (number==4)     // If is_happy is never going to be equal 1
    {
        // Happy numbers are not equal to 4 in any stage
        cout<<0;
    }
    else
    {
        is_happy(number);
    }

}
