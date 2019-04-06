/**
 * @brief It defines the die's commands
 * @file die.h
 * @author Andres Salas
 * @version 1.0
 * @date 13/10/2016
 */
 
#ifndef DIE_H
#define DIE_H

/**
 * @brief Definition of macro LIM_INF
*/

#define LIM_INF 1 /*the lowest number of our die*/

/**
 * @brief Definition of macro LIM_SUP
*/

#define LIM_SUP 6 /*the highest number of our die*/

#include "types.h"

/**
 * @brief Definition of die structure
*/

typedef struct _Die Die; /*<! Definition of the Die structure */


/**
* @brief It creates the die
* @author Andres Salas
* @date 20/10/2016
* @param id: the die's id that we will create
* @return the die created
*/

Die* die_create(Id id);

/**
* @brief It destroy the die
* @author Andres Salas
* @date 20/10/2016
* @param die: the die that we will destroy
* @return STATUS: error control
*/

STATUS die_destroy(Die *die);

/**
* @brief It rolls the die
* @author Andres Salas
* @date 20/10/2016
* @param die : the die that we will roll
* @return STATUS: error control
*/


STATUS die_roll(Die *die);


/**
* @brief It prints the die
* @author Andres Salas
* @date 20/10/2016
* @param die : the die that we will print
* @return STATUS : error control
*/

STATUS die_print(Die *die);


/**
* @brief It gets the die's number
* @author Andres Salas
* @date 07/10/2016
* @param die : the die in which we get the number
* @return int : the number that we get
*/


int die_get_numdie(Die *die);

#endif