/*
Claudia Cser
Creditos a mi compañero, Jorge Santis

Escriba una función llamada ordenarDB que reciba un puntero a un vector de Equipos y ordene la información según
los siguientes criterios:

    El vector general de equipos se deberá ordenar ascendentemente de acuerdo al nombre de los equipos, en orden
    alfabético.
    Para cada equipo, su lista de jugadores se deberá ordenar ascendentemente, primero considerando la posición 
    y, como segundo criterio, el nombre.
    Para cada equipo, su lista de fanáticos se deberá ordenar ascendentemente, primero en función a la 
    agresividad y luego en función al nombre.
    Para cada equipo, su lista de personal del staff se deberá ordenar ascendentemente, primero en función al 
    rol y luego en función al nombre.
*/


#ifndef P3_H
#define P3_H

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "p2.h"

void cambioEquipos(Equipo *equipos1, Equipo *equipos2){ // funcion para intercambiar la posicion de dos equipos dentro de un vector de equipos (equivalente a un swap)
	Equipo *aux = malloc(sizeof(Equipo)); //variable auxiliar para almacenar un equipo mientras se intercambian
	*aux = *equipos1;
	*equipos1 = *equipos2;
	*equipos2 = *aux;
	free(aux); // liberar la variable auxiliar
}

void cambioJugadores(Jugador *jugador1, Jugador *jugador2){ // intercambia la posicion de dos jugadores dentro de un vector de jugadores. Analoga a la anterior.
	Jugador *aux = malloc(sizeof(Jugador));
	*aux = *jugador1;
	*jugador1 = *jugador2;
	*jugador2 = *aux;
	free(aux);
}

void cambioFanaticos(Fanatico *fanatico1, Fanatico *fanatico2){ // intercambia la posicion de dos fanaticos dentro de un vector de fanaticos. Analoga a la anterior.
	Fanatico *aux = malloc(sizeof(Fanatico));
	*aux = *fanatico1;
	*fanatico1 = *fanatico2;
	*fanatico2 = *aux;
	free(aux);
}

void cambioStaff(Staff *staff1, Staff *staff2){ // intercambia la posicion de dos staff dentro de un vector de staff. Analoga a la anterior.
	Staff *aux = malloc(sizeof(Staff));
	*aux = *staff1;
	*staff1 = *staff2;
	*staff2 = *aux;
	free(aux);
}

