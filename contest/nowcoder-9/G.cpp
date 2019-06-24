#include <cstdio>
#include <cstring>
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 10010
#define max(x,y) ((x)>(y)?(x):(y))
vector<int> location[MAX] ;
int e[MAX*MAX] , f[MAX*MAX] ;
inline int get_max(int a,int b) {   return a > b ? a : b ;  }
//char s1[MAX],s2[MAX],s3[MAX],s4[MAX];
int a[MAX],b[MAX],c[MAX],d[MAX],q[MAX],w[MAX];
char ans[MAX];
int n;
int lcs(int a[],int b[],int q[])
{
    int i , j , k , w , ans , l , r , mid ;
    for( i = 1 ; i <=n ; i++) location[i].clear() ;
    for( i = n-1 ; i >= 0 ; i--) location[b[i]].push_back(i) ;
    for( i = k = 0 ; a[i] ; i++)
    {
        for( j = 0 ; j < location[w=a[i]].size() ; j++,k++) e[k] = location[w][j] ;
    }
    f[1] = e[0] ;   f[0] = -1 ;
    for( i = ans = 1 ; i < k ; i++)
    {
        l = 0 ; r = ans ;
        while( l <= r )
        {
            mid = ( l + r ) >> 1 ;
            if( f[mid] >= e[i] ) r = mid - 1 ;
            else l = mid + 1 ;
        }
        if( r == ans ) ans++,f[r+1] = e[i] ;
        else if( f[r+1] > e[i] ) f[r+1] = e[i] ;
    }
    for (int i=1;i<=ans;i++)
        printf("%d%c",f[i],i==ans?'\n':' ');
    for (int i=1;i<=ans;i++)
        q[i-1]=b[f[i]];
    return ans ;
}
int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",a+i);
    for (int i=0;i<n;i++)
        scanf("%d",b+i);
    for (int i=0;i<n;i++)
        scanf("%d",c+i);
    for (int i=0;i<n;i++)
        scanf("%d",d+i);
    int ans=lcs(a,b,q);
    ans=lcs(c,d,w);
    for (int i=0;i<ans;i++)
        printf("%d ",q[i]);
    for (int i=0;i<ans;i++)
        printf("%d ",w[i]);
    ans=lcs(q,w,a);
    printf("%d\n",ans);
    return 0;
}
