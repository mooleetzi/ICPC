#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL long long

LL a[100005];
int main()
{
    int n,t,iCase=0;
    LL k;
    scanf("%d",&t);
    while(t--)
    {
        LL sum=0;
        scanf("%d%lld",&n,&k);
        for(int i=1; i<=n; i++)
        {
            scanf("%I64d",&a[i]);
            sum+=a[i];
        }
        printf("Case #%d: ",++iCase);
        LL ss=sum/k;
        int re=0;
        if(sum%k==0)
        {
            for(int i=1; i<=n; i++)
            {
                if(a[i]==ss)
                    continue;
                if(a[i]<ss)
                {
                    a[i+1]+=a[i];
                    re++;
                }
                else
                {

                    if(a[i]%ss==0)
                    {
                        re+=(a[i]/ss-1);
                    }
                    else
                    {
                        re+=a[i]/ss;
                        a[i+1]+=(a[i]%ss);
                        re++;
                    }
                }
            }
            printf("%d\n",re);
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}
