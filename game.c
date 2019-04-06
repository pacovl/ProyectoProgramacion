/**
 * @brief It implements the game interface and all the associated callbacks for each command
 * @file game.c
 * @author Andres Salas, Francisco Vicente, Maria Barroso y Lucia Colmenarejo
 * @version 1.0
 * @date 27/11/2016
 */


#include <stdio.h>
#include <string.h>
#include "game.h"
#include "GameReader.h"
#include "GameManagement.h"

#ifdef __WINDOWS_BUILD__

/**
* @brief Definition of macro CLEAR
*/

#define CLEAR "cls"
#else

/**
* @brief Definition 2 of macro CLEAR
*/

#define CLEAR "clear"
#endif

/**
* @brief Definition of the data structure
*/

struct _Game{
  Player* player; /*!< The only player who plays*/
  Object* objects[MAX_OBJECTS + 1]; /*!< Array of objects in the game*/
  Space* spaces[MAX_SPACES + 1]; /*!< Array of spaces in the game*/
  Link* links[MAX_LINKS +1];  /*!< Array of links in the game*/
  Die* die; /*!< The die to be used during a game*/
  char last_desc[DESC_SIZE]; /*!< The last  description returned by the examine callback*/
};

/* List of callbacks for each command in the game */


/**
* @brief It doesn't do anything
* @author Andres Salas
* @date 30/09/2016
* @param game : the running game
* @return STATUS : error control
*/
STATUS callback_UNKNOWN(Game* game);

/**
* @brief It finishes the game
* @author Andres Salas
* @date 30/09/2016
* @param game : the running game
* @return STATUS : error control
*/
STATUS callback_QUIT(Game* game);


/**
* @brief It moves the player one position more
* @author Andres Salas
* @date 30/10/2016
* @param game : the running game
* @return STATUS : error control
*/
STATUS callback_NEXT(Game* game);

/**
* @brief It moves the player one position behind
* @author Andres Salas
* @date 30/09/2016
* @param game : the running game
* @return STATUS : error control
*/
STATUS callback_BACK(Game* game);

/**
* @brief It develops the action related to the command 'grab'. Firstly, after the error
* control, it checks whether the given object is in the space where the player
* is or not. If yes, the object is set in the player 'inventory' and it is 
* removed from that space.
* @author Francisco Vicente
* @date 30/10/2016
* @param game : the running game
* @param input : name of the object that may be grabbed
* @return STATUS : error control
*/
STATUS callback_GRAB(Game* game, char* input);

/**
* @brief It develops the action related to the command 'leave'. First of all, it
* checks whether the player has an object in their 'inventory' or not. If
* yes, the object is set in the space where the player is and then it removes
* the object from the player.
* @author Francisco Vicente
* @date 30/10/2016
* @param game : the running game
* @param input : name of the object that may be left
* @return STATUS : error control
*/
STATUS callback_LEAVE(Game* game, char* input);


/**
* @brief It moves the player if there is a possible of jump(Goose)
* @author Andres Salas
* @date 30/09/2016
* @param game : the running game
* @return STATUS : error control
*/
STATUS callback_JUMP(Game* game);

/**
* @brief It rolls the die
* @author Andres Salas 
* @date 30/09/2016
* @param game : the running game
* @return STATUS : error control
*/
STATUS callback_ROLL(Game* game);

/**
* @brief It moves the player through the spaces 
* @author Andres Salas 
* @date 30/09/2016
* @param game : the running game
* @param direction : second input of the command
* @return STATUS : error control
*/
STATUS callback_GO(Game* game, char* direction);


/**
* @brief It examines the object in a given space 
* @author Maria Barroso
* @date 30/09/2016
* @param game : the running game
* @param input : second input of the command
* @return STATUS : error control
*/
STATUS callback_EXAMINE(Game* game, char* input);

/**
* @brief It turns on the object that can be iluminated
* @author Lucía Colmenarejo 
* @date 2/12/2016
* @param game : the running game
* @param input : name of the object that may be grabbed
* @return STATUS : error control
*/
STATUS callback_TURNON(Game* game, char* input);

/**
* @brief It turns off the object that can be iluminated
* @author María Barroso 
* @date 2/12/2016
* @param game : the running game
* @param input : name of the object that may be grabbed
* @return STATUS : error control
*/
STATUS callback_TURNOFF(Game* game, char* input);

/**
* @brief It open a link with an object
* @author María Barroso 
* @date 3/12/2016
* @param game : the running game
* @param inputLink : name of the link that may be oppened
* @param inputObject : name of the object witch may open the link 
* @return STATUS : error control
*/

STATUS callback_OPEN(Game* game, char* inputLink, char* inputObject);

/**
* @brief It saves the game
* @author María Barroso 
* @date 13/12/2016
* @param game : the running game
* @param input: name of the file where save the game
* @return STATUS : error control
*/

STATUS callback_SAVE(Game* game, char* input);

/**
* @brief It loads the game
* @author María Barroso 
* @date 13/12/2016
* @param game : the running game
* @param input: name of the file where load the game
* @return STATUS : error control
*/
STATUS callback_LOAD(Game* game, char*input);


/**
* @brief It sets the location of a player inside the incoming game 
* @author Francisco Vicente
* @date 30/09/2016
* @param game : the running game
* @param id : the id of the player to be searched
* @return STATUS : error control
*/
STATUS game_set_player_location(Game* game, Id id);

/**
* @brief It sets the location of an object inside the incoming game  
* @author Francisco Vicente
* @date 30/09/2016
* @param game : the running game
* @param object : the obejct to be placed in a certain location 
* @param id: the id of the space where that object may be located
* @return STATUS : error control
*/
STATUS game_set_object_location(Game* game, Object* object, Id id);

