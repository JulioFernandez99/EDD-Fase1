#include "NodoCola.h"
#include <string>

using namespace std;

NodoCola::NodoCola(string nombre_py,char priori_,string contadorProyecto)
{
    this->nombre_proyecto=nombre_py;
    this->prioridad=priori_;
    this->numeroProyecto=contadorProyecto;
    this->siguiente=NULL;
}

NodoCola::~NodoCola()
{
    //dtor
}
