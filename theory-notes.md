### 7. Constructori/destructori

1. constructorul este executat la crearea obiectului, destructorul la distrugerea obiectului
2. pentru obiectele globale constructorii se executa in ordinea in care sunt definite obiectele, iar destructorii se apeleaza dupa ce s-a terminat main-ul, in ordinea inversa a constructorilor
3. Sintaxa:

```cpp
numele_clase ( lista_parametri ) {/*implementare*/ };
~numele_clsei () {/*implementare*/ };
```

4.  Constructorii si destructorii nu au tip returnat.  Lista de parametri a constructorului poate fi si vida.

5.  In destructor se pot dezaloca zone de memorie alocate pentru stocarea datelor specifice obiectului sau date statice care contin pointeri la obiecte. Daca aceste zone de memorie nu sunt dezalocate vom avea memory leak.

6. Cand scriem: Class a, b=a; nu se apeleaza operatorul= ci constructorul de copiere (pe anumite compilatoare). Acest mecanism se numeste copy elision.

7.  Ordinea in care se apeleaza constructorii bazelor este:

- clasele de baza care se mostenesc virtual se construiesc primele
- apoi se construiesc clasele de baza care nu sunt de baza
- clasele nevirtuale sunt construite
- datele membre nestatice sunt initializate in ordinea in care apar in declararea campurilor clasei
- corpul constructorului este executat

### 11. Destructorul virtual

- Destructorii nu au parametri.
1. In cazul mostenirii, daca Baza are destructor virtual avem siguranta ca atunci cand se va apela destructorul derivatei se va apela si destructorul bazei (ex: atunci cand avem polimorfism cu pointeri)
2. Nu putem avea constructori virtuali pentru ca intotdeauna tipul real al obiectului care trebuie construit este acelasi cu tipul declarat al obiectului
3. nu are niciun efect daca nu se face upcasting

### 12. Destructor pur virtual

1. Trebuie neaparat sa fie implementat in afara functiei daca vrem sa mostenim din clasa care are destructorul pur virtual.
2. Este folositor atunci cand avem de creat o clasa abstracta dar vrem ca toti fiii ei sa mosteneasca toate metodele declarate fara a fi obligatoriu sa le suprascrie. Este suficient sa facem destructorul pur virtual pentru ca clasa sa fie abstracta.
3. Fiindca compilatorul creeaza un destructor implicit pentru fiecare clasa, orice clasa ce mosteneste dintr-o clasa cu un destructor pur virtual nu o sa fie clasa ablstracta, chiar daca nu a fost definit destructorul de utilizator. ⇒ aceasta este o metoda buna de a crea o ierarhie in care doar baza este abstracta.

### 8. Constructorul de copiere

1. Sintaxa:

```cpp
numele_clasei (const numele_clasei& ob)//nu putem avea trimitere prin valoare pentru ca ar implica
														//apelarea unui CC => loop infinit
										//nu o sa am eroare de compilare daca nu mentionez ca obiectul ob este
										//const, dar voi avea probleme atunci cand vreau sa copiez obiecte constante
										
{
...
}
```

2.  Daca nu e scris de utilizator, compilatorul va da unul public implicit care face shallow copy -copiaza bit cu bit

4.  Definitie: copy constructorul este un constructor care creeaza un obiect initializandu-l cu un alt obiect al aceleiasi clase. Este folosit si pentru trimiterea unui obiect ca parametru prin valoare sau pentru returnarea unui obiect dontr-o functie prin valoare.

5.  Exemplu

6.  Care sunt cazurile in care crapa daca nu avem `(const numele_clasei& ob)` ? cand se apeleaza un cc pe un obiect constant.

7. Poate avea mai multi parametri, cu conditia sa avem valori implicite pentru parametrii in plus.

8. Daca definesc constructorul de copiere pierd accesul la constructorul implicit de copiere si la constructorul de initializare implicit.

### 14. Clase locale

- Sunt clase definite in functii.
- Au anumite restrictii: trebuie sa defineasc toate functiile in interiorul clasei, implicit inline.
- Pot accesa doar variabilele statice sau enum ale functiei din care fac parte
- Nu pot defini variabile statice in astfel de clase, dar pot defini functii statice
- Pot accesa variable si functii globale.
- Pot accesa alte clase locale ale aceleiasi functii.

### 15. this

1. Este un keyword in care se stocheaza adresa obiectului implicit (obiectul care apeleaza functia non-statica).
2. Tipul lui this esta X* (unde X este clasa din care face parte functai apelata). Daca functia are constrangeri de const sau volatile, si this pastreaza aceleasi constrangeri.
3. Functiile prieten nu au pointerul this.
4. Functiile statice nu au pointerul this.

 1.  In cadrul metodei nu mai trebuie specificat carui obeict apartin campurile pentru ca se intelege ca apartin campului implicit.

 2. obiectul implicit al unei metode se poate accesa folosind *this.

 3. este transmis prin referinta (referinta constanta daca metoda e constanta)

### 16. Conversii

1. Prin constructor
    - Prin definirea unui constructor care primeste ca parametru tipul din care se face conversia. Constructorul intoarce intotdeauna un rezultat de tipul clsei din care apartine ⇒ putem face conversie.
    - Constructorii cu un parametru sunt tratati ca metode de conversie implicita. Daca corin sa corectam acest comportament putem pune explicit in fara constructorului.

2. Prin operator de cast

### 9. Variabile statice

1. Se definesc prin static tip nume_variabila;
2. Exista o singura copie pentru toate obiectele din clasa respectiva (si pentru toate obiectele care mostenesc din clasa respectiva)
3. Trebuie initializate in afara clasei pentru a se aloca memorie pentru ele.
4. Nu pot aparea in lista de initializare.
5. Pot fi accesate atat de obiecte cat si de functii statice.
6. Exmeplu:

