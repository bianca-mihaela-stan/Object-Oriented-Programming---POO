#include "Personal.h"

std::istream& operator>> (std::istream& in, Personal& ob)
{
    try
    {
        std::string s;
        std::cout<<"Introduceti numele: ";
        in>>ob.nume;
        std::cout<<"\nIntroduceti CNP-ul: ";
        in>>s;
        if(s.size()!=13)
            throw myexception(3);
        std::string::iterator p= find_if(s.begin(), s.end(), [](char t)
        {
            return !(t>='0' && t<='9');
        });
        if(p!=s.end())
            throw myexception(3);
        ob.cnp=s;
        std::cout<<"\nIntroduceti numarul de filme la care participa: ";
        int n=0;
        in>>n;
        for(int i=1; i<=n; i++)
        {
            Film b;
            in>>b;
            auto u=std::make_shared<Film>(b);
            ob.filme.emplace_back(u);
        }
        std::cout<<"\nIntroduceti suma pe care o castiga(salariul) : ";
        in>>ob.suma;
    }
    catch(myexception& e)
    {
        std::cout<<e.what();
    }
    return in;
}
void Personal::afisare() const
{
    std::cout<<nume<<", cu CNP "<<cnp<<", a lucrat la: \n";
    for(int i=0; i<filme.size(); i++)
    {
        std::cout<<*(filme[i])<<" ";
    }
    std::cout<<" si castiga "<<suma<<".\n";
}

std::vector<std::shared_ptr<Film>> Personal::get_filme() const
{
    return filme;
}

