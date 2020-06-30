#include "nr_natural_mare.h"
#include "myexception.h"

///operatori
Nr_natural_mare& Nr_natural_mare::operator= (Nr_natural_mare const &ob)
{
    a=ob.a;
    nr_cifre=ob.nr_cifre;
    return (*this);
};


std::ostream& operator<< (std::ostream& out, const Nr_natural_mare& ob)
{
    for(int i=0; i<ob.nr_cifre; i++)
        out<<ob.a[i];
    out<<"\n";
    return out;
}


std::istream& operator>> (std::istream& in, Nr_natural_mare& ob)
{
    std::string nr;
    in>>nr;
    try
    {
        for(int i=0; i<nr.size(); i++)
        {
            if(!(nr[i]>='0' && nr[i]<='9'))
                throw 1;
            if(nr[0]=='0' && !(nr.size()==1))
                throw 2;
        }
        if(ob.nr_cifre!=0)
        {
            ob.a.golire();
            ob.nr_cifre=0;
        }
        for(int i=0; i<nr.length(); i++)
        {
            ob.a.Append(nr[i]-48);
        }
        ob.nr_cifre=nr.length();
        return in;
    }
    catch(int x)
    {
        if (x==1) std::cout<<"Tipul numarului trebuie sa fie int.\n";
        else if (x==2) std::cout<<"Numarul nu poate fi denormalizat( ex:00051 e denormalizat).\n";
    }
    catch(...)
    {
        std::cout<<"Programul a intampinat o eroare netratata.\n";
    }
    Nr_natural_mare n(0);
    ob=n;
    //std::cout<<ob;
    return in;
}

bool Nr_natural_mare::operator>(Nr_natural_mare const& b) const
{
    if(nr_cifre<b.nr_cifre)
        return 0;
    else if (nr_cifre==b.nr_cifre)
    {
        int i=0;
        int j=0;
        while(i<=nr_cifre&& j<=b.nr_cifre)
        {
            if(a[i]<b.a[j])
            {
                return 0;
            }
            else if(a[i]>b.a[j])
            {
                return 1;
            }
            i++;
            j++;
        }
        if(i==nr_cifre+1 && j==nr_cifre+1) return 0;///numerele sunt egale
    }
    return 1;
}


bool Nr_natural_mare::operator<(Nr_natural_mare const& b) const
{
    if(nr_cifre<b.nr_cifre)
        return 1;
    else if (nr_cifre==b.nr_cifre)
    {
        int i=0;
        int j=0;
        while(i<=nr_cifre&& j<=nr_cifre)
        {
            if(a[i]<b.a[j])
            {
                return 1;
            }
            else if(a[i]>b.a[j])
            {
                return 0;
            }
            i++;
            j++;
        }
        if(i==nr_cifre && j==nr_cifre) return 0;///numerele sunt egale
    }
    return 0;
}


bool Nr_natural_mare::operator<=(Nr_natural_mare const& b) const
{
    if(nr_cifre<b.nr_cifre)
        return 1;
    else if (nr_cifre==b.nr_cifre)
    {
        int i=0;
        int j=0;
        while(i<nr_cifre&& j<nr_cifre)
        {
            if(a[i]<b.a[j])
            {
                return 1;
            }
            else if(a[i]>b.a[j])
            {
                return 0;
            }
            i++;
            j++;
        }
        if(i==nr_cifre && j==nr_cifre) return 1;///numerele sunt egale
    }
    else return 0;
}


bool Nr_natural_mare::operator>=(Nr_natural_mare const& b) const
{
    if(nr_cifre<b.nr_cifre)
        return 0;
    else if (nr_cifre==b.nr_cifre)
    {
        int i=0;
        int j=0;
        while(i<nr_cifre&& j<nr_cifre)
        {
            if(a[i]<b.a[j])
            {
                return 0;
            }
            else if(a[i]>b.a[j])
            {
                return 1;
            }
            i++;
            j++;
        }
        if(i==nr_cifre && j==nr_cifre) return 1;///numerele sunt egale
    }
    else return 1;
}


bool Nr_natural_mare::operator==(Nr_natural_mare const& b) const
{
    if (nr_cifre==b.nr_cifre)
    {
        int i=0;
        int j=0;
        while(i<nr_cifre&& j<nr_cifre)
        {
            if(a[i]!=b[j])
                return 0;
            i++;
            j++;
        }
        return 1;///numerele sunt egale
    }
    return 0;
}


