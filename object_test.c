/* ===================================================================
File: object_test.c
Version: 1.0
Date: 03-12-2016
Author: Maria Barroso

Description:
    It implements the object_test

Revision history:
Nov. 6, 2016 Version 1.0 (initial release)
=================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include "object.h"
#include "test.h"


#define ID 1
#define MAX_TESTS 28
#define NAME "name"
#define DESCRIPTION "description"
#define ADITDESC "aditDesc"

BOOL test_object1(){ /*object_create ERROR passing NO_ID*/
	Object* object = NULL;
	object = object_create(NO_ID);

	if(!object)
		return TRUE;

	object_destroy(object);
	return FALSE;
}

BOOL test_object2(){ /*object_create OKEY*/
	Object* object = NULL;
	Id idaux = ID;
	object = object_create(idaux);

	if(!object){
		object_destroy(object);
		return FALSE;
	}
		
	object_destroy(object);
	return TRUE;
}

BOOL test_object3(){/*object_destroy ERROR passing inventory*/
	Object* object = NULL;

	if(object_destroy(object) == ERROR)
		return TRUE;

	return FALSE;
}

BOOL test_object4(){/*object_destroy OKEY*/
	Object* object = NULL;
	Id idaux = ID;
	object = object_create(idaux);

	if(object_destroy(object) == ERROR)
		return FALSE;
		
	return TRUE;
}


BOOL test_object5(){  /*object_set_name ERROR passing object*/
	Object* object = NULL;
	char* name = NAME;

	if(object_set_name(object, name) == ERROR)
		return TRUE;
	
	return FALSE;
}

BOOL test_object6(){  /*object_set_name ERROR passing name*/
	Object* object = NULL;
	char* name = NULL;
	Id idaux = ID;
	object = object_create(idaux);

	if(object_set_name(object, name) == ERROR){
		object_destroy(object);
		return TRUE;
	}

	object_destroy(object);	
	return FALSE;
}

BOOL test_object7(){  /*object_set_name OKEY*/
	Object* object = NULL;
	Id idaux = ID;
	char* name = NAME;
	object = object_create(idaux);
	
	if(object_set_name(object, name) == OK){
		object_destroy(object);
		return TRUE;
	}
	
	object_destroy(object);
	return FALSE;
}


BOOL test_object8(){ /*object_get_id ERROR passing object*/
	Object* object = NULL;
	
	if(object_get_id(object) == NO_ID)
		return TRUE;
	
	return FALSE;
}

BOOL test_object9(){ /*object_get_id OKEY*/
	Object* object = NULL;
	Id idaux = ID;
	object = object_create(idaux);
	
	if(object_get_id(object) == idaux){
		object_destroy(object);
		return TRUE;
	}    
	
	object_destroy(object);
	return FALSE;
}

BOOL test_object10(){ /*object_get_name ERROR passing object*/
	Object *object = NULL;
	char* name = NAME;
	
	object_set_name(object, name);	

	if(object_get_name(object) == NULL)
		return TRUE;
	
	return FALSE;
}

BOOL test_object11(){/*object_get_name OKEY*/
	Id idaux = ID;
	Object *object = NULL;
	object = object_create(idaux);
	char* name = NAME;
	
	object_set_name(object,name);

	if(strcmp(object_get_name(object),NAME) == 0){
		object_destroy(object);
		return TRUE;
	}
	
	object_destroy(object);
	return FALSE;
}


BOOL test_object12(){  /*object_set_description ERROR passing object*/
	Object* object = NULL;
	char* description = DESCRIPTION;

	if(object_set_description(object, description) == ERROR)
		return TRUE;
	
	return FALSE;
}


BOOL test_object13(){  /*object_set_description ERROR passing char*/
	Object* object = NULL;
	Id idaux = ID;
	char* description = NULL;
	object = object_create(idaux);

	if(object_set_description(object, description) == ERROR){
		object_destroy(object);
		return TRUE;
	}

	object_destroy(object);
	return FALSE;
}

BOOL test_object14(){/*object_set_description OK*/
	Id idaux = ID;
	Object* object = NULL;
	object = object_create(idaux);
	char*  description = DESCRIPTION;

	if(object_set_description(object, description) == OK){
		object_destroy(object);
		return TRUE;
	}

	object_destroy(object);
	return FALSE;
}


BOOL test_object15(){ /*object_get_description ERROR passing object*/
	Object *object = NULL;
	char* description = DESCRIPTION;
	
	object_set_description(object,description);
	
	if(object_get_description(object) == NULL)
		return TRUE;
	
	return FALSE;
}

