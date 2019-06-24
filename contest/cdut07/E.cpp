#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn=25050;
struct node{
    int s,t;
    node(){}
    node(int a,int b):s(a),t(b){}
    bool operator<(const node &a)const{
        if (s!=a.s){
            return s<a.s;
        }
        else
            return t>a.t;
    }
}info[maxn];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++){
        scanf("%d%d",&info[i].s,&info[i].t);
    }
    sort(info,info+n);

    int s=1,t=-1,int q=0;
    if (info[q].s!=1)
        ans=-1;
    else
    while(t<m){
        if (info[q].t>t)
            ans++;
    }
    return 0;
}
