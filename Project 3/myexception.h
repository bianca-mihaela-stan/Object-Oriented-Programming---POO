#ifndef MYEXCEPTION_H_INCLUDED
#define MYEXCEPTION_H_INCLUDED

class myexception: virtual public std::exception
{
public:
    char* error_message;
    explicit myexception(int i)
    {
        if(i==1)
            error_message="Denumirea filmului nu poate fi vida.\n";
        else if(i==2)
            error_message="Tipul filmului nu poate fi vid.\n";
        else if(i==3)
            error_message="CNP incorect.\n";
        else if(i==4)
            error_message="Formatul duratei incorect.\n";
        else if(i==5)
            error_message="Numarul de filme trebuie sa fie de tip int.\n";
        else if(i==6)
            error_message="T trebuie sa derive din Personal.\n";
    }
    virtual ~myexception() throw () {}
    virtual const char* what() const throw ()
    {
       return error_message;
    }
};

#endif // MYEXCEPTION_H_INCLUDED
