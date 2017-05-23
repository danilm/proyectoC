/* 
 * File:   fichero.h
 * Author: daniellopezmesa
 *
 * Created on May 17, 2017, 12:48 PM
 */

#include "pasajero.h"

FILE* ficheroPasajero;
char lineaPasajero[99];


/*
 * Funcion que lee en un fichero y devuelve el numero de lineas
 */
int obtenerNumLineasP(char* nombre_fichero, int buffer){
    int i = 0;
    //Al ser un fichero de texto lo abrimos con rt
    if ((ficheroPasajero = fopen(nombre_fichero,"rt")) == NULL){
        printf("No se puedo abrir el fichero %s\n", nombre_fichero);
        exit(1);
    } else {
        printf("Leyendo fichero...\n");
        //Vamos leyendo el archivo de texto sabiendo que en total hay 144 caracteres por línea
        //140 corresponden a datos y 4 corresponden al separador #
        
        while ( fgets(linea,buffer,ficheroPasajero) != NULL) {
           //Procesamos la linea usando el delimitador para meterlo en cada parte de la estructura 
            i++;
        }
        fclose(ficheroPasajero);
    }
    return i;
}

/*
 * Función que lee el fichero de Eurocontrol
 */
elementoPasajero* tratarficheroP(char* nombre_fichero, int buffer){
    char *itemp,*tokenp;
    elementoPasajero *primero,*insertarp;
    primero = NULL;
    insertarp =(elementoPasajero*) malloc(sizeof(elementoPasajero));
    int contador = 0;
    int lineaLeida=1;
    
    if ((ficheroPasajero = fopen(nombre_fichero,"rt")) == NULL){
        printf("No se puedo abrir el fichero %s\n", nombre_fichero);
        exit(1);
    } else {
        
        //Vamos leyendo el archivo de texto sabiendo que en total hay 99 caracteres por línea
              
        while ( fgets(lineaPasajero,buffer,ficheroPasajero) != NULL) {
          // printf("Leyendo línea %i del fichero de operadora:%s\n",lineaLeida,lineaPasajero);
            contador = 0;
                        
           //Procesamos la linea usando el delimitador para meterlo en cada parte de la estructura 
            itemp = strtok(lineaPasajero,"#");
            
            tokenp = (char *) malloc(100);
          //  printf("item:%s\n",itemp);
            strcpy(tokenp,itemp);
          //  printf("Contenido token %s...\n",tokenp);
            strcpy(insertarp->dni,tokenp);
            
            contador++;
            
            while (itemp != NULL){
                //printf("Leyendo campo %i del fichero de operadora %s...\n",contador,nombre_fichero);
                itemp = strtok(NULL, "#");
                
                if (itemp != NULL){
                    switch (contador){
                        case 1:
                          //  printf("Contenido campo %s...\n",itemp);
                            strcpy(tokenp,itemp);
                         //   printf("Contenido token %s...\n",tokenp);
                            strcpy(insertarp->nombre,tokenp);
                            break;
                        case 2:
                            strncpy(insertarp->aerolinea,itemp,50);
                            break;
                        case 3:
                            strncpy(insertarp->tipoAvion,itemp,10);
                            break;
                        
                    }
                    contador++;
                }
                
            }
            
            //Llamamos a la insercion de la funcion de pasajeros:
            if (lineaLeida == 1) {
                
                primero=inserta_vaciaP(insertarp);
            } else {
               
                primero =insertaP(primero,insertarp);
            }
            lineaLeida++;
        }
        fclose(ficheroPasajero);
    }
    return primero;
}


