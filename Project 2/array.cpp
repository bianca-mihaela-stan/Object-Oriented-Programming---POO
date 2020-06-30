#include "array.h"
#include <iostream>
///constrcutori
Array::Array()
{
    capacity=1;
    c=new int[capacity];
    len=0;
    //std::cout<<"Array() "<<this<<" "<<(*this);
}
Array::Array(const Array& b) :capacity(b.capacity), len(b.len)
{
    c=new int[b.capacity];
    for(int i=0; i<len; i++)
        c[i]=b.c[i];
    //std::cout<<"Array(const Array& b) :capacity(b.capacity), len(b.len) "<<this<<" "<<(*this);
}
Array::Array(int x)
{
    Array b;
    if(x==0)
    {
        b.Append(0);
    }
     else while(x>0)
    {
        b.Append_front(x%10);
        x=x/10;
    }
    c=new int[b.capacity];
    capacity=b.capacity;
    len=b.len;
    for(int i=0; i<len; i++)
        c[i]=b.c[i];
    //std::cout<<"Array(int x) "<<this<<" "<<(*this);
}




///destructor
Array::~Array()
{
        //std::cout<<"Se apeleaza destructorul pentru array ";
        //Afisare();
        //std::cout<<"~Array() "<<this<<" "<<(*this);
        delete[]c;
}




///append-uri
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
void Array::Append_front(int x)
{
    int* temp;
    if(len+1>capacity)
    {
        temp=new int[2*capacity];
        temp[0]=x;
        for(int i=1; i<=len; i++)
        {
            temp[i]=c[i-1];
        }
        capacity*=2;
        delete[] c;
        c=temp;
    }
    else
    {
        for(int i=len; i>=1; i--)
            c[i]=c[i-1];
        c[0]=x;
    }
    len++;
}




///operatori
std::ostream& operator<< (std::ostream& out, const Array& ob)
{
    for(int i=0; i<ob.len; i++)
        out<<ob.c[i];
    out<<"\n";
    return out;
}


std::istream& operator>> (std::istream& in, Array& ob)
{
    try
    {
        std::string nr;
        getline(std::cin, nr);
        for(int i=0; i<nr.size(); i++)
        {
            if(!(nr[i]>='0' && nr[i]<='9'))
            {
                throw 1;
            }
            if(i==0 && nr[i]=='0')
                throw 2;
        }
        if(ob.len!=0)
        {
            delete[] ob.c;
            ob.len=0;
            ob.capacity=1;
        }
        for(int i=0; i<nr.length(); i++)
        {
            ob.Append(nr[i]-48);
        }
        return in;
    }
    catch(int x)
    {
        if(x==1) std::cout<<"Cifrele din array trebuie sa fei de tip int.\n";
        else if(x==2) std::cout<<"Nu pot sa am format denormalizat. ex: 0019 este denormalizat \n";
    }
    catch(...)
    {
        std::cout<<"Programul a intampinat o eroare netratata.\n";
    }
}
int& Array::operator[] (int x) const
    {
        return c[x];
    }
Array& Array::operator= (Array const & arr)
{
    if(this!=&arr)
    {
        delete[] c;
        c=new int[1];
        len=0;
        capacity=1;
        for(int i=0; i<arr.len; i++)
            (*this).Append(arr[i]);
    }
    return (*this);
}





///getteri
int* Array::get_c() const
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






///alte functii random
void Array::Afisare() const
    {
        for(int i=0; i<len; i++)
            std::cout<<c[i]<<" ";
        std::cout<<"\n";
    }
void Array::Sortare() const
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
void Array::normalizare()
{
    int i=0;
    while(i<len && c[i]==0)
    {
        i++;
    }
    Array temp;
    for(int j=i; j<len; j++)
        temp.Append(c[j]);
    delete[] c;
    capacity=temp.capacity;
    len=temp.len;
    c=new int[capacity];
    for(int i=0; i<len; i++)
        c[i]=temp[i];
}
void Array::golire()
{

    delete[] c;
    c = new int[1];
    capacity=1;
    len=0;
}
