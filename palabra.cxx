#include "palabra.h"

// Fija la palabra almacenada
void Palabra::fijarPalabra(const string& n_palabra) {
    palabra = n_palabra;
}

// Fija el número de línea
void Palabra::fijarNumeroLinea(int numeroLinea) {
    nLinea = numeroLinea;
}

// Retorna la palabra almacenada
string Palabra::obtenerPalabra() const {
    return palabra;
}

// Retorna el número de línea
int Palabra::obtenerNumLinea() const {
    return nLinea;
}