/**
* @brief It gets the location of a player inside the running game 
* @author Francisco Vicente 
* @date 30/09/2016
* @param game : the running game
* @return id : the id of the searched player
*/
Id game_get_player_location(Game* game);

/**
* @brief It gets the location of an object inside the running game 
* @author Francisco Vicente
* @date 30/09/2016
* @param game : the running game
* @param id : the id of the object
* @return Id : the id of the space where the object is located
*/
Id game_get_object_location(Game* game, Id id);

/**
* @brief It adds the links to spaces 
* @author Francisco Vicente 
* @date 30/09/2016
* @param game : the running game
* @param link : the link to add
* @return STATUS : error control
*/
STATUS game_add_link_spaces(Game* game, Link* link);

/* Game interface implementation */


/**
* @brief It creates a game, allocating the necessay memory for it. 
* @author Francisco Vicente
* @date 30/09/2016
* @return Game : the newly created game
*/
Game* game_create() {
  Game* newGame = NULL;
  
  newGame = (Game *)malloc(sizeof(Game));
  if(!newGame)
    return NULL;
  
  /*There is no need of initializing the structure, because
    game_init does that functionality below*/
  return newGame;
}

/**
* @brief It initializes a game just setting its fields with the default values. 
* @author Andres Salas 
* @date 23/09/2016
* @param game : the running game
* @param player_id : the id of the game's player
* @param die_id : the id of the game's die 
* @return STATUS : error control
*/
STATUS game_init(Game* game, Id player_id, Id die_id) {
  int i;
  
  for (i = 0; i < MAX_SPACES; i++) /*Spaces init*/
    game->spaces[i] = NULL;
  
  for (i = 0; i < MAX_OBJECTS; i++) /*Objects init*/
    game->objects[i] = NULL;

  for (i = 0; i < MAX_LINKS; i++) /*Links init*/
    game->links[i] = NULL;
  
  game->player = player_create(player_id); /*Player init [memory alloc]*/
  if(!game->player) 
    return ERROR;
  
  game->die = die_create(die_id); /*Die init [memory alloc]*/
  if(!game->die){
    player_destroy(game->player);
    return ERROR;
  }

  game->last_desc[0] = '\0';
  
  return OK;
}

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
* @param filename2 : the name of the file
* @param filename3 : the name of the file 
* @param player : the id of the game's player
* @param die : the id of the game's die
* @return STATUS : error control
*/
STATUS game_init_from_file(Game* game, char* filename1, char* filename2, char* filename3, Id player, Id die) {
  if(player == NO_ID || die == NO_ID || !game || !filename1 || !filename2)
    return ERROR;

  /*INIT PROCESS*/
  if (game_init(game, player, die) == ERROR)
    return ERROR;

  /*LOAD PROCESS*/
  if (game_load_spaces(game, filename1) == ERROR){
    player_destroy(game->player);
    die_destroy(game->die);
    return ERROR;
  }

  if (game_load_objects(game, filename2) == ERROR){
    player_destroy(game->player);
    die_destroy(game->die);
    return ERROR;
  }
  
  if (game_load_links(game, filename3) == ERROR){
    player_destroy(game->player);
    die_destroy(game->die);
    return ERROR;
  }

  game_set_player_location(game, game_get_space_id_at(game, 0));
  
  return OK;
}

