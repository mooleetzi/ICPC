#include<bits/stdc++.h>
using namespace std;
const int maxn = 60;
struct node
{
    int p, w;
    /* data */
}t[maxn];

int n,s;
int ans=1e9;
int b[maxn];
void dfs(int now,int s,int cnt,int time)
{
    if (cnt>=n){
        ans = min(ans, s);
        return;
    }
    if (s>ans)
        return;
}
int main(int argc, char const *argv[])
{
    cin >> n>>s;
    for (int i = 1; i <= n;i++)
        cin >> t[i].p >> t[i].w;
    b[s] = 1;
    dfs(s, 0, 1,0);
    cout << ans;
    return 0;
}
