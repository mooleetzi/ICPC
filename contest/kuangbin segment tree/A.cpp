#include<bits/stdc++.h>
using namespace std;
const int maxn=50001;
const string s[]={"Add","Sub","Query","End"};
struct node{
    int l,r,sum;
}tree[maxn<<2];
void push(int now){
    tree[now].sum=tree[now<<1].sum+tree[now<<1|1].sum;
    return;
}
void build(int now,int l,int r){
    tree[now].l=l;
    tree[now].r=r;
    if (l==r){
//        scanf("%d",&tree[now].sum);
        cin>>tree[now].sum;
        return;
    }
    int m=(l+r)>>1;
    build(now<<1,l,m);
    build(now<<1|1,m+1,r);
    push(now);
}
void update(int now,int L,int C){
    int l=tree[now].l;
    int r=tree[now].r;
    if (l==r){
        tree[now].sum+=C;
        return;
    }
    int m=(l+r)>>1;
    if (m<L)
        update(now<<1|1,L,C);
    else
        update(now<<1,L,C);
    push(now);
}
int sum(int now,int L,int R){
    int l=tree[now].l;
    int r=tree[now].r;
    if (l==L&&r==R)
        return tree[now].sum;
    int m=(l+r)>>1;
    if (m>=R)
        return sum(now<<1,L,R);
    else if (m<L)
        return sum(now<<1|1,L,R);
    else return sum(now<<1,L,m)+sum(now<<1|1,m+1,R);
}
int main(){
    ios::sync_with_stdio(false);
    int n,t,q=0;
//    scanf("%d",&t);
    cin>>t;
    while(q<t){
//        scanf("%d",&n);
        cin>>n;
        build(1,1,n);
        string ss;
        cout<<"Case "<<++q<<":\n";
        while(cin>>ss&&ss!=s[3]){
            if (ss==s[0]){
                int l,c;
                cin>>l>>c;
                update(1,l,c);
            }
            else if (ss==s[1]){
                int l,c;
                cin>>l>>c;
                update(1,l,-c);
            }
            else if (ss==s[2]){
                int l,r;
                cin>>l>>r;
                cout<<sum(1,l,r)<<"\n";
            }
        }
    }
    return 0;
}
