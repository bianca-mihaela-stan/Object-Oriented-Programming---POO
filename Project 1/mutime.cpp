#include "multime.h"
#include "array.h"
#include "vector_de_multimi.h"
#include <iostream>
Multime::Multime()
    {
        Array a;
        n=0;
    }
Multime::Multime(Multime& ob)
    {
        for(int i=0; i<n; i++)
        {
            a.Append(ob.a[i]);
        }
        n=(ob.n);
    }
Multime::~Multime()
    {
        //std::cout<<"se apeleaza destructorul pentru multime ";
        //Afisare();
    }
void Multime::Transformare(Array x)
{
    if(n!=0) std::cout<<"Nu se poate suprascrie peste o multime nevida";
    else
    {
        x.Sortare();///sortez numerele
        for(int i=0; i<x.len-1; i++)
        {
            if(x[i]!=x[i+1])///iau doar numerele distincte
            {
                a.Append(x[i]);
                if(i==x.len-2)
                {
                    a.Append(x[i+1]);
                }
            }
        }
        n=a.len;
    }
}
Multime Multime::operator+ (Multime const &y)
{
    int i=0, j=0;
    Multime q;
    while(i<n && j<y.n)
    {
        if(a[i]==y.a[j])
        {
            q.a.Append(y.a[j]);
            i++;
            j++;
        }
        else if (a[i]<y.a[j])
        {
            q.a.Append(a[i]);
            i++;
        }
        else if (y.a[j]<a[i])
        {
            q.a.Append(y.a[j]);
            j++;
        }
    }
    while(i<n)
    {
        q.a.Append(a[i]);
        i++;
    }
    while(j<y.n)
    {
        q.a.Append(y.a[j]);
        j++;
    }
    q.n=q.a.len;
    q.a.Sortare();
    return q;
}
Multime& Multime::operator=(Multime const &ob)
{
    delete[] a.get_c();

        if(this!=&ob)
        {
            for(int i=0; i<ob.n; i++)
            {
                a.Append(ob.a[i]);
            }
            n=(ob.n);
        }
    return *this;
}
Multime Multime::operator* (Multime const &y)
{
    Multime q;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<y.n; j++)
        {
            if(a[i]==y.a[j])
                q.a.Append(a[i]);
        }
    }
    q.n=q.a.len;
    q.a.Sortare();
    return q;
}
Multime Multime::operator-(Multime const &y)
{
    Multime q;
    int i=0, j=0;
    while(i<n && j<y.n)
    {
        if(a[i]==y.a[j])
        {
            i++;
            j++;
        }
        if(a[i]<y.a[j])
        {
            q.a.Append(a[i]);
            i++;
        }
        else
        {
            j++;
        }
    }
    while(i<n)
    {
        q.a.Append(a[i]);
        i++;
    }
    q.n=q.a.len;
    return q;
}
void Multime::Afisare() const
{
    for(int i=0; i<n; i++)
    {
        std::cout<<a[i]<<" ";
    }
    std::cout<<"\n";
    return;
}
std::istream& operator>>(std::istream& in, Multime &ob)
{
    delete[] ob.a.get_c();
    ob.a.get_len()=0;
    ob.a.get_capacity()=1;
    in>>ob.n;
    for(int i=0; i<ob.n; i++)
    {
        int x;
        in>>x;
        ob.a.Append(x);
    }
    return in;
}
std::ostream& operator<<(std::ostream& out, Multime& ob)
{
    out<<"Multime cu "<<ob.n<<" elemente : ";
    for(int i=0; i<ob.n; i++)
    {
        out<<ob.a[i]<<" ";
    }
    out<<"\n";
    return out;
}
