

/// Stan Bianca-Mihaela grupa 132
/// rulat cu Codeblocks  g++ C++14
/// Tutore: Lupascu Marian


#ifndef MASCACHIRURGICALA_H_INCLUDED
#define MASCACHIRURGICALA_H_INCLUDED
#include <bits/stdc++.h>
#include "Masca.h"

class MascaChirurgicala:public Masca
{
protected:
public:
    MascaChirurgicala();
    MascaChirurgicala(std::string tip, std::string culoare, int nr_pliuri);
    MascaChirurgicala(const MascaChirurgicala& ob);
    void operator= (const MascaChirurgicala& ob);
    friend std::istream& operator>> (std::istream& in, MascaChirurgicala& ob);
    friend std::ostream& operator<< (std::ostream& out, const MascaChirurgicala& ob);
    ~MascaChirurgicala();



};

#endif //MASCACHIRURGICALA_H_INCLUDED
