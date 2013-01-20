#include "main.h"
#include "field.h"
#include "ship.h"


int main(void){


	printf("%d\n", field_init(13));
	printf("%d\n", ship_init());

	printf("%d\n", ship_set(10, 39, 'n'));
	printf("Koordinaten: %d, %d, %d, %d\n", field_state(1, 29), field_state(1, 30), field_state(1, 31), field_state(1, 32));
	printf("%d\n", ship_state(10, 0));

	return 0;
}
