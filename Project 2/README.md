# Assignment-14-Project-2-OOP
 
 Given the classes:
- Vector (int *a)  as vector
- Nr_Natural_Mare(int_nrcif, Vector V)   as big natural number
- Numar_Intreg_mare(char semn):Nr_Natural_Mare  as big integer number
Implement the usual operations.

Functionality:
- [x] all classes have constructors, copy cionstructors and destructors, operator>>, operator<<, operator=
- [x] inheritance
````
class Nr_natural_mare : public Nr_mare
class Nr_real_mare : public Nr_mare
class Nr_intreg_mare : public Nr_natural_mare
````
- [x] pure virtual functions
````
virtual Array modul()=0;
````
- [x] treating exceptions and adding a custom exception by extending the exception class:
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
- [x] reading the complate information for n objects, storing that in `vector_de_nr_intregi` and `vector_de_nr_naturale` and outputting them
- [x] use of dynamic_cast
````
Nr_mare* a= new Nr_real_mare('+', 258, 1);
    Nr_real_mare* b=dynamic_cast<Nr_real_mare*> (a);
    cout<<b->modul();
````
- [x] use of const_cast to return an object of type Nr_intreg_mare from a const function
````
Nr_intreg_mare Nr_intreg_mare::operator/(Nr_intreg_mare const& b) const
{
//...
    return *(const_cast <Nr_intreg_mare*>(this));
}
````
