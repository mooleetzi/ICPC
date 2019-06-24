#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const long double eps=1e-100;
inline int sgn(long double a){return a < -eps ? -1 : a < eps ? 0 : 1;}
int isSqrt(long double x){
    long double now=floor(sqrt(x));
    cout<<now<<" "<<x<<"\n";
    if (sgn(now*now-x)==0)
        return 1;
    return 0;
}
int main(){
    int t;
    ios::sync_with_stdio(false);
    long double s;
    cin>>s;
    cout<<s<<"\n";
    cout<<isSqrt(s)<<"\n";
    cin>>t;
    while(t--){
        long double op1,op2;
        cin>>op1;
        op2=op1*(op1-1)/2;
        int f1=isSqrt(op1),f2=isSqrt(op2);
        if (f1&&f2)
            cout<<"Arena of Valor\n";
        else if (f1)
            cout<<"Hearth Stone\n";
        else if (f2)
            cout<<"Clash Royale\n";
        else
            cout<<"League of Legends\n";
    }
    return 0;
}
