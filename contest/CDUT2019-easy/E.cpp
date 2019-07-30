//在一个升序的容器里，如果所有元素都大于i则，upp和low都返回begin。都小于i则返回end（越界了）。
//注意数据范围
#include <bits/stdc++.h>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pa = pair<int, int>;
using ld = long double;
const int maxn = 1e5 + 10;
int n, m, k;
template <class T>
inline void read(T &ret)
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
struct item
{
    int s, e;
    item() {}
    item(int ss, int ee) : s(ss), e(ee) {}
    bool operator<(const item &a) const
    {
        return s < a.s;
    }
};
vector<item> v;
multiset<ll> s;
int main(int argc, char const *argv[])
{
    int t;
    read(t);
    while (t--)
    {
        v.clear();
        s.clear();
        read(n);
        for (int i = 0; i < n; i++)
        {
            int s, e;
            read(s), read(e);
            v.emplace_back(item(s, e));
        }
        sort(v.begin(), v.end());
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            item cur = v[i];
            auto f = s.upper_bound(cur.s);
            if (f == s.begin())
            {
                s.insert(cur.e);
                ans += cur.e - cur.s;
            }
            else
            {
                f--;
                ans += cur.e - *f;
                s.erase(f);
                s.insert(cur.e);
            }
        }
        cout << s.size() << " " << ans << "\n";
    }
    return 0;
}
