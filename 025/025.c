#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.14
#define ShapeText(TYPE) char name[500];\
float (*perimeter)(struct TYPE*);\
float (*Area)(struct TYPE*)
typedef struct Circle_S { 
	ShapeText(Circle_S); 
	float radius; 
} Circle; 
typedef struct Rectangle_S { 
	ShapeText(Rectangle_S); 
	float height;
	float width; 
} Rectangle;
typedef struct Triangle_S { 
	ShapeText(Triangle_S); 
	float lo1;
	float lo2;
	float lo3; 
} Triangle;
typedef struct Square_S { 
	ShapeText(Square_S); 
	float lo; 
} Square;


typedef struct Shape_t { // Shape 物件，沒有欄位 
	ShapeText(Shape_t);
} Shape; 



//算面積 
float CArea(Circle *obj) {
	return obj->radius*obj->radius*PI; 
} 
float TArea(Triangle *obj) {
	float temp;
	temp=(obj->lo1+obj->lo2+obj->lo3)/2.00;	
	return sqrt(temp*(temp-obj->lo1)*(temp-obj->lo2)*(temp-obj->lo3)); 
} 
float RArea(Rectangle *obj) {
	return (obj->height*obj->width); 
} 
float SArea(Square *obj) {
	return obj->lo*obj->lo; 
} 

//算周長 
float CPerimeter(Circle *obj) {
	return 2.00*3.14 * obj->radius; 
} 
float TPerimeter(Triangle *obj) {
	return obj->lo1+obj->lo2+obj->lo3; 
} 
float RPerimeter(Rectangle *obj) {
	return 2.00*(obj->height+obj->width); 
} 
float SPerimeter(Square *obj) {
	return 4.00*obj->lo; 
} 

