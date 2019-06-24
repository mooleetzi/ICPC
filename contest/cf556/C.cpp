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
int a[maxn];
int is_prime(int x){
    if (x==2)
        return 1;
    if (x==1||x==0)
        return 0;
    for (int i = 2; i < sqrt(x)+1; i++)
        if (x%i==0)
            return 0;
    return 1;
}
int o, t;
int main(int argc, char const *argv[])
{
    n = read();
    for (int i = 1; i <= n;i++){
        int x = read();
        if (x==1)
            ++o;
        else
        {
            ++t;
        }
    }
    int pre = 0;
    for (int i = 0; i < n; i++)
    {
        if (t && is_prime(pre + 2))
        {
            a[i] = 2;
            --t;
            pre += 2;
            continue;
        }
        else if (o && is_prime(pre + 1))
        {
            a[i] = 1;
            --o;
            pre += 1;
            continue;
        }
        if (t)
        {
            pre += 2;
            a[i] = 2;
            --t;
        }
        else if (o)
        {
            pre += 1;
            a[i] = 1;
            --o;
        }
    }
        for (int i = 0; i < n;i++)
            printf("%d ", a[i]);
        return 0;
}
