#include <iostream>
using namespace std;

/*nodo*/
template <class T>
class node
{
private:
    T * node_;
    node<T> * sig_;
public:
    node();
    node(const T &);
};

/*lista doblemente enlazada*/
template <class T>
class list
{
private:
    node<T> * start;

public:
    bool empty();
    bool full();
    void insert(const T &); /*agrega al comienzo*/
    void add(const T &); /*agrega al final*/
    T * find(const T &);
};

template <class T>
node<T>::node(const T & data)
{
    node_ = new T;
    (*node_) = data;
}

template <class T>
node<T>::node()
{
    node_ = new T;
};

template <class T>
void list<T>::insert(const T & data)
{
    T * n = new T;
    T * auxptr;

    if( start == NULL )
    {
        start->sig_ = n;
        n->sig_ = NULL;
    }
    else
    {
        auxptr = start;
        start->sig_ = n;
        n->sig_ = auxptr;
    }

};