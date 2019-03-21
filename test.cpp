
#include <iostream>
#include <memory>

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


        void show()
        {
            cout<<"------------------"<<endl;
            for(int i = 0 ; i < n ; i++)
            {
                for(int j = 0 ; j < n ; j++)
                {
                    if(data[i][j]==0)
                    {
                        cout<<"[ ]";
                    }
                    else
                    {
                        cout<<"["<<data[i][j]<<"]";
                    }
                }
                cout<<endl;
            }
        }


        void moveH(int d)
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
};



int main()
{

    Board b = Board(6);

    b.show();

    b.set(1,2,4);
    b.set(1,4,4);
    b.set(4,2,6);
    b.set(3,2,4);
    b.set(4,3,7);
    b.show();

    b.moveH(0);
    b.show();

    return 0;
}

