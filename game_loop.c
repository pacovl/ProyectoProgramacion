/**
 * @brief It implements the game loop
 * @file game_loop.c
 * @author Andres Salas, Francisco Vicente, Lucia Colmenarejo and Maria Barroso
 * @version 1.0
 * @date 23-09-2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h" /*types*/


/*Temporary macros for the id number of player and object, which can be random*/

/**
 * @brief Definition of macro PLA_ID
*/

#define PLA_ID 1

/**
 * @brief Definition of macro DIE_ID
*/

#define DIE_ID 1

/**
 * @brief Definition of the main function
 */
int main(int argc, char *argv[]){
	Game* game;  
	Id player;
	Id die;
	FILE *f = NULL;
	Command* cmd = NULL;

	if (argc < 4) { /*Files missing*/
		fprintf(stderr, "Use: %s <spaces_data_file> <objects_data_file>"
			" <links_data_file> -l <log_file> -nv\n\t Where the last three" 
			" arguments are optional and the order matters.\n", argv[0]); 
		return EXIT_FAILURE;
	}
	else if(argc > 4) { /*Optional arguments*/
		if (argc == 5 && !strcmp(argv[4], "-nv")) {
		/*-nv*/	
		}
		else if(argc == 6 && !strcmp(argv[4], "-l")) { 
		/*-l <log_file>*/
		}
		else if(argc == 7 && !strcmp(argv[4], "-l") && !strcmp(argv[6], "-nv")) {
		/*-l <log_file> -nv*/
		}
		else { /*Input error*/
			fprintf(stderr, "Use: %s <spaces_data_file> <objects_data_file>"
			" <links_data_file> -l <log_file> -nv\n\t Where the last three" 
			" arguments are optional and the order matters.\n", argv[0]); 
			return EXIT_FAILURE;
		}
	}
	
	/*Arguments for initializing the game*/
	game = game_create();
	if(!game)
		return EXIT_FAILURE;
	player = PLA_ID;
	die = DIE_ID;

	/*Init process*/
	if (game_init_from_file(game, argv[1], argv[2], argv[3], player, die) == ERROR) {
		fprintf(stderr, "Error while initializing game.\n"); 
		game_destroy(game);
		return EXIT_FAILURE;
	}

	/*Log option, creating/opening log file*/
	if(argc == 6 || argc == 7) {
		f = fopen(argv[5], "w");
		if (!f) {
			game_destroy(game);
			return EXIT_FAILURE;
		}
	}

	/*Mommand type creation*/
	cmd = command_create();
	if(!cmd) {
		game_destroy(game);
		return EXIT_FAILURE;
	}
	
	/*Main loop of the game*/
	while ((command_get_numcmd(cmd) != QUIT) && !game_is_over(game)) {
		if(argc != 5 && argc != 7) /*-nv option check*/
			game_print_screen(game);
		cmd = get_user_input(cmd);
		game_update(game, cmd, f);
	} 

	/*Close and destroy processes before the programm finishes*/
	command_destroy(cmd);
	if(argc == 6 || argc == 7)
		fclose(f);
	game_destroy(game);
	
	return EXIT_SUCCESS;
}