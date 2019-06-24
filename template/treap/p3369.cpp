#include<bits/stdc++.h>
using namespace std;
#define ls(x) tree[x].ch[0]
#define rs(x) tree[x].ch[1]
const int maxn = 1e5 + 10;
struct node
{
    int key, val, ch[2],sz;
}tree[maxn];
int tot;
inline void pushup(int rt){
    tree[rt].sz = tree[ls(rt)].sz + tree[rs(rt)].sz + 1;
}
void split(int root,int &x, int &y, int val)
{
    if (!root){
        x = y = 0;
        return;
    }
    if (tree[root].val<=val){
        x = root;
        split(rs(root), rs(x), y, val);
    }
    else
    {
        y = root;
        split(ls(root),x, ls(y), val);
    }
    pushup(root);
}
void merge(int &root,int x, int y)
{
    if (!x||!y){
        root = x + y;
        return;
    }
    if (tree[x].key<tree[y].key){
        root = x;
        merge(rs(root), rs(x), y);
    }
    else
    {
        root = y;
        merge(ls(root), x, ls(y));
    }
    // pushup(root);
}
void insert(int &root,int val){
    int x, y, z=++tot;
    x = y =0;
    tree[z].val = val;
    tree[z].sz = 1;
    tree[z].key = rand();
    split(root, x, y, val - 1);
    merge(x, x, z);
    merge(root, x, y);
}
void erase(int &root,int val){
    int x, y,z;
    x = y = z=0;
    split(root, x, y, val);
    split(x, x, z,val-1);
    merge(z, ls(z), rs(z));
    merge(x, x, z);
    merge(root, x, y);
}
int kth(int root,int k){
    while(tree[ls(root)].sz+1!=k){
        if (k>tree[ls(root)].sz){
            k -= tree[ls(root)].sz + 1;
            root = rs(root);
        }
        else
            root = ls(root);
    }
    return tree[root].val;
}
int rnk(int &root,int val){
    int x = 0, y = 0, ans;
    split(root, x, y, val - 1);
    ans = tree[x].sz + 1;
    merge(root, x, y);
    return ans;
}
int pre(int &root,int val){
    int x = 0, y = 0, ans;
    split(root, x, y, val - 1);
    ans = kth(x, tree[x].sz);
    merge(root, x, y);
    return ans;
}
int next(int &root,int val){
    int x = 0, y = 0, ans;
    split(root, x, y, val);
    ans = kth(y, 1);
    merge(root, x, y);
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
int rt;
int main(int argc, char const *argv[])
{
    srand(time(0));
    int n;
    read(n);
    for (int i = 0; i < n;i++){
        int op, x;
        read(op), read(x);
        if (op==1)
            insert(rt,x);
        if (op==2)
            erase(rt, x);
        if (op == 3)
            printf("%d\n", rnk(rt,x));
        if (op == 4)
            printf("%d\n", kth(rt,x));
        if (op == 5)
            printf("%d\n", pre(rt,x));
        if (op == 6)
            printf("%d\n", next(rt,x));
    }
    return 0;
}
