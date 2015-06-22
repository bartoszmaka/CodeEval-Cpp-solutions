#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

float distance(int x1,int y1,int x2,int y2);

int main(int argc,char *argv[])
{
    fstream file;
    file.open(argv[1],ios::in);
    while (!file.eof())
    {
        int tab[4];//[0]=x1,[1]=y1,[2]=x2;[3]=y2
        for (int i=0; i<4; i++)
        {
            string buffer;
            file>>buffer;
            if(buffer[0]=='(')
            {
                buffer.erase(0,1);
            }
            if(buffer[buffer.length()-1]==')' ||buffer[buffer.length()-1]==',' )
            {
                buffer.erase(buffer.length()-1,1);
            }
            tab[i]=atoi(buffer.c_str());
        }

        cout<<distance(tab[0],tab[1],tab[2],tab[3])<<endl;

    }
    file.close();
    return 0;
}
float distance(int x1,int y1,int x2,int y2)
{
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}
