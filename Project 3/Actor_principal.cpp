#include "Actor_principal.h"
std::istream& operator>> (std::istream& in, Actor_principal& ob)
{
    in>>static_cast<Actor&>(ob);
    std::vector<std::shared_ptr<Film>>::iterator it;
    for(it=ob.filme.begin(); it<ob.filme.end(); it++)
    {
        ob.bonus+=(*(*it)).get_incasari()*0.1;
    }
    return in;
}

void Actor_principal::afisare() const
{
    std::cout<<"Actorul principal ";
    (*this).Actor::afisare();
    std::cout<<"Bonusul lui este de "<<bonus<<".\n";
}


unsigned int Actor_principal::get_bonus() const
{
    return bonus;
}
