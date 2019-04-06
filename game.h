/**
 * @brief It implements the game interface and all the associated callbacks for each command
 * @file game.c
 * @author Andres Salas, Francisco Vicente, Maria Barroso y Lucia Colmenarejo
 * @version 1.0
 * @date 27/11/2016
 */
 
#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include "player.h" /*space.h -> object.h -> types.h*/
#include "command.h"
#include "die.h"

/**
 * @brief Definition of game structure
*/

typedef struct _Game Game;  /*<! Definition of the game structure*/

/**
* @brief It creates a game, allocating the necessay memory for it. 
* @author Francisco Vicente
* @date 30/09/2016
* @return Game : the newly created game
*/

Game* game_create(); 

/**
* @brief It initializes a game just setting its fields with the default values. 
* @author Andres Salas 
* @date 23/09/2016
* @param game : the running game
* @param player_id : the id of the game's player
* @param die_id : the id of the game's die 
* @return STATUS : error control
*/

STATUS game_init(Game* game, Id player_id, Id die_id);

/**
* @brief It calls game_init at first and then load the spaces of the new game from 
*	the incoming file. Then it sets the locations of player and object at the
*	default space. It is important that game_load_objects is called before 
* game_load_spaces due to the fact that the precess of adding an object to
* the game requires the existance of spaces in that game. 
* @author Francisco Vicente
* @date 29/10/2016
* @param game : the game to be initialized from file
* @param filename1 : the name of the file
* @parma filename2 : the name of the file
* @param filename3 : the name of the file 
* @param player : the id of the game's player
* @param die : the id of the game's die
* @return STATUS : error control
*/

STATUS game_init_from_file(Game* game, char* filename1, char* filename2, char* filename3, Id player, Id die);

/**
* @brief It matches each incoming command with its correspoding callback. It 
* also prints the neccesary data for the log file
* @author Andres Salas
* @date 01/11/2016
* @param game : the game to be updated
* @param cmd : the command that may be used
* @param f : the register file
* @return STATUS : error control
*/

STATUS game_update(Game* game, Command* cmd, FILE *f);

/**
* @brief When the game is finisehd, it frees the dynamic memory allocated previously.
* @author Andres Salas
* @date 23/09/2016
* @param game : the game to be destroyed
* @return STATUS : error control
*/

STATUS game_destroy(Game* game);

/**
* @brief It tells when the game is over.
* @author Andres Salas
* @date 23/09/2016
* @param game : the game which may be over
* @return BOOL : it returns TRUE or FALSE
*/

BOOL game_is_over(Game* game);

/**
* @brief It prints the data allocated in a game structure.
* @author Andres Salas
* @date 23/09/2016
* @param game : the game which data may be printed
* @return void: -
*/

void game_print_data(Game* game);

/**
* @brief It manages all the graphic interface of the game, printing each space where
*	they must be with its grphic description and the symbol and location of 
* each object.
* @author Francisco Vicente
* @date 31/10/2016
* @param game : the game to be printed
* @return void : -
*/

void   game_print_screen(Game* game);

/**
* @brief It sets the location of an object inside the incoming game.
* It is public due to the fact that game_add_object is in GameReader and
* it requiere to use this function.
* @author Francisco Vicente
* @date 30/09/2016
* @param game : the running game
* @param object : the object to be placed in a certain location
* @param id : the id of the space where that object may be located
* @return Status : error control
*/

STATUS game_set_object_location(Game* game, Object* object, Id id);

/**
* @brief It adds an space to the incoming game
* @author Francisco Vicente
* @date 23/09/2016
* @param game : the running game
* @param space : the space to be added
* @return Status: error control
*/

STATUS game_add_space(Game* game, Space* space);

/**
* @brief It gets a space of the game as a pointer from its id.
* @author Francisco Vicente
* @date 23/09/2016
* @param game : the running game
* @param id : the id of space to be returned 
* @return Space : the requested space as a pointer
*/

Space* game_get_space(Game* game, Id id);

/**
* @brief It returns the id of an space of the game in a concrete location.
* @author Francisco Vicente
* @date 23/09/2016
* @param game : the running game
* @param position : the position of the space which id may be returned
* @return Id : the id of the space at the incoming position.
*/

Id game_get_space_id_at(Game* game, int position);

/**
* @brief It adds an object to the incoming game. It also initializes the location 
* of the object, placing it on the first space. Therefore, game_load_spaces
* must be called before game_load_objects.
* @author Francisco Vicente
* @date 17/10/2016
* @param game : the running game
* @param object : the objct to be added
* @return Status : error control
*/

STATUS game_add_object(Game* game, Object* object);

/**
* @brief It returns the id of an object of the game in a concrete location.
* @author Andres Salas
* @date 17/10/2016
* @param game : the running game
* @param position : the position of the object which id may be returned
* @return Id : the id of the object at the incoming position
*/

Id game_get_object_id_at(Game* game, int position);

/**
* @brief It gets the pointer of an object in a game from its id.
* @author Francisco Vicente
* @date 30/10/2016
* @param game : the running game
* @param id : identifier of the object to be returned.
* @return Object : the pointer of the object whose id is the one in the input
*/

Object* game_get_object_pointer(Game* game, Id id);

/*STATUS game_add_link_spaces(Game* game, Link* link);*/

/**
* @brief It gets the pointer of a link in a gema from its id
* @author Lucia Colmenarejo
* @date 12/12/2016
* @param game : the running game
* @param id : identifier of the link to be returned.
* @return Link : the pointer of the link whose id is the one in the input
*/

Link* game_get_link(Game* game, Id id);

/**
* @brief It adds a link to space
* @author Andres Salas
* @date 17/10/2016
* @param game : the running game
* @param link : the link to add
* @return Status : error control
*/

STATUS game_add_link(Game* game, Link* link);

/**
* @brief It prints the objects in the inventory.
* @author Maria Barroso
* @date 24/11/2016
* @param game : the running game
* @return STATUS : error control
*/

STATUS game_print_objects_in_inventory(Game* game);
#endif
