#ifndef NR_REAL_MARE_H_INCLUDED
#define NR_REAL_MARE_H_INCLUDED
#include "nr_mare.h"
#include "array.h"

class Nr_real_mare : public Nr_mare
{
private:
    Array parte_fractionara;
    char semn;
public:
    ///constructori
    Nr_real_mare() : Nr_mare() {};
    Nr_real_mare(Nr_real_mare const & ob) : Nr_mare(ob.a), parte_fractionara(ob.parte_fractionara), semn(ob.semn){};
    Nr_real_mare(char semn, Array p_int,Array  p_frac) : Nr_mare(p_int), parte_fractionara(p_frac), semn(semn) {};

    ///destructor
    ~Nr_real_mare() {};

    ///operatori
    friend std::ostream& operator<< (std::ostream& out, const Nr_real_mare& ob);
    friend std::istream& operator>> (std::istream& in, Nr_real_mare& ob);

    Array modul();
};

#endif // NR_REAL_MARE_H_INCLUDED
