#ifndef TETRIS_H
#define TETRIS_H

#include <iostream>
#include "Partida.h"
#include <list>

using namespace std;

//Definicio necesaria per poder incloure la llibreria i que trobi el main
#define SDL_MAIN_HANDLED
#include <windows.h>
//Llibreria grafica
#include "../Graphic Lib/libreria.h"

typedef struct
{
	string nom;
	int punts;

}Puntuacio;

class Tetris
{
public:
private:
	Partida m_partida;
	list<Puntuacio> m_puntuacions;
};
#endif


