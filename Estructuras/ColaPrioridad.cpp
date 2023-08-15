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
}

class ColaPrioridad{
public:
    int contadorProyectos=1;
    NodoPriori *primero;
    NodoPriori *ultimo;
    void push(string nombre_,char priori_);
    void ordenarCola();
    void verCola();
    void mover(NodoPriori *inicio,NodoPriori *final);
    ColaPrioridad();

};

ColaPrioridad::ColaPrioridad() {
    this->primero=NULL;
    this->ultimo=NULL;
}


void ColaPrioridad::mover(NodoPriori *inicio, NodoPriori *final) {

    string nombre,numero;
    char prioridad;

    inicio->nombre_proyecto=final->nombre_proyecto;
    inicio->prioridad=final->prioridad;
    inicio->numeroProyecto=final->numeroProyecto;

    final->nombre_proyecto=nombre;
    final->prioridad=prioridad;
    final->numeroProyecto=numero;
}

void ColaPrioridad::ordenarCola() {

    if (this->primero==NULL){
        return;
    }
    cout<<"entro"<<endl;
    bool swapped= true;
    NodoPriori* temp;
    NodoPriori* end = NULL;

    do {

        swapped = false;
        temp = this->primero;

        while (temp->siguiente != end) {
            if (temp->prioridad > temp->siguiente->prioridad) {
                // Realiza el intercambio de nodos

                string nombre=temp->nombre_proyecto;
                string numero=temp->numeroProyecto;
                char priori = temp->prioridad;



                temp->nombre_proyecto = temp->siguiente->nombre_proyecto;
                temp->prioridad = temp->siguiente->prioridad;
                temp->numeroProyecto = temp->siguiente->numeroProyecto;

                temp->siguiente->nombre_proyecto = nombre;
                temp->siguiente->prioridad = priori;
                temp->siguiente->numeroProyecto = numero;

                swapped = true;
            }
            temp = temp->siguiente;
        }
        end = temp;
    } while (swapped);

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
    if (this->primero==NULL){
        this->primero=this->ultimo=nuevoNodo;
    } else{
        ultimo->siguiente=nuevoNodo;
        nuevoNodo->anterior=ultimo;
        ultimo=nuevoNodo;
        contadorProyectos++;
        //ordenarCola();
    }


}

void ColaPrioridad::verCola() {
    NodoPriori *temp=this->primero;
    while (temp!=NULL){
        cout<<temp->numeroProyecto;
        temp=temp->siguiente;
    }
    delete temp;
}




