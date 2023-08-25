#include "ListaD.h"

#include <iostream>
#include <string>
using namespace std;

ListaD::ListaD() {
    this->primero=NULL;
    this->ultimo=NULL;
}

void ListaD::push(string tarea_, string numero_,string encargado) {
    NodoD *newNodo=new NodoD(tarea_,numero_,encargado);
    if(this->primero==NULL){
        this->primero=this->ultimo=newNodo;
        return;
    }
    this->ultimo->siguiente=newNodo;
    this->ultimo=newNodo;

}


void ListaD::verListaDoble() {
    NodoD *temp=this->primero;
    while (temp!=NULL){
        cout<<"["<<temp->numero_py<<". "<<temp->tarea<<". "<<temp->encargado<<"]->";
        temp=temp->siguiente;
    }

}

ListaD::~ListaD()
{
    //dtor
}
