#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void main(){
	int map[20][20];
	int i=0,j=0,k=0,body=1,fruits=0;
	int direction=4;
	int mapx[100],mapy[100];
	mapx[0]=9,mapy[0]=9;	
	int temp1=0,temp2=0;
	for(i=1 ; i<20 ;i++){
		for(j=0 ; j<20 ; j++){
			map[i][j]=0;	
			map[0][j]=1;
			map[19][j]=1;				
		}
		map[i][0]=1;
		map[i][19]=1;		
	}
	/*for(i=0 ; i<20 ; i++){
		for(j=0 ; j<20 ; j++){
			printf("%d",map[i][j]);
		}
		printf("\n");	
	}	*/
	scanf("%d",&fruits);
	for(i=0; i<fruits;i++) {
		scanf("%d %d",&temp1,&temp2);
		map[temp1][temp2]=-1;
	}
	map[9][9]=0;
	int movex=0;
	int movey=0;
	int move = 0;
	int hit=0;
	int t1=0,t2=0;
	scanf("%d",&temp1);
	while (temp1 != -1){
		move=0;
		hit=0;
		t1=0;
		t2=0;
		if(temp1 != 5 && temp1!=0){
			direction=temp1;
		}else if(direction == 1 && temp1==5){
			movex=-1;
			movey=0;
			move=1;
		}else if(direction == 2 && temp1==5){
			movex=1;
			movey=0;
			move=1;
		}else if(direction == 3 && temp1==5){
			movex=0;
			movey=-1;
			move=1;
		}else if(direction == 4 && temp1==5){
			movex=0;
			movey=1;
			move=1;
		}
		if(move == 1){
			
			if(map[mapx[0]+movex][mapy[0]+movey] == 1) {
				break;			
			}
			else if(map[mapx[0]+movex][mapy[0]+movey] == -1){
				//printf("%d",map[mapx[0]+movex][mapy[0]+movey]);
				map[mapx[0]+movex][mapy[0]+movey]=0;
				for(i=body ; i>=1 ;i--){
					mapx[i]=mapx[i-1];
					mapy[i]=mapy[i-1];
				}
				//printf("Εάͺψ");
				for (i=0 ; i<body ; i++){
					if((mapx[0]+movex == mapx[i])&&(mapy[0]+movey == mapy[i])){
						hit=1;						
						break;
					} 
				}
				if (hit == 1){
					for(i=0 ; i<body ; i++){
						mapx[i]=mapx[i+1];
						mapy[i]=mapy[i+1];
						mapx[body]=NULL;
						mapy[body]=NULL;
					}
					break;					
				}
				else{
					mapx[0]+=movex;
					mapy[0]+=movey;
					body+=1;				
				}
				//printf("%d",map[mapx[0]+movex][mapy[0]+movey]);
			}else{
				//map[mapx[0]+movex][mapy[0]+movey]=8;
				t1=mapx[body-1];
				t2=mapy[body-1];			
				for(i=body-1 ; i>=1 ;i--){
					mapx[i]=mapx[i-1];
					mapy[i]=mapy[i-1];
				}
				for (i=0 ; i<body ; i++){
					if((mapx[0]+movex == mapx[i])&&(mapy[0]+movey == mapy[i])){
						hit=1;						
						break;
					} 
				}
				if (hit == 1){
					for(i=0 ; i<body-1 ;i++){
						mapx[i]=mapx[i+1];
						mapy[i]=mapy[i+1];
					}
					mapx[body-1]=t1;
					mapy[body-1]=t2;
					break;					
				}
				else{
					mapx[0]+=movex;	
					mapy[0]+=movey;				
				}			
				
			}			
		}					
		if(temp1 == 0){
			printf("%d\n",body);
			for (i=0 ; i<body ; i++){
			printf("%d %d\n",mapx[i],mapy[i]);
		}	
		}
		scanf("%d",&temp1);		
		}
	
		printf("%d\n",body);
		for (i=0 ; i<body ; i++){
			printf("%d %d\n",mapx[i],mapy[i]);
		}	
				
	}


