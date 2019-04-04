#include <iostream>
#ifndef CLASEARREGLO
#define CLASEARREGLO
using namespace std;

class arreglo{
private:
    int * a;
    int size = 0;

public:
    arreglo( int );
    arreglo(const arreglo &);
    ~arreglo();
    int & operator[]( int );
    // arreglo();
    // ~arreglo();

    // arreglo operator+(const arreglo &, const arreglo &);
    // arreglo operator=(double);
};

#endif