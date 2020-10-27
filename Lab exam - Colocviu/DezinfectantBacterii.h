

/// Stan Bianca-Mihaela grupa 132
/// rulat cu Codeblocks  g++ C++14
/// Tutore: Lupascu Marian
#ifndef DEZINFECTANTBACTERII_H_INCLUDED
#define DEZINFECTANTBACTERII_H_INCLUDED
#include <bits/stdc++.h>
#include "Dezinfectatnt.h"

class DezinfectantBacterii: virtual public Dezinfectant
{
protected:
public:
    DezinfectantBacterii();
    DezinfectantBacterii(int nr_organisme_ucise, std::vector<std::string> ingrediente, std::vector<std::string> suprafete);
    DezinfectantBacterii(const DezinfectantBacterii& ob);
    void operator= (const DezinfectantBacterii& ob);
    friend std::istream& operator>> (std::istream& in, DezinfectantBacterii& ob);
    friend std::ostream& operator<< (std::ostream& out, const DezinfectantBacterii& ob);
    ~DezinfectantBacterii();

    double eficienta()
    {
        return double(nr_organisme_ucise)/pow(10,9);
    }

};

#endif //DEZINFECTANTBACTERII_H_INCLUDED
