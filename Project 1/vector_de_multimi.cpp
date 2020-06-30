#include "vector_de_multimi.h"
#include "multime.h"
#include "array.h"
Vector::Vector()
{
    capacity=1;
    c=new Multime[capacity];
    len=0;
}
Vector::~Vector()
{
    delete[]c;
}
Multime& Vector::operator[] (int x) const
{
    return c[x];
}
void Vector::Append(Multime& x)
{
    Multime* temp;
    if(len>=capacity)
    {
        temp=new Multime[2*capacity];
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
