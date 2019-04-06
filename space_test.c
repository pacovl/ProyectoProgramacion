/* ===================================================================
File: space_test.c
Version: 1.0
Date: 24-11-2016
Author: Lucía Colmenarejo

Description:
    It implements the space_test

Revision history:
Nov. 6, 2016 Version 1.0 (initial release)
=================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "space.h"
#include "test.h"

#define ID 1
#define ID2 2
#define NAME "name"
#define DESCRIPTION "description"
#define GDESC1 "gdesc1"
#define GDESC2 "gdesc2"
#define GDESC3 "gdesc3"
#define MAX_TESTS 111
#define ROW 2


BOOL test_space1(){/*space_create ERROR passing NO_ID*/
	Space* space = NULL;
	space = space_create(NO_ID);

	if(!space)
		return TRUE;

	space_destroy(space);
	return FALSE;
}

BOOL test_space2(){ /*space_create OK*/
	Id idaux = ID;
	Space* space = NULL;
	space = space_create(idaux);

	if(!space)
		return FALSE;

	space_destroy(space);
	return TRUE;
}


BOOL test_space3(){/*space_destroy ERROR passing space*/
	Space* space = NULL;

	if(space_destroy(space) == ERROR)
		return TRUE;

	return FALSE;
}

BOOL test_space4(){/*space_destroy OK*/
	Id idaux = ID;
	Space* space = NULL;
	space = space_create(idaux);

	if(space_destroy(space) == OK)
		return TRUE;

	return FALSE;
}

BOOL test_space5(){  /*space_set_name ERROR passing space*/
	Space* space = NULL;
	char *name = NAME;

	if(space_set_name(space, name) == ERROR)
		return TRUE;
	
	return FALSE;
}

BOOL test_space6(){  /*space_set_name ERROR passing name*/
	Space* space = NULL;
	Id idaux = ID;
	char *name = NULL;
	space = space_create(idaux);

	if(space_set_name(space, name) == ERROR){
		space_destroy(space);
		return TRUE;
	}

	space_destroy(space);
	return FALSE;
}

BOOL test_space7(){/*space_set_name OK*/
	Space* space = NULL;
	Id idaux = ID;
	char *name = NAME;
	space = space_create(idaux);

	if(space_set_name(space, name) == OK){
		space_destroy(space);
		return TRUE;
	}

	space_destroy(space);
	return FALSE;
}

BOOL test_space8(){/*space_set_iluminated ERROR passing space*/
	Space* space = NULL;
	BOOL state = TRUE;
	
	if(space_set_iluminated(space, state) == ERROR)
		return TRUE;
	
	return FALSE;
}

BOOL test_space9(){/*space_set_iluminated OK*/
	Space* space = NULL;
	Id idaux = ID;
	BOOL state = TRUE;
	space = space_create(idaux);
	
	
	if(space_set_iluminated(space, state) == OK){
		space_destroy(space);
		return TRUE;
	}
	
	space_destroy(space);
	return FALSE;
}

BOOL test_space10(){  /*space_set_gdesc ERROR passing space*/
	Space* space = NULL;
	char* gdesc1 = GDESC1;
	char* gdesc2 = GDESC2;
	char* gdesc3 = GDESC3;

	if(space_set_gdesc(space, gdesc1, gdesc2, gdesc3)==ERROR)
		return TRUE;

	return FALSE;
}

BOOL test_space11(){  /*space_set_gdesc ERROR passing gdesc1*/
	Space* space = NULL;
	Id idaux = ID;
	char* gdesc1 = NULL;
	char* gdesc2 = GDESC2;
	char* gdesc3 = GDESC3;
	space = space_create(idaux);

	if(space_set_gdesc(space, gdesc1, gdesc2, gdesc3) == ERROR)
		space_destroy(space);
		return TRUE;
	
	space_destroy(space);
	return FALSE;
}

BOOL test_space12(){  /*space_set_gdesc ERROR passing gdesc2*/
	Space* space = NULL;
	Id idaux = ID;
	char* gdesc1 = GDESC1;
	char* gdesc2 = NULL;
	char* gdesc3 = GDESC3;
	space = space_create(idaux);

	if(space_set_gdesc(space, gdesc1, gdesc2, gdesc3) == ERROR)
		space_destroy(space);
		return TRUE;
	
	space_destroy(space);
	return FALSE;
}

BOOL test_space13(){  /*space_set_gdesc ERROR passing gdesc3*/
	Space* space = NULL;
	Id idaux = ID;
	char* gdesc1 = GDESC1;
	char* gdesc2 = GDESC2;
	char* gdesc3 = NULL;
	space = space_create(idaux);

	if(space_set_gdesc(space, gdesc1, gdesc2, gdesc3) == ERROR)
		space_destroy(space);
		return TRUE;
	
	space_destroy(space);
	return FALSE;
}

BOOL test_space14(){/*space_set_gdesc OK*/
	Space* space = NULL;
	Id idaux = ID;
	char* gdesc1 = GDESC1;
	char* gdesc2 = GDESC2;
	char* gdesc3 = GDESC3;
	space = space_create(idaux);

	if(space_set_gdesc(space, GDESC1, GDESC2, GDESC3) == OK){
		space_destroy(space);
		return TRUE;
	}

	space_destroy(space);
	return FALSE;
}

BOOL test_space15(){  /*space_set_description ERROR passing space*/
	Space* space = NULL;
	char* description = DESCRIPTION;

	if(space_set_description(space, description) == ERROR)
		return TRUE;
	
	return FALSE;
}


BOOL test_space16(){  /*space_set_description ERROR passing char*/
	Space* space = NULL;
	Id idaux = ID;
	char* description = NULL;
	space = space_create(idaux);

	if(space_set_description(space, description) == ERROR){
		space_destroy(space);
		return TRUE;
	}

	space_destroy(space);
	return FALSE;
}

BOOL test_space17(){/*space_set_description OK*/
	Id idaux = ID;
	Space* space = NULL;
	space = space_create(idaux);
	char*  description = DESCRIPTION;

	if(space_set_description(space, description) == OK){
		space_destroy(space);
		return TRUE;
	}

	space_destroy(space);
	return FALSE;
}

