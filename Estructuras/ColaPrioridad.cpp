#include <iostream>
#include <string>

using namespace std;

class NodoPriori{
public:

    string nombre_proyecto;
    char prioridad;
    string numeroProyecto;
    NodoPriori *siguiente;
    NodoPriori *anterior;
    NodoPriori(string nombre_py,char priori_,string contadorProyecto);
};

NodoPriori::NodoPriori(string nombre_py, char priori_,string contadorProyecto) {
    this->nombre_proyecto=nombre_py;
    this->prioridad=priori_;
    this->numeroProyecto=contadorProyecto;
    this->siguiente=NULL;
    this->anterior=NULL;
}

class ColaPrioridad{
public:
    int contadorProyectos=1;
    NodoPriori *primero;
    NodoPriori *ultimo;
    void push(string nombre_,char priori_);
    void verCola();
    void mover(NodoPriori *inicio,NodoPriori *final);
    ColaPrioridad();

};

ColaPrioridad::ColaPrioridad() {
    this->primero=NULL;
    this->ultimo=NULL;
}

void ColaPrioridad::push(string nombre_, char priori_) {
    string cadenaCont="PY-";

    if(contadorProyectos<10){
        cadenaCont+= "00"+to_string(contadorProyectos);
    }
    else if(contadorProyectos>10 && contadorProyectos<100){
        cadenaCont+= "0"+to_string(contadorProyectos);
    } else{
        cadenaCont+=to_string(contadorProyectos);
    }

    NodoPriori *nuevoNodo=new NodoPriori(nombre_, priori_,cadenaCont);
    if(primero==NULL){
        primero=nuevoNodo;
        ultimo=nuevoNodo;
        contadorProyectos++;
        return;
    }

    NodoPriori *temp=primero;
    while (temp!=NULL){

        if ( (nuevoNodo->prioridad > temp->prioridad || nuevoNodo->prioridad == temp->prioridad) && (temp->siguiente==NULL ) ) {
            //Si el que viene es mayor

            temp->siguiente = nuevoNodo;
            nuevoNodo->anterior=temp;
            ultimo = nuevoNodo;
            contadorProyectos++;
            return;
        }
        else if ((nuevoNodo->prioridad < temp->prioridad || nuevoNodo->prioridad == temp->prioridad) && temp->anterior==NULL){
            //Si el que viene es menor

            temp->anterior=nuevoNodo;
            nuevoNodo->siguiente=temp;
            primero=nuevoNodo;

            contadorProyectos++;
            return;
        }
        else if ((temp->prioridad  > nuevoNodo->prioridad) && temp->anterior!=NULL ){
            //cout<<"Entro"<<nuevoNodo->prioridad<<endl;
            //Inserta entre nodos
            temp->anterior->siguiente=nuevoNodo;
            temp->anterior=nuevoNodo;
            nuevoNodo->anterior=temp->anterior;
            nuevoNodo->siguiente=temp;
            contadorProyectos++;
            return;
        }
        temp=temp->siguiente;
    }

}

void ColaPrioridad::verCola() {
    NodoPriori *temp=primero;
    while (temp!=NULL){
        cout<<"["<<temp->numeroProyecto<<","<<temp->prioridad<<"]"<<",";
        temp=temp->siguiente;
    }

}

/*
int main(){

    ColaPrioridad *cl=new ColaPrioridad();
    cl->push("Hola1",'A');
    cl->push("Hola1",'B');
    cl->push("Hola1",'C');
    cl->push("Hola1",'D');
    cl->push("Hola1",'E');
    cl->push("Hola1",'F');
    cl->push("Hola1",'G');
    cl->push("Hola1",'H');
    cl->push("Hola1",'I');
    cl->push("Hola1",'J');
    cl->push("Hola1",'K');
    cl->push("Hola1",'L');
    cl->push("Hola1",'M');
    cl->push("Hola1",'N');
    cl->push("Hola1",'O');
    cl->push("Hola1",'P');
    cl->push("Hola1",'Q');
    cl->push("Hola1",'R');
    cl->push("Hola1",'S');
    cl->push("Hola1",'T');
    cl->push("Hola1",'U');
    cl->push("Hola1",'V');
    cl->push("Hola1",'W');
    cl->push("Hola1",'X');
    cl->push("Hola1",'Y');
    cl->push("Hola1",'Z');






    cl->verCola();
    return 0;
}
*/
