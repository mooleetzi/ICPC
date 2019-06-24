#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7+10;
int pri[maxn],sum[maxn];
double c(int m,int n)
{
    double sa,sb,sc;
    sa=sb=sc=0.0;
    for(int i=2;i<=m;i++)
    {
        sa+=log((double)i);
    }
    for(int i=2;i<=n;i++)
    {
        sb+=log((double)i);
    }
    for(int i=2;i<=n-m;i++)
    {
        sc+=log((double)i);
    }

   //cout<<sa<<" "<<sb<<" "<<sc<<endl;

    return sb-sa-sc;
}
int main(){
    memset(sum,0,sizeof sum);
    memset(pri,0,sizeof pri);
    for (int i=1,j=2;i<maxn,j<maxn;i+=2,j+=2)
        pri[i]=1,pri[j]=0;
    pri[1]=0;pri[2]=1;
    for (int i=2;i<maxn;i++){
        sum[i]=sum[i-1];
        if (pri[i]){
            sum[i]++;
            for (int j=2*i;j<maxn;j+=i)
                pri[j]=0;
        }
    }
//    cout<<sum[10];
    int n;
    scanf("%d",&n);
//    cout<<exp(c(2,sum[n]));
    printf("%.0f\n",2*exp(c(2,sum[n])));
    return 0;
}