BOOL test_space18(){/*space_set_extraDesc ERROR passing space*/
	Space* space = NULL;
	char* extraDesc = DESCRIPTION;
	
	if(space_set_extraDesc(space, extraDesc) == ERROR)
		return TRUE;
	
	return FALSE;
}

BOOL test_space19(){/*space_set_extraDesc ERROR passing extraDesc*/
	Space* space = NULL;
	Id idaux = ID;
	char* extraDesc = NULL;
	space = space_create(idaux);
	
	if(space_set_extraDesc(space, extraDesc) == ERROR){
		space_destroy(space);
		return TRUE;
	}
	
	space_destroy(space);
	return FALSE;
}

BOOL test_space20(){/*space_set_extraDesc OK*/
	Space* space = NULL;
	Id idaux = ID;
	char* extraDesc = DESCRIPTION;
	space = space_create(idaux);
	
	if(space_set_extraDesc(space, extraDesc) == ERROR){
		space_destroy(space);
		return FALSE;
	}
	
	space_destroy(space);
	return TRUE;
}	

BOOL test_space21(){  /*space_set_north ERROR passing space*/
	Id idaux = ID;
	Space* space = NULL;
	Link* link = NULL;
	link = link_create(idaux);

	if(space_set_north(space, link) == ERROR){
		link_destroy(link);
		return TRUE;
	}

	link_destroy(link);
	return FALSE;
}

BOOL test_space22(){  /*space_set_north ERROR passing link*/
	Id idaux = ID;
	Space* space = NULL;
	Link* link = NULL;
	space = space_create(idaux);

	if(space_set_north(space, link) == ERROR){
		space_destroy(space);
		return TRUE;
	}

	space_destroy(space);
	return FALSE;
}

BOOL test_space23(){/*space_set_north OK*/
	Id idaux = ID;
	Space* space = NULL;
	space = space_create(idaux);
	Link* link = NULL;
	link = link_create(idaux);

	if(space_set_north(space, link) == OK){
		space_destroy(space);
		return TRUE;
	}

	space_destroy(space);
	link_destroy(link);
	return FALSE;
}

BOOL test_space24(){  /*space_set_south ERROR passing space*/
	Id idaux = ID;
	Space* space = NULL;
	Link* link = NULL;
	link = link_create(idaux);

	if(space_set_south(space, link) == ERROR){
		link_destroy(link);
		return TRUE;
	}
	
	link_destroy(link);
	return FALSE;
}

BOOL test_space25(){  /*space_set_south ERROR passing link*/
	Id idaux = ID;
	Space* space = NULL;
	Link* link = NULL;
	space = space_create(idaux);

	if(space_set_south(space, link) == ERROR){
		space_destroy(space);
		return TRUE;
	}
	
	space_destroy(space);
	return FALSE;
}

BOOL test_space26(){/*space_set_south OK*/
	Id idaux = ID;
	Space* space = NULL;
	space = space_create(idaux);
 	Link* link = NULL;
	link = link_create(idaux);
	
	if(space_set_south(space, link) == OK){
 		space_destroy(space);
		return TRUE;
	}
	
	link_destroy(link);
	space_destroy(space);
	return FALSE;
}

BOOL test_space27(){  /*space_set_east ERROR passing space*/
	Id idaux = ID;
	Space* space = NULL;
	Link* link = NULL;
	link = link_create(idaux);
	
	if(space_set_east(space, link) == ERROR){
		link_destroy(link);
		return TRUE;
	}
	
	link_destroy(link);
	return FALSE;
}

BOOL test_space28(){  /*space_set_east ERROR passing link*/
	Id idaux = ID;
	Space* space = NULL;
	Link* link = NULL;
	space = space_create(idaux);
	
	if(space_set_east(space, link) == ERROR){
		space_destroy(space);
		return TRUE;
	}
	
	space_destroy(space);
	return FALSE;
}

BOOL test_space29(){/*space_set_east OK*/
	Id idaux = ID;
	Space* space = NULL;
	space = space_create(idaux);
	Link* link = NULL;
	link = link_create(idaux);
	
	if(space_set_east(space, link) == OK){
		space_destroy(space);
		return TRUE;
	}

	link_destroy(link);
	space_destroy(space);
	return FALSE;
}

BOOL test_space30(){  /*space_set_west ERROR passing space*/
	Id idaux = ID;
	Space* space = NULL;
	Link* link = NULL;
	link = link_create(idaux);
	
	if(space_set_west(space, link) == ERROR){
		link_destroy(link);
		return TRUE;
	}

	link_destroy(link);
	return FALSE;
}

BOOL test_space31(){  /*space_set_west ERROR passing link*/
	Id idaux = ID;
	Space* space = NULL;
	Link* link = NULL;
	space = space_create(idaux);
	
	if(space_set_west(space, link) == ERROR){
		space_destroy(space);
		return TRUE;
	}

	space_destroy(space);
	return FALSE;
}

BOOL test_space32(){/*space_set_west OK*/
	Id idaux = ID;
	Space* space = NULL;
	space = space_create(idaux);
	Link* link = NULL;
	link = link_create(idaux);

	if(space_set_west(space, link) == OK){
		space_destroy(space);
		return TRUE;
	}
	
	link_destroy(link);
	space_destroy(space);
	return FALSE;
}

BOOL test_space33(){  /*space_set_up ERROR passing space*/
	Id idaux = ID;
	Space* space = NULL;
	Link* link = NULL;
	link = link_create(idaux);
	
	if(space_set_up(space, link) == ERROR){
		link_destroy(link);
		return TRUE;
	}

	link_destroy(link);
	return FALSE;
}

BOOL test_space34(){  /*space_set_up ERROR passing link*/
	Id idaux = ID;
	Space* space = NULL;
	Link* link = NULL;
	space = space_create(idaux);
	
	if(space_set_up(space, link) == ERROR){
		space_destroy(space);
		return TRUE;
	}

	space_destroy(space);
	return FALSE;
}

BOOL test_space35(){/*space_set_up OK*/
	Id idaux = ID;
	Space* space = NULL;
	space = space_create(idaux);
	Link* link = NULL;
	link = link_create(idaux);

	if(space_set_up(space, link) == OK){
		link_destroy(link);
		space_destroy(space);
		return TRUE;
	}
	
	link_destroy(link);
	space_destroy(space);
	return FALSE;
}

