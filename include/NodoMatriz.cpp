#include "NodoMatriz.h"


NodoMatriz::NodoMatriz(NodoCola *proyecto, NodoLista *encargado, int posx, int posy)
{
    //ctor
    this->Abajo = 0;
    this->Anterior = 0;
    this->Arriba = 0;
    this->Siguiente = 0;
    this->PosY = posy;
    this->PosX = posx;
    this->Encargado_c = encargado;
    this->Proyecto_c = proyecto;
}

NodoMatriz::~NodoMatriz()
{
    //dtor
}
