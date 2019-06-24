#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
struct node{
    int x,y;
}vet[2000];
double dis[1200][1200];
double getdis(node,node);
int main(){
    int n;
    int t=0;
    while(cin>>n&&n){
        memset(dis,0x3f,sizeof dis);
        for (int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            vet[i].x=x;
            vet[i].y=y;
        }
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                dis[i][j]=getdis(vet[i],vet[j]);
        double ans=0;
        for (int k=0;k<n;k++)
            for (int i=0;i<n;i++)
                for (int j=0;j<n;j++){
                    if (max(dis[i][k],dis[k][j])<dis[i][j])
                        dis[i][j]=max(dis[i][k],dis[k][j]);
                }
        ans=dis[0][1];
        cout<<"Scenario #"<<++t<<"\n";
        printf("Frog Distance = %.3f\n\n",ans);
    }
}
double getdis(node a,node b){
    return sqrt((double)(a.x-b.x)*(a.x-b.x)+(double)(a.y-b.y)*(a.y-b.y));
}
