

/// Stan Bianca-Mihaela grupa 132
/// rulat cu Codeblocks  g++ C++14
/// Tutore: Lupascu Marian

#ifndef ACHIZITIE_H_INCLUDED
#define ACHIZITIE_H_INCLUDED
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
#include "DezinfectantKiller.h"


using Data = Triplet <int,int,int>;

using Ora = Cuplu <int,int>;


class Achizitie
{
protected:
    Data data;
    std::string nume;
    std::vector<MascaChirurgicala*> masti_chirurgicale;
    std::vector<MascaPolicarbonat*> masti_poli;
    std::vector<DezinfectantBacterii*> dezinfectanti_bacterii;
    std::vector<DezinfectantFungi*> dezinfectanti_fungi;
    std::vector<DezinfectantVirusuri*> dezinfectanti_virus;
    std::vector<DezinfectantKiller*> dezinfectanti_killer;

public:
    Achizitie();
    Achizitie(int, int, int, std::string nume);
    Achizitie(const Achizitie& ob);
    void operator= (const Achizitie& ob);
    friend std::istream& operator>> (std::istream& in, Achizitie& ob);
    friend std::ostream& operator<< (std::ostream& out, const Achizitie& ob);
    ~Achizitie();

    std::vector<Masca*> get_masti() const;
    std::vector<Dezinfectant*> get_dezinfectanti() const;
    Data get_data() const;
    std::string get_nume() const;

    void set_masti(Masca* x);
    void set_dezinfectanti(Dezinfectant* x);
    void set_data(Data x);
    void set_nume(std::string x);
    void clear_masti_chirugicale();
    void clear_masti_poli();
    void clear_dezinfectanti_fungi();
    void clear_dezinfectanti_bacterii();
    void clear_dezinfectanti_virus();
    void clear_dezinfectanti_killer();


    void operator+=(MascaChirurgicala* ob)
    {
        masti_chirurgicale.push_back(ob);
    };
    void operator+=(MascaPolicarbonat* ob)
    {
        masti_poli.push_back(ob);
    };
    void operator+=(Dezinfectant* ob)
    {
        if(DezinfectantKiller* d= dynamic_cast<DezinfectantKiller*> (ob))///am folosit RTTI ca sa rezol ambiguitatea la diamant(ca la Factory Pattern)
            dezinfectanti_killer.push_back(d);
        else if (DezinfectantBacterii* d= dynamic_cast<DezinfectantBacterii*> (ob))
            dezinfectanti_bacterii.push_back(d);
        else if (DezinfectantVirusuri* d= dynamic_cast<DezinfectantVirusuri*> (ob))
            dezinfectanti_virus.push_back(d);
        else if (DezinfectantFungi* d= dynamic_cast<DezinfectantFungi*> (ob))
            dezinfectanti_fungi.push_back(d);
    };


    int calculare_factura()
    {
        int suma=0;
        for(int i=0; i<masti_chirurgicale.size(); i++)
        {
            if((*masti_chirurgicale[i]).get_tip()=="ffp1")
            {
                suma+=5;
            }
            if((*masti_chirurgicale[i]).get_tip()=="ffp2")
            {
                suma+=10;
            }
            if((*masti_chirurgicale[i]).get_tip()=="ffp3")
            {
                suma+=15;
            }
        }
        suma+=masti_poli.size()*20;
        for(int i=0; i<dezinfectanti_bacterii.size(); i++)
        {
            if((*dezinfectanti_bacterii[i]).eficienta()<0.9)
            {
                suma+=10;
            }
            else if((*dezinfectanti_bacterii[i]).eficienta()<0.95)
                suma+=20;

            else if((*dezinfectanti_bacterii[i]).eficienta()<0.975)
                suma+=30;
            else if((*dezinfectanti_bacterii[i]).eficienta()<0.99)
                suma+=40;
            else if((*dezinfectanti_bacterii[i]).eficienta()<0.9999)
                suma+=50;
        }
        for(int i=0; i<dezinfectanti_virus.size(); i++)
        {
            if((*dezinfectanti_virus[i]).eficienta()<0.9)
                suma+=10;
            else if((*dezinfectanti_virus[i]).eficienta()<0.95)
                suma+=20;

            else if((*dezinfectanti_virus[i]).eficienta()<0.975)
                suma+=30;
            else if((*dezinfectanti_virus[i]).eficienta()<0.99)

                suma+=40;
            else if((*dezinfectanti_virus[i]).eficienta()<0.9999)
                suma+=50;

        }
        for(int i=0; i<dezinfectanti_fungi.size(); i++)
        {
            if((*dezinfectanti_fungi[i]).eficienta()<0.9)
                suma+=10;
            else if((*dezinfectanti_fungi[i]).eficienta()<0.95)
                suma+=20;
            else if((*dezinfectanti_fungi[i]).eficienta()<0.975)
                suma+=30;
            else if((*dezinfectanti_fungi[i]).eficienta()<0.99)
                suma+=40;
            else if((*dezinfectanti_fungi[i]).eficienta()<0.9999)
                suma+=50;
        }
        return suma;
    };


    bool operator<(Achizitie& ob)
    {
        if(calculare_factura()<ob.calculare_factura())
            return 1;
        return 0;
    };
    bool operator==(Achizitie& ob)
    {
        if(calculare_factura()==ob.calculare_factura())
            return 1;
        return 0;
    };
};

#endif //ACHIZITIE_H_INCLUDED
