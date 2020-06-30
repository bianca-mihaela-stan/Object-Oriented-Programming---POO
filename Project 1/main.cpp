#include <iostream>
#include <algorithm>
#include "multime.h"
#include "array.h"
#include "vector_de_multimi.h"
using namespace std;
void citire_memorare_afisare_nobiecte(std::istream& in, std::ostream& out)
{
    out<<"Cate obiecte vor fi memorate? nr=";
    int nr;
    in>>nr;
    Vector vec;
    for(int i=0; i<nr; i++)
    {
        Multime ob;
        in>>ob;
        vec.Append(ob);
    }
    for(int i=0; i<nr; i++)
    {
        out<<vec[i];
    }
}
int main()
{
    Array arr;
    arr.Append(1);
    arr.Append(2);
    arr.Append(2);
    arr.Append(3);
    Multime mul1;
    mul1.Transformare(arr);
    cout<<"mul1="; mul1.Afisare();
    Array arr2;
    arr2.Append(-2);
    arr2.Append(2);
    arr2.Append(5);
    arr2.Append(9);
    Multime mul2;
    mul2.Transformare(arr2);
    cout<<"mul2="; mul2.Afisare();
    Array arr3;
    arr3.Append(12);
    arr3.Append(7);
    arr3.Append(-1);
    Multime mul3;
    mul3.Transformare(arr3);
    cout<<"mul3="; mul3.Afisare();
    Multime mul4;
    mul4=mul1+mul2+mul3;
    cout<<"mul4=mul1+mul2+mul3="; mul4.Afisare();

    Multime mul5;
    mul5=mul1*mul2*mul4;
    cout<<"mul5=mul1*mul2*mul4="; mul5.Afisare();

    Multime mul6;
    mul6=mul4-mul2;
    cout<<"mul6=mul4-mul2="; mul6.Afisare();

    Multime mul7;
    cin>>mul7;
    mul7.Afisare();
    cout<<mul7;
    citire_memorare_afisare_nobiecte(cin, cout);
    return 0;
}
