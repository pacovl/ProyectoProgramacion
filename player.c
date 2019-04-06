/**
 * @brief It implements the player interface and all the associated callbacks for each command
 * @file player.c
 * @author Francisco Vicente
 * @version 1.0
 * @date 27/11/2016
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h" /*types.h, space.h*/
#include "inventory.h"

/**
* @brief Definition of data structure 
*/

struct _Player {
    Id id; /*!<identifier of each player*/
    char name[WORD_SIZE + 1]; /*!<name of the player*/
    Id loc; /*!<Id of the space where the player is*/
    Inventory* inventory; /*!<Bag of objects*/
};



/**
* @brief It creates a player and gives to it dynamic memory. 
* @author Francisco Vicente
* @date 23/09/2016
* @param id : player identity
* @return Player : the player created by the identity
*/

Player* player_create(Id id) {
    Player *player = NULL;
    if (id == NO_ID)
        return NULL;
    player = (Player *)malloc(sizeof(Player));
    if (player == NULL) {
        return NULL;
    }
    
    player->id = id;
    player->name[0] = '\0';
    player->loc = NO_ID;
    player->inventory = inventory_create();
    if(!player->inventory)
        return NULL;
    
    return player; 
}

/**
* @brief It destroys a player and frees its memory. 
* @author Francisco Vicente
* @date 23/09/2016
* @param player : the player to be destroyed
* @return STATUS : error control
*/

STATUS player_destroy(Player* player){
    if(!player) return ERROR;
    
    if(inventory_destroy(player->inventory) == ERROR)
        return ERROR;
    
    free(player);
    player = NULL;
    return OK;
}

/**
* @brief It sets the name of a player. 
* @author Francisco Vicente
* @date 23/09/2016
* @param player : the player to be named
* @param name : the wanted name
* @return STATUS : error control
*/

STATUS player_set_name(Player* player, char* name) {
    if (!player || !name) {
        return ERROR;
    }
    if (!strcpy(player->name, name)) {
        return ERROR;
    }
    return OK;
}

/**
* @brief It sets a space where the player is. 
* @author Francisco Vicente
* @date 23/09/2016
* @param player : the player to be set in a space
* @param space : the space where the player will be in
* @return STATUS : error control
*/

STATUS player_set_location(Player* player, Space* space){
    if(!player || !space) return ERROR;
    
    player->loc = space_get_id(space);
    return OK;
}


/**
* @brief It adds the object that the player will carry with.
* @author Francisco Vicente
* @date 23/09/2016
* @param player : the wanted player
* @param object : the object which be carried by a certain player 
* @return STATUS : error control
*/

STATUS player_add_object(Player* player, Object* object){
    if(!player || !object)
        return ERROR;
     
    return inventory_add_id(player->inventory, object_get_id(object));
}


/**
* @brief It deletes an object which a player is carrying in their bag, in case it exists. 
* @author Francisco Vicente
* @date 7/10/2016
* @param player : the current player
* @param object : the object to be removed from the bag
* @return STATUS : error control
*/

STATUS player_delete_object(Player* player, Object* object){
    if(!player)
        return ERROR;
    
    return inventory_delete_id(player->inventory, object_get_id(object));
}


/**
* @brief It gets the id of a player. 
* @author Francisco Vicente
* @date 23/09/2016
* @param player : the incoming player
* @return Id : the identification of that player
*/

Id player_get_id(Player* player) {
    if (!player) {
        return NO_ID;
    }
    return player->id;
}


/**
* @brief It gets the name of a player. 
* @author Francisco Vicente
* @date 23/09/2016
* @param player : the wanted player
* @return char* : the name of that player
*/

const char * player_get_name(Player* player) {
    if (!player) {
        return NULL;
    }
    return player->name;
}


/**
* @brief It gets a space where the player is. 
* @author Francisco Vicente
* @date 23/09/2016
* @param player : the wanted player 
* @return Id : the id of the space where the player is 
*/

Id player_get_location(Player* player) {
    if(!player) return NO_ID;
    return player->loc;
}

/**
* @brief It gets the inventory of a player 
* @author Francisco Vicente
* @date 23/09/2016
* @param player : the wanted player
* @return Set : the set of ids that the inventory have
*/

Inventory* player_get_inventory(Player *player) {
    if(!player) 
        return NULL;
    return player->inventory;
}


/**
* @brief It searches if the id is in the player's inventory 
* @author Francisco Vicente
* @date 23/09/2016
* @param player : the player in which we search the id
* @param id : the id to search 
* @return BOOL : TRUE if it is or FALSE if not
*/

BOOL player_search_id(Player *player, Id id){
    if(!player)
        return FALSE;
        
    return inventory_is_id(player->inventory, id);
}


/**
* @brief It prints the data stored in a player 
* @author Francisco Vicente
* @date 23/09/2016
* @param player : the player to be printed
* @return STATUS : error control
*/

STATUS player_print(Player* player) {  
    if (!player) {
        return ERROR;
    }
    fprintf(stdout, "--> Player.- \nId: %ld \nName: %s \nLocation: %ld\n", player->id, player->name, player->loc);
    inventory_print(player->inventory);

    return OK;
}
