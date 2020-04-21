#include<iostream>
using namespace std;
#ifndef COMPLEJO_INCLUDED
#define COMPLEJO_INCLUDED

class complejo
{
private:
    double x, y;

public:

    //constructores y destructores
    complejo(double, double);
    complejo(double); //real
    complejo(); //nulo
    ~complejo();
    
    //operadores
    complejo &operator=(const complejo &);
    complejo operator+(const complejo &); //conviene operator+(,) asi ignora el orden
    complejo operator-(const complejo &);
    complejo operator*(const complejo &);
    complejo operator/(const complejo &);
    complejo &operator+=(const complejo &);
    complejo &operator-=(const complejo &);
    
    //funciones
    void emitir();
    void setx(double);
    void sety(double);
    double getx() const;
    double gety() const;
    complejo & conjugar();
    double abs() const;
    bool zero();

    //funciones amigas :)
    friend complejo operator+(const complejo &, const complejo &);
    friend complejo operator-(const complejo &, const complejo &);
    friend complejo operator*(const complejo &, const complejo &);
    friend complejo operator/(const complejo &, const complejo &);
    friend bool operator==(const complejo &, const complejo &);
    friend bool operator==(const complejo &, const double);

    //operadores de entrada y salida
    friend std::ostream &operator<<(std::ostream &, const complejo &);
    friend std::istream &operator>>(std::istream &, complejo &);

};

#endif