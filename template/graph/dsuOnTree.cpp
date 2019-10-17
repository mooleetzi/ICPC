/*
    cf600e 求每个节点子树中出现次数最多的编号之和
    dsu on tree模板题
*/
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 1e5 + 10;
inline int read()
{
    char c = getchar();
    int x = 0, f = 1;
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
        x = x * 10 + c - '0', c = getchar();
    return x * f;
}
int N, col[MAXN], son[MAXN], siz[MAXN], cnt[MAXN], Mx, Son;
LL sum = 0, ans[MAXN];
vector<int> v[MAXN];
void dfs(int x, int fa)
{
    siz[x] = 1;
    for (int i = 0; i < v[x].size(); i++)
    {
        int to = v[x][i];
        if (to == fa)
            continue;
        dfs(to, x);
        siz[x] += siz[to];
        if (siz[to] > siz[son[x]])
            son[x] = to; //轻重链剖分
    }
}
void add(int x, int fa, int val)
{
    cnt[col[x]] += val; //因题目而异
    if (cnt[col[x]] > Mx)
        Mx = cnt[col[x]], sum = col[x];
    else if (cnt[col[x]] == Mx)
        sum += (LL)col[x];
    for (int i = 0; i < v[x].size(); i++)
    {
        int to = v[x][i];
        if (to == fa || to == Son)
            continue;
        add(to, x, val);
    }
}
void dfs2(int x, int fa, int opt)
{
    int sz = v[x].size();
    for (int i = 0; i < sz; i++)
    {
        int to = v[x][i];
        if (to == fa)
            continue;
        if (to != son[x])
            dfs2(to, x, 0); //暴力统计轻边的贡献，opt = 0表示递归完成后消除对该点的影响
    }
    if (son[x])
        dfs2(son[x], x, 1), Son = son[x]; //统计重儿子的贡献，不消除影响
    add(x, fa, 1);
    Son = 0;      //暴力统计所有轻儿子的贡献
    ans[x] = sum; //更新答案
    if (!opt)
        add(x, fa, -1), sum = 0, Mx = 0; //如果需要删除贡献的话就删掉
}
int main()
{
    N = read();
    for (int i = 1; i <= N; i++)
        col[i] = read();
    for (int i = 1; i <= N - 1; i++)
    {
        int x = read(), y = read();
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1, 0);
    dfs2(1, 0, 0);
    for (int i = 1; i <= N; i++)
        printf("%I64d ", ans[i]);
    return 0;
}