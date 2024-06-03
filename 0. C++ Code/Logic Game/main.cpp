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
#include <mmsystem.h>

#pragma comment(lib,"winmm.lib")

//EXTRA
void capcelera()
{
    PlaySound("tetrih.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);//TEXT("./0 C++ Code/Logic Game/tetrih.wav")
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
    cout << "                                Axel Povedano Gonzalez             " << endl;
    Sleep(3000);
    system("cls");
    system("Color 0f");
    system("PAUSE");
    PlaySound(nullptr, nullptr, 0);

}

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

void llegeixNomFitxers(string& nomInicial, string& nomFigures, string& nomMoviments)
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
}

int main(int argc, const char* argv[])
{
    //Instruccions necesaries per poder incloure la llibreria i que trobi el main
    SDL_SetMainReady();
    SDL_Init(SDL_INIT_VIDEO);

    //Inicialitza un objecte de la classe Screen que s'utilitza per gestionar la finestra grafica
    Screen pantalla(SCREEN_SIZE_X, SCREEN_SIZE_Y);
    
    Tetris tetris("./data/Games/puntuacions.txt");
    bool sortir = false;
    string nomInici, nomFig, nomMov, nomPlayer="";
    int punts;

    capcelera();
    system("CLS");
    do
    {
        mostraOpcions();
        char opcio = _getch();
        system("CLS");
        switch (opcio)
        {
        case'1':

            PlaySound(TEXT("jogo.wav"), NULL, SND_FILENAME | SND_ASYNC);
            punts = tetris.juga(pantalla, MODE_NORMAL, "", "", "");
            PlaySound(nullptr, nullptr, 0);
            cout << "Insert Player Name: ";
            cin >> nomPlayer;
            tetris.actualitzaPunts(nomPlayer, punts);
            break;
        case '2':
            Sleep(500);
            llegeixNomFitxers(nomInici, nomFig, nomMov);
            punts = tetris.juga(pantalla, MODE_TEST, nomInici, nomFig, nomMov);
            break;
        case'3':
            PlaySound(TEXT("Wii.wav"), NULL, SND_FILENAME | SND_ASYNC);
            tetris.visualitzaPunts(); 
            system("PAUSE");
            PlaySound(nullptr, nullptr, 0);
            system("CLS");
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

    return 0;
}

