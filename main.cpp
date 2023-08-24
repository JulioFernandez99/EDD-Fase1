#include <iostream>
#include <windows.h>
#include <commdlg.h>
#include <map>
#include <vector>
#include <string>
#include <cstdlib>
#include <chrono>   // Necesario para std::chrono
#include <thread>
#include "Cola.h"
#include "Lista.h"
#include "ListaD.h"
#include "Matriz.h"

using namespace std;


Lista *empleados=new Lista();
Lista *empleadosTemp=new Lista();
Cola *colaPriori=new Cola();
Cola *colaTemp=new Cola();
Matriz *matrizN = new Matriz();
ListaD *tareas;//Tareas
string name_user,password_user,tempUser,tempPass,name_py,tarea_py;
string tarea_tarea;
char priori_py;
int opAdmin;
int opCargaEmpleado;
int opPuesto;
string rt;

struct empleado {
    std::string name;
    std::string proyecto;
    std::string puesto;
};


std::vector<empleado> empleadosVector;

//Prototipos de funciones
void Admin();
void Login();
void cargaEmpleados();
string getRuta();
void menuPoryectos();
void crearTareas();
void asignar_Proyectos();


void Login(){
    system("cls");
    cout<<"--------Login--------"<<endl;
    cout<<"User:";
    getline(cin,name_user);
    cout<<"Password:"; cin>>password_user;
    if(empleadosTemp->buscar(name_user,password_user)){
        cin.ignore();
        system("cls");
        cout<<"Bienvenido "<<name_user<<endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        system("cls");
        Admin();

    } else{
        cout<<"Usuario o contrasena invalidos....."<<endl;
        cin.ignore();
        std::this_thread::sleep_for(std::chrono::seconds(1));
        Login();

    }

}

void Admin(){

    cout<<"--------Menu admin--------"<<endl;
    cout<<"1.Cargar empleados"<<endl;
    cout<<"2.Crear proyecto"<<endl;
    cout<<"3.Crear tareas"<<endl;
    cout<<"4.Asignar proyectos"<<endl;
    cout<<"5.Generar reportes"<<endl;
    cout<<"6.Cerrar sesion"<<endl;
    cout<<"7.Exit"<<endl;
    cout<<"8.Trafica en consola"<<endl;
    cin>>opAdmin;
    switch (opAdmin) {
        case 1:
            system("cls");
            cargaEmpleados();
            Admin();
            break;
        case 2:
            system("cls");
            menuPoryectos();
            system("cls");
            Admin();
            break;
        case 3:
            system("cls");
            crearTareas();
            Admin();
            break;
        case 4:
            system("cls");
            asignar_Proyectos();
            Admin();
            break;

        case 5:
            system("cls");

            cout<<"Generando reportes......."<<endl;
            matrizN->Graficar();
            colaTemp->graficar();
            std::this_thread::sleep_for(std::chrono::seconds(5));
            system("cls");
            cout<<"Reportes  generados con exito!"<<endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));

            Admin();
            break;
        case 6:
            cin.ignore();
            system("cls");
            cout<<"Cerrando sesion......"<<endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            system("cls");
            Login();
            break;
        case 7:
            system("cls");
            cout<<" --------------------------------"<<endl;
            cout<<"|Gracias por utilizar mi software|"<<endl;
            cout<<" --------------------------------"<<endl;
            exit(0);
        case 8:
            empleados->verLista();
            colaTemp->verCola();
            tareas->verListaDoble();
            /*
            for (const empleado& empleado : empleadosVector) {
                cout << "User: " << empleado.name << ", Proyecto: " << empleado.proyecto << ", Puesto: " << empleado.puesto << std::endl;
            }*/
            Admin();
            break;

    }

}

