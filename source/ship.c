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

		tmp_ship->ship_id = ship_id++;
		tmp_ship->active = 0;
		tmp_ship->direction = 0;
		tmp_ship->coordinates = NULL;
		tmp_ship->next = NULL;

		if(i<fours*2) {tmp_ship->elements = 4;}
		else if (i<fours*2+threes*2) {tmp_ship->elements = 3;}
		else if (i<fours*2+threes*2+twos*2) {tmp_ship->elements = 2;}
		else if (i<fours*2+threes*2+twos*2+ones*2) {tmp_ship->elements = 1; }

		if(i<fours) {tmp_ship->owner = 1;} 
		else if (i<fours*2) {tmp_ship->owner = 2;}
		else if (i<fours*2+threes) {tmp_ship->owner = 1;}
		else if (i<fours*2+threes*2) {tmp_ship->owner = 2;}
		else if (i<fours*2+threes*2+twos) {tmp_ship->owner = 1;}
		else if (i<fours*2+threes*2+twos*2) {tmp_ship->owner = 2;}
		else if (i<fours*2+threes*2+twos*2+ones) {tmp_ship->owner = 1;}
		else if (i<fours*2+threes*2+twos*2+ones*2) {tmp_ship->owner = 2;}
		
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
	if((coordinate > (field_counter()-1))) return -2;		// Koordinate existiert nicht
	if((direction != 'n') && (direction != 'e') && (direction != 's') && (direction != 'w')) return -3;		// übergebene Himmelsrichtung gibt es nicht
	if(tmp_ship->active != 0) return -4;	// Schiff ist schon gesetzt

	for(i=0;i<(tmp_ship->elements);i++) {
		
	 // printf("elemente %d\nowner%d\n", tmp_ship->elements, tmp_ship->owner);

		if((direction == 'n') && ((coordinate-((tmp_ship->elements)-1)*sqrt(field_counter())) < 0)) {return -5;}				// Schiff geht über das Spielfeld hinaus
		else if((direction == 'e') && (((coordinate%(int)sqrt(field_counter())) + ((tmp_ship->elements)-1)) >= sqrt(field_counter()))) {return -5;}
		else if((direction == 's') && ((coordinate+((tmp_ship->elements)-1)*sqrt(field_counter())) >= field_counter())) {return -5;} 	// Schiff geht über das Spielfeld hinaus
		else if((direction == 'w') && (((coordinate%(int)sqrt(field_counter())) - ((tmp_ship->elements)-1)) < 0)) {return -5;}

		//printf("Owner: %d\n", tmp_ship->owner);

		if((direction == 'n') && (field_state(tmp_ship->owner, coordinate-i*sqrt(field_counter())) != 0)) {return -6;}		// Es ist schon ein Schiff drauf
		else if((direction == 'e') && (field_state(tmp_ship->owner, coordinate+i) != 0)) {return -6;}							// Es ist schon ein Schiff drauf
		else if((direction == 's') && (field_state(tmp_ship->owner, coordinate+i*sqrt(field_counter())) != 0)) {return -6;}		// Es ist schon ein Schiff drauf
		else if((direction == 'w') && (field_state(tmp_ship->owner, coordinate-i) != 0)) {return -6;}							// Es ist schon ein Schiff drauf
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
			field_set(tmp_ship->owner, coordinate+i, ship_id);
			tmp_coordinate->coordinate = coordinate+i;		
		} else if(direction == 's') {
			field_set(tmp_ship->owner, coordinate+i*sqrt(field_counter()), ship_id);
			tmp_coordinate->coordinate = coordinate+i*sqrt(field_counter());
		} else if(direction == 'w') {
			field_set(tmp_ship->owner, coordinate-i, ship_id);
			tmp_coordinate->coordinate = coordinate-i;
		}

		tmp_coordinate->state = 1;
		tmp_coordinate->next = NULL;
	}

	tmp_ship->active = 1;
	tmp_ship->direction = direction;

	return 0;
}

unsigned short ship_start(unsigned short ship_id){
	SHIP *tmp_ship = NULL;
	tmp_ship = ship_address(ship_id);

	if(tmp_ship == NULL) return -1;		// Schiff existiert nicht
	if(tmp_ship->active == 0) return -2;		// Schiff wurde noch nicht gesetzt
	
	return tmp_ship->coordinates->coordinate;
}

int ship_state(unsigned short ship_id, unsigned short coordinate){
	SHIP *tmp_ship = NULL;
	SHIP_COORDINATES *tmp_coordinate = NULL;
	tmp_ship = ship_address(ship_id);

	if(tmp_ship == NULL) return -1;		// Schiff existiert nicht
	if(tmp_ship->active == 0) return 0;		// Schiff wurde noch nicht gesetzt
	
	tmp_coordinate = tmp_ship->coordinates;

	while(tmp_coordinate != NULL) {
		if(tmp_coordinate->coordinate == coordinate) return tmp_coordinate->state; 	
		tmp_coordinate = tmp_coordinate->next;
	}
	return -2;		// Koordinate gab es nicht
}

int ship_change(unsigned short ship_id, unsigned short coordinate, int state){
	SHIP *tmp_ship = NULL;
	SHIP_COORDINATES *tmp_coordinate = NULL;
	tmp_ship = ship_address(ship_id);

	if(tmp_ship == NULL) return -1;		// Schiff existiert nicht
	if(tmp_ship->active == 0) return -2;		// Schiff wurde noch nicht gesetzt
	if((state != 3) && (state != 4)) return -3;		// ungültiger Status
	
	tmp_coordinate = tmp_ship->coordinates;

	while(tmp_coordinate != NULL) {
		if(tmp_coordinate->coordinate == coordinate) {
			tmp_coordinate->state = state;
			return 0; 	
		}
		tmp_coordinate = tmp_coordinate->next;
	}
	return -4;		// Koordinate gab es nicht
}

