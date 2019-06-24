#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int a[10],n;
void doit(){
    for (int i=0;i<10;i++)
        for (int j=1;j<10;j++)
            for (int k=1;k<10;k++)
            if (i+j+k==10&&i+2*j+3*k==n){
                for (int q=1;q<=i;q++) a[q]=1;
                for (int q=i+1;q<=j+i;q++) a[q]=2;
                for (int q=i+j+1;q<=10;q++) a[q]=3;
            }
}
int main(){
    int f=0;
    scanf("%d",&n);
    if (n<10||n>30)
        f=1;
    else doit();
}
