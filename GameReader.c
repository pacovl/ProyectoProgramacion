
/**
 * @brief It implements the game functions that use spaces.
 * @file GameReader.c
 * @author Lucia Colmenarejo
 * @version 1.0
 * @date 2-09-2016
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GameReader.h"

/* GameReader interface implementation */

#ifdef __USE_GNU
# define __rawmemchr rawmemchr
#else
# define __rawmemchr strchr
#endif

char *strtok_r (char *s, const char *delim, char **save_ptr) {
  char *token;

  if (s == NULL)
    s = *save_ptr;

  /* Scan leading delimiters.  */
  s += strspn (s, delim);
  if (*s == '\0')
    {
      *save_ptr = s;
      return NULL;
    }

  /* Find the end of the token.  */
  token = s;
  s = strpbrk (token, delim);
  if (s == NULL)
    /* This token finishes the string.  */
    *save_ptr = __rawmemchr (token, '\0');
  else
    {
      /* Terminate the token and make *SAVE_PTR point past it.  */
      *s = '\0';
      *save_ptr = s + 1;
    }
  return token;
}


/**
* @brief   It loads in the incoming game the spaces stored in a file.
* @author Lucia Colmenarejo
* @date  23-09-2016
* @param game : the running game
* @param filename : the file where the spaces are stored (spaces.dat in this case)
* @return  STATUS : error control
*/

STATUS game_load_spaces(Game* game, char* filename) {
  FILE* file = NULL;
  char line[WORD_SIZE] = "";
  char* toks = NULL;
  /*Space fields*/
  char name[WORD_SIZE] = ""; /*It stores the name of each space while reading the file*/
  char gdesc[MAX_ROWS][MAX_COLUMNS]; /*It stores the graphic descripcion for each space while reading the file*/
  char description[DESC_SIZE]; /*It stores the written description of each space while reading the file*/
  char extraDesc[DESC_SIZE];
  BOOL iluminated = FALSE;
  int iluminated_aux = 0;
  /*The next three pointers are use for reading the object ids of each space, 
  which will be treated as subtokens separated by the delimiter "," using the amazing function strtok_r*/
  char* subtoks = NULL;
  char* savePointer;
  char* obj_ids_str = NULL;
  Id obj_ids[MAX_ID]; 
  /*Direction ids*/
  Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID;
  Id up = NO_ID, down = NO_ID;
  Space* space = NULL;
  /*Other variables*/
  STATUS status = OK; /*Error control*/
  int i;
  
  
  

  if (!filename) {
    return ERROR;
  }
  
  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }
  
  while (fgets(line, WORD_SIZE, file)) {
    for(i = 0; i < MAX_ROWS; i++) {
      gdesc[i][0] = '\0';
    }
    for(i = 0; i < MAX_ID; i++) {
      obj_ids[i] = 0;
    }

    if (strncmp("#s:", line, 3) == 0) {
      /*Read process of the identifiers*/
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      /*Read process of each direction*/
      toks = strtok(NULL, "|");
      north = atol(toks);
      toks = strtok(NULL, "|");
      east = atol(toks);
      toks = strtok(NULL, "|");
      south = atol(toks);
      toks = strtok(NULL, "|");
      west = atol(toks);
      toks = strtok(NULL, "|");
      up = atol(toks);
      toks = strtok(NULL, "|");
      down = atol(toks);
      /*Read process of the iluminated state (FALSE by default)*/
      toks = strtok(NULL, "|");
      iluminated_aux = atoi(toks);
      if(iluminated_aux == 1)
        iluminated = TRUE;
      
      /*Esta mal. En proceso de investigacion profunda*/
      
      /*SOLUC. --> https://linux.die.net/man/3/strtok_r*/
      
      /*Read of the objecct ids which are in the space*/
      toks = strtok(NULL, "|");
      if(strcmp(toks, "-1") != 0) {
        for(i = 0, obj_ids_str = toks; ; obj_ids_str = NULL, i++) {
          subtoks = strtok_r(obj_ids_str, ",", &savePointer);
          if(!subtoks) break;
          obj_ids[i] = atol(subtoks);
        }      
      }
      
      /*Read of the written descriptions*/
      toks = strtok(NULL, "|");
      strcpy(description, toks);

      toks = strtok(NULL, "|");
      strcpy(extraDesc, toks);
      
      /*Load of the graphical description*/
      for(i = 0; i < MAX_ROWS; i++){
        toks = strtok(NULL, "|");
        if(toks != NULL && strlen(toks) > 2) /*the strlen condition aviods that the 
                                              first row of gdesc become a line break*/
          strcpy(gdesc[i], toks);
        else
          gdesc[i][0] = '\0';
      }
      
    
/*#ifdef DEBUG*/
      printf("Leido: %ld|%s|%ld|%ld|%ld|%ld|%ld|%ld|%d|", id, name, north, east, south, west, up, south, iluminated_aux);

      for(i = 0; i < MAX_ID && obj_ids[i] != 0; i++) {
        printf("%ld", obj_ids[i]);
        if(obj_ids[i+1] != 0 || i+1 != MAX_ID) {
          printf(",");
        }
      }
      printf("|%s|%s|%s|%s|%s|\n", description, extraDesc, gdesc[0], gdesc[1], gdesc[2]);
/*#endif*/

      /*Creation and init of each new space*/
      space = space_create(id);
      if (space != NULL) {
          space_set_name(space, name);

        /*each link is initialized with temporal values (only the id, that allow us to find it afterwards)
        which will be replaced correctly in game_load_links with the remaining info about each link*/
        /*These "if's" are not necesarry beacuse of the input control in both functions*/
        if(north != NO_ID)
          space_set_north(space, link_create(north));
        if(east != NO_ID)
          space_set_east(space, link_create(east));
        if(south != NO_ID)
          space_set_south(space, link_create(south));
        if(west != NO_ID)
          space_set_west(space, link_create(west));
         if(up != NO_ID)
          space_set_up(space, link_create(up));
         if(down != NO_ID)
          space_set_down(space, link_create(down));

        space_set_iluminated(space, iluminated);

        for(i = 0; i < MAX_ID && obj_ids[i] != 0; i++) {
          space_add_object_id(space, obj_ids[i]);
        }

        space_set_gdesc(space, gdesc[0], gdesc[1], gdesc[2]);
        
        space_set_description(space, description);

        space_set_extraDesc(space, extraDesc);

        game_add_space(game, space);
      }
    }
  }
  
  if (ferror(file)) {
    status = ERROR;
  }
  
  fclose(file);
  
  return status;
}



