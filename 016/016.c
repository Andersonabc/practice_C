#include <stdio.h>
#include <string.h>

void main(){
	int i=0,j=0,k=0;
	int count=0;
	char move[2];
	char mm;
	char oo;
	int pic[6][9]={{10,11,12,13,14,15,16,17,18},{20,21,22,23,24,25,26,27,28},{30,31,32,33,34,35,36,37,38},{40,41,42,43,44,45,46,47,48},{50,51,52,53,54,55,56,57,58},{60,61,62,63,64,65,66,67,68}};
/*	for(i=0 ; i<9 ; i++){
		printf("%d  ",pic1[i]);
	}*/
	
	//printf("%d",strcmp(move,"-1"));
	
	tpdw(pic[4]);
	
	int aa[3][3];
	int bb[3][3];
	int flat[3][4]={{2,3,5,1},{2,6,5,4},{1,6,3,4}};
	for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            aa[i][j]=j+i*3;
            bb[j][i]=j+i*3;
        }
    }
    
    
    scanf("%s",move);
	while (move[0]!='-'&&move[1]!='0'){
		int r=0,num=0;
		oo=move[0];
		mm=move[1];
		
    if(move[0]=='C'){
        turnaround(pic[5],'L');
        turnaround(pic[3],'R');
        flip(pic[2]);
        turnaround(pic[1],move[1]);
        controlchange(pic,move[1],bb[2],flat[2]);
        flip(pic[2]);
        turnaround(pic[5],'R');
        turnaround(pic[3],'L');
    }
    else{
        num=move[0]-'0';
        if(move[1]=='U'||move[1]=='D'){
        //	printf("work u\n");
            if(num%3==0){
                // 1 turn
                if(move[1]=='U')  turnaround(pic[0],'L');
                else turnaround(pic[0],'R');
            }
            else if(num%3==2){
                if(move[1]=='U')  turnaround(pic[2],'R');
                else turnaround(pic[2],'L');
                // 3 turn
            }

            controlchange(pic,move[1],bb[num%3],flat[1]);

        }
        else if(move[1]=='R'||move[1]=='L'){
        //	printf("work r\n");
            if(num>=0&&num<=2){
                if(move[1]=='L')  turnaround(pic[5],'R');
                else turnaround(pic[5],'L');
 
                r=0;
                // 4 turn
            }
            else if(num>=6&&num<=8){

                turnaround(pic[3],move[1]);
                r=2;
                // 6 turn
            }
            else{
                r=1;
            }

            controlchange(pic,move[1],aa[r],flat[0]);           
        }
    }
   /* for(j=0 ; j<6 ; j++){
 		for(i=0 ; i<9 ; i++){
			printf("%d ",pic[j][i]);
			if((i%3)==2) printf("\n");
		}  
		printf("\n"); 	
	}	*/		
			
		scanf("%s",move);
	}    
	for(i=0 ; i<9 ; i++){
		printf("%d ",pic[1][i]);
		if((i%3)==2) printf("\n");
	}
	

	
}
void spinright (int start,int data[9]){
	int i=0,j=0,k=0;
	for (i=start ; i<start+3 ; i++){
		data[i]+=10;
		if(data[i]>70) data[i]-=60;
	}
} 
void spinleft (int start,int data[9]){
	int i=0,j=0,k=0;
	for (i=start ; i<start+3 ; i++){
		data[i]-=10;
		if(data[i]<10) data[i]+=60;
	}
} 
void goup(int start,int data[9]){
	int i=0,j=0,k=0;
	for (i=start ; i<=start+6 ; i+=3){
		data[i]+=10;
		if(data[i]>=70) data[i]-=50;
		else if ((data[i] % 10) == 3) data[i]+=10;
		else if ((data[i] % 10) == 3) data[i]+=10;
	}
}


