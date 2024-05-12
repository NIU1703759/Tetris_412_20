#include <iostream>
#include "Figura.h"

using namespace std;

/*Figura::Figura(ColorFigura color, TipusFigura tipus)
{
	m_posf_ref = 0;
	m_posc_ref = 0;
	//??
	m_posf = 2;
	m_posc = 1;
	m_tipus = tipus;
	m_color = color;
	incialitzaFigura(tipus, color);
}*/

//get+set d'atributs i inicialitzacio
int Figura::getAmplada(int& index_inici, int& index_final)//retorna el num de columnes NO buides de la matriu figura
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
	index_inici = index_min;
	index_final = index_max;
	return amplada + 1;
}
void Figura::incialitzaFigura(TipusFigura tipus, ColorFigura color)
{
	switch (tipus)
	{
	case FIGURA_O:

		m_forma[0][0] = color;
		m_forma[0][1] = color;
		m_forma[0][2] = COLOR_NEGRE;
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
		m_posc_ref = m_posc - 2;

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
	case FIGURA_S:

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
	case FIGURA_Z:

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
Figura Figura::operator=(const Figura& f)
{
	Figura res;
	res.m_tipus = f.m_tipus;
	res.m_color = f.m_color;
	res.m_posf = f.m_posf;
	res.m_posc = f.m_posc;
	res.m_posf_ref = f.m_posf_ref;
	res.m_posc_ref = f.m_posc_ref;

	for (int i = 0; i < MAX_AMPLADA; i++)
	{
		for (int j = 0; j < MAX_ALCADA; j++)
		{
			res.m_forma[i][j] = f.m_forma[i][j];
		}
	}
	return res;
}

//moviments basics
void Figura::movRight()
{
	m_posc++;
	m_posc_ref++;
}
void Figura::movLeft()
{
	m_posc--;
	m_posc_ref--;
}
void Figura::movDown()
{
	m_posf++;
	m_posf_ref++;
}
void Figura::movUp()
{
	m_posf--;
	m_posf_ref--;
}

//girs
void Figura::invertirColumnes()
{
	ColorFigura invertida[MAX_ALCADA][MAX_AMPLADA];

	if (m_tipus == FIGURA_I) {
		for (int i = 0; i < MAX_AMPLADA; i++)
		{
			for (int j = 0; j < MAX_ALCADA; j++)
			{
				invertida[i][j] = m_forma[MAX_ALCADA - 1 - i][j];
			}
		}
	}

	else {

		for (int i = 0; i < MAX_ALCADA; i++) {
			for (int j = 0; j < MAX_AMPLADA; j++) {
				if (i < MAX_ALCADA - 1 && j < MAX_AMPLADA - 1)
					invertida[i][j] = m_forma[MAX_ALCADA - 2 - i][j];

				else
					invertida[i][j] = COLOR_NEGRE;

			}
		}

	}

	for (int i = 0; i < MAX_ALCADA; i++)
	{
		for (int j = 0; j < MAX_AMPLADA; j++)
		{
			m_forma[i][j] = invertida[i][j];
		}
	}
	/*ColorFigura temp;
	int dim = MAX_ALCADA;

	if (m_tipus != FIGURA_I)
		dim = 3;

	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			temp = m_forma[i][j];
			m_forma[i][j] = m_forma[i][dim - 1 - j];
			m_forma[i][dim - 1 - j] = temp;
		}
	}*/
}
void Figura::invertirFiles()
{
	ColorFigura invertida[MAX_ALCADA][MAX_AMPLADA];

	if (m_tipus == FIGURA_I) {
		for (int i = 0; i < MAX_AMPLADA; i++)
		{
			for (int j = 0; j < MAX_ALCADA; j++)
			{
				invertida[i][j] = m_forma[i][MAX_AMPLADA - 1 - j];
			}
		}
	}

	else {

		for (int i = 0; i < MAX_ALCADA; i++) {
			for (int j = 0; j < MAX_AMPLADA; j++) {
				if (i < MAX_ALCADA - 1 && j < MAX_AMPLADA - 1)
					invertida[i][j] = m_forma[i][MAX_AMPLADA - 2 - j];

				else
					invertida[i][j] = COLOR_NEGRE;

			}
		}

	}

	for (int i = 0; i < MAX_AMPLADA; i++)
	{
		for (int j = 0; j < MAX_ALCADA; j++)
		{
			m_forma[i][j] = invertida[i][j];
		}
	}
	/*ColorFigura temp;
	int dim = MAX_ALCADA;

	if (m_tipus != FIGURA_I)
		dim = 3;
	for (int j = 0; j < dim; j++)
	{
		for (int i = 0; i < dim; i++)
		{
			temp = m_forma[i][j];
			m_forma[i][j] = m_forma[dim - 1 - i][j];
			m_forma[dim - 1 - i][j] = temp;
		}
	}*/
}
void Figura::turnHorari()
{
	ColorFigura transposada[MAX_ALCADA][MAX_AMPLADA];

	invertirColumnes();

	if (m_tipus == FIGURA_I) {
		for (int i = 0; i < MAX_ALCADA; i++) {
			for (int j = 0; j < MAX_AMPLADA; j++) {
				transposada[j][i] = m_forma[i][j];
			}
		}
	}

	else {

		for (int i = 0; i < MAX_ALCADA; i++) {
			for (int j = 0; j < MAX_AMPLADA; j++) {
				if (i < MAX_ALCADA - 1 && j < MAX_AMPLADA - 1)
					transposada[j][i] = m_forma[i][j];

				else
					transposada[i][j] = COLOR_NEGRE;

			}
		}

	}

	for (int i = 0; i < MAX_AMPLADA; i++)
	{
		for (int j = 0; j < MAX_ALCADA; j++)
		{
			m_forma[i][j] = transposada[i][j];
		}
	}

	/*ColorFigura temp;
	int dim = MAX_ALCADA;

	if (m_tipus != FIGURA_O)
	{
		if (m_tipus != FIGURA_I)
			dim = 3;
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
	}*/
}
void Figura::turnAntiHorari()
{
	ColorFigura transposada[MAX_ALCADA][MAX_AMPLADA];

	invertirFiles();

	if (m_tipus == FIGURA_I) {
		for (int i = 0; i < MAX_ALCADA; i++) {
			for (int j = 0; j < MAX_AMPLADA; j++) {
				transposada[j][i] = m_forma[i][j];
			}
		}
	}

	else {

		for (int i = 0; i < MAX_ALCADA; i++) {
			for (int j = 0; j < MAX_AMPLADA; j++) {
				if (i < MAX_ALCADA - 1 && j < MAX_AMPLADA - 1)
					transposada[j][i] = m_forma[i][j];

				else
					transposada[i][j] = COLOR_NEGRE;

			}
		}

	}

	for (int i = 0; i < MAX_AMPLADA; i++)
	{
		for (int j = 0; j < MAX_ALCADA; j++)
		{
			m_forma[i][j] = transposada[i][j];
		}
	}

	/*ColorFigura temp;
	int dim = MAX_ALCADA;

	if (m_tipus != FIGURA_O)
	{
		if (m_tipus != FIGURA_I)
			dim = 3;
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
	}*/
}