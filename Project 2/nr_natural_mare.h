#ifndef NR_NATURAL_MARE_H_INCLUDED
#define NR_NATURAL_MARE_H_INCLUDED
#include "nr_mare.h"
#include "array.h"

class Nr_natural_mare : public Nr_mare
{
protected:
    int nr_cifre;
public:
    ///constrcutori
    Nr_natural_mare() : Nr_mare(), nr_cifre(0) {};
    explicit Nr_natural_mare(int a, Array b) : Nr_mare(b), nr_cifre(a) {};
    explicit Nr_natural_mare(int x) : Nr_mare(x) {nr_cifre=a.get_len();};
    Nr_natural_mare(Nr_natural_mare const &ob): Nr_mare(ob.a), nr_cifre(ob.nr_cifre) {};

    ///destructor
    ~Nr_natural_mare() {};

    ///operatori
    Nr_natural_mare& operator= (Nr_natural_mare const &ob);
    friend std::ostream& operator<< (std::ostream& out, const Nr_natural_mare& ob);
    friend std::istream& operator>> (std::istream& in, Nr_natural_mare& ob);
    bool operator>(Nr_natural_mare const& b) const;
    bool operator<(Nr_natural_mare const& b) const;
    bool operator>=(Nr_natural_mare const& b) const;
    bool operator<=(Nr_natural_mare const& b) const;
    bool operator==(Nr_natural_mare const& b) const;
    bool operator==(int x) const;
    bool operator!=(Nr_natural_mare const& b) const;
    int& operator[] (int) const;
    Nr_natural_mare operator+(Nr_natural_mare const& b) const;
    Nr_natural_mare operator-(Nr_natural_mare const& b) const;
    Nr_natural_mare operator*(Nr_natural_mare const& b) const;
    Nr_natural_mare operator%(Nr_natural_mare const& b) const;
    Nr_natural_mare operator/(Nr_natural_mare const& b) const;
    Nr_natural_mare operator++();
    Nr_natural_mare operator--();
    Nr_natural_mare operator++(int);
    Nr_natural_mare operator--(int);


    ///alte functii random
    //Nr_natural_mare bucata(int start, int end) const;
    Array modul();
};

#endif // NR_NATURAL_MARE_H_INCLUDED
