#include<bits/stdc++.h>
#define cal(x,y) (x-y)/2-1
using namespace std;
const int maxn=2010;
int ishw(string s){
    for (int i=0;i<s.length();i++)
        if (s[i]!=s[s.length()-1-i])
            return (i+1);
    return -1;
}
int res(int n,int m,int p,int q){
    int ans=0;
    int nn=min((m-q)/2,(n-p)/2);
    for(int i=0;i<nn;i++){
        ans++;
        ans+=(cal(m,(q+2*i))+cal(n,(p+2*i)));
    }
    return ans;
}

string s[maxn];
int main(){
    ios::sync_with_stdio(false);
    int t,n,m;
    cin>>t;
    while(t--){
        int f1=0,f2=0;
        cin>>n>>m;
        int minh=maxn,minw=maxn,minh2=maxn,minw2=maxn;
        for (int i=1;i<=n;i++){
            cin>>s[i];
            int q=ishw(s[i]);
            if (q==-1)
                continue;
            if (q!=-1)
                f1=1;
            minh=min(minh,i);
            minw=min(minw,q);
        }
        for (int i=0;i<m;i++){
            string now;
            for (int j=1;j<=n;j++)
                now+=s[j][i];
            int q=ishw(now);
            if (q==-1){
                continue;
            }
            if (q!=-1)
                f2=1;
            minh2=min(minh2,q);
            minw2=min(minw2,i+1);
        }
        int p1,p2,q1,q2;
        //cout<<minh<<" "<<minw<<"\n";
        int ans=0;
        int a=min(minh,n-minh+1);
        int b=max(minh,n-minh+1);
        int z=min(minw,m-minw+1);
        int x=max(minw,m-minw+1);
        p1=b-a+1;
        q1=x-z+1;
        a=min(minh2,n-minh2+1);
        b=max(minh2,n-minh2+1);
        z=min(minw2,m-minw2+1);
        x=max(minw2,m-minw2+1);
        p2=b-a+1;
        q2=x-z+1;
        if (f1==0){
            p1=q1=2;
        }
        if (f2==0)
            p2=q2=2;
        int p,q;
        p=max(p1,p2);
        q=max(q1,q2);
//        cout<<p1<<" "<<q1<<"\n";
//        cout<<p2<<" "<<q2<<"\n";
//        cout<<p<<" "<<q<<"\n";
        ans=res(n,m,p,q);
        cout<<ans<<"\n";
    }
    return 0;
}
