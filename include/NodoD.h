#ifndef NODOD_H
#define NODOD_H


#include <string>

using namespace std;

class NodoD
{
    public:
        string tarea;
        string numero_py;
        string encargado;
        NodoD *siguiente;
        NodoD(string tarea_,string numero_,string encargado);
        virtual ~NodoD();

    protected:

    private:
};

#endif // NODOD_H
