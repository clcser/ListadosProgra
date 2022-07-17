/*
Claudia Cser
Solucion propia

Escriba la declaración, en lenguaje C, de las siguientes estructuras:

    Fanatico: Que contendrá los siguientes campos:
        nombre: Almacenado en una cadena de caracteres de tamaño máximo 100.
        edad: Almacenado en un número entero positivo de 1 Byte.
        agresividad: Almacenado en un número de coma flotante de precisión doble.
    Jugador: Que contendrá los siguientes campos:
        nombre: Almacenado en una cadena de caracteres de tamaño máximo 100.
        edad: Almacenado en un número entero positivo de 1 Byte.
        posicion: Una entre las siguientes opciones: Arquero, Defensor, Medio, Delantero.
        regate: Almacenado en un número de coma flotante de precisión simple.
        defensa: Almacenado en un número de coma flotante de precisión simple.
        reflejos: Almacenado en un número de coma flotante de precisión simple.
        velocidad: Almacenado en un número de coma flotante de precisión simple.
        dureza: Almacenado en un número de coma flotante de precisión simple.
        resistencia: Almacenado en un número de coma flotante de precisión simple.
    Staff: Que contendrá los siguientes campos:
        nombre: Almacenado en una cadena de caracteres de tamaño máximo 100.
        edad: Almacenado en un número entero positivo de 1 Byte.
        rol: Una entre las siguientes opciones: DT, Preparador Arqueros, Preparador Fisico, Asistente, Fisioterapeuta o Doctor.
        experiencia: Un número entero postivo de 1 Byte.
    Equipo: Que contendrá los siguientes campos:
        nombre: Almacenado en una cadena de caracteres de tamaño máximo 100.
        anyoFundacion: Almacenado en un número entero positivo de 4 Bytes.
        staff: Un puntero a un vector compuesto por estructuras del tipo Staff.
        numStaff: Un arreglo estático de 6 elementos que almacena la cantidad de DTs, Preparadores de Arqueros, Preparadores Fisicos, Asistentes, Fisioterapeutas y Doctores en el equipo.
        jugadores: Un puntero a un vector compuesto por estructuras del tipo Jugador.
        numJugadores: Un arreglo estático de 4 elementos que almacena la cantidad de Arqueros, Defensas, Centros y Delanteros que tiene el equipo.
        fanaticos: Un puntero a un vector compuesto por estructuras del tipo Fanatico.
        numFanaticos: Un entero que almacena el número de fanáticos del equipo.
*/
#ifndef P1_H
#define P_H 

#include <stdio.h>
#include <stdlib.h>

enum posicion {
    Arquero,
    Defensor,
    Medio,
    Delantero,
};

enum rol {
    DT,
    PreparadorArqueros,
    PreparadorFisico,
    Asistente,
    Fisioterapeuta,
    Doctor,
};

struct Fanatico {
    char nombre[100];
    unsigned char edad;
    double agresividad;
};

struct Jugador {
    char nombre[100];
    unsigned char edad;
    enum posicion posicion;
    float regate;
    float defensa;
    float reflejos;
    float velocidad;
    float dureza;
    float resistencia;
};

struct Staff {
    char nombre[100];
    unsigned char edad;
    enum rol rol;
    unsigned char experiencia;
};

struct Equipo {
    char nombre[100];
    unsigned int anyoFundacion;
    struct Staff *staff;
    int numStaff[6];
    struct Jugador *jugadores;
    int numJugadores[4];
    struct Fanatico *fanaticos;
    int numFanaticos;
};

#endif //P1_H

/*
int main() {
    struct Equipo equipo;

    scanf("%s", equipo.nombre);
    getchar();
    scanf("%u", &equipo.anyoFundacion);

    
    printf("Nombre: %s\n", equipo.nombre);
    printf("Año fundacion: %d\n", equipo.anyoFundacion);

    return 0;
}

*/
