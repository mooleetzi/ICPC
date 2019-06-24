#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=2e5+10;
const string s[]={"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};
char m[maxn];
int isOk(string now){
    int cnt=0,flag=0;
    char op=now[now.length()-1];
    for (int i=0;i<now.length()-1;i++)
        if (now[i]=='1')
            ++cnt;
    if (cnt&1)
        flag=1;
    if ((!flag&&op=='1')||(flag&&op=='0'))
        return 1;
    return 0;
}
string doit(char p[],int l){
    string ans="";
    string op="";
    int cnt=0;
    for (int i=0;i<l;i++)
        if (p[i]>='0'&&p[i]<='9')
            op+=s[p[i]-'0'];
        else{
            if (p[i]>=65&&p[i]<=90)
                op+=s[p[i]-'A'+10];
            else
                op+=s[p[i]-'a'+10];
        }
    int now=0;
    while(now+9<op.length()){
        string q="";
        for (int i=now;i<now+9;i++)
            q+=op[i];
        //cout<<q<<"\n";
        if (isOk(q)){
            q.erase(q.length()-1,1);
            ans+=q;
        }
        now+=9;
    }
    string q="";
    for (int i=now;i<op.length();i++)
        q+=op[i];
    if (isOk(q)){
        q.erase(q.length()-1,1);
        ans+=q;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>m;
    cout<<doit(m,strlen(m)).length()<<" "<<doit(m,strlen(m));
    return 0;
}
