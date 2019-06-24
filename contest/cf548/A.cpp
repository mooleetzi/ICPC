#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
using ll = long long;
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
char s[maxn];
inline int isEven(char c){
    return !((c - 48) & 1);
}
int main(int argc, char const *argv[])
{
    n = read();
    cin >> s;
    ll ans = 0;
    for (int i = 0; i < n;i++)
        if (isEven(s[i]))
            ans += i + 1;
    cout << ans;
    return 0;
}
