#include "Film.h"

std::istream& operator>> (std::istream& in, Film& ob)
{
    try
    {
        std::string x;
        getline(in, x);
        std::cout<<"\nIntroduceti numle filmului: ";
        getline(in, x);
        if(x=="") throw myexception(1);
        ob.nume=std::move(x);
        std::cout<<"\nIntroduceti tipul filmului: ";
        getline(in, x);
        if(x=="") throw myexception(2);
        ob.tip=std::move(x);
        std::cout<<"\nIntroduceti durata filmului (format 02:30): ";
        getline(in, x);
        if(x.size()>5 || !(x[0]>='0' && x[0]<='9') ||!(x[1]>='0' && x[1]<='9') || !(x[3]>='0' && x[3]<='9') || !(x[4]>='0' && x[4]<='9') ||x[2]!=':')
            throw myexception(4);
        ob.durata=x;
        std::cout<<"\nIntroduceti anul realizarii filmului: ";
        in>>ob.an;
        std::cout<<"\nIntroduceti incasarile filmului: ";
        in>>ob.incasari;
    }
    catch(myexception& e)
    {
        std::cout<<e.what()<<"\n";
    }
    catch(...)
    {
        std::cout<<"Programul a intampinat o eroare netratata.\n";
    }
    return in;
}
std::ostream& operator<< (std::ostream& out, const Film& ob)
{
    out<<"Filmul "<<ob.nume<<"("<<ob.an<<") care este de tip ";
    out<<ob.tip<<", dureaza "<<ob.durata<<" si a avut incasari de ";
    out<<ob.incasari<<".\n";
    return out;
}


unsigned int Film::get_incasari() const
{
    return incasari;
}

unsigned int Film::get_an() const
{
    return an;
}
