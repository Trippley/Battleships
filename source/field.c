#include "main.h"
#include "field.h"

int *field1 = NULL;
int *field2 = NULL;
int *natalie = NULL;	// third global array for Natalie

int counter = 0;

int natalie_init(int size){
	int i;

	if((size < FIELD_MIN) || (size > FIELD_MAX)) return -1;
	if(natalie != NULL) return -2;

	natalie = malloc(sizeof(int)*size*size);

	if(natalie == NULL) return -3;

	counter = size*size;

	for(i=0; i<counter; i++) natalie[i] = 0;

	return 0;
}

int field_init(int size){
	int i;

	if((size < FIELD_MIN) || (size > FIELD_MAX)) return -1;
	if((field1 != NULL) || (field2 != NULL)) return -2;

	field1 = malloc(sizeof(int)*size*size);
	field2 = malloc(sizeof(int)*size*size);

	if((field1 == NULL) || (field2 == NULL)) return -3;

	counter = size*size;

	for(i=0; i<counter; i++) field1[i] = 0;
	for(i=0; i<counter; i++) field2[i] = 0;

	return 0;
}

int field_delete(){
	if((field1 == NULL) && (field2 == NULL)) return -1;

	free(field1);
	free(field2);

	counter = 0;

	return 0;
}

int field_counter(){
	return counter;
}

int field_state(int field, int element){
	if((field != 1) && (field != 2)) return -1;
	if((element < 0) || (element > (counter-1))) return -2;

	if((field1 == NULL) || (field2 == NULL)) return -3;

	if(field == 1) return field1[element];
	if(field == 2) return field2[element];

	return -4;
}

int field_set(int field, int element, int state){
	if((field != 1) && (field != 2)) return -1;
	if((element < 0) || (element > (counter-1))) return -2;

	if((field1 == NULL) || (field2 == NULL)) return -3;

	if(state < 0) return -4;

	if(field == 1) field1[element] = state;
	if(field == 2) field2[element] = state;

	return 0;
}

