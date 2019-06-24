#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
char s[maxn];
int num, first = maxn,n;
int main(int argc, char const *argv[])
{
    cin >> n;
    int cnt = n - 11 >> 1;
    int t = cnt<<1;
    for (int i = 1; i <= n;i++){
        cin >> s[i];
        if (first==maxn&&s[i]=='8')
            first = i;
        if (s[i]=='8')
            ++num;
    }
    if (num<cnt||first>cnt)
        puts("NO");
    else
    {
        puts("YES");
    }
    return 0;
}
