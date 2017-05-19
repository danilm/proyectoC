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


/*
 * 
 */
elementoVuelo ficheroVuelo;
elemento *primero;
elementoVuelo *vectorVuelos;
int numVuelos=0;
char* nombre_fichero="eurocontrol.txt";
int main(int argc, char** argv) {

    //Paso uno: leer fichero de Eurocontrol
    vectorVuelos = tratarfichero(nombre_fichero, 144);
    //Paso dos: leer fichero de la operadora web
    printf("Leyendo fichero de operadora...\n");
    //Paso tres: volcar en la estructura de datos creada los datos de cada fichero
     
    //Paso cuatro: generar informe con el listado de los vuelos en los que no viajan clientes de la operadora
    printf("Generando informe...\n");
    mostrarlistaVuelo(vectorVuelos);
   // mostrarlista(primero);
    
    free(primero);
    free(vectorVuelos);
    
    
    
    return (EXIT_SUCCESS);
}

