#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"
#include "cliente.h"
#include "banco.h"

int main()
{
    // creo variables para ser usadas en el switch
 int opcion;
char nombre[50];
// creeo el banco
   ClientePtr c0 = crearCliente("carlos lopez",10,"caja de ahorro");
    Nodo raiz =  nuevoNodo(c0);
    BancoPtr b1 =crearBanco("santander","eva peron 111",raiz);

    // agrego clientes
    ClientePtr c5 = crearCliente("alberto x",13,"caja de ahorro");
    insertar(getRaiz(b1), c5, compararClientes);
    ClientePtr c1 = crearCliente("ruben fernandez",11,"caja de ahorro");
    insertar(getRaiz(b1), c1, compararClientes );
    ClientePtr c2 = crearCliente("lucia pascuale",9,"inversiones");
    insertar(getRaiz(b1), c2, compararClientes);
// inicio el menu

    printf("----- bienvenido ----\n");
    printf("----- ingrese 1 para ingresar un cliente por teclado ----\n----- ingrese 2 para buscar un cliente por nombre ----\n");
    printf("----- ingrese 3 para mostrar inorden ----\n----- ingrese 4 para posorder ----\n");
    printf("----- ingrese 5 para mostrar preorder----\n----- ingrese 6  para mostrar el banco ----\n----- ingrese 7 para eliminar el arbol ----\n---- ingrese 0 para salir :" );
do{
scanf("%d", &opcion);
getchar();

switch (opcion) {
    case 1:
        crearClientePorTeclado(getRaiz(b1));
        break;
    case 2:
        printf("escriba un nombre y apellido:");
       //scanf("%s", &nombre);
        //el scan daba errores
        fgets(nombre, sizeof(nombre), stdin);
        //seguia dando error asi que busque por internet y me encontre que es porque estaba leyendo el salto de linea y que la funcion strtok lo arreglaba;
        strtok(nombre, "\n");
        ClientePtr buscado = crearCliente(nombre,0,"asd");
        Nodo aux = nuevoNodo(NULL);
        aux = buscar(raiz,buscado,compararClientes);
        if (aux == NULL){
            printf("no se encontro el cliente, quiere hacer algo mas ?  ");

        }else{

        imprimirCliente(obtenerDato(aux));
        }
        break;
    case 3:
        inorden(raiz,imprimirCliente);

        break;
    case 4:
        postorden(raiz,imprimirCliente);

        break;
        case 5:
       preorden(raiz,imprimirCliente);

        break;
        case 6:
        mostrarBanco(b1);

        break;
        case 7:
        liberarArbol(raiz);

        break;
    default:
        printf("Opción no válida.\n");
        break;
}
}while (opcion != 0);






    return 0;

}
