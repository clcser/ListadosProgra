/*
Claudia cser
Solucion propia

P2: Escriba la implementación de las siguientes funciones en lenguaje C:

    crearFanaticos que recibe un número entero positivo y genera un vector dinámico conteniendo esa cantidad de 
    objetos de tipo Fanatico generados aleatoriamente.

    liberarFanaticos que recibe el puntero a un arreglo de Fanaticos y lo libera.

    crearStaff que recibe varios números enteros, indicando cuántos miembros del staff se desea y genera un 
    vector dinámico conteniendo esa cantidad de objetos de tipo Staff generados aleatoriamente.

    liberarStaff que recibe el puntero a un arreglo de tipo Staff y lo libera.

    crearJugadores que recibe varios números enteros, indicando cuántos jugadores de cada tipo se desea y genera
    un vector dinámico conteniendo esa cantidad de objetos de tipo Jugador generados aleatoriamente.

    liberarJugadores que recibe el puntero a un arreglo de tipo Jugador y lo libera.

    crearEquipos que recibe un número entero, indicando cuántos equipos desea y genera un vector dinámico 
    conteniendo esa cantidad de objetos de tipo Equipo generados aleatoriamente.

    liberarEquipos que recibe el puntero a un arreglo de tipo Equipo y su dimensión y lo libera.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// esto es de la pregunta anterior //

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
    srand(time(NULL));
    
    char *nombreAl;
    nombreAl = malloc(27);
      
    for (int i = 0; i < numFanaticos; i++) { 

        int size = 2 + rand() % 25;
        nombreAl[0] = 'A' + rand() % 25;
        for(int i = 1; i < size; i++)
            nombreAl[i] = 'a' + rand() % 25;
        nombreAl[size] = '\0';

        struct Fanatico *fan = &vec[i];

        strncpy(fan->nombre, nombreAl, 100);
        fan->edad = rand() % 100; // numero aleatorio entre 0 y 99
        fan->agresividad = rand() % 10000 / 100.0; // numero aleatorio entre 0 y 99
    }
    return vec;
}


// liberar fanatico
void liberarFanaticos(struct Fanatico *fans) {
    free(fans);
}


// crear vector de staff aleatorio
struct Staff *crearStaff(int numDT, int numPrepArq, int numPrepFis, int numAsis, int numFisio, int numDoc) {
    int staffTot = numDT + numPrepArq + numPrepFis + numAsis + numFisio + numDoc; // cantidad total de de staff
    int staffEsp[6] = {numDT, numPrepArq, numPrepFis, numAsis, numFisio, numDoc}; // cantidad especifica de staff
    
    struct Staff *vec = malloc(staffTot * sizeof(struct Staff));
    
    char *nombreAl;
    nombreAl = malloc(27);
    int cont = 0;
    
    for(int i = 0; i < staffTot; i++) {
        int size = 2 + rand() % 25;
        nombreAl[0] = 'A' + rand() % 25;
        for(int i = 1; i < size; i++)
            nombreAl[i] = 'a' + rand() % 25;
        nombreAl[size] = '\0';
    
        if(staffEsp[cont] > 0) {
           struct Staff *stf = &vec[i];
            strncpy(stf->nombre, nombreAl, 100);
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

    int cont = 0;
    char *nombreAl;
    nombreAl = malloc(27);
       
    for(int i = 0; i < jugTot; i++) {     
        int size = 2 + rand() % 25;
        nombreAl[0] = 'A' + rand() % 25;
        for(int i = 1; i < size; i++)
            nombreAl[i] = 'a' + rand() % 25;
        nombreAl[size] = '\0';

        if(jugEsp[cont] > 0) {
            struct Jugador *jug = &vec[i];
            strncpy(jug->nombre, nombreAl, 100);
            jug->edad = rand() % 30 + 12;
            jug->posicion = cont;
            jug->regate  = rand() % 10000 / 100.0;
            jug->defensa = rand() % 10000 / 100.0;
            jug->reflejos = rand() % 10000 / 100.0;
            jug->velocidad = rand() % 10000 / 100.0;
            jug->dureza = rand() % 10000 / 100.0;
            jug->resistencia = rand() % 10000 / 100.0;

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

    srand(time(NULL));
    for (int i = 0; i < numEquipos; i++) { 
        char *equipoAl;
        equipoAl = malloc(27);
    
        int size = 2 + rand() % 25;
        equipoAl[0] = 'A' + rand() % 25;
        for(int i = 1; i < size; i++)
            equipoAl[i] = 'a' + rand() % 25;
        equipoAl[size] = '\0';

        struct Equipo *eq = &vec[i];

        strncpy(eq->nombre, equipoAl, 100);
        eq->anyoFundacion = rand() % 123 + 1900; // año aleatorio entre 1900 y 2022
        
        for(int i = 0; i < 6; i++) {
            eq->numStaff[i] = rand() % 3 + 1; // numero aleatorio de cada tipo de staff entre 1 y 3
        }
        eq->staff = crearStaff(eq->numStaff[0], eq->numStaff[1], eq->numStaff[2], eq->numStaff[3], eq->numStaff[4], eq->numStaff[5]);
        
        for(int i = 0; i < 4; i++) {
            eq->numJugadores[i] = rand() % 4 + 2; // numero aleatorio de cada tipo de jugador entre 2 y 5
        }
        eq->jugadores = crearJugadores(eq->numJugadores[0], eq->numJugadores[1], eq->numJugadores[2], eq->numJugadores[3]);
        
        eq->numFanaticos = rand() % 50; // fanaticos aleatorios entre 0 y 50
        eq->fanaticos = crearFanaticos(eq->numFanaticos);
    }
    return vec;
}

// liberar equipos
void liberarEquipos(struct Equipo *equipos, int numEquipos) { 
    for(int i = 0; i < numEquipos; i++) {
        liberarStaff(equipos[i].staff);
        liberarFanaticos(equipos[i].fanaticos);
        liberarJugadores(equipos[i].jugadores);
    }
    free(equipos);
}

/*
int main() {
    int numEquipos;
    scanf("%d", &numEquipos);
    struct Equipo *equipo;
    
    equipo = crearEquipos(numEquipos);

    for(int i = 0; i < numEquipos; i++) {
        printf("Nombre: %s\n",equipo[i].nombre);
    }

    liberarEquipos(equipo, numEquipos);

    return 0;
}
*/
