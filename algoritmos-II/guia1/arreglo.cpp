#include "arreglo.h"
using namespace std;

//constructor
arreglo::arreglo(int s){
    a = new int[s];
    size = s;
}

//constructor copia. r: referencia
arreglo::arreglo(const arreglo & r){
    a = new int[r.size];
    size = r.size;
    for(int i=0; i<=size; i++){
        a[i] = r.a[i];
    }
}

arreglo::~arreglo(){
    if(a)
        delete[]a;
}

int & arreglo::operator[](int pos){
    return a[pos];
}