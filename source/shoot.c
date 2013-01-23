#include "main.h"
#include "ship.h"
#include "field.h"
#include "shoot.h"

int shoot(int field, unsigned short coordinate) {

	int f_state;

	f_state = field_state(field, coordinate);

	if(ship_state(f_state, coordinate) <= 0) {return -1;}		// Fehler: Schiff existiert nicht oder wurde noch nicht gesetzt
	else if(ship_state(f_state, coordinate) == 2) {return -2;}	// Fehler: Schiff wurde bereits angeschossen
	else if(ship_state(f_state, coordinate) == 3) {return -3;}	// Fehler: Schiff wurde bereits versenkt
	
	if(f_state == 0) {											// Wasser getroffen
		field_set(field, coordinate, 1);
	} else if(f_state == 1) {
		return -4;												// Fehler: Dieses Feld ist bereits eine Niete
	} else if(f_state >= MIN_SHIP_ID) {
		ship_change(f_state, coordinate, 2);					// Neuer Status: Schiff angeschossen
		ship_sunk(f_state);										// ggf. Status des Schiffes auf versenkt ändern
	}

	return 0;
}
