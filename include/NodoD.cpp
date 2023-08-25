#include "NodoD.h"

NodoD::NodoD(string tarea_, string numero_,string encargado) {
    this->siguiente=NULL;
    this->tarea=tarea_;
    this->numero_py=numero_;
    this->encargado=encargado;
}

NodoD::~NodoD()
{
    //dtor
}
