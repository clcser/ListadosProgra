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
