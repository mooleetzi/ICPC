// #include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
// using ll = long long;
// using ull = unsigned long long;
// using pa = pair<int, int>;
// using ld = long double;
typedef long long ll;
const int maxn = 5100;
const int mod = 100000007;
char s[maxn];
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}
int main(int argc, char const *argv[])
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int t;
    cin >> t;
    getchar();
    while (t--)
    {
        int ans = 0;
        gets(s);
        int cur = 0;
        int sz = strlen(s);
        vector<int> aa;
        aa.clear();
        for (int i = 0; i < sz; i++)
        {
            int sum = 0;
            while (i < sz && s[i] != ' ')
            {
                sum = sum * 10 + s[i] - '0';
                i++;
            }
            aa.push_back(sum);
        }

        sz = aa.size();
        for (int i = 0; i < sz - 1; i++)
            for (int j = i + 1; j < sz; j++)
                ans = max(ans, gcd(aa[i], aa[j]));
        cout << ans << "\n";
    }
    return 0;
}
