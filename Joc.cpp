#include <iostream>
#include "Figura.h"
#include "Joc.h" 
#include "Tauler.h"
#include <fstream>
#include "GraphicManager.h"

//#include "windows.h"

using namespace std;

//EXTRA
/*void Joc::capcelera()
{
	system("Color 0a");
	cout << "     ============================================================================" << endl;
	Sleep(500);
	cout << "\n";
	Sleep(500);
	cout << "       TTTTTTTTTTT   EEEEEEEEEEE   TTTTTTTTTTT   RRRRRRRRRR    III     SSSSSSS   " << endl;
	Sleep(500);
	cout << "       TTTTTTTTTTT   EEEEEEEEEEE   TTTTTTTTTTT   RR      RRR   III   SSS    SSS  " << endl;
	Sleep(500);
	cout << "           TTT       EEE               TTT       RR      RRR         SS          " << endl;
	Sleep(500);
	cout << "           TTT       EEEEEEE           TTT       RR      RR    III   SSS         " << endl;
	Sleep(500);
	cout << "           TTT       EEEEEEE           TTT       RR   RRR      III    SSSSSSSS   " << endl;
	Sleep(500);
	cout << "           TTT       EEE               TTT       RR    RR      III           SSS " << endl;
	Sleep(500);
	cout << "           TTT       EEEEEEEEEEE       TTT       RR     RR     III    SSS     SS " << endl;
	Sleep(500);
	cout << "           TTT       EEEEEEEEEEE       TTT       RR      RR    III     SSSSSSSS  " << endl;
	Sleep(500);
	cout << "\n";
	Sleep(500);
	cout << "     ============================================================================" << endl;
	Sleep(500);
	cout << "                    Diana del Mar Ruiz Veloza i Axel Povedano Gonzalez             " << endl;
	Sleep(1500);
	system("cls");
	system("Color 0f");

}*/

//interaccio amb tauler
void Joc::inicialitza(const string& nomFitxer)
{
	if (nomFitxer != "")//CONCEPTUAL-->en caso de recibir nombre vacio (se ha de codificar desde clase partida) no leeara nada y se empezara de 0
	{
		ifstream fitxer;

		fitxer.open(nomFitxer);

		if (fitxer.is_open())
		{

			ifstream fitxer;
			TipusFigura tipus;
			ColorFigura color, casillas;
			int casillas_int;

			fitxer.open(nomFitxer);

			if (fitxer.is_open())
			{
				int tipus_int, fila, columna, gir;

				//asignaació dels 4 primers valors corresponents a la figura inicial
				fitxer >> tipus_int >> fila >> columna >> gir;

				tipus = TipusFigura(tipus_int);
				color = ColorFigura(tipus_int);

				//omplim figura
				m_figura.setPosF(fila);
				m_figura.setPosC(columna);
				m_figura.incialitzaFigura(tipus, color);
				m_figura.setColocada(false);
				//ampliquem gir de la figura
				for (int i = 0; i < gir % 4; i++)
				{
					m_figura.turnHorari();
				}

				//escribim tauler (sense la figura)
				for (int f = 0; f < MAX_FILA; f++)
				{
					for (int c = 0; c < MAX_COL; c++)
					{
						fitxer >> casillas_int;
						casillas = ColorFigura(casillas_int);
						m_tauler.setTauler(f, c, casillas);
					}
				}
				fitxer.close();
			}
		}
	}

}
void Joc::escriuTauler(const string& nomFitxer)
{
	bool colisiona = true;

	ofstream fitxer;

	fitxer.open(nomFitxer);

	if (!m_figura.getColocada())
	{
		m_tauler.desaFigura(colisiona, m_figura);
		m_figura.setColocada(true);
	}

	if (fitxer.is_open())
	{
		for (int f = 0; f < MAX_FILA; f++)
		{
			for (int c = 0; c < MAX_COL; c++)
			{
				fitxer << m_tauler.getTauler(f, c);
			}
		}
	}
	fitxer.close();
}

//moviments
bool Joc::giraFigura(DireccioGir direccio)
{
	bool xoc = false;

	if (direccio == GIR_HORARI)
	{
		xoc = m_tauler.provocaXoc(m_figura, 2);
	}
	else
	{
		xoc = m_tauler.provocaXoc(m_figura, -2);
	}

	return xoc;
}
bool Joc::mouFigura(int dirX)
{
	bool ocupada = false;

	ocupada = m_tauler.provocaXoc(m_figura, dirX);

	return ocupada;
}
int Joc::baixaFigura()
{
	int files_completades = 0;
	bool colisiona;

	//1er comprovar q moviment es valid
	colisiona = m_tauler.colisiona(m_figura);

	//2n desar el moviment si la figura colisiona
	m_tauler.desaFigura(colisiona, m_figura);

	//3er comprovar si es completa una fila y eliminarla
	files_completades = m_tauler.eliminaFila();

	return files_completades;
}
int Joc::baixaComplet()
{
	int files_completades = 0;
	bool arriba_fons;

	//1er comprovar q arriba al fons del tauler
	arriba_fons = m_tauler.baixaComplet(m_figura);

	//2n desar el moviment si la figura colisiona
	m_tauler.desaFigura(arriba_fons, m_figura);

	//3er comprovar si es completa una fila y eliminarla
	files_completades = m_tauler.eliminaFila();

	return files_completades;
}

//partida
void Joc::actualitza(double deltaTime)
{
	GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
	GraphicManager::getInstance()->drawSprite(GRAFIC_TAULER, POS_X_TAULER, POS_Y_TAULER, false);
	if (Keyboard_GetKeyTrg(KEYBOARD_RIGHT))
		if (m_figura.getPosC() < N_COL_TAULER)
			m_figura.movRight();
	GraphicManager::getInstance()->drawSprite(GRAFIC_QUADRAT_GROC, POS_X_TAULER + (m_figura.getPosC() * MIDA_QUADRAT),
		POS_Y_TAULER + ((m_figura.getPosF() - 1) * MIDA_QUADRAT), false);
}

//SEGONA PART GRAFICA

void Joc::dibuixa()
{
	m_tauler.dibuixa(m_figura);
}