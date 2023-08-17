
#include <string>
#include <windows.h>
#include <commdlg.h>
#include "Estructuras/ListaDobleCircular.cpp"
#include "Estructuras/ColaPrioridad.cpp"
using namespace std;

ListaDobleCircular *empleados;
ColaPrioridad *colaPriori;
string name_user,password_user,tempUser,tempPass,tempPuesto,name_py;
char priori_py;
int opAdmin;
int opCargaEmpleado;
int opPuesto;



void Admin();
void Login();
void cargaEmpleados();
string getRuta();
void menuPoryectos();

void Login(){
    cout<<"--------Login--------"<<endl;
    cout<<"User:"; cin>>name_user;
    cout<<"Password:"; cin>>password_user;
    if(empleados->buscar(name_user,password_user)=="admin"){
        Admin();
    }
    else if (empleados->buscar(name_user,password_user)=="user"){
        cout<<"Necesita ser project manager para seguir.";
    }
    else{
        cout<<"Usuario o contrasegna incorrectas."<<endl;
        Login();
    }
}

void Admin(){
    cout<<"--------Menu admin--------"<<endl;
    cout<<"1.Cargar empleados"<<endl;
    cout<<"2.Crear proyecto"<<endl;
    cout<<"3.Crear tareas"<<endl;
    cout<<"4.Asignar tareas"<<endl;
    cout<<"5.Exit"<<endl;
    cin>>opAdmin;
    switch (opAdmin) {
        case 1:
            cargaEmpleados();
            Admin();
            break;
        case 2:
            menuPoryectos();
            Admin();
            break;
        case 4:
            empleados->verLista();
            colaPriori->verCola();
            Admin();
            break;
        case 5:
            exit(0);

    }
}

void cargaEmpleados(){
    cout<<"1.Carga manual"<<endl;
    cout<<"2.Carga masiva"<<endl;
    cin>>opCargaEmpleado;
    switch (opCargaEmpleado) {
        case 1:
            cout <<"User:"; cin>>tempUser;
            cout <<"Password:"; cin>>tempPass;
            cout <<"Puesto"<<endl;
            cout <<"1.Developer Fronted"<<endl;
            cout <<"2.Developer Backend"<<endl;
            cout <<"3.Quality Assurance"<<endl;
            cout <<"Elija una opcion..."<<endl;
            cin>>opPuesto;
            if (opPuesto==1){
                tempPuesto="Developer Fronted";
            }
            else if (opPuesto==2){
                tempPuesto="Developer Backend";
            }
            else {
                tempPuesto="Quality Assurance";
            }
            empleados->push(tempUser,tempPass,tempPuesto);
            Admin();
            break;
        case 2:
            empleados->cargaMasiva(getRuta());
            break;
    }
}

string getRuta(){
    OPENFILENAME ofn;
    char szFile[260] = {0};

    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;  // Ventana principal o padre (NULL para la ventana principal)
    ofn.lpstrFile = szFile;
    ofn.nMaxFile = sizeof(szFile);
    ofn.lpstrFilter = "All Files (*.*)\0*.*\0";
    ofn.nFilterIndex = 1;
    ofn.lpstrFileTitle = NULL;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = NULL; // Directorio inicial (NULL para el directorio actual)
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
    cout <<"Nombre:"; cin>>name_py;
    cout <<"Prioridad:"; cin>>priori_py;
    priori_py= toupper(priori_py);
    colaPriori->push(name_py,priori_py);
}

int main() {
    empleados=new ListaDobleCircular();
    colaPriori=new ColaPrioridad();
    Login();

    return 0;
}
