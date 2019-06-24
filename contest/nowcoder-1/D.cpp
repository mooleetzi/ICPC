#include<bits/stdc++.h>
using namespace std;
int ma1[9][9],ma2[9][9];
int n,m1,m2;
int main(){
    while(cin>>n>>m1>>m2){
        memset(ma1,0,sizeof ma1);
        memset(ma2,0,sizeof ma2);
        for (int i=0;i<m1;i++){
            int x,y;
            cin>>x>>y;
            ma1[x][y]=1;
            ma1[y][x]=1;
        }
        for (int i=0;i<m2;i++){
            int x,y;
            cin>>x>>y;
            ma2[x][y]=1;
            ma2[y][x]=1;
        }
        int a[n+1];
        for (int i=1;i<=n;i++)
            a[i]=i;
        int ans1=0,ans2=0;
        do{
            int flag=1;
            for (int i=1;i<=n;i++)
                for (int j=1;j<=n;j++)
                    if (ma1[i][j]==1&&ma2[a[i]][a[j]]==0)
                        flag=0;
            if (flag)
                ans1++;
        }while(next_permutation(a+1,a+n+1));
        do{
            int flag=1;
            for (int i=1;i<=n;i++)
                for (int j=1;j<=n;j++)
                    if (ma1[i][j]==1&&ma1[a[i]][a[j]]==0)
                        flag=0;
            if (flag)
                ans2++;
        }while(next_permutation(a+1,a+n+1));
        cout<<ans1/ans2<<endl;
    }
    return 0;
}
//3 1 2
//1 3
//1 2
//2 3
//4 2 3
//1 2
//1 3
//4 1
//4 2
//4 3

