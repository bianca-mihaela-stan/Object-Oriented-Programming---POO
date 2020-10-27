/// Stan Bianca-Mihaela grupa 132
/// rulat cu Codeblocks  g++ C++14
/// Tutore: Lupascu Marian

#include "MascaChirurgicala.h"
MascaChirurgicala::MascaChirurgicala() : Masca()
{
}
MascaChirurgicala::MascaChirurgicala(std::string tip, std::string culoare, int nr_pliuri) :
        Masca(tip, culoare, nr_pliuri)
{

}


MascaChirurgicala::MascaChirurgicala(const MascaChirurgicala& ob) : Masca(ob)
{


}
void MascaChirurgicala::operator= (const MascaChirurgicala& ob)
{
///verifica sa nu ai memory leak de la ce era inainte in obiect
    (*this).Masca::operator=(ob);
}

std::istream& operator>> (std::istream& in, MascaChirurgicala& ob)
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
std::ostream& operator<< (std::ostream& out, const MascaChirurgicala& ob)
{
    out<<"tip= "<<ob.tip<<", ";
    out<<"culoare= "<<ob.culoare<<", ";
    out<<"nr_pliuri= "<<ob.nr_pliuri<<", ";
    return out;
}
MascaChirurgicala::~MascaChirurgicala()
{
///verifica memory leak
};





