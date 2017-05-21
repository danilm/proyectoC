/* 
 * File:   pasajero.h
 * Author: daniellopezmesa
 *
 * Created on May 19, 2017, 11:57 AM
 */
#include <stdio.h>
#include <string.h>

#ifndef PASAJERO_H
#define	PASAJERO_H

struct pasajero {
    char dni[10];
    char nombre[50];
    char aerolinea[50];
    char tipoAvion[10];
    char fecha[10];
    struct pasajero *siguiente;
};

typedef struct pasajero elementoPasajero;


/*
 * Función que inserta un elemento en una lista vacía
 */

elementoPasajero *inserta_vaciaP(elementoPasajero *elemento){
    elementoPasajero *primero, *inserta;
    primero = NULL;
    inserta =(elementoPasajero*) malloc(sizeof(elementoPasajero));
    strncpy(inserta->dni,elemento->dni,10);
    strncpy(inserta->nombre,elemento->nombre,50);
    strncpy(inserta->aerolinea,elemento->aerolinea,50);
    strncpy(inserta->tipoAvion,elemento->tipoAvion,10);
    inserta->siguiente=NULL;
    primero = inserta;
    return primero;
}


/*
 * Función que inserta un elemento en una lista
 */

elementoPasajero *insertaP(elementoPasajero *primero, elementoPasajero *elemento){
    elementoPasajero *insertar;
    insertar = (elementoPasajero*)malloc(sizeof(elementoPasajero));
    strncpy(insertar->dni,elemento->dni,10);
    strncpy(insertar->nombre,elemento->nombre,50);
    strncpy(insertar->aerolinea,elemento->aerolinea,50);
    strncpy(insertar->tipoAvion,elemento->tipoAvion,10);
    insertar->siguiente = primero;
    primero = insertar;
    return primero;
}


/*
 * Función que muestra los elementos de la lista
 */

void mostrarlistaP(elementoPasajero *primero){
    elementoPasajero *aux;
    aux = primero;
    while (aux != NULL){
        printf("dni:%s\n", aux->dni);
        printf("nombre:%s\n", aux->nombre);
        printf("aerolinea:%s\n", aux->aerolinea);
        printf("tipoAvion:%s\n", aux->tipoAvion);
        
        aux=aux->siguiente;
    }
}


#endif	/* PASAJERO_H */

