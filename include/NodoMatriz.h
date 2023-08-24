#ifndef NODOMATRIZ_H
#define NODOMATRIZ_H
#include <string>
#include "Proyecto.h"
#include "Empleado.h"

using namespace std;

class NodoMatriz
{
    public:
        NodoMatriz *Siguiente;
        NodoMatriz *Anterior;
        NodoMatriz *Abajo;
        NodoMatriz *Arriba;
        int PosY;
        int PosX;
        string puesto;
        Proyecto *Proyecto_c;
        Empleado *Encargado_c;
        NodoMatriz(Proyecto *proyecto, Empleado *encargado, int posy, int posx,string codigo);
        virtual ~NodoMatriz();

    protected:

    private:
};

#endif // NODOMATRIZ_H
