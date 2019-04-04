#include <iostream>
#include "racional.h"
using namespace std;

int main()
{
    racional x1, x2, x3; 
    bool finalizar = false;
    char ch;

    cout << endl << "<<>><<>><<>><<>><<>> MF v" << VERSION << " <<>><<>><<>><<>><<>>" << endl;
    cout    << "Operaciones: +, -, *, /, f (a float), d (a double)." << endl 
            << "Pulse q para salir" << endl;
    cout << endl;
    cout << "Operación:";

    while( !finalizar && cin >> ch )
    {
        int skip = 0;

        switch(ch)
        {
            case '+':
                cout << "X1 = ";
                if(!(cin >> x1))
                {
                    cout << "ERROR: x1 inválido" << endl;
                    break;
                    skip = 1;
                }
                cout << "X2 = ";
                if(!(cin >> x2))
                {
                    cout << "ERROR: x2 inválido" << endl;
                    break;
                    skip = 1;
                }
                x3 = x1 + x2;
                cout << x1 << " + " << x2 << " = " << x3 << endl;
                break;

            case '-':
                cout << "X1 = ";
                if(!(cin >> x1))
                {
                    cout << "ERROR: x1 inválido" << endl;
                    break;
                    skip = 1;
                }
                cout << "X2 = ";
                if(!(cin >> x2))
                {
                    cout << "ERROR: x2 inválido" << endl;
                    break;
                    skip = 1;
                }
                x3 = x1 - x2;
                cout << x1 << " - " << x2 << " = " << x3 << endl;
                break;

            case '*':
                cout << "X1 = ";
                if(!(cin >> x1))
                {
                    cout << "ERROR: x1 inválido" << endl;
                    break;
                    skip = 1;
                }
                cout << "X2 = ";
                if(!(cin >> x2))
                {
                    cout << "ERROR: x2 inválido" << endl;
                    break;
                    skip = 1;
                }
                x3 = x1 * x2;
                cout << x1 << " * " << x2 << " = " << x3 << endl;
                break;
           
            case '/':
                cout << "X1 = ";
                if(!(cin >> x1))
                {
                    cout << "ERROR: x1 inválido" << endl;
                    break;
                    skip = 1;
                }
                cout << "X2 = ";
                if(!(cin >> x2))
                {
                    cout << "ERROR: x2 inválido" << endl;
                    break;
                    skip = 1;
                }
                x3 = x1 / x2;
                cout << x1 << " / " << x2 << " = " << x3 << endl;
                break;

            case 'q':
                {
                    cout << "Adiós.\n" ;
                    cout << "<<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>>\n\n" ; 
                    finalizar = true;
                    break;
                }

            case 'd':
                {
                    cout << "X1 = ";
                    if(!(cin >> x1)){
                        cout << "ERROR: x1 inválido" << endl;
                        skip = 1;
                    }
                    cout << "X1 = " << x1.todouble() << endl;
                    break;
                }

            case 'f':
                {
                    cout << "X1 = ";
                    if(!(cin >> x1)){
                        cout << "ERROR: x1 inválido" << endl;
                        skip = 1;
                    }
                    cout << "X1 = " << x1.tofloat() << endl;
                    break;
                }

            default:
                cout << "ERROR: comando inválido! \n";
                std::exit(1);
        }

        //arreglo buffer de entrada roto con clear()
        //y descarto basura del usuario
        if(skip)
        {
            cin.clear();
            while(cin.get(ch) && ch != '\n')
                ;
        }

        if(!finalizar){
            cout << endl;
            cout << "Operación:";
        }

    }
}