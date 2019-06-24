#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const char s[][4]={"add","beq","bne","blt","bgt"};
const int maxn=1e4+10;
int vis[maxn][300];
struct node{
    int op,c1,c2;
}info[maxn];
int main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        //memset(vis,0,sizeof vis);
        cin>>n;
        for (int i=1;i<=n;i++)
            for (int j=0;j<256;j++)
                vis[i][j]=0;
        for (int i=1;i<=n;i++){
            char now[4];
            int op1,op2;
            cin>>now;
            if (strcmp(now,s[0])==0){
                cin>>op1;
                info[i]={0,op1};
            }
            else{
                cin>>op1>>op2;
                for (int j=1;j<=4;j++)
                if (strcmp(now,s[j])==0){
                        info[i]={j,op1,op2};
                        break;
                }
            }
        }
        int now=1,cnt=0,r=0,flag=0;
        while(1){
            if (now>n){
                cout<<"Yes\n";
                break;
            }
            if (flag){
                cout<<"No\n";
                break;
            }
            vis[now][r]=1;
            switch(info[now].op){
                case 0:{
                    r+=info[now].c1;
                    if (r>=256)
                        r-=256;
                    ++now;
                    if (vis[now][r])
                        flag=1;
                    break;
                }
                case 1:{
                    if (r==info[now].c1)
                        now=info[now].c2;
                    else
                        ++now;
                    if (vis[now][r])
                        flag=1;
                    break;
                }
                case 2:{
                    if (r!=info[now].c1)
                        now=info[now].c2;
                    else
                        ++now;
                    if (vis[now][r])
                        flag=1;
                    break;
                }
                case 3:{
                    if (r<info[now].c1)
                        now=info[now].c2;
                    else
                        ++now;
                    if (vis[now][r])
                        flag=1;
                    break;
                }
                case 4:{
                    if (r>info[now].c1)
                        now=info[now].c2;
                    else
                        ++now;
                    if (vis[now][r])
                        flag=1;
                    break;
                }
            }
        }
    }
    return 0;
}
