/*
����:��n������������ѡm�����һ�������壬���������Ȩֵ�ʹ��ڵ�����Ȩֵ��
    ��ô�����Ϊʤ���ҳ�����ʤ���������еıز���ȱ��С���壬��Ϊ����ȱ�٣���
    ÿ��С������Ϊ����ȱ�ٵĴ���
˼·:������ö�������Ӽ���ע���жϵ�ǰj�Ƿ����Ӽ�����((i>>j)&1)==1,i��ʾ�ڼ�������(��2^n)
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
