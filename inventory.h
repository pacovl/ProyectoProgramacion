
/**
 * @brief It defines the inventory
 * @file inventory.h
 * @author Maria Barroso
 * @version 1.0
 * @date 5-10-2016
 */
 
#ifndef INVENTORY_H
#define INVENTORY_H

#include "types.h"
#include "set.h"

/**
 * @brief Definition of macro MAX_OBJ
*/

#define MAX_OBJ 12

/**
 * @brief Definition of data enumeration
*/

typedef struct _Inventory Inventory;  /*<! Definition of the Inventory structure */

/**
* @brief  It creates a inventory which is a set that stores ids.
* @author Maria Barroso
* @date  5-10-2016
* @param -
* @return  Inventory : the inventory space
*/
Inventory* inventory_create();

/**
* @brief  It destroys a inventory, frees the dynamic memory used by it and its ids. 
* @author Maria Barroso
* @date  5-10-2016
* @param inventory : the inventory to be destroyed
* @return  STATUS : error control
*/
STATUS inventory_destroy(Inventory *inventory);

/**
* @brief  it adds an id to our inventory.
* @author Maria Barroso
* @date  5-10-2016
* @param inventory : the inventory where a new element may be added
* @param id: the id to be added.
* @return  STATUS : error control
*/
STATUS inventory_add_id(Inventory* inventory, Id id);

/**
* @brief  it checks that an inventory is full
* @author Maria Barroso
* @date  5-10-2016
* @param inventory : Inventory in which its size is checked
* @return  BOOL : TRUE if it is or FALSE if not
*/

BOOL inventory_is_full(Inventory* inventory);

/**
* @brief  it deletes a certain id from a inventory if it is in the inventory.
* @author Maria Barroso
* @date  5-10-2016
* @param inventory : the inventory where the id may be
* @param id : the id to be removed
* @return  STATUS : error control
*/
STATUS inventory_delete_id(Inventory* inventory, Id id);

/**
* @brief  it gets the ids belonging to an inventory
* @author Maria Barroso
* @date  5-10-2016
* @param inventory : Inventory from which ids are obtained
* @return  Set : set of the ids
*/
Set* inventory_get_ids(Inventory* inventory);

/**
* @brief  it cheks if a id is in an inventory
* @author Maria Barroso
* @date  5-10-2016
* @param inventory : Inventory where an id may be.
* @param id : id to check if is in the inventory
* @return  BOOL : TRUE if it is or FALSE if not
*/
BOOL inventory_is_id(Inventory* inventory, Id id);

/**
* @brief It returns the number of ids that have the set.
* @author Maria Barroso
* @date  5-10-2016
* @param inventory :the inventory given
* @return  int: the number of ids that have the inventory
*/
int inventory_get_maxobj(Inventory* inventory);

/**
* @brief It returns an array of ids
* @author Maria Barroso
* @date  5-10-2016
* @param inventory :the inventory given
* @return  id*: array of ids of the inventory
*/


/*Id* inventory_get_arrayids(Inventory* inventory);*/


/**
* @brief it prints the data stored in a certain space.
* @author Maria Barroso
* @date  5-10-2016
* @param inventory : the inventory to be printed
* @return  STATUS : error control
*/
STATUS inventory_print(Inventory* inventory);

#endif
