#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int l,r,d;
    int t;
    cin>>t;
    while(t--){
        cin>>l>>r>>d;
        if (d<l||d>r)
            cout<<d<<"\n";
        else {
            int tmp=r%d;
            cout<<r+d-tmp<<"\n";
        }
    }
    return 0;
}
