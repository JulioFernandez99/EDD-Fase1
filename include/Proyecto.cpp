#include "Proyecto.h"

Proyecto::Proyecto(std::string nombre, std::string codigo,char prioridad)
{
    //ctor
    this->nombre_proyecto=nombre;
    this->numeroProyecto=codigo;
    this->prioridad=prioridad;

}

Proyecto::~Proyecto()
{
    //dtor
}
