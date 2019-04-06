
/**
 * @brief It implements the game functions that use spaces.
 * @file GameReader.h
 * @author Lucia Colmenarejo
 * @version 1.0
 * @date  2-09-2016
 */

#ifndef GAMEREADER_H
#define GAMEREADER_H

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


#endif
