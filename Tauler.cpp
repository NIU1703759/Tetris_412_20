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

//metodes accessibles per Joc
void Tauler::setTauler(int fila, int columna, ColorFigura casilla)
{
    m_tauler[fila][columna] = casilla;
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

void Tauler::desaFigura(bool colisiona, Figura figura)
{
    if (colisiona)
    {
        int fila = 0;
        int col = 0;
        for (int f = figura.getPosFRef(); f < figura.getPosFRef() + MAX_ALCADA; f++)
        {
            col = 0;
            for (int c = figura.getPosCRef(); c < figura.getPosCRef() + MAX_AMPLADA; c++)
            {
                if (figura.getFigura(fila, col) != COLOR_NEGRE)
                {
                    setTauler(f, c, figura.getFigura(fila, col));
                }
                col++;
            }
            fila++;
        }
    }
}

//comprovacio escenaris tauler
bool Tauler::inicialitzaTaulerTest(Tauler& auxiliar, Tauler& celaEsFigura, Figura figura)
{
    bool colocacio_valida = true;
    //1er inicialitzem el tauler auxiliar tal i com estaba l'original
    for (int i = 0; i < MAX_FILA; i++)
    {
        for (int j = 0; j < MAX_COL; j++)
        {
            auxiliar.setTauler(i, j, m_tauler[i][j]);
            celaEsFigura.setTauler(i, j, COLOR_NEGRE);
        }
    }

    //definim param figura
    int index_inici = 0;
    int index_final = 0;
    int amplada = figura.getAmplada(index_inici, index_final);

    //2n actualitzem els valor dels espais q pasarien a ser ocupats per la figura en el tauler
    int fila = 0;
    int col = 0;
    int i = figura.getPosFRef();
    int c = figura.getPosCRef();

    if ((index_inici + c) >= 0 && (amplada + c) <= MAX_COL)//BUEN ARREGLO
    {
        while (colocacio_valida && i < figura.getPosFRef() + MAX_ALCADA)
        {
            col = 0;
            c = figura.getPosCRef();
            while (colocacio_valida && c < figura.getPosCRef() + MAX_AMPLADA)
            {
                if (figura.getFigura(fila, col) != COLOR_NEGRE)
                {
                    auxiliar.setTauler(i, c, figura.getFigura(fila, col));//generar la matriz auxiliar con la figura ya girada
                    celaEsFigura.setTauler(i, c, figura.getFigura(fila, col));//generar tauler solo con matriz girada para cerciorarnos de que la colision no es detectada con elementos de la propia matriz figura
                }
                col++;
                c++;
            }
            fila++;
            i++;
        }
        //comprovacio sobreposicio en colocacio 
        i = 0;
        c = 0;
        while (colocacio_valida && i < MAX_FILA)
        {
            c = 0;
            while (colocacio_valida && c < MAX_COL)
            {
                if ((auxiliar.getTauler(i, c) != COLOR_NEGRE && celaEsFigura.getTauler(i, c) != COLOR_NEGRE) && (getTauler(i, c) != COLOR_NEGRE))
                {
                    colocacio_valida = false;
                }
                c++;
            }
            i++;
        }
    }
    else
    {
        colocacio_valida = false;
    }
    return colocacio_valida;
}

bool Tauler::dins(Figura figura, int& index_inici, int& index_final)
{
    return figura.getPosFRef() >= 0 && figura.getPosFRef() + MAX_ALCADA < MAX_FILA && figura.getPosCRef() >= 0 && figura.getPosCRef() + figura.getAmplada(index_inici, index_final) < MAX_COL;
}

bool Tauler::provocaXoc(Figura& figura, int moviment)
{
    //genera matriz auxiliar

    bool xoc = false;

    if (!figura.getColocada())
    {
        Tauler auxiliar;
        Tauler celaEsFigura;
        //hacer cambios a figura
        switch (moviment)
        {
        case 1://mou dreta
            figura.movRight();
            break;
        case -1://mou esquerra
            figura.movLeft();
            break;
        case 2:
            figura.turnHorari();
            break;
        case -2:
            figura.turnAntiHorari();
            break;
        default:
            break;
        }

        bool colocacio_valida = inicialitzaTaulerTest(auxiliar, celaEsFigura, figura);

        auxiliar.mostraTauler();
        cout << endl;

        //4rt comprovar colisions
        int f = 0;
        int c = 0;
        if (colocacio_valida)
        {
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
        }
        else
        {
            xoc = true;
        }

        if (xoc)
        {
            switch (moviment)
            {
            case 1://mou dreta
                figura.movLeft();
                break;
            case -1://mou esquerra
                figura.movRight();
                break;
            case 2:
                figura.turnAntiHorari();
                break;
            case -2:
                figura.turnHorari();
                break;
            default:
                break;
            }
        }
    }
    return xoc;
}

bool Tauler::colisiona(Figura& figura)//ultimos cambios
{
    bool colisiona = false;
    if (!figura.getColocada())
    {

        //modifiquem posicio figura per test
        figura.movDown();
        //genera matriz auxiliar
        Tauler auxiliar;
        Tauler celaEsFigura;

        bool colocacio_valida = inicialitzaTaulerTest(auxiliar, celaEsFigura, figura);
        bool provoca_xoc = provocaXoc(figura, 3);

        //3er comprobar colision (!=sobreescribir casilla)
        int f = 0;
        int c = 0;

        if (colocacio_valida && !provoca_xoc)
        {
            while (!colisiona && f < MAX_FILA)
            {
                c = 0;
                while (!colisiona && c < MAX_COL)
                {
                    if (auxiliar.getTauler(f, c) != COLOR_NEGRE && celaEsFigura.getTauler(f, c) != COLOR_NEGRE && getTauler(f, c) == COLOR_NEGRE)
                    {
                        if (getTauler(f + 1, c) != COLOR_NEGRE)
                        {
                            colisiona = true;

                        }
                    }
                    c++;
                }
                f++;
            }
        }
        if (provoca_xoc || !colocacio_valida)
        {
            figura.movUp();
        }
        figura.setColocada(colisiona);
        //La figura colisiona cuando la posicion que le pertenece a la figura desplazada ya estaba ocupada en el tablero original
    }
    return colisiona;
}


//eliminar files
int Tauler::contarBloquesEnFila(int fila)
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

int Tauler::eliminaFila()
{
    bool elimina = false;
    int nfilesEliminades = 0;
    int contadorBlocs = 0;

    for (int i = 0; i < MAX_FILA; i++)
    {
        contadorBlocs = contarBloquesEnFila(i);
        elimina = false;
        if (contadorBlocs == MAX_COL)
        {
            elimina = true;
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

void Tauler::eliminarFila(int fila)
{
    for (int j = 0; j < MAX_COL; j++)
    {
        m_tauler[fila][j] = COLOR_NEGRE;
    }
}
void Tauler::desplazarFilasSuperiores(int fila)
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