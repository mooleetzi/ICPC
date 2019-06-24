#include<iostream>
#include<cstring>
using namespace std;
const int maxn=1e6+100;
const int maxm=1e4+10;
int nxt[maxm],a[maxm],b[maxn];
void getNext(int next[],int l){
    int i=0,j=-1;
    next[0]=-1;
    while(i<l){
        while(j!=-1&&a[i]!=a[j]) j=next[j];
        next[++i]=++j;
    }
}
int kmp(int l1,int l2){
    getNext(nxt,l1);
    int i=0,j=0;
    while(j<l2){
        while(i!=-1&&a[i]!=b[j]) i=nxt[i];
        i++,j++;
        if (i>=l1)
            return j-i+1;
    }
//    if (i==l2)
//        return j-i+1;
    return -1;
}
int main(){
    int t;
    ios::sync_with_stdio(false);
    //cin.tie(0);
    cin>>t;
    while(t--){
        int n,m;
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        memset(nxt,0,sizeof nxt);
        cin>>n>>m;
        for (int i=0;i<n;i++)
            cin>>b[i];
        for (int i=0;i<m;i++)
            cin>>a[i];
        cout<<kmp(m,n)<<"\n";
    }
    return 0;
}
