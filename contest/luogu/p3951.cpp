#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e9 + 7;
int exgcd(int a,int b,int &x,int &y){
    if (!b){
        x = 1;
        y = 0;
        return a;
    }
    int d = exgcd(b, a % b,y,x);
    y -= a / b * x;
    return d;
}
int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    int x, y;
    int r = exgcd(n, m, x, y);
    return 0;
}