BOOL test_object16(){ /*object_get_description OK*/
	Id idaux = ID;
	Object* object = NULL;
	object = object_create(idaux);
	char* description = DESCRIPTION;

	object_set_description(object, description);
	
	if(strcmp(object_get_description(object), DESCRIPTION) == 0){
		object_destroy(object);
		return TRUE;
	}    
	
	object_destroy(object);
	return FALSE;
}


BOOL test_object17(){/*object_get_portability ERROR passing object*/
    Object *object = NULL;
    BOOL portability = TRUE;
    
    object_set_portability(object, portability);
    
	if(object_get_portability(object) == FALSE)
		return TRUE;
	
	return FALSE;
}

BOOL test_object18(){/*object_get_portability OKEY*/
    Id idaux = ID;
    BOOL portability = TRUE;
    Object* object = NULL;
    object = object_create(idaux);

    object_set_portability(object, portability);
    
    if(object_get_portability(object) == portability){
        object_destroy(object);
        return TRUE;
    }
    
    object_destroy(object);
    return FALSE;    
}


BOOL test_object24(){  /*object_set_portability ERROR passing object*/
	Object * object = NULL;
    BOOL portability = TRUE;

	if(object_set_portability(object, portability) == ERROR)
		return TRUE;
	
	return FALSE;
}


BOOL test_object25(){/*object_set_portability OKEY*/
    Id idaux = ID;
    BOOL portability = TRUE;
    Object* object = NULL;
    object = object_create(idaux);
    
    if(object_set_portability(object, portability) == OK){
        object_destroy(object);
        return TRUE;
    }
    
    object_destroy(object);
    return FALSE;
}

BOOL test_object26(){/*object_get_movement ERROR passing object*/
    Object *object = NULL;
    BOOL movement = TRUE;
    
    object_set_movement(object, movement);
    
	if(object_get_movement(object) == FALSE)
		return TRUE;
	
	return FALSE;
}

BOOL test_object27(){/*object_get_movement OKEY*/
    Id idaux = ID;
    BOOL movement = TRUE;
    Object* object = NULL;
    object = object_create(idaux);

    oobject_set_movement(object, movement);
    
    if(object_get_movement(object) == movement){
        object_destroy(object);
        return TRUE;
    }
    
    object_destroy(object);
    return FALSE;    
}


BOOL test_object28(){  /*object_set_movement ERROR passing object*/
	Object * object = NULL;
    BOOL movement = TRUE;

	if(object_set_movement(object, movement) == ERROR)
		return TRUE;
	
	return FALSE;
}


BOOL test_object29(){/*object_set_movement OKEY*/
    Id idaux = ID;
    BOOL movement = TRUE;
    Object* object = NULL;
    object = object_create(idaux);
    
    if(object_set_movement(object, movement) == OK){
        object_destroy(object);
        return TRUE;
    }
    
    object_destroy(object);
    return FALSE;
}


BOOL test_object30(){/*object_get_hidden ERROR passing object*/
    Object *object = NULL;
    BOOL hidden = TRUE;
    
    object_set_hidden(object, hidden);
    
	if(object_get_hidden(object) == FALSE)
		return TRUE;
	
	return FALSE;
}

BOOL test_object31(){/*object_get_hidden OKEY*/
    Id idaux = ID;
    BOOL hidden = TRUE;
    Object* object = NULL;
    object = object_create(idaux);

    object_set_hidden(object, hidden);
    
    if(object_get_hidden(object) == hidden){
        object_destroy(object);
        return TRUE;
    }
    
    object_destroy(object);
    return FALSE;    
}


BOOL test_object32(){  /*object_set_hidden ERROR passing object*/
	Object * object = NULL;
    BOOL hidden = TRUE;

	if(object_set_hidden(object, hidden) == ERROR)
		return TRUE;
	
	return FALSE;
}


BOOL test_object33(){/*object_set_hidden OKEY*/
    Id idaux = ID;
    BOOL hidden = TRUE;
    Object* object = NULL;
    object = object_create(idaux);
    
    if(object_set_hidden(object, hidden) == OK){
        object_destroy(object);
        return TRUE;
    }
    
    object_destroy(object);
    return FALSE;
}

BOOL test_object34(){/*object_get_lights ERROR passing object*/
    BOOL lights = TRUE;
    Object *object = NULL;
    
    object_set_lights(object, lights);
    
	if(object_get_lights(object) == FALSE)
		return TRUE;
	
	return FALSE;
}

BOOL test_object35(){/*object_get_lights OKEY*/
    Id idaux = ID;
    BOOL lights = TRUE;
    Object* object = NULL;
    object = object_create(idaux);

    object_set_lights(object, lights);
    
    if(object_get_lights(object) == lights){
        object_destroy(object);
        return TRUE;
    }
    
    object_destroy(object);
    return FALSE;    
}


