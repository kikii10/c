#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED


struct NodoE ;


typedef struct NodoE * Nodo;


Nodo nuevoNodo(void * dato);

void insertar( Nodo nodo, void * dato,int (*comparar)( void*,  void*)) ;

void preorden( Nodo nodo,void (*imprimir)(void*)) ;

void inorden( Nodo nodo,void (*imprimir)(void*)) ;

void postorden( Nodo nodo,void (*imprimir)(void*)) ;

Nodo buscar(Nodo nodo, void * dato, int (*comparar)( void*,  void*));
void* obtenerDato(Nodo nodo);


void liberarArbol(Nodo nodo);

void postorden(Nodo nodo, void (*liberar)(void*));

#endif // ARBOL_H_INCLUDED
