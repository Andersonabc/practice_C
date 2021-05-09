#include <stdio.h>
#include <string.h>
int cut(char *s , char *p[]){
	int i=0;
	p[0]=strtok(s," ");
	while (p[i]!= NULL){
		i++;
		p[i]=strtok(NULL," ");
		//printf("%s\n",p[i]);
	}
	return i;
}

void main(){
	int i=0,j=0,z=0,no=0,a=0;
	int count=0;
	char data[100];
	char *x[20];
	int nob[20];
	char *ans[20];
	gets(data);
	i=cut(data,x);
	for(j=0 ; j<i ;j++){
		for(z=0;z<strlen(x[j]);z++){
			x[j][z]=tolower(x[j][z]);
		}	
	}
	ans[0]=x[0];
	nob[0]=1;
	for(j=1 ; j<i ;j++){
		for(z=0 ; z<=a ; z++){
			if(strcmp(ans[z],x[j])!=0){
				count++;
			}else{
				nob[z]++;
				break;
			}
		}
		if(count == a+1){
			a++;
			ans[a]=x[j];
			nob[a]=1;
		}
		count=0;
	}
	for (j=0 ; j<=a ; j++){
		printf("%s %d\n",ans[j],nob[j]);
	}
	
	//Hi Siri hello siRi world hellO 
} 
