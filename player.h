/**
 * @brief It implements the player interface and all the associated callbacks for each command
 * @file player.h
 * @author Francisco Vicente
 * @version 1.0
 * @date 27/11/2016
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "space.h" /*object.h -> types.h*/
#include "inventory.h"

 /**
 * @brief Definition of player structure
 */

typedef struct _Player Player; /*<!Definition of the player structure*/

/**
* @brief It creates a player and gives to it dynamic memory. 
* @author Francisco Vicente
* @date 23/09/2016
* @param id : player identity
* @return Player : the player created by the identity
*/

Player* player_create(Id id);

/**
* @brief It destroys a player and frees its memory. 
* @author Francisco Vicente
* @date 23/09/2016
* @param player : the player to be destroyed
* @return STATUS : error control
*/

STATUS player_destroy(Player* player);

/**
* @brief It sets the name of a player. 
* @author Francisco Vicente
* @date 23/09/2016
* @param player : the player to be named
* @param name : the wanted name
* @return STATUS : error control
*/

STATUS player_set_name(Player* player, char* name);


/**
* @brief It sets a space where the player is. 
* @author Francisco Vicente
* @date 23/09/2016
* @param player : the player to be set in a space
* @param space : the space where the player will be in
* @return STATUS : error control
*/

STATUS player_set_location(Player* player, Space* space);

/**
* @brief It adds the object that the player will carry with.
* @author Francisco Vicente
* @date 23/09/2016
* @param player : the wanted player
* @param object : the object which be carried by a certain player 
* @return STATUS : error control
*/

STATUS player_add_object(Player* player, Object* object);

/**
* @brief It deletes an object which a player is carrying in their bag, in case it exists. 
* @author Francisco Vicente
* @date 7/10/2016
* @param player : the current player
* @param object : the object to be removed from the bag
* @return STATUS : error control
*/

STATUS player_delete_object(Player* player, Object* object);

/**
* @brief It gets the id of a player. 
* @author Francisco Vicente
* @date 23/09/2016
* @param player : the incoming player
* @return Id : the identification of that player
*/

Id player_get_id(Player* player);

/**
* @brief It gets the name of a player. 
* @author Francisco Vicente
* @date 23/09/2016
* @param player : the wanted player
* @return char* : the name of that player
*/

const char * player_get_name(Player* player);

/**
* @brief It gets a space where the player is. 
* @author Francisco Vicente
* @date 23/09/2016
* @param player : the wanted player 
* @return Id : the id of the space where the player is 
*/

Id player_get_location(Player* player);

/**
* @brief It gets the inventory of a player 
* @author Francisco Vicente
* @date 23/09/2016
* @param player : the wanted player
* @return Set : the set of ids that the inventory have
*/

Inventory* player_get_inventory(Player* player);

/*Id* player_get_ids(Player* player);*/

/**
* @brief It searches if the id is in the player's inventory 
* @author Francisco Vicente
* @date 23/09/2016
* @param player : the player in which we search the id 
* @param id : the id to search
* @return BOOL : TRUE if it is or FALSE if not
*/

BOOL player_search_id(Player *player, Id id);

/**
* @brief It prints the data stored in a player 
* @author Francisco Vicente
* @date 23/09/2016
* @param player : the player to be printed
* @return STATUS : error control
*/
STATUS player_print(Player* player);

#endif
