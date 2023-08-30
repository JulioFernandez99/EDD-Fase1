#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Lista.h"

using namespace std;



Lista::Lista()
{
    NodoLista *project_manager=new NodoLista("jf","35122");
    project_manager->anterior = project_manager;  //Esta parte es para hacerla circular
    project_manager->siguiente = project_manager; //Esta parte es para hacerla circular
    this->primero = project_manager;
    this->ultimo=project_manager;
}

void Lista::push(string user_name,string user_pass) {
    NodoLista *nuevo=new NodoLista(user_name, user_pass);
    nuevo->anterior = ultimo;
    nuevo->siguiente = this->primero;//No existe en doble enlazada
    this->ultimo->siguiente = nuevo;
    this->primero->anterior = nuevo; //No exites en doble enlazada
    this->ultimo=nuevo;
    this->size++;

}

void Lista::verLista(){
    NodoLista *aux = this->primero;
    while (aux->siguiente!=primero){
        cout<<aux->user_name<<endl;
        aux=aux->siguiente;
    }
    cout<<aux->user_name<<endl;
}

bool Lista::buscar(string user_name, string user_pass){
    NodoLista *aux = this->primero;
    int contador = 0;
    while(this->size > contador) {
        if (aux->user_name == user_name && aux->user_pass==user_pass) {
           return true;
        }
        aux = aux->siguiente;
        contador++;
    }

    return false;
}




void  Lista::cargaMasiva(string ruta) {

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

            this->push(string(tokens[0]),string (tokens[1]));
        }
        inputFile.close();
    } else {
        cerr << "Could not open the file." <<ruta<< std::endl;
    }
}





Lista::~Lista()
{
    //dtor
}
