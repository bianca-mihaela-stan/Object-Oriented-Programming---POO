/// Stan Bianca-Mihaela grupa 132
/// rulat cu Codeblocks  g++ C++14
/// Tutore: Lupascu Marian

#include "Afacere.h"
Afacere::Afacere()
{

}
Afacere::~Afacere()
{
    clear_stoc_dezinfectanti_fungi();
    clear_stoc_dezinfectanti_bacterii();
    clear_stoc_dezinfectanti_virus();
    clear_stoc_dezinfectanti_killer();
    clear_stoc_masti_chirurgicale();
    clear_stoc_masti_poli();
}


//std::vector<Dezinfectant*> Afacere::get_stoc_dezinfectanti_fungi() const
//{
//    return stoc_dezinfectanti;
//}
//std::vector<Masca*> Afacere::get_stoc_masti() const
//{
//    return stoc_masti;
//}
//std::vector<Achizitie*> Afacere::get_achizitii() const
//{
//    return achizitii;
//}
//int Afacere::get_venit() const
//{
//    return venit;
//}
//int Afacere::get_venit_din_masti_cu_logo() const
//{
//    return venit_din_masti_cu_logo;
//}
//Data Afacere::get_data_deschidere() const
//{
//    return data_deschidere;
//}
//void Afacere::set_stoc_dezinfectanti(Dezinfectant* x)
//{
//    stoc_dezinfectanti.emplace_back(x);///foloseste move semantics
//
//}
//void Afacere::set_stoc_masti(Masca* x)
//{
//    stoc_masti.emplace_back(x);///foloseste move semantics
//
//}
//void Afacere::set_achizitii(Achizitie* x)
//{
//    achizitii.emplace_back(x);///foloseste move semantics
//
//}
void Afacere::clear_stoc_dezinfectanti_fungi()
{
    for(int i=0; i<stoc_dezinfectanti_fungi.size(); i++)
    {
        delete stoc_dezinfectanti_fungi[i];
    }
    stoc_dezinfectanti_fungi.clear();
}
void Afacere::clear_stoc_dezinfectanti_virus()
{
    for(int i=0; i<stoc_dezinfectanti_virus.size(); i++)
    {
        delete stoc_dezinfectanti_virus[i];
    }
    stoc_dezinfectanti_virus.clear();
}
void Afacere::clear_stoc_dezinfectanti_bacterii()
{
    for(int i=0; i<stoc_dezinfectanti_bacterii.size(); i++)
    {
        delete stoc_dezinfectanti_bacterii[i];
    }
    stoc_dezinfectanti_bacterii.clear();
}
void Afacere::clear_stoc_dezinfectanti_killer()
{
    for(int i=0; i<stoc_dezinfectanti_killer.size(); i++)
    {
        delete stoc_dezinfectanti_killer[i];
    }
    stoc_dezinfectanti_killer.clear();
}
void Afacere::clear_stoc_masti_chirurgicale()
{
    for(int i=0; i<stoc_masti_chirurgicale.size(); i++)
    {
        delete stoc_masti_chirurgicale[i];
    }
    stoc_masti_chirurgicale.clear();
}
void Afacere::clear_stoc_masti_poli()
{
    for(int i=0; i<stoc_masti_poli.size(); i++)
    {
        delete stoc_masti_poli[i];
    }
    stoc_masti_poli.clear();
}
void Afacere::clear_achizitii()
{
    for(int i=0; i<achizitii.size(); i++)
    {
        delete achizitii[i];
    }
    achizitii.clear();
}




