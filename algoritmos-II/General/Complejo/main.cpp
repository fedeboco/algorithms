#include <iostream>
#include "complejo.h"
using namespace std;

int main()
{
    // complejo b(1,1), a(1,2), c, d, e(1), f, w(23,4);
    // c = (a + b)*e;
    // d = a * b;
    // a.conjugar();
    // w = w / b;

    // cout << "Re(a) = " << a.getx() << "; Im(a) = " << a.gety() << endl;
    // cout << "abs(a) = " << a.abs() <<endl;
    // w.emitir();
    // cout << c;
    complejo x1, x2, x3;
    char ch;

    while(cin >> ch)
    {
        int skip = 0;

        switch(ch)
        {
            case '+':
                if(!(cin >> x1))
                {
                    cout << "ERROR: x1 inválido" << endl;
                    break;
                    skip = 1;
                }
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
                if(!(cin >> x1))
                {
                    cout << "ERROR: x1 inválido" << endl;
                    break;
                    skip = 1;
                }
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
                if(!(cin >> x1))
                {
                    cout << "ERROR: x1 inválido" << endl;
                    break;
                    skip = 1;
                }
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
                if(!(cin >> x1))
                {
                    cout << "ERROR: x1 inválido" << endl;
                    break;
                    skip = 1;
                }
                if(!(cin >> x2))
                {
                    cout << "ERROR: x2 inválido" << endl;
                    break;
                    skip = 1;
                }
                x3 = x1 / x2;
                cout << x1 << " / " << x2 << " = " << x3 << endl;
                break;
            
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
    }
}