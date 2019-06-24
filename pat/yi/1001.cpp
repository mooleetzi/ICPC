#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int n,m=0;
    cin>>n;
    while(n!=1){
        if (n&1)
            n=(3*n+1)>>1;
        else
            n>>=1;
        ++m;
    }
    cout<<m;
    return 0;
}