/**
* @brief It matches each incoming command with its correspoding callback. It 
* also prints the neccesary data for the log file
* @author Francisco Vicente
* @date 01/11/2016
* @param game : the game to be updated
* @param cmd : the command that may be used
* @param f : the register file
* @return STATUS : error control
*/
STATUS game_update(Game* game, Command* cmd, FILE *f) {
  char aditionalInput[CMD_LENGHT];
  char extraInput[CMD_LENGHT];

  /*No -l option chosen*/
  if(f == NULL) {
    switch (command_get_numcmd(cmd)) {

    case UNKNOWN:
      callback_UNKNOWN(game);
      break;

    case QUIT:
      callback_QUIT(game);
      break;

    case NEXT:
      callback_GO(game, "s");
      break;

    case BACK:
      callback_GO(game, "n");
      break;

    case GRAB:
      if(strcpy(aditionalInput, command_get_input(cmd)) == NULL)
        break;
      callback_GRAB(game, aditionalInput);
      break;

    case LEAVE:
      if(strcpy(aditionalInput, command_get_input(cmd)) == NULL)
        break;
      callback_LEAVE(game, aditionalInput);
      break;

    case JUMP:
      callback_GO(game, "e");
      break;

    case ROLL:
      callback_ROLL(game);
      break;
  
    case GO:
      if(strcpy(aditionalInput, command_get_input(cmd)) == NULL)
        break;
      callback_GO(game, aditionalInput);
      break;

    case EXAMINE:
      if(strcpy(aditionalInput, command_get_input(cmd)) == NULL)
        break;
      callback_EXAMINE(game, aditionalInput);
      break;
    
    case TURNON:
      if(strcpy(aditionalInput, command_get_input(cmd)) == NULL)
        break;
      callback_TURNON(game, aditionalInput);
      break;
      
    case TURNOFF:
      if(strcpy(aditionalInput, command_get_input(cmd)) == NULL)
        break;
      callback_TURNOFF(game, aditionalInput);
      break;
    
    case OPEN_LINK:
      if(strcpy(aditionalInput, command_get_input(cmd)) == NULL || 
         strcpy(extraInput, command_get_extraInput(cmd)) == NULL)
        break;
      callback_OPEN(game, aditionalInput, extraInput);
      break;
    /*
    case SAVE:
        if(strcpy(aditionalInput, command_get_input(cmd)) == NULL)
            break;
        callback_SAVE(game, aditionalInput);
        break;
    case LOAD:
        if(strcpy(aditionalInput, command_get_input(cmd)) == NULL)
            break;
        callback_LOAD(game, aditionalInput);
        break;  
    */  
    case NO_CMD:
      break;

    default: /* We must never arrive here*/
      return ERROR;
    }

  return OK;
  }
  
  
  else {
  /*-l option activated*/
  switch (command_get_numcmd(cmd)) {

  case UNKNOWN:
    fprintf(f, "UNKNOWN: ");
    if(callback_UNKNOWN(game) == OK)
      fprintf(f, "OK\n");
    else
      fprintf(f, "ERROR\n");
    break;

  case QUIT:
    fprintf(f, "QUIT: ");
    if(callback_QUIT(game) == OK)
      fprintf(f, "OK\n");
    else
      fprintf(f, "ERROR\n");
    break;

  case NEXT:
    fprintf(f, "NEXT: ");
    if(callback_GO(game, "s") == OK)
      fprintf(f, "OK\n");
    else
      fprintf(f, "ERROR\n");
    break;

  case BACK:
    fprintf(f, "BACK: ");
    if(callback_GO(game, "n") == OK)
      fprintf(f, "OK\n");
    else
      fprintf(f, "ERROR\n");
    break;

  case GRAB:
    if(strcpy(aditionalInput, command_get_input(cmd)) == NULL)
      break;
    fprintf(f, "GRAB %s: ", aditionalInput);
    if(callback_GRAB(game, aditionalInput) == OK){
      fprintf(f, "OK\n");
    }
    else
      fprintf(f, "ERROR\n");
    break;

  case LEAVE:
    if(strcpy(aditionalInput, command_get_input(cmd)) == NULL)
      break;
    fprintf(f, "LEAVE %s: ", aditionalInput);
    if(callback_LEAVE(game, aditionalInput) == OK)
      fprintf(f, "OK\n");
    else
      fprintf(f, "ERROR\n");
    break;

  case JUMP:
    fprintf(f, "JUMP: ");
    if(callback_GO(game, "e") == OK)
      fprintf(f, "OK\n");
    else
      fprintf(f, "ERROR\n");
    break;

  case ROLL:
    fprintf(f, "ROLL: ");
    if(callback_ROLL(game) == OK)
      fprintf(f, "OK\n");
    else
      fprintf(f, "ERROR\n");
    break;
  
  case GO:
    if(strcpy(aditionalInput, command_get_input(cmd)) == NULL)
      break;
    fprintf(f, "GO %s: ", aditionalInput);
    if(callback_GO(game, aditionalInput) == OK)
      fprintf(f, "OK\n");
    else
      fprintf(f, "ERROR\n");
    break;

  case EXAMINE:
    if(strcpy(aditionalInput, command_get_input(cmd)) == NULL)
      break;
    fprintf(f,"EXIMINE %s: ", aditionalInput);
    if(callback_EXAMINE(game, aditionalInput) == OK)
      fprintf(f, "OK\n");
    else
      fprintf(f, "ERROR\n");
    break;
  
  case TURNON:
    if(strcpy(aditionalInput, command_get_input(cmd)) == NULL)
      break;
    fprintf(f, "TURNON %s: ", aditionalInput);
    if(callback_TURNON(game, aditionalInput) == OK){
      fprintf(f, "OK\n");
    }
    else
      fprintf(f, "ERROR\n");
    break;
  
  case TURNOFF:
    if(strcpy(aditionalInput, command_get_input(cmd)) == NULL)
      break;
    fprintf(f, "TURNOFF %s: ", aditionalInput);
    if(callback_TURNOFF(game, aditionalInput) == OK){
      fprintf(f, "OK\n");
    }
    else
      fprintf(f, "ERROR\n");
    break;
    
  case OPEN_LINK:
    if(strcpy(aditionalInput, command_get_input(cmd)) == NULL|| strcpy(extraInput, command_get_extraInput(cmd)) == NULL)
      break;
    fprintf(f, "OPEN %s WITH %s: ", aditionalInput, extraInput);
    if(callback_OPEN(game, aditionalInput, extraInput) == OK){
      fprintf(f, "OK\n");
    }
    else
      fprintf(f, "ERROR\n");
    break;
    /*
  case SAVE:
    if(strcpy(aditionalInput, command_get_input(cmd)) == NULL)
      break;
    fprintf(f, "SAVE %s: ", aditionalInput);
    if(callback_SAVE(game, aditionalInput) == OK){
      fprintf(f, "OK\n");
    }
    else
      fprintf(f, "ERROR\n");
    break;
  case LOAD:
    if(strcpy(aditionalInput, command_get_input(cmd)) == NULL)
      break;
    fprintf(f, "LOAD %s: ", aditionalInput);
    if(callback_LOAD(game, aditionalInput) == OK){
      fprintf(f, "OK\n");
    }
    else
      fprintf(f, "ERROR\n");
    break;
    */
  case NO_CMD:
    break;

  default: /* We must never arrive here*/
    return ERROR;
  }

  return OK;
  }
}

/**
* @brief When the game is finisehd, it frees the dynamic memory allocated previously.
* @author Andres Salas
* @date 23/09/2016
* @param game : the game to be destroyed
* @return STATUS : error control
*/
STATUS game_destroy(Game* game) {
    int i = 0;
    if(!game) 
      return ERROR;
    
    for (i = 0; (i < MAX_SPACES) && (game->spaces[i] != NULL); i++) {
        space_destroy(game->spaces[i]);
    }
    
    for (i = 0; (i < MAX_OBJECTS) && (game->objects[i] != NULL); i++) {
        object_destroy(game->objects[i]);
    }

    player_destroy(game->player);

    die_destroy(game->die);
    
    /*Added for Iteration 3 because game now use dynamic memory when called in game_loop*/
    free(game);
    game = NULL;
        
    return OK;
}

