
/**
 * @brief It implements the object interface.
 * @file object.c
 * @author Andres Salas
 * @version 1.0
 * @date 02-09-2016
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "object.h"
#include "set.h"

/**
 * @brief Definition of the data structure
 */
 
struct _Object {
    Id id; /*!<Identifier of each object*/
    char name[WORD_SIZE + 1]; /*!<Name of the object*/
    char description[DESC_SIZE + 1]; /*!<Description of the object*/
    BOOL portable; /*!<It is portable or not*/
    BOOL moved; /*!<It is moved or not*/
    BOOL hidden; /*!<It is hidden or not*/
    Set *opens; /*!<It opens ids or not*/
    BOOL lights_up; /*!<It is iluminated or not*/
    BOOL activated; /*!<It is activated or not*/
    char aditDesc[DESC_SIZE]; /*!<Extra description of the object*/
};

/* Object interface implementation */

/**
* @brief It creates an object with a given id.
* @author Andres Salas
* @date 23-09-2016
* @param id: object identity
* @return Object : the object structure with its id
*/
Object* object_create(Id id) {
    Object *object = NULL;
    if (id == NO_ID) return NULL;
    
    object = (Object *)malloc(sizeof(Object));
    if (!object) {
        return NULL;
    }
    
    object->id = id;
    object->name[0] = '\0';
    object->description[0] = '\0';
    object->portable = FALSE;
    object->moved = FALSE;
    object->hidden = FALSE;
    object->lights_up = FALSE;
    object->activated = FALSE;
    object->opens = set_create();
    if(object->opens == NULL){
        free(object);
        return NULL;
    }
    object->aditDesc[0] = '\0';
    return object;
}

/**
* @brief It destroys an space and frees its memory.
* @author Andres Salas
* @date 23-09-2016
* @param object: the object to be destroyed
* @return STATUS: error control
*/
STATUS object_destroy(Object *object){
	if(!object) return ERROR;
	
	set_destroy(object->opens);
	free(object);
	object = NULL;
	return OK;
}

/**
* @brief It sets the name of an object
* @author Andres Salas
* @date 23-09-2016
* @param object : the space whose name will be set
* @param name : the wanted name
* @return STATUS: error control
*/
STATUS object_set_name(Object* object, char* name) {
    if (!object || !name) {
        return ERROR;
    }
    
    if (!strcpy(object->name, name)) {
        return ERROR;
    }
    return OK;
}

/**
* @brief It gets the name of a given object.
* @author Andres Salas
* @date 23-09-2016
* @param object : the object whose name is got
* @return char* : the name of the given object
*/
const char* object_get_name(Object* object) {
    if (!object) {
        return NULL;
    }
    return object->name;
}

/**
* @brief It sets the description of an object.
* @author Andres Salas
* @date 23-09-2016
* @param object : the object whose description is got
* @param description : the wanted description
* @return STATUS : error control
*/
STATUS object_set_description(Object* object, char* description){
    if(!object || !description){
        return ERROR;
    }
    strcpy(object->description, description);
    return OK;
}

/**
* @brief It gets the description of an object.
* @author Andres Salas
* @date 12-11-2016
* @param object : the object whose description is got
* @return Char : the description of a certain object
*/
const char* object_get_description(Object* object){
    if(!object){
        return NULL;
    }
    return object->description;
}

/**
* @brief It gets the id of an object.
* @author Andres Salas
* @date 23-09-2016
* @param object : the object whose id is got
* @return Id: the id of a certain object
*/
Id object_get_id(Object* object) {
    if (!object) {
        return NO_ID;
    }
    return object->id;
}

/*Functions for portability structure field*/

/**
* @brief It gets the portability of an object
* @author Andres Salas
* @date 1-12-2016
* @param object : the object whose portability is got
* @return BOOL: the status of the portability
*/
BOOL object_get_portability(Object *object) {
    if(!object)
        return FALSE;
        
    return object->portable;
}

/**
* @brief It sets the portability of an object
* @author Andres Salas
* @date 1-12-2016
* @param object : the object whose portability will be set
* @param portable : the wanted portability
* @return STATUS: error control
*/
STATUS object_set_portability(Object *object, BOOL portable) {
    if(!object)
        return ERROR;
    
    object->portable = portable; 
    return OK;
}

/*Functions for movement structure field*/

/**
* @brief It gets the movement of an object
* @author Andres Salas
* @date 1-12-2016
* @param object : the object whose movement is got
* @return BOOL: the status of the movement
*/
BOOL object_get_movement(Object *object){
    if(!object)
        return FALSE;
    
    return object->moved;
}

/**
* @brief It sets the movement of an object
* @author Andres Salas
* @date 1-12-2016
* @param object : the object whose movement will be set
* @param moved : the wanted movement
* @return STATUS: error control
*/
STATUS object_set_movement(Object *object, BOOL moved){
    if(!object)
        return ERROR;
        
    object->moved = moved;
    return OK;
}

/*Functions for visibility structure field*/

/**
* @brief It gets the visibility of an object
* @author Andres Salas
* @date 1-12-2016
* @param object : the object whose visibility is got
* @return BOOL: the status of the visibility
*/
BOOL object_get_hidden(Object *object){
    if(!object)
        return FALSE;
    
    return object->hidden;
}

/**
* @brief It sets the visibility of an object
* @author Andres Salas
* @date 1-12-2016
* @param object : the object whose visibility will be set
* @param visibility: the wanted visibility
* @return STATUS: error control
*/
STATUS object_set_hidden(Object *object, BOOL hidden){
    if(!object)
        return ERROR;
        
    object->hidden = hidden;
    return OK;
}

/*Functions for opens structure field*/

