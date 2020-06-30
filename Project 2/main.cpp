#include <iostream>
#include "nr_intreg_mare.h"
#include "nr_natural_mare.h"
#include "vector_de_nr_naturale.h"
#include "vector_de_nr_intregi.h"
#include "nr_mare.h"
#include "nr_real_mare.h"
using namespace std;

int main()
{
    //operatii cu clasa Nr_natural_mare
    cout<<"Operatii cu clasa Nr_natural_mare: \n";
    Nr_natural_mare nr1;
    cout<<"Introduceti un nr natural: ";
    cin>>nr1;
    Nr_natural_mare nr2(555);
    cout<<nr2;
    cout<<"nr1+nr1+nr2="<<nr1+nr2;
    cout<<"nr2%nr1="<<nr2%nr1;
    cout<<"nr1.modul()="<<nr1.modul();

    //operatii cu clasa Nr_intreg_mare
    cout<<"Operatii cu clasa Nr_intreg_mare: \n";
    Nr_intreg_mare nr3;
    cout<<"Introduceti un nr intreg: ";
    cin>>nr3;
    cout<<nr3;
    Nr_intreg_mare nr4('-',555);
    cout<<nr4;
    cout<<"nr3+nr3+nr4="<<nr3+nr4;
    cout<<"nr4%nr3="<<nr3%nr4;
    cout<<"nr3.modul()="<<nr3.modul();

    ///operatii cu clasa Nr_real_mare
    cout<<"Operatii cu clasa Nr_real_mare: \n";
    Nr_real_mare nr5('-', 5, 66);
    cout<<nr5.modul();

    ///dynamic-cast de la Nr_mare la Nr_real_mare
    cout<<"dynamic_cast: \n";
    Nr_mare* a= new Nr_real_mare('+', 258, 1);
    Nr_real_mare* b=dynamic_cast<Nr_real_mare*> (a);
    cout<<b->modul();

    ///aruncarea exceptiei create de mine
    cout<<"Aruncarea exceptiei create de mine: \n";
    Nr_natural_mare nr6(0);
    cout<<--nr6;

    ///citirea si memorarea a n obiecte de tip nr_natural_mare
    cout<<"Citirea, memorarea si afisarea a n obiecte de tip nr_natural_mare:\n";
    vector_de_nr_naturale v1;
    cin>>v1;
    cout<<v1;

    cout<<"Citirea, memorarea si afisarea a n obiecte de tip nr_intreg_mare:\n";
    vector_de_nr_intregi v2;
    cin>>v2;
    cout<<v2;

    return 0;
}
