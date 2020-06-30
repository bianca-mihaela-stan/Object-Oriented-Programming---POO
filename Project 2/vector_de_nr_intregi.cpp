#include "vector_de_nr_intregi.h"


///constructori
vector_de_nr_intregi::vector_de_nr_intregi()
{
    capacitate=1;
    nr_obiecte=0;
    p=new Nr_intreg_mare[capacitate];
}
vector_de_nr_intregi::vector_de_nr_intregi(Nr_intreg_mare const &ob)
{
    capacitate=2;
    p=new Nr_intreg_mare[capacitate];
    nr_obiecte=1;
    p[0]=ob;
}

///destructor
vector_de_nr_intregi::~vector_de_nr_intregi()
{
    delete[] p;
}

///operatori
std::ostream& operator<< (std::ostream& out, const vector_de_nr_intregi& ob)
{
    for(int i=0; i<ob.nr_obiecte; i++)
    {
        out<<ob.p[i];
    }
    out<<"\n";
}

std::istream& operator>> (std::istream& in, vector_de_nr_intregi& ob)
{
    std::cout<<"nr_obiecte= ";
    try
    {
        std::string nr_obiecte;
        in>>nr_obiecte;
        for(int i=0; i<nr_obiecte.size(); i++)
        {
            if(!(nr_obiecte[i]>='0' && nr_obiecte[i]<='9'))
                throw 1;
            if(i==0 && nr_obiecte[i]=='0')
                throw 2;
        }
        int nr_ob=stoi(nr_obiecte);
        if(ob.nr_obiecte!=0)
        {
            delete[] ob.p;
            ob.nr_obiecte=0;
            ob.capacitate=1;
        }
        for(int i=0; i<nr_ob; i++)
        {
            std::cout<<"obiectul "<<i+1<<": ";
            Nr_intreg_mare nr;
            in>>nr;
            ob.Append(nr);
        }
    }
    catch(int x)
    {
        if (x==1) std::cout<<"Tipul lui 'nr_obiecte' trebuie sa fie int.\n";
        else if (x==2) std::cout<<"Numarul nu poate fi 0 sau denormalizat( ex:00051 e denormalizat).\n";
    }
    catch(...)
    {
        std::cout<<"Programul a intampinat o eroare netratata.\n";
    }
}


///append
void vector_de_nr_intregi::Append(Nr_intreg_mare const &ob)
{
    Nr_intreg_mare* temp;
    if(nr_obiecte>=capacitate)
    {
        temp=new Nr_intreg_mare[2*capacitate];
        for(int i=0; i<capacitate; i++)
        {
            temp[i]=p[i];
        }
        capacitate*=2;
        delete[] p;
        p=temp;
    }
    p[nr_obiecte]=ob;
    nr_obiecte++;
}