```cpp
class A
{
		static int x;
}
int A::x=0;
```

7. Exemplu de utilizare: pentru a retine numarul de instante ale unui obiect si a limita instantiarea mai multor obiecte = Singelton

### 3. Descrieti proprietatile metodelor statice

1. nu au pointerul this pentru ca nu trebuie apelate neaparat de un obiect (pot fi apelate fie de un obiect al clasei — ob.functie_statica() — fie prin operatorul de scope — Clasa::functie_statica() )
2. au acces coar la  functiile si metodele statice (accesibile global) din clasa
3. o functie nu poate avea o varianta statica si una nestatica
4. nu pot fi virtuale pentru ca nu sunt elgate de un obiect
5. sintaxa: static tip_returnat nume_functie (parametrii_functiei) {implementare functie};
6. nu pot fi functii const sau volatile (nu sunt legate de un obiect)
7. Sintaxa:

```cpp
class A
{
		static void funct();
}
```

8. Exemplu de utilizare: pentru a accesa datele statice ale clasei care au fost declarate ca private pentru arespecta principiul incapsularii.

### Functiile friend

- o functie frind are acces la membrii private si protected ai unei clase, fara sa fie functie membra a clasei respective
- pentru a declara o functie friend trebuie sa includem signatura functiei, precedata de keyword-ul friend
- exemplu de utilizare: supraincarcarea opeartoruilor >> si <<:

```cpp
friend ostream& operator<< (ostream& oout, const clasa& ob);
```

- 

### 10. Supraincarcarea operatorilor

1. Sintaxa generala pentru supraincarcarea ca functie membra:

```cpp
ret-type class-name::operator#(arg-list)
{
		//....
}
unde #: operatorul supraincarcat
ret-type: tipul returnat
arg-list: lista de parametri (pentru operatori unari este vida, pentru binari contine un element)
```

2.  Unii operatori nu se pot supraincarca:

- operator ::
- operator .*
- operator .
- operator ?:
- operator sizeof
- operator typeid

 3.  Nu se pot crea operatori noi.

 4.  Nu se poate redefini precedenta si asociativitatea operatorilor

 5.  Nu se poate redefini numarul de operanzi

 6.  Nu putem avea valori implicite (exceptie operator() )

 7.  Toti operatorii (in afara de operator=) sunt mosteniti in clasele derivate 

- **supraincarcarea ca functii membre**
    - primul operator va fi obiectul care apeleaza functia, adica obiectul implicit, *this
    - pentru operatorii binari vom avea un parametru, pentru operatorii unari vom avea 0 parametri
- **supraincarcarea ca functii independente**
    - Unii operatori se pot redefini si ca functie membra si ca functie prietena, in timp ce altii nu se pot defini deloc ca functii prietene si pot fi definiti doar ca functii membre nestatice:
        - operator=
        - operator()
        - operator[]
        - operator→
    - Supraincarcareaa ca functie independenta se aseamana fosrte mult cu supranincarcarea ca functie friend, doar ca avem alt grad de accesibilitate la datele obiectului.
- **supraincarcarea ca functii friend**
    - operatori care nu se pot supraincarca ca functii friend
        - operator=
        - operator()
        - operator[]
        - operator→
    - vom avea toti operanzii ca parametrii
    - operatorul nu contine pointerul this
    - am acces la toate datele private si protected ale clasei
    - pentru supraincarcarea operatorilor ++ si - - trebuie sa folosim referinte pentru ca obiectul care apeleaza functia trebuie sa se modifice, dar nu avem pointerul this
    - pentru operatorii binari, primul operand este paramatrul din stanga, al doilea parametrul din dreapta
    - in unele cazuri trebuie sa definim 2 functii pentru supraincarcare: int + tip_clasa, tip_clasa+int
- operator ++, —

```cpp
//ca functii membre
tip operator++() {}//prefixat
yip operator++(int) {};//postfixat
//ca functii friend
friend tip operator++(tip &ob, int)
{
}
```

- function call operator ()
    - poate avea mai multi parametri

    ```cpp
    A* operator() (int a, char b)
    {
    		//implementare
    }
    A* a= B(8, 'u');//se apeleaza operatorul()
    ```

- operator cast
    - nu are tip returnat pentru ca tipul retunat e mereu acelasi cu numele operatorului
    - nu poate avea parametri

```cpp
operator int ()
{
		//implementare
}
A a;
coout<<int(a);
```

- operator new, delete
    - pentru argumentele suplimentare exista o forma speciala: tip_p p= new (lista argumente) tip
    - exita forma: p=new(northrow) int[20] care intoarce null la eroare

```cpp
//ca functie membra
void* operator new (size_t size)
{
	void* p;
	p=malloc(size);
	if(!p) {bad_alloc ba; throw ba;}
	return p;
}

void operator delete(void* p)
{
	free(p);
}
```

- operator[] : este considerat operator binar : obiect[5] ≤=> obiect.operator[](5)

```cpp
type class-name::operator[](int i)
{
//...
}
```

- operatorul * implementat ca functie membra trebuie sa aiba 1 sau 0 parametri
- operator→ : se foloseste atunci cand vrem ca un obiect sa se comporte ca un pointer
    - trebuie implementat ca functie membra nestatica
    - este un operator unar
    - este utilizat in cazul iteratorilor
    - intoarce un pointer catre un obiect din clasa

    ```cpp
    clasa* operator-> ()
    {
    	return this;
    }
    ```

### 3. Descrieti regulile supraincarcarii operatorilor unari

1. Sintaxa

```cpp
Clasa Clasa::operator-() const//daca este supraincarcat ca functie membra
{
	//....
}

friend Clasa::operator-(const Clasa& ob)//daca este supraincarcat ca functie prietena
{
	//....
}
```

