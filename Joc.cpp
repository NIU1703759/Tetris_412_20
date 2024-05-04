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

//FUNCIONS
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
			m_figura.setGir(gir);
			m_figura.incialitzaFigura(tipus, color);

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


bool Joc::giraFigura(DireccioGir direccio)
{
	bool xoc = false;

	//comprovacio xoc
	if (direccio == GIR_HORARI)
	{
		m_figura.turnHorari();
	}
	if (direccio == GIR_ANTI_HORARI)
	{
		m_figura.turnAntiHorari();
	}

	xoc = m_tauler.girCorrecte(m_figura, direccio);

	if (xoc)
	{
		if (direccio == GIR_HORARI)
		{
			m_figura.turnAntiHorari();
		}
		if (direccio == GIR_ANTI_HORARI)
		{
			m_figura.turnAntiHorari();
		}
	}

	return xoc;

}
bool Joc::mouFigura(int dirX)
{
	bool mov_valid = false;
	if (dirX == 1)
	{

		mov_valid = (m_tauler.ocupada(m_figura, dirX));
		if (!mov_valid)
		{
			m_figura.movRight();
		}
	}
	else
	{
		mov_valid = m_tauler.ocupada(m_figura, dirX);
		if (!mov_valid)
		{
			m_figura.movLeft();
		}
	}

	int fila = 0;
	int col = 0;
	for (int f = m_figura.getPosFRef(); f < m_figura.getPosFRef() + MAX_ALCADA; f++)
	{
		col = 0;
		for (int c = m_figura.getPosCRef(); c < m_figura.getPosCRef() + m_figura.getAmplada(); c++)
		{
			m_tauler.setTauler(f, c, m_figura.getFigura(fila, col));
			col++;
		}
		fila++;
	}
	return mov_valid;
}

int Joc::baixaFigura()//ultimos cambios
{
	int files_completades = 0;
	bool colisiona;

	//1er comprovar q moviment es valid
	m_figura.movDown();
	colisiona = m_tauler.colisiona(m_figura);

	//2n desar el moviment si la figura colisiona
	desaFigura(colisiona);

	//3er comprovar si es completa una fila y eliminarla
	files_completades = m_tauler.eliminaFila();

	return files_completades;
}

void Joc::desaFigura(bool colisiona)
{
	if (colisiona)
	{
		int fila = 0;
		int col = 0;
		for (int f = m_figura.getPosFRef(); f < m_figura.getPosFRef() + MAX_ALCADA; f++)
		{
			col = 0;
			for (int c = m_figura.getPosCRef(); c < m_figura.getPosCRef() + m_figura.getAmplada(); c++)
			{
				m_tauler.setTauler(f, c, m_figura.getFigura(fila, col));
				col++;
			}
			fila++;
		}
	}
}
void Joc::escriuTauler(const string& nomFitxer)
{
	ofstream fitxer;

	fitxer.open(nomFitxer);

	if (fitxer.is_open())
	{

		//coloquem la figura
		for (int f = 0; f < MAX_FILA; f++)
		{
			for (int c = 0; c < MAX_COL; c++)
			{

				if ((f < m_figura.getPosFRef() + MAX_ALCADA) && f >= m_figura.getPosFRef())
				{

					if ((c < m_figura.getPosCRef() + m_figura.getAmplada() && (c >= m_figura.getPosCRef())) && m_figura.getFigura(f - m_figura.getPosFRef(), c - m_figura.getPosCRef()) != COLOR_NEGRE)
					{
						fitxer << m_figura.getFigura(f - m_figura.getPosFRef(), c - m_figura.getPosCRef());

					}
					else
					{
						fitxer << m_tauler.getTauler(f, c);
					}

				}
				else
				{
					fitxer << m_tauler.getTauler(f, c);
				}
			}
			cout << endl;
		}
	}
	fitxer.close();
}
