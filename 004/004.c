#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main(){
	int times=0,i=0,j=0,temp=0,x=0,y=0;
	scanf("%d",&times);
	int sc1[times];
	int sc2[times];
	int sc3[times];
	char data[times][10];
	char name[4];
	int id[times];
	int alt[times];
	for (i=0;i<times;i++){
		scanf("%d %s %d %d %d",&id[i],&data[i],&sc1[i],&sc2[i],&sc3[i]);
		alt[i]=i;
	//	printf("%d %s %d %d %d %d\n",id[i],data[i],sc1[i],sc2[i],sc3[i],alt[i]);
	}
	
	float ave1=0,ave2=0,ave3=0,toave=0,Median=0,Variance=0,Deviation=0,upper=0,lower=0;
	int total[times];
	for (i=0 ; i<times ; i++){
		total[i]=sc1[i]+sc2[i]+sc3[i];
		ave1+=sc1[i];
		ave2+=sc2[i];
		ave3+=sc3[i];
		toave+=(sc1[i]+sc2[i]+sc3[i]);
	}
	ave1=(float)ave1/times;
	ave2=(float)ave2/times;
	ave3=(float)ave3/times;
	toave=(float)toave/times;
	for(i=0 ; i<times ; i++){
		for(j=0 ; j<times ; j++){
			if (total[i]>total[j]){
				temp=total[i];
				total[i]=total[j];
				total[j]=temp;
				temp=sc1[i];
				sc1[i]=sc1[j];
				sc1[j]=temp;
				temp=sc2[i];
				sc2[i]=sc2[j];
				sc2[j]=temp;
				temp=sc3[i];
				sc3[i]=sc3[j];
				sc3[j]=temp;
				temp=id[i];
				id[i]=id[j];
				id[j]=temp;		
				temp=alt[i];
				alt[i]=alt[j];
				alt[j]=temp;							
			}
		}
	}
	if ((times%2)==0){
		Median=((float)total[times/2-1]+(float)total[times/2])/2;
	}else {
		Median=(float)total[times/2];
	}
	
	for(i=0 ; i<times ; i++){
		Variance+=((float)total[i]-(float)toave)*((float)total[i]-(float)toave);	
}
	Variance=(float)Variance/times;
//	printf("%.2f\n",Variance);
	Deviation=sqrt(Variance);
	
	for(i=0 ; i<times ; i++){
		if (total[i]<Median){
			lower+=(float)total[i];
			x++;
		}else if (total[i]>Median){
			upper+=(float)total[i];
			y++;
		}
	}
	if(lower!=0){
		lower/=(float)x;
	}
	if(upper!=0){
		upper/=(float)y;
	}

	
	
	for (i=0 ; i<times ; i++){
		temp=alt[i];
		printf("%d %s %d %d %d %d %d\n",id[i],data[temp],sc1[i],sc2[i],sc3[i],total[i],(i+1));		
	}
	printf("%.2f\n",ave1);
	printf("%.2f\n",ave2);
	printf("%.2f\n",ave3);
	printf("%.2f\n",toave);
	printf("%.2f\n",Median);
	printf("%.2f\n",Variance);
	printf("%.2f\n",Deviation);
	printf("%.2f\n",upper);
	printf("%.2f",lower);
	
	
	
}
