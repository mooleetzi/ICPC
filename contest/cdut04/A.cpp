#include<iostream>
#include<cstring>
#include<map>
using namespace std;
map<string,int> s;
int main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        string q;
        cin>>q;
        if (s[q]==0)
            cout<<"OK\n";
        else
            cout<<q<<s[q]<<"\n";
        s[q]++;
    }
    return 0;
}
