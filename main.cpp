#include <iostream>
#include <windows.h>
#include <commdlg.h>
#include <string>
#include <cstdlib>
#include "Cola.h"
#include "Lista.h"
#include "ListaD.h"
using namespace std;

Lista *empleados;
Cola *colaPriori;
ListaD *tareas;
string name_user,password_user,tempUser,tempPass,name_py,tarea_py;
string tarea_tarea;
char priori_py;
int opAdmin;
int opCargaEmpleado;
int opPuesto;


//Prototipos de funciones
void Admin();
void Login();
void cargaEmpleados();
string getRuta();
void menuPoryectos();
void crearTareas();


void Login(){
    system("cls");
    cout<<"--------Login--------"<<endl;
    cout<<"User:";
    getline(cin,name_user);
    cout<<"Password:"; cin>>password_user;

    if(empleados->buscar(name_user,password_user)){
        cin.ignore();
        system("cls");
        Admin();

    } else{
        cout<<"Usuario o contrasena invalidos"<<endl;
        cin.ignore();
        Login();

    }

}

void Admin(){

    cout<<"--------Menu admin--------"<<endl;
    cout<<"1.Cargar empleados"<<endl;
    cout<<"2.Crear proyecto"<<endl;
    cout<<"3.Crear tareas"<<endl;
    cout<<"4.Asignar tareas"<<endl;
    cout<<"5.Generar reportes"<<endl;
    cout<<"6.Cerrar sesion"<<endl;
    cout<<"7.Exit"<<endl;
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
            Admin();
            break;
        case 3:
            system("cls");
            crearTareas();
            Admin();
            break;
        case 4:
            empleados->verLista();
            colaPriori->verCola();
            tareas->verListaDoble();
            Admin();
            break;
        case 5:
            colaPriori->graficar();
            Admin();
            break;
        case 6:
            cin.ignore();
            Login();
            break;
        case 7:
            exit(0);

    }

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

            Admin();
            break;
        case 2:
            system("cls");
            empleados->cargaMasiva(getRuta());
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
}

void crearTareas(){

    colaPriori->verCola();
    cout<<"Elija un proyecto:"; cin>>tarea_py;
    if (colaPriori->buscar(tarea_py)){
        cout<<"Nombre de la tarea:";
        cin.ignore(); //Limpiando buffer
        getline(cin, tarea_tarea);
        tareas->push(tarea_tarea,tarea_py);
        cout<<"Tarea agregada con exito...."<<endl;
        return;

    }
    cout<<"El proyecto "<<tarea_py<<" no exite."<<endl;
};

int main() {
    empleados=new Lista();
    colaPriori=new Cola();
    tareas=new ListaD();
    Login();

    return 0;
}




