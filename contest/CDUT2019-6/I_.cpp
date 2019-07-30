//对于狼，若A->B好，B->C好,C->D好,D->A狼 则A铁狼
//若A狼，B->A好，B铁狼
//对于村民，不存在确切为村民的情况，固村民全0
#include <cstring>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
const int maxn = 1e5 + 10;
using pa = pair<int, int>;
int fa[maxn], rnk[maxn];
vector<int> h[maxn], w[maxn];
int wolf[maxn];
vector<pa> ww;
int n;
int find(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}
void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y)
        fa[x] = y;
}
inline int read()
{
    char ch = getchar();
    int f = 1;
    int ret = 0;
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        ret = ret * 10 + ch - '0';
        ch = getchar();
    }
    return ret * f;
}

int main(int argc, char const *argv[])
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        ww.clear();
        n = read();
        for (int i = 1; i <= n; i++)
            fa[i] = i, wolf[i] = 0;
        for (int i = 1; i <= n; i++)
            h[i].clear(), w[i].clear();
        for (int i = 1; i <= n; i++)
        {
            int x;
            char s[10];
            scanf("%d%s", &x, s);
            if (s[0] == 'w')
            {
                w[x].emplace_back(i);
                ww.emplace_back(pa(i, x));
            }
            if (s[0] == 'v')
            {
                h[x].emplace_back(i);
                merge(x, i);
            }
        }
        queue<int> p;
        while (!p.empty())
            p.pop();
        unsigned ans = 0;
        for (auto q : ww)
        {
            int from = q.first;
            int to = q.second;
            if (find(from) == find(to))
            {
                ++ans;
                p.emplace(to);
                while (!p.empty())
                {
                    int now = p.front();
                    p.pop();
                    for (int i = 0; i < h[now].size(); i++)
                    {
                        p.emplace(h[now][i]);
                        ++ans;
                    }
                }
            }
        }
        printf("0 %u\n", ans);
    }
    return 0;
}
