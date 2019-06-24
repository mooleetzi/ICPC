#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,t;
    cin>>n;
    for (int i=1;i<145;i++)
    if (i*(i+1)/2>=n){
        t=i;
        break;
    }
    int ans=0;
    for (int i=1;i<=t-1;i++)
        ans+=i*i;
    int all=t*(t-1)/2;
    ans+=(n-all)*t;
    cout<<ans<<"\n";
    return 0;
}
