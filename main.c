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
int insertado = 0;
int primero = 0;
int numclientes = 0;
int maxnumClientes = 0;
char* nombre_fichero = "eurocontrol.txt";
char* fichero_operadora = "operadora.txt";
char* fichero_informe = "informe.txt";
char aerolinea[50];
char aerolineaMax[50];

FILE *informe;

int main(int argc, char** argv) {
    //Nuesta operadora es UCAAVILA.
    //Paso uno: leer fichero de Eurocontrol
    printf("Leyendo fichero de Eurocontrol...\n");
    vectorVuelos = tratarfichero(nombre_fichero, 144);
    printf("Lectura correcta...\n");
   //mostrarlistaVuelo(vectorVuelos);
    //Paso dos: leer fichero de la operadora web
    printf("Leyendo fichero de operadora...\n");
    vectorPasajeros = tratarficheroP(fichero_operadora,99);
    printf("Lectura correcta...\n");
    //Paso tres: volcar en la estructura de datos creada los datos de cada fichero
    //Vamos recorriendo el vector de vuelos, obtenemos la aerolinea y la buscamos
    //en el fichero de pasajeros.
    //Por cada ocurrencia, obtenemos el DNI y lo metemos en el vector de DNI's
    //Al finalizar la busqueda de cada ocurrencia, apuntamos a ese vector de DNI's y
    //Volvemos a realizar la misma búsqueda hasta que no queden elementos en el vector Vuelos
    
    auxPasajeros=(elementoPasajero*) malloc(sizeof(elementoPasajero));
    auxVuelos=(elementoVuelo*) malloc(sizeof(elementoVuelo));
    auxVuelos = vectorVuelos;
    
    printf("Componiendo estructura...\n");
    
    while (auxVuelos != NULL){
        dni=(elemento*) malloc(sizeof(elemento));
        insertado = 0;
        primero = 0;
        numclientes = 0;
        auxPasajeros = vectorPasajeros;
        strncpy(aerolinea,auxVuelos->aerolinea,50);
        //printf("Buscando aerolina: %s...\n",aerolinea);
        //Buscamos los DNI's que tenga esa aerolinea
        while (auxPasajeros != NULL){
            //printf("Aerolina del fichero de pasajeros: %s\n",auxPasajeros->aerolinea);
            if (strcmp(auxPasajeros->aerolinea,aerolinea)==0){
                //printf("Encontrado DNI: %s\n", auxPasajeros->dni);
                if (primero != 0){
                    dni=inserta(dni,auxPasajeros->dni);
                    numclientes++;
                    
                } else {
                    primero++;
                    insertado = 1;
                    dni=inserta_vacia(auxPasajeros->dni);
                    numclientes++;
                }
            }
            auxPasajeros=auxPasajeros->siguiente;
        }
        //Ahora metemos el DNI dentro de la estructura del vuelo siempre que haya alguno, claro
        if (insertado == 1){
            if (numclientes > maxnumClientes){
                strncpy(aerolineaMax, aerolinea, 50);
                maxnumClientes = numclientes;
            }
            //mostrarlista(dni);
            auxVuelos->listadoDNI=dni;
        }
        auxVuelos=auxVuelos->siguiente;
        
    }
    printf("Estructura correcta...\n");
    //Ya tenemos todo, ahora hay que ir generando los informes pertinentes
    //Paso cuatro: generar informe con el listado de los vuelos en los que no viajan clientes de la operadora
    printf("***************************\n");
    printf("Generando informe...\n");
    
    if ((informe = fopen(fichero_informe,"at")) == NULL){
        printf("No se pudo abrir el fichero de informes %s. Operación abortada.\n", fichero_informe);
        exit(1);
    } else {
        fprintf(informe,"**** Informe Generado ****:\n");
        fprintf(informe,"Listado de vuelos sin clientes de nuestra operadora UCAVILA:\n");
        elementoVuelo *aux=(elementoVuelo*) malloc(sizeof(elementoVuelo));
        aux = vectorVuelos;
        while (aux != NULL){
            if (aux->listadoDNI == NULL){
                fprintf(informe,"##idVuelo:%s\n", aux->idVuelo);
                fprintf(informe,"##operadora:%s\n", aux->operadora);
                fprintf(informe,"##aerolinea:%s\n", aux->aerolinea);
                fprintf(informe,"##tipoAvion:%s\n", aux->tipoAvion);
                fprintf(informe,"##numPasajeros:%i\n", aux->numPasajeros);
                fprintf(informe,"*#####*\n");
            } 
            aux=aux->siguiente;
        }
        fprintf(informe,"***************************\n");
        fprintf(informe,"Nombre de la Aerolinea con más clientes:%s con %i clientes en total.\n", aerolineaMax,maxnumClientes);
        //mostrarlistaP(vectorPasajeros);
        //mostrarlistaVuelo(vectorVuelos);
        fprintf(informe,"***************************\n");
    
   
        fprintf(informe,"DNI's más usados:\n");
    
        elementoVuelo *auxDNI=(elementoVuelo*) malloc(sizeof(elementoVuelo));
        auxDNI = vectorVuelos;
        while (auxDNI != NULL){

            if (auxDNI->listadoDNI != NULL){
                listarDNI(informe,auxDNI->listadoDNI);
            } 
            auxDNI=auxDNI->siguiente;

        }
        //mostrarlista(dni);
        //listarDNI(dni);
        printf("Informe generado correctamente...\n");

        free(auxPasajeros);
        free(auxVuelos);
        free(aux);
        free(auxDNI);
        free(dni);
        free(vectorVuelos);
        free(vectorPasajeros);
        
        fclose(informe);
    
    }    
    
    return (EXIT_SUCCESS);
}

