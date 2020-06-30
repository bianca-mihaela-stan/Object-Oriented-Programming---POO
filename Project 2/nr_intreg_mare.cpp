#include "nr_intreg_mare.h"
#include "myexception.h"
std::ostream& operator<< (std::ostream& out, const Nr_intreg_mare& ob)
{
    out<<ob.semn;
    for(int i=0; i<ob.nr_cifre; i++)
        out<<ob.a[i];
    out<<"\n";
    return out;
}


std::istream& operator>> (std::istream& in, Nr_intreg_mare& ob)
{
    std::string nr;
    in>>nr;
    try
    {

        if(nr[0]=='+' || nr[0]=='-')
        {
            if(nr.size()>=2 && nr[1]=='0' && nr[2]=='0')
                throw 2;
            for(int i=1; i<nr.size(); i++)
            {
                if(!(nr[i]>='0' && nr[i]<='9'))
                    throw 1;
            }
        }
        else
        {
            if(nr.size()>1 && nr[0]==0 && nr[1]==0)
                throw 2;
            for(int i=0; i<nr.size(); i++)
            {
                if(!(nr[i]>='0' && nr[i]<='9'))
                    throw 1;
            }
        }
        if(ob.nr_cifre!=0)
        {
            ob.a.golire();
            ob.nr_cifre=0;
            ob.semn='+';
        }
        if(nr[0]=='-')
            ob.semn='-';
        else if(nr[0]=='+')
            ob.semn='+';
        else
        {
            ob.semn='+';
            for(int i=0; i<nr.length(); i++)
            {
                ob.a.Append(nr[i]-48);
            }
            ob.nr_cifre=nr.length();
            return in;
        }
        for(int i=1; i<nr.length(); i++)
        {
            ob.a.Append(nr[i]-48);
        }
        ob.nr_cifre=nr.length()-1;
        return in;
    }
    catch(int x)
    {
        if (x==1) std::cout<<"Tipul numarului trebuie sa fie int.\n";
        else if (x==2) std::cout<<"Numarul nu poate fi denormalizat( ex:00051 e denormalizat) .\n";
        else if(x==3) std::cout<<"Numarul inserat nu e valid (contine doar + sau -).\n";
    }
    catch(...)
    {
        std::cout<<"Programul a intampinat o eroare netratata.\n";
    }
    Nr_intreg_mare n('+', 0);
    ob=n;
    return in;
}


bool Nr_intreg_mare::operator>(Nr_intreg_mare const& b) const
{
    if ((*this).semn==b.semn)
    {
        if(b.semn=='-')
        {
            return 1-(*this).Nr_natural_mare::operator>(b);
        }
        else {
                return (*this).Nr_natural_mare::operator>(b);
        }
    }
    else
    {
        if(this->semn=='-') return 0;
        else return 1;
    }
}


bool Nr_intreg_mare::operator<(Nr_intreg_mare const& b) const
{
    return 1-(*this).Nr_intreg_mare::operator>(b);
}


bool Nr_intreg_mare::operator==(Nr_intreg_mare const& b) const
{
    if ((*this).semn==b.semn)
    {
        return (*this).Nr_natural_mare::operator==(b);
    }
    else
    {
        return 0;
    }
}


bool Nr_intreg_mare::operator!=(Nr_intreg_mare const& b) const
{
    return 1-(*this).Nr_intreg_mare::operator==(b);
}


bool Nr_intreg_mare::operator>=(Nr_intreg_mare const& b) const
{
    return ((*this).Nr_intreg_mare::operator>(b) || (*this).Nr_intreg_mare::operator==(b));
}


bool Nr_intreg_mare::operator<=(Nr_intreg_mare const& b) const
{
    return ((*this).Nr_intreg_mare::operator<(b) || (*this).Nr_intreg_mare::operator==(b));
}


Nr_intreg_mare& Nr_intreg_mare::operator= (Nr_intreg_mare const &ob)
{
    if(*this!=ob)
    {
        a.golire();
        nr_cifre=ob.nr_cifre;
        a=ob.a;
        semn=ob.semn;
    }
    return *this;

}


