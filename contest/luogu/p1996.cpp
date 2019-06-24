#include<bits/stdc++.h>
using namespace std;
int a[110], b[110];
int main()
{
    int n, m;
    cin >> n >> m;
    int cnt = n, last = 0;
    while(cnt--){
        int tmp;
        for (int i = 1; i <= m;)
        {
            tmp = last + i;
            tmp %= n;
            if(!tmp)
                tmp = n;
            if (a[tmp])
                ++last;
            else
                ++i;
        }
        a[tmp] = 1;
        printf("%d ", tmp);
        last = tmp;
    }
    return 0;
}