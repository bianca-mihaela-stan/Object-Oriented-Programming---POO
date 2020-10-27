

/// Stan Bianca-Mihaela grupa 132
/// rulat cu Codeblocks  g++ C++14
/// Tutore: Lupascu Marian

#ifndef MASCA_H_INCLUDED
#define MASCA_H_INCLUDED
#include <bits/stdc++.h>

class Masca
{
protected:
    std::string tip;
    std::string culoare;
    int nr_pliuri;
    Masca();
    Masca(std::string tip, std::string culoare, int nr_pliuri);
    Masca(const Masca& ob);
    void operator= (const Masca& ob);
    friend std::istream& operator>> (std::istream& in, Masca& ob);
    friend std::ostream& operator<< (std::ostream& out, const Masca& ob);
    virtual ~Masca()=0;
public:
    std::string get_tip() const;
    std::string get_culoare() const;
    int get_nr_pliuri() const;

    void set_tip(std::string x);
    void set_culoare(std::string x);
    void set_nr_pliuri(int x);

};

#endif //MASCA_H_INCLUDED
