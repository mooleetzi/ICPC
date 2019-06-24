#include<iostream>
#include<cstring>
using namespace std;
const int maxn=1e5+10;
const int inf=0x3f3f3f3f;
struct node{
    int ch[2];
    int val,cnt,size,fa;
    node(){
        ch[0]=ch[1]=val=cnt=size=fa=0;
    }
}t[maxn];
int rt,tot;
inline void clear(int i){
    t[i]=node();
}
inline int ws(int x){//判断是哪个儿子 0左1右
    return t[t[x].fa].ch[1]==x;
}
inline void connect(int s,int f,int w){
    if (f)
        t[f].ch[w]=s;
    if (s)
        t[s].fa=f;
}
inline void update(int x){
    t[x].size=t[x].cnt+t[t[x].ch[0]].size+t[t[x].ch[1]].size;
}
inline void rot(int x){//节点旋转
    int w=ws(x);
    int wf=ws(t[x].fa);
    int f=t[x].fa;
    int ff=t[f].fa;
    int tson=t[x].ch[w^1];//x节点的需要改变的子节点
    connect(tson,f,w);
    connect(f,x,w^1);
    connect(x,ff,wf);
    update(f);
    update(x);
}
void splay(int x,int f){//直接伸展到根节点，根据前人理论，可更加平衡
    for (;t[x].fa!=f;rot(x))
        if (t[t[x].fa].fa&&ws(x)==ws(t[x].fa))
            rot(t[x].fa);
    if (!f)
        rt=x;
}
void insert(int x){//插入x
    int now=rt;
    if (!now){
        ++tot;
        t[tot].val=x;
        t[tot].cnt=1;
        update(tot);
        rt=tot;
        return;
    }
    while(t[now].val!=x){
        if (x>t[now].val){
            if (!t[now].ch[1]){
                t[++tot].val=x;
                connect(tot,now,1);
            }
            now=t[now].ch[1];
        }
        else{
            if (!t[now].ch[0]){
                t[++tot].val=x;
                connect(tot,now,0);
            }
            now=t[now].ch[0];
        }
    }
    ++t[now].cnt;
    splay(now,0);
}
int find(int x){//查询值为x的节点编号，并将其伸展到根
    int now=rt;
    if (!rt)
        return 0;
    while(1){
        if (t[now].val==x){
            splay(now,0);
            return now;
        }
        now=t[now].ch[x>t[now].val];
        if (!now)
            return 0;
    }
}
int kth(int x){//查询第x大的数
    int now=rt;
    while(1){
        int left=t[now].size-t[t[now].ch[1]].size;//左儿子+自身
        if (x>t[t[now].ch[0]].size&&x<=left){
            splay(now,0);
            return t[now].val;
        }
        if (x<left)
            now=t[now].ch[0];
        else{
            x-=left;
            now=t[now].ch[1];
        }
    }
}
int rnk(int x){//查询x的排名
    int now=find(x);
    return t[t[now].ch[0]].size+1;
}
void del(int x){//删除值为x的一个节点
    int now=find(x);
    if (!now)
        return;
    if (t[now].cnt>1){
        --t[now].cnt;
        update(now);
        return;
    }
    if (!t[now].ch[0]&&!t[now].ch[1]){
        rt=0;
        return;
    }
    if (!t[now].ch[0]){
        rt=t[now].ch[1];
        t[rt].fa=0;
    }
    else if (!t[now].ch[1]){
        rt=t[now].ch[0];
        t[rt].fa=0;
    }
    else{
        int left=t[now].ch[0];
        while(t[left].ch[1])
            left=t[left].ch[1];
        splay(left,0);
        connect(t[now].ch[1],left,1);
        clear(now);
        update(left);
    }
}
int pre(int x){
    int ans=-inf;
    int now=rt;
    while(now){
        if (t[now].val<x)
            ans=max(ans,t[now].val);
        now=t[now].ch[x>t[now].val];
    }
    return ans;
}
int next(int x){
    int ans=inf;
    int now=rt;
    while(now){
        if (t[now].val>x)
            ans=min(ans,t[now].val);
        now=t[now].ch[x>=t[now].val];
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int op,x;
        cin>>op>>x;
        if (op==1)
            insert(x);
        else if (op==2)
            del(x);
        else if (op==3)
            cout<<rnk(x)<<"\n";
        else if (op==4)
            cout<<kth(x)<<"\n";
        else if (op==5)
            cout<<pre(x)<<"\n";
        else if (op==6)
            cout<<next(x)<<"\n";
    }
    return 0;
}
