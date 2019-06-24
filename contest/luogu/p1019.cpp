#include<bits/stdc++.h>
using namespace std;
vector<string> ve;
map<string, int> vis;
string cur;
int n,ans=(int)-1e10;
int find(string s1, string s2)
{
    int i;
    for (i = 1; i < min(s1.size(), s2.size());i++){
        int flag = 1;
        for (int j = 0; j < i; j++)
            if (s1[s1.size()-i+j]!=s2[j])
                flag = 0;
        if (flag)
            return i;
    }
    return 0;
}
void dfs(string cur){
    ans = max(ans,(int)cur.size());
    for (int i = 0; i < n;i++){
        if (vis[ve[i]]<2){
            int len = find(cur, ve[i]);
            if (len){
                string tmp = cur;
                tmp.erase(tmp.size() - len, len);
                tmp += ve[i];
                if (tmp.size()<=cur.size())
                    continue;
                ++vis[ve[i]];
                dfs(tmp);
                --vis[ve[i]];
            }
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> cur;
        ve.emplace_back(cur);
    }
    char start;
    cin >> start;
    for (int i = 0; i < n;i++)
        if (!vis[ve[i]]&&ve[i].front()==start){
            ++vis[ve[i]];
            cur = ve[i];
            dfs(cur);
            --vis[ve[i]];
        }
    cout << ans << "\n";
    return 0;
}