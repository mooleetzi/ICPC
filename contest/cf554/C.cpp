#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    register int f = 1, ans = 0;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        ans = (ans << 1) + (ans << 3) + ch - 48;
        ch = getchar();
    }
    return ans * f;
}
int a, b;
int main(int argc, char const *argv[])
{
    a = read(), b = read();
    if (a>b)
        swap(a, b);
    if (b%a==0){
        cout << "0\n";
        return 0;
    }
    int r = __gcd(a, b);
    
    return 0;
}
