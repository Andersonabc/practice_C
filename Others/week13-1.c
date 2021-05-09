#include <stdio.h>
#include <stdlib.h>

int main(){
	int i,j,far,err=0;
	int cls[3][4]={0};
	int ans[10][3]={0};
	while (i<3){
		scanf("%d",&cls[i][0]);
		scanf("%d",&cls[i][1]);
		if (cls[i][1]==2){
			scanf("%d",&cls[i][2]);
			scanf("%d",&cls[i][3]);			
		}else{
			if (cls[i][1]!=1){
				err=1;
			}
			scanf("%d",&cls[i][2]);
			
		}

		i+=1;
	}

    for (i = 0; i < 3; i++){
        if (cls[i][0] / 1000 == 0 || (cls[i][1] < 0 || cls[i][1] > 2)){
            err = 1;
	    }
        for (j = 2; j < 2 + cls[i][1]; j++){		
            if (cls[i][j] / 10 <=0 || cls[i][j] / 10 > 5) {			
                err = 1;
           }
	}}
    if (err == 1){	
    	printf("-1");
    }else{
		for (i=2 ; i < 2 + cls[0][1] ; i++ ){
			for (j=2 ; j < 2 + cls[1][1] ; j++ ){
				if (cls[0][i]==cls[1][j]){
					ans[far][0]=cls[0][0];
					ans[far][1]=cls[1][0];
					ans[far][2]=cls[1][j];
					far+=1;
				}
			}
		}
		for (i=2 ; i < 2 + cls[0][1] ; i++ ){
			for (j=2 ; j < 2 + cls[2][1] ; j++ ){
				if (cls[0][i]==cls[2][j]){
					ans[far][0]=cls[0][0];
					ans[far][1]=cls[2][0];
					ans[far][2]=cls[2][j];
					far+=1;
				}
			}
		}	
		for (i=2 ; i < 2 + cls[2][1] ; i++ ){
			for (j=2 ; j < 2 + cls[1][1] ; j++ ){
				if (cls[1][i]==cls[2][j]){
					ans[far][0]=cls[1][0];
					ans[far][1]=cls[2][0];
					ans[far][2]=cls[1][i];
					far+=1;
				}
			}
		}
	if (far == 0) {
	printf("correct");}		
	else{
		for (i=0 ; i<far ; i++){
			printf("%d,%d,%d", ans[i][0], ans[i][1], ans[i][2]);
			printf("\n");
		}
	}	
	}
    return 0;	
}
