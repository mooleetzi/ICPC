#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 1e5 + 10;
using ll = long long;
int n;
struct node
{
    int index, score;
    node() {}
    node(int i, int s)
    {
        index = i;
        score = s;
    }
    bool operator<(const node &a) const
    {
        return score < a.score;
    }
};
node a[5][maxn];
ll getAns(int tmp[])
{
    ll ans = 0;
    node t[5][n + 1];
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < n; j++)
            t[i][j] = a[tmp[i]][j];
    int v[n + 1];
    memset(v, 0, sizeof v);
    for (int i = 0; i < 5; i++)
    {
        int now = max_element(t[i], t[i] + n) - t[i];
        while (v[now])
        {
            t[i][now].score = -1;
            now = max_element(t[i], t[i] + n) - t[i];
        }
        v[now] = 1;
        ans += t[i][now].score;
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y, z, w, h;
        cin >> x >> y >> z >> w >> h;
        a[0][i] = node(i, x);
        a[1][i] = node(i, y);
        a[2][i] = node(i, z);
        a[3][i] = node(i, w);
        a[4][i] = node(i, h);
    }
    ll ans = 0;
    int tmp[] = {0, 1, 2, 3, 4};
    do
    {
        ans = max(getAns(tmp), ans);
    } while (next_permutation(tmp, tmp + 5));
    cout << ans << "\n";
    return 0;
}
