#include <stdio.h>
#include <string.h>
typedef struct fille{ 
	char name[100]; 
	char c[1000];
	//int lon;	
} file;
void output(file saver[100],int to){
	int i=0,j=0;
	for(i=0 ; i<strlen(saver[to].c) ; i++){
		if(saver[to].c[i] == '#') printf("\n");
		else printf("%c",saver[to].c[i]);
	}
	return;
}
void output2(file saver[100],int to,int pri){
	int i=0,j=0;
	for(i=0 ; i<strlen(saver[to].c) ; i++){
		if(saver[to].c[i] == '#') {
			printf("\n");
			j++;
			if (j == pri) return ;
		}else printf("%c",saver[to].c[i]);
	}
}
void output3(file saver[100],int to,int pri){
	//printf("%s\n",saver[to].c);
	char data[100][100];
	char tmp[100];
	int i=0,j=0,k=0,cnt=0,z=0;
	for(i=strlen(saver[to].c)-2 ; i>=0; i--){	
		//printf("%c",saver[to].c[i]);	
		if(saver[to].c[i] != '#') j++;
		else{
			z=0;
			for(k=1 ; k<=j ; k++){
				tmp[z]=saver[to].c[i+k];
				z++;
			}
			//printf("tmp=%s\n",tmp);
			strcpy(data[cnt],tmp);
			strcpy(tmp,"                                          ");
			j=0;
			cnt++;
			if(cnt == pri)  break;
		}
	}
	if((cnt < pri) && (strlen(saver[to].c)) != 0){
		//printf("d dsdsdad");
		for(i=0 ; i<strlen(saver[to].c); i++){
			if(saver[to].c[i] != '#')tmp[i]=saver[to].c[i];
			else break;
		}
		//printf("tttcmp=%s\n",tmp);
		strcpy(data[cnt],tmp);
		cnt++;
	}
	for(i=cnt-1 ; i>=0 ; i--){
		printf("%s\n",data[i]);
	}
	return;
}
int locate(file saver[100],char a[100] ,int to){
	int i=0;
	for(i=0 ; i<to ;i++){
		if(strcmp(saver[i].name,a) == 0) return i;	
	}
}
int cut(char *s , char *p[]){
	int i=0;
	p[0]=strtok(s," ");
	while (p[i]!= NULL){
		i++;
		p[i]=strtok(NULL," ");

	}

	return i;
}

