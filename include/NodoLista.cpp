#include "NodoLista.h"

NodoLista::NodoLista(string user_name,string user_pass)
{
    this->EmpleadoSistema = new Empleado(user_name, user_pass);
    this->siguiente=NULL;
    this->anterior=NULL;
}

NodoLista::~NodoLista()
{
    //dtor
}
