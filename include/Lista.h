#ifndef LISTA_H
#define LISTA_H
#include <cctype> // Necesario para tolower
#include <string>
#include "NodoLista.h"
using namespace std;


class Lista
{
    public:
        int size=1;
        NodoLista *primero;
        NodoLista *ultimo;
        void push(string user_name,string user_pass);
        void verLista();
        bool buscar(string user_name,string user_pass);
        void cargaMasiva(string ruta);
        void pop();
        Lista();
        virtual ~Lista();

    protected:

    private:
};
#endif // LISTA_H
