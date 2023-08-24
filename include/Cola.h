#ifndef COLA_H
#define COLA_H
#include "NodoCola.h"


class Cola
{
    public:
        int contadorProyectos=1;
        NodoCola *primero;
        NodoCola *ultimo;
        string data="";
        void push(string nombre_,char priori_);
        void verCola();
        bool buscar(string numero_py);
        string getNameProyecto(string numero_py);
        void graficar();
        void pop();
        string textoGrafo();
        Cola();
        virtual ~Cola();

    protected:

    private:
};

#endif // COLA_H
