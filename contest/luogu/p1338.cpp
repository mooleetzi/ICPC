#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e4 + 10;
struct fenwick
{
    int c[maxn]={0};
    int lowbit(int x){
        return x & (-x);
    }
    void add(int x){
        while (x<maxn)
        {
            ++c[x];
            x += lowbit(x);
        }
    }
    int query(int x){
        int ans = 0;
        while (x)
        {
            ans += c[x];
            x -= lowbit(x);
        }
        return ans;
    }
    /* data */
};

int a[maxn];
int pre[maxn];
int n, m;
int main(int argc, char const *argv[])
{

    cin >> n>>m;
    int cnt = 0;
    for (int i = 1; i <= n;i++)
        pre[i] = (i-1)* i / 2;
    for (int i = 1; i <= n;i++)
        if (pre[i]>m){
            cnt = i - 1;
            break;
        }
    for (int i = 1; i <= n - cnt;i++)
        a[i] = i;
    for (int i = 1; i <=cnt;i++)
        a[n-cnt+i] =n-i+1;
    
    return 0;
}
