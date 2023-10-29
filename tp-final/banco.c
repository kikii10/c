#include "banco.h"
#include "arbol.h"
#include "cliente.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


struct Banco{

    char nombre[15];

    char direccion[15];

    Nodo raiz;

};



BancoPtr crearBanco(char n[15], char d[15],Nodo raiz){

    BancoPtr b = (BancoPtr) malloc(sizeof(struct Banco));

    strcpy(b->direccion, d);

    strcpy(b->nombre, n);

    b->raiz = raiz;

    return b;

};

void mostrarBanco(BancoPtr b){

    printf("\n\n-----------BANCO-------------\n");
    printf("NOMBRE: %s\n", b->nombre);
    printf("DIRECCION: %s\n", b->direccion);

    inorden(b->raiz,imprimirCliente);

};
Nodo getRaiz(BancoPtr b){

return b->raiz;

};


char *getNombre(BancoPtr b ){
    return b->nombre;
};

char * getDireccion(BancoPtr b){
    return b->direccion;
};


void setNombre(BancoPtr b, char nuevo[15]){

    strcpy(b->nombre, nuevo);

};

void setDireccion(BancoPtr b, char  nuevo[15]){
    strcpy(b->direccion, nuevo);
};

void destruirBanco(BancoPtr b){

    free(b);
};

