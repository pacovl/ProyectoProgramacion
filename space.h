
 /**
 * @brief It implements a space
 * @file space.h
 * @author Andres Salas, Francisco Vicente, Maria Barroso y Lucia Colmenarejo
 * @version 1.0
 * @date 23-09-2016
 */

#ifndef SPACE_H
#define SPACE_H

#include "object.h" /*types*/
#include "set.h"
#include "link.h"

 /**
 * @brief Definition of space structure
 */
typedef struct _Space Space; /*<!Definition of the space structure*/

/*** Definition of constant values ***/

 /**
 * @brief Definition of macro MAX_SPACES
 */
#define MAX_SPACES 10000 /*maximun number of spaces*/

 /**
 * @brief Definition of macro MAX_ROWS
 */
#define MAX_ROWS 3 /*lines of the gdesc*/

 /**
 * @brief Definition of macro MAX_COLUMNS
 */
#define MAX_COLUMNS 8 /*lenght of each line of the gdesc*/


/*** Definition of public functions ***/

/**
* @brief It creates a space
* @author Lucia Colmenarejo
* @date 23-09-2016
* @param id: user identity
* @return Space : the space created by the identity
*/
Space* space_create(Id id);

/**
* @brief It destroys a space
* @author Francisco Vicente
* @date 23-09-2016
* @param space : the space to be destroyed
* @return STATUS : returns Okey/Error
*/
STATUS space_destroy(Space* space);

/**
* @brief It names the space
* @author Andres Salas
* @date 23-09-2016
* @param space : the space to be named
* @param name : the wanted name for the space
* @return STATUS : it returns Okey/Error
*/
STATUS space_set_name(Space* space, char* name);

/**
* @brief It sets the iluminated field in a space 
* @author Francisco Vicente
* @date 1-12-2016
* @param space : the space whose iluminated state we want
* @param state : the state - TRUE (iluminated) or FALSE (not iluminated)
* @return STATUS : error control
*/
STATUS space_set_iluminated(Space* space, BOOL state);

/**
* @brief It set the graphic description of a space
* @author Maria Barroso
* @date 23-09-2016
* @param space : the space to get the graphic description
* @param gdesc1 : the wanted gdesc for the space(row 1)
* @param gdesc2 : the wanted gdesc for the space(row 2)
* @param gdesc3 : the wanted gdesc for the space(row 3)
* @return STATUS : it returns Okey/Error
*/
STATUS space_set_gdesc(Space* space, char* gdesc1, char* gdesc2, char* gdesc3);

/**
* @brief It sets the description of the space.
* @author Francisco Vicente
* @date 12-11-2016
* @param space : the space we want to set
* @param description : the description we want to set
* @return STATUS : it returns Okey/Error
*/
STATUS space_set_description(Space* space, char* description);

/**
* @brief It sets the extra description in a space 
* @author Francisco Vicente
* @date 1-12-2016
* @param space : the space whose extra desc may be set
* @param extraDesc : the extra description we want to set
* @return STATUS : error control
*/
STATUS space_set_extraDesc(Space* space, char* extraDesc);

/**
* @brief It sets the north point in the given space
* @author Lucia Colmenarejo
* @date 23-09-2016
* @param space : the space where the north point is set
* @param link : The link which will become the north point in the space
* @return STATUS : it returns Okey/Error
*/
STATUS space_set_north(Space* space, Link* link);

/**
* @brief It sets the south point in the given space
* @author Francisco Vicente
* @date 23-09-2016
* @param space : the space where the south point is set
* @param link : The link which will become the south point in the space
* @return STATUS : it returns Okey/Error
*/
STATUS space_set_south(Space* space, Link* link);

/**
* @brief It sets the east point in the given space
* @author Andres Salas
* @date 23-09-2016
* @param space : the space where the east point is set
* @param link : The link which will become the east point in the space
* @return STATUS : it returns Okey/Error
*/
STATUS space_set_east(Space* space, Link* link);

/**
* @brief It sets the west point in the given space
* @author Maria Barroso
* @date 23-09-2016
* @param space : the space where the west point is set
* @param link : The link which will become the west point in the space
* @return STATUS : it returns Okey/Error
*/
STATUS space_set_west(Space* space, Link* link);

