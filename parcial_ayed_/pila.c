#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"
#include "cliente.h"
#include "banco.h"
#include "lista.h"


struct NodoE {
    void * data;
    Nodo proximo;
};

struct PilaE{
    Nodo primero;
    int tamanio;
    int tamDelDatoEnBytes;
};


Nodo crearNodop (Pila pila, void *data) {
    Nodo temp =  malloc(sizeof (struct NodoE));


    temp->data = malloc(pila->tamDelDatoEnBytes);

    if (!temp->data) {
        free(temp);
        return temp;
    }


    memcpy(temp->data, data, pila->tamDelDatoEnBytes);

    return temp;
}



Pila crearPila( int tamDelDatoEnBytes) {

    Pila pila = malloc(sizeof(struct PilaE));



    pila->primero = NULL;
    pila->tamanio = 0;
    pila->tamDelDatoEnBytes = tamDelDatoEnBytes;

    return pila;
}

void apilar(Pila pila,void* dato){

    Nodo aux = crearNodop(pila, dato);
    if (pila->tamanio == 0) {
        pila->primero = aux;
        aux->proximo = NULL;
        pila->tamanio++;

    }

    aux->proximo = pila->primero;
    pila->primero = aux;
    pila->tamanio++;


}
void desapilar(Pila pila,void* guardado){

        Nodo siguiente = pila->primero->proximo;
        memcpy(guardado, pila->primero->data, pila->tamDelDatoEnBytes);

        free(pila->primero->data);
        free(pila->primero);
        pila->primero = siguiente;
        pila->tamanio--;



}
Pila apilarLista(Lista l){

Pila apilada = crearPila(sizeof(obtenerDato(l,0)));
Nodo aux = obtenerPrimerNodo(l);
int i=0;
while (aux != NULL){

   apilar(apilada,obtenerDato(l,i));
    aux = aux->proximo;
    i++;

}

return apilada;



}

void desapilarTodo(Pila p){

for (int i = 0; i<p->tamanio+1; i++){

void* guardado;
desapilar(p,&guardado);
printf("cliente desapilado");
mostrarCliente((ClientePtr*)guardado);
}



}



