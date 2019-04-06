
 /**
 * @brief It implements a space
 * @file space.c
 * @author Andres Salas, Francisco Vicente, Maria Barroso y Lucia Colmenarejo
 * @version 1.0
 * @date 23-09-2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "space.h"

/**
 * @brief Definition of the data structure
 */

struct _Space {
    Id id; /*!<identifier of each space*/
    char name[WORD_SIZE + 1]; /*!<name of the space*/
    
    Link* north; /*!<link of the space in the north direction*/
    Link* south; /*!<link of the space in the south direction*/
    Link* east;  /*!<link of the space in the east direction*/
    Link* west;  /*!<link of the space in the west direction*/
    Link* up; /*!<link of the space in the up direction*/
    Link* down; /*!<link of the space in the down direction*/

    Set* objects; /*!<Set of objects which are in the space*/

    char gdesc[MAX_ROWS][MAX_COLUMNS]; /*!<graphic description of each spaces*/
    char description[DESC_SIZE]; /*!<Written description of the space*/
    char extraDesc[DESC_SIZE]; /*!<Extra description of the space*/
    
    BOOL iluminated; /*!<It tells whether a space is iluminated or not*/
};


/* Space interface implementation */

/**
* @brief It creates a space
* @author Lucia Colmenarejo
* @date 23-09-2016
* @param id: user identity
* @return Space : the space created by the identity
*/
Space* space_create(Id id) {
    Space* newSpace = NULL;
    int i;
    if (id == NO_ID)
        return NULL;

    newSpace = (Space *)malloc(sizeof(Space));
    if (newSpace == NULL)
        return NULL;

    newSpace->id = id;
    newSpace->name[0] = '\0';

    newSpace->north = NULL;
    newSpace->south = NULL;
    newSpace->east = NULL;
    newSpace->west = NULL;
    newSpace->up = NULL;
    newSpace->down = NULL;

    newSpace->objects = set_create();
    if(!newSpace->objects)
        return NULL;

    /*As our implementation of gdes is a bidimentional array, the initialization
    is requiered for each row*/
    for(i = 0; i < MAX_ROWS; i++)
        newSpace->gdesc[i][0] = '\0';
   
    newSpace->description[0] = '\0';
    newSpace->extraDesc[0] = '\0';
    
    newSpace->iluminated = FALSE; /*apagado por defecto ???????????*/

    return newSpace;
}

/**
* @brief It destroys a space
* @author Francisco Vicente
* @date 23-09-2016
* @param space : the space to be destroyed
* @return STATUS : returns Okey/Error
*/
STATUS space_destroy(Space* space) {
    if (!space) 
        return ERROR;

    link_destroy(space->north);
    link_destroy(space->south);
    link_destroy(space->east);
    link_destroy(space->west);

    if(set_destroy(space->objects) == ERROR)
        return ERROR;
        
    free(space);
    space = NULL;
    
    return OK;
}


/**
* @brief It names the space
* @author Andres Salas
* @date 23-09-2016
* @param space : the space to be named
* @param name : the wanted name for the space
* @return STATUS : it returns Okey/Error
*/
STATUS space_set_name(Space* space, char* name) {
    if (!space || !name) {
        return ERROR;
    }
    if (!strcpy(space->name, name)) {
        return ERROR;
    }
    return OK;
}

/**
* @brief It sets the iluminated field in a space 
* @author Francisco Vicente
* @date 1-12-2016
* @param space : the space whose iluminated state we want
* @param state : the state - TRUE (iluminated) or FALSE (not iluminated)
* @return STATUS : error control
*/
STATUS space_set_iluminated(Space* space, BOOL state) {
    if(!space)
        return ERROR;
    
    space->iluminated = state;
    
    return OK;
}

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
STATUS space_set_gdesc(Space* space, char* gdesc1, char* gdesc2, char* gdesc3) {

    if (!space || !gdesc1 || !gdesc2 || !gdesc3)
        return ERROR;
    
    if (!strcpy((space->gdesc)[0], gdesc1)) {
        return ERROR;
    }
    if (!strcpy((space->gdesc)[1], gdesc2)) {
        return ERROR;
    }
    if (!strcpy((space->gdesc)[2], gdesc3)) {
        return ERROR;
    }
    return OK;
}

/**
* @brief It sets the description of the space.
* @author Francisco Vicente
* @date 12-11-2016
* @param space : the space we want to set
* @param description : the description we want to set
* @return STATUS : it returns Okey/Error
*/
STATUS space_set_description(Space* space, char* description){
    if (!space || !description) 
        return ERROR;

    if (!strcpy(space->description, description)) 
        return ERROR;
    
    return OK;
}

