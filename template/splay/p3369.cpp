#include<bits/stdc++.h>
#define ls(x) tree[x].ch[0]
#define rs(x) tree[x].ch[1]
using namespace std;
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
int root, tot;
struct node
{
    int ch[2], cnt, size, fa,val;
}tree[maxn];
inline void clear(int x){
    tree[x].size = tree[x].cnt = tree[x].ch[1] = tree[x].ch[0] = tree[x].fa=0;
}
inline int ws(int x)
{ //判断左右儿子
    return tree[tree[x].fa].ch[1] == x;
}
inline void pushup(int x){
    if (x)
        tree[x].size = tree[ls(x)].size + tree[rs(x)].size + tree[x].cnt;
}
inline void connect(int s,int f,int w){
    if (f)
        tree[f].ch[w] = s;
    if (s)
        tree[s].fa = f;
}
inline void rot(int x){
    int f = tree[x].fa;
    int ff = tree[f].fa;
    int w = ws(x);
    int wf = ws(f);
    int tson = tree[x].ch[w ^ 1];
    connect(tson, f, w);
    connect(f, x, w ^ 1);
    connect(x, ff, wf);
    pushup(f);
    pushup(x);
}
inline void splay(int x,int goal){
    while(tree[x].fa!=goal){
        int f = tree[x].fa;
        int ff = tree[f].fa;
        if (ff!=goal){
            if (ws(x)==ws(f))
                rot(f);
            else
                rot(x);
        }
        rot(x);
    }
    if (!goal)
        root = x;
}
inline void insert(int x){
    int now = root;
    if (!now){
        now = ++tot;
        tree[now].cnt = 1;
        tree[now].size = 1;
        tree[now].val = x;
        root = now;
        return;
    }
    while(tree[now].val!=x){
        if (x>tree[now].val){
            if (!rs(now)){
                int tmp = ++tot;
                tree[tmp].val = x;
                connect(tmp, now, 1);
            }
            now = rs(now);
        }
        else
        {
            if (!ls(now)){
                int tmp = ++tot;
                tree[tmp].val = x;
                connect(tmp, now, 0);
            }
            now = ls(now);
        }
    }
    ++tree[now].cnt;
    splay(now, 0);
}
inline int find(int x){
    int now = root;
    if (!now)
        return 0;
    while(now){
        if (x>tree[now].val)
            now = rs(now);
        else if (x<tree[now].val)
            now = ls(now);
        else
            break;
    }
    return now;
}
inline void del(int x){
    int now = find(x);
    if (!now)
        return;
    splay(now, 0);
    if (tree[now].cnt > 1)
    {
        --tree[now].cnt;
        pushup(now);
        return;
    }
    if (!ls(now)&&!rs(now)){
        clear(now);
        root = 0;
    }
    else if (!ls(now))
    {
        root = rs(now);
        tree[root].fa = 0;
        pushup(root);
        clear(now);
    }
    else if (!rs(now))
    {
        root = ls(now);
        tree[root].fa = 0;
        pushup(root);
        clear(now);
    }
    else
    {
        int left = ls(now);
        while(rs(left))
            left = rs(left);
        splay(left, 0);
        connect(tree[now].ch[1], left, 1);
        clear(now);
        pushup(left);
    }
}
int rnk(int x){
    int now = find(x);
    splay(now,0);
    return tree[tree[now].ch[0]].size + 1;
}
int kth(int x){
    int now = root;
    while(1){
        int left = tree[now].size - tree[rs(now)].size;
        if (x>tree[ls(now)].size&&x<=left){
            break;
        }
        if (x<left)
            now = ls(now);
        else{
            x -= left;
            now = rs(now);
        }
    }
    splay(now, 0);
    return tree[now].val;
}
int pre(int x){
    int now = root;
    int ans = -inf;
    while(now){
        if (x>tree[now].val){
            ans = max(ans, tree[now].val);
            now = rs(now);
        }
        else
            now = ls(now);
    }
    return ans;
}
int next(int x){
    int now = root;
    int ans = inf;
    while (now)
    {
        if (x<tree[now].val){
            ans = min(ans, tree[now].val);
            now = ls(now);
        }
        else
        {
            now = rs(now);
        }
    }
    return ans;
}
inline void read(int &x){
    x = 0;
    register int f = 1;
    char ch = getchar();
    while(!isdigit(ch)){
        if (ch=='-')
            f = -1;
        ch = getchar();
    }
    while(isdigit(ch)){
        x = (x << 3) + (x << 1) + ch - 48;
        ch = getchar();
    }
    if (f==-1)
        x = -x;
}

int main(int argc, char const *argv[])
{
    int n;
    read(n);
    for (int i = 0; i < n;i++){
        int op, x;
        read(op);
        read(x);
        // printf("%d %d\n", op, x);
        if (op == 1)
            insert(x);
        if (op==2)
            del(x);
        if (op==3)
            printf("%d\n", rnk(x));
        if (op==4)
            printf("%d\n", kth(x));
        if (op==5)
            printf("%d\n", pre(x));
        if (op==6)
            printf("%d\n", next(x));
    }
    return 0;
}
