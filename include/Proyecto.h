#ifndef PROYECTO_H
#define PROYECTO_H
#include <iostream>
#include <string>
#include "ListaD.h"



using namespace std;
class Proyecto
{
    public:
        string nombre_proyecto;
        string numeroProyecto;
        ListaD *tareas=new ListaD();
        char prioridad;
        Proyecto(std::string nombre, std::string codigo,char prioridad);
        virtual ~Proyecto();

    protected:

    private:
};

#endif // PROYECTO_H
