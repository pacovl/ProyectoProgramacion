/* ===================================================================
File: link_test.c
Version: 1.0
Date: 24-11-2016
Author: María Barroso

Description:
    It implements the link_test

Revision history:
Nov. 6, 2016 Version 1.0 (initial release)
=================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "link.h"
#include "test.h"

#define ID 1
#define NAME "name"
#define MAX_TESTS 31

BOOL test_link1(){ /*link_create ERROR passing NO_ID*/
	Link* link = NULL;
	link = link_create(NO_ID);

	if(!link)
		return TRUE;

	link_destroy(link);
	return FALSE;
}

BOOL test_link2(){ /*link_create OKEY*/
	Id id = ID;
	Link* link = NULL;
	link = link_create(id);

	if(!link)
		return FALSE;

	link_destroy(link);
	return TRUE;
}

BOOL test_link3(){/*link_destroy ERROR passing link*/
	Link* link = NULL;

	if(link_destroy(link) == ERROR)
		return TRUE;

	return FALSE;
}

BOOL test_link4(){/*link_destroy OKEY*/
	Id id = ID;
	Link* link = NULL;
	link = link_create(id);

	if(link_destroy(link) == ERROR)
		return FALSE;

	return TRUE;
}

BOOL test_link5(){ /*link_get_id ERROR passing link*/
	Link *link = NULL;

	if(link_get_id(link) == NO_ID)
		return TRUE;
	
	return FALSE;
}

BOOL test_link6(){/*link_get_id OKEY*/
    Id idaux = ID;
    Link* link = NULL;
    link = link_create(idaux);
    
    if(link_get_id(link) == idaux){
        link_destroy(link);
        return TRUE;
    }
    
    link_destroy(link);
    return FALSE;
}

BOOL test_link7(){ /*link_get_name ERROR passing link*/
	Link *link = NULL;

	if(link_get_name(link) == NULL)
		return TRUE;
	
	return FALSE;
}

BOOL test_link8(){/*link_get_name OKEY*/
    Id idaux = ID;
    char *name = NAME;
    Link* link = NULL;
    link = link_create(idaux);

    if(strcmp(link_get_name(link), "") == 0){
		link_destroy(link);
		return TRUE;
	}

	link_destroy(link);
	return FALSE;
}

BOOL test_link9(){ /*link_get_departureSpace ERROR passing link*/
	Link *link = NULL;

	if(link_get_departureSpace(link) == NO_ID)
		return TRUE;

	return FALSE;
}

BOOL test_link10(){/*link_get_departureSpace OKEY*/
    Id idaux = ID;
    Link* link = NULL;
    link = link_create(idaux);
    
    link_set_departureSpace(link, idaux);
    
    if(link_get_departureSpace(link) == idaux){
        link_destroy(link);
        return TRUE;
    }
    
    link_destroy(link);
    return FALSE;
}

BOOL test_link11(){ /*link_get_arrivalSpace ERROR passing link*/
	Link *link = NULL;

	if(link_get_arrivalSpace(link) == NO_ID)
		return TRUE;

	return FALSE;
}

BOOL test_link12(){/*link_get_arrivalSpace OKEY*/
    Id idaux = ID;
    Link* link = NULL;
    link = link_create(idaux);
    
    link_set_arrivalSpace(link, idaux);
    
    if(link_get_arrivalSpace(link) == idaux){
        link_destroy(link);
        return TRUE;
    }
    
    link_destroy(link);
    return FALSE;
}

BOOL test_link13(){/*link_get_oorc ERROR passing link*/
    Id idaux = ID;
    Link *link = NULL;
    
	if(link_get_oorc(link) == FALSE)
		return TRUE;
	
	return FALSE;
}

BOOL test_link14(){/*link_get_oorc OKEY*/
    Id idaux = ID;
    BOOL oorcaux = TRUE;
    Link* link = NULL;
    link = link_create(idaux);

    link_set_oorc(link, oorcaux);
    
    if(link_get_oorc(link) == oorcaux){
        link_destroy(link);
        return TRUE;
    }
    
    link_destroy(link);
    return FALSE;    
}

