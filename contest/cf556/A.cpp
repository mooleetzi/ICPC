#include <bits/stdc++.h>
#define gcd __gcd
using ll = long long;
using namespace std;
using pa = pair<int, int>;
const int maxn = 4e5 + 10;
vector<pa> v;
inline int read()
{
    register int f = 1, ans = 0;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        ans = (ans << 1) + (ans << 3) + ch - 48;
        ch = getchar();
    }
    return ans * f;
}
int n, m;
int a[maxn], b[maxn];
int main(int argc, char const *argv[])
{
    n = read();
    m = read();
    int r = read();
    for (int i = 0; i < n;i++)
        a[i] = read();
    for (int i = 0; i < m;i++)
        b[i] = read();
    int minx = *min_element(a, a + n);
    int maxx = *max_element(b, b + m);
    /*sb self m!!!n*/
    if (minx>=maxx){
        cout << r;
        return 0;
    }
    int k = r / minx;
    r %= minx;
    r += k * maxx;
    cout << r;
    return 0;
}