Nr_intreg_mare Nr_intreg_mare::operator+(Nr_intreg_mare const &b) const
{
    std::cout<<"adun "<<(*this)<<" cu "<<b;
    if(semn==b.semn)
    {
        Nr_intreg_mare d(semn, (*this).Nr_natural_mare::operator+(b));
        return d;
    }
    else
    {
        if((*this).modul(1)>=b.modul(1))/// 7+(-3)
        {
            Nr_intreg_mare d(semn, (*this).Nr_natural_mare::operator-(b));
            return d;
        }
        else///3-7
        {
            Nr_intreg_mare d(b.semn, (b).Nr_natural_mare::operator-(*this));
            return d;
        }
    }
}

Nr_intreg_mare Nr_intreg_mare::operator-(Nr_intreg_mare const &b) const
{
    if(semn!=b.semn)
    {
        if(semn=='+')///daca am 6-(-3)
        {
            Nr_intreg_mare d('+', (*this).Nr_natural_mare::operator+(b));
            return d;
        }
        else///daca am -6-(3)
        {
            Nr_intreg_mare d('-', (*this).Nr_natural_mare::operator+(b));
            return d;
        }
    }
    else
    {
        if(semn=='+')
            if((*this).modul(1)>=b.modul(1))///daca am 7-3
            {
                Nr_intreg_mare d('+', (*this).Nr_natural_mare::operator-(b));
                return d;
            }
            else///daca am 4-7
            {
                Nr_intreg_mare d('-', (b).Nr_natural_mare::operator-(*this));
                return d;
            }
        else
            if((*this).modul(1)>=b.modul(1))///daca am -7-(-3)=-7+3=-(7-3)
            {
                Nr_intreg_mare d('-', (*this).Nr_natural_mare::operator-(b));
                return d;
            }
            else///daca am -3-(-7)=-3+7=7-3
            {
                Nr_intreg_mare d('+', (b).Nr_natural_mare::operator-(*this));
                return d;
            }
    }
}




Nr_intreg_mare Nr_intreg_mare::operator*(Nr_intreg_mare const& b) const
{
    if(semn==b.semn)
    {
        Nr_intreg_mare d('+', (*this).Nr_natural_mare::operator*(b));
        return d;
    }
    else
    {
        Nr_intreg_mare d('-', (*this).Nr_natural_mare::operator*(b));
        return d;
    }
}



Nr_intreg_mare Nr_intreg_mare::operator/(Nr_intreg_mare const& b) const
{
    try
    {
        Nr_intreg_mare plus('+', 0);
        Nr_intreg_mare minus('-', 0);
        if(b==plus || b==minus)
            throw 1;
        if(semn==b.semn)
        {
            Nr_intreg_mare d('+', (*this).Nr_natural_mare::operator/(b));
            return d;
        }
        else
        {
            Nr_intreg_mare d('-', (*this).Nr_natural_mare::operator/(b));
            return d;
        }
    }
    catch(int x)
    {
        if(x==1) std::cout<<"Nu pot sa impart la 0.";
    }
    return *(const_cast <Nr_intreg_mare*>(this));
}



Nr_intreg_mare Nr_intreg_mare::operator%(Nr_intreg_mare const& b) const
{
    try
    {
        Nr_intreg_mare plus('+', 0);
        Nr_intreg_mare minus('-', 0);
        if(b==plus || b==minus)
        {

            throw 1;
        }
        if(semn==b.semn)
        {
            if(semn=='+')
            {
                Nr_intreg_mare d('+', (*this).Nr_natural_mare::operator%(b));
                return d;
            }
            else
            {
                Nr_intreg_mare d('-', (*this).Nr_natural_mare::operator%(b));
                return d;
            }
        }
        else
        {
            if(semn=='+')
            {
                Nr_intreg_mare d('-', (b).Nr_natural_mare::operator-((*this).Nr_natural_mare::operator%(b)));
                return d;
            }
            else
            {
                    Nr_intreg_mare d('+', (b).Nr_natural_mare::operator-((*this).Nr_natural_mare::operator%(b)));
                    return d;
            }
        }
    }
    catch(int x)
    {
        if(x==1) std::cout<<"Nu pot sa impart la 0.";
    }
    return *(const_cast <Nr_intreg_mare*>(this));
}


///alte functii
Nr_intreg_mare Nr_intreg_mare::modul(int) const
{
    const Nr_natural_mare& d = (*this);
    Nr_intreg_mare c('+', d);
    return c;
}

Array Nr_intreg_mare::modul()
{
    return (*this).a;
}
