#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
struct Trie
{
    int nxt[maxn][26], fail[maxn], end[maxn];
    int rt, tot;
    int newnode(){
        for (int i = 0; i < 26;i++)
            nxt[tot][i] = -1;
        end[tot++] = 0;
        return tot - 1;
    }
    void init(){
        tot = 0;
        rt = newnode();
    }
    void insert(char buf[]){
        int i = 0;
        int now = rt;
        while(buf[i]){
            int idx = buf[i] - 'a';
            if (nxt[now][idx]==-1)
                nxt[now][idx] = newnode();
            now = nxt[now][idx];
            ++i;
        }
        ++end[now];
    }
    void build(){
        queue<int> Q;
        fail[rt] = rt;
        for (int i = 0; i < 26;i++)
            if (nxt[rt][i]==-1)
                nxt[rt][i] = rt;
            else
            {
                fail[nxt[rt][i]] = rt;
                Q.push(nxt[rt][i]);
            }
        while(!Q.empty()){
            int now = Q.front();
            Q.pop();
            for (int i = 0; i < 26;i++){
                if (nxt[now][i]==-1)
                    nxt[now][i] = nxt[fail[now]][i];
                else
                {
                    fail[nxt[now][i]] = nxt[fail[now]][i];
                    Q.push(nxt[now][i]);
                }
            }
        }
    }
    int query(char buf[]){
        int i = 0;
        int now = rt;
        int res = 0;
        while(buf[i]){
            int idx = buf[i] - 'a';
            now = nxt[now][idx];
            int tmp = now;
            while(tmp!=rt&&end[tmp]!=-1){
                res += end[tmp];
                end[tmp] = -1;
                tmp = fail[tmp];
            }
            i++;
        }
        return res;
    }
};
int n;
Trie ac;
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ac.init();
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char *ss=new char[maxn];
        cin >> ss;
        ac.insert(ss);
        delete ss;
    }
    char s[maxn];
    cin >> s;
    ac.build();
    cout << ac.query(s);
    return 0;
}