void asignar_Proyectos(){
    std::map<std::string, empleado> empleadosMapa;
    string encargado,proyecto,puesto;
    int opcion;
    cout<<"-------Empleados existentes-------"<<endl;
    empleadosTemp->verLista();
    cout<<"-------Proyectos existentes-------"<<endl;
    colaTemp->verCola();
    cout<<"\nNombre de empleado:";
    cin.ignore();
    getline(cin,encargado);
    cout<<"Numero de proyecto:";
    getline(cin,proyecto);
    cout<<"1.Fronted developer"<<endl;
    cout<<"2.Backend developer"<<endl;
    cout<<"3.Quality assurance"<<endl;
    cout<<"Seleccione una opcion....:"; cin>>opcion;
    switch (opcion){
        case 1:
            puesto="FRONTED DEVELOPER";
            break;
        case 2:
            puesto="BACKEND DEVELOPER";
            break;
        case 3:
            puesto="QUALITY ASSURANCE";
            break;
    }

    /*
    empleadosMapa[encargado] = { encargado, proyecto, puesto };
    for (const auto& par : empleadosMapa) {
        empleadosVector.push_back(par.second);
    }*/


    while(colaPriori->primero!=NULL){
        matrizN->insertar_proyecto(colaPriori);
        colaPriori->pop();

    }
    if(empleados!=NULL){
        matrizN->insertar_empleado(empleados);
        empleados=NULL;
    }
    matrizN->asignarProyecto(encargado,proyecto,puesto);


}

void cargaEmpleados(){
    system("cls");
    cout<<"1.Carga manual"<<endl;
    cout<<"2.Carga masiva"<<endl;
    cin>>opCargaEmpleado;
    switch (opCargaEmpleado) {
        case 1:
            system("cls");
            cout <<"User:";
            cin.ignore();
            getline(cin,tempUser);
            cout <<"Password:"; cin>>tempPass;
            empleados->push(tempUser,tempPass);
            empleadosTemp->push(tempUser,tempPass);

            Admin();
            break;
        case 2:
            system("cls");
            cout<<"Seleccionando archivos......."<<endl;
            rt=getRuta();
            empleados->cargaMasiva(rt);
            empleadosTemp->cargaMasiva(rt);
            std::this_thread::sleep_for(std::chrono::seconds(5));
            system("cls");
            break;
    }
}

string getRuta(){
    OPENFILENAME ofn;
    char szFile[260] = {0};
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = nullptr;  // Ventana principal o padre (NULL para la ventana principal)
    ofn.lpstrFile = szFile;
    ofn.nMaxFile = sizeof(szFile);
    ofn.lpstrFilter = "All Files (*.*)\0*.*\0";
    ofn.nFilterIndex = 1;
    ofn.lpstrFileTitle = nullptr;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = nullptr; // Directorio inicial (NULL para el directorio actual)
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

    if (GetOpenFileName(&ofn) == TRUE) {
        //std::cout << "File selected: " << szFile << std::endl;
    } else {
        DWORD error = CommDlgExtendedError();
        if (error != 0) {
            std::cerr << "Error occurred: " << error << std::endl;
        } else {
            std::cout << "File selection cancelled." << std::endl;
        }
    }
    return szFile;
}

void menuPoryectos(){
    cout <<"Nombre:";
    cin.ignore();
    getline(cin,name_py);
    cout <<"Prioridad:"; cin>>priori_py;
    priori_py= toupper(priori_py);
    colaPriori->push(name_py,priori_py);
    colaTemp->push(name_py,priori_py);
    cout <<"Proyecto agregado con exito.......";
    std::this_thread::sleep_for(std::chrono::seconds(1));

}

void crearTareas(){


    if(colaPriori->primero!=NULL){
        colaPriori->verCola();
        cout<<"Elija un proyecto:"; cin>>tarea_py;
        if (colaPriori->buscar(tarea_py)){
        cout<<"Nombre de la tarea:";
        cin.ignore(); //Limpiando buffer
        getline(cin, tarea_tarea);
        tareas->push(tarea_tarea,tarea_py);
        cout<<"Tarea agregada con exito...."<<endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        system("cls");
        return;

    }
    cout<<"El proyecto "<<tarea_py<<" no exite."<<endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    system("cls");
    }
    else{
        cout<<"No existen proyectos existentes para asignar tareas....."<<endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("cls");
    }

};

int main() {

    empleados=new Lista();
    empleadosTemp=new Lista();
    colaPriori=new Cola();
    tareas=new ListaD();
    empleados->push("jf","123");
    empleadosTemp->push("jf","123");
    Login();



    return 0;
}

