#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int tonumber(string word);
int main(int argc,char *argv[])
{
    fstream file;
    file.open(argv[1],ios::in);
    string buffer;

    while(!file.eof())
    {
        getline(file,buffer);
//        cout<<" line : "<<buffer;

        int n=count(buffer.begin(),buffer.end(),';')+1;
//        cout<<" numbers : "<<n<<endl;
        string words[n];

        for(int i=0;i<n;i++)
        {
            size_t pos=buffer.find(';');
            string word=buffer.substr(0,pos);
            buffer.erase(0,pos+1);
            cout<<tonumber(word);
        }
        cout<<endl;
    }

    file.close();
    return 0;
}
int tonumber(string word) //I know it's quite ugly solution
{
    if (word=="zero")
    {
        return 0;
    }
    else if (word=="one")
    {
        return 1;
    }
    else if (word=="two")
    {
        return 2;
    }
    else if (word=="three")
    {
        return 3;
    }
    else if (word=="four")
    {
        return 4;
    }
    else if (word=="five")
    {
        return 5;
    }
    else if (word=="six")
    {
        return 6;
    }
    else if (word=="seven")
    {
        return 7;
    }
    else if (word=="eight")
    {
        return 8;
    }
    else if (word=="nine")
    {
        return 9;
    }
    else
    {
        cout<<" unknown digit "<<endl;
    }

}
