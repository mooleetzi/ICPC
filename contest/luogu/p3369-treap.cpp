#include<iostream>
#include<cstdlib>
#define ls(x) a[x].ch[0]
#define rs(x) a[x].ch[1]
using namespace std;
const int maxn=1e5+10;
struct node{
    int key,val,size;
    int ch[2];
}a[maxn];
int tot;
inline void pushup(int root){
    a[root].size=a[ls(root)].size+a[rs(root)].size+1;
}
void split(int root,int &x,int &y,int val){
    if (!root){
        x=y=0;
        return;
    }
    if (a[root].val<=val)
        x=root,split(rs(root),rs(x),y,val);
    else
        y=root,split(ls(root),x,ls(y),val);
    pushup(root);
}
void merge(int &root,int x,int y){
    if (!x||!y){
        root=x+y;
        return;
    }
    if (a[x].key<a[y].key)
        root=x,merge(rs(root),rs(x),y);
    else
        root=y,merge(ls(root),x,ls(y));
    pushup(root);
}
void Insert(int &root,int val){
    int x=0,y=0,z=++tot;
    a[z].val=val,a[z].key=rand();
    a[z].size=1;
    split(root,x,y,val);
    merge(x,x,z);
    merge(root,x,y);
}
void Erase(int &root,int val){
    int x=0,y=0,z=0;
    split(root,x,y,val);
    split(x,x,z,val-1);
    merge(z,ls(z),rs(z));
    merge(x,x,z);
    merge(root,x,y);
}
int kth(int root,int k){
    while(a[ls(root)].size+1!=k){
        if (k<=a[ls(root)].size)
            root=ls(root);
        else
            k-=a[ls(root)].size+1,root=rs(root);
    }
    return a[root].val;
}
int rnk(int &root,int val){
    int x=0,y=0,res;
    split(root,x,y,val-1);
    res=a[x].size+1;
    merge(root,x,y);
    return res;
}
int pre(int &root,int val){
    int x=0,y=0,res;
    split(root,x,y,val-1);
    res=kth(x,a[x].size);
    merge(root,x,y);
    return res;
}
int next(int &root,int val){
    int x=0,y=0,res;
    split(root,x,y,val);
    res=kth(y,1);
    merge(root,x,y);
    return res;
}
int n,rt;
int main(){
    srand(1927);
    ios::sync_with_stdio(false);
//    cin.tie(0);
    cin>>n;
    for (int i=0;i<n;i++){
        int op,x;
        cin>>op>>x;
//        cout<<op<<' '<<x<<'\n';
        if (op==1)
            Insert(rt,x);
        else if (op==2)
            Erase(rt,x);
        else if (op==3)
            cout<<rnk(rt,x)<<"\n";
        else if (op==4)
            cout<<kth(rt,x)<<"\n";
        else if (op==5)
            cout<<pre(rt,x)<<"\n";
        else if (op==6)
            cout<<next(rt,x)<<"\n";
    }
    return 0;
}
