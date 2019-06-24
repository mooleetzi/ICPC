#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
using ll= long long;
inline int read()
{
    register int f = 1, ans = 0;
    char ch = getchar();
    while(!isdigit(ch)){
        if (ch=='-')
            f = -1;
        ch = getchar();
    }
    while(isdigit(ch)){
        ans = (ans << 3) + (ans << 1) + ch - 48;
        ch = getchar();
    }
    return ans * f;
}
int a[maxn];
ll ans = 0,n;
void merge_sort(int l, int r)
{
    if (l==r)
        return;
    int mid = l + r >> 1;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    int tmp[maxn];
    int i = l,t=l,j = mid + 1;
    while(i<=mid&&j<=r){
        if (a[i]<=a[j])
            tmp[t++] = a[i++];
        else
        {
            tmp[t++] = a[j++];
            ans += mid - i + 1;
        }
    }
    while(i<=mid){
        tmp[t++] = a[i++];
    }
    while(j<=r){
        tmp[t++] = a[j++];
    }

    for (int i = l; i <= r; i++)
        a[i] = tmp[i];
}
int main(int argc, char const *argv[])
{
    n = read();
    for (int i = 1; i <=n;i++)
        a[i] = read();
    merge_sort(1, n);
    printf("%lld", ans);
    return 0;
}
