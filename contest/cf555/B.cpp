#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
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
int f[10];
int main(int argc, char const *argv[])
{
    int n=read();
    cin >> s;
    for (int i = 1; i <= 9;i++)
        f[i] = read();
    int ff = 0;
    int st;
    for (int i = 0; i < n; i++)
    {
        int now = s[i] - '0';
        if (f[now]>now){
            ff = 1;
            st = i;
            break;
        }
    }
    if (!ff){
        cout << s << "\n";
        return 0;
    }
    for (int i = 0; i < st; i++)
    {
        cout << s[i];
    }
    for (int i = st; i < n;i++){
        int now = s[i] - '0';
        st = i;
        if (f[now] >= now){
            cout << f[now];
            ++st;
        }
        else
        {

            break;
        }
    }
    // cout << st << "\n";
    for (int i = st; i < n; i++)
        cout << s[i];
    return 0;
}
