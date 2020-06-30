#ifndef ONE_MAN_SHOW_H_INCLUDED
#define ONE_MAN_SHOW_H_INCLUDED

class One_man_show: public Actor_principal, public Regizor
{
    int nr_ore_lucrate;
public:
    One_man_show();
    One_man_show(std::string cnp ,std::string nume,int suma, std::vector<std::shared_ptr<Film>> f,unsigned int bonus, unsigned int suma_fixa, int nr_ore_lucrate)
     : Actor_principal(cnp, nume, suma, f, bonus), Regizor(cnp, nume, suma, f, suma_fixa), nr_ore_lucrate(nr_ore_lucrate) {};
     ~One_man_show();
};

#endif // ONE_MAN_SHOW_H_INCLUDED
