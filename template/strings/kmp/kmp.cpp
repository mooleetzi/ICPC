#include<bits/stdc++.h>
#define N 10000
using namespace std;
string s,t;
int next[N];
void getnext();
int kmp_first();
int kmp_count();
int main(){
    while(cin>>s>>t){
        cout<<kmp_first()<<"\n";
        cout<<kmp_count()<<"\n";
    }
    return 0;
}
void getnext(){
    int j,k,len=t.length();
    j=-1;
    k=0;
    next[0]=-1;
    while(k<len){
        if (j==-1||t[k]==t[j])
            if (t[++k]!=t[++j])
                next[j]=k;//计数时如果要考虑相同字符可抵消，则这样写 否则不然
            else
                next[j]=next[k];
        else
            k=next[k];
    }
}
int kmp_first(){
    int al=s.length();
    int bl=t.length();
    int i=0,j=0;
    memset(next,0,sizeof next);
    getnext();
    while(i<al&&j<bl){
        if (j==-1||s[i]==t[j]){
            i++;
            j++;
        }
        else
            j=next[j];
    }
    if (j==bl)
        return i-bl;
    return -1;
}
int kmp_count(){
    int ans=0;
    int al=s.length();
    int bl=t.length();
    int i=0,j=0;
    memset(next,0,sizeof next);
    getnext();
    while(i<al&&j<=bl){
        if (j==-1||s[i]==t[j]){
            i++;
            j++;
        }
        else
            j=next[j];
        if (j==bl)
            ans++;
    }
    return ans;
}
