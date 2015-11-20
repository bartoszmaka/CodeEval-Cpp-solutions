#include <iostream>
#include <fstream>

using namespace std;

int main(int argc,char*argv[])
{
    fstream file(argv[1],ios::in|ios::binary);

    file.seekg(0,ios::end);
    cout<<file.tellg()<<endl;

    file.close();
    return 0;
}
