#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
int a[maxn];
char p[maxn];
int n,d,tot;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    ios::sync_with_stdio(false);
    //cin.tie(0);
    while(cin>>n>>d){
        memset(a,0,sizeof a);
        int f1=0;
        tot=0;
        int sum=0;
        for (int i=0;i<n;i++){
            char ch;
            cin>>ch;
            p[i]=ch;
            if (ch=='0'&&i==0){
                f1=1;
                continue;
            }
            else if (ch=='0'&&sum){
                tot++;
                a[tot]=sum;
                sum=0;
            }
            else if (ch=='1')
                sum++;
        }
        if (p[n-1]=='1'){
            sum=0;
            f2=1;
            for (int i=n-1;i>0;i--)
                if (p[i]=='1')
                    sum++;
                else
                    break;
        }
        a[++tot]=sum;
        sort(a+1,a+1+tot,cmp);
        int ans=0;
        if (f1==1){
            for (int i=1;i<=(d/2);i++)
                ans+=a[i];
        }
        else{
            for (int i=1;i<=(d/2)+1;i++)
                ans+=a[i];
        }
        cout<<ans<<"\n";
    }
}
