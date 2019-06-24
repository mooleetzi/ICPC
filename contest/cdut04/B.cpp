#include<iostream>
#include<cstring>
#include<map>
using namespace std;
map<string,int> s1;
int a[7];
string s2[]={"","Power","Time","Space","Soul","Reality","Mind"};
int main(){
    s1["purple"]=1;
    s1["green"]=2;
    s1["blue"]=3;
    s1["orange"]=4;
    s1["red"]=5;
    s1["yellow"]=6;
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int q=t;
    while(t--){
        string s;
        cin>>s;
        a[s1[s]]=1;
    }
    cout<<6-q<<"\n";
    for (int i=1;i<=6;i++)
        if (!a[i])
            cout<<s2[i]<<"\n";
    return 0;
}