/**
* @brief It tells when the game is over.
* @author Andres Salas
* @date 23/09/2016
* @param game : the game which may be over
* @return BOOL : it returns TRUE or FALSE
*/
BOOL game_is_over(Game* game) {
  return FALSE;
}

/**
* @brief It prints the data allocated in a game structure.
* @author Andres Salas
* @date 23/09/2016
* @param game : the game which data may be printed
* @return void: -
*/
void game_print_data(Game* game) {
  int i = 0;
  
  printf("\n\n-------------\n\n");
  
  player_print(game->player);
  
  die_print(game->die);
  
  printf("=> Spaces: \n");
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    space_print(game->spaces[i]);
  }
  
  printf("=> Objects: \n");
  for (i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++) {
    object_print(game->objects[i]);
  }

  printf("=> Links: \n");
  for (i = 0; i < MAX_LINKS && game->links[i] != NULL; i++) {
    link_print(game->links[i]);
  }

  printf("=> Description: \n%s\n", game->last_desc);
  
}

/**
* @brief It manages all the graphic interface of the game, printing each space where
*	they must be with its grphic description and the symbol and location of 
* each object.
* @author Francisco Vicente
* @date 31/10/2016
* @param game : the game to be printed
* @return void : -
*/
void game_print_screen(Game* game){
  Link* linkN = NULL;
  Link* linkS = NULL;
  Link* linkJ = NULL;
  Id id_act = NO_ID, id_back = NO_ID, id_next = NO_ID, id_jump = NO_ID;

  char jumpId[WORD_SIZE] = "";
  char jumpLinkId[WORD_SIZE] = "";

  Set* setAux = NULL;
  
  int die_value;

  Space* space_act = NULL; /*current location of the player*/
  Space* space_back = NULL; /*Space pointer of the previous space*/
  Space* space_next = NULL; /*Space pointer of the next space*/

  int flag1 = 0; /*It is useful for printing objects in act,back,next spaces with commas*/
  int flag2 = 0; /*It is useful for printing object locations with commas*/
  int i, j = 0; /*j is a counter used for printing the objects which are in a space*/
  char obj_in_space[11];


  Id objects_id[MAX_OBJECTS];   /*This array may store the id of each object*/
  Id objects_loc[MAX_OBJECTS];  /*This array may store the location of each object*/

  for(i = 0; i < MAX_OBJECTS; i++) {
    objects_id[i] = NO_ID;
  }
  
  for(i = 0; i < MAX_OBJECTS; i++) {
    objects_loc[i] = NO_ID;
  }

  /*Data related to the location of the player and its neighbours*/
  id_act = game_get_player_location(game);
  if (id_act == NO_ID)
    return;
  space_act = game_get_space(game, id_act);
  
  linkN = space_get_north(space_act); 
  id_back = link_get_arrivalSpace(linkN);
  space_back = game_get_space(game, id_back);

  linkS = space_get_south(space_act);
  id_next = link_get_arrivalSpace(linkS);
  space_next = game_get_space(game, id_next);

  linkJ = space_get_east(space_act);
  id_jump = link_get_arrivalSpace(linkJ);
  
  if(system(CLEAR))
     return; 
  
  /*Data related to the location of the objects*/
  for(i = 0; i < MAX_OBJECTS && (game->objects)[i] != NULL; i++) {
    objects_id[i] = object_get_id((game->objects)[i]);
    objects_loc[i] = game_get_object_location(game, objects_id[i]);
  }
  
  /*Previous space print --------------------------------------------*/
  obj_in_space[0] = '\0';
  for(i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++) {
    if(objects_loc[i] == id_back && flag1 == 0) {
      strcat(obj_in_space, object_get_name(game->objects[i]));
      flag1 = 1;
      j++;
    }
    else if(objects_loc[i] == id_back) {
      if(j < 3) {
        strcat(obj_in_space, ",");
        strcat(obj_in_space, object_get_name(game->objects[i]));
        j++;
      }
      else {
        strcat(obj_in_space, "...");
        break; /*break*/
      }

    }
  }
  
  if (id_back != NO_ID) {
    printf("|         %2d|\n",(int) id_back);
    printf("|%11s|\n", space_get_gdesc(space_back, 1));
    printf("|%11s|\n", space_get_gdesc(space_back, 2));
    printf("|%11s|\n", space_get_gdesc(space_back, 3));
    printf("|           |\n"); 
    printf("|%11s|\n", obj_in_space);
    printf("+-----------+\n");
    printf("      ^ %ld\n", link_get_id(linkN));
  }
  
  /*Current space print ---------------------------------------------*/
  j = 0;
  obj_in_space[0] = '\0';
  flag1 = 0;
  for(i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++) {
    if(objects_loc[i] == id_act && flag1 == 0) {
      strcat(obj_in_space, object_get_name(game->objects[i]));
      flag1 = 1;
      j++;
    }
    else if(objects_loc[i] == id_act) {
      if(j < 3) {
        strcat(obj_in_space, ",");
        strcat(obj_in_space, object_get_name(game->objects[i]));
        j++;
      }
      else {
        strcat(obj_in_space, "...");
        break; /*break*/
      }
    }
  }



  if(link_get_id(linkJ) != -1) {
  	sprintf(jumpLinkId, "%ld", link_get_id(linkJ)); 

  	sprintf(jumpId, "--> %ld", id_jump);
  }
  
  if (id_act != NO_ID) {
    printf("+-----------+ %s\n", jumpLinkId);
    printf("| >8D     %2d| %s\n",(int)id_act, jumpId);
    printf("|%11s|\n", space_get_gdesc(space_act, 1));
    printf("|%11s|\n", space_get_gdesc(space_act, 2));
    printf("|%11s|\n", space_get_gdesc(space_act, 3));
    printf("|           |\n"); 
    printf("|%11s|\n", obj_in_space);
    printf("+-----------+\n");
  }
  
  /*Next space print -----------------------------------------------*/
  j = 0;
  obj_in_space[0] = '\0';
  flag1 = 0;
  for(i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++) {
    if(objects_loc[i] == id_next && flag1 == 0) {
      strcat(obj_in_space, object_get_name(game->objects[i]));
      flag1 = 1;
      j++;
    }
    else if(objects_loc[i] == id_next) {
      if(j < 3) {
        strcat(obj_in_space, ",");
        strcat(obj_in_space, object_get_name(game->objects[i]));
        j++;
      }
      else {
        strcat(obj_in_space, "...");
        break; /*break*/
      }
    }
  }
  
  if (id_next != NO_ID) {
    printf("      v %ld\n", link_get_id(linkS));
    printf("+-----------+\n");
    printf("|         %2d|\n",(int)id_next);
    printf("|%11s|\n", space_get_gdesc(space_next, 1));
    printf("|%11s|\n", space_get_gdesc(space_next, 2));
    printf("|%11s|\n", space_get_gdesc(space_next, 3));
    printf("|           |\n"); 
    printf("|%11s|\n", obj_in_space);
  }
  


  printf("\nGame info.-");
  /*Data related to the location of each object*/
  printf ("\n\tObject location: ");
  for(i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++) {
    if(flag2 == 0 && objects_loc[i] != NO_ID) {
      printf(" %s:%ld", object_get_name(game->objects[i]), objects_loc[i]);       
      flag2 = 1;
    }
    
    else if (objects_loc[i] != NO_ID){
      printf(", %s:%ld", object_get_name(game->objects[i]), objects_loc[i]);  
    }
  }

  /*Data related to the player's inventory*/
  setAux = inventory_get_ids(player_get_inventory(game->player));
  if(setAux != NULL && set_get_num(setAux) != 0) {
      printf("\n\tPlayer inventory:");
        
      printf(" %s", object_get_name(game_get_object_pointer(game, set_get_id_number(setAux, 0))));
      for(i = 1; i < set_get_num(setAux); i++)
          printf(" ,%s", object_get_name(game_get_object_pointer(game, set_get_id_number(setAux, i))));
  }

  /*Data related to the die*/
  die_value = die_get_numdie(game->die);
  if(die_value != -1)
    printf("\n\tLast die value: %d", die_value);

  /*Data related to the output of the examine callback*/
  if(strcmp(game->last_desc, "") != 0) {
    printf("\n\nInspect info.-\n\t%s", game->last_desc);
    game->last_desc[0] = '\0';
  }

  /*Instructions for the input*/
  printf("\n\n[Command info.-\n next or n, back or b, quit or q," 
        " grab X (X is the name of the object to be grabbed)," 
        " leave Y or l Y (Y is the name of the object to be left),"
        " jump or j, roll or r, go Z or g Z (Z is the direction),"
        " examine T or e T (T is 'space' or the name of the object to be described),"
        " turnon X (X is the name of the object to be turn on),"
        " turnoff X (X is the name of the object to be turn off),"
        " open L with O (L is the name of the link and O is the name of the object that open it)]");
  printf("\nprompt:> ");
}

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
STATUS game_set_object_location(Game* game, Object* object, Id id) {
  if (id == NO_ID || !object) {
    return ERROR;
  }
    
  return space_add_object(game_get_space(game, id), object);
}

