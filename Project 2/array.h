#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED
#include <iostream>
class Array{
private:
    int* c;///array-ul
    int capacity, len;///lungimea si capacitatea
public:
    ///constrcutori
    Array();
    Array(const Array& b);
    Array(int);
    ///destructor
    ~Array();
    ///append-uri
    void Append(int);
    void Append_front(int x);
    ///operatori
    friend std::ostream& operator<< (std::ostream& out, const Array& ob);
    friend std::istream& operator>> (std::istream& in, Array& ob);
    int& operator[] (int) const;
    Array& operator= (Array const & arr);
    ///getteri
    int* get_c() const;
    int& get_len();
    int& get_capacity();
    ///alte functii random
    void normalizare();
    void Afisare()const;
    void Sortare() const;
    void golire();

};

#endif // ARRAY_H_INCLUDED
