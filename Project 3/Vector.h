#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

template<typename T>
class Vector
{
    std::vector<T> v;
public:
    Vector() {};
    friend std::istream& operator>> (std::istream& in, Vector<T>& ob)
    {
        std::cout<<"Introduceti numarul de obiecte: ";
        int n;
        in>>n;
        for(int i=0; i<n; i++)
        {
            T t;
            in>>t;
            const T te(t);
            ob.v.emplace_back(te);
        }
        return in;
    }
    friend std::ostream& operator<< (std::ostream& out, const Vector<T>& ob)
    {
        for(int i=0; i<ob.v.size(); i++)
        {
            ob.v[i].afisare();
        }
        return out;
    }
};
#endif // VECTOR_H_INCLUDED
