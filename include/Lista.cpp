#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Lista.h"

using namespace std;



Lista::Lista()
{
    this->primero = NULL;
    this->ultimo=NULL;

}

void Lista::push(string user_name,string user_pass) {
    NodoLista *nuevo=new NodoLista(user_name, user_pass);
    if(this->primero==NULL){
        this->primero=nuevo;
        this->ultimo=nuevo;
        this->primero->siguiente=this->ultimo;
        this->primero->anterior=this->ultimo;
        this->ultimo->siguiente=this->primero;
        this->ultimo->anterior=this->primero;
        return;
    }

    nuevo->siguiente=ultimo->siguiente;
    nuevo->anterior=ultimo;
    ultimo->siguiente=nuevo;
    ultimo=nuevo;

    this->size++;

}

void Lista::verLista(){
    NodoLista *aux = this->primero;
    while (aux->siguiente!=primero){
        cout<<aux->EmpleadoSistema->user_name<<endl;
        aux=aux->siguiente;
    }
    cout<<aux->EmpleadoSistema->user_name<<endl;
}

bool Lista::buscar(string user_name, string user_pass){
    NodoLista *aux = this->primero;
    int contador = 0;
    while(this->size > contador) {
        if (aux->EmpleadoSistema->user_name == user_name && aux->EmpleadoSistema->user_pass==user_pass) {
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
                if (token != "user") {
                    tokens.push_back(token);
                }
            }

            if (tokens.size() >= 2) {
                this->push(tokens[0], tokens[1]);
            }
        }
        inputFile.close();
    } else {
        cerr << "Could not open the file." <<ruta<< std::endl;
    }
}

void Lista::pop(){
    if (primero!=NULL) {
            return;
        }

        NodoLista* actual = this->primero;
        while (actual->siguiente != this->primero) {
            NodoLista* siguiente = this->primero->siguiente;
            delete actual;
            actual = siguiente;
        }
        delete actual;
        this->primero=NULL;
}




Lista::~Lista()
{
    //dtor
}
