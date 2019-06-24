#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;
    int er=0;
    for (int i=0;i<s.size();i++)
        if (s[i]=='2')
            ++er;
    double ans=er/((s.size())*1.0);
    double time=1;
    if (s[0]=='-'){
        ans=er/((s.size()-1)*1.0);
        time+=0.5;
    }
    if (((s[s.size()-1]-48)&1)==0){
        time*=2;
    }
    ans=ans*time*100;
    cout<<fixed<<setprecision(2)<<ans<<"%";
    return 0;
}
