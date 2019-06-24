/*
    瞎搞降低复杂度
    O(nmlog(n+m)+nlogn+mlogm)
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
const int inf = 0x3f3f3f3f;

inline int read()
{
    register int tmp = 0, f = 1;
    char ch = getchar();
    if (ch == '-')
    {
        ch = getchar();
        f = -1;
    }
    while (ch >= '0' && ch <= '9')
    {
        tmp = tmp * 10 + ch - '0';
        ch = getchar();
    }
    return tmp * f;
}
int n, m;
int a[maxn][maxn];
set<int> c[maxn], r[maxn];
vector<int> cc[maxn], rr[maxn];
int visx[maxn], visy[maxn];
int getAns(vector<int> &a, vector<int> &b, int pre,int x,int y)
{
    if (!visx[x]){
        sort(a.begin(), a.end());
        visx[x] = 1;
    }
    if (!visy[y]){
        sort(b.begin(), b.end());
        visy[y] = 1;
    }
    int la = a.size();
    int lb = b.size();
    int m1 = lower_bound(a.begin(), a.end(), pre) - a.begin();
    int m2 = lower_bound(b.begin(), b.end(), pre)-b.begin();

    if (m1 < m2)
        la += m2 - m1;
    else
        lb += m1 - m2;
    return max(la, lb);
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++){
            if (!r[i].count(a[i][j]))
                rr[i].emplace_back(a[i][j]), r[i].insert(a[i][j]);
            if (!c[j].count(a[i][j]))
                cc[j].emplace_back(a[i][j]), c[j].insert(a[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = getAns(rr[i], cc[j], a[i][j],i,j);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << "\n";
    }
    return 0;
}