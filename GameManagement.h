/**
 * @brief It implements the game functions that use spaces.
 * @file GameManagement.h
 * @author Lucia Colmenarejo
 * @version 1.0
 * @date  10-12-2016
 */
 
#ifndef GAMEMANAGEMENT_H
#define GAMEMANAGEMENT_H

#include "game.h" /*command.h*/


/**
* @brief   It loads in the incoming game the spaces stored in a file.
* @author Lucia Colmenarejo
* @date  23-09-2016
* @param game : the running game
* @param filename : the file where the spaces are stored (spaces.dat in this case)
* @return  STATUS : error control
*/
STATUS game_load_spaces(Game* game, char* filename);


/**
* @brief  It loads in the incoming game the objects stored in a file.
* @author Lucia Colmenarejo
* @date  17-10-2016
* @param game : the running game
* @param filename : the file where the objects are stored (objects.dat in this case)
* @return  STATUS : error control
*/
STATUS game_load_objects(Game* game, char* filename);

/**
* @brief It loads in the incoming game the links stored in a file.
* @author Lucia Colmenarejo
* @date  11-11-2016
* @param game : the running game
* @param filename : the file where the objects are stored (objects.dat in this case)
* @return  STATUS : error control
*/
STATUS game_load_links(Game* game, char* filename);

/*Funciones de guardado*/


STATUS game_save(Game *game, char* name);

/**
* @brief It rewrites the spaces of a file
* @author Lucia Colmenarejo
* @date  11-12-2016
* @param game : the running game
* @param name : the file where the sapces are rewrites 
* @return  STATUS : error control
*/

STATUS game_save_spaces(Game *game, char* name);


/**
* @brief It rewrites the objects of a file
* @author Lucia Colmenarejo
* @date  11-12-2016
* @param game : the running game
* @param name : the file where the sapces are rewrites 
* @return  STATUS : error control
*/

STATUS game_save_objects(Game *game, char* name);

/**
* @brief It rewrites the links of a file
* @author Lucia Colmenarejo
* @date  11-12-2016
* @param game : the running game
* @param name : the file where the sapces are rewrites 
* @return  STATUS : error control
*/
STATUS game_save_links(Game *game, char* name);

/**
* @brief It loads the game from a file
* @author María Barroso
* @date  11-12-2016
* @param game : the running game
* @param name : the file where the game are rewrites 
* @return  STATUS : error control
*/
STATUS game_load(Game *game, char* name);

#endif