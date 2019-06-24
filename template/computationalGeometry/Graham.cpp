#include<bits/stdc++.h>
using namespace std;
typedef pair<double, double> pa;
const int maxn = 1e3 + 10;
int n, m;
pa t[maxn];
int st[maxn], top;
double mul(pa x0,pa x1,pa x2){
    return (x1.first - x0.first) * (x2.second - x0.second) - (x2.first - x0.first) * (x1.second - x0.second);
}
double len(pa x1,pa x2){
    return sqrt((x2.first - x1.first) * (x2.first - x1.first) + (x2.second - x1.second) * (x2.second - x1.second));
}
bool cmp(pa x1,pa x2){
    double k = mul(t[0], x1, x2);
    if (k>0)
        return true;
    else if (k==0&&len(t[0],x1)<len(t[0],x2))
        return true;
    else
    {
        return false;
    }
    
}
int graham(int n){
    if (n==1){
        top = 0;
        st[0] = 0;
        return 1;
    }
    if (n==2){
        top = 1;
        st[0] = 0;
        st[1] = 1;
        return 1;
    }
    for (int i = 0; i < 2;i++)
        st[i] = i;
    top = 1;
    for (int i = 2; i < n; i++){
        while(top>0&&mul(t[st[top-1]],t[st[top]],t[i])<=0)
            --top;
        st[++top] = i;
    }
    return top == n - 1;
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> t[i].first >> t[i].second;
    }
    for (int i = 1; i < n;i++)
        if (t[i].second<t[0].second||(t[i].second==t[0].second&&t[i].first<t[0].first))
            swap(t[i], t[0]);
    sort(t + 1, t + n, cmp);
    if (!graham(n))
    {
        cout << "i can't cut\n";
        return 0;
    }
    cout << "yes it's a convex\n";
    return 0;
}
