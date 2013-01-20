#include "main.h"
#include "field.h"
#include "ship.h"


int main(void){
	printf("%d\n", field_init(13));
	printf("%d\n", ship_init());
	field_set(1, 168, 1);
	printf("%d\n", ship_counter());

	return 0;
}
