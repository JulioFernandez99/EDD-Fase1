#ifndef NODOD_H
#define NODOD_H
#include <string>

using namespace std;

class NodoD
{
    public:
        string tarea;
        string numero_py;
        NodoD *siguiente;
        NodoD(string tarea_,string numero_);
        virtual ~NodoD();

    protected:

    private:
};

#endif // NODOD_H