BOOL test_space36(){  /*space_set_down ERROR passing space*/
	Id idaux = ID;
	Space* space = NULL;
	Link* link = NULL;
	link = link_create(idaux);
	
	if(space_set_down(space, link) == ERROR){
		link_destroy(link);
		return TRUE;
	}

	link_destroy(link);
	return FALSE;
}

BOOL test_space37(){  /*space_set_down ERROR passing link*/
	Id idaux = ID;
	Space* space = NULL;
	Link* link = NULL;
	space = space_create(idaux);
	
	if(space_set_down(space, link) == ERROR){
		space_destroy(space);
		return TRUE;
	}

	space_destroy(space);
	return FALSE;
}

BOOL test_space38(){/*space_set_down OK*/
	Id idaux = ID;
	Space* space = NULL;
	space = space_create(idaux);
	Link* link = NULL;
	link = link_create(idaux);

	if(space_set_down(space, link) == OK){
		link_destroy(link);
		space_destroy(space);
		return TRUE;
	}
	
	link_destroy(link);
	space_destroy(space);
	return FALSE;
}

BOOL test_space39(){  /*space_add_object ERROR passing space*/
	Id idaux = ID;
	Space* space = NULL;
	Object* object = NULL;
	object = object_create(idaux);

	if(space_add_object(space, object) == ERROR){
		object_destroy(object);
		return TRUE;
	}

	object_destroy(object);
	return FALSE;
}

BOOL test_space40(){  /*space_add_object ERROR passing object*/
	Id idaux = ID;
	Space* space = NULL;
	Object* object = NULL;
	space = space_create(idaux);

	if(space_add_object(space, object) == ERROR){
		space_destroy(space);
		return TRUE;
	}

	space_destroy(space);
	return FALSE;
}

BOOL test_space41(){  /*space_add_object OK*/
	Id idaux = ID;
	Space* space = NULL;
	Object * object = NULL;
	object = object_create(idaux);
	space = space_create(idaux);

	if(	space_add_object(space, object) == OK){
		object_destroy(object);
		space_destroy(space);
		return TRUE;
	}

	object_destroy(object);
	space_destroy(space);
	return FALSE;
}

BOOL test_space42(){  /*space_delete_object ERROR passing space*/
	Id idaux = ID;
	Space* space = NULL;
	Object* object= NULL;
	object = object_create(idaux);
	
	space_add_object(space, object);
	
	if(space_delete_object(space, object) == ERROR){
		object_destroy(object);
		return TRUE;
	}

	object_destroy(object);
	return FALSE;
}

BOOL test_space43(){  /*space_delete_object ERROR passing object*/
	Id idaux = ID;
	Space* space = NULL;
	Object* object= NULL;
	space = space_create(idaux);
	
	space_add_object(space, object);
	
	if(space_delete_object(space, object) == ERROR){
		space_destroy(space);
		return TRUE;
	}
	
	space_destroy(space);
	return FALSE;
}

BOOL test_space44(){  /*space_delete_object OK*/
	Id idaux = ID;
	Space* space = NULL;
	Object* object = NULL;
	object = object_create(idaux);
	space = space_create(idaux);
	
	space_add_object(space, object);
	
	if(space_delete_object(space, object) == OK){
		object_destroy(object);
		space_destroy(space);
		return TRUE;
	}

	object_destroy(object);
	space_destroy(space);
	return FALSE;
}


BOOL test_space45(){ /*space_get_id ERROR passing space*/
	Space* space = NULL;

	if(space_get_id(space) == NO_ID)
		return TRUE;
	
	return FALSE;
}

BOOL test_space46(){ /*space_get_id OK*/
	Id idaux = ID;
	Space* space = NULL;
	space = space_create(idaux);

	if(space_get_id(space) == idaux){
		space_destroy(space);
		return TRUE;
	}

	space_destroy(space);
	return FALSE;
}

BOOL test_space47(){ /*space_get_name ERROR passing space*/
	Space* space = NULL;

	if(space_get_name(space) == NULL)
		return TRUE;
	
	return FALSE;
}

BOOL test_space48(){ /*space_get_name OK*/
	Id idaux = ID;
	Space* space = NULL;
	space = space_create(idaux);

	if(strcmp(space_get_name(space), "") == 0){
		space_destroy(space);
		return TRUE;
	}    
	
	space_destroy(space);
	return FALSE;
}

BOOL test_space49(){/*space_get_iluminated ERROR passing space*/
	Space* space = NULL;
	BOOL iluminated = TRUE;
	
	space_set_iluminated(space, iluminated);
	
	if(space_get_iluminated(space) == FALSE)
		return TRUE;
	
	return FALSE;
}

BOOL test_space50(){/*space_get_iluminated OK*/
	Space* space = NULL;
	Id idaux = ID;
	space = space_create(idaux);
	BOOL iluminated = TRUE;
	
	space_set_iluminated(space,iluminated);
	
	if(space_get_iluminated(space) == iluminated){
		space_destroy(space);
		return TRUE;
	}
	
	space_destroy(space);
	return TRUE;
}

BOOL test_space51(){ /*space_get_gdesc ERROR passing space*/
	int row = ROW;
	char* gdesc1 = GDESC1;
	char* gdesc2 = GDESC2;
	char* gdesc3 = GDESC3;
	Space* space = NULL;
	space_set_gdesc(space, gdesc1, gdesc2, gdesc3);

	if(space_get_gdesc(space, row) == NULL)
		return TRUE;
	
	return FALSE;
}

BOOL test_space52(){ /*space_get_gdesc ERROR passing row min*/
	int row = ROW-2;
	Id idaux = ID;
	char* gdesc1 = GDESC1;
	char* gdesc2 = GDESC2;
	char* gdesc3 = GDESC3;
	Space* space = NULL;
	space = space_create(idaux);
	space_set_gdesc(space, gdesc1, gdesc2, gdesc3);

	if(space_get_gdesc(space, row) == NULL)
		space_destroy(space);
		return TRUE;
	
	space_destroy(space);
	return FALSE;
}

