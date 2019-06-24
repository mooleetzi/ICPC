#include<bits/stdc++.h>
using namespace std;
unordered_map<char,char> ma1,ma2;
set<char> s;
string s1,s2,s3;
int main(){
    cin>>s1>>s2>>s3;
    int flag=1;
    for (int i=0;i<s1.size();i++){
        if ((ma1[s1[i]]&&s2[i]!=ma1[s1[i]])||(ma2[s2[i]]&&s1[i]!=ma2[s2[i]]))
            flag=0;
        ma1[s1[i]]=s2[i];
        ma2[s2[i]]=s1[i];
    }
    string ans="";
    for (int i=0;i<s3.size();i++){
        if (ma1[s3[i]])
            ans+=ma1[s3[i]];
        else
            flag=0;
    }
    for (char a='A';a<='Z';a++)
        if (!ma2[a])
            flag=0;
    if (flag)
        cout<<ans;
    else
        cout<<"Failed";
    return 0;
}
