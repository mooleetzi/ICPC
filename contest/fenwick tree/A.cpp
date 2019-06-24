/*
���⣺��������a[1]..a[n]������a����Ԫ��Ϊ1..n���Ҳ��ظ�������
ð������ԭ���������������ÿ��Ԫ�ص�leftmost-rightmost�ľ���ֵ
�ⷨ:������״��������������Ȼ�����ұߵ�λ�þͱ����i+x-getSum(x)
��� ���x>i ��leftmost=i;����leftmost=x;
*/
#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=x;i<y;i++)
#define mt(a,x) memset(a,x,sizeof(a))
#define maxn 100005
using namespace std;
int c[maxn],ans[maxn];
inline int lowbit(int x){
    return (x&-x);
}
void update(int x){
    while(x<maxn){
        c[x]+=1;
        x+=lowbit(x);
    }
}
int getSum(int x){
    int ans=0;
    while(x){
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}
int main(){
    int t,n,q=0;
    scanf("%d",&t);
    while(q<t){
        mt(ans,0);
        mt(c,0);
        scanf("%d",&n);
        int x;
        for (int i=1;i<=n;i++){
            scanf("%d",&x);
            update(x);
            ans[x]=abs(i+x-getSum(x)-(x>i?i:x));
        }
        printf("Case #%d: ",++q);
        for (int i=1;i<n;i++)
            printf("%d ",ans[i]);
        printf("%d\n",ans[n]);
    }
    return 0;
}
