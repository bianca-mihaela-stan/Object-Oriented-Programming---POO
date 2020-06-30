#ifndef VECTOR_DE_NR_INTREGI_H_INCLUDED
#define VECTOR_DE_NR_INTREGI_H_INCLUDED
#include "nr_intreg_mare.h"
class vector_de_nr_intregi
{
private:
    Nr_intreg_mare* p;
    int nr_obiecte;
    int capacitate;
public:
    ///constructori
    vector_de_nr_intregi();
    vector_de_nr_intregi(Nr_intreg_mare const &ob);

    ///destructor
    ~vector_de_nr_intregi();

    ///append
    void Append(Nr_intreg_mare const &ob);

    ///operatori
    friend std::ostream& operator<< (std::ostream& out, const vector_de_nr_intregi& ob);
    friend std::istream& operator>> (std::istream& in, vector_de_nr_intregi& ob);

    ///alte functii
};

#endif // VECTOR_DE_NR_H_INCLUDED
