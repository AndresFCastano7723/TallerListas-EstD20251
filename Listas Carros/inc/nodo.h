#ifndef NODO_H
#define NODO_H
#include "cancion.h"
#include <iostream>
using std::cout;
using std::endl;

class nodo
{
private:
    cancion dato;
    nodo* siguiente;
    nodo* anterior;
public:
    nodo();
    ~nodo();
    nodo(cancion d);
    cancion getDato();
    nodo* getSiguiente();
    nodo* getAnterior();
    void setDato(cancion d);
    void setSiguiente(nodo* n);
    void setAnterior(nodo* n);
    void imprimir();
};



#endif