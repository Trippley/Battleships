#include "main.h"
#include "ship.h"
#include "field.h"

SHIP *ship_list = NULL;
unsigned short ship_id = 10;					// Werte zwischen 0 und 9 sind für den Status reserviert

int ship_init(){
	unsigned int fours = 0, threes = 0, twos = 0, ones = 0;
	unsigned int i;
	SHIP *tmp_ship = ship_list;

	if(!field_counter()) return -1;				// es existiert noch kein Spielfeld

	fours = 1*field_counter()/169;
	threes = 2*field_counter()/169;
	twos = 3*field_counter()/169;
	ones = 4*field_counter()/169;

	if(ship_list != NULL) return -2;		// wurde schon initialisiert
	

	for(i=0; i<(fours+threes+twos+ones)*2; i++) {

		if(tmp_ship == NULL) {
			ship_list = malloc(sizeof(SHIP));
			tmp_ship = ship_list;
		} else {
			tmp_ship->next = malloc(sizeof(SHIP));
			tmp_ship = tmp_ship->next;
		}

		tmp_ship->ship_id = ++ship_id;
		tmp_ship->active = 0;
		tmp_ship->direction = 0;
		tmp_ship->coordinates = NULL;
		tmp_ship->next = NULL;

		if(i<fours*2) {tmp_ship->elements = 4;}
		else if (i<threes*2) {tmp_ship->elements = 3;}
		else if (i<twos*2) {tmp_ship->elements = 2;}
		else if (i<ones*2) {tmp_ship->elements = 1; }

		if(i<fours) {tmp_ship->owner = 1;} 
		else if (i<fours*2) {tmp_ship->owner = 2;}
		else if (i<threes) {tmp_ship->owner = 1;}
		else if (i<threes*2) {tmp_ship->owner = 2;}
		else if (i<twos) {tmp_ship->owner = 1;}
		else if (i<twos*2) {tmp_ship->owner = 2;}
		else if (i<ones) {tmp_ship->owner = 1;}
		else if (i<ones*2) {tmp_ship->owner = 2;}
		
	}

	return 0;
}

char ship_direction(unsigned short ship_id){
	SHIP *tmp_ship = ship_list;

	while(tmp_ship != NULL){
		if(tmp_ship->ship_id == ship_id) {
			return tmp_ship->direction;
		}
		tmp_ship = tmp_ship->next;
	}
	return -1; 
}

unsigned short ship_counter(){
	SHIP *tmp_ship = ship_list;
	unsigned short i = 0;

	while(tmp_ship != NULL){
		tmp_ship = tmp_ship->next;
		i++;
	}
	return i;
}


