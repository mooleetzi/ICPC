#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=110;
int n,x,sum;
int a[maxn];
int ok(int now){
    int f[sum];
    if (now>sum)
        return 0;
    memset(f,0,sizeof f);
    f[0]=1;
    for (int i=0;i<n;i++)
        for (int j=now;j>=a[i];j--)
            f[j]+=f[j-a[i]];
    if (f[now])
        return 1;
    return 0;
}
int main(){
    while(cin>>n>>x){
        sum=0;
        for (int i=0;i<n;i++)
            cin>>a[i],sum+=a[i];
        while(1){
            if (ok(x)){
                cout<<x<<"\n";
                break;
            }
            x++;
        }
    }
}
