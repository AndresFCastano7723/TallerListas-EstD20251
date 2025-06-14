#include "lista.h"
#include "producto.h"
#include <iostream>
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;

lista::lista() {
    setPrimero(nullptr);
    setUltimo(nullptr);
}  

lista::~lista() {
    nodo* miau = getPrimero();
    while (miau != nullptr) {
        nodo* guau = miau->getSiguiente();
        delete miau;
        miau = guau;
    }
    setPrimero(nullptr);
    setUltimo(nullptr);
}

nodo* lista::getPrimero() {
    return primero;
}

nodo* lista::getUltimo() {
    return ultimo;
}

void lista::setPrimero(nodo* n) {
    primero = n;
}

void lista::setUltimo(nodo* n) {
    ultimo = n;
}

void lista::insertarAlFinal(producto d) {
    nodo* miau = new nodo(d);
    if (getPrimero() == nullptr) {
        setPrimero(miau);
        setUltimo(miau);
    } else {
        getUltimo()->setSiguiente(miau);
        miau->setAnterior(getUltimo());
        setUltimo(miau);
    }
}

void lista::insertarAlInicio(producto d) {
    nodo* miau = new nodo(d);
    if (getPrimero() == nullptr) {
        setPrimero(miau);
        setUltimo(miau);
    } else {
        miau->setSiguiente(getPrimero());
        getPrimero()->setAnterior(miau);
        setPrimero(miau);
    }
}

void lista::eliminar(producto d) {
    nodo* miau = getPrimero();
    while (miau != nullptr) {
        if (miau->getDato().getNombre() == d.getNombre()) {
            if (miau->getAnterior() != nullptr) {
                miau->getAnterior()->setSiguiente(miau->getSiguiente());
            } else {
                setPrimero(miau->getSiguiente());
            }
            if (miau->getSiguiente() != nullptr) {
                miau->getSiguiente()->setAnterior(miau->getAnterior());
            } else {
                setUltimo(miau->getAnterior());
            }
            delete miau;
            return;
        }
        miau = miau->getSiguiente();
    }
}

void lista::imprimir(){
    if(getPrimero() != nullptr && getUltimo() != nullptr){
        nodo* miau;
        miau = getPrimero();
        while(miau != nullptr){
            miau->getDato().mostrar();
            miau = miau->getSiguiente();    
        }
    }else{
        cout << "La lista esta vacia :(" << endl;
        return;
    }
    
}

void lista::ordenarPrecio(producto d) {
    if (getPrimero() == nullptr || getPrimero()->getSiguiente() == nullptr) {
        return;
    }

    bool ojo;
    do {
        ojo = false;
        nodo* cuak = getPrimero();
        while (cuak->getSiguiente() != nullptr) {
            if (cuak->getDato().getPrecio() > cuak->getSiguiente()->getDato().getPrecio()) {
                producto temp = cuak->getDato();
                cuak->setDato(cuak->getSiguiente()->getDato());
                cuak->getSiguiente()->setDato(temp);
                ojo = true;
            }
            cuak = cuak->getSiguiente();
        }
    } while (ojo);
}