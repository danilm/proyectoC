/* 
 * File:   vuelo.h
 * Author: daniellopezmesa
 *
 * Created on May 15, 2017, 12:11 PM
 */
#include <stdio.h>
#include "listadni.h"

#ifndef VUELO_H
#define	VUELO_H

struct vuelo{
    char idVuelo[30];
    char operadora[50];
    char aerolinea[50];
    char tipoAvion[10];
    int numPasajeros;
    struct listaDNI *listadoDNI;
    struct vuelo* siguiente;
};

typedef struct vuelo elementoVuelo;

/*
 * Función que inserta un elemento en una lista vacía
 */

elementoVuelo *inserta_vaciaV(elementoVuelo *elemento){
    elementoVuelo *primero, *inserta;
    primero = NULL;
    inserta =(elementoVuelo*) malloc(sizeof(elementoVuelo));
    strncpy(inserta->idVuelo,elemento->idVuelo,30);
    strncpy(inserta->operadora,elemento->operadora,50);
    strncpy(inserta->aerolinea,elemento->aerolinea,50);
    strncpy(inserta->tipoAvion,elemento->tipoAvion,10);
    inserta->numPasajeros = elemento->numPasajeros;
    inserta->siguiente=NULL;
    primero = inserta;
    return primero;
}


/*
 * Función que inserta un elemento en una lista
 */

elementoVuelo *insertaV(elementoVuelo *primero, elementoVuelo *elemento){
    elementoVuelo *insertar;
    insertar = (elementoVuelo*)malloc(sizeof(elementoVuelo));
    strncpy(insertar->idVuelo,elemento->idVuelo,30);
    strncpy(insertar->operadora,elemento->operadora,50);
    strncpy(insertar->aerolinea,elemento->aerolinea,50);
    strncpy(insertar->tipoAvion,elemento->tipoAvion,10);
    insertar->numPasajeros = elemento->numPasajeros;
    insertar->siguiente = primero;
    primero = insertar;
    return primero;
}

/**
 * Función que busca la aerolinea 
 * @param primero
 * @param aerolinea
 * @return 
 */
elementoVuelo *buscarAerolinea(elementoVuelo *primero, char *aerolinea){
    return primero;
}
/*
 * Función que muestra los elementos de la lista
 */

void mostrarlistaVuelo(elementoVuelo *primero){
    elementoVuelo *aux;
    aux = primero;
    while (aux != NULL){
        printf("idVuelo:%s\n", aux->idVuelo);
        printf("operadora:%s\n", aux->operadora);
        printf("aerolinea:%s\n", aux->aerolinea);
        printf("tipoAvion:%s\n", aux->tipoAvion);
        printf("numPasajeros:%i\n", aux->numPasajeros);
        mostrarlista(aux->listadoDNI);
        aux=aux->siguiente;
    }
}

#endif	/* VUELO_H */

