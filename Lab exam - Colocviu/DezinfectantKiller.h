#ifndef DEZINFECTANTKILLER_H_INCLUDED
#define DEZINFECTANTKILLER_H_INCLUDED
#include "Dezinfectatnt.h"
#include "DezinfectantBacterii.h"
#include "DezinfectantFungi.h"
#include "DezinfectantVirusuri.h"

class DezinfectantKiller : public DezinfectantBacterii, public DezinfectantFungi, public DezinfectantVirusuri
{
public:
    DezinfectantKiller() : DezinfectantBacterii(), DezinfectantFungi() , DezinfectantVirusuri(){};
    DezinfectantKiller(int nr_organisme_ucise, std::vector<std::string> ingrediente, std::vector<std::string> suprafete):
            DezinfectantVirusuri(nr_organisme_ucise, ingrediente, suprafete), DezinfectantBacterii(nr_organisme_ucise, ingrediente, suprafete), DezinfectantFungi(nr_organisme_ucise, ingrediente, suprafete){};
    DezinfectantKiller(const DezinfectantKiller& ob);
    void operator= (const DezinfectantKiller& ob);
    friend std::istream& operator>> (std::istream& in, DezinfectantKiller& ob)
    {
        operator>>(in, static_cast<DezinfectantBacterii&> (ob));
    }
    friend std::ostream& operator<< (std::ostream& out, DezinfectantKiller& ob)
    {
        operator<<(out, static_cast<DezinfectantBacterii&> (ob));
    }
    ~DezinfectantKiller() {};

    double eficienta()
    {
        //return (double(nr_organisme_ucise))/pow(10,9) + double(nr_organisme_ucise)/(1.5*pow(10, 6)) + ((double)nr_organisme_ucise)/pow(10, 8);
    }
};
#endif // DEZINFECTANTKILLER_H_INCLUDED
