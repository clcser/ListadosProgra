#include <stdlib.h>
#include <string.h>
#include <time.h>

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

//////////////////////// AQUI EMPIEZA ESTA PREGUNTA ///////////////////////////

void ordenarDB(struct Equipo *eq) {
    // ordenar equipo
    int i = 0;
    char menor = eq[0]->nombre[0];
    while(eq[i]->nombre[0] != "\0") {
        if(eq[i] < menor) { // ver si esto funciona, si es que hay que usar punteros
            char aux = eq[i];
            eq[i] = menor;
            menor = aux;
        }
        else if(eq[i]->)
        i++
    }
    i = 0;
    // ordenar jugadores
    // ordenar fanaticos
    double minAgresividad = 101;
    while(eq[i] != "\0") {
        if(eq[i]->fanatico->agresividad <= minAgresividad) {
            double aux = eq[i]->fanatico->agresividad;
            eq[i]->fanatico->agresividad = 
        }
    }
    // ordenar staff


}
