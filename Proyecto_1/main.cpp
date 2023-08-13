#include <iostream>
#include <string>
#include "Listas/CircularDoble.cpp"

/*********Variables globales*********/
ListaDobleCircular *empleados;
string name_user;
string password_user;

/*********Prototipo de funciones*********/
void Admin();
void Login();


/*********Menu de login*********/
void Login(){
    cout<<"---------Login---------"<<endl;
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

/*********Menu de admin*********/
 void Admin(){
     int op;
     do{
        cout<<"---------Menu Admin---------"<<endl;
        cout<<"1.Cargar empleados"<<endl;
        cout<<"2.Crear proyecto"<<endl;
        cout<<"3.Crear tareas"<<endl;
        cout<<"4.Asignar tareas"<<endl;
        cout<<"Seleccione una opcion..."; cin>>op;
        switch (op) {

            /*******************Cargar empleados*******************/
            case 1:
                int opCargarEmpleados;
                cout << "---------Cargar empleados---------" << endl;
                cout <<"1.Carga masiva"<<endl;
                cout <<"2.Carga manual"<<endl;
                cin>>opCargarEmpleados;
                switch (opCargarEmpleados) {
                    case 1:
                            empleados->cargaMasiva();
                            Admin();
                        break;
                    case 2:
                        //-------Cargar empleados manual-------
                        int opPuesto;
                        string tempUser,tempPass,tempPuesto;
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
                }

                break;

                /*******************Cargar empleados*******************/
            case 2:
                cout << "Crear proyecto" << endl;
                break;
            case 3:
                cout << "Crear tareas" << endl;
                break;
            case 4:
                cout << "Asignar tareas" << endl;
                empleados->verLista();
                break;

        }

    }while (op<1 || op>4);

}



int main() {
        empleados=new ListaDobleCircular();
        Login();

    return 0;
}
