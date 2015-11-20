#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    fstream file;
    int n;
    int fizz;
    int buzz;
    file.open(argv[1],ios::in);
    while(file.eof()==false)
    {
        file>>fizz;
        file>>buzz;
        file>>n;
        for(int i=1; i<=n; i++)
        {
            if((i%fizz==0)&&(i%buzz==0))
            {
                cout<<"FB";
            }
            else if(i%fizz==0)
            {
                cout<<"F";
            }
            else if(i%buzz==0)
            {
                cout<<"B";
            }
            else
            {
                cout<<i;
            }
            cout<<" ";
        }
        cout<<endl;
    }


    return 0;
}
