#ifndef PERSONAL_H_INCLUDED
#define PERSONAL_H_INCLUDED
#include "Film.h"
#include <memory>
#include <unordered_map>
class Personal
{
protected:
    std::string cnp;
    std::string nume;
    std::vector <std::shared_ptr<Film>> filme;
    static std::unordered_map<std::string, int> umap_pers;///un dictionar in in care o sa am cate persoane lucreaza la filme dintr-un anumit an
    int suma;
public:
    ///de fiecare data cand se creeaza un obiect trebuie sa se incrementeze
    ///Firma_de_distributie<Personal>::nr_persoane++;
    Personal(): cnp(""), nume(""), suma(0) {};
    Personal(std::string cnp ,std::string nume,int suma, std::vector<std::shared_ptr<Film>> f) : cnp(cnp), nume(nume), suma(suma), filme(f)
    {
        for(int i=0; i<filme.size(); i++)
        {
            int an=(*filme[i]).get_an();

            std::string a=std::to_string(an);
            if (umap_pers.find(a) == umap_pers.end())
                umap_pers[a]=0;
            else
                umap_pers[a]++;
        }
    };
    Personal(const Personal& ob): cnp(ob.cnp), nume(ob.nume), suma(ob.suma), filme(ob.filme)
    {
        for(int i=0; i<filme.size(); i++)
        {
            int an=(*filme[i]).get_an();

            std::string a=std::to_string(an);
            if (umap_pers.find(a) == umap_pers.end())
                umap_pers[a]=0;
            else
                umap_pers[a]++;
        }
    };
    Personal& operator= (Personal& ob)
    {
        cnp=ob.cnp;
        nume=ob.nume;
        filme=ob.filme;
        suma=ob.suma;
        for(int i=0; i<filme.size(); i++)
        {
            int an=(*filme[i]).get_an();

            std::string a=std::to_string(an);
            if (umap_pers.find(a) == umap_pers.end())
                umap_pers[a]=0;
            else
                umap_pers[a]++;
        }
        return (*this);
    }
    ~Personal()
    {
        for(int i=0; i<filme.size(); i++)
        {
            int an=(*filme[i]).get_an();

            std::string a=std::to_string(an);
            umap_pers[a]--;
        }
    };

    friend std::istream& operator>> (std::istream& in, Personal& ob);
    virtual void afisare() const;
    std::vector<std::shared_ptr<Film>> get_filme() const;
    static int get_umap(int an)
    {
        std::string a=std::to_string(an);
        return umap_pers[a];
    }
};

//unsigned int Personal::nr_instante=0;


#endif // PERSONAL_H_INCLUDED