/**
* @brief   It loads in the incoming game the objects stored in a file.
* @author Lucia Colmenarejo
* @date  17-10-2016
* @param game : the running game
* @param filename : the file where the objects are stored (objects.dat in this case)
* @return  STATUS : error control
*/

STATUS game_load_objects(Game* game, char* filename){
  FILE* file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = ""; /*It stores the name of each object while reading the file*/
  char description[DESC_SIZE]; /*It stores the written description of each object while reading the file*/
  char* toks = NULL;
  Id id = NO_ID; /*It stores the id of each object while reading the file*/
  Object* object = NULL;
  BOOL portable; /*It stores the portability of each object while reading the file*/
  BOOL moved; /*It stores the movement of each object while reading the file*/
  BOOL hidden; /*It stores the concealment of each object while reading the file*/
  BOOL lights_up; /*It stores the ilumination of each object while reading the file*/
  BOOL activated; /*It stores the activation of each object while reading the file*/
  char aditDesc[DESC_SIZE]; /*It stores the extra description of each object while reading the file*/
  STATUS status = OK; /*Error control*/
  char set[DESC_SIZE];
  
  if (!filename) {
    return ERROR;
  }
  
  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }
  
  while (fgets(line, WORD_SIZE, file)) {
    if (strncmp("#o:", line, 3) == 0) {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      strcpy(description, toks);
      toks = strtok(NULL, "|");
      portable = atoi(toks);
      toks = strtok(NULL, "|");
      moved = atoi(toks);
      toks = strtok(NULL, "|");
      hidden = atoi(toks);
      toks = strtok(NULL, "|");
      strcpy(set, toks);
      toks = strtok(NULL, "|");
      lights_up = atoi(toks);
      toks = strtok(NULL, "|");
      activated = atoi(toks);
      toks = strtok(NULL, "|");
      strcpy(aditDesc, toks);
      
     
#ifdef DEBUG
      printf("Leido: %ld|%s\n", id, name);
#endif

      /*Creation and init of each new object*/
      object = object_create(id);
      if (object == NULL)
        return ERROR;
        
      object_set_name(object, name);
      
      object_set_description(object, description);
      
      object_set_portability(object,portable);
      
      object_set_movement(object,moved);
      
      object_set_hidden(object,hidden);
      
      object_set_lights(object,lights_up);
      
      object_set_activate(object,activated);
      
      object_set_aditDesc(object, aditDesc);
      
      toks=strtok(set+1, "*");
      if(toks != NULL){
        while(toks != NULL){
          toks=strtok(NULL, "*");
          object_add_opens(object, atoi(set));
        }
      }
      
      /*The process of locating the object is in this function*/
      if(game_add_object(game, object) == ERROR)
        status = ERROR;
    }
  }
  
  if (ferror(file)) {
    status = ERROR;
  }
  
  fclose(file);
  
  return status;
}

/**
* @brief It loads in the incoming game the links stored in a file.
* @author Lucia Colmenarejo
* @date  11-11-2016
* @param game : the running game
* @param filename : the file where the objects are stored (objects.dat in this case)
* @return  STATUS : error control
*/
STATUS game_load_links(Game* game, char* filename){
    FILE* file = NULL;
    char line[WORD_SIZE] = "";
    char name[WORD_SIZE] = "";
    char* toks = NULL;
    Id id = NO_ID, origin = NO_ID, destination = NO_ID;
    BOOL oorc;
    int oorc_aux;
    Link* link = NULL;
    STATUS status = OK;
    if (!filename) {
        return ERROR;
    }
    file = fopen(filename, "r");
    if (file == NULL) {
        return ERROR;
    }

    while (fgets(line, WORD_SIZE, file)) {
        if (strncmp("#l:", line, 3) == 0) {
            toks = strtok(line + 3, "|");
            id = atol(toks);
            toks = strtok(NULL, "|");
            strcpy(name, toks);
            toks = strtok(NULL, "|");
            origin = atol(toks);
            toks = strtok(NULL, "|");
            destination = atol(toks);
            toks = strtok(NULL, "|");
            oorc_aux = atoi(toks);
            toks = strtok(NULL, "|");
            if(oorc_aux == 1)
          		oorc = TRUE;
            else
            	oorc = FALSE;

#ifdef DEBUG
            printf("Leido: %ld|%s|%ld|%ld|%d \n", id, name, origin, destination, oorc);
#endif
            
            link = link_create(id);
            if (link != NULL) {
                link_set_name(link, name);
                link_set_departureSpace(link, origin);
                link_set_arrivalSpace(link, destination);
                link_set_oorc(link, oorc);

                /*It completes the link init in the game and the pertinent spaces*/
                game_add_link(game, link);
            }
        }
    }

    if (ferror(file)) {
        status = ERROR;
    }
    fclose(file);

    return status;
  
}
