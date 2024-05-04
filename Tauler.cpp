#include "Tauler.h"
#include "Figura.h"
#include <iostream>

using namespace std;
Tauler::Tauler()
{
    for (int fila = 0; fila < MAX_FILA; fila++)
    {
        for (int columna = 0; columna < MAX_COL; columna++)
        {
            m_tauler[fila][columna] = ColorFigura::COLOR_NEGRE;
        }
    }
}

void Tauler::mostraTauler()
{
    for (int fila = 0; fila < MAX_FILA; fila++)
    {
        for (int columna = 0; columna < MAX_COL; columna++)
        {
            cout << m_tauler[fila][columna] << " ";
        }
        cout << endl;
    }
}

bool Tauler::dins(int fila, int columna)
{
    return fila >= 0 && fila < MAX_FILA&& columna >= 0 && columna < MAX_COL;
}

bool Tauler::girCorrecte(Figura figura, DireccioGir gir)
{
    //genera matriz auxiliar
    Tauler auxiliar;
    Tauler celaEsFigura;

    //1er inicialitzem el tauler auxiliar tal i com estaba l'original
    for (int i = 0; i < MAX_FILA; i++)
    {
        for (int j = 0; j < MAX_COL; j++)
        {
            auxiliar.setTauler(i, j, m_tauler[i][j]);
            celaEsFigura.setTauler(i, j, COLOR_NEGRE);
        }
    }

    //3er actualitzem els valor dels espais q pasarien a ser ocupats per la figura en el tauler en girar
    int fila = 0;
    int col = 0;

    for (int i = figura.getPosFRef(); i < figura.getPosFRef() + MAX_ALCADA; i++)
    {
        col = 0;
        for (int c = figura.getPosCRef(); c < figura.getPosCRef() + figura.getAmplada(); c++)
        {
            auxiliar.setTauler(i, c, figura.getFigura(fila, col));//generar la matriz auxiliar con la figura ya girada
            celaEsFigura.setTauler(i, c, figura.getFigura(fila, col));//generar tauler solo con matriz girada para cerciorarnos de que la colision no es detectada con elementos de la propia matriz figura
            col++;
        }
        fila++;
    }
    auxiliar.mostraTauler();
    cout << endl;
    //4rt comprovar colisions
    bool xoc = false;
    int f = 0;
    int c = 0;
    while (!xoc && f < MAX_FILA)
    {
        while (!xoc && c < MAX_COL)
        {
            if ((auxiliar.getTauler(f, c) != COLOR_NEGRE && celaEsFigura.getTauler(f, c) != COLOR_NEGRE) && (getTauler(f, c) != COLOR_NEGRE))//la posicio del tauler amb la figura girada correspon a la la figura girada, pero al tauler original aquesta posicio NO estava buida
            {
                xoc = true;
            }
            c++;
        }
        f++;
    }
    return xoc;
}

bool Tauler::ocupada(Figura figura, int direccio)
{
    //genera matriz auxiliar
    Tauler auxiliar;
    Tauler celaEsFigura;

    //1er inicialitzem el tauler auxiliar tal i com estaba l'original
    for (int i = 0; i < MAX_FILA; i++)
    {
        for (int j = 0; j < MAX_COL; j++)
        {
            auxiliar.setTauler(i, j, m_tauler[i][j]);
            celaEsFigura.setTauler(i, j, COLOR_NEGRE);
        }
    }

    //2n actualitzem els valor dels espais q pasarien a ser ocupats per la figura en el tauler en desplacarse a la dreta(dir=1) o esquerra(dir=-1)
    for (int i = figura.getPosFRef(); i < figura.getPosFRef() + MAX_ALCADA; i++)
    {
        for (int c = figura.getPosCRef(); c < figura.getPosCRef() + figura.getAmplada(); c++)
        {
            auxiliar.setTauler(i, c + (direccio), figura.getFigura(i, c));//el "+1" es para generar la matriz auxiliar con la figura ya bajada
            celaEsFigura.setTauler(i, c + (direccio), figura.getFigura(i, c));//generar tauler solo con matriz bajada para cerciorarnos de que la colision no es detectada con elementos de la propia matriz figura
        }
    }

    //3er comprovem que el desplaçament no provoca un xoc 
    bool ocupada = false;
    int f = 0;
    int c = 0;
    while (!ocupada && f < MAX_FILA)
    {
        while (!ocupada && c < MAX_COL)
        {
            if ((!dins(f, c + (direccio)) || (auxiliar.getTauler(f, c + (direccio)) != COLOR_NEGRE && celaEsFigura.getTauler(f, c + 1) == COLOR_NEGRE)))
            {
                ocupada = true;
            }
            c++;
        }
        f++;
    }


    return ocupada;
}

