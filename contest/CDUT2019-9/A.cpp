#include <bits/stdc++.h>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pa = pair<int, int>;
using ld = long double;
ll n, m, k;
const int maxn = 1e6 + 10;
const int mod = 998244353;
template <class T>
inline T read(T &ret)
{
    int f = 1;
    ret = 0;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        ret = (ret << 1) + (ret << 3) + ch - '0';
        ch = getchar();
    }
    ret *= f;
    return ret;
}
template <class T>
inline void write(T n)
{
    if (n < 0)
    {
        putchar('-');
        n = -n;
    }
    if (n >= 10)
    {
        write(n / 10);
    }
    putchar(n % 10 + '0');
}

int main(int argc, char const *argv[])
{
    int ans = 0;
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    do
    {
        int tmp[3][3];
        for (int i = 0; i < 9; i++)
            tmp[i / 3][i % 3] = a[i];
        int cnt = 0;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
            {
                vector<int> t;
                t.clear();
                for (int k = 0; k < 3; k++)
                {
                    if (k != i)
                        t.emplace_back(tmp[k][j]);
                    if (k != j)
                        t.emplace_back(tmp[i][k]);
                }
                t.emplace_back(tmp[i][j]);
                sort(t.begin(), t.end());
                if (*max_element(t.begin(), t.end()) == tmp[i][j])
                    ++cnt;
            }
        if (cnt == 1)
            ++ans;
    } while (next_permutation(a, a + 9));
    cout << ans << "\n";
    return 0;
}
