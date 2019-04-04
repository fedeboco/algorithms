#include <iostream>
#include "arreglo.h"
using namespace std;

int main(){
    arreglo a(7);
    
    a[0] = 3;
    a[1] = 6;
    a[2] = a[0] + a[1];
    arreglo b = a;
    std::cout << b[2] << endl;
}