#ifndef PROYECTO_H
#define PROYECTO_H
#include <iostream>
#include <string>

using namespace std;

class Proyecto
{
    public:
        string nombre_proyecto;
        string numeroProyecto;
        char prioridad;
        Proyecto(std::string nombre, std::string codigo,char prioridad);
        virtual ~Proyecto();

    protected:

    private:
};

#endif // PROYECTO_H
