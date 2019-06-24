#include<bits/stdc++.h>
using namespace std;
const int maxn=2e4;
struct sing{
    int a[16],b[16];
}singer[maxn];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    int t,q=0,n,m;
    scanf("%d",&t);
    while(q<t){
        scanf("%d",&n);
        int ans=0;
        deque<int> v;
        for (int i=1;i<=(1<<n);i++) v.push_back(i);
        for (int i=1;i<=(1<<n);i++){
            for (int j=1;j<=n;j++)
                scanf("%d",&singer[i].a[j]),singer[i].b[j]=0;
            sort(singer[i].a+1,singer[i].a+n+1,cmp);
        }
        while(!v.empty()){
//            cout<<v.size()<<"\n";
            int x=v.front();
            v.pop_front();
            int y=v.front();
            v.pop_front();
            //cout<<x<<" "<<y<<"\n";
            int p=1,u=1;
            while(1){
                if (!singer[x].b[p]&&!singer[y].b[u])
                    break;
                if (singer[x].b[p])
                    p++;
                if (singer[y].b[u])
                    u++;

            }
//            cout<<x<<" "<<y<<" "<<singer[x].a[p]<<" "<<singer[y].a[u]<<"\n";
//            cout<<p<<" "<<u<<"\n";
            //cout<<singer[x].a[p]<<" "<<singer[y].a[u]<<"\n";
            if (v.empty()){
                if (singer[x].a[p]>singer[y].a[u])
                    ans=x;
                else
                    ans=y;
                break;
            }
            if (singer[x].a[p]>singer[y].a[u]){
                v.push_back(x);
                while(1){
                    if (singer[x].a[p]>singer[y].a[u]&&singer[x].a[p+1]<singer[y].a[u]&&!singer[x].b[p]||(p==n&&singer[x].a[p]>singer[y].b[u])){
                        singer[x].b[p]=1;
                        break;
                    }
                    p++;
                }
            }
            else{
                v.push_back(y);
                while(1){
                    if (singer[y].a[u]>singer[x].a[p]&&singer[y].a[u+1]<singer[x].a[p]&&!singer[y].b[u]||(u==n&&singer[y].a[u]>singer[x].a[p])){
                        singer[y].b[u]=1;
                        break;
                    }
                    u++;
                }
            }
        }
        printf("Case #%d: %d\n",++q,ans);
    }
}
