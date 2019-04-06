
 /**
 * @brief It defines the link's commands
 * @file link.c
 * @author Maria Barroso
 * @version 1.0
 * @date 05-11-2016
 */
 
#include <stdlib.h>
#include <string.h>
#include "link.h"

/**
 * @brief Definition of the data structure
 */

struct _Link{
   Id id; /*!<Identifier of each link*/
   char name[WORD_SIZE + 1]; /*!<Name of the link*/
   Id departureSpace; /*!<Identifier of the departure space*/
   Id arrivalSpace; /*!<Identifier of the arrival space*/
   BOOL oorc; /*!<Variable that tells whether a link is open or close 
               (TRUE=open, FALSE=close)*/
};


/* Link interface implementation */


/**
* @brief It creates a new link.
* @author Maria Barroso
* @date 5-11-2016
* @param id: the id of the link
* @return Link: the new link
*/
Link* link_create(Id id){
   Link* link;

   if(id == NO_ID)
   		return NULL;

   link = (Link *)malloc(sizeof(Link));
   if(!link)
      return NULL;
   
   link->id = id;
   link->name[0] = '\0';
   link->departureSpace = NO_ID;
   link->arrivalSpace = NO_ID;
   link->oorc = FALSE;

   return link;
}

/**
* @brief It destroys the link
* @author Maria Barroso
* @date 5-11-2016
* @param link: The link that we will destroy
* @return STATUS: error control
*/

STATUS link_destroy(Link* link){
   
   if(!link)
      return ERROR;

   free(link);
   
   return OK;
}

/**
* @brief It gets the idge of a link.
* @author Maria Barroso
* @date 5-11-2016
* @param link : the link whose id is got
* @return Id: the id of a certain link
*/
Id link_get_id(Link* link){
   
   if(!link)
      return NO_ID;
   
   return link->id;
}


/**
* @brief It gets the name of a given link.
* @author Maria Barroso
* @date 5-11-2016
* @param link : the link whose name is got
* @return char* : the name of the given link
*/
char* link_get_name(Link* link){
   
   if(!link)
      return NULL;
   
   return link->name;
}

/**
* @brief It gets the link id of the departureSpace.
* @author Maria Barroso
* @date 5-11-2016
* @param link : the link whose departureSpace id´s is got
* @return Id: the id of a departureSpace of a certain link.
*/
Id link_get_departureSpace(Link* link){
   
   if(!link)
      return NO_ID;
   
   return link->departureSpace;
}


/**
* @brief It gets the link id of the arrivalSpace.
* @author Maria Barroso
* @date 5-11-2016
* @param link : the link whose arrivalSpace id´s is got
* @return Id: the id of a arrivalSpace of a certain link.
*/
Id link_get_arrivalSpace(Link* link){
   
   if(!link)
      return NO_ID;
   
   return link->arrivalSpace;
}


/**
* @brief It gets the id of the oorc link.
* @author Maria Barroso
* @date 5-11-2016
* @param link : the link whose oorc id´s is got
* @return BOOL: value of the link oorc(open or closed)
*/
BOOL link_get_oorc(Link* link){
   if(!link)
      return FALSE;
   
   return link->oorc;
}

/**
* @brief It sets the name of a link.
* @author Maria Barroso
* @date 5-11-2016
* @param link : the link whose name will be modified
* @param name: the new name
* @return STATUS: error control
*/
STATUS link_set_name(Link* link, char *name){
   
   if(!link || !name)
      return ERROR;
   
   if(strcpy(link->name, name) == NULL)
      return ERROR;
   
   return OK;
}

/**
* @brief It sets the departureSpace of a link.
* @author Maria Barroso
* @date 5-11-2016
* @param link : the link whose departureSpace will be modified
* @param id: the new departureSpace
* @return STATUS: error control
*/
STATUS link_set_departureSpace(Link* link, Id id){
   
   if(!link || id == NO_ID)
      return ERROR;
   
   link->departureSpace=id;
   
   return OK;
}


/**
* @brief It sets the arrivalSpace of a link.
* @author Maria Barroso
* @date 5-11-2016
* @param link : the link whose arrivalSpace will be modified
* @param id: the new arrivalSpace
* @return STATUS: error control
*/
STATUS link_set_arrivalSpace(Link* link, Id id){
   
   if(!link || id == NO_ID)
      return ERROR;
   
   link->arrivalSpace=id;
   
   return OK;
}


/**
* @brief It sets the oorc of a link.
* @author Maria Barroso
* @date 5-11-2016
* @param link : the link whose oorc will be modified
* @param oorc: the value of a oorc of a certain link, open or closed.
* @return STATUS: error control
*/
STATUS link_set_oorc(Link* link, BOOL oorc){
   
   if(!link)
      return ERROR;
   
   link->oorc=oorc;
   
   return OK;
}

/**
* @brief It compares the ids of two different links
* @author Maria Barroso
* @date 5-11-2016
* @param link2 : the link1 to compare 
* @param link1 : the link2 to compare
* @return BOOL: value of the comparation of the links(open or closed)
*/
BOOL link_compare_id(Link* link1, Link* link2){
   if(!link1 || !link2)
      return FALSE;
   
   if(link_get_id(link1) == link_get_id(link2))
      return TRUE;
   
   return FALSE;
}


/**
* @brief It prints the data of a link
* @author Maria Barroso
* @date 5-11-2016
* @param link : the link to be printed
* @return STATUS: error control
*/
STATUS link_print(Link *link){
   if(!link)
      return ERROR;
   
   if(link->oorc){
      fprintf(stdout, "-->Link (Id: %ld, Name: %s, Linked spaces: %ld -> %ld, OPEN)\n", link->id, link->name, link->departureSpace, link->arrivalSpace);
   }
   
   else{
      fprintf(stdout, "-->Link (Id: %ld, Name: %s, Linked spaces: %ld -> %ld, CLOSED)\n", link->id, link->name, link->departureSpace, link->arrivalSpace);
   }
   
   return OK;
}
