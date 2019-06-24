/*
    multiset的使用 lower_bound的使用
    返回最接近k的一个值(>=)
*/
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
int a[maxn], c[maxn];
multiset<int> s;
int main(int argc, char const *argv[])
{
    n = read();
    for (int i = 0; i < n;i++)
        a[i] = read();
    for (int i = 0;i<n;i++){
        s.insert(read());
    }
    for (int i = 0;i<n;i++){
        int cur = n - a[i];
        auto now = s.lower_bound(cur);
        if (now!=s.end()){
            c[i] = (*now + a[i]) % n;
        }
        else
        {
            now = s.begin();
            c[i] = (*now + a[i]) % n;
        }
        s.erase(now);
    }
    for (int i = 0; i < n;i++)
        cout << c[i] << " ";
    return 0;   
}
