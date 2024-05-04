#include <iostream>
#include "Figura.h"

using namespace std;

/*Figura::Figura()
{
	m_posf_ref = 0;
	m_posc_ref = 0;
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

}*/

int Figura::getAmplada()//retorna el num de columnes NO buides de la matriu figura
{
	int amplada = 0;
	int index_min = MAX_AMPLADA;
	int index_max = 0;


	for (int c = 0; c < MAX_ALCADA; c++)
	{
		for (int f = 0; f < MAX_AMPLADA; f++)
		{
			if (m_forma[f][c] != COLOR_NEGRE)
			{
				if (c < index_min)
				{
					index_min = c;
				}
				if (c > index_max)
				{
					index_max = c;
				}
			}
		}
	}
	amplada = index_max - index_min;
	return amplada + 1;
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

		m_posf_ref = m_posf;
		m_posc_ref = m_posc - 1;

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

		m_posf_ref = m_posf - 1;
		m_posc_ref = m_posc - 1;

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

		m_posf_ref = m_posf - 1;
		m_posc_ref = m_posc - 1;

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

		m_posf_ref = m_posf - 1;
		m_posc_ref = m_posc - 1;

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

		m_posf_ref = m_posf - 1;
		m_posc_ref = m_posc - 1;

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

		m_posf_ref = m_posf - 1;
		m_posc_ref = m_posc - 1;

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

		m_posf_ref = m_posf - 1;
		m_posc_ref = m_posc - 1;

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
	ColorFigura temp;
	int dim = MAX_ALCADA;

	if (m_tipus != FIGURA_I)
		dim = getAmplada();

	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			temp = m_forma[i][j];
			m_forma[i][j] = m_forma[i][dim - 1 - j];
			m_forma[i][dim - 1 - j] = temp;
		}
	}
}
void Figura::invertirFiles()
{
	ColorFigura temp;
	int dim = MAX_ALCADA;

	if (m_tipus != FIGURA_I)
		dim = getAmplada();
	for (int j = 0; j < dim; j++)
	{
		for (int i = 0; i < dim; i++)
		{
			temp = m_forma[i][j];
			m_forma[i][j] = m_forma[dim - 1 - i][j];
			m_forma[dim - 1 - i][j] = temp;
		}
	}
}
void Figura::turnHorari()
{
	ColorFigura temp;
	int dim = MAX_ALCADA;

	if (m_tipus != FIGURA_I)
		dim = getAmplada();
	for (int i = 0; i < dim; i++)
	{
		for (int j = i + 1; j < dim; j++)
		{
			temp = m_forma[j][i];
			m_forma[j][i] = m_forma[i][j];
			m_forma[i][j] = temp;
		}
	}
	invertirColumnes();
}
void Figura::turnAntiHorari()
{
	ColorFigura temp;
	int dim = MAX_ALCADA;

	if (m_tipus != FIGURA_I)
		dim = getAmplada();
	for (int i = 0; i < dim; i++)
	{
		for (int j = i + 1; j < dim; j++)
		{
			temp = m_forma[j][i];
			m_forma[j][i] = m_forma[i][j];
			m_forma[i][j] = temp;
		}
	}
	invertirFiles();
}
