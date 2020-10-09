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


int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    srand(time(NULL));
    char wybor;
    int licznikGier = 1;
    historiaGry* glowaListy = NULL;
    FILE* plik = fopen("HistoriaGry.bin", "wb");
    do
    {
        int* planszaDoGry = malloc(25 * sizeof(int));
        zasadyGry();
        plansza(planszaDoGry);
        printf("Komputer: O, Ty: X\nWybierz,czy chcesz zaczac pierwszy(1) czy drugi(2)? ");
        int ktoZaczyna, poziomTrudnosci;
        scanf("%d", &ktoZaczyna);
        printf("Wybierz poziom trudnosci (1 - latwy, 2 - sredni, 3 - trudny): ");
        scanf("%d", &poziomTrudnosci);
        if (poziomTrudnosci != 1 && poziomTrudnosci != 2 && poziomTrudnosci != 3)
            printf("Taki poziom nie istnieje! System automatycznie dobiera poziom sredni.\n");
        for (unsigned int kolej = 0; kolej < 25 && rezultatGry(planszaDoGry) == 0; kolej++)
        {
            if ((kolej + ktoZaczyna) % 2 == 0)
            {
                ruchKomputera(planszaDoGry, poziomTrudnosci);
            }
            else
            {
                rysujPlansze(planszaDoGry);
                ruchGracza(planszaDoGry);
            }
        }
        switch (rezultatGry(planszaDoGry))
        {
        case 0:
            rysujPlansze(planszaDoGry);
            printf("REMIS! Dobra robota!\n");
            historiaRozgrywek(&glowaListy, "REMIS");
            fprintf(plik, "GRA NR: %d  REZULTAT: %s\n", licznikGier, glowaListy->ktoWygral);
            break;
        case 1:
            rysujPlansze(planszaDoGry);
            printf("PRZEGRALES! Przykro mi\n");
            historiaRozgrywek(&glowaListy, "PORAZKA");
            fprintf(plik, "GRA NR: %d  REZULTAT: %s\n", licznikGier, glowaListy->ktoWygral);
            break;
        case -1:
            rysujPlansze(planszaDoGry);
            printf("WYGRALES!!! Gratulacje!\n");
            historiaRozgrywek(&glowaListy, "ZWYCIESTWO");
            fprintf(plik, "GRA NR: %d  REZULTAT: %s\n", licznikGier, glowaListy->ktoWygral);
            break;
        }
        licznikGier++;
        UsunPlansze(planszaDoGry);
        printf("Jesli chcesz grac dalej nacisnij 'Y', w przeciwnym razie dowolny przycisk: ");
        wybor = _getch();
        printf("\n\n");
    } while (wybor == 'Y' || wybor == 'y');
    fclose(plik);
    usunHistorieRozgrywek(glowaListy);
    return 0;
}