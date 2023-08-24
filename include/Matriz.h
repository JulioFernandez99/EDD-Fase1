#ifndef MATRIZ_H
#define MATRIZ_H

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <string.h>
#include <chrono>   // Necesario para std::chrono
#include <thread>
#include "NodoMatriz.h"
#include "NodoLista.h"
#include "Cola.h"
#include "Proyecto.h"
#include "Empleado.h"
#include "Lista.h"

using namespace std;

class Matriz
{
    public:
        NodoMatriz *Raiz;
        int CoordenadaX;
        int CoordenadaY;
        int contador_backend=1;
        int contador_frontend=1;
        int contador_qality=1;
        int contador_manager=1;
        void insertar_elemento(std::string proyecto, std::string encargado, int x, int y);
        NodoMatriz *nueva_columna(int x);
        NodoMatriz *nueva_fila(int y);
        NodoMatriz *insertar_fila(NodoMatriz *nuevo, NodoMatriz *cabeza_fila);
        NodoMatriz *insertar_columna(NodoMatriz *nuevo, NodoMatriz *cabeza_columna);
        NodoMatriz *buscarF(int y);
        NodoMatriz *buscarC(int x);
        void Graficar();
        /** Nuevos Metodos **/
        void insertar_proyecto(Cola *cola);
        void insertar_empleado(Lista *lista);
        NodoMatriz *nueva_columna_1(int x, Proyecto *proyecto);
        NodoMatriz *nueva_fila_1(int y, Empleado *empleado);
        void asignarProyecto(std::string nombre_empleado, std::string codigo_proyecto,string puesto);
        NodoMatriz *buscarF_1(std::string nombre);
        NodoMatriz *buscarC_1(std::string codigo);
        Matriz();
        virtual ~Matriz();

    protected:

    private:
};


#endif // MATRIZ_H
