
 /**
 * @brief It implements the link interface.
 * @file link.h
 * @author Maria Barroso
 * @version 1.0
 * @date 05-11-2016
 */
 
 #ifndef LINK_H
 #define LINK_H
 
 #include <stdio.h>
 #include "types.h"
 
 /**
 * @brief Definition of macro OPEN
 */

 #define OPEN 1
 
 /**
 * @brief Definition of macro CLOSED
 */

 #define CLOSED 0

 /**
 * @brief Definition of macro MAX_LINKS
 */

 #define MAX_LINKS 4*10000

 /**
 * @brief Definition of link structure
 */

 typedef struct _Link Link; /*<! Definition of the Link structure */
 


/**
* @brief It creates a new link.
* @author Maria Barroso
* @date 5-11-2016
* @param id: the id of the link
* @return Link: the new link
*/
 Link * link_create(Id id);
 
/**
* @brief It destroys the link
* @author Maria Barroso
* @date 5-11-2016
* @param link: The link that we will destroy
* @return STATUS: error control
*/

 STATUS link_destroy(Link* link);

/**
* @brief It gets the id of a link.
* @author Maria Barroso
* @date 5-11-2016
* @param link : the link whose id is got
* @return Id: the id of a certain link
*/

 Id link_get_id(Link* link);
 
/**
* @brief It gets the name of a given link.
* @author Maria Barroso
* @date 5-11-2016
* @param link : the link whose name is got
* @return char* : the name of the given link
*/

 char* link_get_name(Link* link);
 
/**
* @brief It gets the link id of the departureSpace.
* @author Maria Barroso
* @date 5-11-2016
* @param link : the link whose departureSpace id´s is got
* @return Id: the id of a departureSpace of a certain link.
*/

 Id link_get_departureSpace(Link* link);
 
/**
* @brief It gets the link id of the arrivalSpace.
* @author Maria Barroso
* @date 5-11-2016
* @param link : the link whose arrivalSpace id´s is got
* @return Id: the id of a arrivalSpace of a certain link.
*/

 Id link_get_arrivalSpace(Link* link);
 
/**
* @brief It gets the id of the oorc link.
* @author Maria Barroso
* @date 5-11-2016
* @param link : the link whose oorc id´s is got
* @return BOOL: value of the link oorc(open or closed)
*/
 
 BOOL link_get_oorc(Link* link);
 
/**
* @brief It sets the name of a link.
* @author Maria Barroso
* @date 5-11-2016
* @param link : the link whose name will be modified
* @param name: the new name
* @return STATUS: error control
*/

 STATUS link_set_name(Link *link, char *name);
 
/**
* @brief It sets the departureSpace of a link.
* @author Maria Barroso
* @date 5-11-2016
* @param link : the link whose departureSpace will be modified
* @param id: the new departureSpace
* @return STATUS: error control
*/
 
 STATUS link_set_departureSpace(Link *link, Id id);
 

/**
* @brief It sets the arrivalSpace of a link.
* @author Maria Barroso
* @date 5-11-2016
* @param link : the link whose arrivalSpace will be modified
* @param id: the new arrivalSpace
* @return STATUS: error control
*/
 
 STATUS link_set_arrivalSpace(Link *link, Id id);
 
/**
* @brief It sets the oorc of a link.
* @author Maria Barroso
* @date 5-11-2016
* @param link : the link whose oorc will be modified
* @param oorc: the value of a oorc of a certain link, open or closed.
* @return STATUS: error control
*/
 
 STATUS link_set_oorc(Link *link, BOOL oorc);
 
/**
* @brief It compares the ids of two different links
* @author Maria Barroso
* @date 5-11-2016
* @param link1 : the link1 to compare 
* @param link2 : the link2 to compare
* @return BOOL: value of the comparation of the links(open or closed)
*/

 BOOL link_compare_id(Link *link1, Link *link2);
 
/**
* @brief It prints the data of a link
* @author Maria Barroso
* @date 5-11-2016
* @param link : the link to be printed
* @return STATUS: error control
*/

 STATUS link_print(Link *link);
 
 #endif
