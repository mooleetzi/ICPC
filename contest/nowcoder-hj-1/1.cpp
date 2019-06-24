#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#define eps 0.000001
using std::cin;
using std::cout;
typedef long long ll;
int a[101];
ll num[101];
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    ll x;
    cin>>n>>x;
    for (int i=0;i<n;i++)
        cin>>a[i]>>num[i];
    for (int i=n-1;i>-1;i--){
        if (a[i]==1)
            x-=num[i];
        else if (a[i]==2)
            x+=num[i];
        else if (a[i]==3)
            x/=num[i];
        else if (a[i]==4)
            x*=num[i];
    }
    cout<<x;
    return 0;
}
