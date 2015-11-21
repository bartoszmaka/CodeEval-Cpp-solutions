#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int fib(int n);


int main(int argc, char *argv[]){
    fstream file;
    string buffer;
    file.open(argv[1],ios::in);
    if (file.good() == true){
        while(file.eof() == false){
            getline(file,buffer);
            cout<<fib(atoi(buffer.c_str()))<<endl;
        }
    }
    file.close();
    return 0;
}

int fib(int n)
{
    int tab[n];
    tab[0] = 1;
    tab[1] = 1;
    for(int i = 2 ; i < n ; i++){
        tab[i] = tab[i-1]+tab[i-2];
    }
    return tab[n-1];
}