2.  Daca operatorul este supraincarcat ca functie mebra, aceasta nu primeste parametri.

3.  Avem un caz special pentru operatorii unari : ++ si - - (prefixati si postfixati — diferenta se face prin dummy variable). Exemplu:

```cpp
#include <iostream>
using namespace std;
class Clasa
{
public:
    int i;
    Clasa() : i(0) {};
    Clasa operator++()//operator prefixat
    {
        i++;
        return (*this);
    }
    Clasa operator++(int)//operator postfixat cu dummy variable
    {
        Clasa temp(*this);
        i++;
        return temp;
    }

};

int main()
{
	Clasa a;
    cout<<(a++).i<<" ";
    cout<<(++a).i;
	return 0;
}
```

4.  Operatorii unari care pot fi suprascrisi sunt !, &, ~, *, -, ++, - - si operatorii de conversie.

5. Avem un alt caz special la operatorii de conversie, care nu pot avea tip returnat (tipul returnat este dat de numele operatorului) si nici parametri. Sintaxa:

```cpp
operator tipul_catre_care_se_face_cast() const {//.....};
```

### 18. Clase abstracte

- O clasa abstracta este o clasa care defineste sau msoteneste cel putin o functie in care ultima supraincarcare este pur virtuala.
- Clasele abstracte nu pot fi instantiate si sunt folosite pentru a reprezenta un concept general sau o intefata.
- Tipul unei clase abstracte nu pote fi folost ca tip returnat, ca parametru sau ca tip pentru conversia explicita. Pot fi declarati in schimb pointeri si referinte de clasa abstracta.

```cpp
#include <iostream>
using namespace std;
class A//clasa abstracta
{
	int x;
public:
    A(int x=1) : x(x){};
	virtual void f()=0;
	void afisare() { cout<<x<<" ";}
};
class B: public A//clasa nu e abstracta
{
	int y;
public:
    B(int x=2) : A(), y(x){};
	void f() {};
	virtual void g() {};
	void afisare() { cout<<y<<" ";}
};
class C: public B//clasa abstracta
{
int z;
	public:
    C(int x=3) : B(), z(x){};
	void g()=0;
	void afisare() { cout<<z<<" ";}
};
int main()
{
	//A a; -- eroare, nu pot instantia obiecte din clasa abstracta
	B b;
	A& a=b;//un alt nume pentru partea de baza a lui A
	b.afisare();
	a.afisare();
}

//afiseaza 2 1
```

### Toate metodele care nu sunt pur virtuale trebuie instantiate!

### Mostenirea virtuala

1. Este o metoda de implementare a polimorfismului la executie.
2. exemplu de utilizare: in cazul mostenirii in diamant. Avem 2 clase care mostenesc o baza si o alta clsa acre msoteneste cele 2 clase. ⇒ vom avea anumite elemente care apar de 2 ori in ultima clasa. Rezolvare: scriem ca cele 2 clase msotenesc virtual din clasa de baza.

### Functii virtuale

- este o metoda de implementare a polimorfismului la executie.
- utilitate: putem extinde codul fara a il rescrie
- se pot defini fucntii virtuale pure, adica functii virtuale care nu au o implementare
    - o utilizare importanta a functiilor virtuale pure este prevenirea object slicing-ului
- nu putem face overload in clasele derivate prin schimbarea tipului parametrului de intoarcere (este posibil pentru metodele nevirtuale); exceptie: pointer catre baza intors in baza, pointer catre derivata intors in derivata

### 6. Tratarea exceptiilor

1.  Daca se face throw si nu exista un bloc try din care a fost aruncata exceptia (sau se arunca throw dintr-o functie apelata dintr-un bloc try) atunci avem eroare la run-time: terminate called after throwing an instance of <tip>
2. Daca nu exista un catch care sa fie asociat cu throw-ul aruncat avem eroare de compilare
3. Nu se face niciodata cast atunci cand se cauta catch-ul potrivit pentru un anumit throw (exceptie face faptul ca daca este aruncat un obiect de tip Derivata, throw-ul va fi prins si de un catch de tip Baza)
4. Putem scrie catch(...) care prinde orice exceptie primeste.
5. Sintaxa : 

```cpp
try
{
//....
	 throw tip;
}
catch( tip )
{
//....
}
//...
[catch (...)
{

}]
```

6. Dupa ce este prinsa eroarea nu se revine la locul de unde a fost aruncata eroarea, ci se da controlul "mai sus". Ex: daca eroarea este aruncata dintr-o functie f si prinsa tot in f, iar f este apelat din main, se va continua executia main-ului de la apelarea functiei f in jos. In schimb daca eroarea a fost aruncata in main si prinsa in main, se va executa codul scris dedesubtul lui catch.

7. Terminate poate fi redefinita sa faca altceva prin set_terminate care primeste ca parametru o functie care se va apela de fiecare dacta cand avem terminate.

8. throw; rearunca exceptia care este handeled la momentul respectiv. Daca nu sunt intr-un catch cand se face throw; o sa am eroare de compilare.

### 1. Singleton. Dati un exemplu de o clasa care nu poate avea la un moment dat mai mult de 2 obiecte instantiate

1. Singleton-ul este un design pattern folosit pentru a restrictiona numarul de instante care se pot crea dintr-o clasa la un moment dat.
2. exemplu

```cpp
class Singleton
{
  private:

    static Singleton *instance;
    Singleton();

  public:
		Singleton (const Singleton&)=delete;
    Singleton& operator=(const Singleton&)=delete;

    static Singleton* get_instance()
    {
      if (!instance)
      {
        instance = new Singleton();
      }

      return instance;
    }
};
Singleton* Singleton::instance= nullptr;
```

```cpp
class Singleton
{
  public:
    static Singleton& get_instance()
    {
        return instance;
    }

  private:
		static Singleton instance;
    Singleton();
    Singleton(const Singleton&); 
    Singleton& operator=(const Singleton&); 
    ~Singleton(); 
};
Singleton Singleton::instance(0);
```

