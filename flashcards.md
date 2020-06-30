```cpp
//In ce ordine se apeleaza constructorii?
#include <iostream.h>
class cls1
{ protected: int x;
public: cls1(){ x=13; } };
class cls2: public cls1
{ int y;
public: cls2(){ y=15; }
int f(cls2 ob) { return (ob.x+ob.y); } };
int main()
{ cls2 ob; cout<<ob.f(ob);
return 0;
}
```

- 

    eroare: - nu exista <iostream.h>
    - lipseste namespace std si avem cout
    - daca nu ar lipsi s-ar afisa 28
    - se apeleaza cls1(), cls2(), cls1(ob), cls2(ob)

```cpp
#include <iostream>
using namespace std;
const string& get_name()
{
    string s="magic";
    return s;
}
int main()
{
    const string& p=get_name();
    std::cout<<p;
}
```

- 

    compileaza dar nu ajunge la return 0 -> look more into that

```cpp
#include <iostream>
using namespace std;
const string& get_name()
{
    string s="magic";
    return s;
}
int main()
{
    string& p=get_name();
    std::cout<<p;
}
```

- 

    nu compileaza, s-a scapat ilegal de const

```cpp
#include <iostream>
using namespace std;
string get_name()
{
    string s="magic";
    return s;
}
int main()
{
    const string&p=get_name();
    std::cout<<p;
}
```

- 

    functioneaza, iar valoarea temporara va fi distrusa atunci cand va iesi referinta din scop

```cpp
#include <iostream>
using namespace std;
string get_name()
{
    string s="magic";
    return s;
}
int main()
{
    string&p; 
    p=get_name();
    std::cout<<p;
}
```

- 

    /nu compileaza
    //nu ai voie sa faci bind unei referinte de o valoare temporara

```cpp
#include <iostream>
using namespace std;
string o= "opapa";
const string& get_name()
{
    string s="magic";
    return o;
}
int main()
{
    const string&p=get_name();
    std::cout<<p;
}
```

- 

    opapa

```cpp
#include<iostream.h>
class cls
{ int x;
const int y;
public: cls(int i, int j):x(i), y(j) { }
int imp(int, int) const; };
int imp(int i, int j) const
{ x=i; y=j; return x+y; }
int main()
{ cls ob(5);
cout<<ob.imp(-9,8);
return 0;
}
```

- 

    - nu exista<iostream.h>
    - lipseste namespace std si avem cout
    - 

    se afiseaza 14

    static in funtie face sa nu se distruga obiectul la iesirea din functie

```cpp
//Compileaza sau nu? Daca da de ce, daca nu de ce?
#include <iostream>
using namespace std;
struct Person {
  struct Name {
    std::string first_name;
    std::string last_name;
  } name;
};
Person birth;
int main()
{
  const std::string &first_name = birth.name.first_name;
}
```

- 

    Merge, si birth este distrus dupa ultima acolada.

```cpp
````int returnByValue()
    {
        return 5;
    }
     
    int&amp; returnByReference()
    {
         static int x{ 5 }; 
         return x;
    }
     
    int main()
    {
        int value{ returnByReference() }; 
        int &amp;ref{ returnByValue() }; 
        const int &amp;cref{ returnByValue() }; 
     
        return 0;
    }
````
```

- 

    -static ensures x isn't destroyed when the function ends

    case A -- ok, treated as return by value
    case B -- compile error since the value is an r-value, and an r-value can't bind to a non-const reference
    case C -- ok, the lifetime of the return value is extended to the lifetime of cref

    ```cpp

    ```

```cpp
Ce e aia lifetime extension? cand functioneaza si cand nu functioneaza?
```

- 

    Functioneaza atunci cand un local const T& sau T&& este initializat din reziltatul unei expresii care returneaza:
    -un temporar T
    -T subobiectul unui temporar(un struct care contine T)
    In cazul acesta, obiectul T este distrus atucni cand referinta iese din scop.

    Cand nu merge lifetime extension?
    -cand facem assignment la T& nu const T& - eroare de compilare

    -cand se face non-polimorfic type conversion. type-conversion e permisa atunci cand faci assignment la T& dintr-un temporar U , unde U este copil al lui T

    ```cpp

    ```

```cpp
const int returnByValue()
{
     return 5;
}

int main()
{
    const int &amp;ref { returnByValue() }; 
}
```

- 

    ok, we're extending the lifetime of the copy passed back to main

```cpp
const int&amp; returnByReference()
{
     return 5;
}

int main()
{
    const int &amp;ref { returnByReference() }; 
}
```

- 

    runtime error

```cpp
string get_name()
    {
        string s="magic";
        return s;
    }
    int main()
    {
        string p=get_name();
        std::cout<<p;
}
```

- 

    ok

```cpp
#include <iostream.h>
class cls1
{ int x;
public: cls1(){ x=13; }
int g(){ static int i; i++; return (i+x); } };
class cls2
{ int x;
public: cls2(){ x=27; }
cls1& f(){ static cls1 ob; return ob; } };
int main()
{ cls2 ob;
cout<<ob.f().g();
return 0;
}
```

- 

    - nu exista
    - lipseste namespace std si avem cout

    se afiseaza 14

    static in funtie face sa nu se distruga obiectul la iesirea din functie

```cpp
#include <iostream.h>
class cls1
{ protected: int x;
public: cls1(int i=10) { x=i; }
int get_x() { return x;} };
class cls2: cls1
{ public: cls2(int i):cls1(i) {} };
int main()
{ cls d(37);
cout<<d.get_x();
return 0;
}
```

- 

    - nu exista
    - lipseste namespace std si avem cout

    -nu exista clasa cls

    -daca acolo ar fi cls1 s-ar afisa 37
    -daca acolo ar fi cls2 ar fi eraore(mostenirea e automat privata)

```cpp
Ruleaza sau nu? Daca da, de ce, daca nu, de ce?
#include <iostream>

class Money
{
public:
    Money() : amount{ 0.0 } {};
    Money(double _amount) : amount{ _amount } {};

    explicit operator double() const { return amount; }
private:
    double amount;
};

void display_balance(const Money balance)
{
    std::cout << "The balance is: " << balance << std::endl;
}
```

- 

    Nu ruleaza pentru ca explicit la conversion opeartor previne conversia implicita catre tipul catre care se converteste.

```cpp
Ruleaza sau nu? Daca da, de ce, daca nu, de ce?
#include 

class Money
{
public:
    Money() : amount{ 0.0 } {};
    Money(double _amount) : amount{ _amount } {};

    double operator double() const { return amount; }
private:
    double amount;
};

void display_balance(const Money balance)
{
    std::cout << "The balance is: " << balance << std::endl;
}
```

- 

    Nu ruleaza pentru ca e ilegal sa pui return type la conversion function.

```cpp
Spuneți dacă programul de mai jos este corect. În caz afirmativ, spuneți ce afișează, în caz negativ spuneți
de ce nu este corect și realizați o modificare astfel încât acesta să compileze fără a-i schimba
funcționalitatea.

#include <iostream>
using namespace std;
class B1 { public: int x; };
class B2 { public: int y; };
class B3 { public: int z; };
class B4 { public: int t; };
class D: public B1, private B2, protected B3, B4 { public: int u; };
int main() {
D d;
cout << d.u;
cout << d.x;
cout << d.y;
cout << d.z;
cout << d.t;
return 0;
}

Dar daca în clasele "B1", "B2", "B3", "B4" în loc de "public" scriam "private" sau "protected"?
```

- 
    1. y, z si t nu functioneaza

```cpp
#include <iostream>
using namespace std;
class B
{
protected:
    int a;
public:
    B()
    {
        a = 7;
    }
};
class D : public B
{
public:
    int b;
    D()
    {
        b = a + 7;
    }
};
int main()
{
    D d;
    cout << d.b;
    return 0;
}
```

- 

    14

```cpp
#include <iostream>
using namespace std;
class cls1
{
protected:
int x;
public:
cls1(int i = 10) { x = i; }
int get_x() { return x; }
};
class cls2 : cls1
{
public:
cls2(int i) : cls1(i) {}
};
int main()
{
cls2 d(37);
cout << d.get_x();
return 0;
}
```

- 

    get_x() nu e accesibil din cls2 pot sa fac mostenire public ca sa fie

```cpp
#include <iostream>
using namespace std;
class B1
{
public:
int x;
};
class B2
{
int y;
};
class B3
{
public:
int z;
};
class B4
{
public:
int t;
};
class D : private B1, protected B2, public B3, B4
{
int u;
};
int main()
{
D d;
cout << d.u;
cout << d.x;
cout << d.y;
cout << d.z;
cout << d.t;
return 0;
}
```

- 

    nu merge decat z-ul

    ca sa il fac sa mearga trebuie sa fac toate mostenirile publice si sa modific la y si u specificatorii de acces in public

```cpp
#include <iostream>
using namespace std;
class B
{
int x;
public:
B(int i = 0) { x = i; }
};
class D : public B
{
public:
D() : B(15) {}
int f() { return x; }
};
int main()
{
D d;
cout << d.f();
return 0;
}
```

- 

    nu merge ca x e private. daca il fac protected se afiseaza 15

```cpp
#include <iostream>
using namespace std;
class A
{
protected:
int x;
public:
A(int i = 14) { x = i; }
};
class B : A
{
public:
B(B &b)
{
x = b.x;
}
void afisare()
{
cout << x;
}
};
int main()
{
B b1, b2(b1);
b2.afisare();
return 0;
}
```

- 

    nu merge. am definic CC si obligatoriu trebuie sa definesc si constructorul

    daca definesc constructorul fara parametri afiseaza 14

```cpp
#include <iostream>
using namespace std;
class A
{
protected:
int x;
public:
A(int i = 14) { x = i; }
};
class B : A
{
public:
B() : A(2) {}
B(B &b) { x = b.x - 14; }
void afisare() { cout << x; }
};
int main()
{
B b1, b2(b1);
b2.afisare();
return 0;
}
```

- 

    -12

```cpp
#include <iostream>
using namespace std;
class A
{
int x;
public:
A(int i) : x(i) {}
int get_x() { return x; }
};
class B : public A
{
int y;
public:
B(int i, int j) : y(i), A(j) {}
int get_y() { return y; }
};
class C : protected B
{
int z;
public:
C(int i, int j, int k) : z(i), B(j, k) {}
int get_z() { return z; }
};
int main()
{
C c(1, 2, 3);
cout << c.get_x() + c.get_y() + c.get_z();
return 0;
}
```

