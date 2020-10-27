/// Stan Bianca-Mihaela grupa 132
/// rulat cu Codeblocks  g++ C++14
/// Tutore: Lupascu Marian

#include "Achizitie.h"
Achizitie::Achizitie() : data(Data(0,0,0)), nume("")
{
}
Achizitie::Achizitie(int x, int y, int z, std::string nume) :
        data(Data(x, y, z)), nume(nume)
{


}
Achizitie::Achizitie(const Achizitie& ob) : data(ob.data), nume(ob.nume)
{
    for(int i=0; i<ob.masti_chirurgicale.size(); i++)
    {
        masti_chirurgicale.push_back(&(*ob.masti_chirurgicale[i]));
    }
    for(int i=0; i<ob.masti_poli.size(); i++)
    {
        masti_poli.push_back(&(*ob.masti_poli[i]));
    }
    for(int i=0; i<ob.dezinfectanti_bacterii.size(); i++)
    {
        dezinfectanti_bacterii.push_back(&(*ob.dezinfectanti_bacterii[i]));
    }
    for(int i=0; i<ob.dezinfectanti_fungi.size(); i++)
    {
        dezinfectanti_fungi.push_back(&(*ob.dezinfectanti_fungi[i]));
    }
    for(int i=0; i<ob.dezinfectanti_virus.size(); i++)
    {
        dezinfectanti_virus.push_back(&(*ob.dezinfectanti_virus[i]));
    }
    for(int i=0; i<ob.dezinfectanti_killer.size(); i++)
    {
        dezinfectanti_killer.push_back(&(*ob.dezinfectanti_killer[i]));
    }


}
void Achizitie::operator= (const Achizitie& ob)
{
///verifica sa nu ai memory leak de la ce era inainte in obiect
    clear_masti_chirugicale();
    clear_masti_poli();

    clear_dezinfectanti_virus();
    clear_dezinfectanti_killer();
    clear_dezinfectanti_bacterii();
    clear_dezinfectanti_fungi();
    for(int i=0; i<ob.masti_chirurgicale.size(); i++)
    {
        masti_chirurgicale.push_back(&(*ob.masti_chirurgicale[i]));
    }
    for(int i=0; i<ob.masti_poli.size(); i++)
    {
        masti_poli.push_back(&(*ob.masti_poli[i]));
    }

    for(int i=0; i<ob.dezinfectanti_bacterii.size(); i++)
    {
        dezinfectanti_bacterii.push_back(&(*ob.dezinfectanti_bacterii[i]));
    }
    for(int i=0; i<ob.dezinfectanti_fungi.size(); i++)
    {
        dezinfectanti_fungi.push_back(&(*ob.dezinfectanti_fungi[i]));
    }
    for(int i=0; i<ob.dezinfectanti_virus.size(); i++)
    {
        dezinfectanti_virus.push_back(&(*ob.dezinfectanti_virus[i]));
    }
    for(int i=0; i<ob.dezinfectanti_killer.size(); i++)
    {
        dezinfectanti_killer.push_back(&(*ob.dezinfectanti_killer[i]));
    }
    data=ob.data;
    nume=ob.nume;
}

