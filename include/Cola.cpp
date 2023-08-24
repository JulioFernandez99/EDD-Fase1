#include <iostream>
#include <string>
#include <fstream>
#include "Cola.h"
#include "Proyecto.h"

using namespace std;

Cola::Cola()
{
    this->primero=NULL;
    this->ultimo=NULL;
}


void Cola::push(string nombre_, char priori_) {
    string cadenaCont="PY-";

    if(contadorProyectos<10){
        cadenaCont+= "00"+to_string(contadorProyectos);
    }
    else if(contadorProyectos>9 && contadorProyectos<100){
        cadenaCont+= "0"+to_string(contadorProyectos);
    } else{
        cadenaCont+=to_string(contadorProyectos);
    }


    NodoCola *nuevoNodo=new NodoCola(priori_,new Proyecto(nombre_,cadenaCont,priori_));
    if(primero==NULL){

        primero=nuevoNodo;
        ultimo=nuevoNodo;
        contadorProyectos++;
        return;
    }

    NodoCola *temp=primero;
    NodoCola *anterior=NULL;

    while (temp!=NULL){
        if ( (nuevoNodo->prioridad > temp->prioridad || nuevoNodo->prioridad == temp->prioridad) && (temp->siguiente==NULL ) ) {
            //Si el que viene es mayor
            temp->siguiente = nuevoNodo;
            ultimo = nuevoNodo;
            contadorProyectos++;
            return;
        }
        else if ((nuevoNodo->prioridad < temp->prioridad || nuevoNodo->prioridad == temp->prioridad) && anterior==NULL){
            //Si el que viene es menor

            nuevoNodo->siguiente=temp;
            primero=nuevoNodo;
            contadorProyectos++;
            return;
        }
        else if ((temp->prioridad  > nuevoNodo->prioridad) && anterior!=NULL ){
            //cout<<"Entro"<<nuevoNodo->prioridad<<endl;
            //Inserta entre nodos
            anterior->siguiente=nuevoNodo;
            nuevoNodo->siguiente=temp;
            contadorProyectos++;
            return;
        }
        anterior=temp;
        temp=temp->siguiente;
    }

}

void Cola::pop() {
    if(primero!=NULL){
        primero=primero->siguiente;
    }

}


bool Cola::buscar(string numero_py) {
    NodoCola *temp=primero;
    while (temp!=NULL){
        if (string(temp->Proyecto_C->numeroProyecto)==numero_py){
            return true;
        }
        temp=temp->siguiente;
    }
    return false;
}


void Cola::verCola() {
    NodoCola *temp=primero;
    while (temp!=NULL){
        //cout<<"["<<temp->numeroProyecto<<","<<temp->prioridad<<"]"<<",";
        cout<<temp->Proyecto_C->numeroProyecto<<". "<<temp->Proyecto_C->nombre_proyecto<<","<<temp->prioridad<<endl;
        temp=temp->siguiente;
    }
}


string Cola::textoGrafo() {
    string cadena="";
    int cont=0;
    NodoCola *aux=this->primero;
    while (aux!=NULL){
        cadena+="nodo"+ to_string(cont)+"[label=\""+aux->Proyecto_C->numeroProyecto+"\\n"+" Prioridad:"+aux->prioridad+"\"]; \n";
        aux=aux->siguiente;
        cont++;
    }
    cadena+="nodo"+ to_string(cont)+"[label=\""+"NULL"+"\"]; \n";

    for (int i = 0; i < cont; ++i) {
        cadena+="nodo"+ to_string(i)+"->""nodo"+ to_string(i+1)+"; \n";
    }
    cadena+="\n}";
    return cadena;
}

void Cola::graficar() {
    ofstream archivo;
    archivo.open("ColaDePrioridad.dot",ios::out);
    if (archivo.fail()){
        cout<<"Se produjo un error al abrir el archivo";


    } else{
        archivo<<"digraph graficaLista {\nrankdir=LR;\nnode[shape=\"record\"]; \n"<<textoGrafo();
        archivo.close();

    }

    try{
        system("dot -Tpng ColaDePrioridad.dot -o ColaDePrioridad.png");
        cout<<"Reporte generado con exito.."<<endl;
    }catch (exception  e){
        cout<<"Error al generar la grafica";
    }


}


string Cola::getNameProyecto(string numero_py){

    NodoCola *temp=primero;
    while (temp!=NULL){
        if (string(temp->Proyecto_C->numeroProyecto)==numero_py){
            return temp->Proyecto_C->nombre_proyecto;
        }
        temp=temp->siguiente;
    }
    return "";
}


Cola::~Cola()
{
    //dtor
}
