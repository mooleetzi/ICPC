#include<iostream>
using namespace std;
int a[110][15][11];
int b[110];
int main(){
    int n;
    cin>>n;
    int minx=1e10,maxx=-1e10;
    for (int i=1;i<=n;i++){
        int m;
        cin>>b[i];
        minx=min(minx,b[i]);
        maxx=max(maxx,b[i]);
    }
    int tot=1;
    int last=0;
    int cnt=0;
    if (n==1){
        for (int i=1;i<=b[1];i++)
        for (int j=1;j<=10;j++){
                a[1][i][j]=tot;
                tot+=2;
        }
    }
    else
    while(last<maxx){
        for (int k=last+1;k<=minx;k++)
            for (int j=1;j<=10;j++)
                for (int i=1;i<=n;i++)
                    if (b[i]>=k&&cnt!=1)
                        a[i][k][j]=tot++;
                    else if (b[i]>=k&&cnt==1){
                        ++tot;
                        a[i][k][j]=tot++;
                    }
        int flag=1;
        last=minx;
        for (int i=1;i<=n;i++)
            if (b[i]>minx&&flag){
                minx=b[i];
                flag=0;
            }
            else if (b[i]>minx)
                minx=min(minx,b[i]);
        if (minx==maxx){
            for (int i=1;i<=n;i++)
                if (b[i]==maxx)
                    ++cnt;
        }
    }
    for (int i=1;i<=n;i++){
        cout<<"#"<<i<<"\n";
        for (int j=1;j<=b[i];j++)
            for (int k=1;k<=10;k++)
                cout<<a[i][j][k]<<(k==10?'\n':' ');
    }
    return 0;
}
