/*
Claudia Cser
Solucion propia

Escriba un programa en C que reciba como parámetros 3 valores que correspondan al número de equipos, mı́nimo 
número de fanáticos y máximo número de fanáticos, respectivamente. El programa deberá generar una base de datos 
de equipos acorde a la entrada con una cantidad de fanáticos por equipo, comprendida entre el mı́nimo y el máximo
ingresados. Cada equipo deberá contener 22 jugadores: 3 arqueros, 6 defensas, 7 centrocampistas y 6 delanteros, 
ası́ como 8 componentes del staff: Un Director técnico, un preparador de arqueros, un preparador fı́sico, dos 
asistentes, dos fisioterapeutas y un doctor. El programa deberá imprimir la Base de datos en el orden 
originalmente generado y luego volver a imprimir la Base de datos, una vez ésta haya sido ordenada. 
*/ 

#include "p4.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Equipo *crearEquiposEsp(int numEquipos, int minFan, int maxFan) { 
    srand(time(NULL));
    struct Equipo *vec = malloc(numEquipos * sizeof(struct Equipo));
    int numFan = rand()%(maxFan-minFan+1) + minFan;

    for (int i = 0; i < numEquipos; i++) { 
        char *nombreAl;
        nombreAl = malloc(27);
    
        int size = 2 + rand() % 25;
        nombreAl[0] = 'A' + rand() % 25;
        for(int i = 1; i < size; i++)
            nombreAl[i] = 'a' + rand() % 25;
        nombreAl[size] = '\0';
        printf("\n****%s****\n", nombreAl);

        struct Equipo *eq = &vec[i];

        strncpy(eq->nombre, nombreAl, 100);
        eq->anyoFundacion = rand() % 123 + 1900; // año aleatorio entre 1900 y 2022
        
        eq->numStaff[0] = 1;
        eq->numStaff[1] = 1;
        eq->numStaff[2] = 1;
        eq->numStaff[3] = 2;
        eq->numStaff[4] = 2;
        eq->numStaff[5] = 1;

        eq->staff = crearStaff(1,1,1,2,2,1);
        
        eq->numJugadores[0] = 3;
        eq->numJugadores[1] = 6;
        eq->numJugadores[2] = 7;
        eq->numJugadores[3] = 6;

        eq->jugadores = crearJugadores(3,6,7,6);
        
        eq->numFanaticos = numFan;
        eq->fanaticos = crearFanaticos(numFan);
    }
    return vec;
}
int main() {
    int numEquipos, minFan, maxFan, numFan;
    struct Equipo *equipo;

    scanf("%d",&numEquipos);
    scanf("%d",&minFan);
    scanf("%d",&maxFan);

    equipo = crearEquiposEsp(numEquipos,minFan,maxFan);

    printf("EQUIPOS SIN ORDENAR:\n");
    imprimiDB(equipo,numEquipos);
    
    /*ordenarDB(equipo);

    printf("\nEquipos ordenados:\n");
    imprimiDB(equipo,numEquipos);
    */
    return 0;
}
