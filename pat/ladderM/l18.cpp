#include<iostream>
using namespace std;
int main(){
    int len;
    char ch;
    string s;
    cin>>len>>ch;
    cin.get();
    getline(cin,s);
    if (len<s.size()){
        for (int i=s.size()-len;i<s.size();i++)
            cout<<s[i];
    }
    else{
        for (int i=0;i<len-s.size();i++)
            cout<<ch;
        cout<<s;
    }
    return 0;
}
