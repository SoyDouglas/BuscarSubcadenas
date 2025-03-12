#include "archivo.h"
#include <fstream>   // Para manejar archivos
#include <sstream>   // Para dividir líneas en palabras

// Constructor vacío
Archivo::Archivo() {}

// Fija la lista de líneas de texto con una nueva lista
void Archivo::fijarListaLineas(const vector<vector<string> > &nLista) {
    lineasTexto = nLista;
}

// Retorna la lista de líneas de texto
vector<vector<string> > Archivo::obtenerListaLineas() const {
    return lineasTexto;
}

// Retorna la cantidad de líneas de texto en el archivo
size_t Archivo::obtenerNumLineas() const {
    return lineasTexto.size();
}

// Agregar una nueva línea de palabras al archivo
void Archivo::AgregarListaPals(const vector<string> &n_lista) {
    lineasTexto.push_back(n_lista);
}

// Buscar palabras que comiencen con una subcadena dada
vector<pair<string, int> > Archivo::BuscarPrincipio(const string& subcadena) const {
    vector<pair<string, int> > resultados;
    for (size_t i = 0; i < lineasTexto.size(); i++) {
        for (const auto& palabra : lineasTexto[i]) {
            if (palabra.find(subcadena) == 0) {
                resultados.push_back(make_pair(palabra, i + 1));
            }
        }
    }
    return resultados;
}

// Buscar palabras que contengan la subcadena en cualquier parte
vector<pair<string, int> > Archivo::BuscarContiene(const string& subcadena) const {
    vector<pair<string, int> > resultados;
    for (size_t i = 0; i < lineasTexto.size(); i++) {
        for (const auto& palabra : lineasTexto[i]) {
            if (palabra.find(subcadena) != string::npos) {
                resultados.push_back(make_pair(palabra, i + 1));
            }
        }
    }
    return resultados;
}

// Método para obtener la subcadena
string Archivo::obtenerSubcadena() const {
    return subcadena;
}

// Leer un archivo de texto y almacenar la subcadena
bool Archivo::leerArchivo(const string& nombreArchivo) {
    ifstream archivoEntrada(nombreArchivo);
    if (!archivoEntrada) {
        cerr << "Error al abrir el archivo: " << nombreArchivo << endl;
        return false;
    }

    int numLineas;
    string linea;
    vector<vector<string> > nuevoContenido;

    // Leer la primera línea (cantidad de líneas)
    archivoEntrada >> numLineas;
    archivoEntrada.ignore(); // Ignorar el salto de línea después del número

    // Leer y almacenar la subcadena en la variable de la clase
    getline(archivoEntrada, subcadena);

    // Leer las líneas de texto y almacenarlas
    while (getline(archivoEntrada, linea)) {
        vector<string> palabras;
        istringstream stream(linea);
        string palabra;
        while (stream >> palabra) {
            palabras.push_back(palabra);
        }
        nuevoContenido.push_back(palabras);
    }

    // Asignar el contenido leído a la clase
    lineasTexto = nuevoContenido;

    archivoEntrada.close();
    return true;
}


