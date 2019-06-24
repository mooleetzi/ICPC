#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#define eps 0.00001
using namespace std;
double getNum(double a,double d,double s){
    return a+s-a*cosh(d/(2*a));
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int d,s;
    cin>>d>>s;
    double l=0,r=10000,mid;
    double a;
    while(1){
        mid=(l+r)/2;
        a=getNum(mid,d,s);
        if (fabs(a)<eps)
            break;
        else{
            if (a>0)
                r=mid;
            else
                l=mid;
        }
    }
    cout<<fixed<<setprecision(9)<<2*mid*sinh(d/(2*mid))<<"\n";
    return 0;
}
