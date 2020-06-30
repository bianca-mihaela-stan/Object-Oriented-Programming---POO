#ifndef EXCEPTION_H_INCLUDED
#define EXCEPTION_H_INCLUDED
#include <exception>

class myexception: virtual public std::exception
{
public:
    char* error_message;
    explicit myexception() : error_message("Valuarea calculului nu poate fi retinuta in clasa Nr_natural_Mare.\n") {}
    virtual ~myexception() throw () {}
    virtual const char* what() const throw ()
    {
       return error_message;
    }
};

#endif // EXCEPTION_H_INCLUDED
