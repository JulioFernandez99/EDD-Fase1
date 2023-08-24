#ifndef NODOLISTA_H
#define NODOLISTA_H
#include <string>
#include "Empleado.h"
using namespace std;

//Lista circular
class NodoLista
{
    public:
        Empleado *EmpleadoSistema;
        NodoLista *siguiente;
        NodoLista *anterior;
        NodoLista(string user_name,string user_pass);
        virtual ~NodoLista();

    protected:

    private:
};


#endif // NODOLISTA_H
