#ifndef LINKEDlista_H
#define LINKEDlista_H




enum Booleanos {FALSE, TRUE};


typedef struct NodoE * Nodo;

typedef struct listaE *  Lista;


Nodo crearNodo(Lista lista, void *data);
Lista crearLista( int tamDelDatoEnBytes);
int estaVacia( Lista lista);
int obtenerTamanio( Lista lista);
Nodo obtenerPrimerNodo(Lista lista);
Nodo getProximo(Nodo n);
Lista copiarLista (Lista l);


void* getDatoN(Nodo n);
void* setDatoN(Nodo n, void* dato);
void* obtenerDato( Lista lista, int pos);
void* obtenerPrimerDato( Lista lista);
void* obtenerUltimoDato( Lista lista);
int obtenerDatoEnParametro( Lista lista, int pos, void *backup);
int insertar(Lista lista, void *data, int pos);
int insertarInicio(Lista lista, void *data);
int insertarFinal(Lista lista, void *data);
int removerInicio(Lista lista, void *backup);
int removerFinal(Lista lista, void *backup);
int remover(Lista lista, int pos, void *backup);
void liberarlista(Lista lista);


#endif
