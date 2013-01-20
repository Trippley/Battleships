typedef struct _ship_coordinates{
	unsigned short coordinate;
	int state;
	struct _ship_coordinates *next;
} SHIP_COORDINATES;

typedef struct _ship{
	unsigned short ship_id;
	unsigned short owner;
	unsigned short active;
	unsigned short elements;
	char direction;
	SHIP_COORDINATES *coordinates;
	struct _ship *next;
} SHIP;

SHIP *ship_list;
unsigned short ship_id;

/************************************************************************
 *                                                                      *
 * Die Funktion ship_init dient zum Initialisieren der Schiffe für beide*
 * Spieler. Die Anzahl der Schiffe wird dabei proportional zur Größe    *
 * des Spielfeldes berechnet. Mögliche Rückgabewerte sind:              *
 *                                                                      *
 * -1: Es existiert noch kein Spielfeld.                                *
 * -2: Die ship_list wurde bereits initialisiert.                       *
 *  0: Die Schiffe wurden korrekt initialisiert.                        *
 *                                                                      *
 ************************************************************************/
int ship_init();


/************************************************************************
 *                                                                      *
 * Die Funktion ship_direction gibt die Richtung eines Schiffs zurück.  *
 * feldes zurück. Mögliche Rückgabewerte sind:                          *
 *                                                                      *
 *   0: Das Schiff wurde noch nicht gesetzt.                            *
 * 'n': Norden.                                                         *
 * 'e': Osten.                                                          *
 * 's': Süden.                                                          *
 * 'w': Westen.                                                         *
 *  -1: Das Schiff existiert nicht.                                     *
 *                                                                      *
 ************************************************************************/
char ship_direction(unsigned short ship_id);


/************************************************************************
 *                                                                      *
 * Die Funktion ship_counter gibt die Anzahl der Schiffe beider Spieler *
 * zurück, das heißt z.B. 2*10=20.                                      *
 *                                                                      *
 ************************************************************************/
unsigned short ship_counter();


/************************************************************************
 *                                                                      *
 * Die Funktion ship_set dient zum Setzen der Schiffe. Übergabeparamter *
 * sind die ship_id, die Anfangskoordinate und die Richtung.            *
 * Mögliche Rückgabewerte sind:                                         *
 *                                                                      *
 *   0: Das Schiff wurde gesetzt.                                       *
 *  -1: Das Schiff existiert nicht.                                     *
 *  -2: Die angegebene Koordinate existiert nicht.                      *
 *  -3: Die übergebene Richtung existiert nicht.                        *
 *  -4: Das Schiff wurde bereits gesetzt.                               *
 *  -5: Das Schiff geht über den Spielfeldrand hinaus.                  *
 *  -6: Eines der vom Schiff zu besetzenden Felder ist schon besetzt.   *
 *                                                                      *
 ************************************************************************/
int ship_set(unsigned short ship_id, unsigned short coordinate, char direction);


unsigned short ship_start(unsigned short ship_id);
int ship_state(unsigned short ship_id, unsigned short coordinate);
int ship_change(unsigned short ship_id, unsigned short coordinate, int state);

SHIP *ship_address(unsigned short ship_id);