```cpp
Problema 52:

#include <iostream.h>
class B
{ protected: static int x;
             int i;
  public: B() { x++; i=1; }
          ~B() { x--; cout << "b";}
          int get_x() { return x; }
          int get_i() { return i; } };
int B::x;
class D: public B
{ public: D() { x++; }
          ~D() { x--; cout << "d";} };
int f(B *q)
{ return (q->get_x())+1; }
int main()
{ B *p=new B[10];
  cout<<f(p);
  delete[] p;
  p=new D;
  cout<<f(p);
  delete p;
  
  cout<<D::get_x();
  return 0;
}
```

- 

    nu ruleaza pentru ca get_x nu e metoda statica

    daca fac get_x metoda statica se afiseaza 11bbbbbbbbbb3b1

    se observa ca nu se apeleaza destructorul pentru D pentru ca p este un B* iar destructorul din B nu e virtual

    daca fac destuctorul virtual atunci se afiseaza 11bbbbbbbbbb3db0

```cpp
#include <iostream>
template <class T>
int f(T x, T y)
{
    return x + y;
}
int f(int x, int y)
{
    return x - y;
}
int main()
{
    int a = 5;
    float b = 8.6;
    std::cout << f(a, b);
    return 0;
}
```

- 

    -3

```cpp
#include <iostream.h>
class cls {
    int *v, nr;

public:
    cls(int i = 0)
    {
        nr = i;
        v = new int[i];
        for (int j = 0; j < size(); j++)
            v[j] = 3 * j;
    }
    ~cls() { delete[] v; }
    int size() { return nr; }
    int& operator[](int i) { return v[i]; }
    cls operator+(cls);
};
cls cls::operator+(cls y)
{
    cls x(size());
    for (int i = 0; i < size(); i++)
        x[i] = v[i] + y[i];
    return x;
}
int main()
{
    cls x(10), y = x, z;
    x[3] = y[6] = -15;
    z = x + y;
    for (int i = 0; i < x.size(); i++)
        cout << z[i];
    return 0;
}
```

- 

    ruleaza dar afiseaza garbege ca se distruge obiectul inainte sa fie returnat

```cpp
Spuneti in ce ordine se apeleaza constructorii si destructorii
#include <iostream.h>
class cls {
    int *v, nr;

public:
    cls(int i = 0)
    {
        nr = i;
        v = new int[i];
        for (int j = 0; j < size(); j++)
            v[j] = 3 * j;
    }
    ~cls() { delete[] v; }
    int size() { return nr; }
    int& operator[](int i) { return v[i]; }
    cls operator+(cls);
};
cls cls::operator+(cls y)
{
    cls x(size());
    for (int i = 0; i < size(); i++)
        x[i] = v[i] + y[i];
    return x;
}
int main()
{
    cls x(10), y = x, z;
    x[3] = y[6] = -15;
    z = x + y;
    for (int i = 0; i < x.size(); i++)
        cout << z[i];
    return 0;
}
```

- 

    divided by lines of code:

    cls()cls(ob)cls()

    cls(ob)cls()~cls()~cls()
    238920 200256 12 -30 24 30 -30 42 48 54 ~cls()~cls()~cls()

```cpp
#include <iostream>
class B {
    int i;

public:
    B() { i = 1; }
    int get_i() { return i; }
};
class D : public B {
    int j;

public:
    D() { j = 2; }
    int get_j() { return j; }
};
int main()
{
    B* p;
    int x = 0;
    if (x)
        p = new B;
    else
        p = new D;
    if (typeid(p).name() == "D*")
        std::cout << ((D*)p)->get_j();
    return 0;
}
```

- 

    daca nu ii pun #include <typeinfo> nu compileaza

    daca are typeinfo compileaza dar nu afiseaza nimic

```cpp
#include <iostream>
#include <typeinfo>
class B {
    int i;

public:
    B() { i = 1; }
    int get_i() { return i; }
};
class D : public B {
    int j;

public:
    D() { j = 2; }
    int get_j() { return j; }
};
int main()
{
    B* p;
    int x = 0;
    if (x)
        p = new B;
    else
        p = new D;
    if (typeid(p).name() == typeid(D*).name())
        std::cout << ((D*)p)->get_j();
    return 0;
}
```

- 

    compileaza dar nu afiseaza nimic ⇒ nu merge faze cu typeid(D*)

```cpp
#include<iostream>
using namespace std;
template<class X>void test(X &a, X &b)
{
    X temp;
    temp=a;
    a=b;
    b=temp;
    cout<<"ttest\n";
}
void test(int &c,int &d)
{
    int temp;
    temp=c;
    c=d;
    d=temp;
    cout<<"test 1\n";
}
void test(int e,int f)
{
    int temp;
    temp=e;
    e=f;
    f=temp;
    cout<<"test 2\n";
}
void test(int g,int *h)
{
    int temp;
    temp=g;
    g=*h;
    *h=temp;
    cout<<"test 3\n";
}
int main()
{
    int a=5,b=15,c=25,*d=&a;
    test(a,b);
    test(c,d);
    return 0;
}
```

- 
    - nu compileaza, e ambiguu pentru ca poate sa intre si pe ttest si pe test1 si pe test2
    - interesant e ca intra pe ttest aka pe template fara sa ii dau eu f<int> dar la clase trebuie neaparat sa ii dai tipul
    - daca ii tai functia cu test 1 sau cu test 2 merge
    - sau daca modific linia din main int a=5,b=&a,c=25,*d=&a;

```cpp
#include <iostream.h>
class cls {
    int vi;

public:
    cls(int v = 37) { vi = v; }
    friend int& f(cls);
};
int& f(cls c) { return c.vi; }
int main()
{
    const cls d(15);
    f(d) = 8;
    cout << f(d);
    return 0;
}
```

- 

    ruleaza dar nu afiseaza nimic , undefined behaviour

```cpp
#include<iostream>
#include<typeinfo>
using namespace std;
class B
{
    int i;
public:
    B() { i=1;}
    int get_i() {return i;}
};
class D: public B
{
    int j;
public:
    D() {j=2;}
    int get_j(){return j;}
};
int main()
{
    B *p=new D;
    cout<<p->get_i();
    if(typeid((B*)p).name()=="D*") cout<<((D*)p)->get_j();
    return 0;
}
```

- 

    compileaza si afiseaza 1 pe consola

```cpp
#include <iostream>
using namespace std;
class A
{ protected: static int x;
  public: A(int i=1) {x=i; }
  int get_x() { return x; }
  int& set_x(int i) { int y=x; x=i; return y;}
  A operator=(A a1) { set_x(a1.get_x()); return a1;}
} a(33);
int main()
{ A a(18), b(7);
  cout<<(b=a).set_x(27);
  return 0;
}
```

- 

    nu compileaza pentru ca nu l-am initializat pe x

```cpp
#include <iostream>
using namespace std;
class A
{ protected: static int x;
  public: A(int i=1) {x=i; }
  static int get_x() { return x; }
  int& set_x(int i) { int y=x; x=i; return y;}
  A operator=(A a1) { set_x(a1.get_x()); return a1;}
} a(33);
int A::x;
int main()
{
  cout<<A::get_x();
  return 0;
}
```

- 

    se afiseaza 33. concluzie: mai intai se initializeaza x si apoi se construieste a, chiar daca a e inaintea lui x in cod.

```cpp
#include <iostream>
using namespace std;
class A
{ protected: static int x;
  public: A(int i=1) {x=i; }
  int get_x() { return x; }
  int& set_x(int i) { int y=x; x=i; return y;}
  A operator=(A a1) { set_x(a1.get_x()); return a1;}
} a(33);
int A::x;
int main()
{ A a(18), b(7);
  cout<<(b=a).set_x(27);
  return 0;
}
```

- 

    compileaza dar am runtime error

```cpp
#include <iostream>
using namespace std;
class A
{ protected: static int x;
  public: A(int i=1) {x=i; }
  int get_x() { return x; }
  int& set_x(int i) { int y=x; x=i; return y;}
  A operator=(A a1) { set_x(a1.get_x()); return a1;}
} a(33);
int A::x;
int main()
{ A a(18), b(7);
  cout<<(b=a).get_x();
  return 0;
}
```

- 

    compileaza si afiseaza 7

```cpp
#include <iostream>
using namespace std;
class A
{ protected: static int x;
  public: A(int i=1) {x=i; }
  int get_x() { return x; }
  int& set_x(int i) { int y=x; x=i; return y;}
  A operator=(A a1) { cout<<set_x(a1.get_x()); return a1;}
} a(33);
int A::x;
int main()
{ A a(18), b(7);
  cout<<(b=a).get_x();
  return 0;
}
```

- 

    runtime error

```cpp
#include <iostream>
using namespace std;
class B {
protected:
    static int x;
    int i;

public:
    B()
    {
        x++;
        i = 1;
    }
    ~B() { x--; }
    static int get_x() { return x; }
    int get_i() { return i; }
};
int B::x;
class D : public B {
public:
    D() { x++; }
    ~D() { x--; }
};
int f(B* q)
{
    return (q->get_x()) + 1;
}
int main()
{
    B* p = new B[10];
    cout << f(p);
    delete[] p;
    p = new D;
    cout << f(p);
    delete p;
    cout << D::get_x();
    return 0;
}
```

- 

    1131

```cpp
#include <iostream>
using namespace std;
class A
{   protected: int x;
    public: A(int i):x(i){}
            int get_x(){ return x; } };
class B: A
{   protected: int y;
    public: B(int i,int j):y(i),A(j){}
            int get_y(){ return get_x()+y; } };
class C: protected B
{   protected: int z;
    public: C(int i,int j,int k):z(i),B(j,k){}
            int get_z(){ return get_x()+get_y()+z; } };
int main()
{   C c(5,6,7);
    cout<<c.get_z();
    return 0;
}
```

- 

    get_x() e inaccesibil

    rezolv prin a schimba mostenirea in public sau protected

    warning-ri ca se initializeaza prost in lista de initializare

```cpp
#include <iostream.h>

class cls {
public:
    float sa;
    cls(float s = 0) { sa = s; }
    operator float() { return sa; }
    float f(float c) { return (sa * (1 + c / 100)); }
};

void main()
{
    cls p(100);
    cout << p.f(p);
}
```

- 

    nu compila ca main-ul nu poate fi void

    dar in afara de asta compileaza si afiseaza 200 pentru ca aparent daca am 6.0 o sa afiseze 6 nu 6.0 desi e float

