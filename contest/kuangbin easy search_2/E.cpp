#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#define rep(i,x,y) for (int i=x;i<y;i++)
using namespace std;
const char p[]="ACGT";
int pos[10],len[10];
char s[10][10];
int n,dep;
int get_h(){
    int ans=0;
    rep(i,0,n)
        ans=max(ans,len[i]-pos[i]);
    return ans;
}
int dfs(int deep){
    int c=get_h();
    if (deep+c>dep){
        return 0;
    }
    if (!c){
        return 1;
    }
    rep(i,0,4){
        int flag=0;
        int now[10];
        rep(j,0,n)
            now[j]=pos[j];
        rep(j,0,n){
            if (s[j][pos[j]]==p[i]){
                flag=1;
                pos[j]++;
            }
        }
        if (flag){
            if (dfs(deep+1))
                return 1;
            rep(j,0,n)
                pos[j]=now[j];
        }
    }
    return 0;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        dep=0;
        scanf("%d",&n);
        rep(i,0,n)
            scanf("%s",s[i]),len[i]=strlen(s[i]),dep=max(dep,len[i]),pos[i]=0;
        int ans=0;
        while(1){
            if (dfs(0))
                break;
            dep++;
        }
        printf("%d\n",dep);
    }
}
