#include<bits/stdc++.h>
using namespace std;
int exgcd(int a,int b,int &x,int &y){
    int d=a;
    if (b){
        d = exgcd(b, a % b, x, y);
        int t = x;
        x = y;
        y = t - a / b * y;
    }
    else
    {
        x = 1;
        y = 0;
    }
    return d;
}
int main(){
    list<int> l;
    l.push_back(1);
    auto pos = find(l.begin(), l.end(), 1);
    l.insert(--pos, 2);
    for_each(l.begin(), l.end(), [](int x) {
        cout << x << " ";
    });
    return 0;
}