BOOL test_object36(){  /*object_set_lights ERROR passing object*/
	Object * object = NULL;
    BOOL lights = TRUE;

	if(object_set_lights(object, lights) == ERROR)
		return TRUE;
	
	return FALSE;
}


BOOL test_object37(){/*object_set_lights OKEY*/
    Id idaux = ID;
    BOOL lights = TRUE;
    Object* object = NULL;
    object = object_create(idaux);
    
    if(object_set_lights(object, lights) == OK){
        object_destroy(object);
        return TRUE;
    }
    
    object_destroy(object);
    return FALSE;
}

/*object_get_activate*/

BOOL test_object38(){/*object_get_activate ERROR passing object*/
    BOOL activated = TRUE;
    Object* object = NULL;
    
    object_set_activate(object,activated);
    
	if(object_get_activate(object) == FALSE)
		return TRUE;
	
	return FALSE;
}

BOOL test_object39(){/*object_get_activate OKEY*/
    Id idaux = ID;
    BOOL activated = TRUE;
    Object* object = NULL;
    object = object_create(idaux);

    object_set_activate(object, activated);
    
    if(object_get_activate(object) == activated){
        object_destroy(object);
        return TRUE;
    }
    
    object_destroy(object);
    return FALSE;    
}


BOOL test_object40(){  /*object_set_activate ERROR passing object*/
	Object* object = NULL;
    BOOL activated = TRUE;

	if(object_set_activate(object, activated) == ERROR)
		return TRUE;
	
	return FALSE;
}


BOOL test_object41(){/*object_set_activate OKEY*/
    Id idaux = ID;
    BOOL activated = TRUE;
    Object* object = NULL;
    object = object_create(idaux);
    
    if(object_set_activate(object, activated) == OK){
        object_destroy(object);
        return TRUE;
    }
    
    object_destroy(object);
    return FALSE;
}


BOOL test_object42(){ /*object_print_description ERROR passing object*/ 
	Object* object = NULL;
	char* description = DESCRIPTION;

	object_set_description(object, description);
	
	if(object_print_description(object) == OK)
		return FALSE;

	return TRUE;
}

BOOL test_object43(){ /*object_print_description OK*/
	Id idaux = ID;
	Object* object = NULL;
	object = object_create(idaux);
	char* description = DESCRIPTION;

	object_set_description(object, description);

	if(object_print_description(object) == OK){
		object_destroy(object);
		return TRUE;
	}

	object_destroy(object);
	return FALSE;
}

BOOL test_object44(){ /*object_print_aditDesc ERROR passing object*/ 
	Object* object = NULL;
	char* description = DESCRIPTION;

	object_set_aditDesc(object, description);
	
	if(object_print_aditDesc(object) == OK)
		return FALSE;

	return TRUE;
}

BOOL test_object45(){ /*object_print_aditDesc OK*/
	Id idaux = ID;
	Object* object = NULL;
	object = object_create(idaux);
	char* description = DESCRIPTION;

	object_set_aditDesc(object, description);

	if(object_print_aditDesc(object) == OK){
		object_destroy(object);
		return TRUE;
	}

	object_destroy(object);
	return FALSE;
}

BOOL test_object46(){ /*object_print ERROR passing object*/ 
	Object* object = NULL;
	
	if(object_print(object) == OK)
		return FALSE;

	return TRUE;
}

BOOL test_object47(){ /*object_print OK*/
	Id idaux = ID;
	Object* object = NULL;
	object = object_create(idaux);

	if(object_print(object) == OK){
		object_destroy(object);
		return TRUE;
	}

	object_destroy(object);
	return FALSE;
}

BOOL test_object48(){ /*object_get_opens ERROR passing object*/
	Object* object = NULL;
	Id idaux = ID;
	
	object_add_opens(object, idaux);
	
	if(object_get_opens(object) == NULL)
		return TRUE;

	return FALSE;
}

BOOL test_object49(){ /*object_get_opens OK*/
	Object* object =NULL;
	Id idaux = ID;
	object = object_create(idaux);
	
	object_add_opens(object, idaux);
	
	if(set_get_id_number(object_get_opens(object),0) == idaux){
		object_destroy(object);
		return TRUE;
	}

	object_destroy(object);
	return FALSE;
}


BOOL test_object59(){ /*object_opens_is_full ERROR passing object*/
	Object* object = NULL;
	Id idaux = ID;
	
	object_add_opens(object, idaux);
	
	if(object_opens_is_full(object) == FALSE)
		return TRUE;
	
	return FALSE;
}


BOOL test_object51(){ /*object_opens_is_full OK */
	Object* object =NULL;
	Id idaux =ID;
	
	object = object_create(idaux);
	object_add_opens(object, idaux);
	
	if(object_opens_is_full(object) == FALSE){
		object_destroy(object);
		return TRUE;
	}
	
	object_destroy(object);
	return FALSE;
}


