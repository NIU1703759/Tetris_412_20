#ifndef PARTIDA_H
#define PARTIDA_H

#include <stdio.h>
#include <string>
#include "InfoJoc.h"
#include "Joc.h"
#include "Tauler.h"
#include "Figura.h"
#include "LlistaFigura.h"
#include "LlistaMoviment.h"

using namespace std;

class Partida
{
public:
    Partida();

    void incialitza(ModeJoc mode, const string& fitxerInicial, const string& fitxerFigures,
        const string& fitxerMoviments);

    void actualitza(double deltaTime);
    void actualitzaMov(double deltaTime);
    void actualitzaMovTest(double deltaTime);
    void actualitzaPuntuacio(int nFilesEliminades);

private:
    //atributs necessaris per a jugar
    double m_temps;
    double m_velocitat;

    //atributs visibles pel jugador
    ModeJoc m_mode;
    int m_punts;
    int m_nivell;

    //Atributs necessaris només pels exemples d'utilització de la llibreria. 
    // S'hauran d'eliminar per la implementació del projecte
    static const int MIDA = 4;
    ColorFigura m_forma[MIDA][MIDA];
    int m_fila, m_columna;

    //tauler i condicio de final
    Joc m_joc;
    bool m_finalPartida;

    //llistes dinamiques del mode test
    LlistaFigura m_llistaFigures;
    LlistaMoviment m_llistaMoviments;

};

#endif 
