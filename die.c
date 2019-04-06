/**
 * @brief It defines the die's commands
 * @file die.h
 * @author Andres Salas
 * @version 1.0
 * @date 13/10/2016
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "object.h"
#include "die.h"

/**
* @brief Definition of macro NO_DIE
*/

#define NO_DIE -1 /*Default value of numdie before a roll action tak place*/

/**
* @brief Definition of the data structure
*/

struct _Die {
    Id id; /*!< Die's id*/
    int numdie; /*!< Result of the last roll action*/
};

/* Die interface implementation */


/**
* @brief It creates the die
* @author Andres Salas
* @date 20/10/2016
* @param id: the die's id that we will create
* @return the die created
*/

Die* die_create(Id id){
    Die* die;
    if(id == NO_ID)
        return NULL;
        
    die = (Die *)malloc(sizeof(Die));   
    if(!die)
        return NULL;
    
    die->id = id;
    die->numdie = NO_DIE;
    
    return die;
}


/**
* @brief It destroy the die
* @author Andres Salas
* @date 20/10/2016
* @param die: the die that we will destroy
* @return STATUS: error control
*/

STATUS die_destroy(Die* die){
    if(!die)
        return ERROR;
        
    free(die);
    die = NULL;
    
    return OK;
}


/**
* @brief It rolls the die
* @autho Andres Salas
* @date 20/10/2016
* @param die : the die that we will roll
* @return STATUS: error control
*/

STATUS die_roll(Die* die){
    if(!die)
        return ERROR;
    
    srand(time(NULL));
    
    /*This asignation returns a random number beetwen the specified limits*/
    die->numdie = LIM_INF + (rand() % (LIM_SUP - LIM_INF + 1));

    return OK;
}

/**
* @brief It prints the die
* @author Andres Salas
* @date 20/10/2016
* @param die : the die that we will print
* @return STATUS : error control
*/

STATUS die_print(Die* die){
     if(!die)
        return ERROR;
    
    fprintf(stdout, "--> DIE (Id[%ld]: %d)\n", die->id, die->numdie);
    
    return OK;
}


/**
* @brief It gets the die's number
* @author Andres Salas
* @date 07/10/2016
* @param die : the die in which we get the number
* @return int : the number that we get
*/

int die_get_numdie(Die *die){
    if(!die)
        return NO_DIE;

    return die->numdie;
}
