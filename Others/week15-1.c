#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void plus(int mom1, int mom2, int son1, int son2, int *plson, int *plmom){
	int ansm, anss =0;
	ansm=mom1*mom2;
	anss=(mom1*son2)+(mom2*son1);
	*plson=anss;
	*plmom=ansm;
	//printf("%d",ansm);
} 

void product(int mom1, int mom2, int son1, int son2, int *proson, int *promom){
	int ansm, anss =0;
	ansm=mom1*mom2;
	anss=son1*son2;
	*proson=anss;
	*promom=ansm;
}

void output1(int mom1, int mom2, int son1, int son2, int plson, int plmom){
	float a=0.0;
	int i=0;
	a=((float)son1/(float)mom1+(float)son2/(float)mom2);	
	for (i=2 ; i<=plson ; i++){
		if (plson%i==0 && plmom%i==0){
			plson=plson/i;
			plmom=plmom/i;
		}
	}
	for (i=2 ; i<=plmom ; i++){
		if (plson%i==0 && plmom%i==0){
			plson=plson/i;
			plmom=plmom/i;
		}
	}		
	plson=abs(plson);
	plmom=abs(plmom);
//	printf("%d\n",plson);
//	printf("%d\n",plmom);
	if ((son1==0 || son2==0 || mom1==0 || mom2==0)){
		printf("ERROR");
	}else if(plson >= plmom && a<0.0){
		if (plson%plmom!=0){
			printf("-%d(%d/%d)",(plson/plmom),(plson%plmom),plmom);
		}else{
			printf("-%d",(plson/plmom));
		}	
	}else if(plson >= plmom && a>0.0){
		if (plson%plmom!=0){
			printf("%d(%d/%d)",(plson/plmom),(plson%plmom),plmom);
		}else{
			printf("%d",(plson/plmom));
		}	
	}else if(plson < plmom && a<0.0){
		printf("-%d/%d",plson,plmom);
	}else if(plson < plmom && a>0.0){
		printf("%d/%d",plson,plmom);
	}else{
		printf("0");
	}
}
void output2(int mom1, int mom2, int son1, int son2, int proson, int promom){
	float a=0.0;
	int i=0;
	a=((float)son1/(float)mom1*(float)son2/(float)mom2);
	for (i=2 ; i<=proson ; i++){
		if (proson%i==0 && promom%i==0){
			proson=proson/i;
			promom=promom/i;
		}
	}
	for (i=2 ; i<=promom ; i++){
		if (proson%i==0 && promom%i==0){
			proson=proson/i;
			promom=promom/i;
		}
	}	
	proson=abs(proson);
	promom=abs(promom);	
//	printf("%d\n",proson);
//	printf("%d\n",promom);	
//	printf("%f\n",a);		
	if ((son1==0 || son2==0 || mom1==0 || mom2==0)){
		printf("ERROR");
	}else if(proson >= promom && a<0.0){
		if (proson%promom!=0){
			printf("-%d(%d/%d)",(proson/promom),(proson%promom),promom);
		}else{
			printf("-%d",(proson/promom));
		}
	}else if(proson >= promom && a>0.0){
		if (proson%promom!=0){
			printf("%d(%d/%d)",(proson/promom),(proson%promom),promom);
		}else{
			printf("%d",(proson/promom));
		}
	}else if(proson < promom && a<0.0){
		printf("-%d/%d",proson,promom);
	}else if(proson < promom && a>0.0){
		printf("%d/%d",proson,promom);
	}else{
		printf("0");
	}		
}
void main(){
	int mom1,mom2,son1,son2,i=0;
	int plson,plmom,proson,promom=0;
	scanf("%d/%d",&son1,&mom1);
	scanf("%d/%d",&son2,&mom2);
	plus(mom1,mom2,son1,son2,&plson,&plmom);
	product(mom1,mom2,son1,son2,&proson,&promom);
	output1(mom1,mom2,son1,son2,plson,plmom);
	printf("\n");
	output2(mom1,mom2,son1,son2,proson,promom);
}
