/**
 * @brief It defines the command interpreter
 * @file command.h
 * @author Francisco Vicente
 * @version 1.0
 * @date 23-09-2016
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "command.h"

/**
 * @brief Definition of the data structure
 */
struct _Command {
	T_Command numcmd; /*!< It storages the certain value of the enumeration */ 
	char aditionalInput[CMD_LENGHT]; /*!< It storages the aditional input as a string*/
	char extraInput[CMD_LENGHT]; /*!< It storages extra input for the open command*/
};

/* Declaration of privates functions */


/**
* @brief   It sets the input of a command structure.
* @author Francisco Vicente
* @date  1-11-2016
* @param cmd : the structure where the input may be set
* @param input : the string to be set as the input
* @return  STATUS : error control
*/
STATUS command_set_input(Command* cmd, char* input);

/**
* @brief  It sets the extra input of a command structure.
* @author Francisco Vicente
* @date  2-12-2016
* @param cmd : the structure where the input may be set
* @param input : the string to be set as the extra input
* @return STATUS : error control
*/
STATUS command_set_extraInput(Command* cmd, char* extraInput);

/**
* @brief   It sets the value of the enumeration stored in our structure.
* @author Francisco Vicente
* @date  1-11-2016
* @param cmd : the structure
* @param numcmd : the specific command 
* @return  STATUS : error control
*/
STATUS command_set_numcmd(Command* cmd, T_Command numcmd);

/* Implementation of public functions */

/**
* @brief   It creates a new structure.
* @author Francisco Vicente
* @date  1-11-2016
* @param -
* @return  Command : the new created structure
*/
Command* command_create(){
	Command* cmd;

	cmd = (Command *) malloc (sizeof(Command));
	if (!cmd)
		return NULL;
	
	cmd->numcmd = UNKNOWN;
	cmd->aditionalInput[0] = '\0';
	
	return cmd;
}

/**
* @brief   It destroys the command structure.
* @author Francisco Vicente
* @date  1-11-2016
* @param cmd : the structure to be removed
* @return  STATUS : error control
*/
STATUS command_destroy(Command* cmd){
	if(!cmd)
		return ERROR;
	
	free(cmd);
	cmd = NULL;
	
	return OK;
}


/**
* @brief It interprets the user input
* @author Francisco Vicente
* @date  23-09-2016
* @param cmd : the previous cmd to be modified
* @return Command : a command given by the user input
*/
Command* get_user_input(Command* cmd) {
	char input[CMD_LENGHT] = ""; /*It stores the written (by console) command*/
	char aditionalInput[CMD_LENGHT] = ""; /*It storages the first aditional 
											input in some commands*/
	char extraInput[CMD_LENGHT] = ""; /*It storages the second aditional input
										in the open command*/
	char nexus[5] = "";
	 
	if(!cmd)
		return NULL;

	if (scanf("%s", input) > 0) {

		if (!strcmp(input, "q") || !strcmp(input, "quit")) {
			command_set_numcmd(cmd, QUIT); /*0*/
		}
		else if (!strcmp(input, "n") || !strcmp(input, "next")) {
			command_set_numcmd(cmd, NEXT); /*1*/
		}
		else if (!strcmp(input, "b") || !strcmp(input, "back")) {
			command_set_numcmd(cmd, BACK); /*2*/
		}
		else if (!strcmp(input, "grab")) {
			/*Read process of the second input (the specific object to be grabed)*/
			if(scanf("%s", aditionalInput) > 0) {
				command_set_input(cmd, aditionalInput);
				command_set_numcmd(cmd, GRAB); /*3*/
			}
		}
		else if (!strcmp(input, "l") || !strcmp(input, "leave")) {
			if(scanf("%s", aditionalInput) > 0) {
				command_set_input(cmd, aditionalInput);
				command_set_numcmd(cmd, LEAVE); /*4*/
			}
		} 
		else if (!strcmp(input, "j") || !strcmp(input, "jump")) {
			command_set_numcmd(cmd, JUMP); /*5*/
		}
		else if (!strcmp(input, "r") || !strcmp(input, "roll")) {
			command_set_numcmd(cmd, ROLL); /*6*/
		}
		else if (!strcmp(input, "g") || !strcmp(input, "go")) {
			/*Read process of the second input (the direction to go)*/
			if(scanf("%s", aditionalInput) > 0) {
				command_set_input(cmd, aditionalInput);
				command_set_numcmd(cmd, GO); /*7*/
			}
		}
		else if (!strcmp(input, "e") || !strcmp(input, "examine")) {
			/*Read process of the second input (the specific object or space to be inspected)*/
			if(scanf("%s", aditionalInput) > 0) {
				command_set_input(cmd, aditionalInput);
				command_set_numcmd(cmd, EXAMINE); /*8*/
			} 
		}
		else if (!strcmp(input, "turnon") || !strcmp(input, "ton")) {
			/*Read process of the second input (the specific object to be iluminated)*/
			if(scanf("%s", aditionalInput) > 0) {
				command_set_input(cmd, aditionalInput);
				command_set_numcmd(cmd, TURNON); /*9*/
			}
		}
		else if (!strcmp(input, "turnoff") || !strcmp(input, "toff")) {
			if(scanf("%s", aditionalInput) > 0) {
				command_set_input(cmd, aditionalInput);
				command_set_numcmd(cmd, TURNOFF); /*10*/
			}
		} 
		else if (!strcmp(input, "open") || !strcmp(input, "o")) {
			/*Hay que ampliarlo bastante*/
			if(scanf("%s", aditionalInput) > 0 && scanf("%s", nexus) > 0 && scanf("%s", extraInput) > 0) { /*No estoy seguro de que lo vaya a leer bien*/
				if(!strcmp(nexus, "with")) {  /*Hacer control de errores!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!???*/
					command_set_input(cmd, aditionalInput);
					command_set_extraInput(cmd, extraInput);
					command_set_numcmd(cmd, OPEN_LINK); /*10*/
				}
			}
		}
		else {
			command_set_numcmd(cmd, UNKNOWN); /*-1*/
		} 
	}
	return cmd;
}

