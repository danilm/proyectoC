/* 
 * File:   listadni.h
 * Author: daniellopezmesa
 *
 * Created on May 16, 2017, 12:45 PM
 */
#include <stdio.h>
#include <string.h>

#ifndef LISTADNI_H
#define	LISTADNI_H

struct listaDNI{
    char dni[10];
    struct listaDNI *siguiente;
};

typedef struct listaDNI elemento;
/*
 * Función que inserta un elemento en una lista vacía
 */

elemento *inserta_vacia(char *nuevoDNI){
    elemento *primero, *inserta;
    primero = NULL;
    inserta =(elemento*) malloc(sizeof(elemento));
    strncpy(inserta ->dni, nuevoDNI, 10);
    inserta->siguiente=NULL;
    primero = inserta;
    return primero;
}

/*
 * Función que inserta un elemento en una lista
 */

elemento *inserta(elemento *primero, char *nuevoDNI){
    
    elemento *insertar;
    insertar = (elemento*)malloc(sizeof(elemento));
    strncpy(insertar->dni,nuevoDNI,10);
    insertar->siguiente = primero;
    primero = insertar;
    return primero;
}
/*
 * Función que muestra los elementos de la lista
 */

void mostrarlista(elemento *primero){
    elemento *aux;
    aux = primero;
    while (aux != NULL){
        printf("DNI:%s\n", aux->dni);
        aux=aux->siguiente;
    }
}

void buscarElemento(FILE *fichero,elemento *primero, char *dnibuscar){
    elemento *aux;
    int numElementos = 0;
    aux = primero;
    while (aux != NULL){
        
        if (strcmp(aux->dni,dnibuscar)==0){
            numElementos++;
            
        }
        aux=aux->siguiente;
    }
    if (numElementos > 1){
        fprintf(fichero,"DNI:%s un total de %i veces\n", dnibuscar, numElementos);
    }
    
}

void listarDNI(FILE *fichero, elemento *primero){
    elemento *aux;
    aux = primero;
    char dnibuscar[10];
    while (aux != NULL){
        strncpy(dnibuscar,aux->dni,10);
        buscarElemento(fichero,aux,dnibuscar);
        aux=aux->siguiente;
    }
}

#endif	/* LISTADNI_H */

