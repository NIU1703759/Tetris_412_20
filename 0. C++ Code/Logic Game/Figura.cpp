#include <iostream>
#include "Figura.h"
#include "GraphicManager.h"

using namespace std;

//get+set d'atributs i inicialitzacio
int Figura::getAmplada(int& index_inici,int& index_final)//retorna el num de columnes NO buides de la matriu figura
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
	return amplada+1;
}
int Figura::getAlcada()
{
	int alcada = 0;
	int index_min = MAX_ALCADA;
	int index_max = 0;

	for (int f = 0; f < MAX_ALCADA; f++)
	{
		for (int c = 0; c < MAX_AMPLADA; c++)
		{
			if (m_forma[f][c] != COLOR_NEGRE)
			{
				if (f < index_min)
				{
					index_min = f;
				}
				if (f > index_max)
				{
					index_max = f;
				}
			}
		}
	}
	alcada = index_max - index_min;

	return alcada + 1;
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


		m_posf_ref = m_posf-1;
		m_posc_ref = m_posc-1;

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
		m_posc++;

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
void Figura::transposaMatriu()
{
	ColorFigura transposada[MAX_ALCADA][MAX_AMPLADA];

	if (m_tipus == FIGURA_I)
	{
		for (int f = 0; f < MAX_ALCADA; f++)
		{
			for (int c = 0; c < MAX_AMPLADA; c++)
			{
				transposada[c][f] = m_forma[f][c];
			}
		}
	}
	else {

		for (int f = 0; f < MAX_ALCADA; f++) {
			for (int c = 0; c < MAX_AMPLADA; c++) {
				if (f < MAX_ALCADA - 1 && c < MAX_AMPLADA - 1)
					transposada[c][f] = m_forma[f][c];

				else
					transposada[f][c] = COLOR_NEGRE;

			}
		}

	}

	for (int f = 0; f < MAX_AMPLADA; f++)
	{
		for (int c = 0; c < MAX_ALCADA; c++)
		{
			m_forma[f][c] = transposada[f][c];
		}
	}
}
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
}
void Figura::turnHorari()
{
	invertirColumnes();
	transposaMatriu();
}
void Figura::turnAntiHorari()
{

	invertirFiles();
	transposaMatriu();
}

//SEGONA PART GRAFICA
void Figura::dibuixa()
{
	//1ro selecionar color a dibujar
	for (int fila = 0; fila < MAX_ALCADA; fila++)
	{
		for (int col = 0; col < MAX_AMPLADA; col++)
		{
			if (m_forma[fila][col] != COLOR_NEGRE)
			{
				//HE HECHO LA CORRECCION DEL DIBUJO AL CAER PIOLA
				dibuixaQuadrat(m_color, POS_X_TAULER + ((m_posc_ref + col+1) * MIDA_QUADRAT),
					POS_Y_TAULER + ((m_posf_ref + fila) * MIDA_QUADRAT));
			}
		}
	}
}
Figura::Figura(ColorFigura color, TipusFigura tipus,int posf,int posc)
{
	m_posf_ref = 0;
	m_posc_ref = 0;
	m_posf = posf;
	m_posc = posc;
	m_tipus = tipus;
	m_color = color;
	incialitzaFigura(tipus, color);
}//en caso de no incializar el juego en modo test, todas las figuras seran generadas de esta manera
Figura::Figura()
{
	for (int f = 0; f < MAX_ALCADA; f++)
	{
		for (int c = 0; c < MAX_AMPLADA; c++)
		{
			m_forma[f][c] = COLOR_BLAUCEL;
		}
	}
	/*m_colocada = false;
	m_color = COLOR_MAGENTA;
	m_posf_ref = 0;
	m_posc_ref = 0;
	m_tipus = TipusFigura(m_color);
	incialitzaFigura(m_tipus, m_color);*/
}

