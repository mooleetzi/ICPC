#include<bits/stdc++.h>
using namespace std;
const int maxn=2e4+10;
struct node{
    int w,initInd;
    node(){}
    node(int a,int b){
        initInd=b;
        w=a;
    }
    bool operator<(const node&a)const{
        if (w==a.w)
            return initInd<a.initInd;
        return w>a.w;
    }
}a[maxn];
int n,k;
int e[11];
int main(){
    cin>>n>>k;
    for (int i=1;i<=10;i++)
        cin>>e[i];
    for (int i=1;i<=n;i++){
        int x;
        cin>>x;
        a[i]=node(x,i);
    }
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++){
        int now=(i-1)%10+1;
        a[i].w+=e[now];
    }
    sort(a+1,a+1+n);
    for (int i=1;i<=k;i++)
        cout<<a[i].initInd<<" ";
}
