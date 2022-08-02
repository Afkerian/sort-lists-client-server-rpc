// Calculadora - suma y multiplica enteros, utilizando RPC

#include <ctype.h>
#include <rpc/rpc.h>
#include "list.h"
#include <stdlib.h>

bool_t xdr_param();

typedef param *lista;
void insert(lista *L, int n);

main(int argc, char *argv[])
{
    lista p = NULL;
    int s;
    int number;

    // SHELL=/bin/bash

    if (argc <2)
    {
        printf("USO: client <server-IP> \n");
        exit(1);
    }

    // Aqui se registran los nodos de la lista
    
    printf("Ingrese el numero 0 para terminar\n");
    do
    {
        /* code */
        
        scanf("%d",&number);
        printf("number: %d\n",number);
        insert(&p,number);
    } while (number!=0);
    
    printf("Estamos ordenando la lista...por favor espere\n");

    // p.a = atoi (argv[2]);
    // p.b = atoi (argv[3]);

    callrpc(argv[1], P, V, SUMA, xdr_param, &p, xdr_int, &s);
    printf("s= %d\n", s);
}

bool_t xdr_param(XDR *xdrp, param *p)
{
    if (xdr_int(xdrp, &(p->numero)) == FALSE)
        return (FALSE);
    return (xdr_int(xdrp, &(p->sig)));
}

void insert(lista *L, int n)
{
    lista aux = malloc(sizeof(param));         // Crear un nuevo nodo.
    aux->numero = n;                           // Asignar el valor al nodo.
    aux->sig = *L;                             // Apuntar el nodo al nodo que apuntaba la lista.
    *L = aux;                                  // Hacer que la lista apunte al nodo nuevo.
    printf("Se agrego el %d a la lista\n", n); // Escribir en pantalla que se agregó el valor a la lista.
} /* inserta el valor n al frente de la lista */