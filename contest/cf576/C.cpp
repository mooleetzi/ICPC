//注意数据范围
//log是自然对数 log2才是！！！
#include <bits/stdc++.h>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pa = pair<int, int>;
using ld = long double;
ll n, m, k;
const int maxn = 4e5 + 10;
const int inf = 0x3f3f3f3f;
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
vector<int> a(maxn);
map<int, int> mp;
set<int> s;
struct node
{
    int x, tot;
    node() {}
    node(int x, int tot)
    {
        this->x = x;
        this->tot = tot;
    }
};
int main(int argc, char const *argv[])
{
    read(n);
    read(m);
    ll bits = m * 8; //总的字节数
    m = bits / n;    //一个元素可以占的字节数
    ld tmp = log2(n);
    for (int i = 0; i < n; i++)
    {
        read(a[i]);
        ++mp[a[i]];
        s.insert(a[i]);
    }
    ll ans = 0;
    if (m >= tmp)
    {
        write(0);
        putchar('\n');
        return 0;
    }
    ull t = 1 << m;
    auto now = s.begin();
    ll cnt = 0;
    ull tot = 0;
    deque<int> dq;
    dq.clear();
    for (auto x : s)
    {
        ++tot;              //不同元素个数
        dq.emplace_back(x); //保存状态
        cnt += mp[x];       //不同元素总的个数
        if (tot > t)
        {
            if (!ans)
                ans = inf;
            --tot;
            cnt -= mp[dq.front()];
            dq.pop_front();
            ans = min(n - cnt, ans);
        }
    }
    write(ans);
    return 0;
}
