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
    char dni[9];
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
    strncpy(inserta ->dni, nuevoDNI, 9);
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
    strncpy(insertar->dni,nuevoDNI,9);
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
        printf("%s\n", aux->dni);
        aux=aux->siguiente;
    }
}
#endif	/* LISTADNI_H */

