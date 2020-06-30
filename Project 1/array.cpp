#include "array.h"
#include <iostream>
 Array::Array()
    {
        capacity=1;
        c=new int[capacity];
        len=0;
    }
void Array::Append(int x)
    {
        int* temp;
        if(len>=capacity)
        {
            temp=new int[2*capacity];
            for(int i=0; i<capacity; i++)
            {
                temp[i]=c[i];
            }
            capacity*=2;
            delete[] c;
            c=temp;
        }
        c[len]=x;
        len++;
    }
Array::~Array()
    {
            //std::cout<<"Se apeleaza destructorul pentru array ";
            //Afisare();
            delete[]c;
    }
int& Array::operator[] (int x) const
    {
        return c[x];
    }
void Array::Afisare()
    {
        for(int i=0; i<len; i++)
            std::cout<<c[i]<<" ";
        std::cout<<"\n";
    }
void Array::Sortare()
    {
        for(int i=0; i<len; i++)
            for(int j=i+1; j<len; j++)
        {
            if(c[i]>c[j])
            {
                int x=c[i];
                c[i]=c[j];
                c[j]=x;
            }
        }
    }
int* Array::get_c()
{
    return c;
}
int& Array::get_len()
{
    return len;
};
int& Array::get_capacity()
{
    return capacity;
};
