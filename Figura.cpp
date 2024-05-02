#include <iostream>
#include "Figura.h"

using namespace std;

Figura::Figura()
{
	m_posf_ref = 0;
	m_posc_ref = 2;
	//??
	m_posf = 0;
	m_posc = 0;
	m_tipus = FIGURA_I;
	m_color = NO_COLOR;
	m_gir = GIR_HORARI;

	for (int f = 0; f < MAX_ALCADA; f++)
	{
		for (int c = 0; c < MAX_AMPLADA; c++)
		{
			m_forma[f][c] = NO_COLOR;
		}
	}

}

void Figura::incialitzaFigura(TipusFigura tipus, ColorFigura color)
{
	switch (tipus)
	{
	case FIGURA_O:

		m_forma[0][0] = COLOR_NEGRE;
		m_forma[0][1] = color;
		m_forma[0][2] = color;
		m_forma[0][3] = COLOR_NEGRE;
		m_forma[1][0] = COLOR_NEGRE;
		m_forma[1][1] = color;
		m_forma[1][2] = color;
		m_forma[1][3] = COLOR_NEGRE;
		m_forma[2][0] = COLOR_NEGRE;
		m_forma[2][1] = COLOR_NEGRE;
		m_forma[2][2] = COLOR_NEGRE;
		m_forma[2][3] = COLOR_NEGRE;
		m_forma[3][0] = COLOR_NEGRE;
		m_forma[3][1] = COLOR_NEGRE;
		m_forma[3][2] = COLOR_NEGRE;
		m_forma[3][3] = COLOR_NEGRE;

		//EJE MOTRIZ + ref

		/*m_posf = 0;
		m_posc = 1;*/

		m_color = color;
		m_tipus = tipus;

		break;
	case FIGURA_I:

		m_forma[0][0] = COLOR_NEGRE;
		m_forma[0][1] = COLOR_NEGRE;
		m_forma[0][2] = COLOR_NEGRE;
		m_forma[0][3] = COLOR_NEGRE;
		m_forma[1][0] = color;
		m_forma[1][1] = color;
		m_forma[1][2] = color;
		m_forma[1][3] = color;
		m_forma[2][0] = COLOR_NEGRE;
		m_forma[2][1] = COLOR_NEGRE;
		m_forma[2][2] = COLOR_NEGRE;
		m_forma[2][3] = COLOR_NEGRE;
		m_forma[3][0] = COLOR_NEGRE;
		m_forma[3][1] = COLOR_NEGRE;
		m_forma[3][2] = COLOR_NEGRE;
		m_forma[3][3] = COLOR_NEGRE;

		//EJE MOTRIZ + ref

		/*m_posf = 1;
		m_posc = 2;*/

		m_color = color;
		m_tipus = tipus;

		break;
	case FIGURA_T:

		m_forma[0][0] = COLOR_NEGRE;
		m_forma[0][1] = color;
		m_forma[0][2] = COLOR_NEGRE;
		m_forma[0][3] = COLOR_NEGRE;
		m_forma[1][0] = color;
		m_forma[1][1] = color;
		m_forma[1][2] = color;
		m_forma[1][3] = COLOR_NEGRE;
		m_forma[2][0] = COLOR_NEGRE;
		m_forma[2][1] = COLOR_NEGRE;
		m_forma[2][2] = COLOR_NEGRE;
		m_forma[2][3] = COLOR_NEGRE;
		m_forma[3][0] = COLOR_NEGRE;
		m_forma[3][1] = COLOR_NEGRE;
		m_forma[3][2] = COLOR_NEGRE;
		m_forma[3][3] = COLOR_NEGRE;

		//EJE MOTRIZ + ref

		/*m_posf = 1;
		m_posc = 1;*/

		m_color = color;
		m_tipus = tipus;

		break;
	case FIGURA_L:

		m_forma[0][0] = COLOR_NEGRE;
		m_forma[0][1] = COLOR_NEGRE;
		m_forma[0][2] = color;
		m_forma[0][3] = COLOR_NEGRE;
		m_forma[1][0] = color;
		m_forma[1][1] = color;
		m_forma[1][2] = color;
		m_forma[1][3] = COLOR_NEGRE;
		m_forma[2][0] = COLOR_NEGRE;
		m_forma[2][1] = COLOR_NEGRE;
		m_forma[2][2] = COLOR_NEGRE;
		m_forma[2][3] = COLOR_NEGRE;
		m_forma[3][0] = COLOR_NEGRE;
		m_forma[3][1] = COLOR_NEGRE;
		m_forma[3][2] = COLOR_NEGRE;
		m_forma[3][3] = COLOR_NEGRE;

		//EJE MOTRIZ + ref

		/*m_posf = 1;
		m_posc = 1;*/

		m_color = color;
		m_tipus = tipus;

		break;
	case FIGURA_J:

		m_forma[0][0] = color;
		m_forma[0][1] = COLOR_NEGRE;
		m_forma[0][2] = COLOR_NEGRE;
		m_forma[0][3] = COLOR_NEGRE;
		m_forma[1][0] = color;
		m_forma[1][1] = color;
		m_forma[1][2] = color;
		m_forma[1][3] = COLOR_NEGRE;
		m_forma[2][0] = COLOR_NEGRE;
		m_forma[2][1] = COLOR_NEGRE;
		m_forma[2][2] = COLOR_NEGRE;
		m_forma[2][3] = COLOR_NEGRE;
		m_forma[3][0] = COLOR_NEGRE;
		m_forma[3][1] = COLOR_NEGRE;
		m_forma[3][2] = COLOR_NEGRE;
		m_forma[3][3] = COLOR_NEGRE;

		//EJE MOTRIZ + ref

		/*m_posf = 1;
		m_posc = 1;*/

		m_color = color;
		m_tipus = tipus;

		break;
	case FIGURA_Z:

		m_forma[0][0] = COLOR_NEGRE;
		m_forma[0][1] = color;
		m_forma[0][2] = color;
		m_forma[0][3] = COLOR_NEGRE;
		m_forma[1][0] = color;
		m_forma[1][1] = color;
		m_forma[1][2] = COLOR_NEGRE;
		m_forma[1][3] = COLOR_NEGRE;
		m_forma[2][0] = COLOR_NEGRE;
		m_forma[2][1] = COLOR_NEGRE;
		m_forma[2][2] = COLOR_NEGRE;
		m_forma[2][3] = COLOR_NEGRE;
		m_forma[3][0] = COLOR_NEGRE;
		m_forma[3][1] = COLOR_NEGRE;
		m_forma[3][2] = COLOR_NEGRE;
		m_forma[3][3] = COLOR_NEGRE;

		//EJE MOTRIZ + ref

		/*m_posf = 1;
		m_posc = 1;*/

		m_color = color;
		m_tipus = tipus;

		break;
	case FIGURA_S:

		m_forma[0][0] = color;
		m_forma[0][1] = color;
		m_forma[0][2] = COLOR_NEGRE;
		m_forma[0][3] = COLOR_NEGRE;
		m_forma[1][0] = COLOR_NEGRE;
		m_forma[1][1] = color;
		m_forma[1][2] = color;
		m_forma[1][3] = COLOR_NEGRE;
		m_forma[2][0] = COLOR_NEGRE;
		m_forma[2][1] = COLOR_NEGRE;
		m_forma[2][2] = COLOR_NEGRE;
		m_forma[2][3] = COLOR_NEGRE;
		m_forma[3][0] = COLOR_NEGRE;
		m_forma[3][1] = COLOR_NEGRE;
		m_forma[3][2] = COLOR_NEGRE;
		m_forma[3][3] = COLOR_NEGRE;

		//EJE MOTRIZ + ref

		/*m_posf = 1;
		m_posc = 1;*/

		m_color = color;
		m_tipus = tipus;

		break;
	default:
		break;
	}
}

