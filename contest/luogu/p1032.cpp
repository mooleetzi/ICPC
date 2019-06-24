#include<bits/stdc++.h>
using namespace std;
const int maxn = 10;
using pa = pair<string, string>;
queue<pair<string,int>> que;
unordered_map<string, int> vis;
int cnt;
vector<pa> change;
int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    string ss, ee,st,et;
    cin >> ss >> ee;
    st = ss;
    et = ee;
    while (cin >> ss >> ee)
    {
        change.emplace_back(pa(ss, ee));
    }
    que.push({st,0});
    while (!que.empty() && que.front().second<10)
    {
        string now = que.front().first;
        int pre = que.front().second;
        que.pop();
        vis[now] = 1;
        for (auto x:change){
            string p = now;
            int pos = now.find(x.first);
            while(pos != -1)
            {
                // cout << p << "\n";

                string cur = now;
                cur.erase(pos, x.first.size());
                cur.insert(pos, x.second);
                if (!vis[cur]){
                    que.push({cur,pre+1});
                    if (cur == et)
                    {
                        printf("%d", pre + 1);
                        return 0;
                    }
                }
                p[pos] = '-';
                pos = p.find(x.first);
            }
        }
    }
    printf("NO ANSWER!");
    return 0;
}