BOOL test_space53(){ /*space_get_gdesc ERROR passing row max*/
	int row = ROW+2;
	Id idaux = ID;
	char* gdesc1 = GDESC1;
	char* gdesc2 = GDESC2;
	char* gdesc3 = GDESC3;
	Space* space = NULL;
	space = space_create(idaux);
	space_set_gdesc(space, gdesc1, gdesc2, gdesc3);

	if(space_get_gdesc(space, row) == NULL)
		space_destroy(space);
		return TRUE;
	
	space_destroy(space);
	return FALSE;
}

BOOL test_space54(){ /*space_get_gdesc OK*/
	Id idaux = ID;
	int row = ROW;
	char* gdesc1 = GDESC1;
	char* gdesc2 = GDESC2;
	char* gdesc3 = GDESC3;
	Space* space = NULL;
	space = space_create(idaux);
	space_set_gdesc(space, gdesc1, gdesc2, gdesc3);
	
	if(space_get_gdesc(space, row) == NULL){
		space_destroy(space);
		return FALSE;
	}    

	space_destroy(space);
	return TRUE;
}

BOOL test_space55(){/*space_get_extraDesc ERROR passing space*/
	Space* space = NULL;
	char* extraDesc = DESCRIPTION;
	
	space_set_extraDesc(space, extraDesc);
	
	if(space_get_extraDesc(space) == NULL)
		return TRUE;
	
	return FALSE;
}


BOOL test_space56(){/*space_get_extraDesc OK*/
	Space* space = NULL;
	Id idaux = ID;
	char* extraDesc = DESCRIPTION;
	space = space_create(idaux);
	
	space_set_extraDesc(space, extraDesc);
	
	if(space_get_extraDesc(space) == extraDesc){
		space_destroy(space);
		return TRUE;
	}
	
	space_destroy(space);
	return FALSE;
}

BOOL test_space57(){ /*space_get_north ERROR passing space*/
	Space* space = NULL;
	Link* link = NULL;
	Id idaux = ID;
	link = link_create(idaux);

	space_set_north(space, link);

	if(space_get_north(space) == NULL){
		link_destroy(link);
		return TRUE;
	}

	link_destroy(link);
	return FALSE;
}

BOOL test_space58(){ /*space_get_north OK*/
	Id idaux = ID;
	Space* space = NULL;
	space = space_create(idaux);
	Link* link = NULL;
	link = link_create(idaux);

	space_set_north(space, link);

	if(space_get_north(space) == link){
		space_destroy(space);
		return TRUE;
	}    

	space_destroy(space);
	return FALSE;
}

BOOL test_space59(){ /*space_get_south ERROR passing space*/
	Space* space = NULL;
	Link* link = NULL;
	Id idaux = ID;
	link = link_create(idaux);

	space_set_south(space, link);
	
	if(space_get_south(space) == NULL){
		link_destroy(link);
		return TRUE;
	}
	
	return FALSE;
}

BOOL test_space60(){ /*space_get_south OK*/
	Id idaux = ID;
	Space* space = NULL;
	space = space_create(idaux);
	Link* link = NULL;
	link = link_create(idaux);

	space_set_south(space, link);

	if(space_get_south(space) == link){
		space_destroy(space);
		return TRUE;
	}    
	
	space_destroy(space);
	return FALSE;
}

BOOL test_space61(){ /*space_get_east ERROR passing space*/
	Space* space = NULL;
	Link* link = NULL;
	Id idaux = ID;
	link = link_create(idaux);

	space_set_east(space, link);
	
	if(space_get_east(space) == NULL){
		link_destroy(link);
		return TRUE;
	}
	
	link_destroy(link);
	return FALSE;
}

BOOL test_space62(){ /*space_get_east OK*/
	Id idaux = ID;
	Space* space = NULL;
	space = space_create(idaux);
	Link* link = NULL;
	link = link_create(idaux);

	space_set_east(space, link);

	if(space_get_east(space) == link){
		space_destroy(space);
		return TRUE;
	}    
	
	space_destroy(space);
	return FALSE;
}

BOOL test_space63(){ /*space_get_west ERROR passing space*/
	Space* space = NULL;
	Link* link = NULL;
	Id idaux = ID;
	link = link_create(idaux);

	space_set_west(space, link);

	if(space_get_west(space) == NULL){
		link_destroy(link);
		return TRUE;
	}
	
	link_destroy(link);
	return FALSE;
}

BOOL test_space64(){ /*space_get_west OK*/
	Id idaux = ID;
	Space* space = NULL;
	space = space_create(idaux);
	Link* link = NULL;
	link = link_create(idaux);

	space_set_west(space, link);

	if(space_get_west(space) == link){
		space_destroy(space);
		return TRUE;
	}    
	
	space_destroy(space);
	return FALSE;
}

BOOL test_space65(){ /*space_get_up ERROR passing space*/
	Space* space = NULL;
	Link* link = NULL;
	Id idaux = ID;
	link = link_create(idaux);

	space_set_up(space, link);

	if(space_get_up(space) == NULL){
		link_destroy(link);
		return TRUE;
	}
	
	link_destroy(link);
	return FALSE;
}

BOOL test_space66(){ /*space_get_up OK*/
	Id idaux = ID;
	Space* space = NULL;
	space = space_create(idaux);
	Link* link = NULL;
	link = link_create(idaux);

	space_set_up(space, link);

	if(space_get_up(space) == link){
		link_destroy(link);
		space_destroy(space);
		return TRUE;
	}    
	
	link_destroy(link);
	space_destroy(space);
	return FALSE;
}

BOOL test_space67(){ /*space_get_down ERROR passing space*/
	Space* space = NULL;
	Link* link = NULL;
	Id idaux = ID;
	link = link_create(idaux);

	space_set_down(space, link);

	if(space_get_down(space) == NULL){
		link_destroy(link);
		return TRUE;
	}
	
	link_destroy(link);
	return FALSE;
}

BOOL test_space68(){ /*space_get_down OK*/
	Id idaux = ID;
	Space* space = NULL;
	space = space_create(idaux);
	Link* link = NULL;
	link = link_create(idaux);

	space_set_down(space, link);

	if(space_get_down(space) == link){
		link_destroy(link);
		space_destroy(space);
		return TRUE;
	}    
	
	link_destroy(link);
	space_destroy(space);
	return FALSE;
}

