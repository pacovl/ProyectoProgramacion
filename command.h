/**
 * @brief It defines the command interpreter
 * @file command.h
 * @author Francisco Vicente
 * @version 1.0
 * @date 23-09-2016
 */

#ifndef COMMAND_H
#define COMMAND_H
#include "types.h"

/**
 * @brief Definition of macros
*/

#define CMD_LENGHT 30 /* max size of the input*/

/**
 * @brief Definition of command structure
*/

typedef struct _Command Command; /*<! Definition of the command structure */

/**
 * @brief Definition of data enumeration
*/ 

typedef enum { 
  NO_CMD = -2, 
  UNKNOWN,/*-1*/
  QUIT,   /*0*/
  NEXT,   /*1*/
  BACK,   /*2*/
  GRAB,   /*3*/
  LEAVE,  /*4*/
  JUMP,   /*5*/
  ROLL,   /*6*/
  GO,     /*7*/
  EXAMINE,/*8*/
  TURNON, /*9*/
  TURNOFF, /*10*/
  OPEN_LINK,/*11*/
  SAVE,   /*12*/
  LOAD    /*13*/
} T_Command;


/**
* @brief It creates a new structure.
* @author Francisco Vicente
* @date 1-11-2016
* @param -
* @return Command : the new created structure
*/


Command* command_create();


/**
* @brief It destroys the command structure.
* @author Francisco Vicente
* @date  1-11-2016
* @param cmd : the structure to be removed
* @return STATUS : error control
*/
STATUS command_destroy(Command* cmd);


/**
* @brief It interprets the user input
* @author Francisco Vicente
* @date  23-09-2016
* @param cmd : the previous cmd to be modified
* @return Command : a command given by the user input
*/
Command* get_user_input(Command* cmd);


/**
* @brief It returns the value of the enumeration stored in our structure.
* @author Francisco Vicente
* @date  1-11-2016
* @param cmd : the structure
* @return T_Command : the specified command
*/
T_Command command_get_numcmd(Command* cmd);

/**
* @brief It returns the extra input stored in our structure.
* @author Francisco Vicente
* @date  2-12-2016
* @param cmd : the structure
* @return char* : the extra input of the command
*/
char* command_get_extraInput(Command* cmd);


/**
* @brief It returns the input stored in our structure.
* @author Francisco Vicente
* @date  1-11-2016
* @param cmd : the structure
* @return char* : the aditional input of the command
*/
char* command_get_input(Command* cmd);

#endif
