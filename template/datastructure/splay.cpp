#include<iostream>
using namespace std;
const int maxn=1e5+10;
const int inf=0x3f3f3f3f;
int cnt[maxn];
int ch[maxn][2];
int sz[maxn];
int val[maxn];
int fa[maxn];
int rt,all;
inline void clear(int x){//清除节点信息
    fa[x]=cnt[x]=ch[x][0]=ch[x][1]=sz[x]=cnt[x]=val[x]=0;
}
inline int ws(int x){//which son
    return ch[fa[x]][1]==x;//判断是否是父节点的右儿子,左0 右1
}
inline void update(int x){
    if (x)
        sz[x]=cnt[x]+sz[ch[x][0]]+sz[ch[x][1]];
}
void setson(int s,int f,int w){
    if (s)
        fa[s]=f;
    if (f)
        ch[f][w]=s;
}
void rot(int x){
    int f=fa[x];
    int ff=fa[f];
    int w=ws(x);
    int wf=ws(f);
    int tson=ch[x][w^1];
    setson(tson,f,w);
    setson(x,ff,wf);
    setson(f,x,w^1);
    update(f);
    update(x);
}
void splay(int x){
    for (;fa[x];rot(x))
        if (fa[fa[x]]&&ws(x)==ws(fa[x]))
            rot(fa[x]);
    rt=x;
}
void insert(int x){
    if (!rt){
        ++all;
        sz[all]=cnt[all]=1;
        val[all]=x;
        rt=all;
        return;
    }
    int now=rt;
    while(val[now]!=x){
        if (x>val[now]){
            if (!ch[now][1]){
                val[++all]=x;
                setson(all,now,1);
            }
            now=ch[now][1];
        }
        else{
            if (!ch[now][0]){
                val[++all]=x;
                setson(all,now,0);
            }
            now=ch[now][0];
        }
    }
    ++cnt[now];
    splay(now);
}
int find(int x){//查询x的编号
    int now=rt;
    while(1){
        if (val[now]==x){
            splay(now);
            return now;
        }
        now=ch[now][val[now]<x];
        if (!now)
            return 0;
    }
}
int rnk(int x){//查询x的排名
    int ans=0;
    int now=rt;
    if (!now)
        return -1;
    while(1){
        if (val[now]>x)
            now=ch[now][0];
        else{
            ans+=sz[ch[now][0]];
            if (val[now]==x){
                splay(now);
                return ans+1;
            }
            ans+=cnt[now];
            now=ch[now][1];
        }
    }
}
int kth(int x){//查询排名为x的节点编号
    int now=rt;
    while(1){
        int used=sz[now]-sz[ch[now][1]];//左边加自己
        if (x>sz[ch[now][0]]&&x<=used)//大于左边小于等于左边加自己说明有相同排名的一串数字
            break;
        if (x<used)//小于左边加自己说明排名还在靠前，往左子树找
            now=ch[now][0];
        else{//否则说明在右子树，且在向右过程中应该先把左边&自己的部分排名减去
            x-=used;
            now=ch[now][1];
        }
    }
    splay(now);
    return val[now];
}
void del(int x){
    int now=find(x);//在find之后已经将x节点伸展到了跟
    if (!now)
        return;
    if (cnt[now]>1){
        --cnt[now];
        update(now);
        return;
    }
    if (!ch[now][0]&&!ch[now][1])//整棵树只有一个节点
        rt=0;
    else if (!ch[now][0]){
        rt=ch[now][1];
        fa[rt]=0;
    }
    else if (!ch[now][1]){
        rt=ch[now][0];
        fa[rt]=0;
    }
    else{
        int left=ch[now][0];
        while(ch[left][1])
            left=ch[left][1];
        splay(left);
        setson(ch[now][1],left,1);
        clear(now);
        update(left);
    }
}
int pre(int x){
    int ans=-inf;
    int now=rt;
    while(now){
        if (val[now]<x)
            ans=max(val[now],ans);
        now=ch[now][x>val[now]];//寻找pre时，小于等于都往左找
    }
    return ans;
}
int next(int x){
    int ans=inf;
    int now=rt;
    while(now){
        if (x<val[now])
            ans=min(ans,val[now]);
        now=ch[now][x>=val[now]];//寻找next时，即使相等也得往右子树找
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    int op,x;
    int n;
    cin>>n;
    while(n--){
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
