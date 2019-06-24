#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#define eps 0.000001
using std::cin;
using std::cout;
typedef long long ll;
const int maxn=1e5+10;
int a[5];
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int x;
        cin>>x;
        ++a[x];
    }
    int pre=0;
    ll ans=0;
    for (int i=0;i<n;i++){
        if (pre==0){
            if (a[4]){
                --a[4];
                ans+=16;
                pre=4;
            }
            else if (a[2]){
                --a[2];
                ans+=4;
                pre=2;
            }
            else{
                --a[0];
                break;
            }
        }
        else if (pre==2){
            if (a[4]){
                --a[4];
                ans+=4;
                pre=4;
            }
            else if (a[0]){
                --a[0];
                ans+=4;
                pre=0;
            }
            else{
                --a[2];
                break;
            }
        }
        else if (pre==4){
            if (a[0]){
                --a[0];
                ans+=16;
                pre=0;
            }
            else if (a[2]){
                --a[2];
                ans+=4;
                pre=2;
            }
            else
                break;
        }
    }
    cout<<ans;
    return 0;
}