/**
* @brief It sets the location of a player inside the incoming game
* @author Francisco Vicente
* @date 30/09/2016
* @param game : the running game
* @param id : the id of the player to be searched
* @return Status : error control
*/
STATUS game_set_player_location(Game* game, Id id) {
    if (id == NO_ID || !game) {
        return ERROR;
    }
    
    return player_set_location(game->player, game_get_space(game, id));
}

/**
* @brief It gets the location of a player inside the running game.
* @author Francisco Vicente
* @date 30/09/2016
* @param game : the running game
* @return Id : the id of the searched player
*/
Id game_get_player_location(Game* game) {
    if(!game) 
        return NO_ID;
      
    return player_get_location(game->player);
}

/**
* @brief It gets the location of an object inside the running game.
* @author Francisco Vicente
* @date 29/10/2016
* @param game : the running game
* @param id : the id of object
* @return Id : the id of the space where the object is located
*/
Id game_get_object_location(Game* game, Id id){
  int i = 0;
  Space* current_spa = NULL; /*It stores each space pointer in each iteration*/

  if (id == NO_ID || !game)
    return NO_ID;
    
  for (i = 0; i < MAX_SPACES; i++) {
    current_spa = game->spaces[i];
    if (space_is_object(current_spa, game_get_object_pointer(game, id)) == TRUE){
      return space_get_id(current_spa);
    }
  }
    
  return NO_ID;
}

/**
* @brief It adds an space to the incoming game
* @author Francisco Vicente
* @date 23/09/2016
* @param game : the running game
* @param space : the space to be added
* @return Status: error control
*/
STATUS game_add_space(Game* game, Space* space) {
    int i = 0;

    if (space == NULL) {
        return ERROR;
    }

    while ( (i < MAX_SPACES) && (game->spaces[i] != NULL)){
        i++;
    }
    if (i >= MAX_SPACES) {
        return ERROR;
    }

    game->spaces[i] = space;

    return OK;
}