ColorFigura Figura::getFigura(int fila, int columna)
{
	return m_forma[fila][columna];
}

void Figura::movRight()
{
	m_posc++;
	m_posc_ref++;
	/*deduzco que dado tanto el giro como el movimiento vienen
	* dados por el eje motriz, la consecuente movilizacion del
	* resto de la matrix m_forma corre a caro de la clase JOC*/
	/*
	* for(int i=0;i<MAX_FILES;i++)
	* {
	*	for(int j=0;j<MAX_COLUMNES)
	*	{
	*		m_forma[i][j]=m_forma[i][j+1];
	*	}
	*
	* }
	*
	*/
}
void Figura::movLeft()
{
	m_posc--;
	m_posc_ref--;
	/*for (int i = 0; i < MAX_FILES; i++)
	{
		for (int j = MAX_COLUMNES; j >0;j--)
		{
			m_forma[i][j] = m_forma[i][j -1];

		}
	}
	*/
}
void Figura::movDown()
{
	m_posf++;
	m_posf_ref++;
}

void Figura::invertirColumnes()
{
	for (int i = 0; i < MAX_ALCADA; i++)
	{
		for (int j = 0; j < MAX_AMPLADA; j++)
		{
			m_forma[i][j] = m_forma[i][MAX_AMPLADA - 1 - j];
		}
	}
}
void Figura::invertirFiles()
{
	for (int j = 0; j < MAX_AMPLADA; j++)
	{
		for (int i = 0; i < MAX_ALCADA; i++)
		{
			m_forma[i][j] = m_forma[MAX_ALCADA - 1 - i][j];
		}
	}
}
void Figura::turnHorari()
{
	for (int i = 0; i < MAX_ALCADA; i++)
	{
		for (int j = 0; j < MAX_AMPLADA; j++)
		{
			m_forma[j][i] = m_forma[i][j];
		}
	}
	invertirColumnes();
}
void Figura::turnAntiHorari()
{
	for (int i = 0; i < MAX_ALCADA; i++)
	{
		for (int j = 0; j < MAX_AMPLADA; j++)
		{
			m_forma[j][i] = m_forma[i][j];
		}
	}
	invertirFiles();
}