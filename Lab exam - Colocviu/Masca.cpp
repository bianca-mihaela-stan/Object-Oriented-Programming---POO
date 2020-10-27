/// Stan Bianca-Mihaela grupa 132
/// rulat cu Codeblocks  g++ C++14
/// Tutore: Lupascu Marian

#include "Masca.h"
Masca::Masca() : tip(""), culoare(""), nr_pliuri(0)
{
}
Masca::Masca(std::string tip, std::string culoare, int nr_pliuri) :
        tip(tip), culoare(culoare), nr_pliuri(nr_pliuri)
{


}
Masca::Masca(const Masca& ob) : tip(ob.tip), culoare(ob.culoare), nr_pliuri(ob.nr_pliuri)
{


}
void Masca::operator= (const Masca& ob)
{
///verifica sa nu ai memory leak de la ce era inainte in obiect
    tip=ob.tip;
    culoare=ob.culoare;
    nr_pliuri=ob.nr_pliuri;
}

std::istream& operator>> (std::istream& in, Masca& ob)
{
///verifica memory leak
    std::cout<<"Introduceti tip: ";
    in>>ob.tip;
    std::cout<<"Introduceti culoare: ";
    in>>ob.culoare;
    std::cout<<"Introduceti nr_pliuri: ";
    in>>ob.nr_pliuri;
    return in;
}
std::ostream& operator<< (std::ostream& out, const Masca& ob)
{
    out<<"tip= "<<ob.tip<<", ";
    out<<"culoare= "<<ob.culoare<<", ";
    out<<"nr_pliuri= "<<ob.nr_pliuri<<", ";
    return out;
}
Masca::~Masca()
{
///verifica memory leak
};std::string Masca::get_tip() const
{
    return tip;
}
std::string Masca::get_culoare() const
{
    return culoare;
}
int Masca::get_nr_pliuri() const
{
    return nr_pliuri;
}
void Masca::set_tip(std::string x)
{
    tip=x;
}
void Masca::set_culoare(std::string x)
{
}
void Masca::set_nr_pliuri(int x)
{
}