3.  diferite implementari

Exista 2 implementari pentru singleton, una cu & si una cu *. Cea cu referinta implica riscul de a accesa obiectul dupa distrugere (ex: dintr-un alt destructor). De obicei se prefera prima varianta.

4. Exemplu de doubleton.

```cpp
class Clasa
{
private:
    static Clasa* instance1;
    static Clasa* instance2;
    Clasa() {};
public:
    Clasa (const Clasa&)=delete;
    Clasa& operator=(const Clasa&)=delete;
    static Clasa* get_instance1()
    {
        if(!instance1)
            instance1= new Clasa;
        return instance1;
    }
    static Clasa* get_instance2()
    {
        if(!instance2)
            instance2= new Clasa;
        return instance2;
    }
    virtual ~Clasa()
    {
        delete instance1;
        delete instance2;
    }
};
Clasa* Clasa::instance1=nullptr;
Clasa* Clasa::instance2=nullptr;
```

### 6. Definirea si utilizarea claselor template

1. Sintaxa: 

```cpp
template < lista_de_tipuri >
class clasa
{
		//....
}

clasa < lista_de_tipuri> ob;
```

2.  Functiile unei clase template sunt si ele template

3.  Lista de tipuri este o lista nevida, separata prin virgule, in care fiecare element
este parametru fara tip (non-type parameter), parametru cu tip (type parameter) sau 
parametru template. 

ex: template<template<typename, typename> class T, typename U, int N> — T este parametru template, U este type parameter si N este parametru fara tip

4.  Sunt folosite in general pentru a implementa containere.

5.  Se pot specializa pentru anumite tipuri de date. Specializarile sunt tratate ca fiind clase independente, adica nu sunt constranse de implementarea clasei template initiale.

6.  Fiecare instantiere a clasei template contine propriul sau set de variabile statice.

7.  Atunci cand este instantiata o clasa template trebuie mentionat obligatoriu si lista de tipuri (daca nu avem valori default)

8.  Putem avea valori default pentru tipurile parametrizate.

9.  Nu se poate folosi dynamic_cast pentru a schimba pun pointer la o instanta a unei clase template la o instanta a altei clse template.

### 13. Iterator

1. Iteratorii sunt obiecte care pointeaza catre un element dintr-un container si au abilitatea de a itera printre obiecte folosind cativa operatori: ++, - - pentru traversare si * pentru dereferentiere.
2. Exista mai multe tipuri de iteratori:
- iteratori de input/output

    ex: istream_operator, folosit pentru a citi obiecte succesive de un tip T. Acesta sare peste spatiile libere by default.

- forward iterators

    Au toata functionalitatea iteratorilor de input, daca nu sunt iteratori constanti, au si functionallitatea iteratorilor de output. Au doar o anumita directie in care pot itera. Toate containere standard din STL ofera cel putin acest tip de operator.

- iterator bidirectional

    Au aceleasi caracteristici ca forward iterators doar ca au 2 directii in care pot itera.

- iterator random acess

    Au aceleasi caracteristici ca iteratorii bidirectionali, dar au si abilitatea de a accesa elemente aflate la o distanta mai mare de 1 de ei fara a itera printre toate elementele dintre.

- reverse iterators
- Anumite structuri de date din STL nu ofera iteratori: adaptoarele de containere - stack, queue, priority_queue

### 19. Functiile template

1. Se poate face overload pe functii template: (2 tipuri de polimorfism la compilare)

```cpp
template<class X> void f(X a)
{
		cout<<"f(X a)";
}
template<class X, class Y> void f(X a, Y b)
{
		cout<<"f(X a, Y b)";
}
int main()
{
		f(10);//se apeleaza f(X)
		f(10, 20); //se apeleaza f(Xm y)
}
```

2. Prioritatea de alegere pentru overload pe sabloane:

- potrivire fara conversie:
    - varianta non-template
    - template fara paramatri
    - template cu 1 parametru
    - template cu mai multi parametri
- cu conversie: doar la varianta non template

### 20. Specializarea functiilor template

```cpp
template <typename T>
void f (T x) {
cout << "functie template";
}
template <>
void f (int x) {
cout << "functie specializata";
}
int main () {
f(3); // se apeleaza specializarea
f('c'); // se apeleaza functia template
}
```

1. Exista o anumita prioritate la supraincarcare, si anume: atunci cand programul apeleaza o functie:
- se cauta o functie normla pentru care parametrii sa se potriveasca exact
- daca nu se gaseste, se cauta o specializare template pentru care sa se poate inlocui parametrii
- daca nu se gaseste, se cauta un template pentru care se pot inlocui parametrii
- daca nu se cauta o functie normala pentru care se poate face cast pe parametri

### 21. Pointeri catre membrii in clase

1. Sintaxa

```cpp
expresie .* expresie
expresie ->* expresie
```

2. Exemplu

```cpp
#include <iostream>
using namespace std;
class cl {
public:
   cl(int i) { val=i; }
   int val;
   int p;
   int double_val() { return val+val; }
};

int main()
{
   int cl::*data; // declararea unui pointer la membrii clasei, int reprezinta tipul datei membre
   int (cl::*func)(); // declararea unui pointer la functiile clasei, int reprezinta tipul returnat de funtie
   cl ob1(1), ob2(2); // creez 2 obiecte
	 data = &cl::val; // definirea pointerului
   func = &cl::double_val; // definirea pointerului

// <=> int c1::*data=&cl::val;
// <=> int c1::*func=&cl::double_val;

	 c1.val=1;//offera acces direct
   cout << "Here are values: ";
   cout << ob1.*data << " " << ob2.*data << "\n";//ofera acces prin pointerul la data membra
   cout << "Here they are doubled: ";
   cout << (ob1.*func)() << " ";
   cout << (ob2.*func)() << "\n";
   return 0;
}
```

