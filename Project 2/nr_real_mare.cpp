#include "nr_real_mare.h"

Array Nr_real_mare::modul()
{
    return a;
}

///operatori
std::ostream& operator<< (std::ostream& out, const Nr_real_mare& ob)
{
    out<<ob.semn;
    out<<ob.a;
    out<<",";
    out<<ob.parte_fractionara;
    out<<"\n";
    return out;
}
std::istream& operator>> (std::istream& in, Nr_real_mare& ob)
{
    std::string nr;
    in>>nr;
    try
    {
        int nr_virgule=0;
        for(int i=0; i<nr.size(); i++)
        {
            if(nr[i]==',')
                nr_virgule++;
            if(nr_virgule>1)
                throw 3;
            if(!(nr[i]>='0' && nr[i]<='9' && nr[i]==','))
                throw 1;
            if(i==0 && nr[i]=='0')
                throw 2;
        }
        if(ob.a.get_len()=0)
        {
            ob.a.golire();
            ob.parte_fractionara.golire();
        }
        int parte=0;
        for(int i=0; i<nr.length(); i++)
        {
            if(nr[i]==',')
                parte=1;
            else if(parte==0)
                ob.a.Append(nr[i]-48);
            else
                ob.parte_fractionara.Append(nr[i]-48);
        }
        return in;
    }
    catch(int x)
    {
        if (x==1) std::cout<<"Tipul numarului trebuie sa fie int.\n";
        else if (x==2) std::cout<<"Numarul nu poate fi 0 sau denormalizat( ex:00051 e denormalizat).\n";
        else if (x==3) std::cout<<"Prea multe virgule.\n";
    }
    catch(...)
    {
        std::cout<<"Programul a intampinat o eroare netratata.\n";
    }
    Nr_real_mare n('+', 0, 0);
    ob=n;
    return in;
}
