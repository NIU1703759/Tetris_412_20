#include <iostream>
#include "Figura.h"
#include "Joc.h" 
#include "Tauler.h"
#include <fstream>
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

	//comprovacio xoc
	/*if (direccio == GIR_HORARI)
	{
		m_figura.turnHorari();
		if (m_tauler.dins(m_figura))
		{
			xoc = m_tauler.provocaXoc(m_figura);
			if (xoc)
			{
				m_figura.turnAntiHorari();
			}
		}
		else
		{
			xoc = true;
			m_figura.turnAntiHorari();
		}
	}
	if (direccio == GIR_ANTI_HORARI)
	{
		m_figura.turnAntiHorari();
		if (m_tauler.dins(m_figura))
		{
			xoc = m_tauler.provocaXoc(m_figura);
			if (xoc)
			{
				m_figura.turnHorari();
			}
		}
		else
		{
			xoc = true;
			m_figura.turnHorari();
		}
	}*/
	return xoc;
}
bool Joc::mouFigura(int dirX)
{
	bool ocupada = false;

	ocupada = m_tauler.provocaXoc(m_figura, dirX);
	/*if (dirX == 1)
	{
		m_figura.movRight();
		if (m_tauler.dins(m_figura))
		{
			ocupada = (m_tauler.provocaXoc(m_figura));
			if (ocupada)
			{
				m_figura.movLeft();
			}
		}
		else
		{
			ocupada = true;
			m_figura.movLeft();
		}
	}
	else
	{
		m_figura.movLeft();
		if (m_tauler.dins(m_figura))
		{
			ocupada = (m_tauler.provocaXoc(m_figura));
			if (ocupada)
			{
				m_figura.movRight();
			}
		}
		else
		{
			ocupada = true;
			m_figura.movRight();
		}
	}*/


	return ocupada;
}
int Joc::baixaFigura()//ultimos cambios
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
