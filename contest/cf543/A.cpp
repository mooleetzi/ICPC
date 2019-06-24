#include<bits/stdc++.h>
using namespace std;
const int maxn = 110;
int n, m, k;
int a[maxn],b[maxn],v[maxn];
vector<int> t[maxn];
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <=n;i++)
        cin >> a[i];
    for (int i = 1; i <=n;i++){
        cin >> b[i];
        t[b[i]].push_back(a[i]);
    }
    int ans = 0;
    for (int i = 0; i < k; i++){
        int x;
        cin >> x;
        int ws = b[x];
        if (!v[ws]){
            sort(t[ws].begin(), t[ws].end(), [](int x, int y) { return x > y; });
            v[ws] = 1;
            // for_each(t[ws].begin(), t[ws].end(), [](int x) {
            //     cout << x << " ";
            // });
            // cout << "\n";
        }
        if (t[ws][0] != a[x])
            ++ans;
    }
    cout << ans;
    return 0;
}


