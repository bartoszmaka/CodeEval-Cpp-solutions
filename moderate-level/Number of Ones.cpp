#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void tobinary(int number);

int main(int argc, char *argv[])
{

    fstream file(argv[1],ios::in);
    string buffer;
//    cout<<"dec: \t bits: \t bin: \t ones:"<<endl;

    while (!file.eof())
    {
        getline(file,buffer);
        tobinary(atoi(buffer.c_str()));
    }

    return 0;
}
void tobinary(int number)
{
//        cout<<"dec :"<<number<<"\t"<<endl;
        int n=0;
        int ones=0;
        for(long long int i=1; i<=number; i*=2)
        {
            n++;
        }
//        cout<<"bits : "<<n<<"\t"<<endl;
        bool bits[n];
        for (int i=0;i<n;i++)
        {
            if(number%2==0)
            {
 //               cout<<"\t"<<number<<" | "<<0<<endl;
                number=number/2;
                bits[i]=0;
            }else{
//                cout<<"\t"<<number<<" | "<<1<<endl;
                number=(number-1)/2;
                bits[i]=1;
                ones++;
            }
        }
/*
        cout<<"bin : ";
        for(int i=n-1;i>=0;i--)
        {
            cout<<bits[i];
        }
*/
        cout<<ones<<endl;
}
