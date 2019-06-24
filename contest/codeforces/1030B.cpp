#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#define max(a,b) (a>b?a:b)
using namespace std;
int n,d;
int inside(int x,int y){
    double q1=(double)x+y,q2=(double)x-y;
    double k1=d,k2=2*n-d,k3=d,k4=-d;
    if (q1>=k1&&q1<=k2&&q2>=k4&&q2<=k3)
        return 1;
    return 0;
}
int main(){
    int m;
    ios::sync_with_stdio(false);
    cin>>n>>d>>m;
    for (int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        if (inside(x,y))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
