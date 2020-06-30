#ifndef VECTOR_DE_NR_H_INCLUDED
#define VECTOR_DE_NR_H_INCLUDED
#include "nr_natural_mare.h"
class vector_de_nr_naturale
{
private:
    Nr_natural_mare* p;
    int nr_obiecte;
    int capacitate;
public:
    ///constructori
    vector_de_nr_naturale();
    vector_de_nr_naturale(Nr_natural_mare const &ob);

    ///destructor
    ~vector_de_nr_naturale();

    ///append
    void Append(Nr_natural_mare const &ob);

    ///operatori
    friend std::ostream& operator<< (std::ostream& out, const vector_de_nr_naturale& ob);
    friend std::istream& operator>> (std::istream& in, vector_de_nr_naturale& ob);

    ///alte functii
};

#endif // VECTOR_DE_NR_H_INCLUDED
