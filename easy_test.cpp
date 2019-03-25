


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

void a(Board* b)
{
    b->moveHL();
    b->show();
}

void d(Board* b)
{
    b->moveHR();
    b->show();
}
void w(Board* b)
{
    b->moveVU();
    b->show();
}

void s(Board* b)
{
    b->moveVD();
    b->show();
}

int main()
{
    /* initialize random seed: */
    srand (time(NULL));
    int n = 6;
    Board b = Board(n);

    cout<<"after init:"<<endl;
    b.show();

    b.clear();
    b.add(0,0,2);
    b.add(1,3,4);
    b.add(2,0,4);
    b.add(3,0,2);
    b.add(4,0,8);
    b.add(5,0,16); b.add(5,1,8); b.add(5,2,8); b.add(5,3,4);
    b.show();

    a(&b);

    return 0;
}

