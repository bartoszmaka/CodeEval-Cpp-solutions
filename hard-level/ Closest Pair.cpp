#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
/*
    I know its not the fastest way to solve this problem
    but its good to practice object oriented programming
*/

using namespace std;

float power(float x,int y);

class Point
{
private:
    int x;
    int y;

public:
    Point(int xx = 0, int yy = 0)
    {
        x=xx;
        y=yy;
    }
    void show()
    {
        cout<<"("<<x<<", "<<y<<")"<<endl;   //(x, y)
    }
    void putstuff(int xx = 0, int yy = 0)   //It actually does same thing as constructor
    {
        x=xx;
        y=yy;
    }
    float distancefrom(int x1,int y1)
    {

        return sqrt(power((x1-x), 2)+power((y1-y), 2)); //  /(x2-x1)^2 +(y2-y1)^2
    }

    //Simple encapsulation
    int tellx()
    {
        return x;
    }
    int telly()
    {
        return y;
    }

};
//MAIN **************************************************************************************
int main(int argc, char* argv[])
{
    fstream file(argv[1], ios::in);
    //fstream file("closest pair.txt", ios::in);
    string buffer = "";

    while(!file.eof())
    {

        int n;                  //read number of points to read
        file>>n;
        if (n==0)               //if there's 0 points to read
        {
            return 0;           //then end the program
        }
        Point* wsk = new Point[n];      //create n objects

        for (int i=0; i<n; i++)         //gathering point coordinates
        {
            int x;
            file>>x;
            int y;
            file>>y;
            wsk[i].putstuff(x,y);       //put coordinates into object
            //wsk[i].show();                //debugging
        }
        float lowest=10001;
        for (int i=0; i<n; i++)
        {
            for (int j=i+1; j<n; j++)
            {
                float tmp=wsk[i].distancefrom(wsk[j].tellx(), wsk[j].telly());
                //cout<<i<<":"<<j<<"\t";    //debugging
                //cout<<tmp<<endl;          //debugging
                if (tmp<lowest)
                    lowest=tmp;
            }
        }// End of calculating distances and seeking lowest value
        delete[] wsk;
        if (lowest<=10000)
        {
            cout.setf(ios::fixed);
            cout.precision(4);
            cout<<lowest<<endl;
        }
        else
            cout<<"INFINITY"<<endl;
    }
    return 0;
}
// END OF MAIN ******************************************************************************
float power(float x,int y)
{
    if (y==0)
        return 1;
    else if (y==1)
        return x;
    else
        return x*power(x, y-1);
}
