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
    char* ktoWygral;                ///< napis zawieraj�cy informacj� kto wygra�
    struct historiaGry* nastepny;   ///< adres kolejnego elementu listy
}historiaGry;

#endif