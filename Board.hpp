#ifndef Board_HPP
#define Board_HPP

#include <iostream>

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
                std::cout<<"invalid value"<<std::endl;
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
                std::cout<<"invalid value"<<std::endl;
            }
            else
            {
                data[i][j] += val;
            }
        }

        void clear()
        {
            for(int i = 0 ; i < n ; i++)
            {
                for(int j = 0 ; j < n ; j++)
                {
                    data[i][j] = 0;
                }
            }
            std::cout<<"Board cleared!"<<std::endl;
        }

        void show()
        {
            std::cout<<"------------------"<<std::endl;
            for(int i = 0 ; i < n ; i++)
            {
                for(int j = 0 ; j < n ; j++)
                {
                    int maxV = 0;
                    for(int ii = 0 ; ii < n ; ii++)
                    {
                        maxV = std::max(maxV,data[ii][j]);
                    }

                    int digits = 0;
                    while(maxV>0)
                    {
                        maxV/=10;
                        digits++;
                    }

                    // std::cout<<"digits = "<<digits<<std::endl;

                    if(data[i][j]==0)
                    {
                        std::cout<<"[";
                        for(int d = 0 ; d < digits ; d++)
                            std::cout<<" ";
                        std::cout<<"]";
                    }
                    else
                    {
                        int cur = data[i][j];
                        while(cur>0)
                        {
                            cur/=10;
                            digits--;
                        }
                        std::cout<<"[";
                        for(int d = 0 ; d < digits ; d++)
                            std::cout<<" ";
                        std::cout<<data[i][j];
                        std::cout<<"]";
                    }
                }
                std::cout<<std::endl;
            }
        }

        void moveHL()
        {
            int prev = -1; 
            int writeIdx = 0; 
            for(int i = 0 ; i < n ; i++)
            {
                prev = -1;  
                writeIdx = 0; 
                for(int j = 0 ; j < n ; j++)
                {
                    if(data[i][j]==0)
                    {
                        continue;
                    }
                    std::cout<<"data[i][j] = "<<data[i][j]<<std::endl;
                    std::cout<<"prev = "<<prev<<std::endl;
                    if(data[i][j]==prev)
                    {

                        std::cout<<"writing to data["<<i<<"]["<<writeIdx<<"]:"<<(2*prev)<<std::endl;
                        data[i][writeIdx] = 2*prev;
                        writeIdx++;
                        prev = -1;
                    }
                    else
                    {
                        if(prev!=-1)
                        {
                            std::cout<<"write at "<<writeIdx<<std::endl;
                            data[i][writeIdx] = prev;
                            writeIdx++;
                        } 
                        prev = data[i][j];
                        std::cout<<"new prev = "<<prev<<std::endl;
                    }
                }
                if(prev!=-1)
                {
                    std::cout<<"write idx "<<writeIdx<<", prev = "<<prev<<std::endl;
                    data[i][writeIdx] = prev; 
                    for(int j = writeIdx+1; j < n ; j++)
                    {
                        data[i][j] = 0;
                    }
                }
            }
        }

        void moveHR()
        {
            int prev = -1;
            int writeIdx = n-1;
            for(int i = 0 ; i < n ; i++)
            {
                prev = -1;
                writeIdx = n-1;
                for(int j = n-1; j >=0 ; j--)
                {
                    if(data[i][j]==0)
                    {
                        continue;
                    }
                    std::cout<<"data[i][j] = "<<data[i][j]<<std::endl;
                    std::cout<<"prev = "<<prev<<std::endl;
                    if(data[i][j]==prev)
                    {

                        std::cout<<"writing to data["<<i<<"]["<<writeIdx<<"]:"<<(2*prev)<<std::endl;
                        data[i][writeIdx] = 2*prev;
                        writeIdx--;
                        prev = -1;
                    }
                    else
                    {
                        if(prev!=-1)
                        {
                            std::cout<<"write at "<<writeIdx<<std::endl;
                            data[i][writeIdx] = prev;
                            writeIdx--;
                        }
                        prev = data[i][j];
                        std::cout<<"new prev = "<<prev<<std::endl;
                    }
                }
                if(prev!=-1)
                {
                    std::cout<<"write idx "<<writeIdx<<", prev = "<<prev<<std::endl;
                    data[i][writeIdx] = prev;
                    for(int j = writeIdx-1; j >=0 ; j--)
                    {
                        data[i][j] = 0;
                    }
                }
            }

        }

        void moveVU()
        {
            int prev = -1;
            int writeIdx = 0;
            for(int j = 0 ; j < n ; j++)
            {
                prev = -1;
                writeIdx = 0;
                for(int i = 0 ; i < n ; i++)
                {
                    if(data[i][j]==0)
                    {
                        continue;
                    }
                    std::cout<<"data[i][j] = "<<data[i][j]<<std::endl;
                    std::cout<<"prev = "<<prev<<std::endl;
                    if(data[i][j]==prev)
                    {
                        std::cout<<"writing to data["<<writeIdx<<"]["<<j<<"]:"<<(2*prev)<<std::endl;
                        data[writeIdx][j] = 2*prev;
                        writeIdx++;
                        prev = -1;
                    }
                    else
                    {
                        if(prev!=-1)
                        {
                            std::cout<<"write at "<<writeIdx<<std::endl;
                            data[writeIdx][j] = prev;
                            writeIdx++;
                        }
                        prev = data[i][j];
                        std::cout<<"new prev = "<<prev<<std::endl;
                    }
                }
                if(prev!=-1)
                {
                    std::cout<<"write idx "<<writeIdx<<", prev = "<<prev<<std::endl;
                    data[writeIdx][j] = prev;
                    for(int i = writeIdx+1; i < n ; i++)
                    {
                        data[i][j] = 0;
                    }
                }
            }

        }
        void moveVD()
        {
            int prev = -1;
            int writeIdx = n-1;
            for(int j = 0 ; j <n ; j++)
            {
                prev = -1;
                writeIdx = n-1;
                for(int i = n-1 ; i >= 0 ; i--)
                {
                    if(data[i][j]==0)
                    {
                        continue;
                    }
                    std::cout<<"data[i][j] = "<<data[i][j]<<std::endl;
                    std::cout<<"prev = "<<prev<<std::endl;
                    if(data[i][j]==prev)
                    {
                        std::cout<<"writing to data["<<writeIdx<<"]["<<j<<"]:"<<(2*prev)<<std::endl;
                        data[writeIdx][j] = 2*prev;
                        writeIdx--;
                        prev = -1;
                    }
                    else
                    {
                        if(prev!=-1)
                        {
                            std::cout<<"write at "<<writeIdx<<std::endl;
                            data[writeIdx][j] = prev;
                            writeIdx--;
                        }
                        prev = data[i][j];
                        std::cout<<"new prev = "<<prev<<std::endl;
                    }
                }
                if(prev!=-1)
                {
                    data[writeIdx][j] = prev;
                    std::cout<<"write idx "<<writeIdx<<", prev = "<<prev<<std::endl;
                    for(int i = writeIdx-1; i >=0 ; i--)
                    {
                        data[i][j] = 0;
                    }
                }
            }

        }
};

#endif
