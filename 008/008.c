#include <stdio.h>
#include <string.h>
void swa (char str[100][100] , int count ){
	char temp[100];
	int i,j;
	for(i=0; i<count ; i++){
		for ( j = i + 1 ; j < count ; j++  ) //i + 1
          { 
          	printf("%d %d \n",i,j);
              if ( strcmp ( str [ i ] , str [ j ] ) > 0 ) 
              { 
                  strcpy ( temp , str [ i ] ) ; strcpy ( str [ i ] , str [ j ] ) ; strcpy ( str [ j ] , temp ) ; } 
          } 	
	}

}

void main(){
	int count=0,i=0,j=0,z=0,len=0,a=0;
	char data[100][100];
	char comp[100];
	char t[100];
	scanf("%s",comp);
	scanf("%s",data[0]);
	while (data[count][0]!='-' && data[count][1]!='1'){
		count++;
		scanf("%s",data[count]);
	}

	len=strlen(comp);
	for(i=0 ; i<count ; i++){
		for(j=0 ; j<strlen(data[i]) ; j++){
			if(data[i][j]==comp[0]){
				for(z=0 ; z<len ; z++){
					if(data[i][j+z]==comp[z]){
						a++;
					}					
				}
				//printf("same %d\n",a);
			}
			if(a==len){
				for(z=j ; z<strlen(data[i])-len  ; z++){										
					data[i][z]=data[i][z+len];					
				}	
				data[i][strlen(data[i])-len]='\0';
			}
			a=0;
		}		
	}
	swa(data,count);

	for(i=0 ; i<count ;i++){
		printf("%s\n",data[i]);
	}
	
}

