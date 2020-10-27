/// Stan Bianca-Mihaela grupa 132
/// rulat cu Codeblocks  g++ C++14
/// Tutore: Lupascu Marian

#include "Chirurgicala.h"
Chirurgicala::Chirurgicala() : Masca()
{
}
Chirurgicala::Chirurgicala(std::string tip, std::string culoare, int nr_pliuri) :
        Masca(tip, culoare, nr_pliuri)

{

}

Chirurgicala::Chirurgicala(const Chirurgicala& ob) : Masca(ob)
{


}
void Chirurgicala::operator= (const Chirurgicala& ob)
{
///verifica sa nu ai memory leak de la ce era inainte in obiect
    (*this).Masca::operator=(ob);
}

std::istream& operator>> (std::istream& in, Chirurgicala& ob)
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
std::ostream& operator<< (std::ostream& out, const Chirurgicala& ob)
{
    out<<"tip= "<<ob.tip<<", ";
    out<<"culoare= "<<ob.culoare<<", ";
    out<<"nr_pliuri= "<<ob.nr_pliuri<<", ";
    return out;
}
Chirurgicala::~Chirurgicala()
{
///verifica memory leak
};





