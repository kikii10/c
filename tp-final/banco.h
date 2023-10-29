#ifndef BANCO_H_INCLUDED
#define BANCO_H_INCLUDED
#include "arbol.h"
#include "cliente.h"


struct Banco;

typedef struct Banco * BancoPtr;

BancoPtr crearBanco(char n[15], char d[15],Nodo raiz);

void mostrarBanco(BancoPtr b);
Nodo getRaiz(BancoPtr b);
char *getNombre(BancoPtr b );

char * getDireccion(BancoPtr b);


void setNombre(BancoPtr b, char  nuevo[15]);

void setDireccion(BancoPtr b, char  nuevo[15]);

void destruirBanco(BancoPtr b);


#endif // BANCO_H_INCLUDED
