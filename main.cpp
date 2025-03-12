// Titulo: Estructuras de datos
// Asignatura: Estructuras de datos
// Nombre: Douglas Diaz


#include "archivo.h"
#include "busqueda.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Uso: " << argv[0] << " archivo.txt" << endl;
        return 1;
    }

    string nombreArchivo = argv[1];
    Archivo archivo;

    // Usar el método para leer el archivo
    if (!archivo.leerArchivo(nombreArchivo)) {
        return 1;
    }

    // Obtener la subcadena de búsqueda
    string subcadena = archivo.obtenerSubcadena();
    cout << "Subcadena de búsqueda: " << subcadena << endl;

    // Crear instancia del TAD Búsqueda
    Busqueda buscador;

    // Buscar por prefijo
    cout << "\nHay ";
    buscador.BuscarPorPrefijo(archivo, subcadena);
    buscador.ImprimirResultadosCola();
    cout << " palabras que comiencen con: " << subcadena << endl;

    // Buscar por subcadena en cualquier posición
    cout << "\nHay ";
    buscador.BuscarPorSubcadena(archivo, subcadena);
    buscador.ImprimirResultadosCola();
    cout << " palabras que contienen: " << subcadena << endl;

    // Buscar por subcadena invertida
    string subcadenaInvertida = string(subcadena.rbegin(), subcadena.rend());
    cout << "\nHay ";
    buscador.BuscarPorSubcadenaInvertida(archivo, subcadena);
    buscador.ImprimirResultadosPila();
    cout << " palabras que contienen la subcadena invertida: " << subcadenaInvertida << endl;

    return 0;
}
