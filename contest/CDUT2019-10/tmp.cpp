#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
unordered_set<string> s;
bool judge(vector<int> vec)
{
    int sz = vec.size();
    string now = "";
    for (int i = 0; i < sz; i++)
    {
        now = "";
        for (int j = i, t = 0; t < sz; j = (j + 1) % sz, t++)
            now += vec[j] + '0';
        if (s.count(now))
            return 0;
    }
    s.insert(now);
    return 1;
}
bool isok(vector<int> vec)
{
    int sz = vec.size();
    for (int i = 0; i < sz; i++)
    {
        int p = (vec[i] + 1);
        if (p > sz)
            p = 1;
        int r = vec[(i + 1) % sz];
        if (p == r)
            return 0;
    }
    if (judge(vec))
        return 1;
    return 0;
}
int main(int argc, char const *argv[])
{
    s.clear();
    vector<int> a;
    a.clear();
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        a.push_back(i);
    int ans = 0;
    do
    {
        if (isok(a))
            ++ans;
    } while (next_permutation(a.begin(), a.end()));
    cout << ans << "\n";
    for (auto x : s)
        cout << x << "\n";
    return 0;
}
