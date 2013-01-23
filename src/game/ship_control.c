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

int ship_control(int *field, int size, int counter, int type, char direct){
int *pointer;
int i,j;
int x_count;
int y_count;
int x_check;
int y_check;
int counter_check;
/*Berechnung der x und y Koordinaten des Anfangspunktes des Schiffes*/
x_count=counter % size;
y_count=counter/size;
/*Prüfung ob das Schiff im Array ist und im Umfeld keine belegten Felder hat*/

switch(direct){
	case 'o': if((y_count-type+1)<0){return -1;}
		  x_check=x_count-1;
		  y_check=y_count-type;
		  for(i=0;i<3;i++){
		  	for(j=0;j<type+2;j++){
		  		if(((x_check+i)<size)&&((x_check+i)>=0)&&((y_check+j)<size)&&((y_check+j)>=0)){
		  			counter_check=(y_check+j)*size+x_check+i;
		  			pointer=field+counter_check;
		  			if(*pointer!=0){return -1;};
		  			}
		  		}
		  	}
		
		break;
		
	case 'u':  if((y_count+type-1)>=size){return -1;}
		   x_check=x_count-1;
		   y_check=y_count-1;
		  for(i=0;i<3;i++){
		  	for(j=0;j<type+2;j++){
		  		if(((x_check+i)<size)&&((x_check+i)>=0)&&((y_check+j)<size)&&((y_check+j)>=0)){
		  			counter_check=(y_check+j)*size+x_check+i;
		  			pointer=field+counter_check;
		  			if(*pointer!=0){return -1;};
		  			}
		  		}
		  	}

		break;		
	case 'r':  if((x_count+type-1)>=size){return -1;}
		  x_check=x_count-1;
		  y_check=y_count-1;
		  for(i=0;i<3;i++){
		  	for(j=0;j<type+2;j++){
		  		if(((x_check+j)<size)&&((x_check+j)>=0)&&((y_check+i)<size)&&((y_check+i)>=0)){
		  			counter_check=(y_check+i)*size+x_check+j;
		  			pointer=field+counter_check;
		  			if(*pointer!=0){return -1;};
		  			}
		  		}
		  	}
		break;	
	case 'l': if((x_count-type+1)<0){return -1;}
		  x_check=x_count-type;
		  y_check=y_count-1;
		  for(i=0;i<3;i++){
		  	for(j=0;j<type+2;j++){
		  		if(((x_check+j)<size)&&((x_check+j)>=0)&&((y_check+i)<size)&&((y_check+i)>=0)){
		  			counter_check=(y_check+i)*size+x_check+j;
		  			pointer=field+counter_check;
		  			if(*pointer!=0){return -1;};
		  			}
		  		}
		  	}
		break;	
	}	
	return 0;
	}
		
/*
int main(){
int size=5;
int field[25];
int i;
int typ=2;
int counter=9;
char direct='l';
for(i=0;i<25;i++){
field[i]=0;}

field[6]=3;
field[11]=3;
field[16]=3;
field[23]=2;
field[24]=2;

printf("Ergebnis ist %d",ship_control(&field[1], size, counter, typ, direct));

return 0;
}
	
	*/
