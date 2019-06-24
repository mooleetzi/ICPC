#include<iostream>
#include<cstdio>
int main(){
    int x,y;
    while(scanf("%d%d",&x,&y)==2){
        int ans=x^y;
        printf("%d\n",ans);
    }
}
