#include<stdio.h>
#include<stdlib.h>
typedef struct stu{
    char name[20];
    int num;
    float a,b,c,ave;
}stu;
int main(){
    stu q[6];
    freopen("stud.dat","w",stdout);
    for (int i=0;i<5;i++){
        scanf("%s%d%f%f%f",&q[i].name,&q[i].num,&q[i].a,&q[i].b,&q[i].c);
        q[i].ave=q[i].a+q[i].b+q[i].c;
        q[i].ave/=3;
    }
    for (int i=0;i<5;i++){
        printf("%s %d %f %f %f %f\n",q[i].name,q[i].num,q[i].a,q[i].b,q[i].c,q[i].ave);
    }
    return 0;
}
