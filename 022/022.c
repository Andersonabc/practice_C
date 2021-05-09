# include <stdio.h>
typedef struct input{
	int x1;
	int x2;
	int x3;
}inp;
typedef struct operate{
	char g1;
	char g2;
	char g3;
}gate;
void main(){
	char data1[10];
	gets(data1);
	inp h;
	gate gatee;
	h.x1=data1[0]-'0';
	h.x2=data1[2]-'0';
	h.x3=data1[4]-'0';
	//printf("%d,%d,%d\n",h.x1,h.x2,h.x3);
	int y1,y2,y3;
	char data2[10];
	gets(data2);
	gatee.g1=data2[0];
	gatee.g2=data2[2];
	gatee.g3=data2[4];
	//printf("%c,%c,%c\n",gatee.g1,gatee.g2,gatee.g3);
	if(gatee.g1 == 'E') y1=h.x1;
	else y1=!h.x1;
	if(gatee.g2 == 'A') y2=y1&h.x2;
	else y2=y1|h.x2;
	if(gatee.g3 == 'A') y3=y2&h.x3;
	else y3=y2|h.x3;
	
	printf("%d,%d,%d",y1,y2,y3);
} 
