#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED
#include <iostream>
class Array{
private:
    int* c;///array-ul
    int len, capacity;///lungimea si capacitatea
public:
    Array();
    void Append(int);
    ~Array();
    int& operator[] (int) const;
    void Afisare();
    void Sortare();
    friend class Multime;
    int* get_c();
    int& get_len();
    int& get_capacity();
};

#endif // ARRAY_H_INCLUDED
