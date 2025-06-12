#ifndef LISTA_H
#define LISTA_H
#include "nodo.h"
#include "producto.h"

struct lista {
private:
    nodo* primero;
    nodo* ultimo;
public:
    lista();
    ~lista();
    nodo* getPrimero();
    nodo* getUltimo();
    void setPrimero(nodo* n);
    void setUltimo(nodo* n);
    void insertarAlFinal(producto d);
    void insertarAlInicio(producto d);
    void eliminar(producto d);
    void imprimir();
    void ordenarPrecio(producto d);    
};


#endif