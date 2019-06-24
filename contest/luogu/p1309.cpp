/*
开O2无限可水过 时间复杂度大概O(r(nlogn))
归并排序思想正常过， 不用开O2 时间复杂度为O(nlogn+rn) 合并时间复杂度为O(n)
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
struct node{
    int s,w,ind;
    node(){}
    node(int s,int w,int ind){
        this->s=s;
        this->w=w;
        this->ind=ind;
    }
    bool operator<(const node&a)const{
        if (s==a.s)
            return ind<a.ind;
        return s>a.s;
    }
}a[maxn],b[maxn],c[maxn];
int n,r,q,N;
void merge(){
    int i=1,j=1,k=0;
    while(i<=n&&j<=n){
        if (b[i].s>c[j].s)
            a[++k]=b[i++];
        else if (b[i].s==c[j].s){
            if (b[i].ind<c[j].ind)
                a[++k]=b[i++];
            else
                a[++k]=c[j++];
        }
        else
            a[++k]=c[j++];
    }
    while(i<=n)
        a[++k]=b[i++];
    while(j<=n)
        a[++k]=c[j++];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>r>>q;
    N=2*n;
    for (int i=1;i<=N;i++){
        int x;
        cin>>x;
        a[i]=node(x,0,i);
    }
    for (int i=1;i<=N;i++){
        int x;
        cin>>x;
        a[i].w=x;
    }
    sort(a+1,a+N+1);
    while(r--){
        int tmp=0;
        for (int i=1;i<=n;i++){
            node &x=a[2*i-1];
            node &y=a[2*i];
            if (x.w>y.w){
                b[++tmp]=x;
                b[tmp].s++;
                c[tmp]=y;
            }
            else{
                b[++tmp]=y;
                c[tmp]=x;
                b[tmp].s++;
            }
        }
        merge();
    }
    cout<<a[q].ind;
    return 0;
}
