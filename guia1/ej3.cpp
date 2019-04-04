#include <iostream>
#include <string>
using namespace std;

int main(int argc, char **argv)
{
    string d; //string a recibir
    string e; //string encriptado
    string f; //string desenctriptado
    int j = 0; //contador
    size_t L = 0; //longitud de string

    cout << "Texto a encriptar: ";
    cin >> d;
    L = d.length();

    //Encripto
    for(int i = 0; d[i]; i++)
    {
        e[i] = d[i]^argv[1][j];
        if(j <= L-1)
            j++;
        else
            j = 0;
    }
    cout << "Encriptado: " << e << endl;

}