//創建新圖形 
void CircleNew(Circle *obj,char **ww) { 
	strcpy(obj->name,ww[0]); 
	obj->radius=atof(ww[1]);
	obj->perimeter = CPerimeter; 
	obj->Area = CArea;
} 
void TriangleNew(Triangle *obj,char **ww) { 
	strcpy(obj->name,ww[0]); 
	obj->lo1=atof(ww[1]);
	obj->lo2=atof(ww[2]);
	obj->lo3=atof(ww[3]);
	obj->perimeter = TPerimeter; 
	obj->Area = TArea;
}
void SquareNew(Square *obj,char **ww) { 
	strcpy(obj->name,ww[0]); 
	obj->lo=atof(ww[1]);
	obj->perimeter = SPerimeter; 
	obj->Area = SArea;
}
void RectangleNew(Rectangle *obj,char **ww) { 
	strcpy(obj->name,ww[0]); 
	obj->height=atof(ww[1]);
	obj->width=atof(ww[2]);
	obj->perimeter = RPerimeter;
	obj->Area = RArea;
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
void pp(char *pchData[],char *str){
	int count=0;
	pchData[count]=strtok(str,"(),");
	while(pchData[count]!=NULL){
		pchData[++count]=strtok(NULL,"(),");
	}
}
int pp2(char *pchData[],char *str){
	int count=0;
	pchData[count]=strtok(str,"*");
	while(pchData[count]!=NULL){
		count++;
		pchData[count]=strtok(NULL,"*");
	}
	return count;
}
void swap(Shape **w , Shape **e){
	Shape **temp=*w;
	*w=*e;
	*e=temp;
}
int main() { 
	int length=0;
	char input[500];
	gets(input);
	char *onprocess[500];
	length=cut(input,onprocess);
	Shape *saver[500];
	int total=0;

	
	while (1){
		
		char *qq[500];
		char yy[500];		
		int i=0,j=0,k=0;
		int x=0;
		int location=0;
		char temp[500];
		char tmp;
		
		if(strcmp(onprocess[0],"exit") == 0) break;
		else if(strcmp(onprocess[0],"touch") == 0)	{
			for(i=1 ; i<length ; i+=2){
				strcpy(yy,onprocess[i+1]);
				pp(qq,yy);	
				if(strcmp(onprocess[i],"R") == 0){					
					Rectangle *r=malloc(sizeof(Rectangle));					
					RectangleNew(r,qq);
					saver[total]=(Shape*)r;					
				}else if(strcmp(onprocess[i],"C") == 0){				
					Circle *c=malloc(sizeof(Circle));					
					CircleNew(c,qq);
					saver[total]=(Shape*)c;										
				}else if (strcmp(onprocess[i],"S") == 0){
					Square *s=malloc(sizeof(Square));					
					SquareNew(s,qq);
					saver[total]=(Shape*)s;									
				}else if(strcmp(onprocess[i],"T") == 0){
					Triangle *t=malloc(sizeof(Triangle));					
					TriangleNew(t,qq);
					saver[total]=(Shape*)t;									
				}
				total++;
			}
			for(i=0 ; i<total-1 ; i++){
				for(j=i+1 ; j<total ; j++){
					if(strcmp(saver[i]->name,saver[j]->name)>0)	swap(&saver[i],&saver[j]);				
				}
			}				
		}else if(strcmp(onprocess[0],"cat") == 0){
			int many=0;
			int z=0;
			k=0;
			int count=0;
			char now[500];
			int location;
			int pres=0;
			int star=0;
			char prin[500][500];		
			if(strcmp(onprocess[1],"*") == 0){
				for(i=0 ; i<total ;i++){
					Shape *o=saver[i];
					printf("%.2f,%.2f\n",o->perimeter(o),o->Area(o));
				}
			}else{
				strcpy(yy,onprocess[1]);
				pres=pp2(qq,yy);
				for(star=0 ; star<strlen(onprocess[1]) ; star++){
					if(onprocess[1][star] == '*') break;  
				}
				if(star == 0){
					//printf("eqwewq%s\n",qq[0]);
					for(i=0 ; i<total ; i++){
						for(j=0 ; j<strlen(qq[0]) ; j++){
						//	printf("%c  %c\n",saver[i]->name[strlen(saver[i]->name)-1-j],qq[0][strlen(qq[0])-1-j]);
							if(saver[i]->name[strlen(saver[i]->name)-1-j] == qq[0][strlen(qq[0])-1-j]) count++;	
							else break;						
						}	
						if ((count == strlen(qq[0])) &&(strlen(saver[i]->name)!=strlen(qq[0])) ){
						//	printf("%s  %s\n",saver[i]->name,qq[0]);
						//	printf("%d  %d\n",strlen(saver[i]->name),strlen(qq[0]));
							strcpy(prin[many],saver[i]->name);
							many++;
							count=0;	
						}
					}
					for(i=0 ; i<many ; i++){
						for(j=0 ; j<total ; j++){
							if(strcmp(saver[j]->name,prin[i]) == 0){
								Shape *o=saver[j];
								printf("%.2f,%.2f\n",o->perimeter(o),o->Area(o));
								//printf("%s\n",saver[j]->name);	
							}
						}

					}
				}else if(star == strlen(onprocess[1])-1){
					//printf("ewqew");
					for(i=0 ; i<total ; i++){
						for(j=0 ; j<strlen(qq[0]) ; j++){
							//printf("->%c  ->%c\n",saver[i]->name[j],qq[0][j]);
							if(saver[i]->name[j] == qq[0][j]) count++;
							else break;
						}
						if (count == strlen(qq[0])&&strlen(saver[i]->name)!=strlen(qq[0])){
							strcpy(prin[many],saver[i]->name);
							many++;
							count=0;	
						}
					}
					for(i=0 ; i<many ; i++){
						for(j=0 ; j<total ; j++){
							if(strcmp(saver[j]->name,prin[i]) == 0){
								Shape *o=saver[j];
								printf("%.2f,%.2f\n",o->perimeter(o),o->Area(o));	
							}
						}
					}					
					
				}else if(star == strlen(onprocess[1])){
					for(i=1 ; i<length ; i++){
						for(j=0 ; j<total ; j++){
							if(strcmp(saver[j]->name,onprocess[i]) == 0){
								Shape *o=saver[j];
								printf("%.2f,%.2f\n",o->perimeter(o),o->Area(o));								
							}
						}
					}
					
				}else{
					int len1=strlen(qq[0]);
					int len2=strlen(qq[1]);
					for(j=0 ; j<total ; j++){
						int a1=0;
						int a2=0;
						count=0;
						for(i=0 ; i<len1 ; i++){
							if(saver[j]->name[i]==qq[0][i] )count++;
						}
						if(count == len1) a1=1;
						count=0;	
						for(i=0 ; i<len2 ; i++){
							if(saver[j]->name[strlen(saver[j]->name)-1-i]==qq[1][strlen(qq[1])-1-i] )count++;
						}	
						if(count == len2) a2=1;	
						if(a1==1 && a2 ==1 && (len1+len2)!= strlen(saver[j]->name)){
							Shape *o=saver[j];
							printf("%.2f,%.2f\n",o->perimeter(o),o->Area(o));							
						}
						count=0;		
					}
					
				}
			}
		}
		gets(input);
		length=cut(input,onprocess);	
	}
	//printf("%.2f,%.2f\n",o->perimeter(o),o->Area(o));	
} 	
//touch S fle(2) R file(2,3) C fil3e(1) S fil1e(3) T filae(5,5,5)
//touch S s_1(1) R r_1(2,3) C c_1(1)
//cat c_1 s_1 r_1 
