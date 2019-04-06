/**
 * @brief It implements the inventory interface.
 * @file inventory.c
 * @author Maria Barroso
 * @version 1.0
 * @date 5-10-2016
  */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventory.h"


/**
 * @brief Definition of data structure
 */

struct _Inventory {
    Set* ids; /*!< Set of ids which are in the inventory*/
    int maxobj; /*!< Number of objects that each player can take*/
};

/* Inventory interface implementation */


/**
* @brief  It creates a inventory which is a set that stores ids.
* @author Maria Barroso
* @date  5-10-2016
* @param -
* @return  Inventory : the inventory space
*/

Inventory* inventory_create(){
    Inventory *newinventory = NULL;
    
    newinventory = (Inventory *) malloc (sizeof(Inventory));
    if(!newinventory)
        return NULL;
    
    newinventory->ids = set_create();
    if(!newinventory->ids) {
        free(newinventory);
        return NULL;
    }
        
    newinventory->maxobj = MAX_OBJ;
    
    return newinventory;
}
/**
* @brief  It destroys a inventory, frees the dynamic memory used by it and its ids. 
* @author Maria Barroso
* @date  5-10-2016
* @param inventory : the inventory to be destroyed
* @return  STATUS : error control
*/

STATUS inventory_destroy(Inventory *inventory){
    if(!inventory)
        return ERROR;
    
    if(set_destroy(inventory->ids) == ERROR)
        return ERROR;
    
    free(inventory);
    inventory = NULL;
    
    return OK;
}

/**
* @brief  it adds an id to our inventory.
* @author Maria Barroso
* @date  5-10-2016
* @param inventory : the inventory where a new element may be added
* @param id: the id to be added.
* @return  STATUS : error control
*/
STATUS inventory_add_id(Inventory* inventory, Id id){
    if(!inventory || id == NO_ID || set_get_num(inventory->ids) >= inventory->maxobj)
        return ERROR;
    
    return set_add(inventory->ids, id);
}
/**
* @brief  it checks that an inventory is full
* @author Maria Barroso
* @date  5-10-2016
* @param inventory : Inventory in which its size is checked
* @return  BOOL : TRUE if it is or FALSE if not
*/
BOOL inventory_is_full(Inventory* inventory){
	if(!inventory)
		return TRUE;

	if(set_get_num(inventory->ids) >= inventory->maxobj)
		return TRUE;
	
	return FALSE;
}
/**
* @brief  it deletes a certain id from a inventory if it is in the inventory.
* @author Maria Barroso
* @date  5-10-2016
* @param inventory : the inventory where the id may be
* @param id : the id to be removed
* @return  STATUS : error control
*/
STATUS inventory_delete_id(Inventory* inventory, Id id){
    if(!inventory || id == NO_ID)
        return ERROR;
        
    return set_delete(inventory->ids, id);
}

/**
* @brief  it gets the ids belonging to an inventory
* @author Maria Barroso
* @date  5-10-2016
* @param inventory : Inventory from which ids are obtained
* @return  Set : set of the ids
*/
Set* inventory_get_ids(Inventory* inventory){
    if(!inventory)
        return NULL;
    
    return inventory->ids;
}
/**
* @brief  it cheks if a id is in an inventory
* @author Maria Barroso
* @date  5-10-2016
* @param inventory : Inventory where an id may be.
* @param id : id to check if is in the inventory
* @return  BOOL : TRUE if it is or FALSE if not
*/
BOOL inventory_is_id(Inventory* inventory, Id id){
    if(!inventory || id == NO_ID)
        return FALSE;
    
    return set_search(inventory->ids, id);
}
/**
* @brief It returns the number of ids that have the set.
* @author Maria Barroso
* @date  5-10-2016
* @param inventory :the inventory given
* @return  int: the number of ids that have the inventory
*/
int inventory_get_maxobj(Inventory* inventory){
    if(!inventory)
        return ERR;
    
    return inventory->maxobj;
}

/**
* @brief it prints the data stored in a certain space.
* @author Maria Barroso
* @date  5-10-2016
* @param inventory : the inventory to be printed
* @return  STATUS : error control
*/
STATUS inventory_print(Inventory* inventory){
    if(!inventory)
        return ERROR;
    
    fprintf(stdout, "Inventory.-\n(Maxobjects : %d)", inventory->maxobj);
    
    fprintf(stdout, "\nIds : \n");
    set_print(inventory_get_ids(inventory));
        
    return OK;
}