3. Nu sunt pointeri normali, nu retin adresa unei valori specifice, ci retin offset-ul unei valori generice.

### 23. Reference Lifetime Extension

1. returning `string`, initializing `string`

```cpp
string get_name()
{
    string s="magic";
    return s;
}
int main()
{
    string p=get_name();
    std::cout<<p;//perfectly normal
    return 0;
}
```

2. Returning string, initializing string&

```cpp
#include <bits/stdc++.h>
using namespace std;
string get_name()
{
    string s="magic";
    return s;
}
int main()
{
    string& p=get_name();//nu compileaza
												//nu ai voie sa faci bind unei referinte de o valoare temporara
    std::cout<<p;
    return 0;
}
```

3. Returning const string&, initializing string&

```cpp
#include <bits/stdc++.h>
using namespace std;
const string& get_name()
{
    string s="magic";
    return s;
}
int main()
{
    string& p=get_name();//nu compileaza, s-a scapat ilegal de const
    std::cout<<p;
    return 0;
}
```

4. Returning string, initializing const string& **LIFETIME EXTENSION : desi , avand in vedere ca nu ai voie sa faci bind la string& din valoare temporara string, ai fi zis ca nu va compila, C++ are special-case support pentru asta**

```cpp
#include <bits/stdc++.h>
using namespace std;
string get_name()
{
    string s="magic";
    return s;
}
int main()
{
    const string& p=get_name();//functioneaza, iar valoarea temporara va fi distrusa atunci
															// cand va iesi referinta din scop
    std::cout<<p;
    return 0;
}
```

5. Returning const string&, initializing const string& : **se mosteneste durata de viata a obiectului la care e referinta (in cazul nostru e o variabila locala care va iesi din scope si deci voi avea referinta la garbege)**

```cpp
#include <bits/stdc++.h>
using namespace std;
const string& get_name()
{
    string s="magic";
    return s;
}
int main()
{
    const string& p=get_name();
    std::cout<<(p);
    return 0;
}
```

6. Returning string&, initializing string&. acelasi lucru ca al 5 doar ca referinta e non-const deci se vor vedea modificarile pe obiect

7. Returning string&, initializing const string&: la fel ca la 5

### 24. Diferenta dintre a transmite prin valoare si a transmite prin referinta

- **Referinta**
    - La referinta se actioneaza asupra aceluiasi obiect, deci schimbarile se vad si in afara functiei (exceptie daca referinta e constanta caz in care nu se poate modifica obiectul)
    - La valoare se actioneaza pe 2 obiecte diferite, obiectul initial si o copie a sa pe heap, air efectul nu se vede
    - La referinta nu se mai apeleaza constructorul de copiere si destructorul.
- **Valoare**

```cpp
int funct (int x, int y){}; // prin valoare
int funct (int& x, int y) {}; // prin referinta
```

### 25. const

- trebuie data o valoare pentru elementul constant la declarare. exceptie: extern const int bufsize; pentru care se aloca spatiu (in contrast cu restul variabilelor constante pentru care nu se aloca spatiu in mamorie decat daca se trasnmite prin referinta etc.) pentru a putea fi accesat exetrn
1. **Data members**
    - se initializeaza in constructor folosind lista de initializare si odata initializati nu mai pot fi modificati nici in constructori nici in destructori
2. **Objects**
    - proprietatea de const intra in functiune dupa ce se termina constructia obiectului si se termina inainte de apelarea destructorului
    - obiectele const pot apela doar fucntii const
    - constructorii si destructorii nu pot fi const niciodata
    - se pot scrie 2 functii cu acelasi nume, una const si una fara const si compilatorul decide pe care o apeleaza

    3. pointeri const

    - int const* u < = > const int* u: pointer catre un int care e constant
    - int d=1; int* const w =& d; pointer constant care arata catre intregi + initalizare
    - int d=1; const int* const x=d; int const* const x2=&d; pounter const catre const element

    ```cpp
    int d = 1; 

    const int e = 2; 

    int* u = &d; // OK -- d nu e const

    //! int* v = &e; // Illegal -- e const 

    int* w = (int*)&e; // scap de const

    int main() {}
    ```

    ```cpp
    //am voie sa modific valoarea prin ic, dar nu prin i
    void f2(int ic) 
    {
    	const int& i = ic;
    	//i++; // ilegal - eraore la compilare
    	ic++;//merge
    }

    int main() {}
    ```

    ```cpp
    class X {   int i;
    public:   X(int ii = 0);
    void modify();
    };

    X::X(int ii) { i = ii; }
    void X::modify() { i++; }

    X f5() {   return X(); }
    const X f6() {   return X(); }

    void f7(X& x) { // Pass by non-const reference
      x.modify();
    }

    int main() {
      f5() = X(1); // OK -- non-const return value
      f5().modify(); // OK
    // Causes compile-time errors:
    //!  f7(f5()); -- nu pot sa initializez o referinta cu o valoare temporara
    //!  f6() = X(1); -- nu am voie sa trimit obiect const ca this operatorului = implicit
    //!  f6().modify(); -- modify nu e functie const
    //!  f7(f6()); -- parametrul din f7 nu const
    } ///:~
    ```

    ```cpp
    // Constant pointer arg/return

    void t(int*) {}

    void u(const int* cip) {
    //!  *cip = 2; // Illegal -- modifies value
      int i = *cip; // OK -- copies value
    //!  int* ip2 = cip; // Illegal: non-const
    }

    const char* v() {
      // Returns address of static character array:
      return "result of function v()";
    }

    const int* const w() {
      static int i;
      return &i;
    }
    int main() {
      int x = 0;
      int* ip = &x;
      const int* cip = &x;
      t(ip);  // OK
    //!  t(cip); // Not OK
      u(ip);  // OK
      u(cip); // Also OK
    //!  char* cp = v(); // Not OK
      const char* ccp = v(); // OK
    //!  int* ip2 = w(); // Not OK
      const int* const ccip = w(); // OK
      const int* cip2 = w(); // OK
    //!  *w() = 1; // Not OK
    } ///:~
    ```

    - **functii memebre**
        - nu pot apela functii non-const

