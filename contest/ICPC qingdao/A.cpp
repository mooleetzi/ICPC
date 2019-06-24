#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
    int t;
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        int x,y,ans1,ans2;
        //x=y=ans1=ans2=0;
        cin>>x>>y;
        if (x==y)
            ans1=ans2=x;
        else if (!y)
            ans1=ans2=0;
        else if (x>y){
            int now=x-y+1;
            ans1=y;
            ans2=y/now;
            if (y%now!=0)
                ++ans2;
        }
        cout<<ans1<<" "<<ans2<<"\n";
    }
}
