#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"
#include "cliente.h"


struct NodoE {
    void* dato;
    Nodo izquierda;
    Nodo derecha;

};




 Nodo nuevoNodo(void* dato) {
    // Solicitar memoria
     Nodo nodo = malloc(sizeof(struct NodoE));

    // Asignar el dato e iniciar hojas
    nodo->dato = dato;
    nodo->izquierda = nodo->derecha = NULL;

    return nodo;
  /*  Nodo nodo = malloc(sizeof(struct NodoE));

    nodo->dato = malloc(sizeof(dato));
    memcpy(nodo->dato, dato, sizeof(dato));
    nodo->izquierda = nodo->derecha = NULL;*/
}

void insertar( Nodo nodo, void* dato, int (*comparar)( void*,  void*)) {
/*esto quizas no funciona*/
if (nodo == NULL) {
    nodo = nuevoNodo(dato);
    return;
}

    // ¿Izquierda o derecha?
    // Si es mayor va a la derecha

    if (comparar(dato, nodo->dato)< 0) {
        // Tienes espacio a la derecha?
        if (nodo->derecha == NULL) {
            nodo->derecha = nuevoNodo(dato);
        } else {
            // Si la derecha ya está ocupada, recursividad ;)
            insertar(nodo->derecha, dato,comparar);
        }
    } else {
        // Si no, a la izquierda
        if (nodo->izquierda == NULL) {
            nodo->izquierda = nuevoNodo(dato);
        } else {
            // Si la izquierda ya está ocupada, recursividad ;)
            insertar(nodo->izquierda, dato,comparar);
        }
    }
}


void preorden( Nodo nodo,void (*imprimir)(void*)) {
    if (nodo != NULL) {
        imprimir(nodo->dato);
        // aca hay que hacer un get Nombre para el dato
        preorden(nodo->izquierda,imprimir);
        preorden(nodo->derecha,imprimir);
    }
}

void inorden(Nodo nodo,void (*imprimir)(void*)) {
    if (nodo != NULL) {
        inorden(nodo->izquierda,imprimir);
        imprimir(nodo->dato);
        inorden(nodo->derecha,imprimir);
    }
}

void postorden( Nodo nodo,void (*imprimir)(void*)) {
    if (nodo != NULL) {
        postorden(nodo->izquierda,imprimir);

        postorden(nodo->derecha,imprimir);
        imprimir(nodo->dato);
    }
}



void liberarArbol(Nodo nodo) {
    if (nodo != NULL) {
        liberarArbol(nodo->izquierda);
        liberarArbol(nodo->derecha);
        free(nodo->dato);
        free(nodo);
    }
}
void* obtenerDato(Nodo nodo) {
    return nodo->dato;
}

Nodo buscar(Nodo nodo, void* dato,int (*comparar)( void*,  void*) )
{
    if (nodo == NULL)
    {
        return NULL;
    }



    if ( comparar(dato, nodo->dato) == 0)
    {
        return nodo;
    }

    else if (comparar(dato, nodo->dato) < 0 )
    {


        return buscar(nodo->derecha, dato,comparar);
    }
    else
    {
        return buscar(nodo->izquierda, dato,comparar);
    }
}
