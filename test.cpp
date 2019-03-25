


// TODO:

// need a pool to track which spots can add a new number

// need to change adding process, no more than two numbers can be added.


#include <iostream>
#include <memory>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <string>

#include "Board.hpp"

using namespace std;

//random int in range [a,b]
int randInt(int a, int b)
{
    return rand() % (b-1+a) + a;
}

//random int in range [0,b]
int randInt(int b)
{
    return rand() % (b+1);
}

int main()
{
    /* initialize random seed: */
    srand (time(NULL));
    int n = 6;
    Board b = Board(n);

    b.show();


    int ti = 0;
    int tj = 0;
    int v = 0;


    for(int i = 0 ; i < 3 ; i++)
    {
        ti = randInt(n-1);
        tj = randInt(n-1);
        v = randInt(1)*2+2;
        cout<<"ti = "<<ti<<", tj = "<<tj<<", v = "<<v<<endl;
        b.add(ti,tj,v);
    }
    b.show();
    string mystring = "";
    for(int i = 0 ; i < 50 ; i++)
    {
        cout<<"Please enter move:"<<endl;

        cin>>mystring;
        if(mystring.length()!=1)
        {
            cout<<"Invalid input!"<<endl;
        }
        else
        {
            cout<<"your input is: "<<mystring<<endl;
            if(mystring[0]=='a')
            {
                b.moveHL();
            }
            else if(mystring[0]=='d')
            {
                b.moveHR();
            }
            else if(mystring[0]=='w')
            {
                b.moveVU();
            }
            else if(mystring[0]=='s')
            {
                b.moveVD();
            }
            else
            {
                cout<<"Invalid input!"<<endl;
                continue;
            }
            ti = randInt(n-1);
            tj = randInt(n-1);
            v = 2; //randInt(1)*2+2;
            cout<<"try: ti = "<<ti<<", tj = "<<tj<<", v = "<<v<<endl;
            while(b.hasValue(ti,tj))
            {
                ti = randInt(n-1);
                tj = randInt(n-1);
                v = 2; //randInt(1)*2+2;
                cout<<"try: ti = "<<ti<<", tj = "<<tj<<", v = "<<v<<endl;
            }
            b.add(ti,tj,v);
            b.show();
        }
    }

    return 0;
}

