#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <string>
using namespace std;

class Empleado
{
    public:
        string user_name;
        string user_pass;
        string user_cod;
        string user_puesto;
        Empleado(string nombre, string password);
        virtual ~Empleado();

    protected:

    private:
};

#endif // EMPLEADO_H