/**
* @brief It gets a space of the game as a pointer from its id.
* @author Francisco Vicente
* @date 23/09/2016
* @param game : the running game
* @param id : the id of space to be returned 
* @return Space : the requested space as a pointer
*/
Space* game_get_space(Game* game, Id id){
    int i = 0;

    if (id == NO_ID) {
      return NULL;
    }
    
    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
      if (id == space_get_id(game->spaces[i])){
      	return game->spaces[i];
      }
    }
    
    return NULL;
}

/**
* @brief It returns the id of an space of the game in a concrete location.
* @author Francisco Vicente
* @date 23/09/2016
* @param game : the running game
* @param position : the position of the space which id may be returned
* @return Id : the id of the space at the incoming position.
*/
Id game_get_space_id_at(Game* game, int position) {
    if (position < 0 || position >= MAX_SPACES) {
        return NO_ID;
    }

    return space_get_id(game->spaces[position]);
}

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
STATUS game_add_object(Game* game, Object* object){
  int i;

  if (object == NULL)
    return ERROR;

  for(i = 0; (i < MAX_OBJECTS) && (game->objects[i] != NULL); i++);

  if (i >= MAX_OBJECTS)
    return ERROR;

  /*Adition to game*/
  (game->objects)[i] = object;
  
  /*Init of the object's location in the first space of our game*/
  game_set_object_location(game, object, game_get_space_id_at(game, 0));

  return OK;
}

/**
* @brief It gets the pointer of an object in a game from its id.
* @author Francisco Vicente
* @date 30/10/2016
* @param game : the running game
* @param id : identifier of the object to be returned.
* @return Object : the pointer of the object whose id is the one in the input
*/
Object* game_get_object_pointer(Game* game, Id id) {
  int i = 0;
  Object* current_obj = NULL; /*It stores each objecct pointer in each iteration*/

  if(!game || id == NO_ID)
      return NULL;

  for(i = 0; i < MAX_OBJECTS; i++) {
    current_obj = game->objects[i];
    if(id == object_get_id(current_obj))
      return current_obj;
  }
  return NULL;
}

/**
* @brief It gets the pointer of a link in a gema from its id
* @author Lucia Colmenarejo
* @date 12/12/2016
* @param game : the running game
* @param id : identifier of the link to be returned.
* @return Link : the pointer of the link whose id is the one in the input
*/

Link* game_get_link(Game* game, Id id){
    int i = 0;

    if (id == NO_ID) {
        return NULL;
    }

    for (i = 0; i < MAX_SPACES && game->links[i] != NULL; i++) {
        if (id == link_get_id(game->links[i])) {
            return game->links[i];
        }
    }

    return NULL;
}


/**
* @brief It adds a link to the game
* @author Francisco Vicente
* @date 17/10/2016
* @param game : the running game
* @param link : the link to add
* @return Status : error control
*/
STATUS game_add_link(Game* game, Link* link) {
	  int i;

    if (!link || !game)
    	return ERROR;

    for(i = 0; (i < MAX_LINKS) && (game->links[i] != NULL); i++);

    if (i >= MAX_LINKS)
    	return ERROR;

    /*Adition to game*/
    game->links[i] = link;
    /*It completes the init process for every link in the pertinent space*/
    return game_add_link_spaces(game, link);
}

/**
* @brief It adds a link to space
* @author Francisco Vicente
* @date 17/10/2016
* @param game : the running game
* @param link : the link to add
* @return Status : error control
*/
STATUS game_add_link_spaces(Game* game, Link* link) {
    int i;
    int flag = 0;

    if (!link)
        return ERROR;

    /*Inside this loop, we replace all the temporal links which were set in 
    game_load_spaces (making sure the allocated memory for them is freed) 
    with the complete ones in the pertinent spaces*/
    for (i = 0; i < MAX_SPACES && flag == 0; i++) {

        if (link_compare_id(space_get_north(game->spaces[i]), link)) {
            link_destroy(space_get_north(game->spaces[i]));
            space_set_north(game->spaces[i], link);
            flag = 1;
           
        }
        else if (link_compare_id(space_get_east(game->spaces[i]), link)) {
            link_destroy(space_get_east(game->spaces[i]));
            space_set_east(game->spaces[i], link);
            flag = 1;
        }
        else if (link_compare_id(space_get_south(game->spaces[i]), link)) {
            link_destroy(space_get_south(game->spaces[i]));
            space_set_south(game->spaces[i], link);
            flag = 1;
        }
        else if (link_compare_id(space_get_west(game->spaces[i]), link)) {
            link_destroy(space_get_west(game->spaces[i]));
            space_set_west(game->spaces[i], link);
            flag = 1;
        }
        else if (link_compare_id(space_get_up(game->spaces[i]), link)) {
            link_destroy(space_get_up(game->spaces[i]));
            space_set_up(game->spaces[i], link);
            flag = 1;
        }
        else if (link_compare_id(space_get_down(game->spaces[i]), link)) {
            link_destroy(space_get_down(game->spaces[i]));
            space_set_down(game->spaces[i], link);
            flag = 1;
        }
    }
    return OK;
}

/**
* @brief It doesn't do anything
* @author Andres Salas
* @date 30/09/2016
* @param game : the running game
* @return STATUS : error control
*/
STATUS callback_UNKNOWN(Game* game) {
    return ERROR;
}

/**
* @brief It finishes the game
* @author Andres Salas
* @date 30/09/2016
* @param game : the running game
* @return STATUS : error control
*/
STATUS callback_QUIT(Game* game) {
  if(!game)
      return ERROR;
  return OK;
}

