#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int Tree[3*maxn];
int n;
int a[maxn];
int b[maxn];
int c[maxn];
int d[maxn];
int lowbit(int x)
{
    return x&(-x);
}
void add(int i,int value)
{
    for(int k = i; k <= maxn; k += lowbit(k))
    {
        Tree[k] += value;
    }
}
int sum(int i)
{
    int ans = 0;
    for(int k = i; k >= 1; k -= lowbit(k))
    {
        ans += Tree[k];
    }
    return ans;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int ca = 1; ca <= T; ca++)
    {
        scanf("%d",&n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d",&a[i]);
        }
        memset(Tree,0,sizeof(Tree));
        for(int i = 1; i <= n; i++)
        {
            add(a[i],1);
            b[a[i]] = sum(a[i] - 1);
            c[a[i]] = min(a[i],i);
            d[a[i]] = max(a[i],a[i] - 1 - b[a[i]] + i);
        }
        printf("Case #%d:",ca);
        for(int i = 1; i <= n; i++)
        {
            printf(" %d",abs(d[i] - c[i]));
        }
        printf("\n");
    }
    return 0;
}
