#ifndef NODOCOLA_H
#define NODOCOLA_H

#include <string>

using namespace std;
class NodoCola
{
    public:
        string nombre_proyecto;
        char prioridad;
        string numeroProyecto;
        NodoCola *siguiente;
        NodoCola(string nombre_py,char priori_,string contadorProyecto);
        virtual ~NodoCola();

    protected:

    private:
};

#endif // NODOCOLA_H
