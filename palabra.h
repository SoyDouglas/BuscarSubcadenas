#ifndef PALABRA_H
#define PALABRA_H

#include <iostream>
#include <string>

using namespace std;

class Palabra {
    private:
        string palabra;
        int nLinea;
    public:
        // Métodos para modificar los atributos
        void fijarPalabra(const string& n_palabra);
        void fijarNumeroLinea(int numeroLinea);

        // Métodos para obtener los atributos
        string obtenerPalabra() const;
        int obtenerNumLinea() const;
};

#endif // PALABRA_H
