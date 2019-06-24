#include<stdio.h>
typedef struct complex{
    int real,im;
}complex;
complex product(complex a,complex b);
void print(complex);
int main(){
    complex c1,c2;
    scanf("%d%d%d%d",&c1.real,&c1.im,&c2.real,&c2.im);
    complex ans=product(c1,c2);
    print(ans);
    return 0;
}
complex product(complex a,complex b){
    complex ans;
    ans.real=a.real*b.real-a.im*b.im;
    ans.im=a.real*b.im+b.real*a.im;
    return ans;
}
void print(complex a){
    printf("%d+%di",a.real,a.im);
}
