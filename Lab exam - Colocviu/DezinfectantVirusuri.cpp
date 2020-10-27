/// Stan Bianca-Mihaela grupa 132
/// rulat cu Codeblocks  g++ C++14
/// Tutore: Lupascu Marian

#include "DezinfectantVirusuri.h"
DezinfectantVirusuri::DezinfectantVirusuri() : Dezinfectant()
{
}
DezinfectantVirusuri::DezinfectantVirusuri(int nr_organisme_ucise, std::vector<std::string> ingrediente, std::vector<std::string> suprafete) :
        Dezinfectant(ingrediente, suprafete, nr_organisme_ucise)
{

}


DezinfectantVirusuri::DezinfectantVirusuri(const DezinfectantVirusuri& ob) : Dezinfectant(ob)
{


}
void DezinfectantVirusuri::operator= (const DezinfectantVirusuri& ob)
{
///verifica sa nu ai memory leak de la ce era inainte in obiect
    (*this).Dezinfectant::operator=(ob);
}

std::istream& operator>> (std::istream& in, DezinfectantVirusuri& ob)
{
///verifica memory leak
    std::cout<<"Introduceti nr_organisme_ucise: ";
    in>>ob.nr_organisme_ucise;
    std::cout<<"Introduceti nr ingrediente: ";
    int n;
    in>>n;
    for(int i=0; i<n; i++)
    {
        std::cout<<"Introduceti ingrediente: ";
        std::string x;
        std::cin.get();
        getline(std::cin, x);
        //in>>x;
        ob.ingrediente.push_back(x);
    }
    std::cout<<"Introduceti nr suprafete: ";
    in>>n;
    for(int i=0; i<n; i++)
    {
        std::cout<<"Introduceti suprafete: ";
        std::string x;
        in>>x;
        ob.suprafete.push_back(x);
    }
    return in;
}
std::ostream& operator<< (std::ostream& out, const DezinfectantVirusuri& ob)
{
    out<<"nr_organisme_ucise= "<<ob.nr_organisme_ucise<<", ";
    for(int i=0; i<ob.ingrediente.size(); i++)
    {
        out<<ob.ingrediente[i]<<", ";
    }
    for(int i=0; i<ob.suprafete.size(); i++)
    {
        out<<ob.suprafete[i]<<", ";
    }
    return out;
}
DezinfectantVirusuri::~DezinfectantVirusuri()
{
///verifica memory leak
};





