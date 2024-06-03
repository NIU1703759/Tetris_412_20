#include "Tauler.h"
#include "Figura.h"
#include <iostream>
#include "GraphicManager.h"

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
        int posFRef = figura.getPosFRef();
        int posCref = figura.getPosCRef();


        for (int i = 0; i < MAX_ALCADA; i++)
        {
            for (int j = 0; j < MAX_AMPLADA; j++)
            {
                if (figura.getFigura(i, j) != COLOR_NEGRE)
                    setTauler(i + posFRef, j + posCref, figura.getFigura(i, j));
            }
        }
    }

}

//comprovacio escenaris tauler
bool Tauler::inicialitzaTaulerTest(Tauler& auxiliar, Tauler& celaEsFigura,Figura figura)
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
    int amplada = figura.getAmplada(index_inici,index_final);
    int alcada = figura.getAlcada();

    //2n actualitzem els valor dels espais q pasarien a ser ocupats per la figura en el tauler
    int fila = 0;
    int col = 0;
    int i = figura.getPosFRef();
    int c = figura.getPosCRef();

    if ((index_inici + c) >= 0 && (index_final +c) <= MAX_COL && (alcada+i)<=MAX_FILA)//BUEN ARREGLO
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

bool Tauler::dins(Figura figura,int& index_inici,int& index_final)
{
    return figura.getPosFRef() >= 0 && figura.getPosFRef() + MAX_ALCADA < MAX_FILA && figura.getPosCRef() >= 0 && figura.getPosCRef() + figura.getAmplada(index_inici, index_final) < MAX_COL;
}

bool Tauler::provocaXoc(Figura& figura,int moviment)
{
    bool xoc = false;
    Figura newFigura = figura;

    switch (moviment)
    {
    case 1://mou dreta
        newFigura.movRight();
        break;
    case -1://mou esquerra
        newFigura.movLeft();
        break;
    case 2:
        newFigura.turnHorari();
        break;
    case -2:
        newFigura.turnAntiHorari();
        break;
    default:
        break;
    }

    int i = 0, j = 0;
    int posFref = newFigura.getPosFRef();
    int posCRef = newFigura.getPosCRef();

    while (i < MAX_ALCADA && !xoc)
    {
        j = 0;
        while (j < MAX_AMPLADA && !xoc)
        {
            if ((newFigura.getFigura(i, j) != COLOR_NEGRE && m_tauler[i + posFref][j + posCRef] != COLOR_NEGRE) || (j + posCRef + 1 > MAX_COL && newFigura.getFigura(i, j) != COLOR_NEGRE) || (j + posCRef < 0 && newFigura.getFigura(i, j) != COLOR_NEGRE))
            {
                xoc = true;
            }
            j++;
        }
        i++;
    }
    if (!xoc)
    {
        figura = newFigura;

    }
    return xoc;
}

bool Tauler::colisiona(Figura& figura)//ultimos cambios
{
    bool colisiona = false;


    Figura newFigura = figura;
    newFigura.movDown();

    int i = 0, j = 0;
    int posFref = newFigura.getPosFRef();
    int posCRef = newFigura.getPosCRef();

    while (i < MAX_ALCADA && !colisiona)
    {
        j = 0;
        while (j < MAX_AMPLADA && !colisiona)
        {
            if ((newFigura.getFigura(i, j) != COLOR_NEGRE && m_tauler[i + posFref][j + posCRef] != COLOR_NEGRE) || (i + posFref > MAX_FILA - 1 && newFigura.getFigura(i, j) != COLOR_NEGRE))
            {
                colisiona = true;
            }
            j++;
        }
        i++;
    }
    if (!colisiona)
    {
        figura.movDown();
    }

    figura.setColocada(colisiona);

    return colisiona;
}

bool Tauler::baixaComplet(Figura& figura)
{
    bool baixa_complet = false;

    while (!baixa_complet)
    {
        baixa_complet = colisiona(figura);
    }

    return baixa_complet;
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

//SEGONA PART GRAFICA

void Tauler::dibuixa(Figura figura)
{

    GraphicManager::getInstance()->drawSprite(GRAFIC_TAULER, POS_X_TAULER, POS_Y_TAULER, false);
    
    for (int fila = 0; fila < MAX_FILA; fila++)
    {
        for (int col = 0; col < MAX_COL; col++)
        {
            if (m_tauler[fila][col] != COLOR_NEGRE)
            {
                dibuixaQuadrat(m_tauler[fila][col], POS_X_TAULER + ((col+1) * MIDA_QUADRAT),
                    POS_Y_TAULER + (fila * MIDA_QUADRAT));
            }
            /*if (col == 0 || col == 10 || fila == 0 || fila == 20)
            {
                dibuixaQuadrat(m_tauler[fila][col + 2], POS_X_TAULER + ((col + 1) * MIDA_QUADRAT),
                    POS_Y_TAULER + (fila * MIDA_QUADRAT));
            }*/
        }
            
    }
}
