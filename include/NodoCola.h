#ifndef NODOCOLA_H
#define NODOCOLA_H
#include "Proyecto.h"
#include <string>

using namespace std;
class NodoCola
{
    public:
        Proyecto *Proyecto_C;
        char prioridad;
        NodoCola *siguiente;
        NodoCola(char priori_,Proyecto *nuevoProyecto);
        virtual ~NodoCola();

    protected:

    private:
};

#endif // NODOCOLA_H
