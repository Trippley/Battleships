#include "main.h"
#include "field.h"
#include "ship.h"


int main(void){
	printf("%d\n", field_init(100));
	printf("%d\n", ship_init());
	field_set(1, 168, 1);
	printf("%d\n", field_state(1, 168));

	return 0;
}
