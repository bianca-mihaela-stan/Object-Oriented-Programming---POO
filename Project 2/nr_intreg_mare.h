#ifndef NR_INTREG_MARE_H_INCLUDED
#define NR_INTREG_MARE_H_INCLUDED
#include "nr_natural_mare.h"
class Nr_intreg_mare: public Nr_natural_mare
{
protected:
    char semn;
public:
    Nr_intreg_mare() : Nr_natural_mare() {};
    explicit Nr_intreg_mare(char s, Nr_natural_mare nr) : Nr_natural_mare(nr), semn(s) {};
    explicit Nr_intreg_mare(Nr_natural_mare& nr): Nr_natural_mare(nr), semn('+') {};
    Nr_intreg_mare(Nr_intreg_mare& ob): Nr_natural_mare(ob), semn(ob.semn) {};
    explicit Nr_intreg_mare(char s, int nr): Nr_natural_mare(nr), semn(s) {};


    ///operatori
    friend std::ostream& operator<< (std::ostream& out, const Nr_intreg_mare& ob);
    friend std::istream& operator>> (std::istream& in, Nr_intreg_mare& ob);
    Nr_intreg_mare& operator= (Nr_intreg_mare const &ob);
    bool operator>(Nr_intreg_mare const& b) const;
    bool operator<(Nr_intreg_mare const& b) const;
    bool operator>=(Nr_intreg_mare const& b) const;
    bool operator<=(Nr_intreg_mare const& b) const;
    bool operator==(Nr_intreg_mare const& b) const;
    bool operator!=(Nr_intreg_mare const& b) const;
    Nr_intreg_mare operator+(Nr_intreg_mare const &b) const;
    Nr_intreg_mare operator-(Nr_intreg_mare const &b) const;
    Nr_intreg_mare operator*(Nr_intreg_mare const& b) const;
    Nr_intreg_mare operator/(Nr_intreg_mare const& b) const;
    Nr_intreg_mare operator%(Nr_intreg_mare const& b) const;


    ~Nr_intreg_mare() {};


    ///alte functii
    Nr_intreg_mare modul(int) const;
    Array modul();
};

#endif // NR_INTREG_MARE_H_INCLUDED
