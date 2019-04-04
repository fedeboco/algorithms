#include <iostream>
using namespace std;

class foo{
public:
    foo() { cout << "foo::foo()" << endl; } //1
    foo(const foo &) { cout << "foo::foo(const foo&)" << endl; } //2
    foo const &operator=(foo const &f) {
        cout << "foo const &operator=(foo const &)" << endl; //3
        return *this;
    }

    ~foo() { cout << "foo::~foo()" << endl; } //4
};

foo bar(foo A)
{
    cout << "foo bar(foo)" << endl; //5
    return A;
}

int main()
{   
    cout << "----------1----------" << endl;
    foo A;
    cout << "----------2----------" << endl;
    foo B(A);
    cout << "----------3----------" << endl;
    foo C = A;
    cout << "----------4----------" << endl;
    A = bar(B);
    cout << "-------CERRAMO-------" << endl;
}

//"----------1----------"
//1. Construye A. foo::foo()

//"----------2----------"
//2. Construye B copiando A. Toma a A como const por ser copia. foo::foo(const foo&)

//"----------3----------"
//3. Entró en operator=(). foo const &operator=(foo const &) NO. POR QUEEE? PORQUE ESTÁ INVOCANDO A COPIA foo(const foo &), NO A ASIGNACIÓN. DICE foo previo a C = A.
//2. Construye y Retorna a C por copia constante de A. foo::foo(const foo&)

//"----------4----------"
//2. Construye copia de A constante para recibir en bar(). foo::foo(const foo&)
//5. Ejecuta bar(). foo bar(foo)
//2. Crea una copia de la copia de A para retornar a operator=(), tomando a la copia de A como constante. foo::foo(const foo&)
//3. Se lo asigna a A por lo cual entra en operator=() foo const &operator=(foo const &)
//4. Destruye la copia de la copia de A. foo::~foo()
//4. Destruye la copia de A creada en bar(). foo::~foo()

//"----------CERRAMO----------"
//4. Destruye C. foo::~foo()
//4. Destruye B. foo::~foo()
//4. Destruye A. foo::~foo()