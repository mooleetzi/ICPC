#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1e5 + 10;
int fa[maxn], rnk[maxn];
vector<int> h[maxn];
vector<int> wolf;
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
    // if (rnk[x] > rnk[y])
    //     fa[y] = x;
    // else
    // {
    //     fa[x] = y;
    //     if (rnk[x] == rnk[y])
    //         ++rnk[y];
    // }
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
        wolf.clear();
        n = read();
        // memset(rnk, 0, sizeof(int) * (n + 1));
        for (int i = 1; i <= n; i++)
            fa[i] = i;
        for (int i = 1; i <= n; i++)
            h[i].clear();
        for (int i = 1; i <= n; i++)
        {
            int x;
            char s[10];
            scanf("%d%s", &x, s);
            if (s[0] == 'w')
            {
                if (find(i) == find(x))
                    wolf.emplace_back(x);
            }
            if (s[0] == 'v')
            {
                h[x].emplace_back(i);
                merge(x, i);
            }
        }
        for (int i = 0; i < wolf.size(); i++)
            for (int j = 0; j < h[wolf[i]].size(); j++)
                wolf.emplace_back(h[wolf[i]][j]);
        printf("0 %u", wolf.size());
    }
    return 0;
}
