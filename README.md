# <center>ProjectUp</center>


## Login
Esta parte es la encargada de dar acceso a los empleados existentes dentro del sistema,inicialmente solo se encuentra registrado el Projec Manager con nombre de usuario "PM-201902416" y password "35122".Seguidamente se desplazara un menu donde se encuentran las siguientes opciones.Para que esta parte funcione se realiza un busqueda en la lista circular de empleados hasta coincidir con los datos de algun nodo y se retorna un valor booleano.
![Ejemplo de Markdown](https://w7.pngwing.com/pngs/777/518/png-transparent-pikachu-misty-brock-ash-ketchum-pika-animal-s-cartoon-fictional-character-material-thumbnail.png)


## Carga de empleados
En este apartado se podran registrar empleados al sistema donde se le podran asignar desde proyectos hasta tareas.

En este apartado se trabajo con una lista circular doblemente enlazada.Para que esta funcione inicialmente se definio un nodo que almacene los datos de cada empleado,una vez creada la clase nodo se creo otra clase para la lista circular,y para agregar empleados a dicha lista se utilizo el metodo push que se encarga de crear un nodo con la informacion del empleado y enlazarlo con los demas nodos.

<details>
<summary>Carga manual</summary>
En esta parte se solicitara el nombre y password del empleado y se prodecera a hacer una operacion push a la lista circular.
  
</details>


<details>
<summary>Carga masiva</summary>
Para esta parte inicialemnte se desplegara un filechooser que se encargara de devolver la ruta del archivo que se desea analizar,teniendo la ruta del archivo que se desea analizar se procede a leerlo linea por linea.Al leer cada linea se hace un split con la coma que separa los datos,y se almacena en un vector,seguido a ello se realiza un push de la primera y segunda posicion del vector que corresponden al nombre y password del usuario.

</details>

## Crear proyectos

<details>
<summary>Descripcion</summary>
En este apartado se solicitara el nombre del proyecto y la prioridad.Para que esta parte fuera funcional se trabajo con una cola de prioridad,donde "A" es la prioridad mas alta y "C" la mas baja,para ello se definio un una clase empleado que se encarga de almacenar los datos del proyecto y generar un proyecto para cada uno,luego se definio una clase Cola con la funcion push que se encarga de recibir la prioridad y nombre del proyecto,antes de agregar el nuevo nodo se realiza una verificacion para insertar el nodo en la posicion correcta.

</details>

## Crear tareas
Para esta parte se trabajo con una lista simplemente enlazada,para ello se creo un nodo que almacena la informacion de cada tarea y despues de ello se crea una clase lista simple con su metodo push que se encarga de agregar al final de la lista los elementos.

## Asignar proyectos
Para poder asignar proyectos se solicitara el nombre del empleado,el codigo del proyecto a asignar y el puesto que tendra.Para ello se trabajo una Matriz dispersa que inicialmente se agregarn los proyectos y empleados.Teniendo los encabezados cargados se creo el metodo asignarProyecto donde se enlaza el empleado con el proyecto.

## Asignar tareas
Aca se utilizo la cola de prioridad ya antes mencionada,a cada clase proyecto inicialmente se le definio una lista doblemnte enlazada vacia a la cual se le podra ir agregando proyectos con su funcion push.Para poder asignar una tarea se solicita inicialmente el proyecto para poder buscarlo en la cola de prioridad nodo por nodo y si coincide con alguno se accede al objeto proyecto y sus tareas y se procede a hacerke push a la lista doblemente enlazada.

## Generar reportes
Aca se invoca la funcion graficar de los objetos cola de prioridad y matriz.

## Cerrar sesion
Se realiza un clear screen a la consola y se muestra el login nuevamente.

## Exit
Se detiene el flujo del programa con un exit(0)







