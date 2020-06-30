#ifndef NR_MARE_H_INCLUDED
#define NR_MARE_H_INCLUDED
#include "array.h"
class Nr_mare
{
protected:
    Array a;
public:
    ///constructori
    Nr_mare() : a() {};
    Nr_mare(Nr_mare const &b) : a(b.a) {};
    explicit Nr_mare(Array b) : a(b) {};
    Nr_mare(int x) : a(x) {};

    ///operatori
    Nr_mare& operator= (Nr_mare const & ob) {a=ob.a; return (*this);};

    ///destructor
    virtual ~Nr_mare()=0;

    ///modul
    virtual Array modul()=0;
};

#endif // NR_MARE_H_INCLUDED
