#include "NodoCola.h"

using namespace std;

NodoCola::NodoCola(char priori_,Proyecto *nuevoProyecto)
{
    this->Proyecto_C=nuevoProyecto;
    this->prioridad=priori_;
    this->siguiente=NULL;
}

NodoCola::~NodoCola()
{
    //dtor
}