BOOL test_link15(){  /*link_set_name ERROR passing link*/
	Link* link = NULL;
	char* name = NAME;

	if(link_set_name(link, name) == ERROR)
		return TRUE;

	return FALSE;
}

BOOL test_link16(){  /*link_set_name ERROR passing char*/
	Id idaux = ID;
	Link* link = NULL;
	char* name = NULL;
	link = link_create(idaux);

	if(link_set_name(link, name) == ERROR){
		link_destroy(link);
		return TRUE;
	}

	link_destroy(link);
	return FALSE;
}

BOOL test_link17(){/*link_set_name OKEY*/
    Id idaux = ID;
    Link* link = NULL;
    char* name = NAME;
    link = link_create(idaux);
    
    if(link_set_name(link, name) == OK){
        link_destroy(link);
        return TRUE;
    }
    
    link_destroy(link);
    return FALSE;
}

BOOL test_link18(){  /*link_set_departureSpace ERROR passing link*/
	Link * link = NULL;
	Id idaux = ID;
	
	if(link_set_departureSpace(link, idaux) == ERROR)
		return TRUE;

	return FALSE;
}

BOOL test_link19(){  /*link_set_departureSpace ERROR passing NO_ID*/
	Link * link = NULL;
	Id idaux = ID;
	link = link_create(idaux);

	if(link_set_departureSpace(link, NO_ID) == ERROR){
		link_destroy(link);
		return TRUE;
	}

	link_destroy(link);
	return FALSE;
}

BOOL test_link20(){/*link_set_departureSpace OKEY*/
    Id idaux = ID;
    Link* link = NULL;
    link = link_create(idaux);
    
    if(link_set_departureSpace(link, idaux) == OK){
        link_destroy(link);
        return TRUE;
    }
    
    link_destroy(link);
    return FALSE;
}

BOOL test_link21(){  /*link_set_arrivalSpace ERROR passing link*/
	Link * link = NULL;
	Id idaux = ID;

	if(link_set_arrivalSpace(link, idaux) == ERROR)
		return TRUE;
	
	return FALSE;
}

BOOL test_link22(){  /*link_set_arrivalSpace ERROR passing NO_ID*/
	Link * link = NULL;
	Id idaux = ID;
	link = link_create(idaux);

	if(link_set_arrivalSpace(link, NO_ID) == ERROR){
		link_destroy(link);
		return TRUE;
	}

	link_destroy(link);
	return FALSE;
}

BOOL test_link23(){/*link_set_arrivalSpace OKEY*/
    Id idaux = ID;
    Link* link = NULL;
    link = link_create(idaux);
    
    if(link_set_arrivalSpace(link, idaux) == OK){
        link_destroy(link);
        return TRUE;
    }
    
    link_destroy(link);
    return FALSE;
}

BOOL test_link24(){  /*link_set_oorc ERROR passing link*/
	Link * link = NULL;
    BOOL oorc = TRUE;

	if(link_set_oorc(link, oorc) == ERROR)
		return TRUE;
	
	return FALSE;
}


BOOL test_link25(){/*link_set_oorc OKEY*/
    Id idaux = ID;
    BOOL oorc = TRUE;
    Link* link = NULL;
    link = link_create(idaux);
    
    if(link_set_oorc(link, oorc) == OK){
        link_destroy(link);
        return TRUE;
    }
    
    link_destroy(link);
    return FALSE;
}

BOOL test_link26(){/*link_compare_id ERROR passing link2*/
	Id idaux = ID;
	Link* link1 = NULL;
	Link* link2 = NULL;
	link1 = link_create(idaux);

	if(link_compare_id(link1, link2) == FALSE){
		link_destroy(link1);
		return TRUE;
	}

	link_destroy(link1);
	return FALSE;
}

BOOL test_link27(){/*link_compare_id ERROR passing link1*/
	Id idaux = ID;
	Link* link1 = NULL;
	Link* link2 = NULL;
	link2 = link_create(idaux);

	if(link_compare_id(link1, link2) == FALSE){
		link_destroy(link2);
		return TRUE;
	}

	link_destroy(link2);
	return FALSE;
}

