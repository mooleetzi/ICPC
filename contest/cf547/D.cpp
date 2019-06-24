#include <bits/stdc++.h>
#define gcd __gcd
using ll = long long;
using namespace std;
const int maxn = 150010;
using pa = pair<int, int>;
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
char l[maxn], r[maxn];
int vis[maxn];
multimap<char, int> lt;
vector<pa> v;
vector<int> res1;
set<int> res2;
int main(int argc, char const *argv[])
{
    n = read();
    char ch = getchar();
    int t = 0;
    while (isalpha(ch)||ch=='?')
    {
        *(l + t++) = ch;
        ch = getchar();
    }
    ch = getchar();
    t = 0;
    while (isalpha(ch)||ch=='?')
    {
        *(r + t++) = ch;
        ch = getchar();
    }
    for (int i = 0;i<n;i++){
        lt.insert(make_pair(l[i], i + 1));
        res2.insert(i + 1);
    }
    int ans = 0;
    for (int i = 0; i < n;i++){
        if (r[i]=='?'){
            res1.emplace_back(i + 1);
            continue;
        }
        auto begin = lt.equal_range(r[i]).first;
        auto end = lt.equal_range(r[i]).second;
        if (begin==end){
            begin = lt.equal_range('?').first;
            end = lt.equal_range('?').second;
            if (begin==end)
                continue;
            else
            {
                v.emplace_back(pa(begin->second, i + 1));
                res2.erase(begin->second);
                lt.erase(begin);
                ++ans;
            }
        }
        else
        {
            v.emplace_back(pa(begin->second, i + 1));
            res2.erase(begin->second);
            lt.erase(begin);
            ++ans;
        }
    }
    for (auto x:res1){
        if (!res2.empty()){
            ++ans;
            v.emplace_back(pa(*res2.begin(), x));
            res2.erase(res2.begin());
        }
    }
    cout << ans << "\n";
    for (auto x:v)
        cout << x.first << " " << x.second << "\n";
    return 0;
}
