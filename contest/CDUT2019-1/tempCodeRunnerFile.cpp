// #pragma optimize(2)
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
using namespace std;
using pa = pair<int, int>;
const int maxn = 1e5 + 10;
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    set<int> s;
    int a[maxn];
    int b[maxn];
    int n, m;
    cin >> t;
    while (t--)
    {
        s.clear();
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            b[i] = 1;
            s.insert(i);
            a[i] = i;
        }
        for (int i = 0; i < m; i++)
        {
            int l, r;
            cin >> l >> r;
            if (a[l] < r)
                a[l] = r;
        }
        int l = 1, r = 0;
        for (int i = 1; i <= n; i++)
        {
            int ll = i, rr = a[i];
            if (rr<=r)
                continue;
            for (int i = l; i < ll; i++)
                s.insert(b[i]);
            for (int i = r+1; i <= rr; i++)
            {
                b[i] = *(s.begin());
                s.erase(s.begin());
            }
            l = ll, r = rr;
        }
        for (int i = 1; i <= n; i++)
        {
            if (!b[i])
                b[i] = 1;
            cout << b[i] << (i==n)?'\n':' ';
        }
    }
    return 0;
}
