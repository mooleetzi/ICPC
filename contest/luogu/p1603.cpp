#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int> ma;
void init(){
    string s="one two three four five six seven eight nine ten eleven twelve thirteen fourteen fifteen sixteen seventeen eighteen nineteen twenty";
    string a[30];
    int last=0;
    int tot=0;
    for (int i=0;i<s.size();i++){
        if (s[i]==' '){
            a[tot++]=s.substr(last,i-last);
            last=i+1;
        }
    }
    a[tot++]=s.substr(last,6);
    for (int i=0;i<tot;i++)
        ma[a[i]]=i+1;
    ma["a"]=1;
    ma["both"]=2;
    ma["another"]=3;
    ma["first"]=1;
    ma["second"]=2;
    ma["third"]=3;
}
string a[7];
int tot=0;
int main(){
    init();
    for (int i=0;i<6;i++){
        string now;
        cin>>now;
        transform(now.begin(),now.end(),now.begin(),::tolower);
        if (ma[now]){
            int cur=ma[now]*ma[now]%100;
            if (cur<10){
                stringstream ss;
                ss<<0<<cur;
                a[tot++]=ss.str();
            }
            else{
                stringstream ss;
                ss<<cur;
                a[tot++]=ss.str();
            }
        }
    }
    unsigned long long minx=1e13;
    sort(a,a+tot);
    do{
        string now="";
        for (int i=0;i<tot;i++)
            now+=a[i];
        cout<<now<<"\n";
        unsigned long long cur=0;
        for (int i=0;i<now.size();i++)
            cur=cur*10+now[i]-48;
        if (cur<minx)
            minx=cur;
    }while(next_permutation(a,a+tot));
    if (!tot)
        cout<<"0";
    else
        cout<<minx;
    return 0;
}
