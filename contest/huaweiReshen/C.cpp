#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    if (a>b)
        swap(a,b);
    if (a>c)
        swap(a,c);
    if (b>c)
        swap(b,c);
    int ans=0;
    for (int i=n/a;i>-1;i--)
        for (int j=0;j<=n/b;j++){
            int now=n-i*a-j*b;
            if (now<0)
                break;
            if (now==0){
                ans=max(i+j,ans);
                break;
            }
            else{
                if (now%c==0){
                    ans=max(i+j+now/c,ans);
                }
            }
        }
    cout<<ans<<"\n";
    return 0;
}
