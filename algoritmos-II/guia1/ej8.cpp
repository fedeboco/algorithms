#include <iostream>
using namespace std;

class foo {
public:
    foo() { cout << "foo::foo()" << endl; }
    foo(const foo&) { cout << "foo::foo(const foo&)" << endl; }
    ~foo() { cout << "foo::~foo()" << endl; }
};

foo bar(foo A)
{
    cout << "foo bar(foo)" << endl;
    return A;
}

int main()
{
    foo A;
    cout << "------------" << endl;
    foo B = bar(A);
    cout << "------------" << endl;
}

// Primero construye A. "foo::foo()"
// Luego hace una copia de A, tomando a A como const para pasarle a bar(). "foo::foo(const foo&)"
// Ejecuta bar. "foo bar(foo)"
// Construye y retorna una copia de la copia de A, tomando a la copia de A como const (la copia de A es la variable local de bar()). "foo::foo(const foo&)"
// Destruye la copia de A. "foo::~foo()"
// Destruye la copia de la copia de A que retornó bar(). "foo::~foo()"
// Destruye A. "foo::~foo()"
