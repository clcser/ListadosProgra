/*
Claudia Cser
solucion propia

Escriba una función llamada imprimiDB que reciba un puntero a un vector de Equipos e imprima toda la información
de los equipos por pantalla.
*/
#ifndef P4_H
#define P4_H

#include <stdio.h>
#include <stdlib.h>
#include "p3.h"

void imprimirFanaticos(struct Fanatico *fanatico, int *numFanaticos) {
    for(int i = 0; i < *numFanaticos; i++) {
        printf("-Nombre: %s\n", fanatico[i].nombre);
        printf("    -Edad: %d\n", fanatico[i].edad);
        printf("    -Agresividad: %.3f\n", fanatico[i].agresividad);
        printf("\n");
    }
    printf("\n");
}

void imprimirJugadores(struct Jugador *jugador, int *numJugadores) {
    for(int i = 0; i < 4; i++) {
        int numActual = numJugadores[i];
        for(int j = 0; j < numActual; j++) {
            printf("-Nombre: %s\n", jugador[j].nombre);
            printf("    -Edad: %d\n", jugador[j].edad);
            
            switch(i) {
                case 0:
                    printf("    -Posicion: Arquero\n");
                    break;
                case 1:
                    printf("    -Posicion: Defensor\n");
                    break;
                case 2:
                    printf("    -Posicion: Medio\n");
                    break;
                case 3:
                    printf("    -Posicion: Delantero\n");
                    break;
            }

            printf("    -Regate: %.3f \n", jugador[j].regate);
            printf("    -Defensa: %.3f \n", jugador[j].defensa);
            printf("    -Reflejos: %.3f \n", jugador[j].reflejos);
            printf("    -Velocidad: %.3f \n", jugador[j].velocidad);
            printf("    -Dureza: %.3f \n", jugador[j].dureza);
            printf("    -Resistencia: %.3f \n", jugador[j].resistencia);
            printf("\n");
        }
    }
    printf("\n");
}

void imprimirStaff(struct Staff *staff, int *numStaff) {
    for(int i = 0; i < 6; i++) {
        int numActual = numStaff[i];
        for(int j = 0; j < numActual; j++) {
            printf("-Nombre: %s\n", staff[j].nombre);
            printf("    -Edad: %d\n", staff[j].edad);
            
            switch(i) {
                case 0:
                    printf("    -Rol: DT\n");
                    break;
                case 1:
                    printf("    -Rol: Preparadr de arqueros\n");
                    break;
                case 2:
                    printf("    -Rol: Preparador fisico\n");
                    break;
                case 3:
                    printf("    -Rol: Asistente\n");
                    break;
                case 4:
                    printf("    -Rol: Fisioterapeuta\n");
                    break;
                case 5:
                    printf("    -Rol: Doctor\n");
                    break;
            }

            printf("    -Experiencia: %d/100\n", staff[j].experiencia);
            printf("\n");
        }
    }
    printf("\n");
}

void imprimirEquipo(struct Equipo *equipo) {
    printf("Nombre: %s\n\n", equipo->nombre);
    printf("Año de fundacion: %d\n\n", equipo->anyoFundacion);
    printf("STAFF:\n\n");
    imprimirStaff(equipo->staff, equipo->numStaff);
    printf("JUGADORES:\n\n");
    imprimirJugadores(equipo->jugadores, &equipo->numJugadores[0]);
    printf("FANATICOS:\n\n");
    imprimirFanaticos(equipo->fanaticos, &equipo->numFanaticos);
}

void imprimiDB(struct Equipo *equipo, int numEquipos) {
    for(int i = 0; i < numEquipos; i++) {
        printf("-------------------------Equipo n°%d-------------------------\n", i+1);
        imprimirEquipo(&equipo[i]);
    }
}

#endif //P4_H

/*

int main() {
    int numEquipos;
    struct Equipo *equipos;

    scanf("%d",&numEquipos);
    equipos = crearEquipos(numEquipos);

    imprimiDB(equipos, numEquipos);

    liberarEquipos(equipos, numEquipos);
    
    return 0;
}
*/
