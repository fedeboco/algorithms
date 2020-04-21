#include "complejo.h"
#include <cmath>
using namespace std;

void complejo::emitir()
{
    cout << x << "+j" << y << endl; 
}

//constructor
complejo::complejo(double a, double b)
{
    x = a;
    y = b;
}

//constructor sin parámetros (inicializa nulo)
complejo::complejo()
{
    x = 0;
    y = 0;
}

complejo::~complejo()
{
}

//asignar. ampersand por el this
complejo & complejo::operator=(const complejo &c)
{
    x = c.x;
    y = c.y;
    return *this;
}

//suma con otro complejo
complejo complejo::operator+(const complejo &c)
{
    //estoy creando un complejo que después se destruye
    complejo aux(x + c.x, y + c.y); //uso el constructor
    return aux;
}

complejo complejo::operator-(const complejo &c)
{
    //estoy creando un complejo que después se destruye
    complejo aux(x - c.x, y - c.y); //uso el constructor
    return aux;
}

complejo & complejo::operator+=(const complejo &c)
{
    x = x + c.x;
    y = y + c.y;
    return *this;
}

complejo & complejo::operator-=(const complejo &c)
{
    x = x - c.x;
    y = y - c.y;
    return *this;
}

complejo complejo::operator*(const complejo &c)
{
    complejo aux(x*c.x-y*c.y, x*c.y+y*c.x);
    return aux;
}

complejo complejo::operator/(const complejo &c)
{
    double D = c.x*c.x + c.y*c.y;
    complejo aux( (x*c.x + y*c.y)/D, (-x*c.y + y*c.x)/D );
    return aux;
}

void complejo::setx(double m)
{
    x = m;
}

void complejo::sety(double m)
{
    y = m;
}

//const evita que se puedan editar atributos
double complejo::getx() const
{
    return x;
}

double complejo::gety() const
{
    return y;
}

complejo::complejo(double re)
{
    x = re;
    y = 0;
}

complejo & complejo::conjugar()
{
    y = -y;
    return *this;
}

double complejo::abs() const
{
    return sqrt( x*x + y*y );
}

bool complejo::zero()
{
    return ( x == +0.0 && x == -0.0 && y == +0.0 && y == -0.0) ? true : false;
}

complejo operator+(const complejo & c1, const complejo & c2)
{
    complejo aux(c1.x + c2.x, c1.y + c2.y);
    return aux;
}

complejo operator-(const complejo & c1, const complejo & c2)
{
    complejo aux(c1.x - c2.x, c1.y - c2.y);
    return aux;
}

complejo operator*(const complejo & c1, const complejo & c2)
{
    complejo aux(c1.x*c2.x - c1.y*c2.y, 
                c1.x*c2.y + c1.y+c2.x);
    return aux;
}

complejo operator/(const complejo & c1, const complejo & c2)
{
    double D = c2.x*c2.x + c2.y*c2.y;
    complejo aux( (c1.x*c2.x + c1.y*c2.y)/D, 
                (c1.y*c2.x - c1.x*c2.y)/D );
    return aux;
}

bool operator==(const complejo &c1, const complejo &c2)
{
    return (c1.x == c2.x && c1.y == c2.y) ? true : false;
}

bool operator==(const complejo &c1, const double m)
{
    return (c1.x == m) ? true : false;
}

//ojo con el "os <<"
std::ostream &operator<<(std::ostream &os, const complejo &c)
{
    os << "(" << c.x << "," << c.y << ")";
    return os;
}

std::istream &operator>>(std::istream &is, complejo &c)
{
    int good = false;
    int bad = false;
    char ch = 0;
    double re = 0;
    double im = 0;

    //trato de leer par ordenado
    if(is >> ch && ch == '(')
    {
        if  (is >> re &&
            is >> ch && ch == ',' &&
            is >> im &&
            is >> ch && ch == ')')
            good = true;
        else
            bad = true;
    }
    //no es par entonces devuelvo el caracter y
    //me fijo si es double
    else if ( is.good())
    {
        is.putback(ch);
        if( is >> re )
            good = true;
        else
            bad = true;
    }

    if( good )
        c.x = re, c.y = im;
    if( bad )
        is.clear(ios::badbit); //seteo bit bad

    return is;
}