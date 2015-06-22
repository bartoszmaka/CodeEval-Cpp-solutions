#include <iostream>
#include <fstream>

using namespace std;

int main(int argc,char *argv[])
{
    fstream file (argv[1],ios::in);
    string buffer;
    
    while(!file.eof())
    {
        getline(file,buffer);
        if (atoi(buffer.c_str())>=0 && atoi(buffer.c_str())<=2)
        {
            cout<<"Still in Mama's arms"<<endl;
        }
        else if (atoi(buffer.c_str())>=3 && atoi(buffer.c_str())<=4)
        {
            cout<<"Preschool Maniac"<<endl;
        }
        else if (atoi(buffer.c_str())>=5 && atoi(buffer.c_str())<=11)
        {
            cout<<"Elementary school"<<endl;
        }
        else if (atoi(buffer.c_str())>=12 && atoi(buffer.c_str())<=14)
        {
            cout<<"Middle school"<<endl;
        }
        else if (atoi(buffer.c_str())>=15 && atoi(buffer.c_str())<=18)
        {
            cout<<"High school"<<endl;
        }
        else if (atoi(buffer.c_str())>=19 && atoi(buffer.c_str())<=22)
        {
            cout<<"College"<<endl;
        }
        else if (atoi(buffer.c_str())>=23 && atoi(buffer.c_str())<=65)
        {
            cout<<"Working for the man"<<endl;
        }
        else if (atoi(buffer.c_str())>=66 && atoi(buffer.c_str())<=100)
        {
            cout<<"The Golden Years"<<endl;
        }
        else {cout<<"This program is for humans"<<endl;}

    }
    file.close();
    return 0;
}
