#ifndef NODO_H
#define NODO_H
#include "producto.h"

struct nodo{
private:
    producto dato;
    nodo* siguiente;
    nodo* anterior;
public:
    nodo();
    ~nodo();
    nodo(producto d);
    producto getDato();
    nodo* getSiguiente();
    nodo* getAnterior();
    void setDato(producto d);
    void setSiguiente(nodo* n);
    void setAnterior(nodo* n);
    void imprimir();
};

#endif