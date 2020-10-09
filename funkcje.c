/** @file */

/*

KOLKO I KRZYZYK

*/

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <time.h>


#include "struktury.h"
#include "funkcje.h"


void zasadyGry()
{
    puts("ZASADY GRY W KOLKO I KRZYZYK 5 X 5:\n"
        "Twoim oczom ukaze sie plansza z dostepnymi ruchami w grze. \n"
        "DOSTEPNE RUCHY:\n\n"
        "  0 |  1 |  2 |  3 | 4\n"
        "----+----+----+----+---\n"
        " 5  | 6  | 7  | 8  | 9\n"
        "----+----+----+----+---\n"
        " 10 | 11 | 12 | 13 | 14\n"
        "----+----+----+----+---\n"
        " 15 | 16 | 17 | 18 | 19\n"
        "----+----+----+----+---\n"
        " 20 | 21 | 22 | 23 | 24\n\n"
        "POWODZENIA!\n"
    );
}


void plansza(int* plansza)
{
    const int wiersze = 5, kolumny = 5;
    for (int i = 0; i < 25; i++)
    {
        plansza[i] = 0;
    }
}


void UsunPlansze(int* plansza)
{
    free(plansza);
    plansza = NULL;
}


char rysujZnak(int i)
{
    switch (i)
    {
    case -1:
        return 'X';
    case 0:
        return ' ';
    case 1:
        return 'O';
    }
}


void rysujPlansze(int* plansza)
{
    printf(" %c | %c | %c | %c | %c\n", rysujZnak(plansza[0]), rysujZnak(plansza[1]), rysujZnak(plansza[2]), rysujZnak(plansza[3]), rysujZnak(plansza[4]));
    printf("---+---+---+---+---\n");
    printf(" %c | %c | %c | %c | %c\n", rysujZnak(plansza[5]), rysujZnak(plansza[6]), rysujZnak(plansza[7]), rysujZnak(plansza[8]), rysujZnak(plansza[9]));
    printf("---+---+---+---+---\n");
    printf(" %c | %c | %c | %c | %c\n", rysujZnak(plansza[10]), rysujZnak(plansza[11]), rysujZnak(plansza[12]), rysujZnak(plansza[13]), rysujZnak(plansza[14]));
    printf("---+---+---+---+---\n");
    printf(" %c | %c | %c | %c | %c\n", rysujZnak(plansza[15]), rysujZnak(plansza[16]), rysujZnak(plansza[17]), rysujZnak(plansza[18]), rysujZnak(plansza[19]));
    printf("---+---+---+---+---\n");
    printf(" %c | %c | %c | %c | %c\n", rysujZnak(plansza[20]), rysujZnak(plansza[21]), rysujZnak(plansza[22]), rysujZnak(plansza[23]), rysujZnak(plansza[24]));
}


int rezultatGry(int* plansza)
{
    unsigned int mozliwosciZwyciestwa[12][5] = { {0,1,2,3,4},{4,9,14,19,24},{20,21,22,23,24},{0,5,10,15,20},{0,6,12,18,24},
    {4,8,12,16,20},{1,6,11,16,21},{2,7,12,17,22},{3,8,13,18,23},{5,6,7,8,9},{10,11,12,13,14},{15,16,17,18,19} };

    for (int i = 0; i < 12; i++)
    {
        if (plansza[mozliwosciZwyciestwa[i][0]] != 0 &&
            plansza[mozliwosciZwyciestwa[i][0]] == plansza[mozliwosciZwyciestwa[i][1]] &&
            plansza[mozliwosciZwyciestwa[i][0]] == plansza[mozliwosciZwyciestwa[i][2]] &&
            plansza[mozliwosciZwyciestwa[i][0]] == plansza[mozliwosciZwyciestwa[i][3]] &&
            plansza[mozliwosciZwyciestwa[i][0]] == plansza[mozliwosciZwyciestwa[i][4]])
            return plansza[mozliwosciZwyciestwa[i][0]];
    }

    return 0;
}