/**
* @brief It gets the opens ids of an object
* @author Andres Salas
* @date 1-12-2016
* @param object : the object whose opens field is got
* @return Id: it returns the ids;
*/
Id *object_get_opens_ids(Object *object){
    int numids, i;
    Id* id = NULL;
    if(!object)
        return NULL;
    
    numids = set_get_num(object->opens);
    
    for(i = 0; i < numids; i++)
        id[i] = set_get_id_number(object->opens, i);
    
    return id;
}

/**
* @brief It gets the opens set of an object
* @author Andres Salas
* @date 1-12-2016
* @param object : the object whose opens field is got
* @return Set: it returns the set;
*/
Set *object_get_opens(Object *object){
    if(!object)
        return NULL;
    
    return object->opens;
}

/**
* @brief  it checks that an opens field of object is full
* @author Andres Salas
* @date 1-12-2016
* @param object : the object whose opens field will be studied
* @return BOOL: TRUE if it is full or an error FALSE other case.
*/
BOOL object_opens_is_full(Object *object){
    if(!object)
        return TRUE;

    return set_is_full(object->opens);
} 

/**
* @brief  it adds an id to the opens field
* @author Andres Salas
* @date 1-12-2016
* @param object : the object where we will add the id
* @param idaux: the id that we will add
* @return STATUS: error control
*/
STATUS object_add_opens(Object *object, Id idaux){
    
    if(!object || object_opens_is_full(object) == TRUE)
        return ERROR;
    
    return set_add(object->opens, idaux);
}

/**
* @brief  it deletes an id of the opens field
* @author Andres Salas
* @date 1-12-2016
* @param object : the object where we will delete the id
* @param idaux: the id that we will delete
* @return STATUS: error control
*/
STATUS object_delete_opens(Object *object, Id idaux){
    if(!object || idaux == NO_ID)
        return ERROR;
    
    return set_delete(object->opens, idaux);
}

/**
* @brief  it searchs an id in the opens field
* @author Andres Salas
* @date 1-12-2016
* @param object : the object where we will search
* @param idaux: the id that we will search
* @return BOOL: TRUE if it is or an error FALSE other case.
*/
BOOL object_search_id(Object *object, Id idaux){
    if(!object || idaux == NO_ID)
        return FALSE;
    
    return set_search(object->opens, idaux);
}

/*Functions for light-up structure field*/

/**
* @brief It gets the lights of an object
* @author Andres Salas
* @date 1-12-2016
* @param object : the object whose lights is got
* @return BOOL: the status of the lights
*/
BOOL object_get_lights(Object *object) {
    if(!object)
        return FALSE;
        
    return object->lights_up;
}

/**
* @brief It sets the lights of an object
* @author Andres Salas
* @date 1-12-2016
* @param object : the object whose lights will be set
* @param lights_up : the wanted lights
* @return STATUS: error control
*/
STATUS object_set_lights(Object *object, BOOL lights_up) {
    if(!object)
        return ERROR;
    
    object->lights_up = lights_up; 
    return OK;
}

/*Functions for activate structure field*/ 

/**
* @brief It gets the activate of an object
* @author Andres Salas
* @date 1-12-2016
* @param object : the object whose activate field is got
* @return BOOL: the status of the activate
*/
BOOL object_get_activate(Object *object) {
    if(!object)
        return FALSE;
        
    return object->activated;
}

/**
* @brief It sets the activate of an object
* @author Andres Salas
* @date 1-12-2016
* @param object : the object whose activate field will be set
* @param activated : the wanted activate field
* @return STATUS: error control
*/
STATUS object_set_activate(Object *object, BOOL activated) {
    if(!object)
        return ERROR;
    
    object->activated = activated; 
    return OK;
}

/**
* @brief It gets the extra description in an object 
* @author Maria Barroso
* @date 03-12-2016
* @param object : the object whose desc may be returned
* @return string : the extra description
*/
const char* object_get_aditDesc(Object * object){
    if(object == NULL)
        return NULL;
        
    return object->aditDesc;
}
/**
* @brief It sets the extra description in an object 
* @author Maria Barroso
* @date 02-12-2016
* @param object : the object whose extra desc may be set
* @return STATUS : error control
*/
STATUS object_set_aditDesc(Object *object, char* aditDesc){
    if(object==NULL || aditDesc==NULL)
        return ERROR;
    
    if(!strcpy(object->aditDesc, aditDesc))
        return ERROR;
    
    return OK;
}

/**
* @brief It prints the description of a objects
* @author Andres Salas
* @date 23-09-2016
* @param object : the object which description is printed
* @return STATUS: error control
*/
STATUS object_print_description(Object* object){
	if (!object) 
		return ERROR;

	fprintf(stdout, "%s\n", object->description);

	return OK;
}

/**
* @brief It prints the extra description of a objects
* @author Maria Barroso
* @date 03-12-2016
* @param object : the object which description is printed
* @return STATUS: error control
*/
STATUS object_print_aditDesc(Object* object){
	if (!object) 
		return ERROR;

	fprintf(stdout, "%s\n", object->aditDesc);

	return OK;
}

/**
* @brief It prints the data of an object.
* @author Andres Salas
* @date 23-11-2016
* @param object : the object to be printed
* @return STATUS: error control
*/
STATUS object_print(Object* object) {  
    if (!object) {
        return ERROR;
    }

    fprintf(stdout, "--> Object (Id: %ld; Name: %s) ", object->id, 
                                                        object->name);
    fprintf(stdout, "--> Description: ");
    object_print_description(object);
    fprintf(stdout, "--> Extra description: ");
    object_print_aditDesc(object);
    return OK;
}


