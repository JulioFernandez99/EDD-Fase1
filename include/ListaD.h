#ifndef LISTAD_H
#define LISTAD_H
#include "NodoD.h"


#include <string>

using namespace std;

class ListaD
{
    public:
        NodoD *primero;
        NodoD *ultimo;
        void push(string tarea_,string numero_,string encargado);
        void verListaDoble();
        ListaD();
        virtual ~ListaD();

    protected:

    private:
};
#endif // LISTAD_H
