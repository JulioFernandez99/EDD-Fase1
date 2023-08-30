#ifndef NODOLISTA_H
#define NODOLISTA_H
#include <string>

using namespace std;

class NodoLista
{
    public:
        string user_name;
        string user_pass;
        NodoLista *siguiente;
        NodoLista *anterior;
        NodoLista(string user_name,string user_pass);
        virtual ~NodoLista();

    protected:

    private:
};

#endif // NODOLISTA_H