bool Nr_natural_mare::operator==(int x) const
{
    Nr_natural_mare d(x);
    return d==(*this);

}

bool Nr_natural_mare::operator!=(Nr_natural_mare const& b) const
{
    if (nr_cifre==b.nr_cifre)
    {
        int i=0;
        int j=0;
        while(i<nr_cifre&& j<nr_cifre)
        {
            if(a[i]!=b[i])
                return 1;
            i++;
            j++;
        }
        return 0;///numerele sunt egale
    }
    return 1;
}

int& Nr_natural_mare::operator[] (int x) const
{
    return (*this).a[x];
}

Nr_natural_mare Nr_natural_mare::operator+(Nr_natural_mare const& b) const
{
    Nr_natural_mare c;
    int i=nr_cifre-1;
    int j=b.nr_cifre-1;
    int transfer=0;
    while(i>=0 && j>=0)
    {
        int sum=(a[i]+b.a[j]+transfer)%10;
        transfer=(a[i]+b.a[j]+transfer)/10;
        c.a.Append_front(sum);
        i--;
        j--;
    }
    while(i>=0)
    {
        int sum=(a[i]+transfer)%10;
        transfer=0;
        c.a.Append_front(sum);
        i--;
    }
    while(j>=0)
    {
        int sum=(b.a[j]+transfer)%10;
        transfer=0;
        c.a.Append_front(sum);
        j--;
    }
    if(transfer>0)
        c.a.Append_front(transfer);
    c.nr_cifre=c.a.get_len();
    return c;
}


Nr_natural_mare Nr_natural_mare::operator-(Nr_natural_mare const& b) const
{
    try
    {
        if((*this)==b)
        {
            Nr_natural_mare d(0);
            return d;
        }
        if((*this)<b)
        {
            throw myexception();
        }
        if((*this)>b)
        {
            Nr_natural_mare c;
            int i=nr_cifre-1;
            int j=b.nr_cifre-1;
            int transfer=0;
            while(i>=0 && j>=0)
            {
                int dif=(a[i]-b.a[j]+transfer);
                if(dif<0)
                {
                    dif=dif+10;
                    transfer=-1;
                }
                else transfer=0;
                c.a.Append_front(dif);
                i--;
                j--;
            }
            while(i>=0)
            {
                int dif=(a[i]+transfer);
                transfer=0;
                c.a.Append_front(dif);
                i--;
            }
            c.nr_cifre=c.a.get_len();
            ///trebuie sa shiftez nr-ul cu i pozitii la dreapta
            c.a.normalizare();
            c.nr_cifre=c.a.get_len();
            return c;
        }
    }
    catch(myexception& e)
    {
        std::cout<<e.what()<<"\n";
    }
    catch(...)
    {
        std::cout<<"Programul a intampinat o eroare netratata.\n";
    }
    return (*this);
}



Nr_natural_mare Nr_natural_mare::operator*(Nr_natural_mare const& b) const
{
    Nr_natural_mare c;
    int shift_amount=0;
    int transfer=0;
    for(int j=b.nr_cifre-1; j>=0; j--)///toate cifrele de jos
    {
        transfer=0;
        Nr_natural_mare temp;///aici o sa tin rezultatul dupa fiecare pas
        for(int i=nr_cifre-1; i>=0; i--)///le inmultesc cu toate cifrele de sus
        {
            int sum=(b.a[j]*a[i]+transfer)%10;
            transfer=(b.a[j]*a[i]+transfer)/10;
            temp.a.Append_front(sum);
        }
        if(transfer>0)
            {temp.a.Append_front(transfer); transfer=0;}
        int p=0;
        while(p<shift_amount)
        {
            temp.a.Append(0);
            p++;
        }
        temp.nr_cifre=temp.a.get_len();
        c=c+temp;
        shift_amount++;
    }
    return c;
}




Nr_natural_mare Nr_natural_mare::operator/(Nr_natural_mare const& b) const
{
    try
    {
        if(b==0)
            throw 1;
        if(*this<b)
            {
                Nr_natural_mare d(0);
                return d;
            }
        Nr_natural_mare c;
        int p=0;///in p tin evidenta capatului din dreapta
        Nr_natural_mare temp;
        while(p<nr_cifre)
        {
            temp.a.Append(a[p]);
            temp.a.normalizare();
            temp.nr_cifre=temp.a.get_len();
            p++;
            int cat=0;
            int i=1;
            while(temp>=b)
            {
                temp=temp-b;
                cat++;
            }
            c.a.Append(cat);
            c.nr_cifre++;

        }
        c.a.normalizare();
        c.nr_cifre=c.a.get_len();
        return c;
    }
    catch(int x)
    {
        if(x==1) std::cout<<"Nu pot sa impart la 0.\n";
    }
    return (*this);
}



