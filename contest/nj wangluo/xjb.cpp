#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
int ans[10000][10],cnt;
int p[10];
void search(int step,int now){
    if (step==10){
        if (now==n){
            for (int i=0;i<10;i++)
                ans[cnt][i]=p[i];
            ++cnt;
        }
    }
    else{
        for (int i=1;i<=3;i++){
            p[step]=i;
            search(step+1,now+i);
        }
    }
}
int main(){
    scanf("%d",&n);
    search(0,0);
    printf("%d\n",cnt);
    for (int i=0;i<cnt;i++)
        for (int j=0;j<10;j++)
            printf("%d%c",ans[i][j],j==9?'\n':' ');
    return 0;
}
