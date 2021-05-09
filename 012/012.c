#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
typedef long clock_t;
int cut(char *s , char *p[]){
	int i=0;
	p[0]=strtok(s," ");
	while (p[i]!= NULL){
		i++;
		p[i]=strtok(NULL," ");

	}

	return i;
}
int cut2(char *s , char *p[]){
	int i=0;
	int j=0;
	p[0]=strtok(s," ");
	while (p[i]!= NULL){
		for(j=0 ; j<strlen(p[i]) ; j++){
			p[i][j]=tolower(p[i][j]);
		}
		i++;
		p[i]=strtok(NULL," ");

	}

}

void main(){
	clock_t t1, t2;

	int quantity=0,i=0,j=0,k=0;
	char standard[50];
	int extend=0;
	char direc;
	scanf("%s",standard);
	scanf("%d %c",&extend,&direc);
	int num1=0,num2=0,num3=0,num4=0,num5=0;
	char data1[200],data2[200],data3[200],data4[200],data5[200];
	char data11[200],data22[200],data33[200],data44[200],data55[200];
	char *p1[100],*p2[100],*p3[100],*p4[100],*p5[100];
	char *p11[100],*p22[100],*p33[100],*p44[100],*p55[100];
	char ans1[50][100];
	int stplace[100];
	int st=0;
	int compare[100];
	int cmp=0;
	int tmplace=0;
	for(i=0 ; i<50 ;i++){
		ans1[i][0]='\0';
	}
    t1 = clock();
	int leftstart=0,rightend=0;
	gets(data1);//dont know why it'll be skipped
	gets(data1);
	gets(data2);
	gets(data3);
	gets(data4);
	gets(data5);

	strcpy(data11,data1);
	strcpy(data22,data2);
	strcpy(data33,data3);
	strcpy(data44,data4);
	strcpy(data55,data5);
	num1=cut(data1,p1);
	num2=cut(data2,p2);
	num3=cut(data3,p3);
	num4=cut(data4,p4);
	num5=cut(data5,p5);
	cut2(data11,p11);
	cut2(data22,p22);
	cut2(data33,p33);
	cut2(data44,p44);
	cut2(data55,p55);


	//printf("%s %d %c\n",standard,extend,direc);
	//第一個句子判斷
	k=0;
	for(i=0 ; i<strlen(standard) ; i++){
		standard[i]=tolower(standard[i]);
	}
	if(p1[0]!="0"){
		for(i=0 ; i<num1 ; i++){
		//printf("(1)%s %s\n",p1[i],standard);
		if(strcmp(p11[i],standard)==0){
			for(j=0 ; j<strlen(p1[i]) ; j++){
				p1[i][j]=toupper(p1[i][j]);
			}
			if((i-extend)<0){
				leftstart=0;
				tmplace=i;
			}else{
				leftstart=i-extend;
				tmplace=extend;
			}
			if((i+extend)>=num1){
				rightend=num1-1;
			}else{
				rightend=i+extend;
			}
			//printf("left=%d right=%d\n",leftstart,rightend);
			for(j=leftstart ; j<=rightend ; j++){
				strcat(ans1[quantity],p1[j]);
				strcat(ans1[quantity]," ");
			}
			for(j=leftstart ; j<leftstart+tmplace ; j++){
			//	printf("%s %d \n",p1[j],strlen(p1[j]));
				cmp++;
				k+=strlen(p1[j]);
			}
			//printf("**************\n");
			stplace[st]=k;
			compare[st]=k+cmp;
			cmp=0;
			quantity++;
			st++;
			k=0;
		}
		leftstart=0;
		rightend=0;
	}

	}
 //第二個句子判斷
 //	printf("no2\n");
 	if(p2[0]!="0"){
		for(i=0 ; i<num2 ; i++){
	//	printf("%s %s\n",p2[i],standard);
		if(strcmp(p22[i],standard)==0){
			for(j=0 ; j<strlen(p2[i]) ; j++){
				p2[i][j]=toupper(p2[i][j]);
			}
			if((i-extend)<0){
				leftstart=0;
				tmplace=i;
			}else{
				leftstart=i-extend;
				tmplace=extend;
			}
			if((i+extend)>=num2){
				rightend=num2-1;
			}else{
				rightend=i+extend;
			}
			//printf("left=%d right=%d\n",leftstart,rightend);
			for(j=leftstart ; j<=rightend ; j++){
				strcat(ans1[quantity],p2[j]);
				strcat(ans1[quantity]," ");
			}
			for(j=leftstart ; j<leftstart+tmplace ; j++){
			//	printf("%s %d \n",p1[j],strlen(p1[j]));
				k+=strlen(p2[j]);
				cmp++;
			}
			//printf("**************\n");
			stplace[st]=k;
			compare[st]=k+cmp;
			quantity++;
			cmp=0;
			st++;
			k=0;
		}
		leftstart=0;
		rightend=0;
	}

	}
	//printf("no3\n");
 	if(p3[0]!="0"){
		for(i=0 ; i<num3 ; i++){
	//	printf("%s %s\n",p3[i],standard);
		if(strcmp(p33[i],standard)==0){
			for(j=0 ; j<strlen(p3[i]) ; j++){
				p3[i][j]=toupper(p3[i][j]);
			}
			if((i-extend)<0){
				leftstart=0;
				tmplace=i;
			}else{
				leftstart=i-extend;
				tmplace=extend;
			}
			if((i+extend)>=num3){
				rightend=num3-1;
			}else{
				rightend=i+extend;
			}

		//	printf("left=%d right=%d\n",leftstart,rightend);
			for(j=leftstart ; j<=rightend ; j++){
				strcat(ans1[quantity],p3[j]);
				strcat(ans1[quantity]," ");
			}
			for(j=leftstart ; j<leftstart+tmplace ; j++){
			//	printf("%s %d \n",p1[j],strlen(p1[j]));
				k+=strlen(p3[j]);
				cmp++;
			}
			//printf("**************\n");
			compare[st]=k+cmp;
			stplace[st]=k;
			quantity++;
			cmp=0;
			st++;
			k=0;

		}
		leftstart=0;
		rightend=0;
	}

	}
 	if(p4[0]!="0"){
		for(i=0 ; i<num4 ; i++){
	//	printf("%s %s\n",p4[i],standard);
		if(strcmp(p44[i],standard)==0){
			for(j=0 ; j<strlen(p4[i]) ; j++){
				p4[i][j]=toupper(p4[i][j]);
			}
			if((i-extend)<0){
				leftstart=0;
				tmplace=i;
			}else{
				leftstart=i-extend;
				tmplace=extend;
			}
			if((i+extend)>=num4){
				rightend=num4-1;
			}else{
				rightend=i+extend;
			}
		//	printf("left=%d right=%d\n",leftstart,rightend);
			for(j=leftstart ; j<=rightend ; j++){
				strcat(ans1[quantity],p4[j]);
				strcat(ans1[quantity]," ");
			}
			for(j=leftstart ; j<leftstart+tmplace ; j++){
			//	printf("%s %d \n",p1[j],strlen(p1[j]));
				k+=strlen(p4[j]);
				cmp++;
			}
			//printf("**************\n");
			stplace[st]=k;
			compare[st]=k+cmp;
			cmp=0;
			quantity++;
			st++;
			k=0;

		}
		leftstart=0;
		rightend=0;
	}

	}
 	if(p5[0]!="0"){
		for(i=0 ; i<num5 ; i++){
	///	printf("%s %s\n",p5[i],standard);
		if(strcmp(p55[i],standard)==0){
			for(j=0 ; j<strlen(p5[i]) ; j++){
				p5[i][j]=toupper(p5[i][j]);
			}
			if((i-extend)<0){
				leftstart=0;
				tmplace=i;
			}else{
				leftstart=i-extend;
				tmplace=extend;
			}
			if((i+extend)>=num5){
				rightend=num5-1;
			}else{
				rightend=i+extend;
			}
		//	printf("left=%d right=%d\n",leftstart,rightend);
			for(j=leftstart ; j<=rightend ; j++){
				strcat(ans1[quantity],p5[j]);
				strcat(ans1[quantity]," ");
			}
			for(j=leftstart ; j<leftstart+tmplace ; j++){
			//	printf("%s %d \n",p1[j],strlen(p1[j]));
				k+=strlen(p5[j]);
				cmp++;
			}
			//printf("**************\n");
			stplace[st]=k;
			compare[st]=k+cmp;
			cmp=0;
			quantity++;
			st++;
			k=0;

		}
		leftstart=0;
		rightend=0;
	}

	}
	// ans1為分割好的字串  接著處裡排序
//	printf("%d",quantity);


	int len=0;
	len=strlen(standard);
	for(i=0 ; i<len ; i++){
		standard[i]=toupper(standard[i]);
	}
 	int cm1=0,cm2=0,cm=0;
 	int lon1=0 , lon2=0;
 	char ttp[1000];
	int temp1=0,temp2=0;

	for(i=0 ; i<quantity-1 ; i++){
		for(j=i+1 ; j<quantity ; j++){
		//	printf("i=%d  j=%d\n",i,j);
		//	printf("(1)%s  |   %s\n",ans1[i],ans1[j]);
			if(direc == 'L'){
				cm1=compare[i]-2;
				cm2=compare[j]-2;
				//printf("lon1=%d lon2=%d\n",stplace[i],stplace[j]);
				if(cm1>cm2){
					cm=cm1;
				}else{
					cm=cm2;
				}
			 	if(stplace[i]>stplace[j]){
					strcpy(ttp,ans1[j]);
					strcpy(ans1[j],ans1[i]);
					strcpy(ans1[i],ttp);
					temp1=compare[j];
					compare[j]=compare[i];
					compare[i]=temp1;
					temp2=stplace[j];
					stplace[j]=stplace[i];
					stplace[i]=temp2;

				}else if(stplace[i]==stplace[j]){
					for(k=0 ; k<=cm ; k++){
						//printf("比對字元%c %c %d\n",ans1[i][cm1-k],ans1[j][cm2-k],ans1[i][cm1-k]-ans1[j][cm2-k]);
						if((ans1[i][cm1-k]-ans1[j][cm2-k] > 0) && ans1[i][cm1-k]!=' '&&ans1[j][cm2-k]!= ' '){
							//printf("比對成功 \n");
							strcpy(ttp,ans1[j]);
							strcpy(ans1[j],ans1[i]);
							strcpy(ans1[i],ttp);
							temp1=compare[j];
							compare[j]=compare[i];
							compare[i]=temp1;
							temp2=stplace[j];
							stplace[j]=stplace[i];
							stplace[i]=temp2;
							break;
						}else if ((ans1[i][cm1-k]-ans1[j][cm2-k] < 0) && ans1[i][cm1-k]!=' '&&ans1[j][cm2-k]!= ' '){
							break;
						}
					}

				}

		//	printf("(2)%s   |    %s\n",ans1[i],ans1[j]);
			}else{
				cm1=compare[i]+len+1;
				cm2=compare[j]+len+1;
				//printf("lon1=%d lon2=%d\n",stplace[i],stplace[j]);
				if(strlen(ans1[i])-cm1>strlen(ans1[j])-cm2){
					cm=cm1;
				}else{
					cm=cm2;
				}
			//	printf("test  R  %d  %d\n",cm1,cm2);
			 	if(strlen(ans1[i])-stplace[i]>strlen(ans1[j])-stplace[j]){
					strcpy(ttp,ans1[j]);
					strcpy(ans1[j],ans1[i]);
					strcpy(ans1[i],ttp);
					temp1=compare[j];
					compare[j]=compare[i];
					compare[i]=temp1;
					temp2=stplace[j];
					stplace[j]=stplace[i];
					stplace[i]=temp2;

				}

				else if(strlen(ans1[i])-stplace[i]==strlen(ans1[j])-stplace[j]){
					for(k=0 ; k<=cm ; k++){
						//printf("比對字元%c %c %d\n",ans1[i][cm1-k],ans1[j][cm2-k],ans1[i][cm1-k]-ans1[j][cm2-k]);
						if((ans1[i][cm1+k]-ans1[j][cm2+k] > 0) && ans1[i][cm1+k]!=' '&&ans1[j][cm2+k]!= ' '){
							//printf("比對成功 \n");
							strcpy(ttp,ans1[j]);
							strcpy(ans1[j],ans1[i]);
							strcpy(ans1[i],ttp);
							temp1=compare[j];
							compare[j]=compare[i];
							compare[i]=temp1;
							temp2=stplace[j];
							stplace[j]=stplace[i];
							stplace[i]=temp2;
							break;
						}else if ((ans1[i][cm1+k]-ans1[j][cm2+k] < 0) && ans1[i][cm1+k]!=' '&&ans1[j][cm2+k]!= ' '){
							break;
						}
					}

				}
			}
			cm=0;
			cm1=0;
			cm2=0;

		}
	}


	for(i=0 ; i<quantity ; i++){
		//printf("%s",ans1[i]);
		//printf("info %d  %d",compare[i],strlen(ans1[i])-2);
		for(j=0 ; j<compare[i]; j++){
			printf("%c",tolower(ans1[i][j]));
		}
		for(j=compare[i] ; j<compare[i]+len ; j++){
			printf("%c",ans1[i][j]);
		}
		for(j=compare[i]+len ; j<strlen(ans1[i])-1 ; j++){
			printf("%c",tolower(ans1[i][j]));
		}
		printf("\n");

	}
	t2 = clock();
    printf("%f seconds ", (float)(t2-t1)/CLOCKS_PER_SEC);
    printf(" (measurement granularity: %d of a second)\n", CLOCKS_PER_SEC);

}




