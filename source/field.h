#define FIELD_MAX 100
#define FIELD_MIN 13

/************************************************************************
 *                                                                      *
 * Die Funktion field_init erzeugt 2 Spielfelder. Die Spielfelder sind  *
 * stets quadratisch, mit einer minimalen Größe von 13*13 Feldern und   *
 * einer maximalen Größe von 100*100 Feldern. Der Übergabeparameter     * 
 * muss zwischen 13 und 100 liegen. Alle einzelnen Elemente eines       *
 * werden mit 0 initalisiert. Es gibt folgende Rückgabewerte:           *
 *                                                                      *
 *  0: Die Spielfelder wurden korrekt initialisiert.                    *
 * -1: Die Spielfeldgröße wurde über- oder unterschritten.              *
 * -2: Eines oder beide Spielfelder existieren bereits und konnten      *
 *     daher nicht angelegt werden.                                     *
 * -3: Es steht nicht genügend Speicherplatz zur Initialisierung zur    *
 *     Verfügung.                                                       *
 *                                                                      *
 ************************************************************************/
int field_init(int size);


/************************************************************************
 *                                                                      *
 * Die Funktion field_delete löscht den für die Spielfelder             *
 * reservierten Speicherbereich.                                        *
 * Es gibt folgende Rückgabewerte:                                      *
 *                                                                      *
 *  0: Die Spielfelder wurden gelöscht, der Speicher wurde freigegeben. *
 * -1: Die Spielfelder können nicht gelöscht werden.                    *
 *                                                                      *
 ************************************************************************/
int field_delete();


/************************************************************************
 *                                                                      *
 * Die Funktion field_counter gibt die Anzahl der Elemente eines Spiel- *
 * feldes zurück.                                                       *
 *                                                                      *
 ************************************************************************/
int field_counter();


/************************************************************************
 *                                                                      *
 * Die Funktion field_state gibt den Zustand der Elemente eines Spiel-  *
 * feldes zurück. Der Übergabeparameter field muss 1 oder 2 sein. Der   *
 * Übergabeparameter element muss zwischen 0 und counter-1 liegen.      *
 * Es gibt folgende Rückgabewerte:                                      *
 *                                                                      *
 * -1: Es wurde ein Feld ausgewählt, das nicht existiert.               *
 * -2: Es wurde ein Element ausgewählt, das nicht existiert.            *
 * -3: Eines oder beides Spielfelder existieren nicht.                  *
 *                                                                      *
 * Weitere Rückgabewerte: Status des gewünschten Feldes                 *
 *    0: Wasser.					                                    *
 *    1: Niete (geschossen, aber nicht getroffen.                       *
 *    ansonsten: ship_id                                                *
 ************************************************************************/
int field_state(int field, int element);


/************************************************************************
 *                                                                      *
 * Die Funktion field_set ändert den Zustand der Elemente eines Spiel-  *
 * feldes. Der Übergabeparameter field muss 1 oder 2 sein. Der          *
 * Übergabeparameter element muss zwischen 0 und counter-1 liegen.      *
 * Es gibt folgende Rückgabewerte:                                      *
 *                                                                      *
 *  0: Der Status wurde geändert.
 * -1: Es wurde ein Feld ausgewählt, das nicht existiert.               *
 * -2: Es wurde ein Element ausgewählt, das nicht existiert.            *
 * -3: Eines oder beides Spielfelder existieren nicht.                  *
 * -4: Der Status des gewünschten Feldes ist nicht positiv.             *
 ************************************************************************/
int field_set(int field, int element, int state);


