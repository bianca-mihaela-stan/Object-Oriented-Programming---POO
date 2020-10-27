

/// Stan Bianca-Mihaela grupa 132
/// rulat cu Codeblocks  g++ C++14
/// Tutore: Lupascu Marian

#ifndef MASCAPOLICARBONAT_H_INCLUDED
#define MASCAPOLICARBONAT_H_INCLUDED
#include <bits/stdc++.h>
#include "Masca.h"

class MascaPolicarbonat:public Masca
{
protected:
    std::string tip_prindere;
public:
    MascaPolicarbonat();
    MascaPolicarbonat(std::string tip, std::string culoare, int nr_pliuri, std::string tip_prindere);
    MascaPolicarbonat(std::string tip_prindere);
    MascaPolicarbonat(const MascaPolicarbonat& ob);
    void operator= (const MascaPolicarbonat& ob);
    friend std::istream& operator>> (std::istream& in, MascaPolicarbonat& ob);
    friend std::ostream& operator<< (std::ostream& out, const MascaPolicarbonat& ob);
    ~MascaPolicarbonat();

    std::string get_tip_prindere() const;

    void set_tip_prindere(std::string x);

};

#endif //MASCAPOLICARBONAT_H_INCLUDED
