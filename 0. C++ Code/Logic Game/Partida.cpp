#include <iostream>
#include "Partida.h"
#include "InfoJoc.h"
#include "GraphicManager.h"
#include "Joc.h"
#include "Tauler.h"
#include "Figura.h"
#include "NodeFigura.h"
#include "NodeMoviment.h"

using namespace std;

Partida::Partida()
{
    m_temps = 0;
    m_velocitat = 1.0;
    m_nivell = 0;
    m_finalPartida = false;
    m_punts = 0;
    
}
void Partida::incialitza( const string& fitxerInicial, const string& fitxerFigures, const string& fitxerMoviments) 
{
    if (m_mode == MODE_TEST)//mode test
    {
        //incialitzem el tauler i les llistes dinamiques
        m_joc.inicialitza(fitxerInicial);

        NodeFigura* nodeFig = new NodeFigura();
        m_llistaFigures.ompleLlista(fitxerFigures, nodeFig);

        NodeMoviment* nodeMov = new NodeMoviment();
        m_llistaMoviments.ompleLlista(fitxerFigures, nodeMov);
    }
    else 
    {
        m_finalPartida = m_joc.generaFigura();
    }
}

void Partida::actualitzaMovTest(double deltaTime)
{
    m_temps += deltaTime;
    int nFilesEliminades = 0;
    if (m_temps > deltaTime)
    {
        m_temps = 0.0;

        if (!m_llistaMoviments.esBuida())
        {
            TipusMoviment moviment = m_llistaMoviments.getPrimer()->getValor();
            m_llistaMoviments.treu();
            switch (moviment)
            {
            case MOVIMENT_GIR_HORARI:
                m_joc.mouFigura(2);

                break;
            case MOVIMENT_GIR_ANTI_HORARI:
                m_joc.mouFigura(-2);

                break;
            case MOVIMENT_DRETA:
                m_joc.mouFigura(1);

                break;
            case MOVIMENT_ESQUERRA:
                m_joc.mouFigura(-1);

                break;
            case MOVIMENT_BAIXA_FINAL:

                nFilesEliminades = m_joc.baixaComplet();
                actualitzaPuntuacio(nFilesEliminades);
                if (!m_llistaFigures.esBuida())
                {
                    Figura figura = m_llistaFigures.getPrimer()->getValor();
                    m_llistaFigures.treu();
                    m_joc.generaFiguraTest(figura);
                }
                else
                {
                    m_finalPartida = true;
                }

                break;
            case MOVIMENT_BAIXA:

                nFilesEliminades = m_joc.baixaFigura();
                if (nFilesEliminades != 0)
                {
                    actualitzaPuntuacio(nFilesEliminades);
                    if (!m_llistaFigures.esBuida())
                    {
                        Figura figura = m_llistaFigures.getPrimer()->getValor();
                        m_llistaFigures.treu();
                        m_joc.generaFiguraTest(figura);
                    }
                    else
                    {
                        m_finalPartida = true;
                    }
                }


                break;
            }
        }
        else
        {
            m_finalPartida = true;
        }
    }
}
void Partida::actualitzaMov(double deltaTime)
{
    int nFilesEliminades = 0;

    //REALITZEM MOVIMENTS/BAIXEM DEL TOT ABANS DE COMPROVAR QUE COLISIONI AMB FONS O FIGURA
    if (Keyboard_GetKeyTrg(KEYBOARD_UP))//MOVIMENT_GIR_HORARI
    {
        m_joc.mouFigura(2);
    }
    else
    {
        if (Keyboard_GetKeyTrg(KEYBOARD_DOWN))//MOVIMENT_GIR_ANTI_HORARI
        {
            m_joc.mouFigura(-2);
        }
    }
    if (Keyboard_GetKeyTrg(KEYBOARD_RIGHT))//MOVIMENT_DRETA
    {
        m_joc.mouFigura(1);
    }
    else
    {
        if (Keyboard_GetKeyTrg(KEYBOARD_LEFT))//MOVIMENT_ESQUERRA
        {
            m_joc.mouFigura(-1);
        }
    }

    //baixar figura
    if (Keyboard_GetKeyTrg(KEYBOARD_SPACE))//MOVIMENT_BAIXA_FINAL
    {
        nFilesEliminades = m_joc.baixaComplet();
        actualitzaPuntuacio(nFilesEliminades);
        m_finalPartida = m_joc.generaFigura();
        m_temps = 0.0;
    }
    else
    {
        m_temps += deltaTime;
        if (m_temps > (0.5-m_velocitat/40))
        {
            nFilesEliminades = m_joc.baixaFigura();
            if (nFilesEliminades != 0||m_joc.getFigCol())
            {
                m_finalPartida = m_joc.generaFigura();
                actualitzaPuntuacio(nFilesEliminades);
            }
            m_temps = 0.0;
        }
    }
}
void Partida::actualitza(double deltaTime)
{
    
    if (!m_finalPartida)
    {
        if (m_mode == MODE_NORMAL)
        {
            actualitzaMov(deltaTime);
        }
        else
        {
            actualitzaMovTest(deltaTime);
        }
    }

    //dibuixa fons
    GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
    m_joc.dibuixa();

    //puntuacio i nivell
    string punts = "Puntuacio: " + to_string(m_punts);
    string nivell = "Nivell: " + to_string(m_nivell);

    GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POS_X_PUNTUACIO, POS_Y_PUNTUACIO - 50, 0.8, punts);
    GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POS_X_NIVELL, POS_Y_NIVELL - 50, 0.8, nivell);

    if (m_finalPartida)
    {
        //GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
        GraphicManager::getInstance()->drawFont(FONT_RED_30, POS_X_FINAL, POS_Y_FINAL, 0.8, "GAME OVER");
    }
}
void Partida::actualitzaPuntuacio(int nFilesEliminades)
{
    if (nFilesEliminades == 0)
    {
        m_punts += PUNTS_FIGURA;
    }
    else
    {
        switch (nFilesEliminades)
        {
        case 1:
            m_punts += PUNTS_FILA;
            break;
        case 2:
            m_punts += PUNTS_DOBLE_FILA;
            break;
        case 3:
            m_punts += PUNTS_TRIPLE_FILA;
            break;
        case 4:
            m_punts += PUNTS_TETRIS;
            break;
        }
    }
    if (m_punts > m_nivell * CANVI_NIVELL)
    {
        m_nivell += 1;
        m_velocitat *= CANVI_VELOCITAT;
    }
}

