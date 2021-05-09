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

void fetch(struct student data_s[], int n, int m, char **tmp, int column, int start){ /*��column�Ӿǥͧ��@*/
    int i, j;
    char string[2]={0}; /*�x�s��*/
    for(i=0;i<m;i++) tmp[i][0] = '\0'; /*reset*/
    for(i=0;i<m;i++){ /*��i�ӦѮv*/
        for(j=0;j<n;j++) /*��j�Ӿǥ�*/
            if(data_s[j].choose[column]==i+'A'){ /*�����i�ӦѮv���ǥ� �s��ӦѮvtmp���U*/
                string[0] = j+start;
                strcat(tmp[i], string);
            }
    }
}

void process(struct student data_s[], struct teacher data_t[], int n, int m, int start){
    int i=0, j=0, k=0, flag=0; /*0�������t��� 1���|���t�粒��*/
    char **tmp; /*tmp �Ĥ@�������Ǭ��Ѯv���� �ĤG���O�ӦѮv�Q��ܪ��ǥͦW��*/
    tmp = (char **)malloc(sizeof(char *)* m);
    for(i=0;i<m;i++) tmp[i] = (char *)malloc(sizeof(char)* n);
    i=0;
    while(i<m){ /*i���ǥͲ�i�ӧ��@*/
        fetch(data_s, n, m, tmp, i, start); /*�U�Ӿǥͪ���i�ӧ��@������Ѯv���U*/
        for(j=0;j<m;j++){ /*��j�ӱЮv*/
            /*�L�Ĭ�*/
            if(strlen(tmp[j])==1 && data_t[j].student==0){
                data_t[j].student = tmp[j][0]; /*���t�ǥ͵��Ѯv*/
                strcpy(data_s[tmp[j][0]-start].choose, "000"); /*�w�Q���t��Ѯv���ǥ� ���@�� �k0*/
            }else if(data_t[j].student==0){ /*���Ĭ� k���Ѯv��k�ӧ��@*/
                for(k=0;k<n;k++){ /*�H�ӽĬ𪺦Ѯv��k�ӧ��@ ���t�ǥ͵��Ѯv*/
                    if(strchr(tmp[j], data_t[j].choose[k])!=NULL){
                        data_t[j].student = data_t[j].choose[k]; /*���t�ǥ͵��Ѯv*/
                        strcpy(data_s[data_t[j].choose[k]-start].choose, "000"); /*�w�Q���t��Ѯv���ǥ� ���@�� �k0*/
                        break;
                    }
                }
            }
        }
        /*�U��O����������code �i�[�i���[ */
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
    char tmp='0'; /*�ˬd�����*/
    while(tmp!='\n'){ /*���ݿ�J���@�Ӽ� �����Ĥ@�Ӿǥ�*/
        scanf(" %c%c", &data_s[0].choose[(*m)++], &tmp);
    }
    *n = *m; /*�Ѯv��ǥͧ��@�ӼƤ@��*/
    while(i<*n){ /*����l���ǥ�*/
        for(j=0;j<*m;j++) scanf(" %c%*c", &data_s[i].choose[j]);
        i++;
    }
    i=j=0;
    while(i<*m){ /*���Ѯv���@*/
        for(j=0;j<*n;j++) scanf(" %c%*c", &data_t[i].choose[j]);
        data_t[i++].student = 0;
    }
}

void main(){
    int i=0, j=0, n=0, m=0, start; //n�Ӿǥ� m�ӦѮv
    struct student data_s[10];
    struct teacher data_t[10];
    input(data_s, data_t, &n, &m); /*�B�z��J*/
    start = ('Z'-n+1); /*start ���ǥͪ���l�N��*/
    process(data_s, data_t, n, m, start); /*���t*/
    for(i=0;i<n;i++) /*��X ���ӾǥͶ���*/
        for(j=0;j<m;j++) if(data_t[j].student==i+start) printf("%c->%c\n", data_t[j].student, j+'A');
}
