

/// Stan Bianca-Mihaela grupa 132
/// rulat cu Codeblocks  g++ C++14
/// Tutore: Lupascu Marian

#ifndef DEZINFECTANT_H_INCLUDED
#define DEZINFECTANT_H_INCLUDED
#include <bits/stdc++.h>

class Dezinfectant
{
protected:
    int nr_organisme_ucise;
    std::vector<std::string> ingrediente;
    std::vector<std::string> suprafete;
    Dezinfectant();
    Dezinfectant(std::vector<std::string> ingrediente, std::vector<std::string> suprafete, int nr_organisme_ucise);
    Dezinfectant(const Dezinfectant& ob);
    void operator= (const Dezinfectant& ob);
    friend std::istream& operator>> (std::istream& in, Dezinfectant& ob);
    friend std::ostream& operator<< (std::ostream& out, const Dezinfectant& ob);
    virtual ~Dezinfectant()=0;
public:
    std::vector<std::string> get_ingrediente() const;
    std::vector<std::string> get_suprafete() const;
    int get_nr_organisme_ucise() const;

    void set_ingrediente(std::string& x);
    void set_suprafete(std::string& x);
    void set_nr_organisme_ucise(int x);

    virtual double eficienta()=0;

};

#endif //DEZINFECTANT_H_INCLUDED
