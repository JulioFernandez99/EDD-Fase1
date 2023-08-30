#ifndef NODOMATRIZ_H
#define NODOMATRIZ_H

#include <string>
#include "NodoCola.h"
#include "Lista.h"

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
        NodoCola *Proyecto_c;
        NodoLista *Encargado_c;
        NodoMatriz(NodoCola *proyecto, NodoLista *encargado, int posy, int posx);
        virtual ~NodoMatriz();

    protected:

    private:
};

#endif // NODOMATRIZ_H
