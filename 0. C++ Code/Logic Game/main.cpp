//
//  main.cpp
//
//  Copyright � 2018 Compiled Creations Limited. All rights reserved.
//

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) || defined  (_WIN64)

#include <iostream>
//Definicio necesaria per poder incloure la llibreria i que trobi el main
#define SDL_MAIN_HANDLED
#include <windows.h>
//Llibreria grafica
#include "../Graphic Lib/libreria.h"
#include "../Graphic Lib/NFont/NFont.h"
#include <conio.h>      /* getch */ 

#elif __APPLE__
//Llibreria grafica
#include "../Graphic Lib/libreria.h"
#include "../Graphic Lib/NFont/NFont.h"
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"
#include <SDL2/SDL.h>
#pragma clang diagnostic pop

#endif

#include "./Partida.h"
#include "./InfoJoc.h"
#include "Tetris.h"
#include <string>
#include <stdlib.h>


void mostraOpcions()
{
    cout << endl;
    cout << "MENU PRINCIPAL" << endl;
    cout << "==============" << endl;
    cout << "1. Joc en mode normal" << endl;
    cout << "2. Joc en mode test" << endl;
    cout << "3. Mostrar puntuacions" << endl;
    cout << "4. Sortir" << endl;
}

/*void llegeixNomFitxers(string& nomInicial, string& nomFigures, string& nomMoviments)
{
    cout << "Nom del fitxer amb l'estat inicial del tauler: ";
    getline(cin, nomInicial);
    nomInicial = "./data/Games/" + nomInicial;
    cout << "Nom del fitxer amb la sequencia de figures: ";
    getline(cin, nomFigures);
    nomFigures = "./data/Games/" + nomFigures;
    cout << "Nom del fitxer amb la sequencia de moviments: ";
    getline(cin, nomMoviments);
    nomMoviments = "./data/Games/" + nomMoviments;
}*/

int main(int argc, const char* argv[])
{
    //Instruccions necesaries per poder incloure la llibreria i que trobi el main
    SDL_SetMainReady();
    SDL_Init(SDL_INIT_VIDEO);

    //Inicialitza un objecte de la classe Screen que s'utilitza per gestionar la finestra grafica
    Screen pantalla(SCREEN_SIZE_X, SCREEN_SIZE_Y);
    
    /*Tetris tetris("./data/Games/puntuacions.txt");
    bool sortir = false;
    string nomInici, nomFig, nomMov, nomPlayer="";
    int punts;

    do
    {
        mostraOpcions();
        char opcio = _getch();
        system("CLS");
        switch (opcio)
        {
        case'1':

            punts = tetris.juga(pantalla, MODE_NORMAL, "", "", "");
            cout << "Insert Player Name: ";
            cin >> nomPlayer;
            tetris.actualitzaPunts(nomPlayer, punts);
            break;
        case '2':
            Sleep(500);
            //llegeixNomFitxers(nomInici, nomFig, nomMov);
            punts = tetris.juga(pantalla, MODE_TEST, nomInici, nomFig, nomMov);
            break;
        case'3':
            tetris.visualitzaPunts();
            break;
        case'4':
            sortir = true;
            break;
        default:
            cout << "ERROR: Opcio no disponible..." << endl;
        }
    } while (!sortir);

    tetris.guardaPunts("./data/Games/puntuacions.txt");

    SDL_Quit();

    return 0;*/
    pantalla.show();

    Partida game;

    game.setMode(MODE_NORMAL);

    game.incialitza("./data/Games/partida.txt", "./data/Games/figures.txt", "./data/Games/moviments.txt");

    Uint64 NOW = SDL_GetPerformanceCounter();
    Uint64 LAST = 0;
    double deltaTime = 0;


    do
    {
        LAST = NOW;
        NOW = SDL_GetPerformanceCounter();
        deltaTime = (double)((NOW - LAST) / (double)SDL_GetPerformanceFrequency());

        // Captura tots els events de ratolí i teclat de l'ultim cicle
        pantalla.processEvents();

        game.actualitza(deltaTime);

        //Actualitza la pantalla
        pantalla.update();

    } while (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE));
    // Sortim del bucle si pressionem ESC
    int punts = game.getPunts();
    //Instruccio necesaria per alliberar els recursos de la llibreria 
    SDL_Quit();
    return punts;
}

