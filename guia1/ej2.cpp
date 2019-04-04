#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    time_t timer1i;
    time_t timer1f;
    time_t timer2f;
    double iter = 10000000000;

    char v[] = "caballo"; //cadena
    char * p; //puntero a char
    p = &v[0]; //apunro al comienzo de la cadena
    

    time(&timer1i);
    
    //sin punteros
    for(double j = 0; j <= iter; j++)
    {   
        for(int i = 0; v[i]; ++i)
        {
            v[i] = v[i] + 11;
        }
    }

    time(&timer1f);
    
    //con punteros
    for(double j = 0; j <= iter; j++)
    {   
        for(char *p = v; *p; ++p)
        {
            *p = *p + 11;
        }
    }

    time(&timer2f);

    cout << endl << "Sin punteros: " << timer1f - timer1i << endl
    << "Con punteros: " << timer2f - timer1f<< endl << endl;

    return 0;
}