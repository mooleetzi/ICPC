#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<deque>
#include<cstdlib>
#include<iostream>
#include<functional>
using namespace std;
/*********************************************************************************************/
inline int read(){int x=0;bool fg=0;char ch=getchar();while(ch<'0'||'9'<ch)fg|=ch=='-',       //
ch=getchar();while('0'<=ch&&ch<='9')x=x*10+ch-'0',ch=getchar();return fg?-x:x;}               //
inline long long readll(){long long x=0;bool fg=0;char ch=getchar();while(ch<'0'||'9'<ch)     //
fg|=ch=='-',ch=getchar();while('0'<=ch&&ch<='9')x=x*10+ch-'0',ch=getchar();return fg?-x:x;}   //
inline void Out(int x){if(x<0)x=-x,putchar('-');if(x>9)Out(x/10);putchar(x%10+'0');}          //
inline void Outll(long long x){if(x<0)x=-x,putchar('-');if(x>9)Outll(x/10);putchar(x%10+'0');}//
inline double readdb(){double Dec=0.1,num;bool IsN=false,IsD=false;char ch=getchar();         //
while(ch!='-'&&ch!='.'&&(ch<'0'||ch>'9'))ch=getchar();if(ch=='-')IsN=true,num=0;              //
else if(ch=='.')IsD=true,num=0;else num=ch-'0';if(!IsD){while(ch=getchar(),ch>='0'&&ch<='9')  //
num=num*10+ch-'0';}if(ch=='.'){while(ch=getchar(),ch>='0'&&ch<='9')num+=Dec*(ch-'0'),Dec*=0.1;//
}return IsN?-num:num;}                                                                        //
/*********************************************************************************************/
#define out(x) Out(x),putchar('\n')
#define outll(x) Outll(x),putchar('\n')
#define ll long long
#define eps 1e-10
#define E exp(1)
#define INF 0x3f3f3f3f
#define inf 0x3f3f3f3f3f3f3f3f
#define pi acos(-1)
#define mem0(x) memset(x,0,sizeof(x))
#define mem(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define ui unsigned int
#define ull unsigned long long
/***************************************/
typedef pair<int,int> node;
const int MOD=1e9+7;
const int maxn=1e5+3;
struct pp
{
    int num;
    vector<node>ve;
}p[maxn];
node tmp;

int main()
{
    int t=read();
    while(t--)
    {
        int n=read();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            p[i].num=read();
            p[i].ve.clear();
            for(int j=0;j<p[i].num;j++)
            {
                tmp.first=read(),tmp.second=read();
                p[i].ve.push_back(tmp);
            }
        }
        int dp[n+1];
        for(int i=0;i<=n;i++)
                dp[i]=0;
        bool flag;
        for(int i=1;i<n;i++)
        {
            flag=false;
            for(int j=0;j<p[i-1].num;j++)
            {
                for(int k=0;k<p[i].num;k++)
                {
                    if(p[i].ve[k]==p[i-1].ve[j])
                    {
                        dp[i]=dp[i-1]+1;
                        ans=max(ans,dp[i]);
                        flag=true;
                        break;
                    }
                }
                if(flag)
                    break;
            }
        }
        out(ans);
    }
    return 0;
}
