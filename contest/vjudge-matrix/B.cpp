/*
题意:在n个团体中任意选m个组成一个大团体，若大团体的权值和大于等于总权值和
    则该大团体为胜，找出所有胜利大团体中的必不可缺的小团体，记为不可缺少，求
    每个小团体作为不可缺少的次数
思路:二进制枚举所有子集，注意判断当前j是否在子集中是((i>>j)&1)==1,i表示第几个集合(共2^n)
*/
#include<bits/stdc++.h>
using namespace std;
int ans[21],a[21],n,sum;
void solve(){
    memset(ans,0,sizeof ans);
    int tmp;
    for (int i=0;i<(1<<n);i++){
        tmp=0;
        for (int j=0;j<n;j++)
            if ((i>>j)&1)
                tmp+=a[j];
        if ((tmp<<1)>=sum){
            for (int j=0;j<n;j++)
                if (((i>>j)&1)&&(((tmp-a[j])<<1)<sum))
                    ans[j]++;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        sum=0;
        for (int i=0;i<n;i++)
            cin>>a[i],sum+=a[i];
        solve();
        for (int i=0;i<n;i++)
            printf("%d%c",ans[i],((i==n-1)?'\n':' '));
    }
    return 0;
}