Nr_natural_mare Nr_natural_mare::operator%(Nr_natural_mare const& b) const
{
    try
    {
        if(b==0)
            throw 1;
        if((*this)<b)
            return (*this);
        Nr_natural_mare c, d;
        d=(*this)/b;
        d=d*b;
        c=(*this);
        c=c-d;
        if(b==c)
            c=Nr_natural_mare(0);
        return c;
    }
    catch(int x)
    {
        if(x==1) std::cout<<"Nu pot sa impart la 0.\n";
    }
    return (*this);
}



Nr_natural_mare Nr_natural_mare::operator++()
{
    if(a[nr_cifre-1]+1<=9)
        a[nr_cifre-1]+=1;
    else
    {
        int transfer=1;
        a[nr_cifre-1]=0;
        int i=nr_cifre-2;
        while(transfer==1 && i>=0)
        {
            if(a[i]+1<=9)
            {
                a[i]+=1;
                transfer=0;
            }
            else
            {
                a[i]=0;
                i--;
                transfer=1;
            }
        }
        if(i==-1) a.Append_front(1);
    }
    return (*this);
}

Nr_natural_mare Nr_natural_mare::operator++(int)
{
    Nr_natural_mare d(*this);
    if(a[nr_cifre-1]+1<=9)
        a[nr_cifre-1]+=1;
    else
    {
        int transfer=1;
        a[nr_cifre-1]=0;
        int i=nr_cifre-2;
        while(transfer==1 && i>=0)
        {
            if(a[i]+1<=9)
            {
                a[i]+=1;
                transfer=0;
            }
            else
            {
                a[i]=0;
                i--;
                transfer=1;
            }
        }
        if(i==-1) a.Append_front(1);
    }
    return d;
}

//1000-1=   999
Nr_natural_mare Nr_natural_mare::operator--()
{
    try
    {
        if((*this)==0)
        {
            throw myexception();
        }
        if(a[nr_cifre-1]>0)
            a[nr_cifre-1]-=1;
        else
        {
            Nr_natural_mare d;
            int transfer=-1;
            d.a.Append_front(9);
            int i=nr_cifre-2;
            while(transfer==-1 && i>=0)
            {
                if(a[i]-1>=0)
                {
                    d.a.Append_front(a[i]-1);
                    transfer=0;
                }
                else
                {
                    d.a.Append_front(9);
                    i--;
                    transfer=1;
                }
            }
            d.a.normalizare();
            d.nr_cifre=d.a.get_len();
            (*this)=d;
        }
        return (*this);
    }
    catch(myexception& e)
    {
        std::cout<<e.what()<<"\n";
    }
    catch(...)
    {
        std::cout<<"Programul a intampinat o eroare netratata.\n";
    }
    Nr_natural_mare d(0);
    return d;
}
Nr_natural_mare Nr_natural_mare::operator--(int)
{
    try
    {
        if((*this)==0)
            throw myexception();
        Nr_natural_mare rez(*this);
        if(a[nr_cifre-1]>0)
            a[nr_cifre-1]-=1;
        else
        {
            Nr_natural_mare d;
            int transfer=-1;
            d.a.Append_front(9);
            int i=nr_cifre-2;
            while(transfer==-1 && i>=0)
            {
                if(a[i]-1>=0)
                {
                    d.a.Append_front(a[i]-1);
                    transfer=0;
                }
                else
                {
                    d.a.Append_front(9);
                    i--;
                    transfer=1;
                }
            }
            d.a.normalizare();
            d.nr_cifre=d.a.get_len();
            (*this)=d;
        }
        return rez;
    }
    catch(myexception& e)
    {
        std::cout<<e.what()<<"\n";
    }
    catch(...)
    {
        std::cout<<"Programul a intampinat o eroare netratata.\n";
    }
    Nr_natural_mare d(0);
    return d;
}



///alte functii
Array Nr_natural_mare::modul()
{
    return (*this).a;
}
