
/**
 * @brief It defines an object
 * @file object.h
 * @author Andres Salas
 * @version 1.0
 * @date 23-09-2016
 */
 
#ifndef OBJECT_H
#define OBJECT_H

 /**
 * @brief Definition of macro MAX_OBJECTS
 */

#define MAX_OBJECTS 16 /*limit of the number of objects*/

#include "types.h"
#include "set.h"

 /**
 * @brief Definition of object structure
 */

typedef struct _Object Object; /*<! Definition of the Object structure */


/* Definition of public functions */

/**
* @brief It creates an object with a given id.
* @author Andres Salas
* @date 23-09-2016
* @param id: object identity
* @return Object : the object structure with its id
*/
Object* object_create(Id id);

/**
* @brief It destroys an space and frees its memory.
* @author Andres Salas
* @date 23-09-2016
* @param object: the object to be destroyed
* @return STATUS: error control
*/
STATUS object_destroy(Object *object);

/**
* @brief It sets the name of an object
* @author Andres Salas
* @date 23-09-2016
* @param object : the space whose name will be set
* @param name : the wanted name
* @return STATUS: error control
*/
STATUS object_set_name(Object* object, char* name);

/**
* @brief It sets the description of an object.
* @author Andres Salas
* @date 23-09-2016
* @param object : the object whose description is got
* @param description : the wanted description
* @return STATUS : error control
*/
STATUS object_set_description(Object* object, char* description);

/**
* @brief It gets the name of a given object.
* @author Andres Salas
* @date 23-09-2016
* @param object : the object whose name is got
* @return char* : the name of the given object
*/
const char* object_get_name(Object* object);

/**
* @brief It gets the id of an object.
* @author Andres Salas
* @date 23-09-2016
* @param object : the object whose id is got
* @return Id : the id of a certain object
*/
Id object_get_id(Object* object);

/**
* @brief It gets the description of an object.
* @author Andres Salas
* @date 12-11-2016
* @param object : the object whose description is got
* @return Char : the description of a certain object
*/
const char* object_get_description(Object* object);

/**
* @brief It gets the portability of an object
* @author Andres Salas
* @date 1-12-2016
* @param object : the object whose portability is got
* @return BOOL: the status of the portability
*/
BOOL object_get_portability(Object *object);

/**
* @brief It sets the portability of an object
* @author Andres Salas
* @date 1-12-2016
* @param object : the object whose portability will be set
* @param portable : the wanted portability
* @return STATUS: error control
*/
STATUS object_set_portability(Object *object, BOOL portable);

/**
* @brief It gets the movement of an object
* @author Andres Salas
* @date 1-12-2016
* @param object : the object whose movement is got
* @return BOOL: the status of the movement
*/
BOOL object_get_movement(Object *object);

/**
* @brief It sets the movement of an object
* @author Andres Salas
* @date 1-12-2016
* @param object : the object whose movement will be set
* @param moved : the wanted movement
* @return STATUS: error control
*/
STATUS object_set_movement(Object *object, BOOL moved);

/**
* @brief It gets the visibility of an object
* @author Andres Salas
* @date 1-12-2016
* @param object : the object whose visibility is got
* @return BOOL: the status of the visibility
*/
BOOL object_get_hidden(Object *object);

/**
* @brief It sets the visibility of an object
* @author Andres Salas
* @date 1-12-2016
* @param object : the object whose visibility will be set
* @param visibility: the wanted visibility
* @return STATUS: error control
*/
STATUS object_set_hidden(Object *object, BOOL hidden);

/**
* @brief It gets the opens ids of an object
* @author Andres Salas
* @date 1-12-2016
* @param object : the object whose opens field is got
* @return Id: it returns the ids;
*/
Id *object_get_opens_ids(Object *object);

/**
* @brief It gets the opens set of an object
* @author Andres Salas
* @date 1-12-2016
* @param object : the object whose opens field is got
* @return Set: it returns the set;
*/
Set *object_get_opens(Object *object);

/**
* @brief  it checks that an opens field of object is full
* @author Andres Salas
* @date 1-12-2016
* @param object : the object whose opens field will be studied
* @return BOOL: TRUE if it is full or an error FALSE other case.
*/
BOOL object_opens_is_full(Object *object);

/**
* @brief  it adds an id to the opens field
* @author Andres Salas
* @date 1-12-2016
* @param object : the object where we will add the id
* @param idaux: the id that we will add
* @return STATUS: error control
*/
STATUS object_add_opens(Object *object, Id idaux);

/**
* @brief  it deletes an id of the opens field
* @author Andres Salas
* @date 1-12-2016
* @param object : the object where we will delete the id
* @param idaux: the id that we will delete
* @return STATUS: error control
*/
STATUS object_delete_opens(Object *object, Id idaux);

/**
* @brief  it searchs an id in the opens field
* @author Andres Salas
* @date 1-12-2016
* @param object : the object where we will search
* @param idaux: the id that we will search
* @return BOOL: TRUE if it is or an error FALSE other case.
*/
BOOL object_search_id(Object *objects, Id idaux);

/**
* @brief It gets the lights of an object
* @author Andres Salas
* @date 1-12-2016
* @param object : the object whose lights is got
* @return BOOL: the status of the lights
*/
BOOL object_get_lights(Object *object);

/**
* @brief It sets the lights of an object
* @author Andres Salas
* @date 1-12-2016
* @param object : the object whose lights will be set
* @param lights_up : the wanted lights
* @return STATUS: error control
*/
STATUS object_set_lights(Object *object, BOOL lights_up);

/**
* @brief It gets the activate of an object
* @author Andres Salas
* @date 1-12-2016
* @param object : the object whose activate is got
* @return BOOL: the status of the activate
*/
BOOL object_get_activate(Object *object);

/**
* @brief It sets the activate of an object
* @author Andres Salas
* @date 1-12-2016
* @param object : the object whose activate field will be set
* @param activated : the wanted activate field
* @return STATUS: error control
*/
STATUS object_set_activate(Object *object, BOOL activated);
/**
* @brief It gets the extra description in an object 
* @author Maria Barroso
* @date 03-12-2016
* @param object : the object whose desc may be returned
* @return string : the extra description
*/
const char* object_get_aditDesc(Object * object);
/**
* @brief It sets the extra description in an object 
* @author Maria Barroso
* @date 02-12-2016
* @param object : the object whose extra desc may be set
* @return STATUS : error control
*/
STATUS object_set_aditDesc(Object *object, char* aditDesc);

/**
* @brief It prints the extra description of a objects
* @author Maria Barroso
* @date 03-12-2016
* @param object : the object which description is printed
* @return STATUS: error control
*/
STATUS object_print_aditDesc(Object* object);

/**
* @brief It prints the description of a objects
* @author Andres Salas
* @date 23-09-2016
* @param object : the object which description is printed
* @return STATUS : error control
*/
STATUS object_print_description(Object* object);

/**
* @brief It prints the data of an object.
* @author Andres Salas
* @date 23-09-2016
* @param object : the object to be printed
* @return STATUS : error control
*/
STATUS object_print(Object* object);

#endif
