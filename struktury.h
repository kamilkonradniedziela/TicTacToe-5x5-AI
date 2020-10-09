/** @file */

/*

KOLKO I KRZYZYK

*/

#ifndef STRUKTURY_H
#define STRUKTURY_H

#include <stdio.h>

/**Historia rozgrywek */
typedef struct
{
    char* ktoWygral;                ///< napis zawieraj¹cy informacjê kto wygra³
    struct historiaGry* nastepny;   ///< adres kolejnego elementu listy
}historiaGry;

#endif