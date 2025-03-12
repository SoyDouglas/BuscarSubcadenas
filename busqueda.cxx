#include "busqueda.h"
#include <iostream>
#include <algorithm> // Para invertir la subcadena

void Busqueda::BuscarPorPrefijo(const Archivo& archivo, const string& subcadena) {
    resultadosCola = queue<pair<string, int>>(); // Limpiar la cola

    vector<vector<string> > lineas = archivo.obtenerListaLineas();
    for (size_t i = 0; i < lineas.size(); i++) {
        for (const auto& palabra : lineas[i]) {
            if (palabra.find(subcadena) == 0) {
                resultadosCola.push({palabra, i + 1});
            }
        }
    }
}

void Busqueda::BuscarPorSubcadena(const Archivo& archivo, const string& subcadena) {
    resultadosCola = queue<pair<string, int>>(); // Limpiar la cola

    vector<vector<string> > lineas = archivo.obtenerListaLineas();
    for (size_t i = 0; i < lineas.size(); i++) {
        for (const auto& palabra : lineas[i]) {
            if (palabra.find(subcadena) != string::npos) {
                resultadosCola.push({palabra, i + 1});
            }
        }
    }
}

void Busqueda::BuscarPorSubcadenaInvertida(const Archivo& archivo, const string& subcadena) {
    resultadosPila = stack<pair<string, int> >(); // Limpiar la pila

    string subcadenaInvertida = subcadena;
    reverse(subcadenaInvertida.begin(), subcadenaInvertida.end());

    vector<vector<string>> lineas = archivo.obtenerListaLineas();
    for (size_t i = 0; i < lineas.size(); i++) {
        for (const auto& palabra : lineas[i]) {
            if (palabra.find(subcadenaInvertida) != string::npos) {
                resultadosPila.push({palabra, i + 1});
            }
        }
    }
}

void Busqueda::ImprimirResultadosCola() const {
    cout << resultadosCola.size() << " palabras encontradas." << endl;
    queue<pair<string, int>> temp = resultadosCola;
    while (!temp.empty()) {
        auto resultado = temp.front();
        cout << "Linea " << resultado.second << ": " << resultado.first << endl;
        temp.pop();
    }
}

void Busqueda::ImprimirResultadosPila() const {
    cout << resultadosPila.size() << " palabras encontradas." << endl;
    stack<pair<string, int>> temp = resultadosPila;
    while (!temp.empty()) {
        auto resultado = temp.top();
        cout << "Linea " << resultado.second << ": " << resultado.first << endl;
        temp.pop();
    }
}

