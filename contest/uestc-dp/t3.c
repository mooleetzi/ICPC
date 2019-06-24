#include<stdio.h>
#include<stdlib.h>
typedef struct stu{
    char name[20];
    int num;
    float a,b,c,ave;
}stu;
void sortScore(stu st[],int len){
    int flag = 0;
    for(int i=0;i<len-1;i++){
        flag = 1;
        for(int j=0;j<len-1-i;j++){
            if(st[j].ave>st[j+1].ave){
                stu temp = st[j];
                st[j] = st[j+1];
                st[j+1] = temp;
            }
        }
        if(flag==0)
            break;
    }
}
int main(){
    freopen("stud.dat","r",stdin);
    freopen("stu_sort.dat","w",stdout);
    stu q[5];
    for (int i=0;i<5;i++){
        scanf("%s%d%f%f%f%f",&q[i].name,&q[i].num,&q[i].a,&q[i].b,&q[i].c,&q[i].ave);
    }
    sortScore(q,5);
    for (int i=0;i<5;i++){
        printf("%s %d %f %f %f %f\n",q[i].name,q[i].num,q[i].a,q[i].b,q[i].c,q[i].ave);
    }
    return 0;
}
