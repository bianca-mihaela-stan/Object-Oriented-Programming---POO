#ifndef INTERFATA_H_INCLUDED
#define INTERFATA_H_INCLUDED
class Interfata
{
private:
    static Interfata* instance;
    Interfata(){};
public:
    Interfata(const Interfata&) =delete;
    Interfata& operator=(const Interfata&)=delete;
    static Interfata* get_instance()
    {
        if (instance == nullptr) {
            instance = new Interfata();
        }
        return instance;
    }
    ~Interfata() {};

    std::vector<std::shared_ptr<Film>>& creeaza_un_vector_de_filme()
    {
        std::cout<<"Introduceti cate filme: ";
        std::vector<std::shared_ptr<Film>> v;
        int n;
        std::cin>>n;
        for(int i=0; i<n; i++)
        {
            Film f;
            std::cin>>f;
            v.emplace_back(std::make_shared<Film>(f));
        }
        return v;
    }

    Personal* creeaza_personal()
    {
        Personal p;
        std::cin>>p;
        Personal* ptr=&p;
        return ptr;
    }
    Personal* creeaza_actor()
    {
        Actor p;
        std::cin>>p;
        Personal* ptr=&p;
        return ptr;
    }

    Personal* creeaza_actor_principal()
    {
        Actor_principal p;
        std::cin>>p;
        Personal* ptr=&p;
        return ptr;
    }

    Personal* creeaza_regizor()
    {
        Regizor p;
        std::cin>>p;
        Personal* ptr=&p;
        return ptr;
    }

    void memoreaza_si_afiseaza_n_obiecte()
    {
        Vector<Regizor> r;
        std::cin>>r;
        std::cout<<r;

        Vector<Personal> pers;
        std::cin>>pers;
        std::cout<<pers;

        Vector<Actor> aap;
        std::cin>>aap;
        std::cout<<aap;

        Vector<Actor_principal> app;
        std::cin>>app;
        std::cout<<app;
    }

};

#endif // INTERFATA_H_INCLUDED
