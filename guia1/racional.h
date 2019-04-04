#define VERSION 0.1

#include <iostream>
using namespace std;

class racional{
private:
    int n;
    int d;

public:
    racional();
    racional(int, int);
    racional & operator+(int);
    racional operator+(const racional &);
    racional & simplificar();
    racional & simplificar(int, int);
    double todouble() const;
    float tofloat() const;

    friend ostream & operator<<(std::ostream &, const racional &);
    friend istream & operator>>(std::istream &, racional &);
    friend int mcd(const int &, const int &);
    friend racional operator+(const racional &, const racional &);
    friend racional operator-(const racional &, const racional &);
    friend racional operator*(const racional &, const racional &);
    friend racional operator/(const racional &, const racional &);
};