/**
* @brief It returns the input stored in our structure.
* @author Francisco Vicente
* @date  1-11-2016
* @param cmd : the structure
* @return char* : the aditional input of the command
*/
char* command_get_input(Command* cmd){
	if(!cmd)
		return NULL;

	return cmd->aditionalInput;
} 

/**
* @brief It returns the extra input stored in our structure.
* @author Francisco Vicente
* @date  2-12-2016
* @param cmd : the structure
* @return char* : the extra input of the command
*/
char* command_get_extraInput(Command* cmd){
	if(!cmd)
		return NULL;

	return cmd->extraInput;
} 

/**
* @brief It returns the value of the enumeration stored in our structure.
* @author Francisco Vicente
* @date  1-11-2016
* @param cmd : the structure
* @return T_Command : the specified command
*/
T_Command command_get_numcmd(Command* cmd) {
	if(!cmd)
		return UNKNOWN;

	return cmd->numcmd;
}

/**
 * @brief Implementation of private functions
 */


/**
* @brief  It sets the input of a command structure.
* @author Francisco Vicente
* @date  1-11-2016
* @param cmd : the structure where the input may be set
* @param input : the string to be set as the input
* @return STATUS : error control
*/
STATUS command_set_input(Command* cmd, char* input){
	if(!cmd || !input)
		return ERROR;

	if(strcpy(cmd->aditionalInput, input) == NULL)
		return ERROR;

	return OK;
}

/**
* @brief  It sets the extra input of a command structure.
* @author Francisco Vicente
* @date  2-12-2016
* @param cmd : the structure where the input may be set
* @param input : the string to be set as the extra input
* @return STATUS : error control
*/
STATUS command_set_extraInput(Command* cmd, char* extraInput) {
	if(!cmd || !extraInput)
		return ERROR;
		
	if(strcpy(cmd->extraInput, extraInput) == NULL)
		return ERROR;
	
	return OK;
}

/**
* @brief  It sets the value of the enumeration stored in our structure.
* @author Francisco Vicente
* @date  1-11-2016
* @param cmd : the structure
* @param numcmd : the specific command 
* @return STATUS : error control
*/
STATUS command_set_numcmd(Command* cmd, T_Command numcmd) {
	if(!cmd || numcmd < NO_CMD || numcmd > LOAD)
		return UNKNOWN;

	cmd->numcmd = numcmd;

	return OK;
}

