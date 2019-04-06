
/**
 * @brief It defines a set
 * @file set.h
 * @author Lucia Colmenarejo
 * @version 1.0
 * @date 13-10-2016
 */

#ifndef SET_H
#define SET_H

#include "types.h"

 /**
 * @brief Definition of macro MAX_ID
 */

#define MAX_ID 50

 /**
 * @brief Definition of set structure
 */

typedef struct _Set Set;  /*<! Definition of the Set structure */

/**
* @brief It creates a set which stores ids.
* @author Lucia Colmenarejo
* @date 14-10-2016
* @param -
* @return Set : the created space
*/
Set* set_create();

/**
* @brief It destroys a set and frees the dynamic memory used by it. 
* @author Lucia Colmenarejo
* @date 14-10-2016
* @param set : the set to be destroyed
* @return STATUS : error control
*/
STATUS set_destroy(Set *set);

/**
* @brief it adds an id to our set.
* @author Lucia Colmenarejo
* @date 14-10-2016
* @param set: the set where a new element may be added
* @param id: the id to be added.
* @return STATUS : error control
*/
STATUS set_add(Set *set, Id id);


/**
* @brief it deletes a certain id from a set if it is in the set.
* @author Lucia Colmenarejo
* @date 14-10-2016
* @param set : the set where the id may be
* @param id : the id to be removed
* @return STATUS : error control
*/
STATUS set_delete(Set *set, Id id);

/**
* @brief It tells whether a certain object is in a set or not.
* @author Lucia Colmenarejo
* @date 14-10-2016
* @param set : the set where the object is searched
* @param id : the id to be searched
* @return BOOL : TRUE (the id is in that space) or FALSE (it is not)
*/
BOOL set_search(Set *set, Id id);

/**
* @brief It returns the number of ids that have the set.
* @author Lucia Colmenarejo
* @date 14-10-2016
* @param set : the set given
* @return int: the number of ids that have the set.
*/
int set_get_num(Set *set);

/**
* @brief it gets the ids of a set
* @author Lucia Colmenarejo
* @date 14-10-2016
* @param set : the set to gets the ids
* @return Id*: array of ids
*/
/*Id* set_get_ids(Set* set);*/

/**
* @brief it prints the data stored in a certain space.
* @author Lucia Colmenarejo
* @date 14-10-2016
* @param set : the set to be printed
* @return STATUS : error control
*/
STATUS set_print(Set *set);

/*STATUS set_print_ids(Set* set, Game* game);*/

/**
* @brief It gets the id number
* @param set : the set to gets the number of id
* @param pos : the position of the id
* @return Id : the id that we want
*/
Id set_get_id_number(Set* set, int pos);

BOOL set_is_full(Set* set);


#endif
