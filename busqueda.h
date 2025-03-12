#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include "archivo.h"
#include <queue>
#include <stack>

using namespace std;

class Busqueda {
private:
    queue<pair<string, int>> resultadosCola; // Cola para almacenar resultados en orden de aparición
    stack<pair<string, int>> resultadosPila; // Pila para búsqueda inversa

public:
    Busqueda() {}

    void BuscarPorPrefijo(const Archivo& archivo, const string& subcadena);
    void BuscarPorSubcadena(const Archivo& archivo, const string& subcadena);
    void BuscarPorSubcadenaInvertida(const Archivo& archivo, const string& subcadena);
    void ImprimirResultadosCola() const;
    void ImprimirResultadosPila() const;
};

#endif // BUSQUEDA_H


