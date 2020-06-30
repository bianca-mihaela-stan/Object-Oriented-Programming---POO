#ifndef REGIZOR_H_INCLUDED
#define REGIZOR_H_INCLUDED
#include "Personal.h"
class Regizor: virtual public Personal
{
    unsigned int suma_fixa;
public:
    Regizor(): Personal(), suma_fixa(0){};
    Regizor(std::string cnp ,std::string nume,int suma, std::vector<std::shared_ptr<Film>> f,unsigned int suma_fixa) : Personal(cnp, nume, suma, f), suma_fixa(suma_fixa) {};
    ~Regizor() {};
    friend std::istream& operator>> (std::istream& in, Regizor& ob);
    void afisare() const;
};

#endif // REGIZOR_H_INCLUDED