/**
* @brief It sets the up direction in a space 
* @author Francisco Vicente
* @date 1-12-2016
* @param space : the space whose up direction may be set
* @return STATUS : error control
*/
STATUS space_set_up(Space* space, Link* link);

/**
* @brief It sets the down direction in a space 
* @author Francisco Vicente
* @date 1-12-2016
* @param space : the space whose down direction may be set
* @return STATUS : error control
*/
STATUS space_set_down(Space* space, Link* link);

/**
* @brief it adds an object in the given space
* @author Lucia Colmenarejo
* @date 23-09-2016
* @param space : the given space
* @param object : the object to be added on that space 
* @return STATUS : it returns Okey/Error
*/
STATUS space_add_object(Space* space, Object* object);

STATUS space_add_object_id(Space* space, Id obj_id);

/**
* @brief it deletes a certain object which is on the given space, in case it exists.
* @author Andres Salas
* @date 7-10-2016
* @param space : the space from which the object will be deleted
* @param object : the object to be removed from that space
* @return STATUS : it returns Okey/Error
*/
STATUS space_delete_object(Space* space, Object* object);

/**
* @brief It searches for the user who has created a space
* @author Maria Barroso
* @date 12-11-2016
* @param space : the space where the user is serached
* @return Id : it returns the user who has created a space
*/
Id space_get_id(Space* space);

/**
* @brief It searches for the name of a space
* @author Lucia Colmenarejo
* @date 23-09-2016
* @param space : the space where the name is searched
* @return Char : it returns the name of the incoming space
*/
const char* space_get_name(Space* space);

/**
* @brief It gets the iluminated field in a space 
* @author Francisco Vicente
* @date 1-12-2016
* @param space : the space whose iluminated state may be returned
* @return BOOL : the state - TRUE (iluminated) or FALSE (not iluminated)
*/
BOOL space_get_iluminated(Space* space);

/**
* @brief It searches for the name of a space
* @author Andres Salas
* @date 23-09-2016
* @param space : the space where the name is searched
* @param row : the line to be returned
* @return Char : it returns the gdesc of the incoming space
*/
const char* space_get_gdesc(Space* space, int row);

/**
* @brief It gets the extra description in a space 
* @author Francisco Vicente
* @date 1-12-2016
* @param space : the space whose desc may be returned
* @return string : the extra description
*/
const char* space_get_extraDesc(Space* space);

/**
* @brief It searches for the north point in a space
* @author Francismo Vivente
* @date 23-09-2016
* @param space : the space where the north point is searched
* @return Link* : it returns the link which is the north point
*/
Link * space_get_north(Space* space);

/**
* @brief It searches for the south point in a space
* @author María Barroso
* @date 23-09-2016
* @param space : the space where the south point is searched
* @return Link* : it returns the link which is the south point
*/
Link * space_get_south(Space* space);

/**
* @brief It searches for the east point in a space
* @author María Barroso
* @date 23-09-2016
* @param space : the space where the east point is searched
* @return Link* : it returns the link which is the east point
*/
Link * space_get_east(Space* space);

/**
* @brief It searches for the west point in a space
* @author María Barroso
* @date 23-09-2016
* @param space : the space where the west point is searched
* @return Link* : it returns the link which is the west point
*/
Link * space_get_west(Space* space);

/**
* @brief It gets the up direction in a space 
* @author Francisco Vicente
* @date 1-12-2016
* @param space : the space whose up direction may be returned
* @return link : the requested link
*/
Link * space_get_up(Space* space);

/**
* @brief It gets the down direction in a space 
* @author Francisco Vicente
* @date 1-12-2016
* @param space : the space whose down direction may be returned
* @return link : the requested link
*/
Link * space_get_down(Space* space);

/**
* @brief It returns the set of objects which are in a space
* @author Andres Salas
* @date 14-10-2016
* @param space : the space where the the object is  searched
* @return Set : the set of objects in that space
*/
Set* space_get_objects(Space* space);

/**
* @brief It returns the description of the space
* @author Francisco Vicente
* @date 12/11/2016
* @param space : the space whose description may be returned
* @return Char : the description
*/
const char* space_get_description(Space* space);

