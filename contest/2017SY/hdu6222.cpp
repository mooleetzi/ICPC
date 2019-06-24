#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
vector<__int128_t> a;
__int128 pow(__int128 x,int n){
    __int128_t ans=1;
    while(n){
        if (n&1)
            ans*=x;
        x*=x;
        n>>=1;
    }
    return ans;
}
int main(){
    int t;
    __int128 x=2,y=4,z=10;
    a.push_back(y);
    while(y<=pow(z,30)){
        __int128 t=y;
        y=y*4-x;
        a.push_back(y);
        x=y;
    }
    ios::sync_with_stdio(false);
    cin>>t;
    for (int i=0;i<t;i++){
        __int128 now;
        cin>>now;
        for (auto x : a)
        if (x>=now){
            cout<<x<<"\n";
            break;
        }
    }
    return 0;
}
