#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

#include "cliente.h"
#include "banco.h"
#include "pila.h"



int main()
{
    printf("PARCIAL AYED - ignacio - szymborski - 42396340\n");

    printf("\n----------PUNTO 1: Original-----------\n ");

    BancoPtr b1 =crearBanco("santander","eva peron 111");
   ClientePtr c1 = crearCliente("ruben fernandez",11,"caja de ahorro");
    insertarInicio(getLista(b1),&c1);
    ClientePtr c2 = crearCliente("lucia pascuale",9,"inversiones");
    insertarInicio(getLista(b1),&c2);
    ClientePtr c3 = crearCliente("brenda benitez",11,"moneda extranjera");
    insertarInicio(getLista(b1),&c3);
    ClientePtr c4 = crearCliente("luana szpyrka",13,"caja de ahorro");
    insertarInicio(getLista(b1),&c4);

    mostrarBanco(b1);
 //hago la copia del banco antes de ordenarlo
    BancoPtr copia = copiarBanco(b1);
    printf("\n----------PUNTO 2: Ordenado-----------\n ");

    ordenarBanco(b1);
    mostrarBanco(b1);

    printf("\n----------PUNTO 3: Copia-----------\n ");
    mostrarBanco(copia);
    printf("\n----------PUNTO 4: Buscar: Caja de Ahorro-----------\n ");
    mostrarCajaDeAhorro(b1);
    printf("\n----------PUNTO 5: Apilar -----------\n ");

    Pila p1 = apilarLista(getLista(b1));
    desapilarTodo(p1);




    return 0;
}
