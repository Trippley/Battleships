#include "main.h"
#include "ship.h"
#include "field.h"
#include <math.h>

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

SHIP *ship_address(unsigned short ship_id){
	SHIP *tmp_ship = ship_list;
	
	while(tmp_ship != NULL){
		if(tmp_ship->ship_id == ship_id) {
			return tmp_ship;
		}
		tmp_ship = tmp_ship->next;
	}

	return NULL;
}

char ship_direction(unsigned short ship_id){
	SHIP *tmp_ship = NULL;

	tmp_ship = ship_address(ship_id);

	if(tmp_ship != NULL) return tmp_ship->direction;

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

int ship_set(unsigned short ship_id, unsigned short coordinate, char direction){
	SHIP *tmp_ship = NULL;
	SHIP_COORDINATES *tmp_coordinate = NULL;
	int i;
	
	tmp_ship = ship_address(ship_id);

	if(tmp_ship == NULL) return -1;			// Schiff existiert nicht
	if((coordinate < 0) || (coordinate > (field_counter()-1))) return -2;		// Koordinate existiert nicht
	if((direction != 'n') || (direction != 'e') || (direction != 's') || (direction != 'w')) return -3;		// übergebene Himmelsrichtung gibt es nicht
	if(tmp_ship->active != 0) return -4;	//Schiff ist schon gesetzt

	for(i=0; i<(tmp_ship->elements);i++) {
		
		if((direction == 'n') && ((coordinate-((tmp_ship->elements)-1)*sqrt(field_counter())) < 0)) return -5;					// Schiff geht über das Spielfeld hinaus
		if((direction == 'e') && (((coordinate%(int)sqrt(field_counter())) + ((tmp_ship->elements)-1)) < sqrt(field_counter()))) return -5;
		if((direction == 's') && ((coordinate+((tmp_ship->elements)-1)*sqrt(field_counter())) > field_counter())) return -5; 	// Schiff geht über das Spielfeld hinaus
		if((direction == 'w') && (((coordinate%(int)sqrt(field_counter())) - ((tmp_ship->elements)-1)) < 0)) return -5;

		if((direction == 'n') && (field_state(tmp_ship->owner, coordinate-i*sqrt(field_counter())) != 0)) return -6;		// Es ist schon ein Schiff drauf
		if((direction == 'e') && (field_state(tmp_ship->owner, coordinate+i) != 0)) return -6; 							// Es ist schon ein Schiff drauf
		if((direction == 's') && (field_state(tmp_ship->owner, coordinate+i*sqrt(field_counter())) != 0)) return -6;		// Es ist schon ein Schiff drauf
		if((direction == 'w') && (field_state(tmp_ship->owner, coordinate-i) != 0)) return -6;							// Es ist schon ein Schiff drauf
	}

	for(i=0;i<(tmp_ship->elements);i++){

		if(tmp_coordinate == NULL) {
			tmp_coordinate = malloc(sizeof(SHIP_COORDINATES));
			tmp_ship->coordinates = tmp_coordinate;
		} else {
			tmp_coordinate->next = malloc(sizeof(SHIP_COORDINATES));
			tmp_coordinate = tmp_coordinate->next;
		}

		if(direction == 'n') {
			field_set(tmp_ship->owner, coordinate-i*sqrt(field_counter()), ship_id);
		
			tmp_coordinate->coordinate = coordinate-i*sqrt(field_counter());
		} else if(direction == 'e') {
		} else if(direction == 's') {
		} else if(direction == 'w') {
		}

		tmp_coordinate->state = 1;
		tmp_coordinate->next = NULL;
	}

	tmp_ship->active = 1;
	tmp_ship->direction = direction;
}