void main (){
	int length=0;
	char input[200];
	gets(input);
	char *onprocess[100];
	length=cut(input,onprocess);
	file saver[100];
	int total=0;

	while (1){
		int x=0;
		int location=0;
		char temp[100];
		char tmp;
		char inform[1000];
		for(x=0 ; x<1000 ; x++){
			inform[x]=' ';
		}
		for(x=0 ; x<100 ; x++){
			temp[x]=' ';
		}
		
		if(strcmp(onprocess[0],"exit") == 0) break;
		else if(strcmp(onprocess[0],"touch") == 0 ){
			char ttp[100];
			int i=0,j=0,k=0;
			for (i=1 ; i<length ; i++){
				strcpy(saver[total].name,onprocess[i]);
				total++;
			}
			for(i=0 ; i<total-1 ; i++){
				for(j=i+1 ; j<total ; j++){
					if(strcmp(saver[i].name,saver[j].name)>0){
						strcpy(ttp,saver[i].name);
						strcpy(saver[i].name,saver[j].name);
						strcpy(saver[j].name,ttp);
					}
				}
			}			
			//printf("!!!touch\n");
		}else if(strcmp(onprocess[0],"vim") == 0 ){
			int i=0,j=0,k=0;
			strcpy(inform,"");
			int check=0;
			//printf("!!!vim\n");
			location=locate(saver,onprocess[1],total);
			//printf("%d\n",location);
			scanf("%c",&tmp);
			while (1){
				scanf("%s%c",temp,&tmp);
				//printf("%s\n",temp);
				if(strcmp(temp,":w") == 0) {
					strcpy(saver[location].c,inform);
					check=1;
				}
				else if(strcmp(temp,":q") == 0){
					if (check == 0)printf("error\n");					
					break;
				}else if (strcmp(temp,":wq") == 0){
					strcpy(saver[location].c,inform);
					break;
				}else if (strcmp(temp,":q!") == 0) break;
				else{ 
					strcat(inform,temp);
					if(tmp == '\n') strcat(inform,"#");//printf("传︽la\n");
					//printf("%s",inform);					
				}

			}
						
		}else if(strcmp(onprocess[0],"cat") == 0 ){
			int i=0,j=0,k=0;
			int location;
			char prin[100][100];
			j=0;
			int z=0;
			k=0;
			int count=0;
			//printf("cat!!\n");
			char now[100];
			if(onprocess[1][0]=='*'){
				z=0;
				for(i=1 ; i<strlen(onprocess[1]) ; i++){
					now[j]=onprocess[1][i];
					j++;
				}
				now[j]='\0';
				for(i=0 ; i<total ;i++){
					for(k=strlen(now)-1 ; k>=0 ; k--){
						if(saver[i].name[strlen(saver[i].name)-1-z] == now[k]) z++;
					}
					if(z == strlen(now)){
						strcpy(prin[count],saver[i].name);
						count++;
					}					
				}				
			}
			else if(onprocess[1][strlen(onprocess[1])-1]=='*'){
				//printf("erewrewrewr\n");
				for(i=0 ; i<strlen(onprocess[1])-1 ; i++){
					now[j]=onprocess[1][i];
					j++;
				}
				//printf("%s",now);
				now[j]='\0';
				for(i=0 ; i<total ;i++){
					z=0;
					for(k=0 ; k<strlen(now) ; k++){
						if(saver[i].name[k] == now[k]) z++;
						
					}
					//printf("%d\n",z);
					if(z == strlen(now)){
						strcpy(prin[count],saver[i].name);
						count++;
					}					
				}				
			}else{
				strcpy(now,onprocess[1]);
				for(i=0 ; i<total ;i++){
					z=0;
					for(k=0 ; k<strlen(now) ; k++){
						if(saver[i].name[k] == now[k]) z++;
						
					}
					//printf("%d\n",z);
					if(z == strlen(now) && strlen(now) ==strlen(saver[i].name) ){
						strcpy(prin[count],saver[i].name);
						count++;
					}					
				}				
			}			
						
			char ttp[100];
			for(i=0 ; i<count-1 ; i++){
				for(j=i+1 ; j<count ; j++){
					if(strcmp(prin[i],prin[j])>0){
						strcpy(ttp,prin[i]);
						strcpy(prin[i],prin[j]);
						strcpy(prin[j],ttp);
					}
				}
			}
			//printf("%s",prin[0]);
			for (i=0 ; i<count ; i++)
			{
				//printf("i=%d\n",i);
				location=locate(saver,prin[i],total);
				//printf("%d\n",location);
				output(saver,location);
				
			}
			
			
			
			
		}else if (strcmp(onprocess[0],"head") == 0 ){
			int i=0,j=0,k=0;
			int location;
			char prin[100][100];
			j=0;
			int z=0;
			k=0;
			int count=0;
			//printf("head!!\n");
			char now[100];
			int prinnum=10;
			if(strcmp(onprocess[1],"-n") == 0) {
				prinnum=atoi(onprocess[2]);
				if(onprocess[3][0] == '*'){
					z=0;
					for(i=1 ; i<strlen(onprocess[3]) ; i++){
						now[j]=onprocess[3][i];
						j++;
					}
					now[j]='\0';
					for(i=0 ; i<total ;i++){
						for(k=strlen(now)-1 ; k>=0 ; k--){
							if(saver[i].name[strlen(saver[i].name)-1-z] == now[k]) z++;
						}
						if(z == strlen(now)){
							strcpy(prin[count],saver[i].name);
							count++;
						}					
					}				
				}
				else if (onprocess[3][strlen(onprocess[3])-1] == '*'){  //临⊿代 
					for(i=0 ; i<strlen(onprocess[3])-1 ; i++){
						now[j]=onprocess[3][i];
						j++;
					}
					//printf("%s",now);
					now[j]='\0';
					for(i=0 ; i<total ;i++){
						z=0;
						for(k=0 ; k<strlen(now) ; k++){
							if(saver[i].name[k] == now[k]) z++;
							
						}
						//printf("%d\n",z);
						if(z == strlen(now)){
							strcpy(prin[count],saver[i].name);
							count++;
						}					
					}				
				}else{
					strcpy(now,onprocess[3]);
					for(i=0 ; i<total ;i++){
						z=0;
						for(k=0 ; k<strlen(now) ; k++){
							if(saver[i].name[k] == now[k]) z++;
							
						}
						
						//printf("%d    %d\n",strlen(now),strlen(saver[i].name));
						if(z == strlen(now)&& strlen(now) ==strlen(saver[i].name)){
							strcpy(prin[count],saver[i].name);
							count++;
						}					
					}				
				}				
			}
			else {
				prinnum=10;
				if(onprocess[1][0] == '*'){
					z=0;
					for(i=1 ; i<strlen(onprocess[1]) ; i++){
						now[j]=onprocess[1][i];
						j++;
					}
					now[j]='\0';
					for(i=0 ; i<total ;i++){
						for(k=strlen(now)-1 ; k>=0 ; k--){
							if(saver[i].name[strlen(saver[i].name)-1-z] == now[k]) z++;
						}
						if(z == strlen(now)){
							strcpy(prin[count],saver[i].name);
							count++;
						}					
					}				
				}
				else if (onprocess[1][strlen(onprocess[1])-1] == '*'){  //临⊿代 
					for(i=0 ; i<strlen(onprocess[1])-1 ; i++){
						now[j]=onprocess[1][i];
						j++;
					}
					//printf("%s",now);
					now[j]='\0';
					for(i=0 ; i<total ;i++){
						z=0;
						for(k=0 ; k<strlen(now) ; k++){
							if(saver[i].name[k] == now[k]) z++;
							
						}
						//printf("%d\n",z);
						if(z == strlen(now)){
							strcpy(prin[count],saver[i].name);
							count++;
						}					
					}				
				}else{
					strcpy(now,onprocess[1]);
					for(i=0 ; i<total ;i++){
						z=0;
						for(k=0 ; k<strlen(now) ; k++){
							if(saver[i].name[k] == now[k]) z++;
							
						}
						
						//printf("%d    %d\n",strlen(now),strlen(saver[i].name));
						if(z == strlen(now)&& strlen(now) ==strlen(saver[i].name)){
							strcpy(prin[count],saver[i].name);
							count++;
						}					
					}				
				}				
			}

			char ttp[100];
			for(i=0 ; i<count-1 ; i++){
				for(j=i+1 ; j<count ; j++){
					if(strcmp(prin[i],prin[j])>0){
						strcpy(ttp,prin[i]);
						strcpy(prin[i],prin[j]);
						strcpy(prin[j],ttp);
					}
				}
			}			
			for (i=0 ; i<count ; i++){
				location=locate(saver,prin[i],total);
				output2(saver,location,prinnum);
			}
			
			
		}else if(strcmp(onprocess[0],"tail") == 0 ){
			int i=0,j=0,k=0;
			int location;
			char prin[100][100];
			j=0;
			int z=0;
			k=0;
			int count=0;
			//printf("tail!!\n");
			char now[100];
			int prinnum=10;
			if(strcmp(onprocess[1],"-n") == 0){
				prinnum=atoi(onprocess[2]);
				if(onprocess[3][0] == '*'){
					z=0;
					for(i=1 ; i<strlen(onprocess[3]) ; i++){
						now[j]=onprocess[3][i];
						j++;
					}
					now[j]='\0';
					for(i=0 ; i<total ;i++){
						for(k=strlen(now)-1 ; k>=0 ; k--){
							if(saver[i].name[strlen(saver[i].name)-1-z] == now[k]) z++;
						}
						if(z == strlen(now)){
							strcpy(prin[count],saver[i].name);
							count++;
						}					
					}
					//printf("count=%d\n",count);				
				}
				else if (onprocess[3][strlen(onprocess[3])-1] == '*'){  //临⊿代 
					for(i=0 ; i<strlen(onprocess[3])-1 ; i++){
						now[j]=onprocess[3][i];
						j++;
					}
					//printf("%s",now);
					now[j]='\0';
					for(i=0 ; i<total ;i++){
						z=0;
						for(k=0 ; k<strlen(now) ; k++){
							if(saver[i].name[k] == now[k]) z++;
							
						}
						//printf("%d\n",z);
						if(z == strlen(now)){
							strcpy(prin[count],saver[i].name);
							count++;
						}					
					}				
				}else{
					strcpy(now,onprocess[3]);
					for(i=0 ; i<total ;i++){
						z=0;
						for(k=0 ; k<strlen(now) ; k++){
							if(saver[i].name[k] == now[k]) z++;
							
						}
						//printf("%d\n",z);
						if(z == strlen(now)&& strlen(now) ==strlen(saver[i].name)){
							strcpy(prin[count],saver[i].name);
							count++;
						}					
					}				
				}				
			} else{
				prinnum=10;
				if(onprocess[1][0] == '*'){
					z=0;
					for(i=1 ; i<strlen(onprocess[1]) ; i++){
						now[j]=onprocess[1][i];
						j++;
					}
					now[j]='\0';
					for(i=0 ; i<total ;i++){
						for(k=strlen(now)-1 ; k>=0 ; k--){
							if(saver[i].name[strlen(saver[i].name)-1-z] == now[k]) z++;
						}
						if(z == strlen(now)){
							strcpy(prin[count],saver[i].name);
							count++;
						}					
					}				
				}
				else if (onprocess[1][strlen(onprocess[1])-1] == '*'){  //临⊿代 
					for(i=0 ; i<strlen(onprocess[1])-1 ; i++){
						now[j]=onprocess[1][i];
						j++;
					}
					//printf("%s",now);
					now[j]='\0';
					for(i=0 ; i<total ;i++){
						z=0;
						for(k=0 ; k<strlen(now) ; k++){
							if(saver[i].name[k] == now[k]) z++;
							
						}
						//printf("%d\n",z);
						if(z == strlen(now)){
							strcpy(prin[count],saver[i].name);
							count++;
						}					
					}				
				}else{
					strcpy(now,onprocess[1]);
					for(i=0 ; i<total ;i++){
						z=0;
						for(k=0 ; k<strlen(now) ; k++){
							if(saver[i].name[k] == now[k]) z++;
							
						}
						
						//printf("%d    %d\n",strlen(now),strlen(saver[i].name));
						if(z == strlen(now)&& strlen(now) ==strlen(saver[i].name)){
							strcpy(prin[count],saver[i].name);
							count++;
						}					
					}				
				}								
			}

			char ttp[100];
			for(i=0 ; i<count-1 ; i++){
				for(j=i+1 ; j<count ; j++){
					if(strcmp(prin[i],prin[j])>0){
						strcpy(ttp,prin[i]);
						strcpy(prin[i],prin[j]);
						strcpy(prin[j],ttp);
					}
				}
			}			
			for (i=0 ; i<count ; i++){
				//printf("prin=%s\n",prin[i]);
				location=locate(saver,prin[i],total);
				//printf("%s\n",saver[location].c);
				
				output3(saver,location,prinnum);
			}	
			
					
		} else if(strcmp(onprocess[0],"rm") == 0 ){
			int i=0,j=0,k=0;
			int location=0;
			for(i=1 ; i<length ;i++){
				location=locate(saver,onprocess[i],total);
				strcpy(saver[location].name,"deleted");
			}
			
		} else if(strcmp(onprocess[0],"ls") == 0 ){
			int i=0,j=0,k=0;
			for(i=0 ; i<total ;i++){
				if(strcmp(saver[i].name,"deleted") != 0){
					printf("%s ",saver[i].name);
				}
			}
			printf("\n");
		}
		
		
		fflush(stdin);
		gets(input);
		length=cut(input,onprocess);
	}
	

	
}

/*
touch file2 file1 file3 afile cdfile file5
vim file1
a
123
456
789
:wq
vim cdfile
a
1564
ewqewq5e61qw
156d1qw6q5
d1wq561dqw
2dwq+62dwq
:wq
vim afile
a
1
2
55
:w
:q 
vim file3
a
ewqewq
ewqewqe
wqewqe
wqewqe
wqe
wqe
qwe
wqe
wqe
wqe
wq
sa
rf
:wq
tail -n 2 file*
tail -n 2 *file
*/
	/*if(cnt < pri){
		z=0;
		for(i=0 ; i<strlen(saver[to].c); i++){
			if(saver[to].c[i] != '#')z++;
			else break;
		}
		for(i=0 ; i<z ;i++){
			tmp[i]=saver[to].c[i];
		}
		strcpy(data[cnt],tmp);
		cnt++;
	}*/

