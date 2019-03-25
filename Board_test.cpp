


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

    cout<<"after init:"<<endl;
    b.show();


    //moveHL test
    int moveHL_test_count = 1;

    cout<<">>>>>>>>> moveHL() test "<<moveHL_test_count<<" <<<<<<<<<<<"<<endl;
    b.clear();
    b.add(0,0,1);
    b.add(0,1,1);
    b.add(0,2,1);
    b.add(0,3,1);
    b.add(0,4,1);
    b.show();

    b.moveHL();
    b.show();
    moveHL_test_count++;


    cout<<">>>>>>>>> moveHL() test "<<moveHL_test_count<<" <<<<<<<<<<<"<<endl;
    b.clear();
    b.add(0,0,1);
    b.add(0,1,1);
    b.add(0,3,1);
    b.add(0,4,1);
    b.add(0,5,1);
    b.show();

    b.moveHL();
    b.show();
    moveHL_test_count++;

    cout<<">>>>>>>>> moveHL() test "<<moveHL_test_count<<" <<<<<<<<<<<"<<endl;
    b.clear();
    b.add(0,1,1);
    b.add(0,4,1);
    b.add(0,5,1);
    b.show();

    b.moveHL();
    b.show();
    moveHL_test_count++;

    return 0;
}

