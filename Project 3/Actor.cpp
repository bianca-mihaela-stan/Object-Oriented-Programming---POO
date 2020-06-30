#include "Actor.h"
std::istream& operator>> (std::istream& in, Actor& ob)
{
    in>>static_cast<Personal&>(ob);
    return in;
}

void Actor::afisare() const
{
    std::cout<<"Actorul ";
    (*this).Personal::afisare();
}
