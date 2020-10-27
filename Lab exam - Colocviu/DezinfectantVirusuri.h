

/// Stan Bianca-Mihaela grupa 132
/// rulat cu Codeblocks  g++ C++14
/// Tutore: Lupascu Marian

#ifndef DEZINFECTANTVIRUSURI_H_INCLUDED
#define DEZINFECTANTVIRUSURI_H_INCLUDED
#include <bits/stdc++.h>
#include "Dezinfectatnt.h"

class DezinfectantVirusuri: virtual public Dezinfectant
{
protected:
public:
    DezinfectantVirusuri();
    DezinfectantVirusuri(int nr_organisme_ucise, std::vector<std::string> ingrediente, std::vector<std::string> suprafete);
    DezinfectantVirusuri(const DezinfectantVirusuri& ob);
    void operator= (const DezinfectantVirusuri& ob);
    friend std::istream& operator>> (std::istream& in, DezinfectantVirusuri& ob);
    friend std::ostream& operator<< (std::ostream& out, const DezinfectantVirusuri& ob);
    ~DezinfectantVirusuri();

    double eficienta()
    {
        return ((double)nr_organisme_ucise)/pow(10, 8);
    }

};

#endif //DEZINFECTANTVIRUSURI_H_INCLUDED
