
#include <iostream>
#include <set>
#include <tuple>
#include <typeinfo>
#include <set>
#include "Firma_de_distributie.h"
#include "Film.h"
#include "Personal.h"
#include "Actor.h"
#include "Actor_principal.h"
#include "Regizor.h"
#include "Vector.h"
#include "Interfata.h"

using namespace std;

std::unordered_map<std::string, int> Personal::umap_pers = {{"0", 0}};
std::unordered_map<std::string, int> Actor::umap_act = {{"0", 0}};
std::unordered_map<std::string, int> Actor_principal::umap_actp = {{"0", 0}};
std::unordered_map<int, std::set<Film*> > Film::umap_film ={{0, {nullptr}}};
Interfata* Interfata::instance = nullptr;


template<typename T>
int Firma_de_distributie<T>::nr_persoane=0;

template<typename T>
int Firma_de_distributie<T>::nr_actori=0;

template<typename T>
std::set<Film*> Firma_de_distributie<T>::vf= {{nullptr}};


template<>
int Firma_de_distributie<Actor>::nr_actori_principali=0;

int main()
{

    Film f1("noah", "drama", "02:22", 1000000, 2012);
    Film f3("bami", "fantasy", "02:10", 3000000, 2012);
    Film f2("utah", "comedie", "01:50", 10000, 2006);



    vector<shared_ptr<Film>> v1;
    v1.push_back(make_shared<Film>(f1));
    v1.push_back(make_shared<Film>(f2));

    vector<shared_ptr<Film>> v2;
    v2.push_back(make_shared<Film>(f3));
    v2.push_back(make_shared<Film>(f1));




    Personal p1("1111111111111", "andrei", 600, v1);


    Actor_principal ap1("2222222222222", "marius", 10000, move(v2), 3300);
    Actor_principal ap2("3333333333333", "andreea", 30000, move(v1), 20000);


    Personal* ptr1=&p1;
    Personal* ptr2=&ap1;


    set<tuple<Film*, Personal*, int>> s;

    for(int i=0; i<p1.get_filme().size(); i++)
    {
        int b;
        if(typeid(*ptr1).name()==typeid(ap1).name())
        {
            Actor_principal* ptr=dynamic_cast<Actor_principal*>(ptr1);
            b=(*ptr).get_bonus();
        }
        else b=0;
        Film* f=&(*(p1.get_filme()[i]));
        tuple<Film*, Personal*, int> elem;
        elem=make_tuple(f, ptr1 , b);


        s.insert(elem);

    }

    for(int i=0; i<ap1.get_filme().size(); i++)
    {
        int b;
        if(typeid(*ptr2).name()==typeid(ap1).name())
        {
            Actor_principal* ptr=dynamic_cast<Actor_principal*>(ptr2);
            b=(*ptr).get_bonus();
        }
        else b=0;
        Film* f=&(*(ap1.get_filme()[i]));
        tuple<Film*, Personal*, int> elem;
        elem=make_tuple(f, ptr2 , b);


        s.insert(elem);

    }

    ///afisarea structurii de date
    for_each(s.begin(), s.end(), [](const tuple<Film*, Personal*, int>& tup)
             {
                 cout<<(*(get<0>(tup)));
                (*(get<1>(tup))).afisare();
                cout<<get<2>(tup)<<"\n";
                cout<<"\n\n\n";
             });



    ///exemplificarea la
    cout<<Firma_de_distributie<Film>::creare_obiect(2012);
    cout<<*(Firma_de_distributie<Personal>::creare_obiect(2012));

    ///specializarea pe actor
    Firma_de_distributie<Actor> firma3(2012);
    cout<<firma3;


    ///memorarea a n obiecte
    Interfata::get_instance()->memoreaza_si_afiseaza_n_obiecte();


    return 0;
}