void ordenarDB(Equipo *equipos, int numEquipos){
	for (int i = 0; i < numEquipos; ++i){ // recorre todos los equipos
		for (int j = i+1; j < numEquipos; ++j){ // recorre desde el equipo seleccionado+1 en adelante
			int nomMayor = (strlen(equipos[i].nombre) > strlen(equipos[j].nombre)) ? strlen(equipos[j].nombre) : strlen(equipos[i].nombre); // guarda la longitud del nombre de equipo mas corto
			for (int k = 0; k <= nomMayor ; ++k){ 
				if(k==nomMayor){ // si llega a la ultima letra de la palabra mas corta
					if(strlen(equipos[i].nombre) > strlen(equipos[j].nombre)){ // si la palabra que esta primero(en orden del arreglo) es mas larga, las intercambia
						cambioEquipos(&equipos[i], &equipos[j]);
						break;
					}
				}else if(equipos[i].nombre[k] > equipos[j].nombre[k]){ // si la letra en posicion k de la primera palabra es mayor(en orden alfabetico) que la letra en posicion k de la segunda palabra, las intercambia 
					cambioEquipos(&equipos[i], &equipos[j]);
					break;
				}else if(equipos[i].nombre[k] < equipos[j].nombre[k]){ // si la letra en posicion k es menor en la primera palabra, estan ordenadas y pasa a la siguiente palabra 
					break;
				}
			}
		}
	}
	for (int i = 0; i < numEquipos; ++i){ // recorre los equipos
		int totalJugadores = equipos[i].numJugadores[0]+equipos[i].numJugadores[1]+equipos[i].numJugadores[2]+equipos[i].numJugadores[3];
		int posiciones[totalJugadores];
		for (int j = 0; j < totalJugadores; ++j){ // recorre todos los jugadores 
			posiciones[j] = equipos[i].jugadores[j].posicion; // llena el arreglo con las posiciones correspondientes al orden de los jugadores
		}
		for (int j = 0; j < totalJugadores; ++j){ // recorre los jugadores
			for(int k = j; k < totalJugadores; ++k){ // recorre desde el jugador seleccionado en adelante
				if(posiciones[j] > posiciones[k]){ // si la posicion seleccionada es mayor a cualquiera de las siguientes, las intercambia
					cambioJugadores(&equipos[i].jugadores[j], &equipos[i].jugadores[k]);
					int aux = posiciones[j];
					posiciones[j] = posiciones[k];
					posiciones[k] = aux;
				}
			}
		}for (int j = 0; j < totalJugadores; ++j){ // recorre los jugadores
			for (int l = j; l < totalJugadores ; ++l){ // recore desde el jugador seleccionado en adelante
				if(posiciones[j]!=posiciones[l]) break; // si los jugadores no son de la misma posicion, pasa al siguiente
				int nomMayor = (strlen(equipos[i].jugadores[l].nombre) > strlen(equipos[i].jugadores[j].nombre)) ? strlen(equipos[i].jugadores[j].nombre) : strlen(equipos[i].jugadores[l].nombre); // guarda la longitud del nombre mas corto
				for (int k = 0; k <= nomMayor; ++k){ // recorre los nombres
					if(k==nomMayor){ // si llega a la ultima letra
						if(strlen(equipos[i].jugadores[j].nombre) > strlen(equipos[i].jugadores[l].nombre)){ //si no estan en orden alfabetico los intercambia
							cambioJugadores(&equipos[i].jugadores[l], &equipos[i].jugadores[j]);
							break;
						}
					}else if(equipos[i].jugadores[j].nombre[k] > equipos[i].jugadores[l].nombre[k]){ // si no entan en orden alfabetico los intercambia
						cambioJugadores(&equipos[i].jugadores[j], &equipos[i].jugadores[l]);
						break;
					}else if(equipos[i].jugadores[j].nombre[k] < equipos[i].jugadores[l].nombre[k]){ // si estan en orden alfabetico pasa a la siguiente palabra
						break;
					}
				}
			}
		}
	}

	for (int i = 0; i < numEquipos; ++i){ // recorre los equipos
		int totalFanaticos = equipos[i].numFanaticos; 
		for (int j = 0; j < totalFanaticos; ++j){ // recorre los fanaticos
			for(int k = j; k < totalFanaticos; ++k){ // recorre desde el fanatico seleccionado
				if(equipos[i].fanaticos[j].agresividad > equipos[i].fanaticos[k].agresividad){ // ordena los fanaticos por agresividad
					cambioFanaticos(&equipos[i].fanaticos[j], &equipos[i].fanaticos[k]);
				}
			}
		}for (int j = 0; j < totalFanaticos; ++j){ // recorre los fanaticos
			for (int l = j; l < totalFanaticos ; ++l){
				if(equipos[i].fanaticos[j].nombre != equipos[i].fanaticos[l].nombre) break; // si los fanaticos tienen distinto nombre pasa al siguiente
				int nomMayor = (strlen(equipos[i].fanaticos[j].nombre) > strlen(equipos[i].fanaticos[l].nombre)) ? strlen(equipos[i].fanaticos[l].nombre) : strlen(equipos[i].fanaticos[j].nombre); // guarda el largo del nombre mas corto
				for (int k = 0; k <= nomMayor; ++k){ // recorre los nombres
					if(k==nomMayor){ // si llega al final de un nombre 
						if(strlen(equipos[i].fanaticos[j].nombre) > strlen(equipos[i].fanaticos[l].nombre)){ // los ordena si no estan ordenados alfabeticamente
							cambioFanaticos(&equipos[i].fanaticos[j], &equipos[i].fanaticos[l]);
							break;
						}
					}else if(equipos[i].fanaticos[j].nombre[k] > equipos[i].fanaticos[l].nombre[k]){ // si no estan ordenados, los ordena
						cambioFanaticos(&equipos[i].fanaticos[j], &equipos[i].fanaticos[l]);
						break;
					}else if(equipos[i].fanaticos[j].nombre[k] < equipos[i].fanaticos[l].nombre[k]){ // si estan ordenados pasa al siguiente
						break;
					}
				}
			}
		}
	}
	for (int i = 0; i < numEquipos; ++i){ // recorre los equipos
		int totalStaff = equipos[i].numStaff[0]+equipos[i].numStaff[1]+equipos[i].numStaff[2]+equipos[i].numStaff[3]+equipos[i].numStaff[4]+equipos[i].numStaff[5];
		int posiciones[totalStaff];
		for (int j = 0; j < totalStaff; ++j){ // recorre el staff
			posiciones[j] = equipos[i].staff[j].rol; // guarda los roles de cada staff en orden
		}
		for (int j = 0; j < totalStaff; ++j){ // recorre el staff
			for(int k = j; k < totalStaff; ++k){ // recorre desde el elemento seleccionado al ultimo
                if(posiciones[j] > posiciones[k]){ // si las posiciones no estan en orden las intercambia
					cambioStaff(&equipos[i].staff[j], &equipos[i].staff[k]);
					int aux = posiciones[j];
					posiciones[j] = posiciones[k];
					posiciones[k] = aux;
				}
			}
		}for (int j = 0; j < totalStaff; ++j){ // recorre el staff y lo ordena alfabeticamente
			for (int l = j; l < totalStaff ; ++l){
				if(posiciones[j]!=posiciones[l]) break;
				int nomMayor = (strlen(equipos[i].staff[l].nombre) > strlen(equipos[i].staff[j].nombre)) ? strlen(equipos[i].staff[j].nombre) : strlen(equipos[i].staff[l].nombre);
				for (int k = 0; k <= nomMayor; ++k){
					if(k==nomMayor){
						if(strlen(equipos[i].staff[j].nombre) > strlen(equipos[i].staff[l].nombre)){
							cambioStaff(&equipos[i].staff[l], &equipos[i].staff[j]);
							break;
						}
					}else if(equipos[i].staff[j].nombre[k] > equipos[i].staff[l].nombre[k]){
						cambioStaff(&equipos[i].staff[j], &equipos[i].staff[l]);
						break;
					}else if(equipos[i].staff[j].nombre[k] < equipos[i].staff[l].nombre[k]){
						break;
					}
				}
			}
		}
	}
}
/*
int main(){
	srand(time(NULL));
	int numEquipos;
	printf("Indique la cantidad de equipos presentes:\n");
	scanf("%d", &numEquipos);
	Equipo *equipos = crearEquipos(numEquipos);
	printf("Equipos antes de los cambios:\n");
	imprimirEquipos(equipos, numEquipos);
	ordenarDB(equipos, numEquipos);
	printf("Equipos despues de los cabmios:\n");
	imprimirEquipos(equipos, numEquipos);
	return 0;
}
*/
#endif // P3_H
