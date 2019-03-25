


// TODO:

// need a pool to track which spots can add a new number

// need to change adding process, no more than two numbers can be added.


#include <iostream>
#include <memory>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <string>

using namespace std;


class Board
{
    public:
        int** data;
        int n;
        Board(int n)
        {
            this->n = n;
            data = (int**)calloc(n,sizeof(int*));
            for(int i = 0 ; i < n ; i++)
                data[i] = (int*)calloc(n,sizeof(int));
        }


        void set(int i, int j, int val)
        {
            if(val<=0)
            {
                cout<<"invalid value"<<endl;
            }
            else
            {
                data[i][j] = val;
            }
        }   

        void add(int i, int j, int val)
        {
            if(val<=0)
            {
                cout<<"invalid value"<<endl;
            }
            else
            {
                data[i][j] += val;
            }
        }   

        void show()
        {
            cout<<"------------------"<<endl;
            for(int i = 0 ; i < n ; i++)
            {
                for(int j = 0 ; j < n ; j++)
                {
                    int maxV = 0;
                    for(int ii = 0 ; ii < n ; ii++)
                    {
                        maxV = max(maxV,data[ii][j]);
                    }

                    int digits = 0;
                    while(maxV>0)
                    {
                        maxV/=10;
                        digits++;
                    }

                    // cout<<"digits = "<<digits<<endl;

                    if(data[i][j]==0)
                    {
                        cout<<"[";
                        for(int d = 0 ; d < digits ; d++)
                            cout<<" ";
                        cout<<"]";
                    }
                    else
                    {
                        int cur = data[i][j];
                        while(cur>0)
                        {
                            cur/=10;
                            digits--;
                        }
                        cout<<"[";
                        for(int d = 0 ; d < digits ; d++)
                            cout<<" ";
                        cout<<data[i][j];
                        cout<<"]";
                    }
                }
                cout<<endl;
            }
        }

        void moveHL()
        {
            int prev = -1;
            int writeIdx = 0;
            int sum = 0;
            for(int i = 0 ; i < n ; i++)
            { 
                prev = -1;  
                sum = 0;
                writeIdx = 0;
                for(int j = 0 ; j < n ; j++)
                {
                    if(data[i][j]==0)
                    {
                        continue;
                    }
                    cout<<"data[i][j] = "<<data[i][j]<<endl;
                    cout<<"prev = "<<prev<<endl;
                    if(data[i][j]==prev)
                    {
                        sum+=prev;
                        cout<<"sum = "<<sum<<endl;
                    }
                    else
                    {
                        if(prev!=-1)
                        {
                            cout<<"write at "<<writeIdx<<endl;
                            cout<<"sum ="<<sum<<endl;
                            data[i][writeIdx] = sum;
                            writeIdx++;
                        } 
                        prev = data[i][j];
                        cout<<"new prev = "<<prev<<endl;
                        sum = prev;
                    } 
                }
                if(prev!=-1)
                {
                    if(sum==0)
                    {
                        data[i][writeIdx] = prev;
                    }
                    else
                    {
                        cout<<"write idx "<<writeIdx<<", sum = "<<sum<<endl;
                        data[i][writeIdx] = sum;
                        for(int j = writeIdx+1; j < n ; j++)
                        {
                            data[i][j] = 0;
                        }
                    }
                } 
            }

        }

