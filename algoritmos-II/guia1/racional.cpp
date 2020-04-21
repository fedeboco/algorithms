#include <iostream>
#include "racional.h"
using namespace std;

//algoritmo de Euclides para maximo comun divisor
int mcd(const int num,const int den){
    if( !den )
       return num;
    else
       return mcd(den, num % den);
}

racional & racional::simplificar(){
    int M = mcd(n, d);
    n = n/M;
    d = d/M;

    if( d < 0 )
    {
        n *= -1;
        d *= -1;
    }

    return *this;
}

racional & racional::simplificar(int num, int den){

    n = num;
    d = den;
    return this->simplificar();
}

racional::racional(int num, int den){

    if( !den )
        cout << "ERROR: DIVISIÓN POR CERO" << endl;
    if( !num%den ){
        n = num/den;
        d = 1;
    }
    else{
        n = num;
        d = den;
        this->simplificar();
    }
}

racional::racional(){
    n = 0;
    d = 1;
}

racional & racional::operator+(int a){

    racional aux( a*d + n, d );
    return aux.simplificar();

}

racional racional::operator+(const racional & a){

    racional aux( a.n * d + a.d * n , a.d * d);
    return aux.simplificar();

}

racional operator+(const racional & a, const racional & b){

    racional aux( a.n * b.d + b.n * a.d , a.d*b.d );
    return aux.simplificar();

}

racional operator-(const racional & a, const racional & b){

    racional aux( a.n * b.d - b.n * a.d , a.d*b.d );
    return aux.simplificar();

}

racional operator*(const racional & a, const racional & b){

    racional aux(a.n * b.n, a.d * b.d);
    return aux.simplificar();

}
racional operator/(const racional & a, const racional & b){

    racional aux(a.n * b.d, a.d * b.n);
    return aux.simplificar();

}

double racional::todouble() const{

    double aux = (double)n / (double)d;
    return aux;

}

float racional::tofloat() const{

    float aux = (float)n / (float)d;
    return aux;

}

std::ostream & operator<<(std::ostream & os, const racional & r){
    os << r.n << "/" << r.d;
    return os;
}

//no anda con enteros
std::istream & operator>>(std::istream & is, racional & r){

    char ch;
    int num = 0;
    int den = 1;
    int good = false;
    int bad = false;

    //Uso get(ch) porque extrae sin formato y busca hasta '/n'.
    //Si no tiene la barra es int.
    if( is >> num ){

        if(is.get(ch) && ch == '/' && is >> den ){
            good = true;
        }

        //Acá supone int.
        else if( is.good() )
        {
            is.putback(ch);
            good = true;
        }
        //Acá leyó cualquiera.
        else
            bad = true;

    }

    if( good )
        r.n = num, r.d = den;
    if( bad )
        is.clear(ios::badbit);
    return is;

}