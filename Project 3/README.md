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


Tasks:

- [x] using templates
````
template<typename T>
class Firma_de_distributie
````
- [x] using STL
````
set<tuple<Film*, Personal*, int>> s;
````
- [x] using static variables, static functions, const variables and const functions
````
static std::unordered_map<int, std::set<Film*> > umap_film;
static std::set<Film*>& get_filme_din_an(int an)
{
    return umap_film[an];
}
const Film& ob;
unsigned int get_incasari() const;
````
- [x] using RTTI concepts relative to templates
````
if(typeid(T).name()!=typeid(Personal).name() && typeid(T).name()!=typeid(Actor).name()
           && typeid(T).name()!=typeid(Actor_principal).name() && typeid(T).name()!=typeid(Regizor).name())
````
- [x] treating exceptions
````
class myexception: virtual public std::exception
{
public:
    char* error_message;
    explicit myexception(int i)
    .....
````
- [x] readubding, storing and outputting n objects
- [x] constructors, destructors, operators= and friend function to read
- [x] base classes should containg a virtual output functions, used by derived classes as well
````
virtual void afisare() const;
````
- [x] read function should be friend and used by derived classes
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
- [x] **Named Constructor Idiom** = hiding the constructor in Firma_de_distributie and creating object through: 
````
static Firma_de_distributie<T>* creare_obiect(int an);
````
