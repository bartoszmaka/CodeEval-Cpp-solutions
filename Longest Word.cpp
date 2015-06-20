#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main(int argc,char *argv[])
{
    fstream file (argv[1],ios::in);

    while(!file.eof())
    {
        string buffer;
        string word;
        getline (file,buffer);
        buffer.insert(buffer.end(),' ');//Now every word ends with ' '
        int n=count(buffer.begin(),buffer.end(),' ');
//        cout<<buffer<<endl;
//        cout<<"words in line : "<<n<<endl;

        for (int i=0; i<n; i++)
        {
            size_t pos = buffer.find(' ');
//            cout<<"' ' found at position : "<<pos<<endl;
            if(pos>word.length())
            {
                word=buffer.substr(0,pos);
            }
            buffer.erase(0,pos+1);
//            cout<<buffer<<endl;
        }

        cout<<word<<endl;

    }

    file.close();
    return 0;
}