```cpp
#include <iostream>
using namespace std;

class B {
public:
	int x;
	B(int i = 16) { x = i; }
	B(){}
	B f(B ob) { return x + ob.x; }
};
class D : public B {
public:
	D(int i = 25) { x = i; }
	B f(B ob) { return x + ob.x + 1; }
	void afisare() { cout << x; }
};
int main()
{
	B *p1 = new D, *p2 = new B, *p3 = new B(p1->f(*p2));
	cout << p3->x;
	return 0;
}
```

- 

    nu compileaza, cei 2 constructori fara parametri de la B fac ambiguitate

    daca sterg al doilea constructor fara parametri  se afiseaza 41 pentru ca f nu e virtual si cum p1 e B* se dupe pe varianta de B

```cpp
#include <iostream>
using namespace std;
class A
{   static int *x;
    public: A() {}
            int get_x() { return (++(*x))++; } };
int *A::x(new int(19));
int main()
{   A *p=new A,b;
    cout<<b.get_x()<<" ";
    cout<<p->get_x();
    return 0;
}
```

- 

```cpp
#include <iostream>
using namespace std;
class A {
protected:
    int x;

public:
    A(int i = 14) { x = i; }
};
class B : A {
public:
    B()
        : A(2)
    {
    }
    B(B& b) { x = b.x - 14; }
    void afisare() { cout << x; }
};
int main()
{
    B b1, b2(b1);
    b2.afisare();
    return 0;
}
```

- 

    -12

```cpp
#include <iostream>
class B {
public:
    int x;
    B(int i = 16) { x = i; }
    B f(B ob) { return x + ob.x; }
};
class D : public B {
public:
    D(int i = 25) { x = i; }
    B f(B ob) { return x + ob.x + 1; }
    void afisare() { std::cout << x; }
};
int main()
{
    B *p1 = new D, *p2 = new B, *p3 = new B(p1->f(*p2));
    std::cout << p3->x;
    return 0;
}
```

- 

    41

```cpp
#include <iostream>
using namespace std;

class A
{
public: int x;
public: A(int i = -16) { x = i; }
		virtual A f(A a) { return x + a.x; }
		void afisare() { cout << x; }
};
class B: public A
{
public: B(int i=3):A(i){}
		A f(A a) { return x + a.x + 1; }
};
int main()
{
	A *p1 = new B, *p2 = new A, *p3 = new A(p1->f(*p2));
	p3->afisare();
	return 0;
}
```

- 

    nu compileaza la linia A f(A a) { return x + a.x + 1; } pentru ca nu a.x e protected

    daca il fac e x public compileaza si afiseaza -12

```cpp
#include <iostream>
using namespace std;

class A
{
	int x;
public: A(int i = 17) { x = i; }
		int get_x() { return x; }
};
class B
{
	int x;
public: B(int i = -16) { x = i; }
		operator A() { return x; }
		int get_x() { return x; }
};
int main()
{
	B a;
	A b = a;
	cout << b.get_x();
	return 0;
}
```

- 

    -16

```cpp
#include <iostream>
using namespace std;

class A
{
	int x;
public: A(int i = 17) { x = i; }
		int get_x() { return x; }
};
class B : A
{
	int x;
public: B(int i = -16) : A() { x = i; }
		operator A() { return x; }
		int get_x() { return x; }
};
int main()
{
	B b;
	A a = b;
	cout << a.get_x();
	return 0;
}
```

- 

    eroare de compilare: la linia `A a = b;` A is an inaccessible base of B

    cand am mostenire privata, practic nu vreau sa se stie pentru restul programului ca intre cele 2 clase exista mostenire

    observati ca nu da eroare la linia public: `B(int i = -16) : A() { x = i; }` pentru ca din interiorul clasei se stie ca exista o mostenire

```cpp
#include <iostream>
using namespace std;

class A
{
	int x;
public: A(int i = 17) { x = i; }
		int get_x() { return x; }
};
class B : A
{
	int x;
public: B(int i = -16) : A() { x = i; B b; A a=b;}
		operator A() { return x; }
		int get_x() { return x; }
};
int main()
{
	B b;
	//A a = b;
	cout << b.get_x();
	return 0;
}
```

- 

    super tare! deci nu am voie sa fac casting in main unui obiect de tip B la baza sa A pentru ca main-ul nu stie ca exista mostenire intre cele 2

    in schimb in interiorul constructorului lui B pot sa fac asta

```cpp
#include <iostream>
using namespace std;

class A
{
	int x;
public: A(int i = 17) { x = i; }
		virtual int get_x() { return x; }
};
class B : A
{
	int x;
public: B(int i = -16) : A() { x = i; B* b= new B; A* a = dynamic_cast<A*> (b);}
		operator A() { return x; }
		int get_x() { return x; }
};
int main()
{
	B* b= new B;
	//A* a = dynamic_cast<A*> (b);
	cout << b->get_x();
	return 0;
}
```

- 

    la fel pentru cazul asta: daca incerc sa fac dynamic_cast in main pentru ca nu recunoaste baza

    dar in constructorul lui B pot sa fac asta bine mersi

    programul ruleaza, dar imi da runtime error

    okay, aparent dadaea runtime error ca alocam un alt obiect pe stiva in constructorul lui B of course, aveam ciclu infinit:)) acum ca am mutat dynamic cast-ul in get_x() merge fara probleme

```cpp
#include <iostream>
using namespace std;

class A
{
protected: int x;
public: A(int i = -16) { x = i; }
		virtual A f(A a) { return x + a.x; }
		void afisare() { cout << x; }
};
class B: public A
{
public: B(int i=3):A(i){}
		A f(A a) { return x + 1; }
		B operator+ (B a) { return x + a.x; }
};
int main()
{
	B a; int b = -21;
	a += b;
	cout << b;
	return 0;

}
```

- 

    no match for opartor +=

```cpp
#include <iostream>
using namespace std;

class A
{
	int x;
public:
	A(int i):x(i){}
	int get_x() const { return x; }
};
class B : public A
{
	int *y;
public:
	B(int i) :A(i)
	{
		y = new int[i];
		for (int j = 0; j < i; j++) y[j] = 1;
	}
	B(B&);
	int &operator[](int i) { return y[i]; }
};
B::B(B& b)
{
	y = new int[b.get_x()];
	for (int i = 0; i < b.get_x(); i++) y[i] = b[i];
}
ostream &operator<<(ostream& o, B a)
{
	for (int i = 0; i < a.get_x(); i++)o << a[i];
	return o;
}
int main()
{
	B b(5);
	cout << b;
	return 0;
}
```

- 

    eroare: no matching function for call to A::A() de ce? copy-constructer-ul nu este chained ca constructorii normali; adica cc din B nu apeleaza automat cc din A. in schimb apeleaza automat constructorul fara parametri din A.

```cpp
#include <iostream>
using namespace std;
class A {
    int x;

public:
    A(int i) { x = i; }
    int get_x() { return x; }
    int& set_x(int i) { x = i; }
    A operator=(A a1)
    {
        set_x(a1.get_x());
        return a1;
    }
};
class B : public A {
    int y;

public:
    B(int i)
        : A(i)
    {
        y = i;
    }
    void afisare() { cout << y; }
};
int main()
{
    B a(112), b, *c;
    cout << (b = a).get_x();
    (c = &a)->afisare();
    return 0;
}
```

- 

    nu are parametru default pentru B

    daca pun parametru default la B o sa afiseze 112112

```cpp

#include <iostream>
using namespace std;

class A
{
	int x;
public:
	A(int i=0):x(i){cout<<"A()";}
	int get_x() const { return x; }
	~A() {cout<<"~A()";}
};
class B : public A
{
	int *y;
public:
	B(int i) :A(i)
	{
	    cout<<"B()";
		y = new int[i];
		for (int j = 0; j < i; j++) y[j] = 1;
	}
	B(B&);
	int &operator[](int i) { return y[i]; }
	~B() {cout<<"~B()";}
};
B::B(B& b)
{
    cout<<"B(ob)";
	y = new int[b.get_x()];
	for (int i = 0; i < b.get_x(); i++) y[i] = b[i];
}
ostream &operator<<(ostream& o, B a)
{
	for (int i = 0; i < a.get_x(); i++)o << a[i];
	return o;
}
int main()
{
	B b(5);
	cout << b;
	return 0;
}
```

- 

    A()B()A()B(ob)~B()~A()~B()~A()

```cpp
#include <iostream>
class A {
    static int x;

public:
    A(int i = 0) { x = i; }
    int get_x() { return x; }
    int& set_x(int i) { x = i; }
    A operator=(A a1)
    {
        set_x(a1.get_x());
        return a1;
    }
};
int A::x;
int main()
{
    A b, a(212);
    std::cout << (b = a).get_x();
    return 0;
}
```

- 

    212

```cpp
#include <iostream>
using namespace std;
class B {
private
    static int x;
    int i;

public:
    B()
    {
        x++;
        i = 1;
    }
    ~B() { x--; }
    static int get_x() { return x; }
    int get_i() { return i; }
};
int B::x;
class D : public B {
public:
    D() { x++; }
    ~D() { x--; }
};
int f(B* q)
{
    return (q->get_i()) + 1;
}
int main()
{
    B* p = new B;
    cout << f(p);
    delete p;
    p = new D;
    cout << f(p);
    delete p;
    cout << D::get_x();
    return 0;
}
```

- 

    nu compileaza: x e private in B si va fi innacesibil in D (mare grija laspecificatorul de acces de la campurile statice →doar fiindca sunt statice nu inseamna ca pot fi modificate de oricine)

    solutie: il fac pe B protected sau public

```cpp
#include <iostream>
template <class T, class U>
T f(T x, U y)
{
    return y;
}
int f(int x, int y)
{
    return x - y;
}
int main()
{
    int *a = new int(3), b(23);
    std::cout << *f(a, b);
    return 0;
}
```

- 

    invalid conversion from int to int*

    solutie posibila: `return x+y;`

```cpp
#include <iostream>
template <class T, class U>
T f(T x, U y)
{
    return x+y;
}
int f(int x, int y)
{
    return x - y;
}
int main()
{
    int *a = new int(3), b(23);
    std::cout << *f(a, b);
    return 0;
}
```

- 

    compileaza si afiseaza o valoare nedeterminata, cu 23 de spatii la "dreapta" adresei catre care arata a

```cpp
#include <iostream>
class problema {
    int i;

public:
    problema(int j = 5) { i = j; }
    void schimba() { i++; }
    void afiseaza() { std::cout << "starea curenta " << i << "\n"; }
};
problema mister1() { return problema(6); }
void mister2(problema& o)
{
    o.afiseaza();
    o.schimba();
    o.afiseaza();
}
int main()
{
    mister2(mister1());
    return 0;
}
```

