#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main(int argc,char*argv[])
{
    fstream file (argv[1], ios::in);
    string buffer="";
    while(!file.eof())
    {
        getline(file,buffer);
        int n = count(buffer.begin(),buffer.end(),';');
        int *numbers;
        numbers = new int [n+1];

        for(int i = 0; i<=n-1; i++)
        {
            int pos=buffer.find(',');
            buffer.erase(0,pos+1);
            pos=buffer.find(';');
            numbers[i]=atoi(buffer.substr(0,pos).c_str());
        }
        numbers[n]=0;
        sort(numbers,numbers+(n+1));

        for (int i=1;i<n;i++)
        {
            cout<<numbers[i]-numbers[i-1]<<",";
        }
        cout<<numbers[n]-numbers[n-1]<<endl;
        delete[] numbers;
    }
    file.close();

    return 0;
}
