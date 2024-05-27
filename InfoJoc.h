#ifndef INFO_JOC_H
#define INFO_JOC_H

typedef enum
{
    MOVIMENT_ESQUERRA = 0,
    MOVIMENT_DRETA = 1,
    MOVIMENT_GIR_HORARI = 2,
    MOVIMENT_GIR_ANTI_HORARI = 3,
    MOVIMENT_BAIXA = 4,
    MOVIMENT_BAIXA_FINAL = 5,
} TipusMoviment;

typedef enum
{
    TECLA_ESQUERRA,
    TECLA_DRETA,
    TECLA_AMUNT,
    TECLA_ABAIX,
    TECLA_ESPAI,
    TECLA_ESCAPE,
    NO_TECLA
} TipusTecla;

const int N_TIPUS_FIGURES = 7;

typedef enum
{
    COLOR_NEGRE = 0,
    COLOR_GROC,
    COLOR_BLAUCEL,
    COLOR_MAGENTA,
    COLOR_TARONJA,
    COLOR_BLAUFOSC,
    COLOR_VERMELL,
    COLOR_VERD,
    NO_COLOR
} ColorFigura;

typedef enum
{
    NO_FIGURA = 0,
    FIGURA_O,
    FIGURA_I,
    FIGURA_T,
    FIGURA_L,
    FIGURA_J,
    FIGURA_Z,
    FIGURA_S
} TipusFigura;

typedef enum
{
    MODE_NORMAL = 0,
    MODE_TEST

} ModeJoc;

// Tamany de la pantalla gràfica
const int SCREEN_SIZE_X = 600;
const int SCREEN_SIZE_Y = 700;

// Mida dels quadrats que formen el tauler
const int MIDA_QUADRAT = 26;

// Tamany del tauler
const int N_FILES_TAULER = 21;
const int N_COL_TAULER = 11;

// Posició del tauler a la pantalla
const int POS_X_TAULER = 120;
const int POS_Y_TAULER = 100;

//necessari per generacio espontania de figures
const int N_FIGURES = 7;

//Coord de missatges de joc
const int POS_X_PUNTUACIO = 120;
const int POS_Y_PUNTUACIO = 50;
const int POS_X_NIVELL = 300;
const int POS_Y_NIVELL = 50;
const int POS_X_FINAL = 120;
const int POS_Y_FINAL = 300;

//sistema de puntuacio
const int PUNTS_FIGURA = 10;
const int PUNTS_FILA = 100;
const int PUNTS_DOBLE_FILA = 150;
const int PUNTS_TRIPLE_FILA = 175;
const int PUNTS_TETRIS = 200;
const int CANVI_NIVELL = 1500;
const int CANVI_VELOCITAT = 0.5;

#endif