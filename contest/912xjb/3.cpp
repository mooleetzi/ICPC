#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int x,y,z;
int solve(){
    int a[20];
    memset(a,0,sizeof a);
    for (int i=1;i<=20;i++)
        a[i-1]=x*i;
    int f=0;
    for (int i=0;i<(1<<20);i++){
        int cnt=0;
        for (int j=0;j<20;j++)
            if (i&(1<<j))
                cnt+=a[j];
        if (cnt%y==z)
            return 1;
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        cin>>x>>y>>z;
        int ans=solve();
        if (ans)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