/**
* @brief It sets the extra description in a space 
* @author Francisco Vicente
* @date 1-12-2016
* @param space : the space whose extra desc may be set
* @param extraDesc : the extra description we want to set
* @return STATUS : error control
*/
STATUS space_set_extraDesc(Space* space, char* extraDesc) {
    if(!space || !extraDesc)
        return ERROR;
        
    if(!strcpy(space->extraDesc, extraDesc))
        return ERROR;
        
    return OK;
}

/**
* @brief It sets the north point in the given space
* @author Lucia Colmenarejo
* @date 23-09-2016
* @param space : the space where the north point is set
* @param link : The link which will become the north point in the space
* @return STATUS : it returns Okey/Error
*/
STATUS space_set_north(Space* space, Link* link) {
    if (!space || !link) {
        return ERROR;
    }
    space->north = link;
    return OK;
}


/**
* @brief It sets the south point in the given space
* @author Francisco Vicente
* @date 23-09-2016
* @param space : the space where the south point is set
* @param link : The link which will become the south point in the space
* @return STATUS : it returns Okey/Error
*/
STATUS space_set_south(Space* space, Link* link) {
    if (!space || !link) {
        return ERROR;
    }
    space->south = link;
    return OK;
}

/**
* @brief It sets the east point in the given space
* @author Andres Salas
* @date 23-09-2016
* @param space : the space where the east point is set
* @param link : The link which will become the east point in the space
* @return STATUS : it returns Okey/Error
*/
STATUS space_set_east(Space* space, Link* link) {
    if (!space || !link) {
        return ERROR;
    }
    space->east = link;
    return OK;
}

/**
* @brief It sets the west point in the given space
* @author Maria Barroso
* @date 23-09-2016
* @param space : the space where the west point is set
* @param link : The link which will become the west point in the space
* @return STATUS : it returns Okey/Error
*/
STATUS space_set_west(Space* space, Link* link) {
    if (!space || !link) {
        return ERROR;
    }
    space->west = link;
    return OK;
}

/**
* @brief It sets the up direction in a space 
* @author Francisco Vicente
* @date 1-12-2016
* @param space : the space whose up direction may be set
* @return STATUS : error control
*/
STATUS space_set_up(Space* space, Link* link) {
    if(!space || !link)
        return ERROR;
        
    space->up = link;
    return OK;
}

/**
* @brief It sets the down direction in a space 
* @author Francisco Vicente
* @date 1-12-2016
* @param space : the space whose down direction may be set
* @return STATUS : error control
*/
STATUS space_set_down(Space* space, Link* link) {
    if(!space || !link)
        return ERROR;
    
    space->down = link;
    return OK;
}

/**
* @brief it adds an object in the given space
* @author Lucia Colmenarejo
* @date 23-09-2016
* @param space : the given space
* @param object : the object to be added on that space 
* @return STATUS : it returns Okey/Error
*/
STATUS space_add_object(Space* space, Object* object) {
    if (!space || !object) {
        return ERROR;
    }
    
    return set_add(space->objects, object_get_id(object));
}

STATUS space_add_object_id(Space* space, Id obj_id) {
    if (!space || obj_id == NO_ID) {
        return ERROR;
    }
    
    return set_add(space->objects, obj_id);
}


/**
* @brief it deletes a certain object which is on the given space, in case it exists.
* @author Andres Salas
* @date 7-10-2016
* @param space : the space from which the object will be deleted
* @param object : the object to be removed from that space
* @return STATUS : it returns Okey/Error
*/
STATUS space_delete_object(Space* space, Object* object){
    if(!space || !object){
        return ERROR;
    }
    
    return set_delete(space->objects, object_get_id(object));
}

/**
* @brief It searches for the user who has created a space
* @author Maria Barroso
* @date 12-11-2016
* @param space : the space where the user is serached
* @return Id : it returns the user who has created a space
*/
Id space_get_id(Space* space) {
    if (!space) {
        return NO_ID;
    }
    return space->id;
}

/**
* @brief It searches for the name of a space
* @author Lucia Colmenarejo
* @date 23-09-2016
* @param space : the space where the name is searched
* @return Char : it returns the name of the incoming space
*/
const char * space_get_name(Space* space) {
    if (!space) {
        return NULL;
    }
    return space->name;
}

/**
* @brief It gets the iluminated field in a space 
* @author Francisco Vicente
* @date 1-12-2016
* @param space : the space whose iluminated state may be returned
* @return BOOL : the state - TRUE (iluminated) or FALSE (not iluminated)
*/
BOOL space_get_iluminated(Space* space) {
    if(!space)
        return FALSE;
        
    return space->iluminated;
}

/**
* @brief It searches for the name of a space
* @author Andres Salas
* @date 23-09-2016
* @param space : the space where the name is searched
* @param row : the line to be returned
* @return Char : it returns the gdesc of the incoming space
*/
const char* space_get_gdesc(Space* space, int row) {
    if (!space || row < 1 || row > MAX_ROWS) {
        return NULL;
    }
    return (space->gdesc)[row - 1];
}

