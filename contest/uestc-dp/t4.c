#include<stdio.h>
void jump(float);
int main(){
    float n;
    scanf("%f",&n);
    jump(n);
    return 0;
}
void jump(float x){
    float ans=x;
    x/=2;
    int i=1;
    while(x&&i<10){
        ans+=2*x;
        x/=2;
        i++;
    }
    if (i>=10)
        x*=2;
    printf("%f %f",ans,x);
    return;
}
