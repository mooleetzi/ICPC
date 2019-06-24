#include<iostream>
#include<cmath>
using namespace std;
string s[]={"You are wan mei!","You are tai shou le!","You are tai pang le!"};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        double h,w;
        cin>>h>>w;
        double opt=(h-100)*1.8;
        if (fabs(opt-w)<opt*0.1)
            cout<<s[0]<<"\n";
        else if (w>opt)
            cout<<s[2]<<"\n";
        else
            cout<<s[1]<<"\n";
    }
    return 0;
}
