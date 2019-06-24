#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, m;
int a[maxn];
int pre[maxn][11];
inline int judge(int x)
{
    multiset<int> s1;
    set<int> s2;
    s1.clear(), s2.clear();
    for (int i = 1; i <= 10; i++)
    {
        int t = pre[x][i];
        if (t)
            s1.insert(t), s2.insert(t);
    }
    if (s2.size()>2)
        return false;
    if (s2.size()==1){
        int k = s1.count(*s2.begin());
        return k == 1||*s2.begin()==1;
    }
    int t1 = 0, t2 = 0;
    int x1 = *(s2.begin());//最小出现次数
    s2.erase(s2.begin());
    int x2 = *(s2.begin());//最大出现次数
    s2.erase(s2.begin());
    t1 = s1.count(x1), t2 = s1.count(x2);
    if (t1==1&&x1==1)
        return true;
    if (t2==1&&abs(x1-x2)==1)
        return true;
    return false;
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        for (int j = 1; j <= 10; j++)
            pre[i][j] = pre[i - 1][j];
        ++pre[i][a[i]];
    }
    for (int last = n; last >= 1; last--)
    {
        if (judge(last))
        {
            cout << last;
            return 0;
        }
    }
    return 0;
}