        void moveHR()
        {
            int prev = -1;
            int writeIdx = n-1;
            int sum = 0;
            for(int i = 0 ; i < n ; i++)
            { 
                prev = -1;  
                sum = 0;
                writeIdx = n-1;
                for(int j = n-1; j >=0 ; j--)
                {
                    if(data[i][j]==0)
                    {
                        continue;
                    }
                    cout<<"data[i][j] = "<<data[i][j]<<endl;
                    cout<<"prev = "<<prev<<endl;
                    if(data[i][j]==prev)
                    {
                        sum+=prev;
                        cout<<"sum = "<<sum<<endl;
                    }
                    else
                    {
                        if(prev!=-1)
                        {
                            cout<<"write at "<<writeIdx<<endl;
                            cout<<"sum ="<<sum<<endl;
                            data[i][writeIdx] = sum;
                            writeIdx--;
                        } 
                        prev = data[i][j];
                        cout<<"new prev = "<<prev<<endl;
                        sum = prev;
                    } 
                }
                if(prev!=-1)
                {
                    if(sum==0)
                    {
                        data[i][writeIdx] = prev;
                    }
                    else
                    {
                        cout<<"write idx "<<writeIdx<<", sum = "<<sum<<endl;
                        data[i][writeIdx] = sum;
                        for(int j = writeIdx-1; j >=0 ; j--)
                        {
                            data[i][j] = 0;
                        }
                    }
                } 
            }

        }

        void moveVU()
        {
            int prev = -1;
            int writeIdx = 0;
            int sum = 0;
            for(int j = 0 ; j < n ; j++)
            { 
                prev = -1;  
                sum = 0;
                writeIdx = 0;
                for(int i = 0 ; i < n ; i++)
                {
                    if(data[i][j]==0)
                    {
                        continue;
                    }
                    cout<<"data[i][j] = "<<data[i][j]<<endl;
                    cout<<"prev = "<<prev<<endl;
                    if(data[i][j]==prev)
                    {
                        sum+=prev;
                        cout<<"sum = "<<sum<<endl;
                    }
                    else
                    {
                        if(prev!=-1)
                        {
                            cout<<"write at "<<writeIdx<<endl;
                            cout<<"sum ="<<sum<<endl;
                            data[writeIdx][j] = sum;
                            writeIdx++;
                        } 
                        prev = data[i][j];
                        cout<<"new prev = "<<prev<<endl;
                        sum = prev;
                    } 
                }
                if(prev!=-1)
                {
                    if(sum==0)
                    {
                        data[writeIdx][j] = prev;
                    }
                    else
                    {
                        cout<<"write idx "<<writeIdx<<", sum = "<<sum<<endl;
                        data[writeIdx][j] = sum;
                        for(int i = writeIdx+1; i < n ; i++)
                        {
                            data[i][j] = 0;
                        }
                    }
                } 
            }

        }

        void moveVD()
        {
            int prev = -1;
            int writeIdx = n-1;
            int sum = 0;
            for(int j = 0 ; j <n ; j++)
            { 
                prev = -1;  
                sum = 0;
                writeIdx = n-1;
                for(int i = n-1 ; i >= 0 ; i--)
                {
                    if(data[i][j]==0)
                    {
                        continue;
                    }
                    cout<<"data[i][j] = "<<data[i][j]<<endl;
                    cout<<"prev = "<<prev<<endl;
                    if(data[i][j]==prev)
                    {
                        sum+=prev;
                        cout<<"sum = "<<sum<<endl;
                    }
                    else
                    {
                        if(prev!=-1)
                        {
                            cout<<"write at "<<writeIdx<<endl;
                            cout<<"sum ="<<sum<<endl;
                            data[writeIdx][j] = sum;
                            writeIdx--;
                        } 
                        prev = data[i][j];
                        cout<<"new prev = "<<prev<<endl;
                        sum = prev;
                    } 
                }
                if(prev!=-1)
                {
                    if(sum==0)
                    {
                        data[writeIdx][j] = prev;
                    }
                    else
                    {
                        cout<<"write idx "<<writeIdx<<", sum = "<<sum<<endl;
                        data[writeIdx][j] = sum;
                        for(int i = writeIdx-1; i >=0 ; i--)
                        {
                            data[i][j] = 0;
                        }
                    }
                } 
            }

        }
};



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
            v = randInt(1)*2+2;
            //cout<<"ti = "<<ti<<", tj = "<<tj<<", v = "<<v<<endl;
            b.add(ti,tj,v);
            b.show();
        }
    }

    return 0;
}