### 27. Referinte independente

- trebuie initializate la definire pentru ca ele nu se pot schimba in timpul programului

### 28. new

- aloca memorie si intoarce un pointer la inceputul zonei respective
- la eroare se arunca exceptia bad_alloc din <new>
- pentru obiecte, new apeleaza si constructorul, iar delete destructorul

### 29. Array-urile de obiecte alocate dinamic

- nu se pot initaliza
- trebuie sa existe constructor fara parametri

### 30. Pointeri si referinte

- **Pointer**
    - pointeaza catre un obiect
    - obiectul spre care pointeaza poate fi schimbat
    - pointerul declarat de un anumit tip nu poate pointa catre un alt tip care nu e in aceeasi ierarhie cu el si mai jos ca el.
- **Referinta**
    - este un pointer constant care se dereferentiaza automat
    - odata atribuita unui obiect nu mai poate fi schimbata
    - prin modificarea referintei se modifica si obiectul referit.

### 22. **Diferenta dintre returnarea prin valoare, pointer si referinta.**

- **Valoare:**
    - poti returna literals (5), variabile (x) sau expresii (x+1)
    - poti returna si expresii care implica variabile locale fara sa te ingrijorezi de scope: valoarea expresiei este evaluata inainte de  iesirea din functie si este transmisa callerului

    ```cpp
    int doubleValue(int x)
    {
        int value{ x * 2 };
        return value; // A copy of value will be returned here
    } // value goes out of scope here
    ```

    - este indicata pentru returnarea variabilelor care au fost declarate in functie si pentru returnarea argumentelor transmise prin valoare si pentru tipuri de date primitive : int flaot double
    - nu este indicata atunci cand se returneaza un array sau un obiect mare pentru ca se apeleaza CC de 2 ori: se pune valoarea pe stiva si de pe stiva in caller
    - se copiaza valoarea furnizata de functie intr-o variabila temporata, de tipul returnat al functei
- **Adresa (pointer)**
    - se returneaza adresa variabilei caller-ului
    - se poate returna doar o variabila, nu un literal sau o expresie pentru ca acestea sunt rvalues si nu au adresa
    - returnarea este foarte rapida  pentru ca se copiaza doar o adresa
    - daca incerci sa returnezi adresa unei variabile locale va fi undefined behaviour pentru ca valoarea este distrusa dupa iesirea din functie iar caller-ul primeste o adresa de memorie nealocata

    ```cpp
    int* doubleValue(int x)
    {
        int value{ x * 2 };
        return &value;
    }
    ```

    - se foloseste pentru a returna memorie alocata dinamic si functioneaza pentru ca nu iese din scope

    ```cpp
    int* allocateArray(int size)
    {
        return new int[size];
    }
    ```

- **Reference**
    - cand se returneaza un obiect prin referinta nu se mai apeleaza constructorul de copiere si destructorul
    - daca avem functie const nu avem voie sa returnam obiectul implicit sau date membre ale sale prin referinta pentru ca am risca sa modificam datele membre ale obiectului sis a incalcam promisiunea de const
    - la fel ca la pointer, se pot returna doar variabile, nu literali si nu expresii care contin variabile locale
    - se transmite o referinta la obiect caller-ului, care poate modifica mai departe obiectul (daca este referinta const atunci nu se poate modifica obiectul)
    - este rapida
    - este folosita de obiect pentru returnarea parametrilor transmisi prin referinta

    ```cpp
    int& getElement(std::array<int, 25> &array, int index)
    {
        // we know that array[index] will not be destroyed when we return to the caller (since the caller passed in the array in the first place!)
        // so it's okay to return it by reference
        return array[index];
    }
    ```

    - **Incurcarea returnarii prin valoare si prin referinta : compilatorul poate sa transforme automat din pass by value in pass by reference dar nu invers (decat daca am const reference)**

    ```cpp
    int value()
    {
        return 12;
    }
     
    int& reference()
    {
         static int x{12}; // static face ca variabila sa nu fie distrusa dupa ce se termina functia
         return x;
    }
     
    int main()
    {
        int value{ reference() }; // ok, e tratata ca si cum s-ar transmite o valoare
        int &ref{ value() }; // eroare, nu se poate initializa o referinta cu o valoare temporara
        const int &cref{ returnByValue() }; // ok, i se extinde durata de viata a valorii prin lifetime extension
     
        return 0;
    }
    ```

- **Lifetime extension doesn’t save dangling references**

```cpp
const int& returnByReference()
{
     return 5;
}
 
int main()
{
    const int &ref { returnByReference() }; // runtime error
}
```

Se stie ca: 

- daca returnezi o valoare locala prin referinta ea iese din scop
- daca returnezi o valoarea ca ocnst int& ii maresti duarata de viata (more on that later)

Care are precedenta in cazul acesta? Prima. 5 iese din scop si apoi se returneaza o const reference la ceva nealocat. 

In cazul urmator e  ok:

```cpp
const int returnByValue()
{
     return 5;
}
 
int main()
{
    const int &ref { returnByValue() }; // ok, we're extending the lifetime of the copy passed back to main
}
```

### 24. Diferenta dintre a transmite prin valoare si a transmite prin referinta

