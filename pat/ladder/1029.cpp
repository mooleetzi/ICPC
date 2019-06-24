#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
    int n;
    double ans;
    cin>>n;
    ans=(n-100)*0.9*2;
    cout<<fixed<<setprecision(1)<<ans;
    return 0;
}
