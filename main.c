/* 
 * File:   main.c
 * Author: daniellopezmesa
 *
 * Created on May 15, 2017, 12:06 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vuelo.h"
#include "listadni.h"
#include "fichero.h"
#include "pasajero.h"
#include "ficheroOperadora.h"


/*
 * 
 */
elementoVuelo ficheroVuelo;
elemento *primero;
elementoVuelo *vectorVuelos;
elementoPasajero *vectorPasajeros;
int numVuelos=0;
char* nombre_fichero="eurocontrol.txt";
char* fichero_operadora ="operadora.txt";

int main(int argc, char** argv) {

    //Paso uno: leer fichero de Eurocontrol
    vectorVuelos = tratarfichero(nombre_fichero, 144);
    mostrarlistaVuelo(vectorVuelos);
    //Paso dos: leer fichero de la operadora web
    printf("Leyendo fichero de operadora...\n");
    vectorPasajeros = tratarficheroP(fichero_operadora,99);
    //Paso tres: volcar en la estructura de datos creada los datos de cada fichero
     
    //Paso cuatro: generar informe con el listado de los vuelos en los que no viajan clientes de la operadora
    printf("Generando informe...\n");
    
    mostrarlistaP(vectorPasajeros);
   // mostrarlista(primero);
    
    free(primero);
    free(vectorVuelos);
    free(vectorPasajeros);
    
    
    
    return (EXIT_SUCCESS);
}

