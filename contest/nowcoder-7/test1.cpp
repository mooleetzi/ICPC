#include<bits/stdc++.h>
using namespace std;
const int maxn=100;
int f[maxn],vis[maxn];
int sum=0;
int main(){
    int n;
    memset(f,-1,sizeof f);
    cin>>n;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
        if (!vis[j]){
            if (f[i]==-1){
                f[i]=j;
                vis[j]=1;
                sum+=(i&j);
            }
            else {
                if ((f[i]&i)>(i&j)){
                    sum-=(f[i]&i);
                    sum+=(i&j);
                    vis[f[i]]=0;
                    f[i]=j;
                    vis[j]=1;
                }
            }
        }
    for (int i=0;i<n;i++)
        cout<<f[i]<<" ";
    cout<<"\n"<<sum;
    return 0;
}
