#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int assign(int *data, int n, int i){
    int j=0;
    while(j<n){
        if(i==0) return 1;
        if(i%10==0 || i%10>n) return 0; //������0 or �j��n
        data[j++] = i%10;
        i /= 10;
    }
    return 1;
}

int IsNotSame(int *data, int n){ //�ˬd�O�_���ۦP�Ʀr
    int i, j;
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++) if(data[i]==data[j] && data[i]!=0) return 0;
    return 1;
}

int gen(int **data, int n){ //���ͲզX
    int len=0, i, M=pow(10, n);
    for(i=1;i<M;i++) if(assign(data[len], n, i) && IsNotSame(data[len], n)) len++; //����1~10^n
    return len;
}

void sort(int *data, int n, int **activity){ //�ƧǸӲզX�ɶ� �Ѥp~�j
    int j, k, tmp;
    for(j=1;j<n;j++)
        for(k=0;k<n-j;k++){
            if(data[k+1]==0) break;
            if(activity[data[k]-1][1]>activity[data[k+1]-1][1]){
                tmp = data[k];
                data[k] = data[k+1];
                data[k+1] = tmp;
            }
        }
}

int countroom(int *data, int i, int **activity){
    int Max = 1, now = data[i];
    for(i=i-1;i>=0;i--){ //�ˬd�Ӭ��ʥH�e���ɶ��O�_���| �ݭn�h�}�|ĳ��
        if(activity[now-1][1]<activity[data[i]-1][2]) Max++;
    }
    return Max;
}

int getMaxActivity(int **data, int n, int m, int len, int **activity){
    int i=0, j, MaxRoom=0, counter=0, BestMax = 0;
    while(i<len){
        sort(data[i], n, activity); //�ɶ��Ƨ�

        for(j=0;j<n;j++){ //�ˬd�ж��ϥζq
            if(data[i][j]==0) break;
            MaxRoom = countroom(data[i], j, activity);
            if(MaxRoom>m) break;
        }

        if(MaxRoom>m) data[i][0] = -1; //�W�L�ѵ��� �ӲզX�L��
        else{
            for(j=0;j<n;j++) if(data[i][j]!=0) counter++; //���ʼ�
            data[i][10] = counter; //�x�s
        }

        if(data[i][0]!=-1 && BestMax < counter) BestMax = counter; //���̤j���ʼ�
        counter = 0;
        i++;
    }
    return BestMax;
}

int getMaxHour(int **data, int n, int m, int len, int **activity){
    int i=0, j, BestMax=0, counter=0;
    while(i<len){
        if(data[i][0]==-1){ //�զX�L�� �h���L
            i++;
            continue;
        }

        for(j=0;j<n;j++){ //�ɶ��p��
            if(data[i][j]==0) break;
            counter += (activity[data[i][j]-1][2] - activity[data[i][j]-1][1]);
        }

        data[i][11] = counter; //�x�s
        if(BestMax<counter) BestMax = counter; //��̤j�ϥήɶ�

        counter = 0;
        i++;
    }
    return BestMax;
}

void main(){
    int i, j, n, m, **data, len, **activity, Maxactivity, Maxhour;
    scanf("%d", &m);
    scanf("%d", &n);
    /*initialize*/
    data = (int **)malloc(pow(10, n) * sizeof(int *));
    activity = (int **)malloc(n * sizeof(int *));
    for(i=0;i<pow(10, n);i++) data[i] = (int *)calloc(12, sizeof(int));
    for(i=0;i<n;i++) activity[i] = (int *)calloc(3, sizeof(int));
    len = gen(data, n);
 
    /*process*/
    for(i=0;i<n;i++) scanf("%d %d %d", &activity[i][0], &activity[i][1], &activity[i][2]);
    Maxactivity = getMaxActivity(data, n, m, len, activity);
    Maxhour = getMaxHour(data, n, m, len, activity);
    printf("%d\n", Maxhour);
    printf("%d\n", Maxactivity);



    for(i=0;i<pow(10, n);i++) free(data[i]);
    free(data);
    for(i=0;i<n;i++) free(activity[i]);
    free(activity);
}
