typedef struct _ship{
	unsigned short ship_id;
	unsigned short owner;
	unsigned short active;
	unsigned short elements;
	char direction;
	unsigned int *coordinates;
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
