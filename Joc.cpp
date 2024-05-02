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
	TipusFigura tipus;
	ColorFigura color, casillas;
	int casillas_int;

	fitxer.open(nomFitxer);

	if (fitxer.is_open())
	{
		int tipus_int, fila, columna, gir;

		//asignaació dels 4 primers valors corresponents a la figura inicial
		fitxer >> tipus_int >> fila >> columna >> gir;

		fila--;
		columna--;

		tipus = TipusFigura(tipus_int);
		color = ColorFigura(tipus_int);

		//omplim figura
		m_figura.setPosF(fila);
		m_figura.setPosC(columna);
		m_figura.setForma(tipus);
		m_figura.setColor(color);
		m_figura.setGir(gir);
		m_figura.incialitzaFigura(tipus, color);

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

		//ampliquem gir de la figura i comprovem que es valid
		bool gir_correcte = true;
		int i = 0;
		while (gir_correcte && i < gir % 4)
		{
			gir_correcte = m_tauler.girCorrecte(m_figura, GIR_HORARI);

			if (gir_correcte)
			{
				m_figura.turnHorari();
				i++;
			}
		}
		if (gir_correcte)//implementem girs nomes si son valids
		{
			for (int f = 0; f < MAX_ALCADA; f++)
			{
				for (int c = 0; c < MAX_AMPLADA; c++)
				{
					m_tauler.setTauler(f + m_figura.getPosFRef(), c + m_figura.getPosCRef(), m_figura.getFigura(f, c));
				}
			}
		}
		else
		{
			cout << "ERROR: GIR INCORRECTE" << endl;
		}

		m_tauler.mostraTauler();//ultimos cambios

	}
	fitxer.close();
}

bool Joc::giraFigura(DireccioGir direccio)
{
	bool xoc;

	if (direccio == GIR_HORARI)
	{
		xoc = m_tauler.girCorrecte(m_figura, direccio);
		if (!xoc)
		{
			m_figura.turnHorari();
		}

	}
	else
	{
		xoc = m_tauler.girCorrecte(m_figura, direccio);
		if (!xoc)
		{
			m_figura.turnAntiHorari();
		}
	}

	for (int f = 0; f < MAX_ALCADA; f++)
	{
		for (int c = 0; c < MAX_AMPLADA; c++)
		{
			m_tauler.setTauler(f + m_figura.getPosFRef(), c + m_figura.getPosCRef(), m_figura.getFigura(f, c));
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

	for (int f = 0; f < MAX_ALCADA; f++)
	{
		for (int c = 0; c < MAX_AMPLADA; c++)
		{
			m_tauler.setTauler(f + m_figura.getPosFRef(), c + m_figura.getPosCRef(), m_figura.getFigura(f, c));
		}
	}
	return mov_valid;
}

int Joc::baixaFigura()//ultimos cambios
{
	int files_completades = 0;
	bool colisiona;

	//1er comprovar q moviment es valid abans de desplaçar
	colisiona = m_tauler.colisiona(m_figura);


	if (colisiona)
	{
		m_figura.movDown();
		//2n colocar figura a tauler
		for (int i = 0; i < MAX_ALCADA; i++)
		{
			for (int c = 0; c < MAX_AMPLADA; c++)
			{
				m_tauler.setTauler(i + m_figura.getPosFRef(), c + m_figura.getPosCRef(), m_figura.getFigura(i, c));
			}
		}

		//3er comprovar si es completa una fila y eliminarla
		files_completades = m_tauler.eliminaFila();

	}

	return files_completades;
}

void Joc::escriuTauler(const string& nomFitxer)//si o si esta bien
{
	ofstream fitxer;

	fitxer.open(nomFitxer);

	if (fitxer.is_open())
	{
		for (int f = 0; f < MAX_FILA; f++)
		{
			for (int c = 0; c < MAX_COL; c++)
			{
				fitxer << m_tauler.getTauler(f, c) << " ";//ultimos cambios
			}
			cout << endl;
		}
	}
	fitxer.close();
}