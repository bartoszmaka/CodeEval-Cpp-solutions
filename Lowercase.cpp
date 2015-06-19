#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    fstream file;
    string buffer;

    file.open(argv[1],ios::in);
    if (file.good()==true)
    {
        while(getline(file,buffer))
        {
            transform(buffer.begin(),buffer.end(),buffer.begin(),::tolower);
            cout<<buffer<<endl;
        }
    }
    file.close();
    return 0;
}
