#include "NodoD.h"

NodoD::NodoD(string tarea_, string numero_) {
    this->siguiente=NULL;
    this->tarea=tarea_;
    this->numero_py=numero_;
}

NodoD::~NodoD()
{
    //dtor
}