- 

    aici se vede o bucatica din ce am invatat la lifetime extension: nu compileaza, nu ai voie sa initializezi o referinta cu o valoare temporara (rvalue)

    rezolvare: 

    ```cpp
    void mister2(problema o)//am sters referinta de aici
    {
        o.afiseaza();
        o.schimba();
        o.afiseaza();
    }
    ```

    sau

    ```cpp
    void mister2(const problema& o)//asta e fix lifetime extension, initializez o const
                     //reference cu o valoare temporara si i sa mareste durata de viata
    {
        o.afiseaza();
    //    o.schimba();
    //    o.afiseaza();
    }
    ```

```cpp
#include <iostream>

class D;

class B {
    int x;
    friend void f(B, D);

public:
    B(int i = 0) { x = i; }
};

class D : public B {
public:
    int y;
    D(int i = 0, int j = 0)
        : B(i)
    {
        y = j;
    }
};

void f(B b, D d) { std::cout << b.x << " " << d.y; }//daca functia asta era inaite de D nu 
																										//mergea

void main()
{
    B b;
    D d;
    f(b, d);
}
```

- 

    nu compileaza ca nu ai voie sa ai void main

    dar in afara de asta functioneaza, si afiseaza 0 0

```cpp
#include <iostream>
using namespace std;
int f(int y)
{
    if (y < 0)
        throw y;
    return y / 2;
}
int f(int y, int z)
{
    if (y < z)
        throw z - y;
    return y / 2;
}
float f(int& y)
{
    cout <<"y este referinta";
    return (float)y / 2;
}
int main()
{
    int x;
    try {
        cout <<"Da - mi un numar par : ";
        cin >> x;
        if (x % 2)
            x = f(x, 0);
        else
            x = f(x);
        cout <<"Numarul "<< x <<" e bun !"<< endl;
    }
    catch (int i) {
        cout <<"Numarul ”<< i <<” nu e bun !"<< endl;
    }
    return 0;
}
```

- 

    ambiguitate la f(x)

    ca sa rezolv ambiguitatea pun o dummy variable la `int f(int y, float p)`

```cpp
#include <iostream>
using namespace std;
struct B {
    int i;

public:
    B() { i = 1; }
    virtual int get_i() { return i; }
} a;
class D : virtual public B {
    int j;

public:
    D() { j = 2; }
    int get_i() { return B::get_i() + j; }
};
class D2 : virtual public B {
    int j2;

public:
    D2() { j2 = 3; }
    int get_i() { return B::get_i() + j2; }
};
class MM : public D2, public D {
    int x;

public:
    MM() { x = D::get_i() + D2::get_i(); }
    int get_i() { return x; }
};
{
    MM b;
}
int main()
{
    B* o = new MM();
    cout << o->get_i() << "\n";
    MM* p = dynamic_cast<MM*>(o);
    if (p)
        cout << p->get_i() << "\n";
    D* p2 = dynamic_cast<D*>(o);
    if (p2)
        cout << p2->get_i() << "\n";
    return 0;
}
```

- 

    nu compileaza aici: 

    `{
        MM b;
    }`

    apparently random curly braces outside of main are a nono

    ca sa compileze pur si simplu tai bucata aia si afiseaza 7\n7\n7

```cpp
#include <iostream>
using namespace std;
class B
{ int i;
  public: B() { i=80; }
          virtual int get_i() { return i; }
};
class D: public B
{ int j;
  public: D() { j=27; }
          int get_j() {return j; }
};
int main()
{ D *p=new B;
  cout<<p->get_i();
  cout<<((D*)p)->get_j();
  return 0;
}
```

- 

    nu compileaza, dsaca modific `D *p=new D;` afiseaza 8027 

```cpp
#include<iostream>
using namespace std;
class B
{
    protected: int x;
    public: B(int i=0) {x=i;}
    virtual B minus() {return (1-x);}
};
class D: public B
{
    public: D(int i=0):B(i) {}
    void afisare() {cout<<x;}
};
int main()
{
    D *p1=new D(18);
    *p1=p1->minus();
    p1->afisare();
    return 0;
}
```

- 

    nu compileaza, nu am operator = intre D si B la linia `*p1=p1->minus();` ⇒ linia asta

```cpp
#include <iostream>

class B {
    int x;

public:
    B(int v) { v = x; }
    int get_x() { return x; }
};

class D : private B {
    int y;

public:
    D(int v)
        : B(v)
    {
    }
    int get_x() { return x; }
};

int main()
{
    D d(10);
    std::cout << d.get_x();
}
```

- 

    nu compileaza: nu am acces la x din get_x()-ul din clasa B

    daca modific sa returneaza y merge si afiseaza o valoare nedeterminata

```cpp
#include <iostream>

class B {
    int x;

public:
    B(int v) { v = x; }
    int get_x() { return x; }
};

class D : private B {
    int y;

public:
    D(int v)
        : B(v)
    {
			std::cout<<get_x();
    }
    int get_y() { return y; }
};

int main()
{
    D d(10);
    std::cout << d.get_y();
}
```

- 

    interesant e ca asta compileaza

    deci am acces la functiile private din A in B, dar nu pot sa le apelez din main

```cpp
#include <iostream>
class B {
    int x;

public:
    B(int i = 17) { x = i; }
    int get_x() { return x; }
    operator int() { return x; }
};
class D : public B {
public:
    D(int i = -16)
        : B(i)
    {
    }
};
int main()
{
    D a;
    std::cout << 27 + a;
    return 0;
}
```

- 

    11

```cpp
#include <iostream.h>
template <class T, class U>
T f(T x, U y)
{
    return x + y;
}
int f(int x, int y)
{
    return x - y;
}
int main()
{
    int *a = new int(3), b(23);
    cout << *f(a, b);
    return 0;
}
```

- 

    nu compileaza, nu pot sa adun 2 pointeri

    daca fac template-ul sa returneze doar x merge, sau daca il fac si pe a int normal

```cpp
#include <iostream>
using namespace std;
class A
{
    int x;
public:
    A(int i = 25)
    {
        x = i;
    } 
    int& f() const
    {
        return x;
    }
};
int main()
{
    A ob(5);
    cout << ob.f();
    return 0;
}
```

- 

    am functie const care promite ca nu modifica functia si apoi returnez o referinta la int prin care se poate modifica valoarea lui x, contradictie cu const deci nu ruleaz

    daca scot & sau const merge

```cpp
#include <iostream>
using namespace std;
class B
{
public:
    int x;
    B(int i = 16)
    {
        x = i;
    }
    B f(B ob)
    {
        return x + ob.x;
    }
};
class D : public B
{
public:
    D(int i = 25)
    {
        x = i;
    }
    D f(D ob)
    {
        return x + ob.x + 1;
    } void afisare()
    {
        cout << x;
    }
};
int main()
{
    D *pl = new D, *p2 = new B, *p3 = new D(pl->f(*p2)) cout << p3->x;
    return 0;
}
```

- 

    am facut D* la B* si nu am voie deci nu ruleaza

    daca il fac pe p2 sa pointeze la D merge

```cpp
#include <iostream.h>
class cls {
    int x;

public:
    cls(int i) { x = i; }
    int set_x(int i)
    {
        int y = x;
        x = i;
        return y;
    }
    int get_x() { return x; }
};
int main()
{
    cls* p = new cls[10];
    int i = 0;
    for (; i < 10; i++)
        p[i].set_x(i);
    for (i = 0; i < 10; i++)
        cout << p[i].get_x(i);
    return 0;
}
```

- 

    nu am constructor fara parametri la cls si mai e eroarea de la `cout << p[i].get_x(i);` ca nu am get_x parametrizat

    daca corectez astea 2 erori afiseaza 0123456789

```cpp
#include <iostream>
using namespace std;
class clsl
{
protected:
    int x;
public:
    clsl(int i=10)
    {
        x=i;
    }
    int get_x()
    {
        return x;
    }
};
class cls2: clsl
{
public:
    cls2(int i):clsl(i) {}
};
int main()
{
    cls2 d(37);
    cout<<d.get_x();
    return 0;
}
```

- 

     nu merge pentru ca get_x e o metoda privata a lui cls2

    ce se intampla aici e ca tot ce era protected sau public in cls1 devine private in cls2.

    ce era privat in cls1 devine inaccesibil

```cpp
#include <iostream.h>

class D;

class B {
    int x;
    friend void f(B, D);

public:
    B(int i = 0) { x = i; }
};

class D : public B {
public:
    int y;
    D(int i = 0, int j = 0)
        : B(i)
    {
        y = j;
    }
};

void f(B b, D d) { cout << b.x << " " << d.y; }

void main()
{
    B b;
    D d;
    f(b, d);
}
```

- 

    compileaza si afiseaza 0 0?

    de ce?

    D are fix campurile lui B, nu se modifica niciun specificator de acces, ceea ce inseamna ca il are pe x privat si il poate accesa din clasa

```cpp
#include <iostream.h>
#include <typeinfo>
class B {
    int i;

public:
    B() { i = 1; }
    int get_i() { return i; }
};
class D : B {
    int j;

public:
    D() { j = 2; }
    int get_j() { return j; }
};
int main()
{
    B* p = new D;
    cout << p->get_i();
    if (typeid((B*)p).name() == "D*")
        cout << ((D*)p)->get_j();
    return 0;
}
```

- 

    crapa de aici: `B* p = new D;` B este o baza inaccesibila a lui D ⇒ main-ul nici macar nu stie ca are loc o mostenire

    !!!!! nu o sa mearga daca inlocuiesc mosetnirea privata cu protected

    pentru main private si protected sunt acelasi lucru ⇒ ii trebuie mostenire publica

```cpp
#include <iostream.h>

class cls {
    int vi;

public:
    cls(int v = 18) { vi = v; }
    operator int() { return vi; }
    cls operator++()
    {
        vi++;
        return *this;
    }
    cls operator++(int);
};

cls cls::operator++(int)
{
    cls aux = *this;
    vi++;
    return aux;
}

void main()
{
    cls p(20);
    int x = p++, y = ++p;
    cout << "x=" << x << ", y=" << y << endl;
}
```

- 

    afiseaza 20 22

