#include "NodoLista.h"

NodoLista::NodoLista(string user_name,string user_pass)
{
    this->user_name=user_name;
    this->user_pass=user_pass;
    this->siguiente=NULL;
    this->anterior=NULL;
}

NodoLista::~NodoLista()
{
    //dtor
}