/**
* @brief It tells whether a certain object is in a space or not 
* @author Andres Salas
* @date 14-10-2016
* @param space : the space where the object is searched
* @param object : the object to be searched
* @return BOOL : TRUE (the object is in that space) or FALSE (it is not)
*/
BOOL space_is_object(Space* space, Object *object);

/**
* @brief It tells whether a space has a link in the north direction or not 
* @author Francisco Vicente
* @date 1-12-2016
* @param space : the space whose link may be checked
* @return BOOL : TRUE (when the link exists) or FALSE (it does not)
*/
BOOL space_is_north_linked(Space* space);

/**
* @brief It tells whether a space has a link in the south direction or not 
* @author Francisco Vicente
* @date 1-12-2016
* @param space : the space whose link may be checked
* @return BOOL : TRUE (when the link exists) or FALSE (it does not)
*/
BOOL space_is_south_linked(Space* space);

/**
* @brief It tells whether a space has a link in the east direction or not 
* @author Francisco Vicente
* @date 1-12-2016
* @param space : the space whose link may be checked
* @return BOOL : TRUE (when the link exists) or FALSE (it does not)
*/
BOOL space_is_east_linked(Space* space);

/**
* @brief It tells whether a space has a link in the west direction or not 
* @author Francisco Vicente
* @date 1-12-2016
* @param space : the space whose link may be checked
* @return BOOL : TRUE (when the link exists) or FALSE (it does not)
*/
BOOL space_is_west_linked(Space* space);

/**
* @brief It tells whether a space has a link in the up direction or not 
* @author Francisco Vicente
* @date 1-12-2016
* @param space : the space whose link may be checked
* @return BOOL : TRUE (when the link exists) or FALSE (it does not)
*/
BOOL space_is_up_linked(Space* space);

/**
* @brief It tells whether a space has a link in the down direction or not 
* @author Francisco Vicente
* @date 1-12-2016
* @param space : the space whose link may be checked
* @return BOOL : TRUE (when the link exists) or FALSE (it does not)
*/
BOOL space_is_down_linked(Space* space);

/**
* @brief It tells whether the north link is open or not 
* @author Francisco Vicente
* @date 1-12-2016
* @param space : the space whose north link may be checked
* @return BOOL : TRUE (when the link is open) or FALSE (it is not)
*/
BOOL space_is_open_north(Space* space);

/**
* @brief It tells whether the south link is open or not 
* @author Francisco Vicente
* @date 1-12-2016
* @param space : the space whose south link may be checked
* @return BOOL : TRUE (when the link is open) or FALSE (it is not)
*/
BOOL space_is_open_south(Space* space);

/**
* @brief It tells whether the east link is open or not 
* @author Francisco Vicente
* @date 1-12-2016
* @param space : the space whose east link may be checked
* @return BOOL : TRUE (when the link is open) or FALSE (it is not)
*/
BOOL space_is_open_east(Space* space);

/**
* @brief It tells whether the west link is open or not 
* @author Francisco Vicente
* @date 1-12-2016
* @param space : the space whose west link may be checked
* @return BOOL : TRUE (when the link is open) or FALSE (it is not)
*/
BOOL space_is_open_west(Space* space);

/**
* @brief It tells whether the up link is open or not 
* @author Francisco Vicente
* @date 1-12-2016
* @param space : the space whose up link may be checked
* @return BOOL : TRUE (when the link is open) or FALSE (it is not)
*/
BOOL space_is_open_up(Space* space);

/**
* @brief It tells whether the down link is open or not 
* @author Francisco Vicente
* @date 1-12-2016
* @param space : the space whose down link may be checked
* @return BOOL : TRUE (when the link is open) or FALSE (it is not)
*/
BOOL space_is_open_down(Space* space);

/**
* @brief It prints the description of the space
* @author Francisco Vicente
* @date 14-10-2016
* @param space : the space whose desc may be printed
* @return STATUS : error control
*/
STATUS space_print_description(Space* space);

/**
* @brief It prints the extra description of the space
* @author Francisco Vicente
* @date 1-12-2016
* @param space : the space whose extra desc may be printed
* @return STATUS : error control
*/
STATUS space_print_extraDesc(Space* space);

/**
* @brief It prints a given space in the standar output
* @author Lucia Colmenarejo
* @date 23-09-2016
* @param space : the space we will be printed
* @return STATUS : error control
*/
STATUS space_print(Space* space);

#endif
