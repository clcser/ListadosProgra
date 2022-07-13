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

// crear vector de fanaticos aleatorios
struct Fanatico *crearFanaticos(int numFanaticos) {
    struct Fanatico *vec = malloc(numFanaticos * sizeof(struct Fanatico));
    char *nombres[] = {
        "a",
        "b",
        "c",
        "d",
    };
    srand(time(NULL));

    for (int i = 0; i < numFanaticos; i++) { 
        int rnd = rand() % sizeof(nombres); // crea un numero aleatorio entre 0 y la cantidad de nombres
        struct Fanatico *fan = &vec[i];

        strncpy(fan->nombre, nombres[rnd], 100);
        fan->edad = rand() % 80 + 10; // numero aleatorio entre 10 y 89
        fan->agresividad = rand() % 100; // numero aleatorio entre 0 y 99
    }
    return vec;
}


// liberar fanatico
void liberarFanaticos(struct Fanatico *fans) {
    free(fans);
}


// crear vector de staff aleatorio
struct Staff* crearStaff(int numDT, int numPrepArq, int numPrepFis, int numAsis, int numFisio, int numDoc) {
    int staffTot = numDT + numPrepArq + numPrepFis + numAsis + numFisio + numDoc; // cantidad total de de staff
    int staffEsp[6] = {numDT, numPrepArq, numPrepFis, numAsis, numFisio, numDoc}; // cantidad especifica de staff
    
    struct Staff *vec = malloc(staffTot * sizeof(struct Staff));
    char *nombres[] = {
        "a",
        "b",
        "c",
        "d",
    };
    
    int cont = 0;
    for(int i = 0; i < staffTot; i++) {
        if(staffEsp[cont] > 0) {
            int rnd = rand() % sizeof(nombres);
            struct Staff *stf = &vec[i];

            strncpy(stf->nombre, nombres[rnd], 100);
            stf->edad = rand() % 40 + 20;
            stf->rol = cont;
            stf->experiencia = rand() % 100;
            
            staffEsp[cont]--;
        }
        else cont ++;
    }
    return vec;
}


// liberar staff
void liberarStaff(struct Staff* staff){
    free(staff);
}


// crear vector de jugadores aleatorios
struct Jugador *crearJugadores(int numArq, int numDef, int numCent, int numDel) {
    int jugTot = numArq + numDef + numCent + numDel;
    int jugEsp[4] = {numArq, numDef, numCent, numDel};

    struct Jugador *vec = malloc(jugTot * sizeof(struct Jugador));
    char *nombres[] = {
        "a",
        "b",
        "c",
        "d",
    };

    int cont = 0;
    for(int i = 0; i < jugTot; i++) {
        if(jugEsp[cont] > 0) {
            int rnd = rand() %sizeof(nombres);
            struct Jugador *jug = &vec[i];

            strncpy(jug->nombre, nombres[rnd], 100);
            jug->edad = rand() % 30 + 12;
            jug->posicion = cont;
            jug->regate  = rand() % 100;
            jug->defensa = rand() % 100;
            jug->reflejos = rand() % 100;
            jug->velocidad = rand() % 100;
            jug->dureza = rand() % 100;
            jug->resistencia = rand() % 100;

            jugEsp[cont]--;
        }
        else cont ++;
    }
    return vec;
}


// liberar jugadores
void liberarJugadores(struct Jugador *jugadores) {
    free(jugadores);
}


// crear vector de equipos aleatorios
struct Equipo *crearEquipos(int numEquipos) {
    struct Equipo *vec = malloc(numEquipos * sizeof(struct Equipo));
    char *nombres[] = {
        "a",
        "b",
        "c",
        "d",
    };
    srand(time(NULL));

    for (int i = 0; i < numEquipos; i++) { 
        int rnd = rand() % sizeof(nombres); // crea un numero aleatorio entre 0 y la cantidad de nombres
        struct Equipo *eq = &vec[i];

        strncpy(eq->nombre, nombres[rnd], 100);
        eq->anyoFundacion = rand() % 123 + 1900; // año aleatorio entre 1900 y 2022
        for(int i = 0; i < 6; i++) {
            eq->numStaff[i] = rand() % 2 + 1; // numero aleatorio de cada tipo de staff entre 1 y 3
        }
        eq->staff = crearStaff(eq->numStaff[0], eq->numStaff[1], eq->numStaff[2], eq->numStaff[3], eq->numStaff[4], eq->numStaff[5]);
        for(int i = 0; i < 4; i++) {
            eq->numJugadores[i] = rand() % 3 + 2; // numero aleatorio de cada tipo de jugador entre 2 y 5
        }
        eq->jugadores = crearJugadores(eq->numJugadores[0], eq->numJugadores[1], eq->numJugadores[2], eq->numJugadores[3]);
        eq->numFanaticos = rand() % 10000; // fanaticos aleatorios entre 0 y 10 mil
        eq->fanaticos = crearFanaticos(eq->numFanaticos);
    }
    return vec;
}

// liberar equipos
void liberarEquipos(struct Equipo *equipos, int numEquipos) { // REVISAR ESTO!
    free(equipos);
}


