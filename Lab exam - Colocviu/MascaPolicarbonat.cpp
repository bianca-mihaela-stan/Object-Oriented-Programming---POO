

#include "MascaPolicarbonat.h"
MascaPolicarbonat::MascaPolicarbonat() : Masca(), tip_prindere("")
{
}
MascaPolicarbonat::MascaPolicarbonat(std::string tip, std::string culoare, int nr_pliuri, std::string tip_prindere) :
        Masca(tip, culoare, nr_pliuri), tip_prindere(tip_prindere)
{


}
MascaPolicarbonat::MascaPolicarbonat(std::string tip_prindere) : tip_prindere(tip_prindere)
{

}
MascaPolicarbonat::MascaPolicarbonat(const MascaPolicarbonat& ob) : Masca(ob), tip_prindere(ob.tip_prindere)
{


}
void MascaPolicarbonat::operator= (const MascaPolicarbonat& ob)
{
///verifica sa nu ai memory leak de la ce era inainte in obiect
    (*this).Masca::operator=(ob);
    tip_prindere=ob.tip_prindere;
}

std::istream& operator>> (std::istream& in, MascaPolicarbonat& ob)
{
///verifica memory leak
    std::cout<<"Introduceti tip_prindere: ";
    in>>ob.tip_prindere;
    ob.set_tip("ffp0");
    std::cout<<"Introduceti culoare: ";
    in>>ob.culoare;
    std::cout<<"Introduceti nr_pliuri: ";
    in>>ob.nr_pliuri;
    return in;
}
std::ostream& operator<< (std::ostream& out, const MascaPolicarbonat& ob)
{
    out<<"tip_prindere= "<<ob.tip_prindere<<", ";
    out<<"tip= "<<ob.tip<<", ";
    out<<"culoare= "<<ob.culoare<<", ";
    out<<"nr_pliuri= "<<ob.nr_pliuri<<", ";
    return out;
}
MascaPolicarbonat::~MascaPolicarbonat()
{
///verifica memory leak
};

std::string MascaPolicarbonat::get_tip_prindere() const
{
    return tip_prindere;
}
void MascaPolicarbonat::set_tip_prindere(std::string x)
{
}




