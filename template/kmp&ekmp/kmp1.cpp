#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
char p[maxn],s[maxn];
int nxt[maxn];
void getNext(){
    memset(nxt,0,sizeof nxt);
    nxt[0]=-1;
    int i=0,j=-1;
    int l1=strlen(p);
    while(i<l1){
        while(j!=-1&&p[i]!=p[j]) j=nxt[j];
        nxt[++i]=++j;
    }
}
int kmp(){
    int l1=strlen(p);
    int l2=strlen(s);
    int i=0,j=0,ans=0;
    cout<<p<<" "<<s;
    while(j<l2){
        while(i!=-1&&p[i]!=s[j]) i=nxt[i];
        i++,j++;
        if (i>=l1){
            ans++;
            i=nxt[i];
        }
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    //cin.tie(0);
    while(cin>>p>>s){
//        getNext();
        cout<<" "<<kmp()<<"\n";
    }
    return 0;
}
