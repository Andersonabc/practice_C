#include <stdio.h>

/*void main(){
	int i=0;
	int x[]={24,18,59,12,36,5,9};
	quickSort(x,0,7);
	printf("//////////////////////////////\n");
	for(i=0 ; i<7 ; i++){
		printf("%d ",x[i]);
	}
}
void quickSort(int x[], int first, int last){
	int i=0;
	int splitVal = 0;
	int splitPoint=0;
	if(first < last){
		splitVal = x[first];
		splitPoint = split(x, splitVal, first, last);
		quickSort(x,first,splitPoint-1);
		quickSort(x,splitPoint+1, last);
	}
	for(i=0 ; i<7 ; i++){
		printf("%d ",x[i]);
	}	
	printf("\n");
	printf("------------------------------\n");
}

int split(int x[], int splitVal, int first, int last){
	int splitPoint=0;
	int left = first +1;
	int right = last;
	int temp=0;
	while (left <= right){
		while ((x[left]>=splitVal)&&(left<=right)) left++;
		while((x[right]<=splitVal)&&(left<=right)) right--;
		if (left < right){
			printf("swap1\n");
			temp=x[left];
			x[left]=x[right];
			x[right]=temp;
		} 
	}
	splitPoint = right;
	printf("swap2\n");
	temp=x[first];
	x[first]=x[splitPoint];
	x[splitPoint]=temp;
	return splitPoint;
}*/
void write(){
    FILE *p;
    char c;
    p = fopen("test.txt", "w");
    while((c=getchar())!='\n'){
        putc(c, p);
    }
    fclose(p);
    return;
}
void main(){
    read();
    write();
    return;
}



