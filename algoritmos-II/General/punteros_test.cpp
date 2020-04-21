#include <iostream>
using namespace std;

int main()
{
    //arr es lo mismo que &arr[0]
    //arreglo de enteros y puntero a arreglo
    int vector[3] = {1, 2, 3};
    int * vector1;
    vector1 = vector;

    cout << *vector1 << endl << *(vector1+1) << endl << vector1[2] << endl;
    
    //arreglo de strings y puntero a arreglo de arreglos
    char const * s[] = {"nico", "nica", "nice"}; //const obligatorio en c++
    char const ** vector2;
    vector2 = s;

    cout << endl << *vector2 << endl << vector2[1] << endl << vector2[2] << endl;

    //idem sin operador []
    char const * s2[] = {"nico", "nica", "nice"}; //const obligatorio en c++
    char const ** vector3;
    vector3 = s2;

    cout << endl << *vector3 << endl << *(vector3+1) << endl << *(vector3+2) << endl;

}