BOOL test_space69(){ /* space_get_objects ERROR passing space*/
	Space * space = NULL;
	Set* set = NULL;
	set = set_create();

	if(space_get_objects(space) == NULL){
		set_destroy(set);
		return TRUE;
	}

	set_destroy(set);
	return FALSE;
}

BOOL test_space70(){ /* space_get_objects OK*/
	Id idaux = ID;
	Space* space = NULL;
	space = space_create(idaux);
	Set* set = NULL;
	set = set_create();

	if(space_get_objects(space) == set){
		space_destroy(space);
		set_destroy(set);
		return FALSE;
	}    

	space_destroy(space);
	set_destroy(set);
	return TRUE;
}

BOOL test_space71(){ /*space_get_description ERROR passing space*/
	Space *space = NULL;
	
	if(space_get_description(space) == NULL)
		return TRUE;
	
	return FALSE;
}

BOOL test_space72(){ /*space_get_description OK*/
	Id idaux = ID;
	Space* space = NULL;
	space = space_create(idaux);

	if(space_get_description(space) == NULL){
		space_destroy(space);
		return FALSE;
	}    
	
	space_destroy(space);
	return TRUE;
}

BOOL test_space73(){  /*space_is_object ERROR passing space*/
	Id idaux = ID;
	Space* space = NULL;
	Object* object = NULL;
	object = object_create(idaux);

	if(space_is_object(space, object) == FALSE){
		object_destroy(object);
		return TRUE;
	}

	object_destroy(object);
	return FALSE;
}

BOOL test_space74(){  /*space_is_object ERROR passing object*/
	Id idaux = ID;
	Space* space = NULL;
	space = space_create(idaux);
	Object* object = NULL;

	if(space_is_object(space, object) == FALSE){
		space_destroy(space);
		return TRUE;
	}

	space_destroy(space);
	return FALSE;
}


BOOL test_space75(){  /*space_is_object  OK*/
	Id idaux = ID;
	Space* space = NULL;
	space = space_create(idaux);
	Object * object = NULL;
	object = object_create(idaux);

	space_add_object(space, object);
	
	if(space_is_object(space, object) == TRUE){
		object_destroy(object);
		space_destroy(space);
		return TRUE;
	}
	
	object_destroy(object);
	space_destroy(space);
	return FALSE;
}

BOOL test_space76(){/*space_is_north_linked ERROR passing space*/
	Space* space = NULL;
	Link* link = NULL;
	Id idaux = ID;
	link = link_create(idaux);
	
	space_set_north(space,link);
	
	if(space_is_north_linked(space) == FALSE){
		link_destroy(link);
		return TRUE;
	}

	link_destroy(link);
	return FALSE;
}

BOOL test_space77(){/*space_is_north_linked ERROR passing link*/
	Space* space = NULL;
	Link* link = NULL;
	Id idaux = ID;
	space = space_create(idaux);
	
	space_set_north(space,link);
	
	if(space_is_north_linked(space) == FALSE){
		space_destroy(space);
		return TRUE;
	}
	
	space_destroy(space);
	return FALSE;
}

BOOL test_space78(){/*space_is_north_linked OK*/
	Space* space = NULL;
	Link* link = NULL;
	Id idaux = ID;
	Id idaux2 = ID2;
	space = space_create(idaux);
	link = link_create(idaux2);
	
	space_set_north(space,link);
	
	if(space_is_north_linked(space) == TRUE){
		space_destroy(space);
		return TRUE;
	}
	
	space_destroy(space);
	return FALSE;
}

BOOL test_space79(){/*space_is_south_linked ERROR passing space*/
	Space* space = NULL;
	Link* link = NULL;
	Id idaux = ID;
	link = link_create(idaux);
	
	space_set_south(space,link);
	
	if(space_is_south_linked(space) == FALSE){
		link_destroy(link);
		return TRUE;
	}

	link_destroy(link);
	return FALSE;
}

BOOL test_space80(){/*space_is_south_linked ERROR passing link*/
	Space* space = NULL;
	Link* link = NULL;
	Id idaux = ID;
	space = space_create(idaux);
	
	space_set_south(space,link);
	
	if(space_is_south_linked(space) == FALSE){
		space_destroy(space);
		return TRUE;
	}
	
	space_destroy(space);
	return FALSE;
}

BOOL test_space81(){/*space_is_south_linked OK*/
	Space* space = NULL;
	Link* link = NULL;
	Id idaux = ID;
	Id idaux2 = ID2;
	space = space_create(idaux);
	link = link_create(idaux2);
	
	space_set_south(space,link);
	
	if(space_is_south_linked(space) == TRUE){
		space_destroy(space);
		return TRUE;
	}
	
	space_destroy(space);
	return FALSE;
}

BOOL test_space82(){/*space_is_east_linked ERROR passing space*/
	Space* space = NULL;
	Link* link = NULL;
	Id idaux = ID;
	link = link_create(idaux);
	
	space_set_east(space,link);
	
	if(space_is_east_linked(space) == FALSE){
		link_destroy(link);
		return TRUE;
	}

	link_destroy(link);
	return FALSE;
}

BOOL test_space83(){/*space_is_east_linked ERROR passing link*/
	Space* space = NULL;
	Link* link = NULL;
	Id idaux = ID;
	space = space_create(idaux);
	
	space_set_east(space,link);
	
	if(space_is_east_linked(space) == FALSE){
		space_destroy(space);
		return TRUE;
	}
	
	space_destroy(space);
	return FALSE;
}

BOOL test_space84(){/*space_is_east_linked OK*/
	Space* space = NULL;
	Link* link = NULL;
	Id idaux = ID;
	Id idaux2 = ID2;
	space = space_create(idaux);
	link = link_create(idaux2);
	
	space_set_east(space,link);
	
	if(space_is_east_linked(space) == TRUE){
		space_destroy(space);
		return TRUE;
	}
	
	space_destroy(space);
	return FALSE;
}

BOOL test_space85(){/*space_is_west_linked ERROR passing space*/
	Space* space = NULL;
	Link* link = NULL;
	Id idaux = ID;
	link = link_create(idaux);
	
	space_set_west(space,link);
	
	if(space_is_west_linked(space) == FALSE){
		link_destroy(link);
		return TRUE;
	}

	link_destroy(link);
	return FALSE;
}

