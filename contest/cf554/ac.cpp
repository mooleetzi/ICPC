
#include <bits/stdc++.h>
#define exp 1e-8
#define mian main
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ll long long
#define pb push_back
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define w(x) while (x--)
#define int_max 2147483647
#define lowbit(x) (x) & (-x)
#define gcd(a, b) __gcd(a, b)
#define pq(x) priority_queue<x>
#define ull unsigned long long
#define sc(x) scanf("%d", &x)
#define scl(x) scanf("%lld", &x)
#define pl(a, n) next_permutation(a, a + n)
#define ios ios::sync_with_stdio(false)
#define met(a, x) memset((a), (x), sizeof((a)))
using namespace std;
int n, ans, a[32];
int f(int n)
{
    int res = n;
    int pos = 0;
    int t = 1;
    while (res)
    {
        if ((res & 1) == 0)
            pos = t;
        t++;
        res >>= 1;
    }
    return pos;
}
int main()
{
    for (int i = 0; i <= 31; i++)
        a[i] = (1 << i) - 1;
    while (~scanf("%d", &n))
    {
        ans = 0;     //ans记录步骤数
        int num = 0; //记录要进行异或的数
        while (1)
        {
            int pos = f(n);
            if (pos == 0)
                break;
            ans++;
            num++;
            bool flag = false;
            a[num] = pos;
            n ^= (1 << pos) - 1;
            for (int i = 0; i <= 31; i++)
                if (a[i] == n)
                {
                    flag = true;
                    break;
                }
            if (flag)
                break;
            n++;
            ans++;
        }
        printf("%d\n", ans);
        for (int i = 1; i <= num; i++)
        {
            if (i == ans)
                printf("%d", a[i]);
            else
                printf("%d ", a[i]);
        }
        if (ans != 0)
            printf("\n");
    }
}