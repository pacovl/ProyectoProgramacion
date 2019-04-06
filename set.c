
 /**
 * @brief It implements the set interface.
 * @file set.c
 * @author Lucia Colmenarejo
 * @version 1.0
 * @date 13-10-2016
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"

/**
 * @brief Definition of the data structure
 */

struct _Set {
    Id id[MAX_ID]; /*!<Identifiers stored in each set*/
    int num; /*!<The number of elements in the set*/
};


/* Set interface implementation */


/**
* @brief It creates a set which stores ids.
* @author Lucia Colmenarejo
* @date 14-10-2016
* @param -
* @return Set : the created space
*/
Set* set_create(){
    Set* set = NULL;
    int i = 0;
    
    set = (Set *) malloc (sizeof(Set));
    if(!set)
        return NULL;
    
    set->num = 0;
    
    for(i = 0; i < MAX_ID; i++){
        set->id[i] = NO_ID;
    }
    
    return set;
}

/**
* @brief It destroys a set and frees the dynamic memory used by it. 
* @author Lucia Colmenarejo
* @date 14-10-2016
* @param set : the set to be destroyed
* @return STATUS : error control
*/
STATUS set_destroy(Set *set){
    if(!set)
        return ERROR;
        
    free(set);
    return OK;
}

/**
* @brief it adds an id to our set.
* @author Lucia Colmenarejo
* @date 14-10-2016
* @param set: the set where a new element may be added
* @param id: the id to be added.
* @return STATUS : error control
*/
STATUS set_add(Set *set, Id id){
    if(!set || id == NO_ID || set->num >= MAX_ID)
        return ERROR;
    set->id[set->num] = id;
    (set->num)++;
    return OK;
}


/**
* @brief it deletes a certain id from a set if it is in the set.
* @author Lucia Colmenarejo
* @date 14-10-2016
* @param set : the set where the id may be
* @param id : the id to be removed
* @return STATUS : error control
*/
STATUS set_delete(Set *set, Id id){
    int i = 0;
    
    if(!set)
        return ERROR;
    
    for(i = 0; i < set->num; i++){
        if(set->id[i] == id){
            set->id[i] = NO_ID;
            while(i < set->num){
                set->id[i] = set->id[i+1];
                i++;
            }
            set->id[i] = NO_ID;
            set->num--;
            return OK;
        }
    }
    
    return ERROR;
}

/**
* @brief It tells whether a certain object is in a set or not.
* @author Lucia Colmenarejo
* @date 14-10-2016
* @param set : the set where the object is searched
* @param id : the id to be searched
* @return BOOL : TRUE (the id is in that space) or FALSE (it is not)
*/
BOOL set_search(Set *set, Id id){
    int i;
    
    if(!set || id == NO_ID)
        return FALSE;
    
    for(i=0; i < set->num; i++){
        if(set->id[i] == id)
            return TRUE;
    }
    return FALSE;
}


/**
* @brief It returns the number of ids that have the set.
* @author Lucia Colmenarejo
* @date 14-10-2016
* @param set : the set given
* @return int: the number of ids that have the set.
*/
int set_get_num(Set *set){
    if(!set)
        return -1;
        
    return set->num;
}


/**
* @brief it prints the data stored in a certain space.
* @author Lucia Colmenarejo
* @date 14-10-2016
* @param set : the set to be printed
* @return STATUS : error control
*/
STATUS set_print(Set *set){
    int i;
    if(!set)
        return ERROR;
    
    if(set->id[0] == NO_ID){
    	printf("Empty set\n");
    	return OK;
    }

    printf("--> Set (");
    
    for(i = 0; i < set->num; i++){
        printf("Id[%d]: %ld  ", i+1, set->id[i]);
    }
    
    printf(")\n");
    return OK;
}

/**
* @brief It gets the id number
* @param set : the set to gets the number of id
* @param pos : the position of the id
* @return Id : the id that we want
*/

Id set_get_id_number(Set* set, int pos) {
    if(!set || pos < 0 || pos > set->num)
        return NO_ID;

    return set->id[pos];
}

BOOL set_is_full(Set* set){
    if(!set)
        return TRUE;
    
    if(set_get_num(set) >= MAX_ID)
        return TRUE;
    
    return FALSE;
}