/**
* @brief It gets the extra description in a space 
* @author Francisco Vicente
* @date 1-12-2016
* @param space : the space whose desc may be returned
* @return string : the extra description
*/
const char* space_get_extraDesc(Space* space) {
    if(!space)
        return NULL;
        
    return space->extraDesc;
}

/**
* @brief It searches for the north point in a space
* @author Francismo Vivente
* @date 23-09-2016
* @param space : the space where the north point is searched
* @return Link* : it returns the link which is the north point
*/
Link* space_get_north(Space* space) {
   if (!space) {
        return NULL;
    }
    return space->north;
}

/**
* @brief It searches for the south point in a space
* @author María Barroso
* @date 23-09-2016
* @param space : the space where the south point is searched
* @return Link* : it returns the link which is the south point
*/
Link* space_get_south(Space* space) {
    if (!space) {
        return NULL;
    }
    return space->south;
}

/**
* @brief It searches for the east point in a space
* @author María Barroso
* @date 23-09-2016
* @param space : the space where the east point is searched
* @return Link* : it returns the link which is the east point
*/
Link* space_get_east(Space* space) {
    if (!space) {
        return NULL;
    }
    return space->east;
}

/**
* @brief It searches for the west point in a space
* @author María Barroso
* @date 23-09-2016
* @param space : the space where the west point is searched
* @return Link* : it returns the link which is the west point
*/
Link* space_get_west(Space* space) {
    if (!space) {
        return NULL;
    }
    return space->west;
}

/**
* @brief It gets the up direction in a space 
* @author Francisco Vicente
* @date 1-12-2016
* @param space : the space whose up direction may be returned
* @return link : the requested link
*/
Link* space_get_up(Space* space) {
    if(!space)
        return NULL;
    
    return space->up;
}

/**
* @brief It gets the down direction in a space 
* @author Francisco Vicente
* @date 1-12-2016
* @param space : the space whose down direction may be returned
* @return link : the requested link
*/
Link* space_get_down(Space* space) {
    if(!space)
        return NULL;
    
    return space->down;
}

/**
* @brief It returns the set of objects which are in a space
* @author Andres Salas
* @date 14-10-2016
* @param space : the space where the the object is searched
* @return Set : the set of objects in that space
*/
Set* space_get_objects(Space* space) {
    if (!space) {
        return NULL;
    }
    return space->objects;
}


/**
* @brief It returns the description of the space
* @author Francisco Vicente
* @date 12/11/2016
* @param space : the space whose description may be returned
* @return Char : the description
*/
const char* space_get_description(Space* space){
    if(!space)
        return NULL;
    return space->description;
}

/**
* @brief It tells whether a certain object is in a space or not 
* @author Andres Salas
* @date 14-10-2016
* @param space : the space where the object is searched
* @param object : the object to be searched
* @return BOOL : TRUE (the object is in that space) or FALSE (it is not)
*/
BOOL space_is_object(Space* space, Object *object){
    if(!space || !object)
        return FALSE;
        
    return set_search(space->objects, object_get_id(object));
}

/**
* @brief It tells whether a space has a link in the north direction or not 
* @author Francisco Vicente
* @date 1-12-2016
* @param space : the space whose link may be checked
* @return BOOL : TRUE (when the link exists) or FALSE (it does not)
*/
BOOL space_is_north_linked(Space* space){
	if(!space)
        return FALSE;
        
    if(!space->north)
        return FALSE;
    return TRUE;
}

/**
* @brief It tells whether a space has a link in the south direction or not 
* @author Francisco Vicente
* @date 1-12-2016
* @param space : the space whose link may be checked
* @return BOOL : TRUE (when the link exists) or FALSE (it does not)
*/
BOOL space_is_south_linked(Space* space){
	if(!space)
        return FALSE;
        
    if(!space->south)
        return FALSE;
    return TRUE;
}

/**
* @brief It tells whether a space has a link in the east direction or not 
* @author Francisco Vicente
* @date 1-12-2016
* @param space : the space whose link may be checked
* @return BOOL : TRUE (when the link exists) or FALSE (it does not)
*/
BOOL space_is_east_linked(Space* space) {
	if(!space)
        return FALSE;
        
    if(!space->east)
        return FALSE;
    return TRUE;
}

/**
* @brief It tells whether a space has a link in the west direction or not 
* @author Francisco Vicente
* @date 1-12-2016
* @param space : the space whose link may be checked
* @return BOOL : TRUE (when the link exists) or FALSE (it does not)
*/
BOOL space_is_west_linked(Space* space) {
	if(!space)
        return FALSE;
        
    if(!space->west)
        return FALSE;
    return TRUE;
}

