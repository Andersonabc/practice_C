#include <stdio.h>
#include <string.h>
#define shapeText(TYPE) int(*GateValue)(int x1,int x2);\
int(*GateValue1)(int x1)
//#define shpae(t) int(*GateValue1)(int x1)
typedef struct GGate{ 
	shapeText();  
	//shpae();
}Gate; 

int GateAndValue(int x1,int x2){
	if((x1 + x2)==2) return 1;
	else return 0;
} 
int GateOrValue(int x1,int x2){
	if((x1 + x2)>=1) return 1;
	else return 0;

} 
int GateNotValue(int x1){
	if(x1 == 1) return 0;
	else return 1;
} 
int GateEmptyValue(int x1){
	return x1;
} 


void CreateGate(Gate *obj,char a){ 
	if(a == 'N'){
		obj->GateValue1 = GateNotValue;
	//	printf("N\n");
	}else if (a== 'E'){
		obj->GateValue1 = GateEmptyValue;
		//printf("E\n");
	}else if(a == 'A'){
		obj->GateValue = GateAndValue;
		//printf("A\n");
	}else if(a == 'O'){
		obj->GateValue = GateOrValue;
		//printf("O\n");
	}
	 
} 

int main(){
	int i=0,j=0,k=0;
	char data[9];
	char ga[9];
	gets(data);
	gets(ga);
	int ans[4];
	Gate p;
	Gate q;
	Gate r;
	Gate s;
	Gate t;
	Gate *okok[]={&p,&q,&r,&s,&t};
	/*CreateGate(&p,ga[0]);
	CreateGate(&q,ga[2]);
	CreateGate(&r,ga[4]);
	CreateGate(&s,ga[6]);
	CreateGate(&t,ga[8]);*/
	for (i=0 ; i<9 ;i+=2){
		//printf("%d %d",i,j);
		CreateGate(okok[j],ga[i]);
		j++;
	} 
	ans[0]= p.GateValue1(data[0]-'0');
	ans[1]= q.GateValue(data[2]-'0',ans[0]);
	ans[2]= r.GateValue(data[4]-'0',ans[1]);
	k= s.GateValue(data[6]-'0',data[4]-'0');
	ans[3]= t.GateValue(ans[2],k);
	
	printf("%d,%d,%d,%d",ans[0],ans[1],ans[2],ans[3]);
	return 0; 
} 
