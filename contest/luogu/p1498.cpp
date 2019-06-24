#include<bits/stdc++.h>
using namespace std;
template<class T>
inline void read(T&ans){
    ans = 0;
    register T f = 1;
    char ch = getwchar();
    while(!isdigit(ch)){
        if (ch=='-')
            f = -1;
        ch = getchar();
    }
    while(isdigit(ch)){
        ans = (ans << 1) + (ans << 3) + ch - 48;
        ch = getchar();
    }
    ans *= f;
}
int main(int argc, char const *argv[])
{
    int n;
    read(n);
    for (int i = 1; i <= n;i++){
        for (int j = n; j > i;j--)
    }
        return 0;
}