BOOL test_link28(){/*link_compare_id ERROR distinct links*/
    Id idaux = ID;
    Id idaux2 = ID+1;
    Link* link1 = NULL;
    Link* link2 = NULL;
    link1 = link_create(idaux);
    link2 = link_create(idaux2);
    
    
    if(link_compare_id(link1,link2) == FALSE){
        link_destroy(link1);
        link_destroy(link2);
        return TRUE;
    }
    
    link_destroy(link1);
    link_destroy(link2);
    return FALSE;
}

BOOL test_link29(){/*link_compare_id OKEY*/
    Id idaux = ID;
    Link* link1 = NULL;
    Link* link2 = NULL;
    link1 = link_create(idaux);
    link2 = link_create(idaux);
    
    
    if(link_compare_id(link1,link2) == TRUE){
        link_destroy(link1);
        link_destroy(link2);
        return TRUE;
    }
    
    link_destroy(link1);
    link_destroy(link2);
    return FALSE;
}

BOOL test_link30(){ /*link_print ERROR*/ 
	Link *link = NULL;

	if(link_print(link) == OK)
		return FALSE;
	
	return TRUE;
}

BOOL test_link31(){ /*link_print OKEY*/
	Id idaux = ID;
	Link * link= link_create(idaux);

	if(link_print(link) == OK){
		link_destroy(link);
		return TRUE;
	}
	
	link_destroy(link);
	return FALSE;
}

int main(int argc, char* argv[]){
	int test = 0;
	int all = 1;

	if(argc < 2)
		printf("Passing all tests to the Link module:\n");
	
	else{
		test = atoi(argv[1]);
		all = 0;
		if(test < 1 || test > MAX_TESTS){
			printf("Error, unrecognized test\n");
			exit(EXIT_SUCCESS);
		}
		printf("Passing test number %d to the Link module: \n", test);
	}

	if(all || test == 1) TEST_RESULT(test_link1());
	if(all || test == 2) TEST_RESULT(test_link2());
	if(all || test == 3) TEST_RESULT(test_link3());
	if(all || test == 4) TEST_RESULT(test_link4());
	if(all || test == 5) TEST_RESULT(test_link5());
	if(all || test == 6) TEST_RESULT(test_link6());
	if(all || test == 7) TEST_RESULT(test_link7());
	if(all || test == 8) TEST_RESULT(test_link8());
	if(all || test == 9) TEST_RESULT(test_link9());
	if(all || test == 10) TEST_RESULT(test_link10());
	if(all || test == 11) TEST_RESULT(test_link11());
	if(all || test == 12) TEST_RESULT(test_link12());
	if(all || test == 13) TEST_RESULT(test_link13());
	if(all || test == 14) TEST_RESULT(test_link14());
	if(all || test == 15) TEST_RESULT(test_link15());
	if(all || test == 16) TEST_RESULT(test_link16());
	if(all || test == 17) TEST_RESULT(test_link17());
	if(all || test == 18) TEST_RESULT(test_link18());
	if(all || test == 19) TEST_RESULT(test_link19());
	if(all || test == 20) TEST_RESULT(test_link20());
	if(all || test == 21) TEST_RESULT(test_link21());
	if(all || test == 22) TEST_RESULT(test_link22());
	if(all || test == 23) TEST_RESULT(test_link23());
	if(all || test == 24) TEST_RESULT(test_link24());
	if(all || test == 25) TEST_RESULT(test_link25());
	if(all || test == 26) TEST_RESULT(test_link26());
	if(all || test == 27) TEST_RESULT(test_link27());
	if(all || test == 28) TEST_RESULT(test_link28());
	if(all || test == 29) TEST_RESULT(test_link29());
	if(all || test == 30) TEST_RESULT(test_link30());
	if(all || test == 31) TEST_RESULT(test_link31());
	__test_passed++;
	
	PRINT_PERCENTAGE;

	return 0;
}