BOOL test_object52(){ /*object_add_opens ERROR passing object*/
	Object* object =NULL;
	Id idaux = ID;
	
	if(object_add_opens(object, idaux) == ERROR){
		return TRUE;
	}
	
	return FALSE;
}

BOOL test_object53(){ /*object_add_opens ERROR passing NO_ID*/
	Object* object = NULL;
	Id idaux = ID;
	object = object_create(idaux);
	
	if(object_add_opens(object, NO_ID) == ERROR){
		object_destroy(object);
		return TRUE;
	}
	
	object_destroy(object);
	return FALSE;
}

BOOL test_object54(){ /*object_add_opens OK*/
	Object* object =NULL;
	Id idaux = ID;
	object = object_create(idaux);
	
	if(object_add_opens(object, idaux) == OK){
		object_destroy(object);
		return TRUE;
	}
	
	object_destroy(object);
	return FALSE;
}


BOOL test_object55(){ /* object_delete_opens ERROR passing object*/
	Object* object =NULL;
	Id idaux = ID;
	
	object_add_opens(object, idaux);
	
	if(object_delete_opens(object, idaux) == ERROR)
		return TRUE;
	
	return FALSE;
}

BOOL test_object56(){ /* object_delete_opens ERROR passing NO_ID*/
	Object* object =NULL;
	Id idaux = ID;
	object = object_create(idaux);
	
	object_add_opens(object, idaux);
	
	if(object_delete_opens(object, NO_ID) == ERROR){
		object_destroy(object);
		return TRUE;
	}
	
	object_destroy(object);
	return FALSE;
}


BOOL test_object57(){ /*object_delete_opens OK*/
	Object* object =NULL;
	Id idaux = ID;
	object = object_create(idaux);
	
	object_add_opens(object, idaux);
	
	if(object_delete_opens(object, idaux) == OK){
		object_destroy(object);
		return TRUE;
	}
	
	object_destroy(object);
	return FALSE;
}

BOOL test_object58(){ /*object_search_id ERROR passing object*/
	Object* object = NULL;
	Id idaux = ID;
	
	object_add_opens(object,idaux);
	
	if(object_search_id(object, idaux) == FALSE)
		return TRUE;
	
	return FALSE;
}

BOOL test_object59(){ /*object_search_id ERROR passing NO_ID*/
	Object* object = NULL;
	Id idaux = ID;
	object = object_create(idaux);
	
	object_add_opens(object, idaux);
	
	if(object_search_id(object, NO_ID) == ERROR)
		return TRUE;
	
	return FALSE;
}


BOOL test_object60(){ /*object_search_id OK*/
	Object* object =NULL;
	Id idaux = ID;
	object = object_create(idaux);
	
	object_add_opens(object, idaux);
	
	if(object_search_id(object, idaux) == OK){
		object_destroy(object);
		return TRUE;
	}
	
	object_destroy(object);
	return FALSE;
}

BOOL test_object61(){ /*object_get_aditDesc ERROR passing object*/
	Object* object =NULL;
	char* aditDesc = ADITDESC;
	
	object_set_aditDesc(object, aditDesc);
	
	if(object_get_aditDesc(object) == NULL)
		return TRUE;
	
	return FALSE;
}

BOOL test_object62(){ /*object_get_aditDesc OK*/
	Object* object =NULL;
	Id idaux = ID;
	object = object_create(idaux);
	char* aditDesc = ADITDESC;
	
	if(strcmp(object_get_aditDesc(object), ADITDESC) == 0){
		object_destroy(object);
		return TRUE;
	}
	
	object_destroy(object);
	return FALSE;
}


BOOL test_object63(){ /*object_set_aditDesc ERROR passing object*/
	Object* object = NULL;
	char* aditDesc = ADITDESC;
	
	if(object_set_aditDesc(object, aditDesc) == ERROR)
		return TRUE;
	
	return FALSE;
}


BOOL test_object64(){ /*object_set_aditDesc ERROR passing aditDesc*/
	Object* object = NULL;
	char* aditDesc = NULL;
	Id idaux = ID;
	object = object_create(idaux);
	
	if(object_set_aditDesc(object, aditDesc) == ERROR){
		object_destroy(object);
		return TRUE;
	}
	
	object_destroy(object);
	return FALSE;
}

/*animooooo :)
Te he dejado un mensaje en cambios para que te entretengas luego*/

BOOL test_object62(){ /*object_set_aditDesc OK*/
	Object* object =NULL;
	char* aditDesc = ADITDESC;
	Id idaux = ID;
	object = object_create(idaux);
	
	if(object_set_aditDesc(object, aditDesc) == OK){
		object_destroy(object);
		return TRUE;
	}
	
	object_destroy(object);
	return FALSE;
}




