//2500ms t了半天
//next_permutation爆搜
//加了输入挂2418ms险过
//当前位置还原初始位置，超过k直接跳过，没有则更新答案
//神了
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 10;
const int inf = 0x3f3f3f3f;
int n, k;
int pos[maxn];
int a[maxn], b[maxn], c[maxn];
int d[maxn];
inline int read()
{
    int ans = 0;
    char ch = getchar();
    while (isdigit(ch))
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans;
}
void print(int *d, int l)
{
    for (int i = 0; i < 10; i++)
        b[i] = a[i] = 0;
    for (int i = 0; i < l; i++)
        ++b[d[i]], ++a[d[i]];
    for (int i = 0; i < l; i++)
    {
        if (!i)
            for (int j = 1; j < 10; j++)
            {
                if (b[j])
                {
                    printf("%d", j);
                    --b[j];
                    break;
                }
            }
        else
        {
            for (int j = 0; j < 10; j++)
                if (b[j])
                {
                    printf("%d", j);
                    --b[j];
                    break;
                }
        }
    }
    printf(" ");
    for (int i = 0; i < l; i++)
        for (int j = 9; j > -1; j--)
            if (a[j])
            {
                --a[j];
                printf("%d", j);
                break;
            }
    printf("\n");
}
int main(int argc, char const *argv[])
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int t = read();
    // cin >> t;
    // scanf("%d", &t);
    while (t--)
    {
        // cin >> n >> k;
        // scanf("%d%d", &n, &k);
        n = read(), k = read();
        int tmp = n;
        int tot = 0;
        while (tmp)
        {
            d[tot++] = tmp % 10;
            tmp /= 10;
        }
        for (int i = 0; i < tot / 2; i++)
            swap(d[i], d[tot - i - 1]);
        int l = tot;
        if (k >= l - 1)
        {
            print(d, l);
            continue;
        }
        int minx = inf, maxx = -inf;
        for (int i = 0; i < l; i++)
            c[i] = i;
        do
        {
            int ans = 0;
            if (d[c[0]] == 0)
                continue;
            int cnt = 0;
            int f = 1;
            for (int i = 0; i < l; i++)
                pos[i] = c[i];
            for (int i = 0; i < l && f; i++)
            {
                if (pos[i] != i)
                {
                    for (int j = i + 1; j < l; j++)
                        if (pos[j] == i)
                        {
                            swap(pos[i], pos[j]);
                            ++cnt;
                            if (cnt > k)
                            {
                                f = 0;
                                break;
                            }
                        }
                }
            }
            if (f)
            {
                for (int i = 0; i < l; i++)
                    ans = ans * 10 + d[c[i]];
                minx = min(minx, ans);
                maxx = max(maxx, ans);
            }

        } while (next_permutation(c, c + l));
        printf("%d %d\n", minx, maxx);
    }
    return 0;
}
