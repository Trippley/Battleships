#include <stdio.h>
#include <stdlib.h>
void mark(int shoot, int *cfield, int size){
int x_shoot;
int y_shoot;
int temp;

 		x_shoot=shoot%size;
		y_shoot=shoot/size;
		
		if(((x_shoot-1)>=0)&&((y_shoot-1)>=0)){
			temp=(y_shoot-1)*size+(x_shoot-1);
			*cfield[temp]=1;
			}
			
		if(((y_shoot-1)>=0)){
			temp=(y_shoot-1)*size+(x_shoot);
			*cfield[temp]=1;
			}
		if(((x_shoot+1)<size)&&((y_shoot-1)>=0)){
			temp=(y_shoot-1)*size+(x_shoot+1);
			*cfield[temp]=1;
			}
		if(((x_shoot+1)<size)){
			temp=(y_shoot)*size+(x_shoot+1);
			*cfield[temp]=1;
			}	
		if(((x_shoot+1)<size)&&((y_shoot+1)<size)){
			temp=(y_shoot+1)*size+(x_shoot+1);
			*cfield[temp]=1;
			}
		if(((y_shoot+1)<size)){
			temp=(y_shoot+1)*size+(x_shoot);
			*cfield[temp]=1;
			}			
		if(((x_shoot-1)>=0)&&((y_shoot+1)<size)){
			temp=(y_shoot+1)*size+(x_shoot-1);
			*cfield[temp]=1;
			}
		if(((x_shoot-1)>=0)){
			temp=(y_shoot)*size+(x_shoot-1);
			*cfield[temp]=1;
			}

}

/* 1=daneben 2=getroffen 3=versenkt*/
int shoot_pc(int *cfield,int *memory,int size){
int shoot;
int i;
int result;
int temp;
int x_shoot;
int y_shoot;
int j;
int k;
int direct;
char orient;
if(*memory==-1){
	for(i=0;i<1;i++){
	shoot=rand()%(size*size);
	if(*cfield[shoot]!=0){i-=1;}
	}
	result=shoot(shoot);
*cfield[shoot]=result;
switch(result){
	case 1: return 0;break;
	case 2: *memory[0]=shoot;
		shoot_pc(&cfield, &memory, size);
		break;
	case 3: mark(shoot);
		for(k=0;k<3;k++){
		if(*memory[k]!=-1){
			mark(*memory[k]);
			*memory[k]=-1;}
		}
			
		shoot_pc(&cfield, &memory, size);
		break;	
					
		}
	}	

else{
	if(*memory[1]==-1){
			for(j=0;j<1,j++){
				direct=rand()%4;
			switch(direct){
			case 0: shoot=*memory[0]-size;
				if((shoot>=0)){if(*cfield[shoot]!=0)j-=1;}
				else{j-=1;}
				break;
			case 1:shoot=*memory[0]+1;
				x_shoot=shoot%size;
				if((x_shoot))
				if((*cfield[shoot]!=0)){j-=1;}
				break;
			case 2:shoot=*memory[0]+size;
				if((*cfield[shoot]!=0)&&(shoot<(size*size))){j-=1;}
				break;
			case 3:shoot=*memory[0]-1;
				if(*cfield[shoot]!=0){j-=1;}
				break;
				
			}
			
	result=shoot(shoot);
	*cfield[shoot]=result;
	switch(result){
	case 1: return 0;break;
	case 2: *memory[1]=shoot;
		shoot_pc(&cfield, &memory, size);
		break;
	case 3: case 3: mark(shoot);
		for(k=0;k<3;k++){
		if(*memory[k]!=-1){
			mark(*memory[k]);
			*memory[k]=-1;}
		}
			
		shoot_pc(&cfield, &memory, size);
		break;	
					
		}
	}
	
	else{ temp=*memory[0]-*memory[1];
		if(temp=size||temp=-size){orient='s';}
		else{orient='w';}
		
	direct=rand()%2;
	switch(direct):
	
	case 0: temp=size*size;
		for(k=0;k<3;k++){
			if((*memory[k]!=-1)&&(memory[k]<temp)){
				temp=memory[k];
				}
			}
			if(orient=='w'){shoot=temp-1;}
			else{shoot=temp-size;}
				
	case 1: temp=			
				
				
