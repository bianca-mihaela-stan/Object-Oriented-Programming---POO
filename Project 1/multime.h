#ifndef MULTIME_H_INCLUDED
#define MULTIME_H_INCLUDED
#include "array.h"
#include <iostream>
class Multime{
private:
    Array a;///multimea
    int n;///nr de elemente din multime
public:
    Multime();
    Multime(Multime& ob);
    void Append(int t);
    void Scoate(int x);
    ~Multime();
    void Transformare(Array t);
    int& operator[] (int x) const;
    Multime operator+ (Multime const &y);
    Multime& operator=(Multime const &y);
    Multime operator* (Multime const &y);
    Multime operator-(Multime const &y);
    friend std::istream& operator>>(std::istream& in, Multime &ob);
    friend std::ostream& operator<<(std::ostream& out, Multime &ob);
    void citire_memorare_afisare_nobiecte(std::istream& in, std::ostream& out);
    void Afisare() const;
};
#endif // MULTIME_H_INCLUDED
