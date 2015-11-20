#include <iostream>
#include <fstream>

using namespace std;

int main(int argc,char*argv[])
{
    fstream file(argv[1],ios::in);
    string buffer;

    while(!file.eof())
    {
        getline(file,buffer);
        if (buffer[0]>=97 && buffer[0]<=122)
        {
            buffer[0]-=32;
        }
        for(int i=0; i<buffer.length(); i++)
        {
            if(buffer[i]==' ')
            {
                if (buffer[i+1]>=97 && buffer[i+1]<=122)
                {
                    buffer[i+1]-=32;
                }
            }
        }
        cout<<buffer<<endl;
    }


    file.close();
    return 0;
}