/**
* @brief It develops the action related to the command 'grab'. Firstly, after the error
* control, it checks whether the given object is in the space where the player
* is or not. If yes, the object is set in the player 'inventory' and it is 
* removed from that space.
* @author Francisco Vicente
* @date 30/10/2016
* @param game : the running game
* @param input : name of the object that may be grabbed
* @return STATUS : error control
*/
STATUS callback_GRAB(Game* game, char* input){
  Object* obj_current = NULL; /*the object which name is the second argument*/
  /*Locations of the player and the object, which should be the same*/
  Id player_loc = NO_ID;
  Id object_loc = NO_ID;
  int i;
  
  if(!game || !input) 
    return ERROR;

  if(inventory_is_full(player_get_inventory(game->player)))
    return ERROR;

  /*Process of getting the object pointer from its name*/
  for(i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++){
    if(!strcmp(input, object_get_name(game->objects[i])))
      obj_current = game->objects[i];
  }

  /*Object no portable*/
  if(!obj_current || object_get_portability(obj_current) == FALSE)
    return ERROR;

  /*Checking whether player is in the same space as the requested object*/
  player_loc = game_get_player_location(game);
  object_loc = game_get_object_location(game, object_get_id(obj_current));
  
  
  if(player_loc == object_loc){
    /*Moving object to the inventary*/
    player_add_object(game->player, obj_current);
    
    /*Removing object from the space*/
    space_delete_object(game_get_space(game, player_loc), obj_current);
    return OK;
  }
  return ERROR;
}

/**
* @brief It develops the action related to the command 'leave'. First of all, it
* checks whether the player has an object in their 'inventory' or not. If
* yes, the object is set in the space where the player is and then it removes
* the object from the player.
* @author Francisco Vicente
* @date 30/10/2016
* @param game : the running game
* @param input : name of the object that may be left
* @return STATUS : error control
*/
STATUS callback_LEAVE(Game* game, char* input){
    Object* obj_current = NULL; /*The object which is in the player's inventory*/
    Id obj_current_id; /*its Id*/
    int i;
    int flag = 0;

	  /*Process of getting the object pointer from its name*/
	  for(i = 0; i < MAX_OBJECTS && game->objects[i] != NULL && flag == 0; i++){
    	  if(!strcmp(input, object_get_name(game->objects[i]))) {
      		  obj_current = game->objects[i];
      		  flag = 1;
    	  }
  	}

  	obj_current_id = object_get_id(obj_current);
  	
  	/*Checking whether the input object is in the player's inventory or not*/
    if(player_search_id(game->player, obj_current_id) == FALSE)
      return ERROR;

    if(obj_current_id != NO_ID){
        /*Addition process to the space*/
        space_add_object(game_get_space(game, player_get_location(game->player)), 
                         obj_current);
    
        /*Remove process from the player's inventory*/
        player_delete_object(game->player, obj_current);
        return OK;
    }
    return ERROR;
}

/**
* @brief It rolls the die
* @author Andres Salas 
* @date 30/09/2016
* @param game : the running game
* @return STATUS : error control
*/
STATUS callback_ROLL(Game* game){

  return die_roll(game->die);
}

/**
* @brief It moves the player through the spaces 
* @author Andres Salas 
* @date 30/09/2016
* @param game : the running game
* @param direction : second input of the command
* @return STATUS : error control
*/
STATUS callback_GO(Game* game, char* direction) {
  Id current_id = NO_ID;
  Id space_id = NO_ID;
  DIRECTION dir;
  Space* current_space = NULL;
  Link* current_link = NULL;
    
  /*Process of getting the input direction*/
  if(!strcmp("north", direction) || !strcmp("n", direction)) {
  	dir = N;
  }
  else if(!strcmp("south", direction) || !strcmp("s", direction)) {
  	dir = S;
  }
  else if(!strcmp("east", direction) || !strcmp("e", direction)) {
  	dir = E;
  }
  else if(!strcmp("west", direction) || !strcmp("w", direction)) {
  	dir = W;
  }
  /*Other case: error because of an incorrect input*/
  else {
  	return ERROR;
  }
  
  /*Process of getting the current space*/
  space_id = game_get_player_location(game);
  if (space_id == NO_ID)
    return ERROR;
  current_space = game_get_space(game, space_id);
  
  /*Process of getting the arrival space*/
  if(dir == N) 
      		current_link = space_get_north(current_space);
  
  else if(dir == S)
      		current_link = space_get_south(current_space);
  
  else if(dir == E)
      		current_link = space_get_east(current_space);
  
  else if(dir == W) 
      		current_link = space_get_west(current_space);

  current_id = link_get_arrivalSpace(current_link);
  if (current_id != NO_ID) {
	   game_set_player_location(game, current_id);
     return OK;
  }
    
  return ERROR;
}

/**
* @brief It examines the object in a given space 
* @author Maria Barroso
* @date 30/09/2016
* @param game : the running game
* @param input : second input of the command
* @return STATUS : error control
*/


