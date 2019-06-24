/*
    以为手写双端队列要快些，但是并没有
*/
#include<iostream>
using namespace std;
const int maxn = 1e6 + 10;
int n, k;
int a[maxn];
struct node{
    int x, idx;
    node(){}
    node(int a,int b):x(a),idx(b){}
};
node q1[maxn], q2[maxn];
int ans1[maxn], ans2[maxn];
int tot;
int h1, t1, h2, t2;
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n;i++){
        int x;
        cin >> x;
        while(h1<t1&&q1[t1-1].x>x)
            t1--;
        while(h1<t1&&i-q1[h1].idx>=k)
            h1++;
        q1[t1++] = node(x, i);
        while(h2<t2&&q2[t2-1].x<x)
            t2--;
        while(h2<t2&&i-q2[h2].idx>=k)
            h2++;
        q2[t2++] = node(x, i);
        if (i>=k)
            ans1[tot] = q1[h1].x, ans2[tot++] = q2[h2].x;
    }
    for (int i = 0; i < tot;i++)
        cout << ans1[i] << " ";
    cout << "\n";
    for (int i = 0; i < tot;i++)
        cout << ans2[i] << " ";
    cout << "\n";
    return 0;
}
