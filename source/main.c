#include <stdio.h>
#include "field.h"

int main(void){
	printf("%d\n", field_init(13));
	field_set(1, 168, 1);
	printf("%d\n", field_state(1, 168));

	return 0;
}