STATUS callback_EXAMINE(Game* game, char* input){
  Object* obj_current = NULL; /*the object whose name is the second argument*/
  /*Locations of the player*/
  Id player_loc = NO_ID;
  Space* space_current = NULL;
  int i;
  
  if(!game || !input) 
    return ERROR;

  player_loc = game_get_player_location(game);
  space_current = game_get_space(game, player_loc);

  /*INSP SPACE*/
  
  if(!strcmp(input, "space") || !strcmp(input, "s")) {
    if(space_get_iluminated(space_current)) { /*Checking whether the space is iluminated or not*/
  	  sprintf(game->last_desc, "Space %ld: %s",space_get_id(space_current),
                                             space_get_extraDesc(space_current));
  	  return OK;
    }
    else {
      return ERROR;
    }
  }

  /*INSP OBJ*/
  /*Process of getting the object pointer from its name*/
  for(i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++){
    if(!strcmp(input, object_get_name(game->objects[i])))
      obj_current = game->objects[i];
  }

  /*if input is not a valid object or space*/
  if(!obj_current)
    return ERROR;

  /*Checking whether player is in the same space as the requested object*/
  if(object_get_hidden(obj_current)==FALSE || space_is_object(space_current, obj_current) == TRUE || 
  	inventory_is_id(player_get_inventory(game->player), object_get_id(obj_current)) == TRUE) { /*object found*/
  	    if(object_get_movement(obj_current)==FALSE)
  		    printf(game->last_desc, "Object %s: %s", object_get_name(obj_current), object_get_description(obj_current));
  		  else printf(game->last_desc, "Object %s: %s", object_get_name(obj_current), object_get_aditDesc(obj_current));
  		  return OK;
  }

  /*Object not found*/
  else {
  	sprintf(game->last_desc, "Object not found.\n");
  	return ERROR;
  }
}



/**
* @brief It turns on the object that can be iluminated
* @author Lucía Colmenarejo 
* @date 2/12/2016
* @param game : the running game
* @param input : name of the object that may be turn on
* @return STATUS : error control
*/
STATUS callback_TURNON(Game* game, char* input){
  Object* obj_current = NULL; /*the object whose name is the second argument*/

  int i;
  
  if(!game || !input) 
    return ERROR;
    
  for(i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++){
      if(!strcmp(input, object_get_name(game->objects[i])))
        obj_current = game->objects[i];
  }

  /*if input is not a valid object*/
  if(!obj_current)
     return ERROR;
      
    
  if(object_get_lights(obj_current)==TRUE || inventory_is_id(player_get_inventory(game->player), object_get_id(obj_current)) == TRUE){
      if(object_get_activate(obj_current)==FALSE){
          if(object_set_activate(obj_current, TRUE)==OK){
            return OK;
          }
          return ERROR;
      }
  }
  return ERROR;
}

/**
* @brief It turns off the object that can be iluminated
* @author María Barroso 
* @date 2/12/2016
* @param game : the running game
* @param input : name of the object that may be grabbed
* @return STATUS : error control
*/
STATUS callback_TURNOFF(Game* game, char* input){
    Object* obj_current = NULL; /*the object whose name is the second argument*/
    /*Locations of the player*/
    int i;
    
    if(!game || !input) 
        return ERROR;
    
    for(i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++){
        if(!strcmp(input, object_get_name(game->objects[i])))
            obj_current = game->objects[i];
    }
  
    /*if input is not a valid object*/
    if(!obj_current)
        return ERROR;
    
    
    if(object_get_lights(obj_current)==TRUE || inventory_is_id(player_get_inventory(game->player), object_get_id(obj_current)) == TRUE){
        if(object_get_activate(obj_current)==TRUE){
            if(object_set_activate(obj_current, FALSE)==OK){
                return OK;
            }
            return ERROR;
        }
    }
    return ERROR;
}

/**
* @brief It open a link with an object
* @author María Barroso 
* @date 3/12/2016
* @param game : the running game
* @param inputLink : name of the link that may be oppened
* @param inputObject : name of the object witch may open the link
* @return STATUS : error control
*/

STATUS callback_OPEN(Game* game, char* inputLink, char* inputObject){
    Object* obj_current = NULL;
    Link* link_current = NULL;
    Id player_loc = NO_ID;
    int i, numids;
    Set* id_current;  /*Vigilar si vale con esta declaración o hacerla estática, 
                        además de cambiar este nombre de mierda*/
    
    if(!game || !inputObject || !inputLink) 
        return ERROR;
    
    player_loc = game_get_player_location(game);
    if(player_loc == NO_ID)
        return ERROR;
    
    /*Process of getting the object whose name is the second argument*/
    for(i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++){
        if(!strcmp(inputObject, object_get_name(game->objects[i])))
            obj_current = game->objects[i];
    }
    if(!obj_current)
        return ERROR;
        
    /*Process of getting the link whose name is the third argument*/
    for(i = 0; i < MAX_LINKS && game->links[i] != NULL; i++){
        if(!strcmp(inputLink, link_get_name(game->links[i])))
            link_current = game->links[i];
    }
    if(!link_current)
        return ERROR;
    
    id_current = object_get_opens(obj_current);
    if(!id_current)
        return ERROR;
        
    numids = set_get_num(object_get_opens(obj_current));
    
    if(inventory_is_id(player_get_inventory(game->player), object_get_id(obj_current)) == TRUE){
        for(i = 0; i < numids; i++){
            if(set_get_id_number(id_current, i) == link_get_id(link_current)){
                if(link_set_oorc(link_current, TRUE) == ERROR){
                    return ERROR;
                }
                return OK;
            }
        }
    }
    return ERROR;
}

/**
* @brief It saves the game
* @author María Barroso 
* @date 13/12/2016
* @param game : the running game
* @param input: name of the file where save the game
* @return STATUS : error control
*/

/*
STATUS callback_SAVE(Game* game, char* input){
    if(game==NULL|| input==NULL)
        return ERROR;
        
    return game_save(game, input);
}
*/

/**
* @brief It loads the game
* @author María Barroso 
* @date 13/12/2016
* @param game : the running game
* @param input: name of the file where load the game
* @return STATUS : error control
*/
/*
STATUS callback_LOAD(Game* game, char*input){
    if(game==NULL|| input==NULL)
        return ERROR;

    return game_load(game, input);
}
*/
