#include<iostream>
using namespace std;
string s[]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
int main(){
    ios::sync_with_stdio(false);
    string str;
    cin>>str;
    if (str[0]=='-'){
        cout<<"fu ";
        for (int i=1;i<str.size()-1;i++)
            cout<<s[str[i]-48]<<" ";
        cout<<s[str[str.size()-1]-48];
    }
    else{
        for (int i=0;i<str.size()-1;i++)
            cout<<s[str[i]-48]<<" ";
        cout<<s[str[str.size()-1]-48];
    }
    return 0;
}