std::istream& operator>> (std::istream& in, Achizitie& ob)
{
///verifica memory leak
    std::cout<<"Introduceti data: ";
    in>>ob.data;
    std::cout<<"Introduceti nume: ";
    in>>ob.nume;
    std::cout<<"Introduceti nr masti: ";
    int n;
    in>>n;
    for(int i=0; i<n; i++)
    {
        std::cout<<"Introduceti tipul mastii: 1.chirurgicala 2.policarbonat ";
        int x;
        in>>x;
        if(x==1)
        {
            MascaChirurgicala* ptr= new MascaChirurgicala;
            in>>(*ptr);
            ob.masti_chirurgicale.push_back(ptr);
        }
        else if(x==2)
        {
            MascaPolicarbonat* ptr= new MascaPolicarbonat;
            in>>(*ptr);
            ob.masti_poli.push_back(ptr);
        }
    }
    std::cout<<"Introduceti nr dezinfectanti: ";
    in>>n;
    for(int i=0; i<n; i++)
    {
        std::cout<<"Introduceti tipul de dezinfectant: 1. bacterii 2.fungi 3.virus 4.killer";
        int x;
        in>>x;
        if(x==1)
        {
            DezinfectantBacterii* ptr= new DezinfectantBacterii;
            in>>(*ptr);
            ob.dezinfectanti_bacterii.push_back(ptr);
        }
        if(x==2)
        {
            DezinfectantFungi* ptr= new DezinfectantFungi;
            in>>(*ptr);
            ob.dezinfectanti_fungi.push_back(ptr);
        }
        if(x==3)
        {
            DezinfectantVirusuri* ptr= new DezinfectantVirusuri;
            in>>(*ptr);
            ob.dezinfectanti_virus.push_back(ptr);
        }
        if(x==4)
        {
//            DezinfectantKiller* ptr= new DezinfectantKiller;
//            in>>(*ptr);
//            ob.dezinfectanti_killer.push_back(ptr);
        }
    }
    return in;
}
std::ostream& operator<< (std::ostream& out, const Achizitie& ob)
{
    out<<"data= "<<ob.data<<", ";
    out<<"nume= "<<ob.nume<<", ";
    for(int i=0; i<ob.masti_chirurgicale.size(); i++)
    {
        out<<(*ob.masti_chirurgicale[i])<<", ";
    }
    for(int i=0; i<ob.masti_poli.size(); i++)
    {
        out<<(*ob.masti_poli[i])<<", ";
    }

    for(int i=0; i<ob.dezinfectanti_fungi.size(); i++)
    {
        out<<(*ob.dezinfectanti_fungi[i])<<", ";
    }
    for(int i=0; i<ob.dezinfectanti_virus.size(); i++)
    {
        out<<(*ob.dezinfectanti_virus[i])<<", ";
    }
    for(int i=0; i<ob.dezinfectanti_killer.size(); i++)
    {
        out<<(*ob.dezinfectanti_killer[i])<<", ";
    }
    return out;
}
Achizitie::~Achizitie()
{
    clear_dezinfectanti_bacterii();
    clear_dezinfectanti_fungi();
    clear_dezinfectanti_killer();
    clear_dezinfectanti_virus();
    clear_masti_chirugicale();
    clear_masti_poli();

};

//std::vector<Masca*> Achizitie::get_masti() const
//{
//    return masti;
//}
//std::vector<Dezinfectant*> Achizitie::get_dezinfectanti() const
//{
//    return dezinfectanti;
//}
Data Achizitie::get_data() const
{
    return data;
}
std::string Achizitie::get_nume() const
{
    return nume;
}
//void Achizitie::set_masti(Masca* x)
//{
//    masti.emplace_back(x);///foloseste move semantics
//
//}
//void Achizitie::set_dezinfectanti(Dezinfectant* x)
//{
//    dezinfectanti.emplace_back(x);///foloseste move semantics
//
//}
//void Achizitie::set_data(Data x)
//{
//}
//void Achizitie::set_nume(std::string x)
//{
//}
void Achizitie::clear_masti_chirugicale()
{
    for(int i=0; i<masti_chirurgicale.size(); i++)
    {
        delete masti_chirurgicale[i];
    }
    masti_chirurgicale.clear();
}
void Achizitie::clear_masti_poli()
{
    for(int i=0; i<masti_poli.size(); i++)
    {
        delete masti_poli[i];
    }
    masti_poli.clear();
}
void Achizitie::clear_dezinfectanti_bacterii()
{
    for(int i=0; i<dezinfectanti_bacterii.size(); i++)
    {
        delete dezinfectanti_bacterii[i];
    }
    dezinfectanti_bacterii.clear();
}
void Achizitie::clear_dezinfectanti_virus()
{
    for(int i=0; i<dezinfectanti_virus.size(); i++)
    {
        delete dezinfectanti_virus[i];
    }
    dezinfectanti_virus.clear();
}
void Achizitie::clear_dezinfectanti_fungi()
{
    for(int i=0; i<dezinfectanti_fungi.size(); i++)
    {
        delete dezinfectanti_fungi[i];
    }
    dezinfectanti_fungi.clear();
}
void Achizitie::clear_dezinfectanti_killer()
{
    for(int i=0; i<dezinfectanti_killer.size(); i++)
    {
        delete dezinfectanti_killer[i];
    }
    dezinfectanti_killer.clear();
}