/**
* @brief It tells whether a space has a link in the up direction or not 
* @author Francisco Vicente
* @date 1-12-2016
* @param space : the space whose link may be checked
* @return BOOL : TRUE (when the link exists) or FALSE (it does not)
*/
BOOL space_is_up_linked(Space* space) {
    if(!space)
        return FALSE;
        
    if(!space->up)
        return FALSE;
    return TRUE;
}

/**
* @brief It tells whether a space has a link in the down direction or not 
* @author Francisco Vicente
* @date 1-12-2016
* @param space : the space whose link may be checked
* @return BOOL : TRUE (when the link exists) or FALSE (it does not)
*/
BOOL space_is_down_linked(Space* space) {
    if(!space)
        return FALSE;
    
    if(!space->down)
        return FALSE;
    return TRUE;
}

/**
* @brief It tells whether the north link is open or not 
* @author Francisco Vicente
* @date 1-12-2016
* @param space : the space whose north link may be checked
* @return BOOL : TRUE (when the link is open) or FALSE (it is not)
*/
BOOL space_is_open_north(Space* space) {
	if(!space)
		return FALSE;

	return link_get_oorc(space->north);
}

/**
* @brief It tells whether the south link is open or not 
* @author Francisco Vicente
* @date 1-12-2016
* @param space : the space whose south link may be checked
* @return BOOL : TRUE (when the link is open) or FALSE (it is not)
*/
BOOL space_is_open_south(Space* space) {
	if(!space)
		return FALSE;

	return link_get_oorc(space->south);
}

/**
* @brief It tells whether the east link is open or not 
* @author Francisco Vicente
* @date 1-12-2016
* @param space : the space whose east link may be checked
* @return BOOL : TRUE (when the link is open) or FALSE (it is not)
*/
BOOL space_is_open_east(Space* space) {
	if(!space)
		return FALSE;

	return link_get_oorc(space->east);
}

/**
* @brief It tells whether the west link is open or not 
* @author Francisco Vicente
* @date 1-12-2016
* @param space : the space whose west link may be checked
* @return BOOL : TRUE (when the link is open) or FALSE (it is not)
*/
BOOL space_is_open_west(Space* space) {
	if(!space)
		return FALSE;

	return link_get_oorc(space->west);
}

/**
* @brief It tells whether the up link is open or not 
* @author Francisco Vicente
* @date 1-12-2016
* @param space : the space whose up link may be checked
* @return BOOL : TRUE (when the link is open) or FALSE (it is not)
*/
BOOL space_is_open_up(Space* space) {
    if(!space)
        return FALSE;
    
    return link_get_oorc(space->up);
}

/**
* @brief It tells whether the down link is open or not 
* @author Francisco Vicente
* @date 1-12-2016
* @param space : the space whose down link may be checked
* @return BOOL : TRUE (when the link is open) or FALSE (it is not)
*/
BOOL space_is_open_down(Space* space) {
    if(!space)
        return FALSE;
    
    return link_get_oorc(space->down);
}

/**
* @brief It prints the description of the space
* @author Francisco Vicente
* @date 14-10-2016
* @param space : the space whose desc may be printed
* @return STATUS : error control
*/
STATUS space_print_description(Space* space){
	if(! space)
		return ERROR;
	
	fprintf(stdout,"%s\n", space->description);
	return OK;
}

/**
* @brief It prints the extra description of the space
* @author Francisco Vicente
* @date 1-12-2016
* @param space : the space whose extra desc may be printed
* @return STATUS : error control
*/
STATUS space_print_extraDesc(Space* space){
	if(! space)
		return ERROR;
	
	fprintf(stdout,"%s\n", space->extraDesc);
	return OK;
}

/**
* @brief It prints a given space in the standar output
* @author Lucia Colmenarejo
* @date 23-09-2016
* @param space : the space which will be printed
* @return STATUS : error control
*/
STATUS space_print(Space* space) {
    int i;
  
    if (!space)
        return ERROR;

    fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", space->id, space->name);
    fprintf(stdout, "-->North\n");
    link_print(space->north);
    fprintf(stdout, "-->South\n");
    link_print(space->south);
    fprintf(stdout, "-->East\n");
    link_print(space->east);
    fprintf(stdout, "-->West\n");
    link_print(space->west);
    fprintf(stdout, "-->Up\n");
    link_print(space->up);
    fprintf(stdout, "-->Down\n");
    link_print(space->down);
    
    fprintf(stdout, "---> Objects in the space:\n");
    set_print(space->objects);
    
    
    fprintf(stdout, "--> Graphic description:\n");
    for(i = 0; i < MAX_ROWS; i++) {
            fprintf(stdout, "%s\n", (space->gdesc)[i]);
    }

    fprintf(stdout, "--> Description: ");
    space_print_description(space);
    fprintf(stdout, "--> Extra description: ");
    space_print_extraDesc(space);
    
    return OK;
}
