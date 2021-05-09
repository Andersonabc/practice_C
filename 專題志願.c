#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct student{
    char choose[10];
};

struct teacher{
    char choose[10];
    char student;
};

void fetch(struct student data_s[], int n, int m, char **tmp, int column, int start){ /*第column個學生志願*/
    int i, j;
    char string[2]={0}; /*儲存用*/
    for(i=0;i<m;i++) tmp[i][0] = '\0'; /*reset*/
    for(i=0;i<m;i++){ /*第i個老師*/
        for(j=0;j<n;j++) /*第j個學生*/
            if(data_s[j].choose[column]==i+'A'){ /*取選第i個老師的學生 存到該老師tmp底下*/
                string[0] = j+start;
                strcat(tmp[i], string);
            }
    }
}

void process(struct student data_s[], struct teacher data_t[], int n, int m, int start){
    int i=0, j=0, k=0, flag=0; /*0為都有配對到 1為尚未配對完成*/
    char **tmp; /*tmp 第一維的順序為老師順序 第二維是該老師被選擇的學生名單*/
    tmp = (char **)malloc(sizeof(char *)* m);
    for(i=0;i<m;i++) tmp[i] = (char *)malloc(sizeof(char)* n);
    i=0;
    while(i<m){ /*i為學生第i個志願*/
        fetch(data_s, n, m, tmp, i, start); /*各個學生的第i個志願分類到老師底下*/
        for(j=0;j<m;j++){ /*第j個教師*/
            /*無衝突*/
            if(strlen(tmp[j])==1 && data_t[j].student==0){
                data_t[j].student = tmp[j][0]; /*分配學生給老師*/
                strcpy(data_s[tmp[j][0]-start].choose, "000"); /*已被分配到老師的學生 志願序 歸0*/
            }else if(data_t[j].student==0){ /*有衝突 k為老師第k個志願*/
                for(k=0;k<n;k++){ /*以該衝突的老師第k個志願 分配學生給老師*/
                    if(strchr(tmp[j], data_t[j].choose[k])!=NULL){
                        data_t[j].student = data_t[j].choose[k]; /*分配學生給老師*/
                        strcpy(data_s[data_t[j].choose[k]-start].choose, "000"); /*已被分配到老師的學生 志願序 歸0*/
                        break;
                    }
                }
            }
        }
        /*下方是提早結束的code 可加可不加 */
        for(j=0;j<m;j++) if(data_t[j].student==0) flag=1;
        if(flag==0) break;
        else flag=0;

        i++;
    }
    for(i=0;i<m;i++) free(tmp[i]);
    free(tmp);
}

void input(struct student data_s[], struct teacher data_t[], int *n, int *m){
    int i=1, j=0;
    char tmp='0'; /*檢查換行用*/
    while(tmp!='\n'){ /*先看輸入志願個數 先取第一個學生*/
        scanf(" %c%c", &data_s[0].choose[(*m)++], &tmp);
    }
    *n = *m; /*老師跟學生志願個數一樣*/
    while(i<*n){ /*取其餘的學生*/
        for(j=0;j<*m;j++) scanf(" %c%*c", &data_s[i].choose[j]);
        i++;
    }
    i=j=0;
    while(i<*m){ /*取老師志願*/
        for(j=0;j<*n;j++) scanf(" %c%*c", &data_t[i].choose[j]);
        data_t[i++].student = 0;
    }
}

void main(){
    int i=0, j=0, n=0, m=0, start; //n個學生 m個老師
    struct student data_s[10];
    struct teacher data_t[10];
    input(data_s, data_t, &n, &m); /*處理輸入*/
    start = ('Z'-n+1); /*start 取學生的初始代號*/
    process(data_s, data_t, n, m, start); /*分配*/
    for(i=0;i<n;i++) /*輸出 按照學生順序*/
        for(j=0;j<m;j++) if(data_t[j].student==i+start) printf("%c->%c\n", data_t[j].student, j+'A');
}