int ruchKomputera(int* plansza, int n)
{
    int pustaPlansza = 0;

    for (int i = 0; i < 25; i++)
    {
        if (plansza[i] == 0)
            pustaPlansza++;
    }
    if (pustaPlansza == 25)
    {
        return plansza[rand() % 25] = 1;
    }

    unsigned int mozliwosciZwyciestwa[12][5] = { {0,1,2,3,4},{4,9,14,19,24},{20,21,22,23,24},{0,5,10,15,20},{0,6,12,18,24},
    {4,8,12,16,20},{1,6,11,16,21},{2,7,12,17,22},{3,8,13,18,23},{5,6,7,8,9},{10,11,12,13,14},{15,16,17,18,19} };

    bool prawdopodobienstwo;
    int prawdopodobienstwoProcentowe;

    switch (n)
    {
    case 1:
        prawdopodobienstwoProcentowe = 50;
        break;
    case 2:
        prawdopodobienstwoProcentowe = 70;
        break;
    case 3:
        prawdopodobienstwoProcentowe = 90;
        break;
    default:
        prawdopodobienstwoProcentowe = 70;
        break;
    }

    prawdopodobienstwo = (rand() % 100) < prawdopodobienstwoProcentowe;

    for (int i = 0; i < 12; i++)
    {
        //Gdy komputer widzi okazje (zajmuje aktualnie cztery pola pod rz¹d lub w rzêdzie gdzieœ brakuje tylko jednego pola), poddaje gracza automatycznie
        if (plansza[mozliwosciZwyciestwa[i][0]] == 1 && plansza[mozliwosciZwyciestwa[i][4]] == 0 &&
            plansza[mozliwosciZwyciestwa[i][0]] == plansza[mozliwosciZwyciestwa[i][1]] &&
            plansza[mozliwosciZwyciestwa[i][1]] == plansza[mozliwosciZwyciestwa[i][2]] &&
            plansza[mozliwosciZwyciestwa[i][2]] == plansza[mozliwosciZwyciestwa[i][3]])
            return plansza[mozliwosciZwyciestwa[i][4]] = 1;

        else if (plansza[mozliwosciZwyciestwa[i][1]] == 1 && plansza[mozliwosciZwyciestwa[i][0]] == 0 &&
            plansza[mozliwosciZwyciestwa[i][1]] == plansza[mozliwosciZwyciestwa[i][2]] &&
            plansza[mozliwosciZwyciestwa[i][2]] == plansza[mozliwosciZwyciestwa[i][3]] &&
            plansza[mozliwosciZwyciestwa[i][3]] == plansza[mozliwosciZwyciestwa[i][4]])
            return plansza[mozliwosciZwyciestwa[i][0]] = 1;

        else if (plansza[mozliwosciZwyciestwa[i][0]] == 1 && plansza[mozliwosciZwyciestwa[i][1]] == 0 &&
            plansza[mozliwosciZwyciestwa[i][0]] == plansza[mozliwosciZwyciestwa[i][2]] &&
            plansza[mozliwosciZwyciestwa[i][2]] == plansza[mozliwosciZwyciestwa[i][3]] &&
            plansza[mozliwosciZwyciestwa[i][3]] == plansza[mozliwosciZwyciestwa[i][4]])
            return plansza[mozliwosciZwyciestwa[i][1]] = 1;

        else if (plansza[mozliwosciZwyciestwa[i][0]] == 1 && plansza[mozliwosciZwyciestwa[i][2]] == 0 &&
            plansza[mozliwosciZwyciestwa[i][0]] == plansza[mozliwosciZwyciestwa[i][1]] &&
            plansza[mozliwosciZwyciestwa[i][1]] == plansza[mozliwosciZwyciestwa[i][3]] &&
            plansza[mozliwosciZwyciestwa[i][3]] == plansza[mozliwosciZwyciestwa[i][4]])
            return plansza[mozliwosciZwyciestwa[i][2]] = 1;

        else if (plansza[mozliwosciZwyciestwa[i][0]] == 1 && plansza[mozliwosciZwyciestwa[i][3]] == 0 &&
            plansza[mozliwosciZwyciestwa[i][0]] == plansza[mozliwosciZwyciestwa[i][1]] &&
            plansza[mozliwosciZwyciestwa[i][1]] == plansza[mozliwosciZwyciestwa[i][2]] &&
            plansza[mozliwosciZwyciestwa[i][2]] == plansza[mozliwosciZwyciestwa[i][4]])
            return plansza[mozliwosciZwyciestwa[i][3]] = 1;

        //------------
        //blokowanie gracza po trzech wystapieniach znaku

        else if (plansza[mozliwosciZwyciestwa[i][0]] == -1 && plansza[mozliwosciZwyciestwa[i][3]] == 0 &&
            plansza[mozliwosciZwyciestwa[i][0]] == plansza[mozliwosciZwyciestwa[i][1]] &&
            plansza[mozliwosciZwyciestwa[i][1]] == plansza[mozliwosciZwyciestwa[i][2]])
            if (prawdopodobienstwo)         //prawdopodobienstwo 70%
                return plansza[mozliwosciZwyciestwa[i][3]] = 1;
            else
                break;

        else if (plansza[mozliwosciZwyciestwa[i][1]] == -1 && plansza[mozliwosciZwyciestwa[i][4]] == 0 &&
            plansza[mozliwosciZwyciestwa[i][1]] == plansza[mozliwosciZwyciestwa[i][2]] &&
            plansza[mozliwosciZwyciestwa[i][2]] == plansza[mozliwosciZwyciestwa[i][3]])
           if (prawdopodobienstwo)
                return plansza[mozliwosciZwyciestwa[i][4]] = 1;
           else
               break;

        else if (plansza[mozliwosciZwyciestwa[i][1]] == -1 && plansza[mozliwosciZwyciestwa[i][0]] == 0 &&
            plansza[mozliwosciZwyciestwa[i][1]] == plansza[mozliwosciZwyciestwa[i][2]] &&
            plansza[mozliwosciZwyciestwa[i][2]] == plansza[mozliwosciZwyciestwa[i][3]])
            if (prawdopodobienstwo)
                return plansza[mozliwosciZwyciestwa[i][0]] = 1;
            else
                break;

        else if (plansza[mozliwosciZwyciestwa[i][2]] == -1 && plansza[mozliwosciZwyciestwa[i][1]] == 0 &&
            plansza[mozliwosciZwyciestwa[i][2]] == plansza[mozliwosciZwyciestwa[i][3]] &&   //blad
            plansza[mozliwosciZwyciestwa[i][3]] == plansza[mozliwosciZwyciestwa[i][4]])
            if (prawdopodobienstwo)
                return plansza[mozliwosciZwyciestwa[i][1]] = 1;
            else
                break;
    }

    unsigned int ruch;
    do
    {
        ruch = rand() % 25;
        plansza[ruch];
    } while (plansza[ruch] != 0);
    return plansza[ruch] = 1;
}


