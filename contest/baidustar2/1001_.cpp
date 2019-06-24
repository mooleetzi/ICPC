#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int maxn=2e5+10;
inline void read(int &x){char ch=getchar();x=0;for(;ch<'0'||ch>'9';ch=getchar());for(;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-'0';}
inline void readll(long long &x){char ch=getchar();x=0;for(;ch<'0'||ch>'9';ch=getchar());for(;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-'0';}
int fa[maxn],rnk[maxn];
vector<int>ff[maxn];
int find1(int x)
{
    if(x!=fa[x])
        fa[x]=find1(fa[x]);
    return fa[x];
}
void Union(int x,int y)
{
    int r1=find1(x);
    int r2=find1(y);
    if(r1==r2)
        return ;
    if(rnk[r1]<rnk[r2])
        fa[r2]=r1;
    else
    {
        if(rnk[r1]==rnk[r2])
            rnk[r2]++;
        fa[r1]=r2;
    }
}
int main()
{
    int t,n,m,k,a,b;
    int maxx,root,num;
    read(t);
    while(t--)
    {
        read(n);read(m);read(k);
        for(int i=0;i<=n;i++)
            ff[i].clear(),fa[i]=i,rnk[i]=0;
        for(int i=0;i<m;i++)
        {
            read(a);read(b);
            Union(a,b);
            ff[a].push_back(b);
            ff[b].push_back(a);
        }
        maxx=0;num=0;root=0;
        for(int i=0;i<n;i++)
            if(ff[i].size()>maxx)
                maxx=ff[i].size(),root=i;
        int ans=maxx;

        set<int>s;
        for(int i=0;i<n;i++)
            s.insert(find1(i));
        ans+=s.size()-1;
        ans+=k;
        ans=min(ans,n-1);
        printf("%d\n",ans);
    }
    return 0;
}