```cpp
#include <iostream.h>
class B {
protected:
    int x;

public:
    B(int i = 28) { x = i; }
    virtual B f(B ob) { return x + ob.x + 1; }
    void afisare() { cout << x; }
};
class D : public B {
public:
    D(int i = -32)
        : B(i)
    {
    }
    B f(B ob) { return x + ob.x - 1; }
};
int main()
{
    B *p1 = new D, *p2 = new B, *p3 = new B(p1->f(*p2));
    p3->afisare();
    return 0;
}
```

- 

    nu compileaza

    nu am acces la ob.x aici: `B f(B ob) { return x + ob.x - 1; }`

    am acces la x-ul care a apelat funcia, nu si la al celorlalte obiecte

```cpp
#include <iostream>
using namespace std;
class A
{
public:
    int x;
    A(int i = -13)
    {
        x = i;
    }
};
class B : virtual public A
{
public:
    B(int i = -15)
    {
        x = i;
    }
};
class C : virtual public A
{
public:
    C(int i = -17)
    {
        x = i;
    }
};
class D : virtual public A
{
public:
    D(int i = -29)
    {
        x = i;
    }
};
class E : public B, public D, public C
{
public:
    int y;
    E(int i, int j) : D(i), B(j)
    {
        y = x + i + j;
    }
    E(E& ob)
    {
        y = ob.x - ob.y;
    }
};
int main()
{
    E el(5, 10), e2 = el;
    cout << e2.y;
    return 0;
}
```

- 

    ruleaza si afiseaza -15

    de ce? 

    1. il construieste pe e1 din 5 si 10 adica x=10 si y=25
    2. il construieste pe e2 cu cc din E care apeleaza pe rand constructorii fara parametri din B, D si C; cum astia doar rescriu x-ul, x o sa ia ultima valoare pe care i-0 dam adica -17, iar y o sa fie cel din cc, adica -15

     

```cpp
#include <iostream.h>
class cls {
    int x;

public:
    cls(int i = 25) { x = i; }
    int f();
};
int cls::f() { return x; }
int main()
{
    const cls d(15);
    cout << d.f();
    return 0;
}
```

- 

    passing const as this discards qualifiers

    daca il fac pe f const merge

```cpp
#include <iostream>
using namespace std;
class A {
    static int x;

public:
    A(int i = 0) { x = i; }
    int get_x() { return x; }
    int& set_x(int i) { x = i; }
    A operator=(A a1)
    {
        set_x(a1.get_x());
        return a1;
    }
};
int main()
{
    A a(212), b;
    cout << (b = a).get_x();
    return 0;
}
```

- 

    nu compileaza, nu l-am initializat pe x

```cpp
#include <iostream>
using namespace std;
struct X
{
    int i;
public:
    X(int ii )
    {
        i = ii;
    };
    int f1()
    {
        return i;
    }
    X f2() const
    {
        int i=this->f1();
        return X(34-i);
    }
};
const X f3()
{
    return X(16);
}
int f4(const X& x)
{
    return x.f1();
}
int main()
{
    X ob(11);
    cout<<f4(ob.f2().f1());
    return 0;
}
```

- 

    eroare: `passing const X as this discards qualifiers`  

    deeeci chiar daca obiectul nu era const inainte, odata ce il transmit unei functii const nu mai pot sa il transmit din functia aia in alte functii neconst

    ⇒il fac pe f1 const si afiseaza 23

```cpp
Ordinea in care se apelaza constructorii si destrictorii:
#include <iostream>
using namespace std;
struct X
{
    int i;
public:
    X(int ii )
    {
        i = ii;
        cout<<"X()";
    };
    X(const X& ob)
    {
        i=ob.i;
        cout<<"X(ob)";
    }
    ~X()
    {
        cout<<"~X()";
    }
    int f1() const
    {
        return i;
    }
    X f2() const
    {
        int i=this->f1();
        return X(34-i);
    }
};
const X f3()
{
    return X(16);
}
int f4(const X& x)
{
    return x.f1();
}
int main()
{
    X ob(11);
    cout<<"\n";
    cout<<f4(ob.f2().f1());
    return 0;
}
```

- 

    X() — se construieste ob
    X()X()23~X()~X()~X() —se construieste un obiect la resturn-ul din f2 si se mai construieste unul implicit ca sa fie transmis lui f4, si cele 2 obiecte se distrug dupa afisare

```cpp
#include <iostream>
using namespace std;
class A
{
    int x;
    static int y;
public:
    A(int i,int j):x(i),y(j) {}
    int f() const;
};
int A::y;
int A::f() const
{
    return y;
}
int main()
{
    const A a(21,2);
    cout<<a.f();
    return 0;
}
```

- 

    nu compileaza: **nu ma voie sa pun un static in lista de initializare!!!**

    daca pun `A(int i,int j):x(i) {y=i;}` compileaza

```cpp
#include<iostream>
using namespace std;
class cls
{
    int x;
public:
        cls(int i=0) {cout<<" c1 "; x=i;}
        ~cls() {cout<<" d 1 ";}
};
class cls1
{
    int x; cls xx;
public:
        cls1(int i=0){cout<<" c2 ";x=i;}
        ~cls1(){cout<<" d2 ";}
}c;
class cls2
{
    int x;cls1 xx;cls xxx;
public:
    cls2(int i=0) {cout<<" c3 ";x=i;}
    ~cls2(){ cout<<" d3 ";}
};
int main()
{
    cls2 s;
    return 0;
}
```

- 

    c1 c2 — se construieste obiectul ala global de la cls1

    c1 c2 — se construieste partea de cls1 din s

    c1 — se construieste partea de cls din s

    c3 — se construieste s-ul

    d3 d1 d2 d1 d2 d1 —in ordinea inversa a constructorilor

```cpp
#include <iostream>
#include <typeinfo>
using namespace std;
class B {
    int i;

public:
    B(int x) { i = x + 1; }
    int get_i() { return i; }
};
class D : public B {
    int j;

public:
    D()
        : B(1)
    {
        j = i + 2;
    }
    int get_j() { return j; }
};
int main()
{
    B* p = new D[10];
    cout << p->get_i();
    if (typeid((B*)p).name() == "D*")
        cout << ((D*)p)->get_j();
    return 0;
}
```

- 

    nu compileaza: D() nu are acces la i (nici in corpul functiei nici in ista de initializare)

```cpp
#include <iostream>
class B
{
protected:
    int x;

public:
    B(int i = 28)
    {
        x = i;
    }
    virtual B f(B ob)
    {
        return x + ob.x + 1;
    }
    void afisare()
    {
        std::cout << x;
    }
};
class D : public B
{
public:
    D(int i = -32)
        : B(i)
    {
    }
    B f(B ob)
    {
        return x + ob.x - 1;
    }
};
int main()
{
    B *p1 = new D, *p2 = new B, *p3 = new B(p1->f(*p2));
    p3->afisare();
    return 0;
}
```

- 

    no compileaza: la `B f(B ob)` imi zice int B::x is protected within this context

    de ce la asta nu merge si la o problema de mai devreme, cu aceeasi ierarhie mergea?

    amintesc functia din ierarhia aia:

    ```cpp
    int f(cls2 ob)
    {
        return (ob.x + ob.y);
    }
    ```

    Eu vreau ca din derivata sa accesez date dintr-un obiect de tip baza

    si asta nu se poate

    asta e diferenta dintre cele 2 functii: aia care merge primeste un obiect de tip derivata si cum dunctia se afla in clasa derivata are acces la toate campurile obiectului respectiv

    in schimb cea care nu merge se afla in derivata, primeste un obiect de tip baza si vrea sa ii acceseze campurile, cea ce nu e permis

```cpp
#include <iostream>
using namespace std;
template <class T, class U>
T fun(T x, U y)
{
    return x + y;
}
int fun(int x, int y)
{
    return x - y;
}
int fun(int x)
{
    return x + 1;
}
int main()
{
    int *a = new int(10), b(5);
    cout << fun(a, b);
    return 0;
}
```

- 

    returneaza o adresa de memorie la 5 pasi de adresa de memorie catre care arata a

    **!!!! `cout << *fun(a, b);` daca aveam asa, returna o valoare nedeterminata, aflata la pozitia aia, nu o adresa de memorie**

```cpp
#include <iostream>
using namespace std;
class B {
protected:
    static int x;
    int i;

public:
    B()
    {
        x++;
        i = 1;
    }
    ~B() { x--; }
    static int get_x() { return x; }
    int get_i() { return i; }
};
int B::x;
class D : public B {
public:
    D()
    {
        x++;
        i++;
    }
    ~D()
    {
        x--;
        i--;
    }
    int f1(B o) { return 5 + get_i(); }
};
int f(B* q)
{
    return (q->get_x()) + 1;
}
int main()
{
    B* p = new B[10];
    cout << f(p);
    delete[] p;
    p = new D;
    cout << p->f1(p);
    delete p;
    cout << D::get_x();
    return 0;
}
```

- 

    nu compileaza, in primul rand ca f1 nu e in B

    daca ar fi fost in b si ar fi fost metoda virtuala atunci compilatorul ar fi stiut sa o aleaga pe cea din D 

    dar fiindca tipul declarat al lui p este B si nu am functia asta virtuala in B el o cauta in B si nu o agseste si da eraore

    dar si daca ar fi gasit-o se potrivea signatura cu cea din D

    ⇒ comentez linia aia, sau modific linia astfel : `cout << p->f1(*p);` si mut functia f1 in B

```cpp
#include <iostream>
using namespace std;
class A {
protected:
    static int x;

public:
    A(int i = 0) { x = i; }
    virtual A schimb() { return (7 - x); }
};
class B : public A {
public:
    B(int i = 0) { x = i; }
    void afisare() { cout << x; }
};
int A::x = 5;
int main()
{
    A* p1 = new B(18);
    *p1 = p1->schimb();
    ((B*)p1)->afisare();
    return 0;
}
```

- 

    -11

```cpp
#include <iostream>
using namespace std;
class B
{
protected:
    int x;
public:
    B(int i=0):x(i) {}
    operator int()
    {
        return x;
    }
};
class D: public B
{
public:
    D(int i=0):B(i) {}
    operator B()
    {
        return B();
    };
    operator float()
    {
        return x;
    }
};
int main()
{
    D ob(12);
    try
    {
        throw ob;
    }
    catch (float a)
    {
        cout<<"A";
    }
    catch(B b)
    {
        cout<< "B";
    }
    catch(D d)
    {
        cout << "C";
    }
    catch(...)
    {
        cout<<"D";
    }
    return 0;
}
```

- 

    afiseaza B pentru ca catch-ul se verifica daca se potriveste exact cu tipul, sau daca e o baza neambigua a obiectului aruncat