void Tauler::setTauler(int fila, int columna, ColorFigura casilla)
{
    m_tauler[fila][columna] = casilla;
}

bool Tauler::colisiona(Figura figura)//ultimos cambios
{
    //genera matriz auxiliar
    Tauler auxiliar;
    Tauler celaEsFigura;

    //1er inicialitzem el tauler auxiliar tal i com estaba l'original
    for (int i = 0; i < MAX_FILA; i++)
    {
        for (int j = 0; j < MAX_COL; j++)
        {
            auxiliar.setTauler(i, j, m_tauler[i][j]);
            celaEsFigura.setTauler(i, j, COLOR_NEGRE);
        }
    }

    //2n actualitzem els valor dels espais q pasarien a ser ocupats per la figura en el tauler en desplaçarse cap avall
    for (int i = figura.getPosFRef(); i < figura.getPosFRef() + MAX_ALCADA; i++)
    {
        for (int c = figura.getPosCRef(); c < figura.getPosCRef() + MAX_AMPLADA; c++)
        {
            auxiliar.setTauler(i, c, figura.getFigura(i, c));//el "+1" es para generar la matriz auxiliar con la figura ya bajada
            celaEsFigura.setTauler(i, c, figura.getFigura(i, c));//generar tauler solo con matriz bajada para cerciorarnos de que la colision no es detectada con elementos de la propia matriz figura
        }
    }

    //3er comprobar colision (!=sobreescribir casilla)
    bool colisiona = false;
    int f = 0;
    int c = 0;
    while (!colisiona && f < MAX_FILA)
    {
        c = 0;
        while (!colisiona && c < MAX_COL)
        {
            if (auxiliar.getTauler(f, c) != COLOR_NEGRE && celaEsFigura.getTauler(f, c) != COLOR_NEGRE)//&& Cel·laEsFigura[f][c] == 1
            {
                if (auxiliar.getTauler(f + 1, c) != COLOR_NEGRE && celaEsFigura.getTauler(f, c) == COLOR_NEGRE)
                {
                    colisiona = true;
                }
            }
            c++;
        }
        f++;
    }
    //La figura colisiona cuando en la siguiente fila (misma columna) hay una casilla llena.
    return colisiona;
}

//funcions privades d'eliminaFila():
void Tauler::eliminarFila(int fila)//si o si estan bien
{
    for (int j = 0; j < MAX_COL; j++)
    {
        m_tauler[fila][j] = COLOR_NEGRE;
    }
}
void Tauler::desplazarFilasSuperiores(int fila)//si o si estan bien
{
    for (int i = fila; i > 0; i--)
    {
        for (int j = 0; j < MAX_COL; j++)
        {
            m_tauler[i][j] = m_tauler[i - 1][j];
        }
    }
    for (int j = 0; j < MAX_COL; j++)
    {
        m_tauler[0][j] = COLOR_NEGRE;
    }
}

int Tauler::contarBloquesEnFila(int fila)//si o si estan bien
{
    int contadorBlocs = 0;

    for (int j = 0; j < MAX_COL; j++)
    {
        if (m_tauler[fila][j] != COLOR_NEGRE)
        {
            contadorBlocs++;
        }
    }
    return contadorBlocs;
}
int Tauler::eliminaFila()//si o si estan bien
{
    bool elimina = false;
    int nfilesEliminades = 0;

    for (int i = 0; i < MAX_FILA; i++)
    {
        int contadorBlocs = contarBloquesEnFila(i);

        if (contadorBlocs == MAX_COL)
        {
            elimina = true;
            break;
        }
        if (elimina)
        {
            eliminarFila(i);
            desplazarFilasSuperiores(i);
            nfilesEliminades++;
        }
    }
    return nfilesEliminades;
}
