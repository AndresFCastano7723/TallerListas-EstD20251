#include "lista.h"
#include "cancion.h"
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

void lista::insertarAlFinal(cancion d) {
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

void lista::insertarAlInicio(cancion d) {
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

void lista::eliminar(cancion d) {
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

void lista::leerArch(lista &l, const string &nomArch) {
    ifstream entrada(nomArch);
    string n;
    int id;
    if (!entrada) {
        cout << "El archivo " << nomArch << " no se encontró :(\n";
        return;
    }
    while (entrada >> n >> id) {
        cancion rawr(n, id);
        if (l.getPrimero() == nullptr) {
            l.insertarAlInicio(rawr);
        } else {
            l.insertarAlFinal(rawr);
        }
        cout << "Cancion " << n << " (ID: " << id << ") anadida a la lista." << endl;
    }
    entrada.close();
    cout << "MIAU :3" << endl;
}

void lista::guardarArch(lista &l, const string &nomArch){
    ofstream salida(nomArch);
    if (!salida) {
        cout << "No se pudo abrir el archivo " << nomArch << " para escritura :(\n";
        return;
    }
    nodo* miau = l.getPrimero();
    while (miau != nullptr) {
        salida << miau->getDato().getNombre() << "\t" << miau->getDato().getCodigo() << endl;
        miau = miau->getSiguiente();
    }
    salida.close();
    cout << "Datos guardados en " << nomArch << " :)" << endl;
}