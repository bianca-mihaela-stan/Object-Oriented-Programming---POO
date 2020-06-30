#ifndef VECTOR_DE_MULTIMI_H_INCLUDED
#define VECTOR_DE_MULTIMI_H_INCLUDED
#include "multime.h"
class Vector{
private:
    Multime*c;
    int len, capacity;
public:
    Vector();
    ~Vector();
    Multime& operator[] (int x) const;
    void Append(Multime& x);
};

#endif // VECTOR_DE_MULTIMI_H_INCLUDED
