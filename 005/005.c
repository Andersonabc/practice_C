#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main(){
	int people=0,i=0,j=0,k=0,s=0,err=0,temp=0,total=0,st=0,tt=0;
	float a=0.0;
	scanf("%d",&people);
	int classes[people];
	int rank[people];
	int id[people];
	char name[people][10];
	char course[100][100];
	int credits[people][100];
	int score[people][100];
	int find[50];
	int start[people];
	for (i=0;i<people;i++){
		scanf("%d %s",&id[i],&name[i]);
		scanf("%d",&classes[i]);
		start[i]=st;
		rank[i]=i;
		st+=classes[i];
		//printf("%d %s %d\n",id[i],name[i],classes[i]);
		for(j=0;j<classes[i];j++){			
			scanf("%s %d %d",&course[total],&credits[i][j],&score[i][j]);
			total++;
			//printf("%s %d %d\n",&course[i][j],credits[i][j],score[i][j]);
		}
	}
	float rankscore[50];
	for (i=0 ; i<people ; i++){
		for (j=0 ; j<classes[i] ; j++){
			temp+=(credits[i][j]*score[i][j]);
			s+=credits[i][j];
		}
		rankscore[i]=((float)temp/(float)s);
		temp=0,s=0;
	
	}
	for(i=0 ; i<people ; i++){
		for(j=0 ; j<people ; j++){	
			if (rankscore[i]>rankscore[j]){
			a=rankscore[i];
			rankscore[i]=rankscore[j];
			rankscore[j]=(float)a;
			temp=rank[i];
			rank[i]=rank[j];
			rank[j]=temp;
						
		}
	}
}

	

	j=0;
	scanf("%d",&temp);
	while (temp != 0){
		find[j]=temp;
		j++;
		scanf("%d",&temp);
	}
	//printf("%d",j);
	int allcrdd=0,crdd=0,ave=0;
	float ans=0;
	for (i=0 ; i<j ; i++){
		for(k=0 ; k<people ; k++){
			if(find[i] == id[k]){
				st=start[k];
				printf("%d %s\n",id[k],name[k]);
				for (s=0 ; s<classes[k] ; s++){
					printf("%s %d %d\n",course[st+s],credits[k][s],score[k][s]);
					allcrdd+=credits[k][s];
					if(score[k][s]>=60){
						crdd+=credits[k][s];
					}
					ave+=(score[k][s]*credits[k][s]);
				}
				ans=(float)ave/(float)allcrdd;
				printf("%d\n",crdd);
				printf("%.2f\n",ans);		
				err+=1;
				//printf("%s",&course[k][0]);
			for (tt=0 ;tt<people;tt++){
				if(rank[tt]==k){
					printf("%d\n",(tt+1));
				}
			}
			}
			
		}
		ave=0,allcrdd=0,crdd=0,ans=0.0;
		if(err==0){
			printf("ERROR\n");
		}
		err=0;
	}
}