- **Referinta**
    - La referinta se actioneaza asupra aceluiasi obiect, deci schimbarile se vad si in afara functiei (exceptie daca referinta e constanta caz in care nu se poate modifica obiectul)
    - La valoare se actioneaza pe 2 obiecte diferite, obiectul initial si o copie a sa pe heap, air efectul nu se vede
    - La referinta nu se mai apeleaza constructorul de copiere si destructorul.
- **Valoare**

```cpp
int funct (int x, int y){}; // prin valoare
int funct (int& x, int y) {}; // prin referinta
```

### 2. Descrieti polimorfismul la compilare.

1.  Se realizeaza la compilare (early binding) si este un proces in care compilatorul asociaza o adresa fiecarei functii, verifica daca functia exista, daca numarul si tipul parametrilor este acelasi, daca tipul returnat este corect etc.
2. Este obtinut prin supraincarcarea functiilor (se pot defini mai multe functii cu acelasi nume care se deosebesc prin numarul de argumente si tipul lor fara a crea ambiguitate - nu este de ajuns sa difere tipul returnat! ). Ordinea in care compilatorul alege functai este: 1. potrivire exacta a parametrilor, 2. conversie fara pierderi, 3. conversie cu pierderi
3. Este obtinut prin supraincarcarea operatorilor:

```cpp
int a=0, b=12;
cout<<a + b; // se afiseaza 12
string s1="examen", s2=" oop";
cout<<s1 + s2; // se afiseaza "examen oop"
```

Astfel, operatorul + are sensuri diferite in functie de pozitia sa.

4. Este obtinut prin functiile template (un "model" dupa care compilatorul poate crea functii similare)

```cpp
#include <iostream>
using namespace std;

template <typename T>
void aduna (T a, T b)
{
	cout<<a+b;
}

int main()
{
	int a=1, b=-19;
	string s1="examen", s2=" oop";

	//pot specifica tipul pentru care apelez functia template
	aduna<int>(a, b);
	//dar nu este neaparat sa specific tipul la functii, ci compilatorul isi va da
	//seama singur care este tipul
	aduna(s1, s2);
	// aduna(s1, a); da eraore de compilare pentru ca cele 2 variabile au tipuri diferite
	// aduna<int>(s1, a); da eroare de compilare, chiar daca am specificat tipul
	return 0;
}
```

La compilare, compilatorul decide care este tipul pentru care apelam functia - notat aici cu A - (tipul poate fi specificat sau nu). Daca nu exista deja o instanta a functiei template pentru tipul A, isi rescrie o functie identica cu cea din template in care inlocuieste toate aparitiile parametrului T cu A. Functia rezultata se numeste instanta a functiei template pentru tipul A.

Atunci cand nu poate decide care este tipul pentru care este apelata functia sau tipul declarat nu coincide cu parametrii trimisi functiei, compilatorul va afisa o eraore de compilare.

4. Este obtinut prin clasele template.

```cpp
#include <iostream>
using namespace std;

template <typename T>
class template_class
{
public:
	T a;
	template_class() : a(T()) {}
};

template <>
class template_class<int>
{
	int a;
	template_class() : a(109) {}
}

int main()
{
	template_class<int> x;//in cazul claselor este obligatoriu sa specific tipul
	template_class<long long> y;
	template_class<string> z;
	cout<<x.a<<" "<<y.a<<" "<<z.a;// afiseaza 109 0 ""
	return 0;
}
```

5. Aceleasi principii sunt folosite si in STL pentru definirea diferitelor tipuri de structuri (ex: vector<int>, vector<char*>, pair<Book*, Reader>, etc.)

6. Este obtinut prin parametrii cu valori implicite.

### 3. Descrieti polimorfismul la executie.

1. Apelarea unei functii este stabilita la runtime, nu la compilare. La executie compilatorul decide care este tipul real al obiectului care a apelat functia (daca am apelat functia printr-un pointer sau referinta) si apeleaza functia corespunzatoare ei.
2. Este obtinut prin keyword-ul virtual. O functie virtuala este o functie care poate fi rescrisa in clasa derivata si pentru care compilatorul va face late-binding.
3. Cuprinde: instantierea dinamica, mostenirea si metodele virtuale.
4. Sintaxa:

```cpp
class clasa1
{
	virtual tip_returnat1 functie1 (parametrii_functie1);//sintaxa declararii unei functii virtuale
	tip_returnat2 functie2 (parametrii_functie2);
}

class clasa 2 : specificator_de_acces clasa1
{
		tip_returnat1 functie1 (parametrii_functie1);//suprascriere a metodei virtuale
		tip_returnat2 functie2 (parametrii_functie2);
}
int main()
{
		clasa1* a= new clasa1();
		clasa2* b= new clasa2();
		a->functie1();//apeleaza clasa1::functie1
		b->functie1();//apeleaza clasa2::functie1
		a->functie2();//apeleaza clasa1::functie2
		b->functie2();//apeleaza clasa1::functie2
}
```

1. Se realizeaza prin VTABLE. La compilare, compilatorul creeaza un VTABLE pentru fiecare clasa care are functii virtuale si pentru fiecare clasa care mosteneste o clasa cu functii virtuale. VTABLE contine cate un pointer pentru fiecare functie virtuala. In cazul functiilor pur virtuale, pointerul este NULL. VTABLE-ul este folosit doar in cazul pointerilor.
2. Vptr este un pointer ascuns al fiecarei clase care are functii virtuale. Vptr arata care VTABLE-ul clasei. Toate clasele care mostenesc o clasa cu vptr vor mosteni si vptr.
3. Caz particular: mostenirea virtuala.

### 17. Enumerati modalitatile pe care le stiti prin care puteti avea acces la un membru privat din clasa A in cadrul clasei B

1. facem clasa B prietena cu clasa A
2. facem un getter si un setter pentru B

### Spuneti in ce situatii o variabila constanta poate fi transmisa ca parametru unei functii.

