#include "Tetris.h"
#include <fstream>
#include <iostream>

using namespace std;

#include <Windows.h>
#include "../Graphic Lib/libreria.h"
#include "../Graphic Lib/NFont/NFont.h"

Tetris::Tetris(const string& fitxerPuntuacions)
{
	ifstream fitxer;
	fitxer.open(fitxerPuntuacions);
	if (fitxer.is_open())
	{
		Puntuacio player;
		fitxer >> player.nom >> player.punts;
		while (!fitxer.eof())
		{
			m_puntuacions.push_back(player);
			fitxer >> player.nom >> player.punts;
		}
		fitxer.close();
	}
}
int Tetris::juga(Screen& pantalla, ModeJoc mode, const string& nomFitxerInicial, const string& nomFitxerFigures, const string& nomFitxerMoviments)
{
	pantalla.show();

	m_partida = Partida();

	m_partida.setMode(mode);

	m_partida.incialitza("./data/Games/partida.txt", "./data/Games/figures.txt", "./data/Games/moviments.txt");

	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;
	double deltaTime = 0;


	do
	{
		LAST = NOW;
		NOW = SDL_GetPerformanceCounter();
		deltaTime = (double)((NOW - LAST) / (double)SDL_GetPerformanceFrequency());

		// Captura tots els events de ratolí i teclat de l'ultim cicle
		pantalla.processEvents();

		m_partida.actualitza(deltaTime);

		//Actualitza la pantalla
		pantalla.update();

	} while (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE));
	// Sortim del bucle si pressionem ESC
	int punts = m_partida.getPunts();
	//Instruccio necesaria per alliberar els recursos de la llibreria 

	return punts;
}
void Tetris::actualitzaPunts(const string& nom, int punts)
{
	Puntuacio player;
	player.nom = nom;
	player.punts = punts;
	list<Puntuacio>::iterator it = m_puntuacions.begin();
	bool trobat = false;

	if (!m_puntuacions.empty())
	{
		while (!trobat && (it != m_puntuacions.end()))
		{
			if (it->punts < punts)
			{
				m_puntuacions.insert(it, player);
				trobat = true;
			}
			else
			{
				it++;
			}
		}
		if (m_puntuacions.size() == 11)
		{
			m_puntuacions.pop_back();
		}
	}
	if (m_puntuacions.size() < 10 && !trobat)
	{
		m_puntuacions.push_back(player);
	}
}
void Tetris::visualitzaPunts()
{
	list<Puntuacio>::iterator it = m_puntuacions.begin();
	int posicio = 1;
	cout << endl;
	cout << "=========================" << endl;
	cout << "  TAULER DE PUNTUACIONS" << endl;
	cout << "=========================" << endl;
	while(it!=m_puntuacions.end())
	{
		cout << posicio << ".- " << it->nom << " --> " << it->punts << endl;
		posicio++;
		it++;
	}
	cout << endl;
}
void Tetris::guardaPunts(const string& nomFitxer)
{
	ofstream fitxer;
	fitxer.open(nomFitxer);
	list<Puntuacio>::iterator it = m_puntuacions.begin();
	while (it != m_puntuacions.end())
	{
		fitxer << it->nom << " " << it->punts << endl;
		it++;
	}
	fitxer.close();
}