```cpp
# include <iostream>
using namespace std;
class A
{
    static int x;
    const int y;
public:
    A(int i, int j):x(i),y(j)) {}
    static int f(int z, int v)
    {
        return x + z + v;
    }
};
int A::x;
int main()
{
    A ob(l,-2);
    cout<<ob.f(-3,2);
    return 0;
}
```

- 

    la linia `A(int i, int j):x(i),y(j)) {}` x is a static data member, it can only be initialized at its definition

```cpp
#include<iostream>
#include<vector>
using namespace std;
class Test {int i;
public:
    Test(int x = 0):i(x)
    {
        cout<<"C ";
    };
    Test(const Test& x)
    {
        i = x.i;
        cout<<"CC ";
    } ~Test(){cout<<"D ";}
};
int main()
{
    vector<Test> v;
    cout<<"\n";
    v.push_back(1);
    cout<<"\n";
    Test ob(3);
    cout<<"\n";
    v.push_back(ob);
    cout<<"\n";
    Test& ob2 = ob;
    cout<<"\n";
    v.push_back(ob2);
		cout<<"\n";
    return 0;
}
```

- 

    C CC D — construieste obiectul temporar din 1, il copiaza in vector si il distruge
    C — construieste obiectul din 3
    CC CC D — fiindca vectorul nu are destul spatiu trebuie sa se extinda, si ca sa se extinda face o copie la toate obiectele care sunt deja in vector, dupa care copiaza obiectul ob si sterge obiectul temporar pe care l-a retinut

    CC CC CC D D— la fel, face o copie la toate obiectele existente in vector si apoi copiaza obiectul trimis si sterge obiectele temporare pe care le-a retinut

    D D D D — sterge cele 3 obiecte aflate in vector + obiectul declara in ob

```cpp
#include <iostream>
#include <vector>
using namespace std;
class Test
{
    int i;
public:
    Test(int x = 0):i(x)
    {
        cout<<"C ";
    };
    Test(const Test& x)
    {
        i = x.i;
        cout<<"CC ";
    }
    ~Test()
    {
        cout<<"D ";
    }
};

int main()
{
    vector<Test> v;
    v.push_back(10);
    cout<<endl;
    v.push_back(20);
    cout<<endl;
    Test ob(30);
    v.push_back(ob);
    cout<<endl;
    Test& ob2 = ob;
    v.push_back(ob2);
    cout<<endl;
}
```

- 

```cpp
#include <iostream>
using namespace std;
class cls
{
    int i;
public:
    cls(int j):i(j) {}

    int* f(int *x)
    {
        x[1]=i;
        return x;
    }
};
int main()
{
    cls a(5);
    int x[10];
    for(int i=0; i<10; i++)
        x[i]=10-i;
    cout<<a.f(x)[3]<<" "<<x[2];
    return 0;
}
```

- 

    7 8

```cpp
#include <iostream>
class cls
{
    int x;
public:
    cls(int y)
    {
        x=y;
    }
    friend int operator*(cls a,cls b)
    {
        return (a.x*b.x);
    }
};
int main()
{
    cls m(100),n(15);
    std::cout << m*n;
    return 0;
}
```

- 

    afiseaza 1500. concluzie: daca operatorul * e implementat ca functie friend tot merge sa scriu m*n, nu trebuie sa scriu operator* (m, n)

```cpp
<in#include <iostream>
using namespace std;
class B
{
    int i;

public:
    B()
    {
        i = 1;
    }
    virtual int get_i()
    {
        return i;
    }
};
class D : virtual public B
{
    int j;

public:
    D()
    {
        j = 2;
    }
    int get_i()
    {
        return B::get_i() + j;
    }
};
class D2 : virtual public B
{
    int j2;

public:
    D2()
    {
        j2 = 3;
    }
    int get_i()
    {
        return B::get_i() + j2;
    }
};
class MM : public D, public D2
{
    int x;

public:
    MM()
    {
        x = D::get_i() + D2::get_i();
    }
    int get_i()
    {
        return x;
    }
};
int main()
{
    B* o = new MM();
    cout << o->get_i() << "\n";
    MM* p = dynamic_cast<MM*>(o);
    if (p)
        cout << p->get_i() << "\n";
    D* p2 = dynamic_cast<D*>(o);
    if (p2)
        cout << p2->get_i() << "\n";
    return 0;
}
```

- 

    7\n7\n7

    interesant e ca atunci cand fac un obiect cu new pot sa apelaz constructorul astfel: `new MM();` in timp ce daca doar apelez constructorul nu am voie sa pun paranteze ca se considera declaratie de functie

```cpp
#include<iostream>
using namespace std;
class A
{
    int i;
    public: A() {i=1;}
    virtual int get_i() {return i;}
};
class B: public A
{
    int j;
    public: B() {j=2;}
    int get_i() { return A::get_i()+j;}
};
int main()
{
    const int i=cin.get();
    if(i%3) {A o;}
    else {B o;}
    cout<<o.get_i();
    return 0;
}
```

- 

    da eroare la linia  `cout<<o.get_i();` pentru ca nu stie cine e o pentru ca obiectul a fost distrus in ambele cazuri

    interesant e ca nici daca scriu `if(i%3) {static A o;}` nu merge, desi in functii ar trebui sa mearga

```cpp
#include <iostream>
using namespace std;
class cls1 {
  int x;
public:
  cls1 () {
    x = 13;
  }
  int g() {
    static int i; i++;
    return (i+x);
  }
  afisare()
  {
      cout<<x;
  }
};

class cls2 {
  int x;
public:
  cls2() {
    x = 27;
  }
  cls1& f() {
     cls1 ob; return ob;
  }
};

int main() {
  cls2 ob;
  cout<<ob.f().g();
  return 0;
}
```

- 

    Compileaza, doar ca da undefined behaviour. Cand returnez cls& din f, obiectul deja a fost distrus. Dar nu e asta problema, ideea e ca noi pe obiectul ala distrus apelam g. Si nici asta nu ar fi o problema daca nu am avea x in g. Compilatorul cauta un obiect care nu mai exista la adresa aia si de-aia da undefined behaviour. 

    Daca scriu in g doar  `return i;` in loc de `return (i+x);` o sa mearga si o sa afiseze 1. Ceea ce insemna ca static int i e initializat cu 0 automat.

```cpp
#include <iostream.h>
class A {
    int x;

public:
    A(int i = 0) { x = i; }
    A operator+(const A& a) { return x + a.x; }
    template <class T>
    ostream& operator<<(ostream&);
};
template <class T>
ostream& A::operator<<(ostream& o)
{
    o << x;
    return o;
}
int main()
{
    A a1(33), a2(-21);
    cout << a1 + a2;
    return 0;
}
```

- 

    Nu functioneaza pentru ca << nu isi poate da seama cine este T-ul. In unele cazuri compilatorul isi da seama singur, dar cum T nu intra in discutie in parametri poarte fi oricine. apelarea corecta a afisarii este: `(a1 + a2).operator<<<int>(cout);` Ordinea apelarii constructorilor si desrtuctorilor este: A() A() A() 12 ~A() ~A() ~A()

```cpp
#include <iostream>
using namespace std;
class A
{
protected:
    static int x;
public:
    A(int i=1)
    {
        x=i;
    }
    int get_x()
    {
        return x;
    }
    int& set_x(int i)
    {
        int y=x;
        x=i;
        return y;
    }
    A operator=(A a1)
    {
        set_x(a1.get_x());
        return a1;
    }
} a(33);
int main()
{
    A a(18), b(7);
    cout<<(b=a).set_x(27);
    return 0;
}
```

