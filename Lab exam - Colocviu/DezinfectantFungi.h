

/// Stan Bianca-Mihaela grupa 132
/// rulat cu Codeblocks  g++ C++14
/// Tutore: Lupascu Marian

#ifndef DEZINFECTANTFUNGI_H_INCLUDED
#define DEZINFECTANTFUNGI_H_INCLUDED
#include <bits/stdc++.h>
#include "Dezinfectatnt.h"

class DezinfectantFungi: virtual public Dezinfectant
{
protected:
public:
    DezinfectantFungi();
    DezinfectantFungi(int nr_organisme_ucise, std::vector<std::string> ingrediente, std::vector<std::string> suprafete);
    DezinfectantFungi(const DezinfectantFungi& ob);
    void operator= (const DezinfectantFungi& ob);
    friend std::istream& operator>> (std::istream& in, DezinfectantFungi& ob);
    friend std::ostream& operator<< (std::ostream& out, const DezinfectantFungi& ob);
    ~DezinfectantFungi();

    double eficienta()
    {
        return double(nr_organisme_ucise)/(1.5*pow(10, 6));
    }

};

#endif //DEZINFECTANTFUNGI_H_INCLUDED
