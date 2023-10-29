#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "banco.h"
#include "lista.h"
#include "cliente.h"


struct Banco{

    char nombre[15];

    char direccion[15];

    Lista listaClientes;

};



BancoPtr crearBanco(char n[15], char d[15]){

    BancoPtr b = (BancoPtr) malloc(sizeof(struct Banco));

    strcpy(b->direccion, d);

    strcpy(b->nombre, n);

    b->listaClientes = crearLista(sizeof(ClientePtr));

    return b;

};

void mostrarBanco(BancoPtr b){

    printf("\n\n-----------BANCO-------------\n");
    printf("NOMBRE: %s\n", b->nombre);
    printf("DIRECCION: %s\n", b->direccion);
    for (int i = 0 ; i<obtenerTamanio(b->listaClientes); i++){

       mostrarCliente (*(ClientePtr*)obtenerDato(b->listaClientes,i));


    }

};

void ordenarBanco(BancoPtr b){
Lista listaAux = getLista(b);
Nodo aux = obtenerPrimerNodo(listaAux);
int i = 0;
int cambio = 1;
void* ayuda;

do{
aux = obtenerPrimerNodo(listaAux);
i = 0;
cambio = 0;

while(getProximo(aux) != NULL){
ClientePtr cliente1 = *(ClientePtr*)obtenerDato(listaAux,i);
ClientePtr cliente2 = *(ClientePtr*)obtenerDato(listaAux,i+1);

    if(getHora(cliente1) > getHora(cliente2)){


        ayuda = getDatoN(aux);
        setDatoN(aux,getDatoN(getProximo(aux)));
        setDatoN(getProximo(aux),ayuda);
        cambio = 1;

    }

aux = getProximo(aux);
i++;


}








}while (cambio == 1);



}
void mostrarCajaDeAhorro(BancoPtr b){
Lista listaAux = getLista(b);
Nodo aux = obtenerPrimerNodo(listaAux);
int i = 0;
while (aux != NULL){
    ClientePtr cliente1 = *(ClientePtr*)obtenerDato(listaAux,i);
    if (strcmp(getTurno(cliente1),"caja de ahorro") == 0){

        mostrarCliente(cliente1);

    }

  aux = getProximo(aux);
  i++;
}

}
BancoPtr copiarBanco(BancoPtr b){


  BancoPtr copia = (BancoPtr) malloc(sizeof(struct Banco));

    strcpy(copia->direccion, b->direccion);

    strcpy(copia->nombre, b->nombre);

    copia->listaClientes = copiarLista(b->listaClientes);

    return copia;



}

char *getNombre(BancoPtr b ){
    return b->nombre;
};

char * getDireccion(BancoPtr b){
    return b->direccion;
};

Lista getLista(BancoPtr b){

return b->listaClientes;

}


void setNombre(BancoPtr b, char nuevo[15]){

    strcpy(b->nombre, nuevo);

};

void setDireccion(BancoPtr b, char  nuevo[15]){
    strcpy(b->direccion, nuevo);
};

void destruirBanco(BancoPtr b){

    free(b);
};
