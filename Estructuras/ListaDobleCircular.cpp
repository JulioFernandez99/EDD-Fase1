#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>


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
    this->siguiente=NULL;
    this->anterior=NULL;
}

/*-------Clase Lista-------*/
class ListaDobleCircular {
public:
    int size=1;
    Nodo *primero;
    Nodo *ultimo;
    void push(string user_name,string user_pass,string user_puesto);
    void verLista();
    string buscar(string user_name,string user_pass);
    void cargaMasiva(string ruta);
    ListaDobleCircular();

};

ListaDobleCircular::ListaDobleCircular() {
    Nodo *project_manager=new Nodo("jf","35122","Project Manager");
    project_manager->anterior = project_manager;  //Esta parte es para hacerla circular
    project_manager->siguiente = project_manager; //Esta parte es para hacerla circular
    this->primero = project_manager;
    this->ultimo=project_manager;

}
void ListaDobleCircular::push(string user_name,string user_pass,string user_puesto) {
    Nodo *nuevo=new Nodo(user_name, user_pass,user_puesto);
    nuevo->anterior = ultimo;
    nuevo->siguiente = this->primero;//No existe en doble enlazada
    this->ultimo->siguiente = nuevo;
    this->primero->anterior = nuevo; //No exites en doble enlazada
    this->ultimo=nuevo;
    this->size++;

}

void ListaDobleCircular::verLista(){
    Nodo *aux = this->primero;
    while (aux->siguiente!=primero){
        cout<<aux->user_name<<endl;
        aux=aux->siguiente;
    }
    cout<<aux->user_name<<endl;
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




void  ListaDobleCircular::cargaMasiva(string ruta) {

    ifstream inputFile(ruta); // Abre el archivo para lectura

    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {

            istringstream ss(line);
            string token;
            vector<std::string> tokens;

            while (getline(ss, token, ',')) {
                tokens.push_back(token);
            }

            this->push(string(tokens[0]),string (tokens[1]),string (tokens[2]));
        }
        inputFile.close();
    } else {
        cerr << "Could not open the file." <<ruta<< std::endl;
    }
}

