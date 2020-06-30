#ifndef FIRMA_DE_DISTRIBUTIE_H_INCLUDED
#define FIRMA_DE_DISTRIBUTIE_H_INCLUDED
#include <vector>
#include <string>
#include <memory>
#include "Film.h"
#include "Personal.h"
#include "myexception.h"
#include "Actor.h"
#include "Actor_principal.h"
#include "Regizor.h"

//class Personal;

template<typename T>
class Firma_de_distributie
{
    static int nr_persoane;
    static int nr_actori;
    static std::set<Film*> vf;
    int an;
    explicit Firma_de_distributie(int a)
    {
        if(typeid(T).name()!=typeid(Personal).name() && typeid(T).name()!=typeid(Actor).name()
           && typeid(T).name()!=typeid(Actor_principal).name() && typeid(T).name()!=typeid(Regizor).name())
        {
            throw myexception(6);
        }
        else
        {
            nr_persoane=Personal::get_umap(a);
            nr_actori=Actor::get_umap(a);
            vf=Film::get_filme_din_an(a);
            an=a;
        }
    }

public:
    ~Firma_de_distributie()
    {
        for(auto& i: vf)
            delete i;
    };
    static Firma_de_distributie<T>* creare_obiect(int an)
    {
        try
        {
            Firma_de_distributie<T>* f=new Firma_de_distributie<T>(an);
            //Firma_de_distributie<T> f(an);
            return f;

        }
        catch(myexception& e)
        {
            std::cout<<e.what();
            return nullptr;
        }
    }
    friend std::istream& operator>> (std::istream& in, Firma_de_distributie<T>& f)
    {
        std::cout<<"Introduceti anul pentru firma de distributie: ";
        in>>f.an;
    }
    friend std::ostream& operator<< (std::ostream& out, Firma_de_distributie<T>& f)
    {
        out<<"\nIn anul"<<f.an<<" s-au facut filmele: ";
        std::set<Film*>::iterator it;
        for(it=vf.begin(); it!=vf.end(); ++it)
        {
            std::cout<<(*(*it));
        }
        out<<"\nLa aceste filme au participat "<<f.nr_persoane<<" persoane si "<<f.nr_actori<<" actori.\n";
    }
};


template<>
class Firma_de_distributie<Actor>
{
    int an;
    static int nr_actori_principali;
public:
    explicit Firma_de_distributie(int a)
    {
        an=a;
        nr_actori_principali=Actor_principal::get_umap(a);
    }

    ~Firma_de_distributie(){};
    friend std::istream& operator>> (std::istream& in, Firma_de_distributie<Actor>& f)
    {
        std::cout<<"Introduceti anul pentru firma de distributie: ";
        in>>f.an;
    }
    friend std::ostream& operator<< (std::ostream& out, Firma_de_distributie<Actor>& f)
    {
        out<<"\nIn anul "<<f.an<<" au fost "<<f.nr_actori_principali<<" actori care au fost distribuiti in roluri principale.\n";
    }
    static Firma_de_distributie<Actor>* creare_obiect(int an)
    {
        Firma_de_distributie<Actor>* f=new Firma_de_distributie<Actor>(an);
        return f;
    }
};



#endif // FIRMA_DE_DISTRIBUTIE_H_INCLUDED
