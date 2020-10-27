

/// Stan Bianca-Mihaela grupa 132
/// rulat cu Codeblocks  g++ C++14
/// Tutore: Lupascu Marian

#ifndef AFACERE_H_INCLUDED
#define AFACERE_H_INCLUDED
#include <bits/stdc++.h>
#include "Triplet.h"
#include "Masca.h"
#include "Chirurgicala.h"
#include "Masca.h"
#include "MascaChirurgicala.h"
#include "MascaPolicarbonat.h"
#include "Dezinfectatnt.h"
#include "DezinfectantBacterii.h"
#include "DezinfectantVirusuri.h"
#include "DezinfectantFungi.h"
#include "Achizitie.h"




using Data = Triplet <int,int,int>;

using Ora = Cuplu <int,int>;


class Afacere
{
protected:
    std::vector<DezinfectantBacterii*> stoc_dezinfectanti_bacterii;
    std::vector<DezinfectantVirusuri*> stoc_dezinfectanti_virus;
    std::vector<DezinfectantFungi*> stoc_dezinfectanti_fungi;
    std::vector<DezinfectantKiller*> stoc_dezinfectanti_killer;
    std::vector<MascaChirurgicala*> stoc_masti_chirurgicale;
    std::vector<MascaPolicarbonat*> stoc_masti_poli;
    std::vector<Achizitie*> achizitii;
    static int venit;
    int venit_din_masti_cu_logo;
    Data data_deschidere;
public:
    static Afacere* instance;
    Afacere();
public:
    Afacere(const Afacere&)=delete;
    Afacere& operator=(const Afacere&)=delete;
    static Afacere* get_instance()
    {
        if(!instance)
            instance= new Afacere;
        return instance;
    }
    virtual ~Afacere();

    std::vector<Dezinfectant*> get_stoc_dezinfectanti() const;
    std::vector<Masca*> get_stoc_masti() const;
    std::vector<Achizitie*> get_achizitii() const;
    int get_venit() const;
    int get_venit_din_masti_cu_logo() const;
    Data get_data_deschidere() const;

    void set_stoc_dezinfectanti(Dezinfectant* x);
    void set_stoc_masti(Masca* x);
    void set_achizitii(Achizitie* x);
    void clear_stoc_dezinfectanti_fungi();
    void clear_stoc_dezinfectanti_bacterii();
    void clear_stoc_dezinfectanti_virus();
    void clear_stoc_dezinfectanti_killer();
    void clear_stoc_masti_chirurgicale();
    void clear_stoc_masti_poli();
    void clear_achizitii();

    void adauga_dezinfectant()
    {
        std::cout<<"Introduceti tipul de dezinfectant: 1. bacterii 2.fungi 3.virus 4.killer";
        int x;
        std::cin>>x;
        if(x==1)
        {
            DezinfectantBacterii* ptr= new DezinfectantBacterii;
            std::cin>>(*ptr);
            stoc_dezinfectanti_bacterii.push_back(ptr);
        }
        if(x==2)
        {
            DezinfectantFungi* ptr= new DezinfectantFungi;
            std::cin>>(*ptr);
            stoc_dezinfectanti_fungi.push_back(ptr);
        }
        if(x==3)
        {
            DezinfectantVirusuri* ptr= new DezinfectantVirusuri;
            std::cin>>(*ptr);
            stoc_dezinfectanti_virus.push_back(ptr);
        }
        if(x==4)
        {
            DezinfectantKiller* ptr= new DezinfectantKiller;
            //std::cin>>(*ptr);
            stoc_dezinfectanti_killer.push_back(ptr);
        }
    }

    void adauga_masca()
    {
        std::cout<<"Introduceti tipul mastii: 1.chirurgicala 2.policarbonat ";
        int x=verifica_strinct_pozitiv<int>(std::cin);
        if(x==1)
        {
            MascaChirurgicala* ptr= new MascaChirurgicala;
        std::cin>>(*ptr);
            stoc_masti_chirurgicale.push_back(ptr);
        }
        else if(x==2)
        {
            MascaPolicarbonat* ptr= new MascaPolicarbonat;
            std::cin>>(*ptr);
            stoc_masti_poli.push_back(ptr);
        }
    }


    void adauga_achizitie()
    {
        Achizitie* a= new Achizitie;
        std::cin>>(*a);
        achizitii.push_back(a);
        venit+=(*a).calculare_factura();
    }

    void cel_mai_eficient()
    {

    }

    void venitul_din_luna(int luna)
    {
        int suma=0;
        for(int i=0; i<achizitii.size(); i++)
        {
            if((*achizitii[i]).get_data().get_second()==luna)
            {
                suma+=(*achizitii[i]).calculare_factura();
            }
        }
        std::cout<<"Venitul din luna este: "<<suma<<"\n";
    }


    void cle_mai_fidel_client()
    {
        int maxx=0;
        std::unordered_map<std::string, int> umap;
        for(int i=0; i<achizitii.size(); i++)
        {
            umap[(*achizitii[i]).get_nume()]++;
            maxx=std::max(maxx, umap[(*achizitii[i]).get_nume()]);
        }
        for(int i=0; i<achizitii.size(); i++)
        {
            if(umap[(*achizitii[i]).get_nume()]==maxx)
                std::cout<<(*achizitii[i]).get_nume();
        }

    }

    void afisare_venit()
    {
        std::cout<<venit;
    }



};

#endif //AFACERE_H_INCLUDED
