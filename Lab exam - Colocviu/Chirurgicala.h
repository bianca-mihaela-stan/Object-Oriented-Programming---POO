

/// Stan Bianca-Mihaela grupa 132
/// rulat cu Codeblocks  g++ C++14
/// Tutore: Lupascu Marian
#ifndef CHIRURGICALA_H_INCLUDED
#define CHIRURGICALA_H_INCLUDED
#include <bits/stdc++.h>
#include "Masca.h"

class Chirurgicala:public Masca
{
protected:
public:
    Chirurgicala();
    Chirurgicala(std::string tip, std::string culoare, int nr_pliuri);
    Chirurgicala(const Chirurgicala& ob);
    void operator= (const Chirurgicala& ob);
    friend std::istream& operator>> (std::istream& in, Chirurgicala& ob);
    friend std::ostream& operator<< (std::ostream& out, const Chirurgicala& ob);
    ~Chirurgicala();



};

#endif //CHIRURGICALA_H_INCLUDED
