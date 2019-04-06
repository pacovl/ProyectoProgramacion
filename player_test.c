/* ===================================================================
File: player_test.c
Version: 1.0
Date: 24-11-2016
Author: Francisco Vicente

Description:
    It implements the player_test

Revision history:
Nov. 6, 2016 Version 1.0 (initial release)
=================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"
#include "test.h"


#define ID 1
#define MAX_TESTS 28
#define NAME "name"

BOOL test_player1(){ /*player_create ERROR passing NO_ID*/
	Player* player = NULL;
	player = player_create(NO_ID);

	if(!player)
		return TRUE;

	player_destroy(player);
	return FALSE;
}

BOOL test_player2(){ /*player_create OK*/
	Player* player = NULL;
	Id idaux = ID;
	player = player_create(idaux);

	if(!player)
		return FALSE;

	player_destroy(player);
	return TRUE;
}

BOOL test_player3(){/*player_destroy ERROR passing player*/
	Player * player = NULL;
	
	if(player_destroy(player) == ERROR)
		return TRUE;

	return FALSE;
}

BOOL test_player4(){/*player_destroy OKEY*/
	Player* player = NULL;
	Id idaux = ID;
	player = player_create(idaux);

	if(player_destroy(player) == OK)
		return TRUE;

	return FALSE;
}

BOOL test_player5(){  /*player_set_name ERROR passing player*/
	Player* player = NULL;
	char* name = NAME;

	if(player_set_name(player, name) == ERROR)
		return TRUE;
	
	return FALSE;
}

BOOL test_player6(){  /*player_set_name ERROR passing name*/
	Player* player = NULL;
	char* name = NULL;
	Id idaux = ID;
	player = player_create(idaux);

	if(player_set_name(player, name) == ERROR){
		player_destroy(player);
		return TRUE;
	}

	player_destroy(player);	
	return FALSE;
}

BOOL test_player7(){  /*player_set_name OKEY*/
	Player* player = NULL;
	Id idaux = ID;
	char* name = NAME;
	player = player_create(idaux);
	
	if(player_set_name(player, name) == OK){
		player_destroy(player);
		return TRUE;
	}
	
	player_destroy(player);
	return FALSE;
}

BOOL test_player8(){ /*player_set_location ERROR passing player*/
	Player* player = NULL;
	Id idaux = ID;
	Space* space = NULL;
	space = space_create(idaux);

	if(player_set_location(player, space) == ERROR){
		space_destroy(space);
		return TRUE;
	}

	space_destroy(space);
	return FALSE;
}

BOOL test_player9(){ /*player_set_location ERROR passing space*/
	Player *player = NULL;
	Id idaux = ID;
	Space * space = NULL;
	player = player_create(idaux);

	if(player_set_location(player, space) == ERROR){
		player_destroy(player);
		return TRUE;
	}

	player_destroy(player);
	return FALSE;
}

BOOL test_player10(){  /*player_set_location OKEY*/
	Player* player = NULL;
	Id idaux = ID;
	Space* space = NULL;
	space = space_create(idaux);
	player = player_create(idaux);
	
	if(player_set_location(player, space) == OK){
		space_destroy(space);
		player_destroy(player);
		return TRUE;
	}

	space_destroy(space);
	player_destroy(player);
	return FALSE;
}

BOOL test_player11(){  /*player_add_object ERROR passing player*/
	Player* player = NULL;
	Id idaux = ID;
	Object* object = NULL;
	object = object_create(idaux);
	
	if(player_add_object(player, object)==ERROR){
		object_destroy(object);
		return TRUE;
	}
	
	object_destroy(object);
	return FALSE;
}

BOOL test_player12(){  /*player_add_object ERROR passing object*/
	Player* player = NULL;
	Id idaux = ID;
	Object* object = NULL;
	player = player_create(idaux);
	
	if(player_add_object(player, object)==ERROR){
		player_destroy(player);
		return TRUE;
	}
	
	player_destroy(player);
	return FALSE;
}

BOOL test_player13(){  /*player_add_object OKEY*/
	Player* player = NULL;
	Id idaux = ID;
	Object* object = NULL;
	player = player_create(idaux);
	object = object_create(idaux);
	
	if(player_add_object(player, object) == OK){
		object_destroy(object);
		player_destroy(player);
		return TRUE;
	}

	object_destroy(object);
	player_destroy(player);
	return FALSE;
}

BOOL test_player14(){  /*player_delete_object ERROR passing player*/
	Id idaux = ID;
	Player* player = NULL;
	Object * object = NULL;
	object = object_create(idaux);

	if(player_delete_object(player, object) == ERROR){
		object_destroy(object);
		return TRUE;
	}

	object_destroy(object);
	return FALSE;
}

BOOL test_player15(){  /*player_delete_object ERROR passing object*/
	Id idaux = ID;
	Player* player = NULL;
	Object * object = NULL;
	player = player_create(idaux);

	if(player_delete_object(player, object) == ERROR){
		player_destroy(player);
		return TRUE;
	}
	
	player_destroy(player);
	return FALSE;
}

BOOL test_player16(){  /*player_delete_object OKEY*/
	Player* player = NULL;
	Id idaux = ID;
	Object* object= NULL;
	object = object_create(idaux);
	player = player_create(idaux);
	player_add_object(player, object);

	if(player_delete_object(player, object) == OK){
		object_destroy(object);
		player_destroy(player);
		return TRUE;
	}

	object_destroy(object);
	player_destroy(player);
	return FALSE;
}

BOOL test_player17(){ /*player_get_id ERROR passing player*/
	Player* player = NULL;
	
	if(player_get_id(player) == NO_ID)
		return TRUE;
	
	return FALSE;
}

