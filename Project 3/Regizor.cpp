#include "Regizor.h"
std::istream& operator>> (std::istream& in, Regizor& ob)
{
    in>>static_cast<Personal&>(ob);
    std::cout<<"\n Introduceti suma fixa pe care o obtine din toate filmele regizate: ";
    in>>ob.suma_fixa;
    return in;
}
void Regizor::afisare() const
{
    std::cout<<"\nRegizorul ";
    (*this).Personal::afisare();
    std::cout<<"Suma fixa pe care o obtine este de "<<suma_fixa<<".\n";
}