BOOL test_space86(){/*space_is_west_linked ERROR passing link*/
	Space* space = NULL;
	Link* link = NULL;
	Id idaux = ID;
	space = space_create(idaux);
	
	space_set_west(space,link);
	
	if(space_is_west_linked(space) == FALSE){
		space_destroy(space);
		return TRUE;
	}
	
	space_destroy(space);
	return FALSE;
}

BOOL test_space87(){/*space_is_west_linked OK*/
	Space* space = NULL;
	Link* link = NULL;
	Id idaux = ID;
	Id idaux2 = ID2;
	space = space_create(idaux);
	link = link_create(idaux2);
	
	space_set_west(space,link);
	
	if(space_is_west_linked(space) == TRUE){
		space_destroy(space);
		return TRUE;
	}
	
	space_destroy(space);
	return FALSE;
}

BOOL test_space88(){/*space_is_up_linked ERROR passing space*/
	Space* space = NULL;
	Link* link = NULL;
	Id idaux = ID;
	link = link_create(idaux);
	
	space_set_up(space,link);
	
	if(space_is_up_linked(space) == FALSE){
		link_destroy(link);
		return TRUE;
	}

	link_destroy(link);
	return FALSE;
}

BOOL test_space89(){/*space_is_up_linked ERROR passing link*/
	Space* space = NULL;
	Link* link = NULL;
	Id idaux = ID;
	space = space_create(idaux);
	
	space_set_up(space,link);
	
	if(space_is_up_linked(space) == FALSE){
		space_destroy(space);
		return TRUE;
	}
	
	space_destroy(space);
	return FALSE;
}

BOOL test_space90(){/*space_is_up_linked OK*/
	Space* space = NULL;
	Link* link = NULL;
	Id idaux = ID;
	Id idaux2 = ID2;
	space = space_create(idaux);
	link = link_create(idaux2);
	
	space_set_up(space,link);
	
	if(space_is_up_linked(space) == TRUE){
		link_destroy(link);
		space_destroy(space);
		return TRUE;
	}
	
	link_destroy(link);
	space_destroy(space);
	return FALSE;
}

BOOL test_space91(){/*space_is_down_linked ERROR passing space*/
	Space* space = NULL;
	Link* link = NULL;
	Id idaux = ID;
	link = link_create(idaux);
	
	space_set_down(space,link);
	
	if(space_is_down_linked(space) == FALSE){
		link_destroy(link);
		return TRUE;
	}

	link_destroy(link);
	return FALSE;
}

BOOL test_space92(){/*space_is_down_linked ERROR passing link*/
	Space* space = NULL;
	Link* link = NULL;
	Id idaux = ID;
	space = space_create(idaux);
	
	space_set_down(space,link);
	
	if(space_is_down_linked(space) == FALSE){
		space_destroy(space);
		return TRUE;
	}
	
	space_destroy(space);
	return FALSE;
}

BOOL test_space93(){/*space_is_down_linked OK*/
	Space* space = NULL;
	Link* link = NULL;
	Id idaux = ID;
	Id idaux2 = ID2;
	space = space_create(idaux);
	link = link_create(idaux2);
	
	space_set_down(space,link);
	
	if(space_is_down_linked(space) == TRUE){
		link_destroy(link);
		space_destroy(space);
		return TRUE;
	}
	
	link_destroy(link);
	space_destroy(space);
	return FALSE;
}

BOOL test_space94(){ /*space_is_open_north ERROR passing space*/
	Space* space = NULL;
	Link* link = NULL;
	Id idaux = ID;
	BOOL oorc = TRUE;
	link = link_create(idaux);
	
	link_set_oorc(link, oorc);
	space_set_north(space, link);
	
	if(space_is_open_north(space) == FALSE){
		link_destroy(link);
		return TRUE;
	}
	
	link_destroy(link);
	return FALSE;
}

BOOL test_space95(){ /*space_is_open_north OK*/
	Space* space = NULL;
	Link* link = NULL;
	Id idaux = ID;
	Id idaux2 = ID2;
	BOOL oorc = TRUE;
	space = space_create(idaux);
	link = link_create(idaux2);
	
	link_set_oorc(link, oorc);
	space_set_north(space, link);
	
	if(space_is_open_north(space) == TRUE){
		space_destroy(space);
		return TRUE;
	}
	
	space_destroy(space);
	return FALSE;
}

BOOL test_space96(){ /*space_is_open_south ERROR passing space*/
	Space* space = NULL;
	Link* link = NULL;
	Id idaux = ID;
	BOOL oorc = TRUE;
	link = link_create(idaux);
	
	link_set_oorc(link, oorc);
	space_set_south(space, link);
	
	if(space_is_open_south(space) == FALSE){
		link_destroy(link);
		return TRUE;
	}
	
	link_destroy(link);
	return FALSE;
}

BOOL test_space97(){ /*space_is_open_south OK*/
	Space* space = NULL;
	Link* link = NULL;
	Id idaux = ID;
	Id idaux2 = ID2;
	BOOL oorc = TRUE;
	space = space_create(idaux);
	link = link_create(idaux2);
	
	link_set_oorc(link, oorc);
	space_set_south(space, link);
	
	if(space_is_open_south(space) == TRUE){
		space_destroy(space);
		return TRUE;
	}
	
	space_destroy(space);
	return FALSE;
}

BOOL test_space98(){ /*space_is_open_east ERROR passing space*/
	Space* space = NULL;
	Link* link = NULL;
	Id idaux = ID;
	BOOL oorc = TRUE;
	link = link_create(idaux);
	
	link_set_oorc(link, oorc);
	space_set_east(space, link);
	
	if(space_is_open_east(space) == FALSE){
		link_destroy(link);
		return TRUE;
	}
	
	link_destroy(link);
	return FALSE;
}

BOOL test_space99(){ /*space_is_open_east OK*/
	Space* space = NULL;
	Link* link = NULL;
	Id idaux = ID;
	Id idaux2 = ID2;
	BOOL oorc = TRUE;
	space = space_create(idaux);
	link = link_create(idaux2);
	
	link_set_oorc(link, oorc);
	space_set_east(space, link);
	
	if(space_is_open_east(space) == TRUE){
		space_destroy(space);
		return TRUE;
	}
	
	space_destroy(space);
	return FALSE;
}

