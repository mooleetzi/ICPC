#include<iostream>
#include<set>
using namespace std;
const int maxn=510;
int ma[maxn][maxn];
int v[maxn];
int main(){
    int n,m,k,l;
    cin>>n>>m>>k;
    for (int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        ma[x][y]=ma[y][x]=1;
    }
    cin>>l;
    for (int i=1;i<=l;i++){
        set<int> now;
        now.clear();
        for (int j=1;j<=n;j++){
            cin>>v[j];
            now.insert(v[j]);
        }
        int flag=1;
        for (int j=1;j<=n&&flag;j++)
            for (int q=j+1;q<=n;q++)
            if ((ma[j][q]&&v[j]==v[q])||(v[j]>n||v[j]<1||v[q]>n||v[q]<1)){
                flag=0;
                break;
            }
        if (flag){
            if (now.size()==k)
                cout<<"Yes\n";
            else
                cout<<"No\n";
        }
        else
            cout<<"No\n";
    }
    return 0;
}
