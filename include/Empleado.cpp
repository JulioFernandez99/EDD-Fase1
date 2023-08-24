#include "Empleado.h"

Empleado::Empleado(std::string nombre, std::string password)
{
    //ctor
    this->user_cod = "";
    this->user_name = nombre;
    this->user_pass = password;
    this->user_puesto = "";
}

Empleado::~Empleado()
{
    //dtor
}
