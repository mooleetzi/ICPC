#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;

inline int read(){
    register int tmp=0,f=1;
    char ch = getchar();
    if (ch=='-'){
        ch = getchar();
        f = -1;
    }
    while(ch>='0'&&ch<='9'){
        tmp = tmp * 10 + ch - '0';
        ch = getchar();
    }
    return tmp*f;
}
int n, m;