- cand se primeste parametrul prin valoare. daca variabila ce trebuie trimisa este un obiect de tip definit de utilizator trebuie sa avem copy constructorul definit cu const C& ob sau sa avem copy constructorul implicit
- cand se primeste parametrul prin referinta constanta

### Descrieti trei metode de proiectare diferite prin care elementele unei clase se pot regasi in dublu exemplar, sub diverse forme, in definitia altei clase.

- Clasa B si clasa C mostenesc public din clasa A, care are doar date public si protected. Clasa D mosteneste public din clasele B si C. ⇒ clasa D va avea 2 copii ale membrilor din clasa A.
- Clasa A contine campul B b si campul C c. Clasa B si clasa C mostenesc public din clasa D, care are doar campuri protected sau private.
- Clasa A mosteneste clasa B. Clasa A contine campul B b.

### RTTI

- Este un mecanism care identifica tipul unui obiect la executie. In VTABLE se retine adresa informatiilor de RTTI pentru calsa A. informatiile de RTTI contin atat name pe care il apelam la typeid, cat si bases, care tine o lista de pointeri catre informatiile de RTTI ale tuturor bazelor clasei.
- Se poate aplica doar claselor care au cel putin o functie virtuala.
- dynamic_cast foloseste RTTI
- Se realizeaza prin typeid, pentru care trebuie sa includem libarria typeinfo
- exemplu de utilizare:

    Factory pattern: pentru a crea obiecte fara a specifica exact tipul exact al obeictului. Daca facem facory pattern pentru o ierarhie in diamant, ( A->B, A→ C, B, C→ D) trebuie sa testam mai intai daca tipul real al obiectului spre care pointeaza pointerul primit ca parametru este de tip D, apoi B, C si A. Intotdeauna D trebuie sa fie primul.

- exemplu:

```cpp
class A
{
		virtual f();
}
class B: public A
{
}
class C: public A
{
}
int main()
{
	A* b= new B();
	A* c= new C();
	if(typeid(*b)==typeid(B))
		cout<<"obiect de tip B";
	else if(typeid(*b)==typeid(C))
		cout<<"obiect de tip C";
	return 0;
}
```

### Descrieti pe scurt comportamentul operatorului dynamic_cast<>

1. Realizeaza conversia de la un obiect de un tip la alt tip atunci cand este aplicat pe pointeri sau referinte.
2. Sintaxa:

```cpp
dynamic_cast <tip_nou> (expresie)
```

2.  Deoarece foloseste RTTI, functioneaza doar pentru ierarhii care au functii virtuale.

3.  Daca cast-ul se realizeaza cu succes se returneaza o valoare de tipul tip_nou. Daca esueaza si tip_nou este un pointer reurneaza nullptr. Daca esueaza si tip_nou este referinta arunca o referinta de tipul std::bad_cast.

3.  Nu se pot face conversii in care sa se scape ilegal de const sau volatile (pentru asta exista const_cast)

4.  dynamic_cast <tip_nou> (nullptr) returneaza nullptr

5.  Daca expresie este un pointer la un tip polimorfic si tip_nou este un void pointer, rezultatul este un pointer la cel mai derivat obiect catre care arata sau referentiaza expresie.

### Dimensiunea unei clase

```cpp
class A {}; //dimensiune 1
class B 
{
		int x;
		char c;
}//dimensiune 8: ceil(4 + 1, 4)
class C
{
		double x;
		char c[17];
}//dimensiune 32: ceil(17+8, 8)
```

### Dati 3 exemple in care functiile sablon nu genereaza o versiune a functiei dintr-un sablon pentru functia respectiva

- Avem definita o functie non-template pentru care exista o potrivire exacta a parametrilor.
- Exista o specializare a functiei template pentru care parametrii se potrivesc exact.
- Nu exista o potrivire exacta a parametrilor functiei apelate cu parametrii functiei template.

### Lista de initializare

1. Sintaxa:

```cpp
class Clasa
{
		int x, y;
	public: 
		A(int x, int y): x(7), y(9) {};
}
```

1. Poate fi utilizata doar la constructori.
2. Nu putem pune variabile statice in ea (ar insenma ca daca apelam de 2 ori constructorul in program initializam de 2 ori variabila statica, dar ea poate fi initializata doar o data)
3. In cazul in care clasa are o data membra sub forma de referinta, este obligatoriu sa o initalizam in lista de initializare dintr-un paramatru transmis prin referinta.
4. In cazul in care avem o data membra constanta, aceasta poate fi initializata doar o data, deci trebuie sa fie initializata in lista de initializare.
5. Se utilizieaza pentru:
    - initializarea datelor membru care nu au constructor fara parametri
    - apelarea constructorilor bazelor pentru bazele care nu au constructori fara parametri
    - pentru eficienta

### Diferenta dintre un pointer catre un obiect constant si un pointer constant catre un obiect

- **Pointer catre un obiect constant**
    - Valoarea obiectului nu poate fi modificata, dar putem modifica obiectul catre care pointeaza pointerul.
    - Sintaxa: const tip* p sau tip* const t
- **Pointer constanat catre un obiect**
    - Pointerul nu se poate modifica, dar valoarea catre care pointeaza da
    - Sintaxa: tip const* p
    - exemplu: this
    - se poate face atribuire de adresa pentru un obiectnon-cosnst catre un obiect const
    - nu se poate face atribuire pe adresa de obiect const catre un pointer non-const.

### Descrieti cum puteti prelua o data prin incluziune si a doua oara prin mostenire o clasa numar intr-o clasa lista care descrie liste nevide de dimensiune variabila de elemente de tip numar.

Prin incluziune:

```cpp
class numar
{
///implementare
}

class lista 
{
vector<numar> v;
//restul implementarii
}
```

prin mostenire:

```cpp

```

### Object slicing
