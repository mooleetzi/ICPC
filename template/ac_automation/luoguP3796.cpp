#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int num;
string ans;
struct Trie
{
    int nxt[maxn][26], fail[maxn], end[maxn];
    map<int, string> wd;
    map<string, int> cnt;
    int rt, tot;
    int newnode()
    {
        for (int i = 0; i < 26; i++)
            nxt[tot][i] = -1;
        end[tot++] = 0;
        return tot - 1;
    }
    void init()
    {
        memset(end, 0, sizeof end);
        tot = 0;
        rt = newnode();
        wd.clear();
        cnt.clear();
    }
    void insert(char buf[])
    {
        int i = 0;
        int now = rt;
        while (buf[i])
        {
            int idx = buf[i] - 'a';
            if (nxt[now][idx] == -1)
                nxt[now][idx] = newnode();
            now = nxt[now][idx];
            ++i;
        }
        ++end[now];
        wd[now] = string(buf);
    }
    void build()
    {
        queue<int> Q;
        fail[rt] = rt;
        for (int i = 0; i < 26; i++)
            if (nxt[rt][i] == -1)
                nxt[rt][i] = rt;
            else
            {
                fail[nxt[rt][i]] = rt;
                Q.push(nxt[rt][i]);
            }
        while (!Q.empty())
        {
            int now = Q.front();
            Q.pop();
            for (int i = 0; i < 26; i++)
            {
                if (nxt[now][i] == -1)
                    nxt[now][i] = nxt[fail[now]][i];
                else
                {
                    fail[nxt[now][i]] = nxt[fail[now]][i];
                    Q.push(nxt[now][i]);
                }
            }
        }
    }
    void query(char buf[],int &num,string &ans)
    {
        int i = 0;
        int now = rt;
        while (buf[i])
        {
            int idx = buf[i] - 'a';
            now = nxt[now][idx];
            int tmp = now;
            while (tmp != rt)
            {
                if (end[tmp])
                    ++cnt[wd[tmp]];
                tmp = fail[tmp];
            }
            i++;
        }
        for (auto x:cnt)
            cout << x.first << " " << x.second << "\n";
    }
};
int n;
Trie ac;
char buf[maxn];
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (cin>>n&&n)
    {
        ac.init();
        for (int i = 0; i < n;i++){
            char *s = new char[200];
            cin >> s;
            ac.insert(s);
        }
        scanf("%s", buf);
        num = 0;
        ac.query(buf,num,ans);
        // cout << num << "\n"
        //      << ans << "\n";
    }

    return 0;
}