#include <stdio.h>
#include <string.h>
#include <math.h>

void decimal_to_binary(int n, int length){
//	printf("decimal_to_binary\n");
//	printf("%d\n",n); 
	int i=0,j=0,k=0;
	k=pow(2,length-1);
	for (i=0 ; i<length ; i++){
		//printf("%d   %d\n",k,n);
		if((n/k)==1){
			printf("1 ");
			n=n%k;
		}else{
			printf("0 ");
		}
		k=pow(2,length-2-i);		
	}
	printf("\n");
}

void main(){
	int count=0,i=0,j=0,k=0;
	char NameData[100][100];
	int NumData[100][100];
	int Datalen[100];
	int action=0;
	char temp[100];
	scanf("%d",&action);
	while (action != 4){
		int fixnum=0,fixplace=0;
		int inputnum=0;
		int err=0;
		j=0;
		k=0;
		if(action == 1){
			//printf("step1\n");
			scanf("%s",&temp);
			for(i=0 ; i<count ; i++){
				if(strcmp (temp,NameData[i])==0){
					printf("Error\n");
					err=1;
					break;					
				}
			}
			if(err == 0){
				strcpy(NameData[count],temp);
				scanf("%d",&inputnum);
				while (inputnum != -1){
					NumData[count][j]=inputnum;
					j++;
					scanf("%d",&inputnum);
				}
				Datalen[count]=j;
				count++;
			}			
		}else if (action == 2){
			//printf("step2\n");
			scanf("%s",&temp);
			for(i=0 ; i<count ; i++){
				if(strcmp (temp,NameData[i])==0){
					break;
				}
			}
			if(i==count){
				printf("Error\n");
			}else{
				printf("%d bytes\n",Datalen[i]);
				//printf("i=%d\n",i);
				for(k=0 ; k<Datalen[i] ; k++){
				//	printf("%d\n",NumData[i][k]);
					decimal_to_binary(NumData[i][k],8);
				}
			}
		}else if (action == 3){
			//printf("step3\n");
			scanf("%s",&temp);
			for(i=0 ; i<count ; i++){
				if(strcmp (temp,NameData[i])==0){
					break;
				}
			}
			if(i==count){
				printf("Error\n");
			}else{
				scanf("%d",&fixplace);
				scanf("%d",&fixnum);
				NumData[i][fixplace-1]=fixnum;
			}
		
		}
	scanf("%d",&action);
	}
		
}

