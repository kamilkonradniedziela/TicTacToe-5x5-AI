/** @file */

/*

KOLKO I KRZYZYK

*/

#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <stdio.h>

#include "struktury.h"

/**Funkcja wyswietlaj�ca zasady gry
*/
void zasadyGry();

/**Funkcja alokuje dynamiczn� tablic� sluzac� za plansz� do gry 
@param[in,out] adres pierwszego elementu tablicy 
*/
void plansza(int* plansza);

/**Funckja usuwa plansz� po grze
@param[in,out] adres pierwszego elementu tablicy 
*/
void UsunPlansze(int* plansza);

/**Funckja rysuje znak w kratce
@param i liczba odpowiedzialna za wyb�r znaku
*/
char rysujZnak(int i);

/**Funkcja rysuje tarcze w czasie trwania gry
@param[in,out] adres pierwszego elementu tablicy
*/
void rysujPlansze(int* plansza);

/**Funkcja zawiera wszystkie mo�liwo�ci wygrania gry,zwracane -1 odpowiada wygranej gracza, gdy zwraca 1 wygrywa komputer 
@param[in,out] adres pierwszego elementu tablicy
*/
int rezultatGry(int* plansza);

/**Funkcja odpowiada za ruch komputera
@param[in,out] adres pierwszego elementu tablicy
@param n poziom trudno�ci wybrany przez gracza
*/
int ruchKomputera(int* plansza, int n);

/**Funcja odpowiada za ruch gracza
@param[in,out] adres pierwszego elementu tablicy
*/
void ruchGracza(int* plansza);

/**Funkcja odpowiada za tworzenie histori rozgrywek
@param[in,out] adres pierwszego elementu listy jednokierunkowej
@param napis wyraz zale�ny od rezultatu gry
*/
void historiaRozgrywek(historiaGry** pGlowa, const char* napis);

/**Funkcja odpowiada za usuwanie histori rozgrywek
@param[in,out] adres pierwszego elementu listy jednokierunkowej
*/
void usunHistorieRozgrywek(historiaGry* pGlowa);

#endif