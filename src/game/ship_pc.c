/*########################
###
###		This Programm
###		falls under the
###		MIT Software
###		license. Check
###		COPYING for 
###		further
###		information.
###
########################*/

#include <stdio.h>
#include <stdlib.h>

void ship_pc(int *field,int size,int type1,int type2,int type3,int type4){
int i=0;
int counter;
char direct;
int helpdirect;

for(i=0;i<type1; i++){

counter=rand() % (size*size);
helpdirect=rand() % 4;
switch(helpdirect){
case 0: direct='o';
	break;
case 1: direct='r';
	break;
case 2: direct='u';
	break;
case 3: direct='l';
	break;
	return -1;}

if((ship_set(&field, 1, counter, direct))=-1){i-=1};
}

for(i=0;i<type2; i++){

counter=rand() % (size*size);
helpdirect=rand() % 4;
switch(helpdirect){
case 0: direct='o';
	break;
case 1: direct='r';
	break;
case 2: direct='u';
	break;
case 3: direct='l';
	break;
	return -1;}

if((ship_set(&field, 2, counter, direct))=-1){i-=1};
}	

for(i=0;i<type3; i++){

counter=rand() % (size*size);
helpdirect=rand() % 4;
switch(helpdirect){
case 0: direct='o';
	break;
case 1: direct='r';
	break;
case 2: direct='u';
	break;
case 3: direct='l';
	break;
	return -1;}

if((ship_set(&field, 3, counter, direct))=-1){i-=1};
}

for(i=0;i<type4; i++){

counter=rand() % (size*size);
helpdirect=rand() % 4;
switch(helpdirect){
case 0: direct='o';
	break;
case 1: direct='r';
	break;
case 2: direct='u';
	break;
case 3: direct='l';
	break;
	return -1;}

if((ship_set(&field, 4, counter, direct))=-1){i-=1};
}
}
