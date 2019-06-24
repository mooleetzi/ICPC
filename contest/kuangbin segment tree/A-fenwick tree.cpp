#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=50010;
typedef long long ll;
ll c[maxn],n;
inline int lowbit(int x){
    return (x&-x);
}
void update(int x,int val){
    while(x<=n){
        c[x]+=val;
        x+=lowbit(x);
    }
}
int query(int x){
    int ans=0;
    while(x){
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    int q,t=0;
    cin>>q;
//    scanf("%d",&q);
    while(t<q){
        memset(c,0,sizeof c);
        cin>>n;
//        scanf("%d",&n);
        for (int i=1;i<=n;i++){
            int x;
            cin>>x;
//            scanf("%d",&x);
            update(i,x);
        }
        string s;
        cout<<"Case "<<++t<<":\n";
        while(cin>>s&&s!="End"){
            int a,b;
            cin>>a>>b;
            if (s=="Query")
                cout<<query(b)-query(a-1)<<"\n";
//                printf("%d\n",query(b)-query(a-1));
            else if (s=="Add")
                update(a,b);
            else if (s=="Sub")
                update(a,-b);
        }
    }
    return 0;
}
//2
//10
//1 2 3 4 5 6 7 8 9 10
//Query 1 3
//Add 3 6
//Query 2 7
//Sub 10 2
//Add 6 3
//Query 3 10
//End
//10
//1 2 3 4 5 6 7 8 9 10
//Query 1 3
//Add 3 6
//Query 2 7
//Sub 10 2
//Add 6 3
//Query 3 10
//End

