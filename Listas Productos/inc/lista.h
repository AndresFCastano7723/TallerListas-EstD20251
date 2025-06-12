#ifndef LISTA_H
#define LISTA_H
#include "nodo.h"
#include "cancion.h"
#include <string>
using std::string;

class lista {
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
    void insertarAlFinal(cancion d);
    void insertarAlInicio(cancion d);
    void eliminar(cancion d);
    void imprimir();
    void leerArch(lista &l, const string &nomArch);
    void guardarArch(lista &l, const string &nomArch);
};


#endif