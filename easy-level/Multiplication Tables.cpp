#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    for (int i=1;i<=12;i++)
    {
        for(int j=1;j<=12;j++)
        {
            int output=i*j;
            stringstream ss;
            ss << output;
            string number=ss.str();
            for (int k=4;k>number.length();k--)
            {
                cout<<" ";
            }
            cout<<output;
        }
        cout<<endl;
    }
    return 0;
}
