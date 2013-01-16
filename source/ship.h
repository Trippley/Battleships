typedef struct _ship{
	unsigned short ship_id;
	unsigned short owner;
	unsigned short active;
	unsigned short elements;
	unsigned int *coordinates;
	struct _ship *next;
} SHIP;

SHIP *ship_list;
unsigned int ship_id;

int ship_init();
