#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn = 2e5 + 10;
struct node
{
    int x, idx;
    bool operator<(const node &a){
        return x < a.x;
    }
    bool operator==(const node&a){
        return x == a.x;
    }
}a[maxn],b[maxn];
int vis[maxn];
int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 0; i < n;i++){
        cin>>a[i].x;
        a[i].idx = i;
        b[i] = a[i];
    }
    sort(a,a+n);
    sort(b, b + n);
    auto last = unique(a, a + n)-a;
    for (int i = 0; i < last;i++)
        vis[a[i].idx] = 1;
    set<int> s;
    s.clear();
    for (auto x = 0; x <n; x++)
    {
        if (!vis[b[x].idx])
            s.insert(b[x].x);
    }
    if (s.size()!=n-last){
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    cout << last<< "\n";
    for (auto x = 0; x != last;x++)
        cout << a[x].x << " ";
    cout << "\n";
    cout << s.size() << "\n";
    vector<int> ans;
    ans.clear();
    for (auto x : s)
        ans.emplace_back(x);
    reverse(ans.begin(), ans.end());
    for (auto x:ans)
        cout << x << " ";
    return 0;
}
