#ifndef FILM_H_INCLUDED
#define FILM_H_INCLUDED
#include <bits/stdc++.h>
#include "myexception.h"
class Film
{
protected:
    std::string nume;
    std::string tip;
    std::string durata;
    unsigned int an;
    unsigned int incasari;
    static std::unordered_map<int, std::set<Film*> > umap_film;
public:
    Film(std::string nume="", std::string tip="", std::string durata="", int incasari=0, int an=0) : nume(nume), tip(tip), durata(durata), incasari(incasari), an(an)
    {
        umap_film[an].insert(this);
    };
    Film(const Film& ob) : nume(ob.nume), tip(ob.tip), durata(ob.durata), an(ob.an), incasari(ob.incasari) {};
    Film& operator=(Film& ob)
    {
        nume=ob.nume;
        tip=ob.tip;
        durata=ob.durata;
        an=ob.an;
        incasari=ob.incasari;
        return(*this);
    }
    ~Film()
    {
        umap_film[an].erase(this);
    }
    friend std::istream& operator>> (std::istream& in, Film& ob);
    friend std::ostream& operator<< (std::ostream& out, const Film& ob);
    unsigned int get_incasari() const;
    unsigned int get_an() const;
    static std::set<Film*>& get_filme_din_an(int an)
    {
        return umap_film[an];
    }
};
#endif // FILM_H_INCLUDED
