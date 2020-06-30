# Tema-14-Proiect-2-POO
 
 Se dau urmatoarele clase:
- Vector (int *a)
- Nr_Natural_Mare(int_nrcif, Vector V)
- Numar_Intreg_mare(char semn):Nr_Natural_Mare
Să se implementeze operatiile uzuale

Functionalitate:
- [x] toate clasele au constructori de initializare, copiere, destructori si operatorii >>, << si = supraincarcati
- [x] ilustrarea conceptelor de mostenire:
````
class Nr_natural_mare : public Nr_mare
class Nr_real_mare : public Nr_mare
class Nr_intreg_mare : public Nr_natural_mare
````
- [x] utilizare functiilor virtuale pure:
````
virtual Array modul()=0;
````
- [x] tratarea exceptiiilor + adaugarea unei exceptii prin extinderea clasei exception:
````
class myexception: public std::exception
{
public:
    virtual const char* what() const throw()
    {
        return "Valuarea calculului nu poate fi retinuta in clasa Nr_natural_Mare.\n";
    }
};
````
- [x] citirea informatiilor complete a n obiecte, memorarea acestoa in `vector_de_nr_intregi` si `vector_de_nr_naturale` si afisarea lor
- [x] utilizare dynamic_cast
````
Nr_mare* a= new Nr_real_mare('+', 258, 1);
    Nr_real_mare* b=dynamic_cast<Nr_real_mare*> (a);
    cout<<b->modul();
````
- [x] utilizare const_cast pentru a putea returna un obect de tip Nr_intreg_mare dintr-o functie const
````
Nr_intreg_mare Nr_intreg_mare::operator/(Nr_intreg_mare const& b) const
{
//...
    return *(const_cast <Nr_intreg_mare*>(this));
}
````
