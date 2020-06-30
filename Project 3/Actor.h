#ifndef ACTOR_H_INCLUDED
#define ACTOR_H_INCLUDED
#include "Personal.h"
class Actor : public Personal
{
    static std::unordered_map<std::string, int> umap_act;
public:
    Actor(): Personal()
    {

    };
    Actor(std::string cnp ,std::string nume,int suma, std::vector<std::shared_ptr<Film>> f): Personal(cnp, nume, suma, f)
    {
        for(int i=0; i<filme.size(); i++)
        {
            int an=(*filme[i]).get_an();

            std::string a=std::to_string(an);
            if (umap_act.find(a) == umap_act.end())
                umap_act[a]=0;
            else
                umap_act[a]++;
        }
    };
    Actor(const Actor& ob) : Personal(ob.cnp, ob.nume, ob.suma, ob.filme)
    {
        for(int i=0; i<filme.size(); i++)
        {
            int an=(*filme[i]).get_an();

            std::string a=std::to_string(an);
            if (umap_act.find(a) == umap_act.end())
                umap_act[a]=0;
            else
                umap_act[a]++;
        }
    }
    Actor& operator=(Actor& ob)
    {
        cnp=ob.cnp;
        nume=ob.nume;
        suma=ob.suma;
        filme=ob.filme;
        for(int i=0; i<filme.size(); i++)
        {
            int an=(*filme[i]).get_an();

            std::string a=std::to_string(an);
            if (umap_act.find(a) == umap_act.end())
                umap_act[a]=0;
            else
                umap_act[a]++;
        }
        return (*this);
    }
    ~Actor()
    {
        for(int i=0; i<filme.size(); i++)
        {
            int an=(*filme[i]).get_an();

            std::string a=std::to_string(an);
            if (umap_act.find(a) == umap_act.end())
                umap_act[a]=0;
            else
                umap_act[a]++;
        }
    };
    friend std::istream& operator>> (std::istream& in, Actor& ob);
    virtual void afisare() const;
    static int get_umap(int an)
    {
        std::string a=std::to_string(an);
        return umap_act[a];
    }
};
#endif // ACTOR_H_INCLUDED
