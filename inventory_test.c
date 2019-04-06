/* ===================================================================
File: inventory_test.c
Version: 1.0
Date: 24-11-2016
Author: Andres Salas

Description:
    It implements the inventory_test

Revision history:
Nov. 6, 2016 Version 1.0 (initial release)
=================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include "inventory.h"
#include "test.h"


#define ID 1
#define ID2 5
#define MAX_TESTS 24

BOOL test_inventory1(){ /*inventory_create OKEY*/
	Inventory* inventory = NULL;
	inventory = inventory_create();

	if(!inventory)
		return FALSE;

	inventory_destroy(inventory);
	return TRUE;
}


BOOL test_inventory2(){/*inventory_destroy ERROR passing inventory*/
	Inventory* inventory = NULL;

	if(inventory_destroy(inventory) == ERROR)
		return TRUE;

	return FALSE;
}

BOOL test_inventory3(){/*inventory_destroy OKEY*/
	Inventory* inventory = NULL;
	inventory = inventory_create();

	if(inventory_destroy(inventory) == ERROR)
		return FALSE;

	return TRUE;
}

BOOL test_inventory4(){/*inventory_add_id ERROR passing inventory*/
	Inventory* inventory = NULL;

	if(inventory_add_id(inventory, NO_ID) == OK){
		return FALSE;
	}

	return TRUE;
}

BOOL test_inventory5(){/*inventory_add_id ERROR paso ID*/
	Inventory* inventory = NULL;
	inventory = inventory_create();

	if(inventory_add_id(inventory, NO_ID) == OK){
		inventory_destroy(inventory);
		return FALSE;
	}

	inventory_destroy(inventory);
	return TRUE;
}

BOOL test_inventory6(){/* inventory_add_id ERROR is full*/
	Id arrayids[MAX_OBJ];
	Id idaux = 100;
	int i;
	Inventory* inventory = NULL;
	inventory = inventory_create();
	
	for(i=0; i<MAX_OBJ;i++){
		arrayids[i] = i;
		inventory_add_id(inventory, arrayids[i]);
	}

	if(inventory_add_id(inventory, idaux) == ERROR){
		inventory_destroy(inventory);
		return TRUE;
	}

	inventory_destroy(inventory);
	return FALSE;
}

BOOL test_inventory7(){/*inventory_add_id OKEY*/
	Inventory* inventory = NULL;
	inventory = inventory_create();

	if(inventory_add_id(inventory, ID2) == OK){
		inventory_destroy(inventory);
		return TRUE;
	}

	inventory_destroy(inventory);
	return FALSE;
}

BOOL test_inventory8(){/*inventory_is_full ERROR passing inventory*/
	Inventory* inventory = NULL;

	if(inventory_is_full(inventory) == TRUE){
		inventory_destroy(inventory);
		return FALSE;
	}

	inventory_destroy(inventory);
	return TRUE;
}

BOOL test_inventory9(){/*inventory_is_full ERROR only one id*/
	Inventory* inventory = NULL;
	inventory = inventory_create();

	inventory_add_id(inventory, ID);
	if(inventory_is_full(inventory) == TRUE){
		inventory_destroy(inventory);
		return FALSE;
	}

	inventory_destroy(inventory);
	return TRUE;
}

BOOL test_inventory10(){/*inventory_is_full OKEY*/
	int i;
	Id arrayids[MAX_OBJ];
	Inventory* inventory = NULL;
	inventory = inventory_create();
	
	for(i=0; i<MAX_OBJ;i++){
		arrayids[i] = i;
		inventory_add_id(inventory, arrayids[i]);
	}


	if(inventory_is_full(inventory) == TRUE){
		inventory_destroy(inventory);
		return TRUE;
	}

	inventory_destroy(inventory);
	return FALSE;
}

BOOL test_inventory11(){/*inventory_delete_id ERROR passing inventory*/
	Inventory* inventory = NULL;

	if(inventory_delete_id(inventory, ID) == OK)
		return FALSE;

	return TRUE;
}

BOOL test_inventory12(){/*inventory_delete_id ERROR nothing in inventory*/
	Inventory* inventory = NULL;
	inventory = inventory_create();

	if(inventory_delete_id(inventory, ID) == OK){
		inventory_destroy(inventory);
		return FALSE;
	}

	inventory_destroy(inventory);
	return TRUE;
}

BOOL test_inventory13(){/*inventory_delete_id ERROR not id in inventory*/
	Inventory* inventory = NULL;
	inventory = inventory_create();

	inventory_add_id(inventory, ID);
	if(inventory_delete_id(inventory, ID2) == OK){
		inventory_destroy(inventory);
		return FALSE;
	}

	inventory_destroy(inventory);
	return TRUE;
}

BOOL test_inventory14(){/*inventory_delete_id OKEY*/
	Inventory* inventory = NULL;
	inventory = inventory_create();

	inventory_add_id(inventory, ID);
	if(inventory_delete_id(inventory, ID) == OK){
		inventory_destroy(inventory);
		return TRUE;
	}

	inventory_destroy(inventory);
	return FALSE;
}

BOOL test_inventory15(){/*inventory_get_ids ERROR passing inventory*/
	Set* set=NULL;
	Inventory* inventory = NULL;
	
	set = set_create();
	set_add(set, ID);

	if(set_get_id_number(inventory_get_ids(inventory),0) == set_get_id_number(set,0)){
		set_destroy(set);
		return FALSE;
	}

	set_destroy(set);
	return TRUE;		
}

