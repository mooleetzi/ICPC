#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long  ll;
const int INF = 0x3f3f3f3f;
const int MAXN = 100000 + 5;
const int mod=1e9+7;
struct Edge {
    int u, v, w;
    bool operator < (const Edge& e) const {
        return w < e.w;
    }
} edges[MAXN];
int T, N;
ll a[MAXN],b[MAXN];
int par[MAXN], _rank[MAXN];
struct TNode {
    int v, w;
    TNode() {}
    TNode(int v, int w) : v(v), w(w) {}
};
vector<TNode> G[MAXN];
ll sum[MAXN];
ll ans;
void init() {
    memset(par, -1, sizeof(par));
    memset(_rank, 0, sizeof(_rank));
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= N; i++) G[i].clear();
}
int Find(int x) {
    return -1 == par[x] ? x : (par[x] = Find(par[x]));
}

void doit() {
    sort(edges, edges + N-1);
    for (int i = 0; i < N-1; i++) {
        Edge& e = edges[i];
        int pu = Find(e.u);
        int pv = Find(e.v);
        if (pu == pv) continue;
        if (_rank[pu] == _rank[pv]) {
            par[pv] = pu;
            _rank[pu] ++;
        } else if (_rank[pu] > _rank[pv]) {
            par[pv] = pu;
        } else {
            par[pu] = pv;
        }
        Find(e.u);
        Find(e.v);
        G[e.u].push_back(TNode(e.v, e.w));
        G[e.v].push_back(TNode(e.u, e.w));
    }
}
void dfs(int root, int father) {
    sum[root] = 1;
    for (int i = 0; i < G[root].size(); i++) {
        TNode& e = G[root][i];
        int son = e.v;
        if (son == father) continue;
        dfs(son, root);
        sum[root] += sum[son];
        ans += (sum[son] * (N - sum[son])) * e.w;
    }
}
ll getAns(ll ans){
    ans=(ans*a[N-1])%mod;
}
int main() {
    scanf("%d", &N);
    int u, v, w;
    for (int i = 0; i < N-1; i++) {
        scanf("%d %d %d", &u, &v, &w);
        edges[i].u = u;
        edges[i].v = v;
        edges[i].w = w;
    }
    init();
    doit();
    ans = 0;
    dfs(1, -1);
    printf("%lld\n",ans);
    return 0;
}
