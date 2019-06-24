#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
void solve1(string);
void solve2(string,int);
void solve3(string,int);
void solve4(string);
int main(){
    string s;
    getline(cin,s);
    int i;
    for (i=0;i<s.length();i++)
    if (s[i]=='/'){
        solve2(s,i);
        break;
    }
    else if (s[i]=='%'){
        solve4(s);
        break;
    }
    else if (s[i]=='.'){
        solve3(s,i);
        break;
    }
    if (i==s.length())
        solve1(s);
    return 0;
}
void solve1(string s){
    reverse(s.begin(),s.end());
    while(s[0]=='0'){
        s.erase(0,1);
    }
    if (s=="")
        s="0";
    cout<<s<<"\n";
}
void solve2(string s,int x){
    string s1=s.substr(0,x);
    string s2=s.substr(x+1,s.length());
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    while(s1[0]=='0'){
        s1.erase(0,1);
    }
    while(s2[0]=='0'){
        s2.erase(0,1);
    }
    if (s1=="")
        s1="0";
    if (s2=="")
        s2="0";
    cout<<s1<<"/"<<s2<<"\n";
}
void solve3(string s,int x){
    string s1=s.substr(0,x);
    string s2=s.substr(x+1,s.length());
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    while(s1[0]=='0'){
        s1.erase(0,1);
    }
    while(*(s2.end()-1)=='0'){
        s2.erase(s2.length()-1,1);
    }
    if (s1=="")
        s1="0";
    if (s2=="")
        s2="0";
    cout<<s1<<"."<<s2<<"\n";
}
void solve4(string s){
    string s1=s.substr(0,s.length()-1);
    reverse(s1.begin(),s1.end());
    while(s1[0]=='0'){
        s1.erase(0,1);
    }
    if (s1=="")
        s1="0";
    cout<<s1<<"%"<<"\n";
}