BOOL test_space100(){ /*space_is_open_west ERROR passing space*/
	Space* space = NULL;
	Link* link = NULL;
	Id idaux = ID;
	BOOL oorc = TRUE;
	link = link_create(idaux);
	
	link_set_oorc(link, oorc);
	space_set_west(space, link);
	
	if(space_is_open_west(space) == FALSE){
		link_destroy(link);
		return TRUE;
	}
	
	link_destroy(link);
	return FALSE;
}

BOOL test_space101(){ /*space_is_open_west OK*/
	Space* space = NULL;
	Link* link = NULL;
	Id idaux = ID;
	Id idaux2 = ID2;
	BOOL oorc = TRUE;
	space = space_create(idaux);
	link = link_create(idaux2);
	
	link_set_oorc(link, oorc);
	space_set_west(space, link);
	
	if(space_is_open_west(space) == TRUE){
		space_destroy(space);
		return TRUE;
	}
	
	space_destroy(space);
	return FALSE;
}

BOOL test_space102(){ /*space_is_open_up ERROR passing space*/
	Space* space = NULL;
	Link* link = NULL;
	Id idaux = ID;
	BOOL oorc = TRUE;
	link = link_create(idaux);
	
	link_set_oorc(link, oorc);
	space_set_up(space, link);
	
	if(space_is_open_up(space) == FALSE){
		link_destroy(link);
		return TRUE;
	}
	
	link_destroy(link);
	return FALSE;
}

BOOL test_space103(){ /*space_is_open_up OK*/
	Space* space = NULL;
	Link* link = NULL;
	Id idaux = ID;
	Id idaux2 = ID2;
	BOOL oorc = TRUE;
	space = space_create(idaux);
	link = link_create(idaux2);
	
	link_set_oorc(link, oorc);
	space_set_up(space, link);
	
	if(space_is_open_up(space) == TRUE){
		space_destroy(space);
		link_destroy(link);
		return TRUE;
	}
	
	space_destroy(space);
	link_destroy(link);
	return FALSE;
}

BOOL test_space104(){ /*space_is_open_down ERROR passing space*/
	Space* space = NULL;
	Link* link = NULL;
	Id idaux = ID;
	BOOL oorc = TRUE;
	link = link_create(idaux);
	
	link_set_oorc(link, oorc);
	space_set_down(space, link);
	
	if(space_is_open_down(space) == FALSE){
		link_destroy(link);
		return TRUE;
	}
	
	link_destroy(link);
	return FALSE;
}

BOOL test_space105(){ /*space_is_open_down OK*/
	Space* space = NULL;
	Link* link = NULL;
	Id idaux = ID;
	Id idaux2 = ID2;
	BOOL oorc = TRUE;
	space = space_create(idaux);
	link = link_create(idaux2);
	
	link_set_oorc(link, oorc);
	space_set_down(space, link);
	
	if(space_is_open_down(space) == TRUE){
		space_destroy(space);
		link_destroy(link);
		return TRUE;
	}
	
	space_destroy(space);
	link_destroy(link);
	return FALSE;
}

BOOL test_space106(){ /*space_print_description ERROR passing space*/ 
	Space* space = NULL;
	char* description = DESCRIPTION;

	space_set_description(space, description);
	if(space_print_description(space) == OK)
		return FALSE;

	return TRUE;
}

BOOL test_space107(){ /*space_print_description OK*/
	Id idaux = ID;
	Space* space = NULL;
	space = space_create(idaux);
	char* description = DESCRIPTION;

	space_set_description(space, description);

	if(space_print_description(space) == OK){
		space_destroy(space);
		return TRUE;
	}

	space_destroy(space);
	return FALSE;
}

BOOL test_space108(){/*space_print_extraDesc ERROR passing space*/
	Space* space = NULL;
	char* extraDesc = DESCRIPTION;
	
	space_set_extraDesc(space,extraDesc);
	if(space_print_extraDesc(space) == ERROR)
		return TRUE;
	
	return FALSE;
}

BOOL test_space109(){/*space_print_extraDesc OK*/
	Space* space = NULL;
	Id idaux = ID;
	char* extraDesc = DESCRIPTION;
	space = space_create(idaux);
	
	space_set_extraDesc(space,extraDesc);
	
	if(space_print_extraDesc(space) == OK){
		space_destroy(space);
		return TRUE;
	}
	
	space_destroy(space);
	return FALSE;
}

BOOL test_space110(){ /*space_print ERROR passing space*/ 
	Space* space = NULL;
	
	if(space_print(space) == OK)
		return FALSE;

	return TRUE;
}

BOOL test_space111(){ /*space_print OK*/
	Id idaux = ID;
	Space* space = NULL;
	space = space_create(idaux);

	if(space_print(space) == OK){
		space_destroy(space);
		return TRUE;
	}

	space_destroy(space);
	return FALSE;
}

