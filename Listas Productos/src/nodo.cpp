#include "nodo.h"
#include <iostream>
using std::cout;
using std::endl;


nodo::nodo(){
}

nodo::~nodo(){}

nodo::nodo(cancion d){
    setDato(d);
}

cancion nodo::getDato(){
    return dato;
}

nodo* nodo::getSiguiente(){
    return siguiente;
}
nodo* nodo::getAnterior(){
    return anterior;
}

void nodo::setDato(cancion d){
    dato = d;
}

void nodo::setSiguiente(nodo* n){
    siguiente = n;
}

void nodo::setAnterior(nodo* n){
    anterior = n;
}

void nodo::imprimir(){
    dato.mostrar();
    cout << "Nodo ant: " << getAnterior() << "\tNodo sig: " << getSiguiente() << endl << endl;
}