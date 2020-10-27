/// Stan Bianca-Mihaela grupa 132
/// rulat cu Codeblocks  g++ C++14
/// Tutore: Lupascu Marian
#ifndef TRIPLET_H_INCLUDED
#define TRIPLET_H_INCLUDED
#include <bits/stdc++.h>
template<class A,class B,class C>
class Triplet
{
private:
    A first;
    B second;
    C third;
public:
    Triplet()
    {

    }
    Triplet(A f,B s,C t): first(f),
        second(s),
        third(t)
    {
    }

};

template<>
class Triplet <int, int, int>
{
    private:
    int first;
    int second;
    int third;
public:
    Triplet(int f=0,int s=0,int t=0): first(f), second(s), third(t) {};
    Triplet& operator- (const Triplet& ob )
    {
        int a=third-ob.third;
        int b=second-ob.second;
        int c=first-ob.first;
        if(b<0) {a--; b=b+12;}
        if(c<0) {b--; c=c+30;}
        Triplet<int, int, int> t(a, b, c);
        return t;
    }
    bool operator> (const Triplet& ob)
    {
        if(first<ob.first) return 0;
        else if(first>ob.first) return 1;
        else
        {
            if(second<ob.second) return 0;
            else if(second>ob.second) return 1;
            else
            {
                if(third<ob.third) return 0;
                else if(third>ob.third) return 1;
                else return 0;
            }
        }
    }
    bool operator>= (const Triplet& ob)
    {
        if(first<ob.first) return 0;
        else if(first>ob.first) return 1;
        else
        {
            if(second<ob.second) return 0;
            else if(second>ob.second) return 1;
            else
            {
                if(third<ob.third) return 0;
                else if(third>ob.third) return 1;
                else return 1;
            }
        }
    }
    bool operator< (const Triplet& ob)
    {
        return 1-((*this)>=ob);
    }
    bool operator<= (const Triplet& ob)
    {
        return 1-((*this)>ob);
    }
    bool operator== (const Triplet& ob)
    {
        return first==ob.first && second==ob.second && third==ob.third;
    }
    bool operator!= (const Triplet& ob)
    {
        return 1-((*this)==ob);
    }


    friend std::istream& operator>> (std::istream& in, Triplet<int, int, int>& ob)
    {
        std::cout<<"Introduceti ziua: ";
        in>>ob.first;
        std::cout<<"Introduceti luna: ";
        in>>ob.second;
        std::cout<<"Introduceti anul: ";
        in>>ob.third;
        return in;
    }
    friend std::ostream& operator<< (std::ostream& out,const Triplet<int, int, int>& ob)
    {
        out<<ob.third<<"."<<ob.second<<"."<<ob.first;
        return out;
    }
    int get_first() const
    {
        return first;
    }
    int get_second() const
    {
        return second;
    }
    int get_third() const
    {
        return third;
    }

};

///functii template pentru a a citi de la tastatura pana cand se citeste un numar pozitiv
template<class T>
T verifica_pozitiv(std::istream& in)
{
    T value;
    int ok=0;
    while (ok==0)
    try
    {
        ok=1;
        in>>value;
        if (value<0) throw 1;
    }
    catch(int)
    {
        std::cout<<"Campul trebuie sa aiba o valoare pozitiva!\n";
        ok=0;
    }
    return value;
}


template<class T>
T verifica_strinct_pozitiv(std::istream& in)
{
    int value;
    int ok=0;
    while (ok==0)
    try
    {
        ok=1;
        in>>value;
        if (value<0) throw 1;
    }
    catch(int)
    {
        std::cout<<"Campul trebuie sa aiba o valoare pozitiva!\n";
        ok=0;
    }
    return value;
}


template<class A,class B>
class Cuplu
{
private:
    A first;
    B second;
public:
    Cuplu()
    {

    }
    Cuplu(A f,B s): first(f),
        second(s)
    {
    }

};

template<>
class Cuplu <int, int>
{
    private:
    int first;
    int second;
public:
    Cuplu(int f=0,int s=0,int t=0): first(f), second(s) {};
    Cuplu& operator- (const Cuplu& ob )
    {
        int a=first-ob.first;
        int b=second-ob.second;
        if(b<0) {a--; b=b+60;}
        if(a<0) {a=a+24;}
        Cuplu<int, int> t(a, b);
        return t;
    }
    bool operator> (const Cuplu& ob)
    {
        if(first<ob.first) return 0;
        else if(first>ob.first) return 1;
        else
        {
            if(second<ob.second) return 0;
            else if(second>ob.second) return 1;
            return 0;
        }
    }
    bool operator>= (const Cuplu& ob)
    {
        if(first<ob.first) return 0;
        else if(first>ob.first) return 1;
        else
        {
            if(second<ob.second) return 0;
            else if(second>ob.second) return 1;
            return 1;
        }
    }
    bool operator< (const Cuplu& ob)
    {
        return 1-((*this)>=ob);
    }
    bool operator<= (const Cuplu& ob)
    {
        return 1-((*this)>ob);
    }
    bool operator== (const Cuplu& ob)
    {
        return first==ob.first && second==ob.second;
    }
    bool operator!= (const Cuplu& ob)
    {
        return 1-((*this)==ob);
    }


    friend std::istream& operator>> (std::istream& in, Cuplu<int, int>& ob)
    {
        std::cout<<"Introduceti ora: ";
        in>>ob.first;
        std::cout<<"Introduceti minutul: ";
        in>>ob.second;
        return in;
    }
    friend std::ostream& operator<< (std::ostream& out,const Cuplu<int, int>& ob)
    {
        out<<ob.first<<":"<<ob.second;
        return out;
    }

};
#endif // TRIPLET_H_INCLUDED
