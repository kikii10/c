#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include "lista.h"

typedef struct NodoE * Nodo;

typedef struct PilaE *  Pila;


Nodo crearNodop(Pila pila, void *data);
Pila crearPila (int tamDelDatoEnBytes);
void apilar(Pila,void * dato);
void desapilar(Pila p, void* guardado);
Pila apilarLista(Lista l);
void desapilarTodo(Pila p);

#endif // PILA_H_INCLUDED
