#include<bits/stdc++.h>
using namespace std;
const int max_vet=256;
const int inf=1e6+100;
const int inf2=1e4+1;
int s[inf],p[inf2],a[inf2];
void kmp(int s[],int p[],int next[]);
int slen,plen;
int main(){
    int t;
    cin>>t;
    while(t--){
        memset(p,0,sizeof(p));
        memset(s,0,sizeof(s));
        memset(a,0,sizeof(a));
        cin>>slen>>plen;
        for (int i=0;i<slen;i++)
            cin>>s[i];
        for (int i=0;i<plen;i++)
            cin>>p[i];
        kmp(s,p,a);
    }
    return 0;
}
void kmp(int s[],int p[],int next[]){
    //memset(next,0,sizeof(next));
    next[0]=-1;
    int i,j,k,ans=-1;
    i=0;k=-1;
    while(i<plen-1){
        if (k==-1||p[i]==p[k]){
            i++;
            k++;
//            if (p[k]!=p[i])
                next[i]=k;
//            else
//                next[i]=next[k];
        }
        else
            k=next[k];
    }
    i=0;
    j=0;
    while(i<slen&&j<plen){
            if (j==-1||p[j]==s[i]){
                i++;
                j++;
            }
            else
                j=next[j];
    }
    if (j==plen)
        ans=i-j;
    if (ans!=-1)
        cout<<ans+1<<endl;
    else
        cout<<-1<<endl;
}
