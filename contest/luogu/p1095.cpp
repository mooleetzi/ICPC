#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m,s,t;
    cin>>m>>s>>t;
    int c=m;
    int s1=0,s2=0;
    for (int i=1;i<=t;i++){
        s1+=17;
        if (c>=10){
            s2+=60;
            c-=10;
        }
        else
            c+=4;
        s1=s1<s2?s2:s1;
        if (s1>=s){
            cout<<"Yes\n"<<i<<"\n";
            return 0;
        }
    }
    cout<<"No\n"<<s1<<"\n";
    return 0;
}
