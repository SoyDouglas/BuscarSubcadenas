#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Archivo {
    private:
        vector<vector<string> > lineasTexto; 
        string subcadena; 

    public:
        // Constructor
        Archivo();

        // Cambia el vector actual de líneas de texto por n_lista.
        void fijarListaLineas(const vector<vector<string> > &nLista);
        
        // Retorna el vector de líneas de texto que contiene el archivo.
        vector<vector<string> > obtenerListaLineas() const; 

        // Retorna la cantidad de líneas de texto en el archivo.
        size_t obtenerNumLineas() const; 

        // Agregar una nueva línea de palabras al archivo
        void AgregarListaPals(const vector<string> &n_lista);

        // Buscar palabras que comiencen con la subcadena dada
        vector<pair<string, int> > BuscarPrincipio(const string& subcadena) const;

        // Buscar palabras que contengan la subcadena en cualquier parte
        vector<pair<string, int> > BuscarContiene(const string& subcadena) const;

        // ✅ Leer un archivo de texto y almacenar la subcadena
        bool leerArchivo(const string& nombreArchivo); // 🔹 Se eliminó 'Archivo::'

        // ✅ Obtener la subcadena almacenada
        string obtenerSubcadena() const;
};

#endif // ARCHIVO_H

