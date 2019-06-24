#include <iostream>
using namespace std;
const int maxn=1000010;
int p[maxn];
int sum[maxn];
inline int findFather(int x)
{
    return p[x]==x?x:p[x]=findFather(p[x]);
}
int read() {
    int x = 0;
    char c = getchar();
    while (c < '0' | c > '9')c = getchar();
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}
void write(int x) {
    int y = 10, len = 1;
    while (y <= x) {
        y *= 10;
        len++;
    }
    while (len--) {
        y /= 10;
        putchar(x / y + 48);
        x %= y;
    }
}
int main()
{
    int n;
    n=read();
    for(int i=1;i<=maxn;++i)
    {
        p[i]=i;
        sum[i]=1;
    }
    for(int i=0;i<n-1;++i)
    {
            int a,b;
            a=read(),b=read();
            int pa=findFather(a);
            int pb=findFather(b);
            if(pa!=pb)
            {
                p[pa]=pb;
                sum[pb]+=sum[pa];
            }
    }
        int maxSum=1;
        for(int i=1;i<=maxn;++i)
        {
            if(p[i]==i)
            {
                maxSum=max(maxSum,sum[i]);
            }
        }
        write(maxSum);
    return 0;
}
