/* 
 * File:   fichero.h
 * Author: daniellopezmesa
 *
 * Created on May 17, 2017, 12:48 PM
 */

#ifndef FICHERO_H
#define	FICHERO_H

#include <stdio.h>
#include "vuelo.h"

FILE* fichero;
char linea[144];


/*
 * Funcion que lee en un fichero y devuelve el numero de lineas
 */
int obtenerNumLineas(char* nombre_fichero, int buffer){
    int i = 0;
    //Al ser un fichero de texto lo abrimos con rt
    if ((fichero = fopen(nombre_fichero,"rt")) == NULL){
        printf("No se puedo abrir el fichero %s\n", nombre_fichero);
        exit(1);
    } else {
        
        //Vamos leyendo el archivo de texto sabiendo que en total hay 144 caracteres por línea
        //140 corresponden a datos y 4 corresponden al separador #
        
        while ( fgets(linea,buffer,fichero) != NULL) {
           //Procesamos la linea usando el delimitador para meterlo en cada parte de la estructura 
            i++;
        }
        fclose(fichero);
    }
    return i;
}

/*
 * Función que lee el fichero de Eurocontrol
 */
elementoVuelo* tratarfichero(char* nombre_fichero, int buffer){
    char *item;
    char token[6];
    elementoVuelo *primero,*insertar;
    primero = NULL;
    insertar =(elementoVuelo*) malloc(sizeof(elementoVuelo));
    int contador = 0;
    int lineaLeida=1;
    
    if ((fichero = fopen(nombre_fichero,"rt")) == NULL){
        printf("No se puedo abrir el fichero de Eurocontrol: %s\n", nombre_fichero);
        exit(1);
    } else {
        
        //Vamos leyendo el archivo de texto sabiendo que en total hay 144 caracteres por línea
        //140 corresponden a datos y 4 corresponden al separador #
        
        while ( fgets(linea,buffer,fichero) != NULL) {
           
            contador = 0;
                        
           //Procesamos la linea usando el delimitador para meterlo en cada parte de la estructura 
            item = strtok(linea,"#");
            strcpy(&token[0],item);
            strncpy(insertar->idVuelo,&token[0],30);
            contador++;
            
            while (item != NULL){
                item = strtok(NULL, "#");
                if (item != NULL){
                    
                    strcpy(&token[contador],item);
                    switch (contador){
                        case 1:
                            strncpy(insertar->operadora,&token[1],50);
                            break;
                        case 2:
                            strncpy(insertar->aerolinea,&token[2],50);
                            break;
                        case 3:
                            strncpy(insertar->tipoAvion,&token[3],10);
                            break;
                        case 4:
                            insertar->numPasajeros = atoi(&token[4]);
                            break;
                    }
                    contador++;
                }
                
            }
            
            //Llamamos a la insercion de la funcion de vuelos:
            if (lineaLeida == 1) {
                
                primero=inserta_vaciaV(insertar);
            } else {
               
                primero =insertaV(primero,insertar);
            }
            lineaLeida++;
        }
        fclose(fichero);
    }
    return primero;
}
#endif	/* FICHERO_H */

