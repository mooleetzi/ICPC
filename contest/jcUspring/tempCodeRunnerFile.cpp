#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e8 + 10;
int a, b, c, d;
int exgcd(int a,int b,int &x,int &y){
    if (!b){
        x = 1;
        y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
int main(int argc, char const *argv[])
{
    cin >> a >> b >> c >> d;
    if ((d-b)%__gcd(a,-c)!=0)
        cout << "-1";
    else
    {
        int x, y;
        int r = exgcd(a, -c, x, y);
        int t = d - b;
        x *= t / r;
        y *= t / r;
        // cout << x << " " << y << "\n";
        while (x < 0)
        {
            x += c;
            y -= a;
        }
        cout << x * a + b;
    }

    return 0;
}
