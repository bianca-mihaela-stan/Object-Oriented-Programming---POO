## Tema 7. 
La realizarea unui film(nume,tip,durata), participa o mulțime de persoane: un
regizor, actori, personal tehnic etc. Fiecare personal (cnp, nume, nume_film) are prevăzut
prin contract un procent din încasări, drept urmare primește, pentru fiecare film la care
participa, o anumită suma. Actorii, dacă sunt personaje principale, primesc un bonus de 10%
din încasări, iar regizorul are prevăzut și o suma fixa, indiferent de calitatea filmului produs.
Structura de date: set<tuple<persoana, film, bonus>>
Cerința suplimentară:
- Să se adauge toate campurile relevante pentru modelarea acestei probleme.
- Sa se construiască clasa template FirmaDistributie care sa conțină informații despre filmele
realizate într-un an. Clasa conțină numărul total de persoane implicat incrementat automat),
numărul de actori (incrementat automat) și o structura de obiecte, alocată dinamic.
- Să se realizeze o specializare pentru tipul Actor, care sa conțină numărul actorilor care au
fost distribuiți în roluri principale.


Cerinte:

- [x] utilizarea sabloanelor
````
template<typename T>
class Firma_de_distributie
````
- [x] utilizarea STL
````
set<tuple<Film*, Personal*, int>> s;
````
- [x] utilizarea variabilelor, funcțiilor statice, constantelor și a unei functii const
````
static std::unordered_map<int, std::set<Film*> > umap_film;
static std::set<Film*>& get_filme_din_an(int an)
{
    return umap_film[an];
}
const Film& ob;
unsigned int get_incasari() const;
````
- [x] utilizarea conceptelor de RTTI raportat la template-uri
````
if(typeid(T).name()!=typeid(Personal).name() && typeid(T).name()!=typeid(Actor).name()
           && typeid(T).name()!=typeid(Actor_principal).name() && typeid(T).name()!=typeid(Regizor).name())
````
- [x] tratarea excepțiilor
````
class myexception: virtual public std::exception
{
public:
    char* error_message;
    explicit myexception(int i)
    .....
````
- [x] citirea informațiilor complete a n obiecte, memorarea și afișarea acestora
- [x] clasele să conțină constructori, destructori, =, funcție prietena de citire a datelor
- [x] clasa de baza sa conțină funcție virtuala de afisare, rescrisa în clasele derivate
````
virtual void afisare() const;
````
- [x] operatorul de citire să fie implementat ca funcție prieten (în clasele derivate să se facă
referire la implementarea acestuia în clasa de baza)
````
std::istream& operator>> (std::istream& in, Regizor& ob)
{
    in>>static_cast<Personal&>(ob);
    std::cout<<"\n Introduceti suma fixa pe care o obtine din toate filmele regizate: ";
    in>>ob.suma_fixa;
}
````

### BONUS:
- [x] **lambda functions**
```[](const tuple<Film*, Personal*, int>& tup)
             {
                 cout<<(*(get<0>(tup)));
                (*(get<1>(tup))).afisare();
                cout<<get<2>(tup)<<"\n";
                cout<<"\n\n\n";
             }
````
- [x] **smart pointers**
````
std::vector <std::shared_ptr<Film>> filme;
````
- [x] **move semantics**
````
Actor_principal ap1("2222222222222", "marius", 10000, move(v2), 3300);
Actor_principal ap2("3333333333333", "andreea", 30000, move(v1), 20000);
ob.filme.emplace_back(u);
````
- [x] **diamond inheritance**
````
              Personal
                /     \
               /       \
          Actor        Regizor
            |             |
            |             |
    Actor_principal       |
            \             /
             \           /
              \         /
              One_man_show
````
- [x] **Named Constructor Idiom** (ascunderea constrctorului in clasa template Firma_de_distributie si crearea de obiecte prin intermediul
metodei:
````
static Firma_de_distributie<T>* creare_obiect(int an);
````
