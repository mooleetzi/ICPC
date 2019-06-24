#include<bits/stdc++.h>
using namespace std;
const int maxn = 2500 * 25 + 100;
char s[maxn];
int tot;
using pa = pair<int, int>;
vector<pa> a, b;
int main()
{
    char ch = getchar();
    while(ch!='E'){
        if (!isalnum(ch)){
            ch = getchar();
            continue;
        }
        s[tot++] = ch;
        ch = getchar();
    }
    int x, y, w, q;
    x = y = w = q = 0;
    for (int i = 0; i < tot; i++){
        if (s[i]=='W'){
            x++;
            w++;
        }
        else
        {
            y++;
            q++;
        }
        if ((x>=11||y>=11)&&abs(x-y)>=2){
            a.emplace_back(pa(x, y));
            x = y = 0;
        }
        if ((w>=21||q>=21)&&abs(w-q)>=2){
            b.emplace_back(pa(w, q));
            w = q = 0;
        }
    }
    a.emplace_back(pa(x, y));
    b.emplace_back(pa(w, q));
    if (a.empty())
        puts("0:0\n");
    else
    {
        for (auto x:a)
            printf("%d:%d\n", x.first, x.second);
        putchar('\n');
    }
    if (b.empty()){
        puts("0:0");
    }
    else
    {
        for (auto x:b)
            printf("%d:%d\n", x.first, x.second);
    }
    return 0;
}