#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <string>
using std::string;

class producto{
private:
    string nombre;
    double precio;
public:
    producto();
    producto(string n, double p, int c);
    ~producto();
    string getNombre();
    double getPrecio();
    void setNombre(string n);
    void setPrecio(double p);
    void mostrar();
};


#endif