int main(int argc, char* argv[]){
	int test = 0;
	int all = 1;

	if(argc < 2)
		printf("Passing all tests to the Space module:\n");
	
	else{
		test = atoi(argv[1]);
		all = 0;
		if(test < 1 || test > MAX_TESTS){
			printf("Error, unrecognized test\n");
			exit(EXIT_SUCCESS);
		}
		printf("Passing test number %d to the Space module: \n", test);
	}
	if(all || test == 1) TEST_RESULT(test_space1());
	if(all || test == 2) TEST_RESULT(test_space2());
	if(all || test == 3) TEST_RESULT(test_space3());
	if(all || test == 4) TEST_RESULT(test_space4());
	if(all || test == 5) TEST_RESULT(test_space5());
	if(all || test == 6) TEST_RESULT(test_space6());
	if(all || test == 7) TEST_RESULT(test_space7());
	if(all || test == 8) TEST_RESULT(test_space8());
	if(all || test == 9) TEST_RESULT(test_space9());
	if(all || test == 10) TEST_RESULT(test_space10());
	if(all || test == 11) TEST_RESULT(test_space11());
	if(all || test == 12) TEST_RESULT(test_space12());
	if(all || test == 13) TEST_RESULT(test_space13());
	if(all || test == 14) TEST_RESULT(test_space14());
	if(all || test == 15) TEST_RESULT(test_space15());
	if(all || test == 16) TEST_RESULT(test_space16());
	if(all || test == 17) TEST_RESULT(test_space17());
	if(all || test == 18) TEST_RESULT(test_space18());
	if(all || test == 19) TEST_RESULT(test_space19());
	if(all || test == 20) TEST_RESULT(test_space20());
	if(all || test == 21) TEST_RESULT(test_space21());
	if(all || test == 22) TEST_RESULT(test_space22());
	if(all || test == 23) TEST_RESULT(test_space23());
	if(all || test == 24) TEST_RESULT(test_space24());
	if(all || test == 25) TEST_RESULT(test_space25());
	if(all || test == 26) TEST_RESULT(test_space26());
	if(all || test == 27) TEST_RESULT(test_space27());
	if(all || test == 28) TEST_RESULT(test_space28());
	if(all || test == 29) TEST_RESULT(test_space29());
	if(all || test == 30) TEST_RESULT(test_space30());
	if(all || test == 31) TEST_RESULT(test_space31());
	if(all || test == 32) TEST_RESULT(test_space32());
	if(all || test == 33) TEST_RESULT(test_space33());
	if(all || test == 34) TEST_RESULT(test_space34());
	if(all || test == 35) TEST_RESULT(test_space35());
	if(all || test == 36) TEST_RESULT(test_space36());
	if(all || test == 37) TEST_RESULT(test_space37());
	if(all || test == 38) TEST_RESULT(test_space38());
	if(all || test == 39) TEST_RESULT(test_space39());
	if(all || test == 40) TEST_RESULT(test_space40());
	if(all || test == 41) TEST_RESULT(test_space41());
	if(all || test == 42) TEST_RESULT(test_space42());
	if(all || test == 43) TEST_RESULT(test_space43());
	if(all || test == 44) TEST_RESULT(test_space44());
	if(all || test == 45) TEST_RESULT(test_space45());
	if(all || test == 46) TEST_RESULT(test_space46());
	if(all || test == 47) TEST_RESULT(test_space47());
	if(all || test == 48) TEST_RESULT(test_space48());
	if(all || test == 49) TEST_RESULT(test_space49());
	if(all || test == 50) TEST_RESULT(test_space50());
	if(all || test == 51) TEST_RESULT(test_space51());
	if(all || test == 52) TEST_RESULT(test_space52());
	if(all || test == 53) TEST_RESULT(test_space53());
	if(all || test == 54) TEST_RESULT(test_space54());
	if(all || test == 55) TEST_RESULT(test_space55());
	if(all || test == 56) TEST_RESULT(test_space56());
	if(all || test == 57) TEST_RESULT(test_space57());
	if(all || test == 58) TEST_RESULT(test_space58());
	if(all || test == 59) TEST_RESULT(test_space59());
	if(all || test == 60) TEST_RESULT(test_space60());
	if(all || test == 61) TEST_RESULT(test_space61());
	if(all || test == 62) TEST_RESULT(test_space62());
	if(all || test == 63) TEST_RESULT(test_space63());
	if(all || test == 64) TEST_RESULT(test_space64());
	if(all || test == 65) TEST_RESULT(test_space65());
	if(all || test == 66) TEST_RESULT(test_space66());
	if(all || test == 67) TEST_RESULT(test_space67());
	if(all || test == 68) TEST_RESULT(test_space68());
	if(all || test == 69) TEST_RESULT(test_space69());
	if(all || test == 70) TEST_RESULT(test_space70());
	if(all || test == 71) TEST_RESULT(test_space71());
	if(all || test == 72) TEST_RESULT(test_space72());
	if(all || test == 73) TEST_RESULT(test_space73());
	if(all || test == 74) TEST_RESULT(test_space74());
	if(all || test == 75) TEST_RESULT(test_space75());
	if(all || test == 76) TEST_RESULT(test_space76());
	if(all || test == 77) TEST_RESULT(test_space77());
	if(all || test == 78) TEST_RESULT(test_space78());
	if(all || test == 79) TEST_RESULT(test_space79());
	if(all || test == 80) TEST_RESULT(test_space80());
	if(all || test == 81) TEST_RESULT(test_space81());
	if(all || test == 82) TEST_RESULT(test_space82());
	if(all || test == 83) TEST_RESULT(test_space83());
	if(all || test == 84) TEST_RESULT(test_space84());
	if(all || test == 85) TEST_RESULT(test_space85());
	if(all || test == 86) TEST_RESULT(test_space86());
	if(all || test == 87) TEST_RESULT(test_space87());
	if(all || test == 88) TEST_RESULT(test_space88());
	if(all || test == 89) TEST_RESULT(test_space89());
	if(all || test == 90) TEST_RESULT(test_space90());
	if(all || test == 91) TEST_RESULT(test_space91());
	if(all || test == 92) TEST_RESULT(test_space92());
	if(all || test == 93) TEST_RESULT(test_space93());
	if(all || test == 94) TEST_RESULT(test_space94());
	if(all || test == 95) TEST_RESULT(test_space95());
	if(all || test == 96) TEST_RESULT(test_space96());
	if(all || test == 97) TEST_RESULT(test_space97());
	if(all || test == 98) TEST_RESULT(test_space98());
	if(all || test == 99) TEST_RESULT(test_space99());
	if(all || test == 100) TEST_RESULT(test_space100());
	if(all || test == 101) TEST_RESULT(test_space101());
	if(all || test == 102) TEST_RESULT(test_space102());
	if(all || test == 103) TEST_RESULT(test_space103());
	if(all || test == 104) TEST_RESULT(test_space104());
	if(all || test == 105) TEST_RESULT(test_space105());
	if(all || test == 106) TEST_RESULT(test_space106());
	if(all || test == 107) TEST_RESULT(test_space107());
	if(all || test == 108) TEST_RESULT(test_space108());
	if(all || test == 109) TEST_RESULT(test_space109());
	if(all || test == 110) TEST_RESULT(test_space110());
	if(all || test == 111) TEST_RESULT(test_space111());
	__test_passed++;

	PRINT_PERCENTAGE;

	return 0;
}