BOOL test_player18(){ /*player_get_id OKEY*/
	Player* player = NULL;
	Id idaux = ID;
	player = player_create(idaux);
	
	if(player_get_id(player) == idaux){
		player_destroy(player);
		return TRUE;
	}    
	
	player_destroy(player);
	return FALSE;
}

BOOL test_player19(){ /*player_get_name ERROR passing player*/
	Player *player = NULL;

	if(player_get_name(player) == NULL)
		return TRUE;
	
	return FALSE;
}

BOOL test_player20(){/*player_get_name OKEY*/
	Id idaux = ID;
	Player *player = NULL;
	player = player_create(idaux);

	if(strcmp(player_get_name(player), "") == 0){
		player_destroy(player);
		return TRUE;
	}
	
	player_destroy(player);
	return FALSE;
}

BOOL test_player21(){ /* player_get_location ERROR passing player*/
	Player* player = NULL;
	Space* space = NULL;
	Id idaux = ID;
	space = space_create(idaux);
	
	player_set_location(player, space);
	
	if(player_get_location(player) == NO_ID){
		space_destroy(space);
		return TRUE;
	}
	
	space_destroy(space);
	return FALSE;
}

BOOL test_player22(){ /* player_get_location OK */
	Player* player = NULL;
	Space* space = NULL;
	Id idaux = ID;
	space = space_create(idaux);
	player = player_create(idaux);
	
	player_set_location(player, space);

    if(player_get_location(player) == idaux){
    	space_destroy(space);
    	player_destroy(player);
        return TRUE;
    }   
    
    space_destroy(space);
    player_destroy(player);
	return FALSE;
}

BOOL test_player23(){ /* player_get_inventory ERROR passing player*/
	Player* player = NULL;

	if(player_get_inventory(player) == NULL)
		return TRUE;
	
	return FALSE;
}

BOOL test_player24(){ /* player_get_inventory OK*/
	Player* player = NULL;
	Id idaux = ID;
	player = player_create(idaux);
	
	if(player_get_inventory(player) == NULL){
		player_destroy(player);
		return FALSE;
	}    
	
	player_destroy(player);
	return TRUE;
}

BOOL test_player25(){  /*player_search_id ERROR passing player*/
	Player* player = NULL;
	Id idaux = ID;
	Object* object = NULL;
	object = object_create(idaux);
	
	player_add_object(player, object);
	
	if(player_search_id(player, idaux) == FALSE){
		object_destroy(object);
		return TRUE;
	}
		
	object_destroy(object);
	return FALSE;
}


BOOL test_player26(){  /*player_search_id OKEY*/
	Player* player = NULL;
	Id idaux = ID;
	Object* object = NULL;
	object = object_create(idaux);
	player = player_create(idaux);
	
	player_add_object(player, object);
	
	if(player_search_id(player, idaux) == TRUE){
		object_destroy(object);
		player_destroy(player);
		return TRUE;
	}
	
	object_destroy(object);
	player_destroy(player);
	return FALSE;
}

BOOL test_player27(){ /*player_print ERROR passing player*/ 
	Player* player = NULL;
	
	if(player_print(player) == OK)
		return FALSE;
	
	return TRUE;
}

BOOL test_player28(){ /*player_print OKEY*/
	Id idaux = ID;
	Player* player= player_create(idaux);
	
	if(player_print(player) == OK){
		player_destroy(player);
		return TRUE;
	}
	
	player_destroy(player);
	return FALSE;
}


int main(int argc, char* argv[]){
	int test = 0;
	int all = 1;

	if(argc < 2)
		printf("Passing all tests to the Player module:\n");
	
	else{
		test = atoi(argv[1]);
		all = 0;
		if(test < 1 || test > MAX_TESTS){
			printf("Error, unrecognized test\n");
			exit(EXIT_SUCCESS);
		}
		printf("Passing test number %d to the Player module: \n", test);
	}

	if(all || test == 1) TEST_RESULT(test_player1());
	if(all || test == 2) TEST_RESULT(test_player2());
	if(all || test == 3) TEST_RESULT(test_player3());
	if(all || test == 4) TEST_RESULT(test_player4());
	if(all || test == 5) TEST_RESULT(test_player5());
	if(all || test == 6) TEST_RESULT(test_player6());
	if(all || test == 7) TEST_RESULT(test_player7());
	if(all || test == 8) TEST_RESULT(test_player8());
	if(all || test == 9) TEST_RESULT(test_player9());
	if(all || test == 10) TEST_RESULT(test_player10());
	if(all || test == 11) TEST_RESULT(test_player11());
	if(all || test == 12) TEST_RESULT(test_player12());
	if(all || test == 13) TEST_RESULT(test_player13());
	if(all || test == 14) TEST_RESULT(test_player14());
	if(all || test == 15) TEST_RESULT(test_player15());
	if(all || test == 16) TEST_RESULT(test_player16());
	if(all || test == 17) TEST_RESULT(test_player17());
	if(all || test == 18) TEST_RESULT(test_player18());
	if(all || test == 19) TEST_RESULT(test_player19());
	if(all || test == 20) TEST_RESULT(test_player20());
	if(all || test == 21) TEST_RESULT(test_player21());
	if(all || test == 22) TEST_RESULT(test_player22());
	if(all || test == 23) TEST_RESULT(test_player23());
	if(all || test == 24) TEST_RESULT(test_player24());
	if(all || test == 25) TEST_RESULT(test_player25());
	if(all || test == 26) TEST_RESULT(test_player26());
	if(all || test == 27) TEST_RESULT(test_player27());
	if(all || test == 28) TEST_RESULT(test_player28());
	__test_passed++;

	PRINT_PERCENTAGE;

	return 0;
}
