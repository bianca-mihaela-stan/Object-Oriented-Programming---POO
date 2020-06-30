#ifndef ACTOR_PRINCIPAL_H_INCLUDED
#define ACTOR_PRINCIPAL_H_INCLUDED
#include "Actor.h"
class Actor_principal: virtual public Actor
{
    unsigned int bonus;
    static std::unordered_map<std::string, int> umap_actp;
public:
    Actor_principal() : Actor(), bonus(0)
    {
        for(int i=0; i<filme.size(); i++)
        {
            int an=(*filme[i]).get_an();

            std::string a=std::to_string(an);
            if (umap_actp.find(a) == umap_actp.end())
                umap_actp[a]=0;
            else
                umap_actp[a]++;
        }
    };
    Actor_principal(std::string cnp ,std::string nume,int suma, std::vector<std::shared_ptr<Film>> f,unsigned int bonus): Actor(cnp, nume, suma, f), bonus(bonus)
    {
        for(int i=0; i<filme.size(); i++)
        {
            int an=(*filme[i]).get_an();

            std::string a=std::to_string(an);
            if (umap_actp.find(a) == umap_actp.end())
                umap_actp[a]=0;
            else
                umap_actp[a]++;
        }
    };
    Actor_principal(const Actor_principal& ob) : Actor(ob), bonus(ob.bonus)
    {
        for(int i=0; i<filme.size(); i++)
        {
            int an=(*filme[i]).get_an();

            std::string a=std::to_string(an);
            if (umap_actp.find(a) == umap_actp.end())
                umap_actp[a]=0;
            else
                umap_actp[a]++;
        }
    }
    ~Actor_principal()
    {
        for(int i=0; i<filme.size(); i++)
        {
            int an=(*filme[i]).get_an();

            std::string a=std::to_string(an);
            if (umap_actp.find(a) == umap_actp.end())
                umap_actp[a]=0;
            else
                umap_actp[a]--;
        }
    };
    friend std::istream& operator>> (std::istream& in, Actor_principal& ob);
    void afisare() const;
    unsigned int get_bonus() const;
    static int get_umap(int an)
    {
        std::string a=std::to_string(an);
        return umap_actp[a];
    }
};


#endif // ACTOR_PRINCIPAL_H_INCLUDED
