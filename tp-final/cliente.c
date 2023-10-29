#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "arbol.h"

struct Cliente{

    char nombreYApellido[15];

    int hora;

    char turno[15];

};



ClientePtr crearCliente(char nyA[15], int hora, char t[15] ){


    ClientePtr cliente = (ClientePtr) malloc(sizeof(struct Cliente));


    strcpy(cliente->nombreYApellido, nyA);

    strcpy(cliente->turno, t);

    cliente->hora = hora;






    return cliente ;

};
ClientePtr crearClientePorTeclado(Nodo nodo){


    char nombreYApellido[50];
    int hora;
    char turno[15];

    printf("Ingrese el nombre y apellido del cliente: ");
    scanf("%s", nombreYApellido);
   // fgets(nombreYApellido, sizeof(nombreYApellido), stdin);


    printf("Ingrese la hora del cliente: ");
    scanf("%d", &hora);


    printf("Ingrese el turno del cliente: ");
    scanf("%s", turno);
   //fgets(turno, sizeof(turno), stdin);

    ClientePtr nuevoCliente = crearCliente(nombreYApellido, hora, turno);
    insertar(nodo,nuevoCliente,compararClientes);

    printf("cliente agregado quiere hacer algo mas? ");
    return nuevoCliente;


};

void mostrarCliente(ClientePtr c){

    printf("\n\t-----------CLIENTE-------------\n");
    printf("\tNOMBRE: %s\n",c->nombreYApellido);
    printf("\tTURNO: %s\n",c->turno);
    printf("\tHORA: %d\n",c->hora);


};

char* getNombreYApellido(ClientePtr c){
    return c->nombreYApellido;

};

char* getTurno(ClientePtr c){
    return c->turno;
};

int getHora(ClientePtr c){
    return c->hora;
};

void setNombreYApellido(ClientePtr c, char nYA[15]){

    strcpy(c->nombreYApellido, nYA);

};

void setHora(ClientePtr c, int hora){

    c->hora = hora;

};

void setTurno(ClientePtr c, char turno[15]){

    strcpy(c->turno, turno);

};

void destruirCliente(ClientePtr c){


    free(c);

};
/*                    hasta aca es mi parcial empiezo con los temas del tp                                 */


// creo las funciones que despues van a ser llamadas en el arbol, esto se tendria que hacer en todas las estructuras que quiera usar el arbol

int compararClientes( void* a,  void* b) {

  return strcmp(((ClientePtr)a)->nombreYApellido, ((ClientePtr)b)->nombreYApellido);
}
int compararClientesHorario( void* a,  void* b) {
   return (*(int*)a - *(int*)b);
}
int compararClientesTurno( void* a,  void* b) {
    return strcmp(((struct Cliente*)a)->turno, ((struct Cliente*)b)->turno);
}


void imprimirCliente( void* dato) {
    ClientePtr cliente = (ClientePtr)dato;
    printf("Nombre: %s, Hora: %d, Turno: %s\n", cliente->nombreYApellido, cliente->hora, cliente->turno);
}

