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
elemento *dni;
elementoVuelo *vectorVuelos;
elementoPasajero *vectorPasajeros;
elementoPasajero *auxPasajeros;
elementoVuelo *auxVuelos;

int numVuelos = 0;
int primero = 0;
char* nombre_fichero = "eurocontrol.txt";
char* fichero_operadora = "operadora.txt";
char aerolinea[50];

int main(int argc, char** argv) {

    //Paso uno: leer fichero de Eurocontrol
    vectorVuelos = tratarfichero(nombre_fichero, 144);
    mostrarlistaVuelo(vectorVuelos);
    //Paso dos: leer fichero de la operadora web
    printf("Leyendo fichero de operadora...\n");
    vectorPasajeros = tratarficheroP(fichero_operadora,99);
    //Paso tres: volcar en la estructura de datos creada los datos de cada fichero
    //Vamos recorriendo el vector de vuelos, obtenemos la aerolinea y la buscamos
    //en el fichero de pasajeros.
    //Por cada ocurrencia, obtenemos el DNI y lo metemos en el vector de DNI's
    //Al finalizar la busqueda de cada ocurrencia, apuntamos a ese vector de DNI's y
    //Volvemos a realizar la misma búsqueda hasta que no queden elementos en el vector Vuelos
    dni=(elemento*) malloc(sizeof(elemento));
    auxPasajeros=(elementoPasajero*) malloc(sizeof(elementoPasajero));
    auxVuelos=(elementoVuelo*) malloc(sizeof(elementoVuelo));
    auxVuelos = vectorVuelos;
    auxPasajeros = vectorPasajeros;
    printf("La direccion de memoria de *auxVuelos es: %p\n",auxVuelos);
    printf("La direccion de memoria de *vectorVuelos es: %p\n",vectorVuelos);
    printf("Componiendo estructura...\n");
    while (auxVuelos != NULL){
        strncpy(aerolinea,auxVuelos->aerolinea,50);
        printf("Buscando aerolina: %s...\n",aerolinea);
        //Buscamos los DNI's que tenga esa aerolinea
        while (auxPasajeros != NULL){
            printf("Aerolina del fichero de pasajeros: %s\n",auxPasajeros->aerolinea);
            if (strcmp(auxPasajeros->aerolinea,aerolinea)==0){
                printf("Encontrado DNI: %s\n", auxPasajeros->dni);
                if (primero != 0){
                    dni=inserta(dni,auxPasajeros->dni);
                    primero++;
                } else {
                    dni=inserta_vacia(auxPasajeros->dni);
                }
            }
            auxPasajeros=auxPasajeros->siguiente;
        }
        //Ahora metemos el DNI dentro de la estructura del vuelo
        auxVuelos->listadoDNI=dni;
        auxVuelos=auxVuelos->siguiente;
        
    }
    
    //Ya tenemos todo, ahora hay que ir generando los informes pertinentes
    //Paso cuatro: generar informe con el listado de los vuelos en los que no viajan clientes de la operadora
    printf("Generando informe...\n");
    
    //mostrarlistaP(vectorPasajeros);
    mostrarlistaVuelo(vectorVuelos);
    //mostrarlista(dni);
    free(auxPasajeros);
    free(auxVuelos);
    free(dni);
    free(vectorVuelos);
    free(vectorPasajeros);
    
    
    
    return (EXIT_SUCCESS);
}