- 

    x nu este initializat.

    - Daca il initalizez si il fac pe set_x sareturneze `int`, nu `int&` ca sa nu mai dea undefined behaviour, ordinea in care se vor apela constrctorii este:

    A() — se creeaza a-ul global

    A() A() — se creeaza a si b

    A(ob) A(ob) 27 ~A() ~A() — se apeleaza CC sa ca pot transmite a-ul prin valoare la operator=, apoi se apeleaza CC ca sa pot returna a1 prin valoare din operator=; se afiseaza 27 si dupa `;` se apeleaza destructorii pntru cele 2 obiecte create cu CC

    ~A() ~A()~A() — se distrug restul obiectelor

    - Daca rescriu operator= cu signatura `A operator=(A& a1)` se va apela un singur CC, la fel daca modific astfel: `A& operator=(A a1)`
    - Daca modific `A& operator=(A& a1)` nu se va apela niciun CC.
    - Daca modific operator = astfel:

    ```cpp
    A operator=(A a1)
    {
        set_x(a1.get_x());
        return a1.get_x();
    }
    ```

    O sa se apeleaze A(ob) A() 7 ~A() ~A() — nu se apeleaza si constructor si cc pentru returnare, doar constructor

    ```cpp
    #include<iostream>
    using namespace std;
    class B
    {
    protected:
        int x;
    public:
        B(int i = 1)
        {
            x=i;
        }
        virtual B f(B ob)
        {
            return x+ob.x+1;
        }
        void afisare()
        {
            cout<<x;
        }
    };
    class D: public B
    {
    public:
        D(int i = -2) : B(i) {}
        B f(B ob)
        {
            return x+ob.x-1;
        }
    };
    int main()
    {
        B *p1 = new D;
        B *p2 = new B;
        B *p3 = new B(p1->f(*p2));
        p3->afisare();
        return 0;
    }
    ```

    - 

        nu compielaza aici: 

        ```cpp
        B f(B ob)//primesc un obiect de tip B in clasa D
        {
            return x+ob.x-1;//si incerc sa accesez x-ul unui obiect de al tip
        }
        ```

        rezolvare: il facem pe x public

    ```cpp
    #include<iostream>

        class cls {
    public:
        int x;
        cls() { x = 3; }
        void f(cls& c) { std::cout << c.x; }
    };

    int main()
    {
        const cls d;
        f(d);
    }
    ```

    - 

        nu compileaza

        1. f nu e apelata de un obeict
        2. se scapa ilegal de const cand se trimite parametrul
        3. fucntai nu e const (daca l-am pune pe d sa apeleze functia)

    ```cpp
    #include <iostream>
    class cls {
        int x;

    public:
        cls(int y) { x = y; }
        int operator*(cls a, cls b) { return (a.x * b.x); }
    };
    int main()
    {
        cls m(100), n(15);
        std::cout << m * n;
        return 0;
    }
    ```

    - 

        nu compileaza. operatorul * implementat ca functie membra trebuie sa aiba 1 parametru sau 0

    ```cpp
    #include <iostream>
    using namespace std;
    int f(int y)
    {
        try {
            if (y > 0)
                throw y;
        }
        catch (int i) {
            throw;
        }
        return y - 2;
    }
    int f(int y, int z)
    {
        try {
            if (y < z)
                throw z - y;
        }
        catch (int i) {
            throw;
        }
        return y + 2;
    }
    float f(float& y)
    {
        cout << " y este referinta";
        return (float)y / 2;
    }
    int main()
    {
        int x;
        try {
            cout << "Da-mi un numar par: ";
            cin >> x;
            if (x % 2)
                x = f(x, 0);
            else
                x = f(x);
            cout << "Numarul " << x << " e bun!" << endl;
        }
        catch (int i) {
            cout << "Numarul " << i << " nu e bun!" << endl;
        }
        return 0;
    }
    ```

    - 

        x impar x<0: Numarul -x nu e bun!

        x impar x≥0: Numarul x+2 e bun!

        x par x>0: Numarul x nu e bun!

        x par x≤0: Numarul x-2 e bun!

    ```cpp
    #include <iostream.h>
    template <class T, class U>
    T f(T x, U y)
    {
        return x + y;
    }
    int f(int x, int y)
    {
        return x - y;
    }
    int main()
    {
        int *a = new int(3), b(23);
        cout << *f(a, b);
        return 0;
    }
    ```

    - 

        valoare nedeterminata aflata cu 23 de biti mai la dreapta de adresa catre care arata a.

    ### cele 3 cazuri de accesibilitate la membri ai unui obiect

    ```cpp
    #include <iostream>
    class cls1
    {
    protected:
        int x;

    public:
        cls1()
        {
            x = 13;
        }
    };
    class cls2 : public cls1
    {
        int y;

    public:
        cls2()
        {
            y = 15;
        }
        int f(cls2 ob)
        {
            return (ob.x + ob.y);// aici accesez 2 campuri ale obiectului ob pe care le 
    														//am si in clasa cls2 : 
    														//x (e protected deci se mosteneste ca protected) si y
        }
    };
    int main()
    {
        cls2 ob;
        std::cout << ob.f(ob);
        return 0;
    }
    ```

    ```cpp
    #include <iostream>
    class B
    {
    protected:
        int x;

    public:
        B(int i = 28)
        {
            x = i;
        }
        virtual B f(B ob)
        {
            return x + ob.x + 1;
        }
        void afisare()
        {
            std::cout << x;
        }
    };
    class D : public B
    {
    public:
        D(int i = -32)
            : B(i)
        {
        }
        B f(B ob)
        {
            return x + ob.x - 1;/// int B::x is protected within this context
    				//aici incerc sa accesez campurile unui obiect din clasa B in interiorul clasei D
        }
    };
    int main()
    {
        B *p1 = new D, *p2 = new B, *p3 = new B(p1->f(*p2));
        p3->afisare();
        return 0;
    }

    ```

    ```cpp
    #include <iostream>
    class B
    {
        int x;

    public:
        B(int i = 10)
        {
            x = i;
        }
        int get_x()
        {
            return x;
        }
    };
    class D : public B
    {
    public:
        D(int i)
            : B(i)
        {
        }
        D operator+(const D& a)
        {
            return x + a.x;
    				//aici incerc sa accesez din clasa D un camp privat care tine de partea de baza 
        }
    };
    int main()
    {
        D ob1(7), ob2(-12);
        std::cout << (ob1 + ob2).get_x();
        return 0;
    }
    ```

    test

    ```cpp
    #include <iostream.h>
    class cls1 {
        int x;

    public:
        cls1() { x = 13; }
        int g()
        {
            static int i;
            i++;
            return (i + x);
        }
    };
    class cls2 {
        int x;

    public:
        cls2() { x = 27; }
        cls1& f()
        {
            static cls1 ob;
            return ob;
        }
    };
    int main()
    {
        cls2 ob;
        cout << ob.f().g();
        return 0;
    }
    ```

    nu compileaza, se incearca accesarea unui camp al unui obiect distrus

    daca modific return(i+x) in return i merge

    ```cpp
    #include <iostream>
    using namespace std;
    class cls1 {
      int x;
    public:
      cls1 () {
        x = 13;
      }
      int g() {
        static int i; i++; 
        return (i+x);
      }
    };

    class cls2 {
      int x;
    public:
      cls2() {
        x = 27;
      }
      cls1& f() {
         cls1 ob; return ob;
      }
    };

    int main() {
      cls2 ob;
      cout << ob.f().g();
      return 0;
    }
    ```

    la fel ca mai sus

    ```cpp
    #include <iostream.h>
    class problema {
        int i;

    public:
        problema(int j = 5) { i = j; }
        void schimba() { i++; }
        void afiseaza() { cout << "starea curenta " << i << "\n"; }
    };
    problema mister1() { return problema(6); }
    void mister2(problema& o)
    {
        o.afiseaza();
        o.schimba();
        o.afiseaza();
    }
    int main()
    {
        mister2(mister1());
        return 0;
    }
    ```

    nu pot initializa o referinta cu o valoare temporara

    ```cpp
    #include <iostream.h>
    class A {
        int x;

    public:
        A(int i = 0) { x = i; }
        A operator+(const A& a) { return x + a.x; }
        template <class T>
        ostream& operator<<(ostream&);
    };
    template <class T>
    ostream& A::operator<<(ostream& o)
    {
        o << x;
        return o;
    }
    int main()
    {
        A a1(33), a2(-21);
        cout << a1 + a2;
        return 0;
    }
    ```

    modific cout << a1 + a2; in a1.operator<<<int>(cout);

    ```cpp
    #include <iostream.h>
    class B {
        int x;

    public:
        B(int i = 2)
            : x(i)
        {
        }
        int get_x() const { return x; }
    };
    class D : public B {
        int* y;

    public:
        D(int i = 2)
            : B(i)
        {
            y = new int[i];
            for (int j = 0; j < i; j++)
                y[j] = 1;
        }
        D(D& a)
        {
            y = new int[a.get_x()];
            for (int i = 0; i < a.get_x(); i++)
                y[i] = a[i];
        }
        int& operator[](int i) { return y[i]; }
    };
    ostream& operator<<(ostream& o, const D& a)
    {
        for (int i = 0; i < a.get_x(); i++)
            o << a[i];
        return o;
    }
    int main()
    {
        D ob(5);
        cout << ob;
        return 0;
    }
    ```

    operator[] nu are const si e apelat pentru un obiect const

    ```cpp
    #include <iostream.h>
    class B {
        int i;

    public:
        B() { i = 1; }
        virtual int get_i() { return i; }
    };
    class D : public B {
        int j;

    public:
        D() { j = 2; }
        int get_i() { return B::get_i() + j; }
    };
    int main()
    {
        const int i = cin.get();
        if (i % 3) {
            D o;
        }
        else {
            B o;
        }
        cout << o.get_i(); //(1)
        return 0;
    }
    ```

    ambele obiecte de tip o se distrug\

    ca sa il fac sa mearga pot sa mai adaug un D o; inainte de cout.

    ```cpp
    #include <iostream>
    #include <typeinfo>
    using namespace std;

    class B
    { int i;
      public: B() { i=1; }
              int get_i() { return i; }
    };
    class D: public B
    { int j;
      public: D() { j=2; }
              int get_j() {return j; }
    };
    int main()
    { B *p=new D;
      cout<<p->get_i();
      if (typeid((B*)p).name()=="B") cout<<((D*)p)->get_j();
      return 0;
    }
    ```

    daca se intampla ca acela sa fie numele type-idului pentru (B*)p atunci se inacerca un c-style cast din B* la B in D* ceea ce e ilegal si nu compileaza. altfel, compileaza si afiseaza 1

    ```cpp
    #include<iostream>
    using namespace std;
    class cls
    {
        int x;
    public: cls(int i=3) {x=i;}
        int &f() const{ return x;}
    };
    int main()
    {
        const cls a(-3);
        int b=a.f();
        cout<<b;
        return 0;
    }
    ```

    nu merge pentru ca desi promit ca functia este const si nu modifica niciun camp al obiectului, erturneaza adresa unui camp, ceea ce inseamna ca am putea modifica campul in main. este de ajuns ca f sa returneze int pentru a se pastra functionalitatea.

    ```cpp
    #include <iostream>
    using namespace std;
    class cls
    {	int x;
    public: cls(int i=2) { x=i; }
    int set_x(int i) { int y=x; x=i; return y; }
    int get_x(){ return x; } };
    int main()
    { cls *p=new cls[15];
          for(int i=2;i<8;i++) p[i].set_x(i);
    	  for(int i=1;i<6;i++) cout<<p[i].get_x();
      return 0;
    }
    ```

    22345

    ```cpp
    #include <iostream.h>
    #include <typeinfo>
    class B {
        int i;

    public:
        B() { i = 1; }
        int get_i() { return i; }
    };
    class D : B {
        int j;

    public:
        D() { j = 2; }
        int get_j() { return j; }
    };
    int main()
    {
        B* p = new D; //(1)
        cout << p->get_i(); //(2)
        if (typeid((B*)p).name() == "D*")
            cout << ((D*)p)->get_j();
        return 0;
    }
    ```

    main-ul nu stie ca exista o relatie de mostenire intre D si B. pot sa inlocuiesc D* = new D dar atunci nu o sa mai mearga linia 2. pot sa inlocuiesc B* = new B si nu o sa mai mearga conditia idn if. deci trebuie sa sterg una din ele.

    ```cpp
    #include<iostream>
    using namespace std;
    class A
    {
        int valoare;
        public: A(int param1=3):valoare(param1){}
        int getValoare(){return this->valoare;}
    };
    int main()
    {
        A vector[]={*(new A(3)),*(new A(4)),*(new A(5)),*(new A(6)) };
        cout<<vector[2].getValoare();
        return 0;
    }
    ```

    5

    ```cpp
    #include <iostream.h>
    class cls {
        static int x;

    public:
        cls(int i = 1) { x = i; }
        cls f(cls a) { return x + a.x; }
        static int g() { return f() / 2; }
    };
    int cls::x = 7;
    int main()
    {
        cls ob;
        cout << cls::g();
        return 0;
    }
    ```

    g, ca metoda statica, apeleaza functia f care are nevoie de obiect. si in plus fata de asta, signatura cu cazre e apelata f nu se poatriveste cu signatura din cls

    ```cpp
    #include <iostream>
    using namespace std;
    class B {
    protected:
        int x;

    public:
        B(int i = 12) { x = i; }
        virtual B f(B ob) { return x + ob.x + 1; }
        void afisare() { cout << x; }
    };
    class D : public B {
    public:
        D(int i = -15)
            : B(i - 1)
        {
            x++;
        }
        B f(B ob) { return x - 2; }
    };
    int main()
    {
        B *p1 = new D, *p2 = new B, *p3 = new B(p1->f(*p2));
        p3->afisare();
        return 0;
    }
    ```

    -16

    ```cpp
    #include <iostream>
    using namespace std;
    class B
    { int i;
    public: B() { i=1; cout<<"B ";}
        virtual int get_i() { return i; } };
    class D: virtual public B
    { int j;
    public: D() { j=2; cout<<"D ";}
        int get_i() {return B::get_i()+j; } };
    class D2: virtual public B
    { int j2;
    public: D2() { j2=3; cout<<"D2 "; }
        int get_i() {return B::get_i()+j2; } };
    class MM: public D, public D2
    { int x;
    public: MM() { x=D::get_i()+D2::get_i();cout<<"MM \n"; }
        int get_i() {return x; } };
    int main()
    { B *o= new MM();
        cout<<o->get_i()<<"\n";
        MM *p= dynamic_cast<MM*>(o);
        if (p) cout<<p->get_i()<<"\n";
        D *p2= dynamic_cast<D*>(o);
        if (p2) cout<<p2->get_i()<<"\n";
        return 0;
    }
    ```

    B D D2 MM

    7

    7

    7

    ```cpp
    #include <iostream>
    using namespace std;
    class A {
    protected:
        int x;

    public:
        A(int i = 14) { x = i; }
    };
    class B : A {
    public:
        B()
            : A(2)
        {
        }
        B(B& b) { x = b.x - 14; }
        void afisare() { cout << x; }
    };
    int main()
    {
        B b1, b2(b1);
        b2.afisare();
        return 0;
    }
    ```

    -12

    ```cpp
    #include <iostream.h>

    class Y;

    class Z;

    class X {
        int x;

    public:
        X(int n = 0) { x = n; }
        friend Y;
    };

    class Y {
        int y;
        friend Z;
    };

    class Z {
    public:
        void f(X u) { cout << u.x; }
    };

    void main()
    {
        X a;
        Z b;
        b.f(a);
    }
    ```

    0

    ```cpp
    #include <iostream.h>
    class cls1 {
    protected:
        int x;

    public:
        cls1(int i = 10) { x = i; }
        int get_x() { return x; }
    };
    class cls2 : cls1 {
    public:
        cls2(int i)
            : cls1(i)
        {
        }
    };
    int main()
    {
        cls d(37);
        cout << d.get_x();
        return 0;
    }
    ```

    daca aici am cls2 atunci nu compileaza ca am get_x privat, daca nu, compileaza si afiseaza 37

    ```cpp
    #include <iostream.h>

    class vector {
        int *p, nr;

    public:
        operator int() { return nr; }
        vector(int);
    };

    vector::vector(int n)
    {
        p = new int[n];
        nr = n;
        while (n--)
            p[n] = n;
    }

    void f(int i)
    {
        while (i--)
            cout << i << endl;
    }

    void main()
    {
        vector x(10);
        f(x);
    }
    ```

    nederminat 987654321 nedereminat

    ```cpp
    #include <iostream.h>
    class cls {
        int x;

    public:
        cls(int i) { x = i; }
        int set_x(int i)
        {
            int y = x;
            x = i;
            return y;
        }
        int get_x() { return x; }
    };
    int main()
    {
        cls* p = new cls[10]; //(1)
        int i = 0;
        for (; i < 10; i++)
            p[i].set_x(i);
        for (i = 0; i < 10; i++)
            cout << p[i].get_x();
        return 0;
    }
    ```

    nu am constructor fara parametri

    daca scriu int i=0 atunci afiseaza 0123456789

    ```cpp
    #include <iostream.h>
    class cls1 {
    public:
        int x;
        cls1(int i = 20) { x = i; }
    };
    class cls2 {
    public:
        int y;
        cls2(int i = 30) { y = i; }
        operator cls1()
        {
            cls1 ob;
            ob.x = y;
            return ob;
        }
    };
    cls1 f(cls1 ob)
    {
        ob.x++;
        return ob;
    }
    int main()
    {
        cls1 ob1;
        f(ob1);
        cout << ob1.x;
        cls2 ob2;
        f(ob2);
        cout << ob2.y;
        return 0;
    }
    ```

    2030

    ```cpp
    #include <iostream.h>
    class B {
    protected:
        static int x;
        int i;

    public:
        B()
        {
            x++;
            i = 1;
        }
        ~B() { x--; }
        static int get_x() { return x; }
        int get_i() { return i; }
    };
    int B::x;
    class D : public B {
    public:
        D() { x++; }
        ~D() { x--; }
    };
    int f(B* q)
    {
        return (q->get_x()) + 1;
    }
    int main()
    {
        B* p = new B[10];
        cout << f(p);
        delete[] p;
        p = new D;
        cout << f(p);
        delete p;
        cout << D::get_x();
        return 0;
    }
    ```

    1132

    ```cpp
    #include <iostream>
    using namespace std;

    class A {
    	int x;

    public:
    	A(int i = 2)
    		: x(i)
    	{
    	}
    	int get_x() const { return x; }
    };
    class B : public A {

    	int* y;

    public:
    	B(int i = 2)
    		: A(i)
    	{
    		y = new int[i];
    		for (int j = 0; j < i; j++)
    			y[j] = 1;
    	}
    	int& operator[](int i) const { return y[i]; }
    };
    ostream& operator<<(ostream& o, const B &b)
    {
    	for (int i = 0; i < b.get_x(); i++)
    		o << b[i];
    	return o;
    }
    int main()
    {
    	const B b(5);
    	b[2] = 3; b[4] = 5;
    	cout << b;
    	return 0;
    }
    ```

    nu compileaza: operator [] pretinde ca este functie ocnst dar returneaza adresa unui camp.

    daca sterg linia b[2] = 3; b[4] = 5; compileaza

    ```cpp
    // aici stie sa faca conversia de la int la A din consrtuctor
    A(int i = 0) { x = i; }
    operator+(const A& a) { return a.x; }

    //aici nu stie sa faca conversia de la void la A chiar daca am valoare default in constructor
    A(int i = 0) { x = i; }
    operator+(const A& a) { return; } 

    //aici stie sa faca conversia din int in a pentru ca am valoare default la j
    A(int i = 0, int j=0) { x = i; }
    operator+(const A& a) { return a.x; } 

    ```

    ```cpp
    #include <iostream>
    using namespace std;

    class A
    {
    public:
        A(string str = "")
        {
            cout << "C";
        }

        A(const A &ob)
        {
            cout << "CC";
        }
    };

    int main()
    {
        A ob = "examen";
    // nu compileaza. Incearca sa:
    //-faca conversie pentru "examen de la char[7] la string
    //-faca conversie de la temporarul string la A
    //Esueaza pentru ca:
    //-o secventa de conversii implicite nu poat avea mai mult de o conversie.

    		//string s="examen";-- asta merge si afiseaza C
        //A ob = s;
       return 0;
    }
    ```

    ### Copy elision

    In anumite situatii compilatorul este obligat  sa construiasca obiectele direct in locul in care sunt stocate, nu sa le construiasca si apoi sa le copieze. Acest lucru se numeste copy elision.

    exemplu:

    ```cpp
    #include <iostream> 
    using namespace std; 
       
    class A 
    { 
    public:     
        A(const string str = "")
        { 
            cout << "C" << endl; 
        }     
          
        A(const A &ob)
        { 
            cout << "CC" << endl; 
        }  
    }; 
       
    int main() 
    {  
        A ob = "examen";//in acest caz se afiseaza C
        return 0; 
    }
    ```

    1. La return, cand operatorul este un "pure rvalue"(adica ceva care calculeaza o valoare care nu este asociata unui obiect sau care creaza un obiect temporar) de acelasi tip cu clasa din care face parte functia (ignorand constrangerile de const sau volatile) care este returnat.

    ```cpp
    T f() {
        return T();
    }
     
    f(); // only one call to default constructor of T
    ```

    2. Atunci cand este initializat un obiect si elementul cu care se initializeaza este un "pure rvalue" de acelasi tip (ignorand constrangerile de const si volatile).

    ```cpp
    T x = T(T(f())); // only one call to default constructor of T, to initialize x
    ```

     

    Exemplu:

    ```cpp
    #include <iostream>

    struct C {
      C() = default;
      C(const C&) { std::cout << "A copy was made.\n"; }
    };

    C f() {
      return C();
    }

    int main() {
      std::cout << "Hello World!\n";
      C obj = f();
    }
    ```

    In functie de compilator, programul poate afisa oricare dintre urmatoarele outputturi:

    Hello World! A copy was made. A copy was made.

    Hello World! A copy was made.

    Hello World!

    ### !nu merge sa incrementam un pointer catre baza daca suntem in clasa derivata

    ```cpp
    #include <iostream>
    using namespace std;

    class base {
       int i;
    public:
       void set_i(int num) { i=num; }
       int get_i() { return i; }
    };

    class derived: public base {
       int j;
    public:
       void set_j(int num) {j=num;}
       int get_j() {return j;}
    };
    int main()
    {
       base *bp;//bp e poointer de tip baza
       derived d[2];// d e pointer de tip derivata
       bp = d;
       d[0].set_i(1);
       d[1].set_i(2);
       cout << bp->get_i() << " ";//se afiseaza 1 
       bp++; // relative to base, not derived
       cout << bp->get_i(); // garbage value displayed
       return 0;
    }
    ```

    ```cpp
    #include <iostream>
    using namespace std;

    class base {
       int i;
    public:
       void set_i(int num) { i=num; }
       int get_i() { return i; }
    };

    class derived: public base {
       int j;
    public:
       void set_j(int num) { j=num; }
       int get_j() { return j; }
    };
    int main()
    {
       base *bp;
       derived d;
       bp = &d; // base pointer points to derived object
                   // access derived object using base pointer
       bp->set_i(10);
       cout << bp->get_i() << " ";
    /* The following won't work. You can't access elements of a derived class using a base class pointer.

       bp->set_j(88); // error
       cout << bp->get_j(); // error
    */
    ((derived *)bp)->set_j(88); 
    cout << ((derived *)bp)->get_j(); 

    return 0;
    }
    ```
