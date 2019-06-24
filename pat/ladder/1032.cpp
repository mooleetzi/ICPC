#include<iostream>
using namespace std;
int main(){
    int n;
    char ch;
    string s;
    cin>>n>>ch;
    char ss;
    getline(cin,s);
    getline(cin,s);
    if (s.size()>=n){
        for (int i=s.size()-n;i<s.size();i++)
            cout<<s[i];
        cout<<"\n";
    }
    else{
        for (int i=0;i<n-s.size();i++)
            cout<<ch;
        cout<<s<<"\n";
    }
    return 1;
}
