#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, m, sa[maxn], rk[maxn], tp[maxn], tax[maxn], p;
int height[maxn], T;
char s[maxn];
long long ans;
void Qsort()
{
    for (int i = 0; i <= m; i++)
        tax[i] = 0;
    for (int i = 1; i <= n; i++)
        tax[rk[i]]++;
    for (int i = 1; i <= m; i++)
        tax[i] += tax[i - 1];
    for (int i = n; i >= 1; i--)
        sa[tax[rk[tp[i]]]--] = tp[i];
}
void get_height(int n)
{
    int k = 0, j;
    for (int i = 1; i <= n; i++)
    {
        j = sa[rk[i] - 1];
        if (k)
            k--;
        while (s[j + k] == s[i + k])
            k++;
        height[rk[i]] = k;
    }
}
int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++)
        rk[i] = s[i] - '0', tp[i] = i;
    m = 105;
    Qsort();
    for (int ws = 1, p = 0; p < n; m = p, ws <<= 1)
    {
        p = 0;
        for (int i = 1; i <= ws; i++)
            tp[++p] = n - ws + i;
        for (int i = 1; i <= n; i++)
            if (sa[i] > ws)
                tp[++p] = sa[i] - ws;
        Qsort();
        swap(tp, rk);
        rk[sa[1]] = p = 1;
        for (int i = 2; i <= n; i++)
        {
            rk[sa[i]] = (tp[sa[i - 1]] == tp[sa[i]] && tp[sa[i - 1] + ws] == tp[sa[i] + ws]) ? p : ++p;
        }
    }
    get_height(n);
    ans = 0;
    for (int i = 1; i <= n; i++)
        ans += n + 1 - sa[i] - height[i];
    printf("%lld\n", ans);
    return 0;
}