BOOL test_inventory16(){/*inventory_get_ids OKEY*/
	Set* set=NULL;
	Inventory* inventory = NULL;
	
	set = set_create();
	set_add(set, ID);

	inventory = inventory_create();
	inventory_add_id(inventory,ID);

	if(set_get_id_number(inventory_get_ids(inventory),0) == set_get_id_number(set,0)){
		inventory_destroy(inventory);
		set_destroy(set);
		return TRUE;
	}

	inventory_destroy(inventory);
	set_destroy(set);
	return FALSE;		
}

BOOL test_inventory17(){/*inventory_is_id ERROR passing inventory*/
	Inventory* inventory = NULL;
	
	if(inventory_is_id(inventory, ID) == TRUE){
		return FALSE;
	}

	return TRUE;
}

BOOL test_inventory18(){/*inventory_is_id ERROR passing NO_ID*/
	Inventory* inventory = NULL;
	inventory = inventory_create();

	inventory_add_id(inventory, ID);
	if(inventory_is_id(inventory, NO_ID) == TRUE){
		inventory_destroy(inventory);
		return FALSE;
	}

	inventory_destroy(inventory);
	return TRUE;
}

BOOL test_inventory19(){/*inventory_is_id ERROR the id2 is not in the inventory*/
	Inventory* inventory = NULL;
	inventory = inventory_create();

	inventory_add_id(inventory, ID);
	if(inventory_is_id(inventory, ID2) == TRUE){
		inventory_destroy(inventory);
		return FALSE;
	}

	inventory_destroy(inventory);
	return TRUE;
}

BOOL test_inventory20(){/*inventory_is_id OKEY*/
	Inventory* inventory = NULL;
	inventory = inventory_create();

	inventory_add_id(inventory, ID);
	if(inventory_is_id(inventory, ID2) == TRUE){
		inventory_destroy(inventory);
		return FALSE;
	}

	inventory_destroy(inventory);
	return TRUE;
}

BOOL test_inventory21(){/*inventory_get_maxobj ERROR pasing inventory*/
	Inventory* inventory = NULL;

	if(inventory_get_maxobj(inventory) == MAX_OBJ){
		return FALSE;
	}

	return TRUE;
}

BOOL test_inventory22(){/*inventory_get_maxobj OKEY*/
	Inventory* inventory = NULL;
	inventory = inventory_create();

	if(inventory_get_maxobj(inventory) == MAX_OBJ){
		inventory_destroy(inventory);
		return TRUE;
	}

	inventory_destroy(inventory);
	return FALSE;
}

BOOL test_inventory23(){/* inventory_print ERROR passing inventory*/
	Inventory* inventory = NULL;

	if(inventory_print(inventory) == OK)
		return FALSE;

	return TRUE;
}

BOOL test_inventory24(){/* inventory_print OKEY*/
	Inventory* inventory = NULL;
	inventory = inventory_create();

	if(inventory_print(inventory) == OK){
		inventory_destroy(inventory);
		return TRUE;
	}

	inventory_destroy(inventory);
	return FALSE;
}

int main(int argc, char* argv[]){
	int test = 0;
	int all = 1;

	if(argc < 2)
		printf("Passing all tests to the Inventory module:\n");
	
	else{
		test = atoi(argv[1]);
		all = 0;
		if(test < 1 || test > MAX_TESTS){
			printf("Error, unrecognized test\n");
			exit(EXIT_SUCCESS);
		}
		printf("Passing test number %d to the Player module: \n", test);
	}

	if(all || test == 1) TEST_RESULT(test_inventory1());
	if(all || test == 2) TEST_RESULT(test_inventory2());
	if(all || test == 3) TEST_RESULT(test_inventory3());
	if(all || test == 4) TEST_RESULT(test_inventory4());
	if(all || test == 5) TEST_RESULT(test_inventory5());
	if(all || test == 6) TEST_RESULT(test_inventory6());
	if(all || test == 7) TEST_RESULT(test_inventory7());
	if(all || test == 8) TEST_RESULT(test_inventory8());
	if(all || test == 9) TEST_RESULT(test_inventory9());
	if(all || test == 10) TEST_RESULT(test_inventory10());
	if(all || test == 11) TEST_RESULT(test_inventory11());
	if(all || test == 12) TEST_RESULT(test_inventory12());
	if(all || test == 13) TEST_RESULT(test_inventory13());
	if(all || test == 14) TEST_RESULT(test_inventory14());
	if(all || test == 15) TEST_RESULT(test_inventory15());
	if(all || test == 16) TEST_RESULT(test_inventory16());
	if(all || test == 17) TEST_RESULT(test_inventory17());
	if(all || test == 18) TEST_RESULT(test_inventory18());
	if(all || test == 19) TEST_RESULT(test_inventory19());
	if(all || test == 20) TEST_RESULT(test_inventory20());
	if(all || test == 21) TEST_RESULT(test_inventory21());
	if(all || test == 22) TEST_RESULT(test_inventory22());
	if(all || test == 23) TEST_RESULT(test_inventory23());
	if(all || test == 24) TEST_RESULT(test_inventory24());
	__test_passed++;
	

	PRINT_PERCENTAGE;

	return 0;
}