void ruchGracza(int* plansza)
{
    unsigned int ruch;
    do
    {
        printf("\nTwoj ruch ([0...24]): ");
        scanf("%d", &ruch);
        printf("\n");
        if (plansza[ruch] != 0 && ruch < 25)
        {
            printf("Pole ktore wybierasz jest zajete! Wybierz dostepne pole.\n");
        }
        if (ruch >= 25)
        {
            printf("Pole ktore wybierasz nie istnieje! Wybierz dostepne pole.\n");
        }
    } while (ruch >= 25 || plansza[ruch] != 0);
    plansza[ruch] = -1;
}


void historiaRozgrywek(historiaGry** pGlowa, const char* napis)
{
    if (*pGlowa == NULL)
    {
        *pGlowa = (historiaGry*)malloc(sizeof(historiaGry));
        (*pGlowa)->ktoWygral = strcpy(malloc(strlen(napis) + 1), napis);
        (*pGlowa)->nastepny = NULL;
    }
    else
    {
        historiaGry* kolejnyRekord = (historiaGry*)malloc(sizeof(historiaGry));
        kolejnyRekord->ktoWygral = strcpy(malloc(strlen(napis) + 1), napis);
        kolejnyRekord->nastepny = *pGlowa;
        *pGlowa = kolejnyRekord;
    }
}

void usunHistorieRozgrywek(historiaGry* pGlowa)
{
    while (pGlowa)
    {
        historiaGry* tmp = pGlowa->nastepny;
        free(pGlowa->ktoWygral);
        free(pGlowa);
        pGlowa = tmp;
    }
}