void turnaround(int data[9],char c){
	//printf("turmaround\n");
    int i=0;
    if(c=='L'){
        for(i=0;i<3;i++) turnright(data);
    }
    else{
        turnright(data);
    }
}
int turnright(int data[9]){
	//printf("turnright\n");
	int rect[3][3];
    int i=0,j=0,tmp[3][3];
    for(i=0 ; i<3 ; i++){
    	for(j=0 ; j<3 ; j++){
    		rect[i][j]=data[3*i+j];
		}
	}
    for (i=0;i<3;i++){
        for(j=0;j<3;j++){
            tmp[i][j]=rect[i][j];

        }
    }
    for (i=0;i<3;i++){
        for(j=2;j>=0;j--){
            rect[i][2-j]=tmp[j][i];

        }
    }
    for(i=0 ; i<3 ; i++){
    	for(j=0 ; j<3 ; j++){
    		data[3*i+j]=rect[i][j];
		}
	}
  
}
void lfrg(int data[9]){
	int i=0,j=0,tmp[3][3];
	int rect[3][3];
	for(i=0 ; i<3 ; i++){
    	for(j=0 ; j<3 ; j++){
    		rect[i][j]=data[3*i+j];
		}
	}
    
    for (i=0;i<3;i++){
        for(j=0;j<3;j++){
            tmp[i][j]=rect[i][j];

        }
    }
    for (i=0;i<3;i++){
        for(j=0;j<3;j++){
            rect[i][j]=tmp[i][2-j];

        }
    }
    for(i=0 ; i<3 ; i++){
    	for(j=0 ; j<3 ; j++){
    		data[3*i+j]=rect[i][j];
		}
	}     
}
void tpdw(int data[9]){
	int i=0,j=0,tmp[3][3];
	int rect[3][3];
    for(i=0 ; i<3 ; i++){
    	for(j=0 ; j<3 ; j++){
    		rect[i][j]=data[3*i+j];
		}
	}	
    
    for (i=0;i<3;i++){
        for(j=0;j<3;j++){
            tmp[i][j]=rect[i][j];

        }
    }
    for (i=0;i<3;i++){
        for(j=0;j<3;j++){
            rect[i][j]=tmp[2-i][j];

        }
    }
    for(i=0 ; i<3 ; i++){
    	for(j=0 ; j<3 ; j++){
    		data[3*i+j]=rect[i][j];
		}
	}     
}
void flip (int data[9]){
	tpdw(data);
	lfrg(data);
}
void flippic5 (int data[][9],char c){
	int i=0,j=0;	
    if(c=='D'||c=='U')tpdw(data[4]);
    else if(c=='R'||c=='L')lfrg(data[4]);	
}
void controlchange (int data[][9],char c,int number[3],int flat[4]){
	
	//printf("controlchange\n");
    int i=0,j=0;
    /*for(i=0 ; i<6 ; i++){
    	for(j=0 ; j<9 ; j++){
    		printf("%d ",data[i][j]);
		}
		printf("\n");
	}*/
 	
    flippic5(data,c);
   
    //
    if(c=='D'||c=='L'){
        for(i=0;i<3;i++) change(data,number,flat,c);

    }
    else{
        change(data,number,flat,c);
    }
    //

    flippic5(data,c);	
}
void change (int data[][9] , int number[3], int flat[4]){
	int i=0,j=0,k=0,x,y;
	/*for(i=0 ; i<6 ; i++){
		for(j=0 ; j<9 ; j++){
			printf("%d ",data[i][j]);
		}
		printf("\n");
	}*/
	int a=0,b=0;
	int rect[6][3][3];
	int tmp[6][3][3];
	for (i=0 ; i<6 ; i++){
		for(j=0 ; j<3 ; j++){
			for(k=0 ; k<3 ; k++){
				rect[i][j][k]=data[i][3*j+k];
				tmp[i][j][k]=data[i][3*j+k];
				//printf("%d ",rect[i][j][k]);
			}
		}
	//	printf("\n");
	}
    for (i=0;i<3;i++){
        for(j=0;j<3;j++){
            transfer(number[j],&x,&y);
            rect[flat[i+1]-1][y][x]=tmp[flat[i]-1][y][x];

        }
    }

    for(j=0;j<3;j++){
        transfer(number[j],&x,&y);
        rect[flat[0]-1][y][x]=tmp[flat[3]-1][y][x];

    }
    //printf("test\n");
	for (i=0 ; i<6 ; i++){
		for(j=0 ; j<3 ; j++){
			for(k=0 ; k<3 ; k++){
				data[i][3*j+k]=rect[i][j][k];
			}
		}
	}
/*	for(i=0 ; i<6 ; i++){
		for(j=0 ; j<9 ; j++){
			printf("%d ",data[i][j]);
		}
		printf("\n");
	}*/
	
		
	
}
void transfer(int fig,int* x,int* y){
    *x=fig%3;
    if(fig>=0&&fig<=2) *y=0;
    else if(fig>=6&&fig<=8) *y=2;
    else if(fig>=3&&fig<=5) *y=1;
   
}
