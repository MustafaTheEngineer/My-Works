#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define ROW 29
#define COL 120
#define CHAR 'N'

void freshen(char [][COL],int min[],int max[]);
void show(char [][COL]);
void findArea(char [][COL],int *min,int *max);
void transfer(char [][COL],char [][COL]);
void drawLine(char [][COL],int,int,int,char);

int main(void){

	int i,k,live=0,min[2]={COL,COL},max[2];
	char map[ROW][COL];
	for(i=0 ; i < ROW ; ++i){
		for(k=0 ; k < COL ; ++k)
			map[i][k]=' ';
	}
	map[8][8]=CHAR;
	map[8][9]=CHAR;
	map[9][7]=CHAR;
	map[9][8]=CHAR;
	map[9][9]=CHAR;
	map[9][10]=CHAR;
	map[10][7]=CHAR;
	map[10][8]=CHAR;
	map[10][10]=CHAR;
	map[10][11]=CHAR;
	map[11][9]=CHAR;
	map[11][10]=CHAR;
	
	drawLine(map,3,7,3,'v');
	
	for(i=0;i<100;++i){
		show(map);
		findArea(map,min,max);
		freshen(map,min,max);
	}
		
	getch();
	return 0;
}

void freshen(char map[][COL],int min[],int max[]){
	int i,k,l,m,live=0;
	char change[ROW][COL];
	for(i=0;i<ROW;++i){
		for(k=0;k<COL;++k)
			change[i][k]=map[i][k];
	}
	for(i=min[0] ; i <= max[0] ; ++i){
		for(k=min[1] ; k <= max[1] ; ++k){
			for(l=0 ; l < 3 ; ++l){
				for(m=0 ; m < 3 ; ++m){
					if(map[i-1+l][k-1+m] == CHAR)
						++live;
				}
			}
			if(map[i][k] == CHAR){
				--live;
				if(live < 2)
					change[i][k] = ' ';
				else if(live > 3)
					change[i][k] = ' ';
			}
			else{
				if(live==3)
					change[i][k] = CHAR;
			}
			live = 0;
		}
	}
	transfer(map,change);
}

void show(char map[][COL]){
	int i,k;
	for(i=0 ; i < ROW ; ++i){
		for(k=0 ; k < COL ; ++k)
			printf("%c",map[i][k]);
	}
	for(i=0; i< 100000000 ; ++i);
	system("cls");
}

void findArea(char map[][COL],int *min,int *max){
	int i,k;
	for(i=0 ; i<ROW ; ++i){
		for(k=0 ; k<COL ; ++k){
			if(map[i][k] == CHAR){
				if(i > (max[0]-1))
					max[0] = (i+1);
				else if(i < (min[0]-1))
					min[0] = (i-1);
				if(k > (max[1]-1))
					max[1] = (k+1);
				else if(k < (min[1]-1))
					min[1] = (k-1);
			}
			
		}
	}
}

void transfer(char mainMap[][COL],char change[][COL]){
	int i,k;
	for(i=0;i<ROW;++i){
		for(k=0;k<COL;++k)
			mainMap[i][k]=change[i][k];
	}
}

void drawLine(char map[][COL],int x,int y,int length,char ch){
	if(x < 0 || x > COL)
		fprintf(stderr,"x value is out of range.");
	if(y < 0 || y > ROW)
		fprintf(stderr,"y value is out of range.");
	else{
		int i;
		if(ch='v'){
			for(i=0;i<length;++i)
				map[y+i][x]=CHAR;
		}
		else if(ch='h'){
			for(i=0;i<length;++i)
				map[y][x+i]=CHAR;
		}
		else
			fprintf(stderr,"char ch must be v(vertical) or h(horizontal)");
	}
}



