#include <iostream>
#include <windows.h>
#include <commdlg.h>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

/*-------Clase nodo-------*/
class Nodo{
public:
    string user_name;
    string user_pass;
    string user_puesto;
    Nodo *siguiente;
    Nodo *anterior;
    Nodo(string user_name,string user_pass,string user_puesto);
};
Nodo::Nodo(string user_name,string user_pass,string user_puesto) {
    this->user_name=user_name;
    this->user_pass=user_pass;
    this->user_puesto=user_puesto;
}

/*-------Clase Lista-------*/
class ListaDobleCircular {
public:
    int size=0;
   Nodo *primero;
   Nodo *ultimo;
   void push(string user_name,string user_pass,string user_puesto);
   void verLista();
   string buscar(string user_name,string user_pass);
   ListaDobleCircular();
   void cargaMasiva();
};

ListaDobleCircular::ListaDobleCircular() {
    Nodo *project_manager=new Nodo("PM-201902416","35122","Project Manager");
    project_manager->anterior = project_manager;  //Esta parte es para hacerla circular
    project_manager->siguiente = project_manager; //Esta parte es para hacerla circular
    this->primero = project_manager;
    this->ultimo=project_manager;
    this->size++;
}
void ListaDobleCircular::push(string user_name,string user_pass,string user_puesto) {
    Nodo *nuevo=new Nodo(user_name, user_pass,user_puesto);
    nuevo->anterior = ultimo;
    nuevo->siguiente = this->primero;//No existe en doble enlazada
    this->ultimo->siguiente = nuevo;
    this->primero->anterior = nuevo; //No exites en doble enlazada
    this->ultimo=nuevo;
    this->size++;
    cout <<"Empleado agregado con exito!"<<endl;
}

void ListaDobleCircular::verLista(){
    Nodo *aux = this->primero;
    int contador = 0;
    while(this->size > contador)
    {
        cout << aux->user_name << endl;
        aux = aux->siguiente;
        contador++;
    }
}

string ListaDobleCircular::buscar(string user_name, string user_pass){
    Nodo *aux = this->primero;
    int contador = 0;
    while(this->size > contador) {
        if (aux->user_name == user_name && aux->user_pass == user_pass) {
            if (aux->user_puesto=="Project Manager"){
                return "admin";
            }
            return "user";
        }
        aux = aux->siguiente;
        contador++;
    }
    return "fail";
}

void ListaDobleCircular::cargaMasiva() {
    OPENFILENAME ofn;
    char fileName[MAX_PATH] = "";

    ZeroMemory(&ofn, sizeof(OPENFILENAME));
    ofn.lStructSize = sizeof(OPENFILENAME);
    ofn.lpstrFilter = "Archivos de Texto (*.txt)\0*.txt\0Todos los archivos (*.*)\0*.*\0";
    ofn.lpstrFile = fileName;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST;

    if (GetOpenFileName(&ofn) == TRUE) {
        //cout << "Archivo seleccionado: " << fileName << endl;

        /*---------------------------Abriendo archivo---------------------------*/
        ifstream inputFile(fileName); // Abre el archivo para lectura

        if (!inputFile.is_open()) {
            cout << "No se pudo abrir el archivo." << endl;
        }

        string line;
        while (getline(inputFile, line)) {
            //cout << line << endl;
            cout << "---------------------------" << endl;
            //--------------------------
            istringstream ss(line);
            string token;
            vector<std::string> tokens;

            while (getline(ss, token, ',')) {
                tokens.push_back(token);
            }

            push(tokens[0],tokens[1],tokens[2]);
            //cout << tokens[0]<< endl;//user_name
            //cout << tokens[1]<< endl;//user_password
            //cout << tokens[2]<< endl;//user_puesto
            //--------------------------
        }

        inputFile.close(); // Cierra el archivo

    } else {
        cout << "No se seleccionó ningún archivo." <<endl;
    }
    cout<<"Carga masiva realizada con exito!"<<endl;

}
