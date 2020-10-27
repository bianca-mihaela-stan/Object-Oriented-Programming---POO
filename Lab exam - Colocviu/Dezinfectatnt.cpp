/// Stan Bianca-Mihaela grupa 132
/// rulat cu Codeblocks  g++ C++14
/// Tutore: Lupascu Marian

#include "Dezinfectatnt.h"
Dezinfectant::Dezinfectant() : nr_organisme_ucise(0)
{
}
Dezinfectant::Dezinfectant(std::vector<std::string> ingrediente, std::vector<std::string> suprafete, int nr_organisme_ucise) :
        ingrediente(ingrediente), suprafete(suprafete), nr_organisme_ucise(nr_organisme_ucise)
{


}
Dezinfectant::Dezinfectant(const Dezinfectant& ob) : ingrediente(ob.ingrediente), suprafete(ob.suprafete), nr_organisme_ucise(ob.nr_organisme_ucise)
{


}
void Dezinfectant::operator= (const Dezinfectant& ob)
{

    nr_organisme_ucise=ob.nr_organisme_ucise;
}

std::istream& operator>> (std::istream& in, Dezinfectant& ob)
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
std::ostream& operator<< (std::ostream& out, const Dezinfectant& ob)
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
Dezinfectant::~Dezinfectant()
{
///verifica memory leak
};std::vector<std::string> Dezinfectant::get_ingrediente() const
{
    return ingrediente;
}
std::vector<std::string> Dezinfectant::get_suprafete() const
{
    return suprafete;
}
int Dezinfectant::get_nr_organisme_ucise() const
{
    return nr_organisme_ucise;
}
void Dezinfectant::set_ingrediente(std::string& x)
{
    ingrediente.emplace_back(x);///foloseste move semantics

}
void Dezinfectant::set_suprafete(std::string& x)
{
    suprafete.emplace_back(x);///foloseste move semantics

}
void Dezinfectant::set_nr_organisme_ucise(int x)
{
}




